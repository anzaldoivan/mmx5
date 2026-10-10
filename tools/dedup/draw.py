"""The draw filter: inventory -> a ranked drawable set and a refused set, one reason per refused function (G27).

  draw.py [--selftest]

Inputs: .run/census/inventory.jsonl, .run/census/groups.jsonl (census.py dup), .run/sig/twins.jsonl (sig.py band),
carve.py `plan` run in-process per candidate, config/dedup.exclude.yaml. Output: .run/dedup/draw.jsonl rows
{alias, module, name, vram, insns, verdict: "draw"|"refused", reason, rank, reach[, detail]}.
Reasons, first match wins:
  vendor          kind libobj|libgap
  excluded-module the row's yaml segment is an inventory.excluded module, or census load() could not cover the row
  already-c       status c, or carve plan `c-exists`
  exclude-list    an entry of config/dedup.exclude.yaml (alias, vram, name)
  uncarveable     carve plan refusal (detail = jump-table|rodata-shared|outside-asm|not-found|ambiguous); rockx5 passes the
                  yaml segment as module (C0019)
  dup-member      census dup group: if a member has C (status c or src/<alias>/<name>.c), every other member not
                  refused above; else every member but the representative (first (alias, vram, name) not refused above)
reach(f) = |dup group u family group (only if insns >= census.FAMILY_MIN_INSNS) u f's sig cluster u the sig clusters
near-linked to it, near links counted only between fns >= the floor| (1 if none); twins.jsonl exact rows rep->member (sig_a = sig_b), near rows link cluster reps.
Drawable rank 1..d by reach x insns desc, tie alias, vram, name; refused rank null.
Prints `draw: <d> of <m> drawable, <r> refused` (m = inventory rows counted independently), `draw: refused <reason>
<c>` for all six reasons, then `draw: uncarveable <detail> <c>`. Exit 1 if d + r != m.
Exclude list: before drawing every entry's `reprobe` (argv by shlex, cwd repo root, no shell, 120 s) runs; exit 0 =
stale (the function no longer refuses): `draw: stale exclude <alias> <vram> <reason>`, exit 1, nothing written.
--selftest: tools/dedup/fixtures/draw (synthetic rows; uncarveable via the carve fixture), one function per reason +
one drawable, and a stale entry that must refuse.
Stdlib only.
"""

import json
import shlex
import subprocess
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
FIX = Path(__file__).resolve().parent / "fixtures" / "draw"
sys.path.insert(0, str(ROOT / "tools" / "census"))
sys.path.insert(0, str(Path(__file__).resolve().parent))
import carve  # noqa: E402
import census  # noqa: E402
from census import FAMILY_MIN_INSNS  # noqa: E402
from inventory import aliases_of, excluded, parse_yaml  # noqa: E402

INV = ROOT / ".run/census/inventory.jsonl"
GROUPS = ROOT / ".run/census/groups.jsonl"
TWINS = ROOT / ".run/sig/twins.jsonl"
EXCL = ROOT / "config/dedup.exclude.yaml"
OUT = ROOT / ".run/dedup/draw.jsonl"
REASONS = ("vendor", "excluded-module", "already-c", "exclude-list", "uncarveable", "dup-member")


def key(r):
    return (r["alias"], r["vram"], r["name"])


def seg_of(r):
    """yaml code segment of a rockx5 row (`rockx5/ovl08_800EE9BC` -> ovl08), as census.load() derives it."""
    return r["module"].split("/")[1].split("_")[0] if r.get("module") and "/" in r["module"] else None


def jsonl(p):
    return [json.loads(x) for x in p.read_text().splitlines() if x.strip()]


def read_exclude(p):
    """Restricted YAML: `#` comments, `entries:` then one `  - {json object}` per entry (JSON is YAML flow)."""
    out = []
    for ln in p.read_text().splitlines():
        s = ln.strip()
        if s.startswith("- {"):
            out.append(json.loads(s[2:]))
        elif s and not s.startswith("#") and s not in ("entries:", "entries: []"):
            raise SystemExit(f"draw: refused -- {p.name}: unparsable line {ln!r}")
    return out


def stale(entries, cwd):
    """Entries whose re-probe exits 0 (no longer refuses)."""
    bad = []
    for e in entries:
        try:
            rc = subprocess.run(shlex.split(e["reprobe"]), cwd=cwd, capture_output=True, timeout=120).returncode
        except (OSError, subprocess.TimeoutExpired):
            rc = 1  # ponytail: a probe that cannot run counts as live; fix the probe if it never runs
        if rc == 0:
            bad.append(e)
    return bad


def reach_sets(rows, groups, twins):
    """{key: set of keys}: dup u family (floor) u own sig cluster u near-linked clusters."""
    ins = {key(r): r["insns"] for r in rows}
    out = defaultdict(set)
    for g in groups:
        ks = {key(m) for m in g["members"]}
        for k in ks:
            if g["kind"] == "dup" or ins.get(k, 0) >= FAMILY_MIN_INSNS:
                out[k] |= ks
    cl, sig_of, near = defaultdict(set), {}, defaultdict(set)
    for t in twins:
        a, b = key(t["a"]), key(t["b"])
        for k, s in ((a, t["sig_a"]), (b, t["sig_b"])):
            cl[s].add(k)
            sig_of[k] = s
        if t["tier"] == "near":
            near[t["sig_a"]].add(t["sig_b"])
            near[t["sig_b"]].add(t["sig_a"])
    for k, s in sig_of.items():
        # the family floor gates near links too, on both ends: a 16-insn fn one insert from the 673-member
        # 15-insn class otherwise inherits that class's reach (T5 run 1: top ranks reach 684-725 at 16-19 insns)
        if near[s] and ins.get(k, 0) >= FAMILY_MIN_INSNS:
            for s2 in near[s] | {s}:
                out[k] |= {j for j in cl[s2] if ins.get(j, 0) >= FAMILY_MIN_INSNS}
    return {k: max(len(out.get(k, set()) | {k}), 1) for k in ins}


def draw(rows, groups, twins, excl_mods, miss, entries, planner, has_c):
    """-> out rows (input order). planner(r) -> None (plannable) or a carve refusal string."""
    reason, detail = {}, {}
    ex = {(e["alias"], e["vram"].upper().removeprefix("0X"), e["name"]) for e in entries}
    for r in rows:
        k = key(r)
        if r["kind"] in ("libobj", "libgap"):
            reason[k] = "vendor"
        elif k in miss or (r["alias"], seg_of(r)) in excl_mods:
            reason[k] = "excluded-module"
        elif r["status"] == "c":
            reason[k] = "already-c"
        elif k in ex:
            reason[k] = "exclude-list"
        else:
            p = planner(r)
            if p == "c-exists":
                reason[k] = "already-c"
            elif p is not None:
                reason[k], detail[k] = "uncarveable", p
    present = {key(r) for r in rows}
    for g in groups:
        if g["kind"] != "dup":
            continue
        ms = sorted(k for k in (key(m) for m in g["members"]) if k in present)
        free = [k for k in ms if k not in reason]
        if not any(has_c(k) for k in ms):
            free = free[1:]  # the representative stays drawable
        for k in free:
            reason[k] = "dup-member"
    rch = reach_sets(rows, groups, twins)
    ok = sorted((r for r in rows if key(r) not in reason), key=lambda r: (-rch[key(r)] * r["insns"], *key(r)))
    rank = {key(r): i for i, r in enumerate(ok, 1)}
    out = []
    for r in rows:
        k = key(r)
        o = {"alias": r["alias"], "module": r.get("module"), "name": r["name"], "vram": r["vram"], "insns": r["insns"],
             "verdict": "refused" if k in reason else "draw", "reason": reason.get(k), "rank": rank.get(k),
             "reach": rch[k]}
        if k in detail:
            o["detail"] = detail[k]
        out.append(o)
    return out


def summary(out, m):
    d = sum(o["verdict"] == "draw" for o in out)
    r = len(out) - d
    c = Counter(o["reason"] for o in out if o["reason"])
    u = Counter(o["detail"] for o in out if o.get("detail"))
    lines = [f"draw: {d} of {m} drawable, {r} refused"] + [f"draw: refused {x} {c[x]}" for x in REASONS]
    lines += [f"draw: uncarveable {x} {n}" for x, n in sorted(u.items())]
    if d + r != m:
        lines.append(f"draw: FAIL -- {d} + {r} != {m}")
    return lines, d + r == m, c


def ctx_planner(root, asm_root=None):
    cxs = {}

    def planner(r):
        if r["alias"] not in cxs:
            cxs[r["alias"]] = carve.Ctx(root, r["alias"], asm_root)
        try:
            carve.plan(cxs[r["alias"]], int(r["vram"], 16), seg_of(r) if r["alias"] == "rockx5" else None, r["name"])
            return None
        except carve.Refused as e:
            return str(e)
    return planner


def main_run():
    entries = read_exclude(EXCL)
    bad = stale(entries, ROOT)
    for e in bad:
        print(f"draw: stale exclude {e['alias']} {e['vram']} {e['reason']}")
    if bad:
        return 1
    for p in (INV, GROUPS, TWINS):
        if not p.exists():
            print(f"draw: refused -- missing {p.relative_to(ROOT)}")
            return 2
    m = sum(1 for x in INV.read_text().splitlines() if x.strip())
    rows = jsonl(INV)
    if len({key(r) for r in rows}) != len(rows):
        print("draw: FAIL -- duplicate (alias, vram, name) in inventory")
        return 1
    res = census.load()
    if res[0] == 2:
        return 2
    miss = {key(r) for r in res[2]}
    excl_mods = {(a, n) for a in aliases_of(ROOT) for n, _ in excluded(ROOT, parse_yaml(ROOT / f"config/splat.{a}.yaml")[1])}
    cs = {key(r) for r in rows if r["status"] == "c"}
    out = draw(rows, jsonl(GROUPS), jsonl(TWINS), excl_mods, miss, entries, ctx_planner(ROOT),
               lambda k: k in cs or (ROOT / f"src/{k[0]}/{k[2]}.c").exists())
    lines, ok, _ = summary(out, m)
    if ok:
        OUT.parent.mkdir(parents=True, exist_ok=True)
        OUT.write_text("".join(json.dumps(o) + "\n" for o in out))
    print("\n".join(lines))
    return 0 if ok else 1


def selftest():
    fx = json.loads((FIX / "draw.json").read_text())
    rows = fx["rows"]
    st = {key(r): r["status"] for r in rows}
    ok = True
    entries = read_exclude(FIX / "exclude.yaml")
    if stale(entries, ROOT):
        print("draw: selftest FAIL -- live exclude entry reported stale")
        ok = False
    out = draw(rows, fx["groups"], fx["twins"], {tuple(x) for x in fx["excluded_modules"]},
               {tuple(x) for x in fx["miss"]}, entries, ctx_planner(carve.FIX), lambda k: st.get(k) == "c")
    lines, rok, c = summary(out, len(rows))
    print("\n".join(lines))
    got = {o["name"]: (o["reason"] or "draw") for o in out}
    if not rok or got != fx["want"] or any(c[x] < 1 for x in REASONS):
        print(f"draw: selftest FAIL -- got {got}")
        ok = False
    want_rank = [o["name"] for o in sorted((o for o in out if o["rank"]), key=lambda o: o["rank"])]
    if want_rank != fx["want_rank"]:
        print(f"draw: selftest FAIL -- rank {want_rank}")
        ok = False
    global EXCL
    keep, EXCL = EXCL, FIX / "exclude_stale.yaml"  # planted negative: the full run must refuse, writing nothing
    before = OUT.stat().st_mtime_ns if OUT.exists() else None
    rc = main_run()
    EXCL = keep
    if rc != 1 or (OUT.stat().st_mtime_ns if OUT.exists() else None) != before:
        print("draw: selftest FAIL -- planted stale entry not refused")
        ok = False
    print("draw: control OK -- one function per reason, stale entry refused" if ok else "draw: selftest FAIL")
    return 0 if ok else 1


if __name__ == "__main__":
    if sys.argv[1:] == ["--selftest"]:
        sys.exit(selftest())
    if sys.argv[1:]:
        print(__doc__)
        sys.exit(2)
    sys.exit(main_run())
