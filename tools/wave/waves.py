#!/usr/bin/env python3
"""Wave tool: draw a stratified wave of drafting targets, build one card pack per target, try one draft.

  waves.py draw W<k> [--per 6] [--buckets 20,50,100,200] [--order strata|leverage] [--size N]
  waves.py card W<k>
  waves.py try <draft.c> --target <alias>_<name>
  waves.py status [W<k>] [--drafts-only] [--waves DIR]
  waves.py rate [W<k>] [--check]
  waves.py --selftest

draw: inputs .run/census/inventory.jsonl, .run/census/groups.jsonl, .run/sig/twins.jsonl, .run/dedup/draw.jsonl
  (never refreshed here; refused, exit 1, when any is older than the last commit touching src or config/splat.*, G31).
  Buckets A..D by insns upper bound; > last bound = lane `unmeasured`, not drawn. Per bucket `--per` targets by draw
  rank, >= 2 rockx5 and >= 3 slus (unsatisfiable -> exit 1 naming the bucket). A candidate is valid when: draw.jsonl
  verdict `draw`, its asm .s on disk, inventory status `asm`, not in config/dedup.exclude.yaml, and no drawn target
  shares its cluster (same groups.jsonl group or a twins.jsonl pair, keyed (alias, name); C0043).
  Writes waves/W<k>/wave.json {wave, date, buckets, targets: [{alias, module, name, vram, insns, bucket, rank, reach}]}
  (never overwrites), re-validates it: `wave: W<k> drew <n> targets, <i> invalid` (exit 1 if i > 0), then
  `lane: <lane> <count>` lines partitioning every draw.jsonl row. --order strata (default) is the above.
  --order leverage --size N (R2): one pool of valid drawable rows by reach desc, insns desc, (alias, vram); a row whose
  bucket (`>`+last bound past it) routes `defer` in docs/routing.md is skipped, `draft-twin` only with a banked twin
  or a matched lever (as the card computes); NEED is a floor over the N; same wave.json shape, output and checks.
card: .run/wave/W<k>/packs/<alias>_<name>/{card.md, target.s -> asm file}. No asm text in card.md. A card naming a
  lever id or C<nnnn> that resolves in neither docs/codegen-map/levers.yaml nor cookbook/INDEX.md is refused (G44).
try: compile the draft standalone (probe.compile_obj, reconcile.triple(); scratch .run/probe/wave/<alias>_<name>/),
  masked word compare (probe.read_func/diff_words) against probe.target_bytes. `try: <name> match` (exit 0) |
  `try: <name> diff <d> of <w> words` (exit 1) + `try:   differing word offsets: +0x..` | `try: <name> error <stage>`
  (exit 2) + the stage's first stderr lines (<= 5, `try:   ` prefixed). Appends one JSON line to
  .run/wave/try/<alias>_<name>.jsonl. Target bytes are never printed or written (G12).
status: drafts waves/W<k>/drafts/<alias>_<name>.c vs verdicts.jsonl rows (keyed alias,name):
  `wave: W<k> <d> drafts = <b> banked + <f> failed + <n> no-verdict`, exit 1 when unequal or a draft has no row.
  --drafts-only: every wave.json target has a draft and an attempts.jsonl row: `wave: W<k> <n> of <m> targets
  drafted`, else exit 1. --waves overrides the waves/ root. status_counts(wdir) is the importable count.
  W<k> omitted: every waves/W<k>/ dir (wave_dirs, k ascending), one `wave: W<k> ...` line each; exit 1 if any
  fails or there is no wave.
rate: per wave.json bucket, join verdicts.jsonl (banked) and attempts.jsonl ctx_k (T2/T4 rows, as status); writes and
  prints waves/W<k>/rate.txt `rate: <bucket> <bi> of <ai> insns banked, <bh> of <ah> heads, <c> k ctx per banked insn`
  (c = ctx_k of all bucket targets incl. failed / bi) + `rate: >200 unmeasured, 0 of 0 heads`. --check: docs/routing.md
  `route: <bucket> <draft|draft-twin|defer> cap <N> tries` must equal R3 per measured bucket (bi/ai >= 50% draft,
  20-50% draft-twin, < 20% defer), plus a `route: >200 ... unmeasured` line: `routing: <r> of <m> buckets routed`,
  exit 1 when r < m or a route mismatches (named).
  W<k> omitted (aggregate, R5): the same lines with every wave's per-bucket counts summed (no rate.txt written);
  --check routes against the aggregate.
--selftest: tools/wave/fixtures (synthetic, ROM-free) in .run/wave/selftest.
Stdlib only.
"""

import argparse
import contextlib
import datetime
import io
import json
import os
import re
import shutil
import subprocess
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
FIX = Path(__file__).resolve().parent / "fixtures"
sys.path.insert(0, str(ROOT / "tools/dedup"))
sys.path.insert(0, str(ROOT / "tools/probe"))

INV, GROUPS, TWINS, DRAW = (".run/census/inventory.jsonl", ".run/census/groups.jsonl", ".run/sig/twins.jsonl",
                            ".run/dedup/draw.jsonl")
NEED = {"rockx5": 2, "slus": 3}
REGS = ("zero at v0 v1 a0 a1 a2 a3 t0 t1 t2 t3 t4 t5 t6 t7 s0 s1 s2 s3 s4 s5 s6 s7 t8 t9 k0 k1 gp sp fp ra").split()


def jsonl(p):
    return [json.loads(x) for x in p.read_text().splitlines() if x.strip()]


def read_exclude(p):
    import draw  # tools/dedup/draw.py: the one parser of the restricted yaml
    return draw.read_exclude(p) if p.exists() else []


def unit(r):
    """The yaml code segment: rockx5 `rockx5/ovl08_800EE9BC` -> ovl08 (draw.seg_of); slus keeps its module."""
    return r["module"].split("/")[1].split("_")[0] if r["alias"] == "rockx5" else r["module"]


def asm_index(root, alias):
    """name -> .s file holding `glabel name` (segment files; nonmatchings skipped)."""
    idx = {}
    for f in sorted((root / "asm" / alias).rglob("*.s")):
        if "nonmatchings" in f.parts:
            continue
        for ln in f.read_text(errors="replace").splitlines():
            if ln.startswith("glabel "):
                idx.setdefault(ln.split()[1], f)
    return idx


def asm_body(f, name):
    """Instruction text of `name` (the part after the `/* off vram word */` comment), one line per insn."""
    out, on = [], False
    for ln in f.read_text(errors="replace").splitlines():
        t = ln.split()
        if t[:2] == ["glabel", name]:
            on = True
        elif on and t[:1] == ["endlabel"]:
            break
        elif on and t and not t[0].startswith((".", "glabel", "jlabel", "dlabel")):
            out.append(ln.split("*/", 1)[-1].strip())
    return out


def clusters(groups, twins):
    """(alias, name) -> cluster root; union-find over groups.jsonl members and twins.jsonl pairs."""
    par = {}

    def find(k):
        par.setdefault(k, k)
        while par[k] != k:
            par[k] = par[par[k]]
            k = par[k]
        return k

    for g in groups:
        ks = [(m["alias"], m["name"]) for m in g["members"]]
        for k in ks[1:]:
            par[find(k)] = find(ks[0])
    for t in twins:
        par[find((t["b"]["alias"], t["b"]["name"]))] = find((t["a"]["alias"], t["a"]["name"]))
    return find


class World:
    def __init__(self, root):
        self.root = root
        self.inv = {(r["alias"], r["name"]): r for r in jsonl(root / INV)}
        self.groups, self.twins = jsonl(root / GROUPS), jsonl(root / TWINS)
        self.draw = jsonl(root / DRAW)
        self.excl = {(e["alias"], e["vram"], e["name"]) for e in read_exclude(root / "config/dedup.exclude.yaml")}
        self.find = clusters(self.groups, self.twins)
        self.asm = {a: asm_index(root, a) for a in NEED}
        self.dr = {(r["alias"], r["name"]): r for r in self.draw}

    def invalid(self, t, used):
        """None or the first failing check for target row t; used = cluster roots already drawn."""
        k = (t["alias"], t["name"])
        if self.dr.get(k, {}).get("verdict") != "draw":
            return "not-drawable"
        f = self.asm[t["alias"]].get(t["name"])
        if f is None or not f.exists():
            return "no-asm"
        if self.inv.get(k, {}).get("status") != "asm":
            return "status-not-asm"
        if (t["alias"], t["vram"], t["name"]) in self.excl:
            return "excluded"
        if self.find(k) in used:
            return "cluster"
        return None


def stale_inputs(root):
    ts = subprocess.run(["git", "log", "-1", "--format=%ct", "--", "src", "config/splat.*"], cwd=ROOT,
                        capture_output=True, text=True, check=True).stdout.strip()
    ts = int(ts or 0)
    return [p for p in (INV, GROUPS, TWINS, DRAW) if not (root / p).exists() or (root / p).stat().st_mtime < ts]


def letters(bounds):
    return [chr(ord("A") + i) for i in range(len(bounds))]


def bucket_of(insns, bounds):
    return next((L for L, b in zip(letters(bounds), bounds) if insns <= b), None)


def lanes(w, bounds):
    c = Counter()
    for r in w.draw:
        if r["verdict"] == "draw":
            b = bucket_of(r["insns"], bounds)
            c[f"drawable-{b}" if b else "unmeasured"] += 1
        elif r["reason"] == "uncarveable":
            d = r.get("detail")
            c["uncarveable-" + (d if d in ("rodata", "jump-table") else "other")] += 1
        else:
            c[r["reason"]] += 1
    assert sum(c.values()) == len(w.draw), "lane partition does not cover draw.jsonl"
    return c


def draw_leverage(w, size, bounds):
    """R2: -> targets | None (refusal printed). Pool by reach desc, insns desc, (alias, vram); docs/routing.md `defer`
    buckets skipped, `draft-twin` buckets only with a banked twin or a matched lever; NEED floors the whole wave."""
    rp = w.root / "docs/routing.md"
    route = {m[1]: m[2] for m in map(ROUTE.match, rp.read_text().splitlines()) if m} if rp.exists() else {}
    levers = read_levers(w.root)
    pool = sorted((r for r in w.draw if r["verdict"] == "draw" and r["rank"] is not None),
                  key=lambda r: (-r["reach"], -r["insns"], r["alias"], r["vram"]))
    used, got, cnt = set(), [], Counter()
    for r in pool:
        if len(got) == size:
            break
        b = bucket_of(r["insns"], bounds) or f">{bounds[-1]}"
        how = route.get(b, "draft")
        if how == "defer" or w.invalid(r, used):
            continue
        short = sum(max(0, n - cnt[a]) for a, n in NEED.items() if a != r["alias"])  # NEED floor, as strata
        if size - len(got) - 1 < short:
            continue
        k = (r["alias"], r["name"])
        if how == "draft-twin" and not (banked_twins(w, k)
                                        or matched_levers(asm_body(w.asm[r["alias"]][r["name"]], r["name"]), levers)):
            continue
        got.append(dict({x: r[x] for x in ("alias", "module", "name", "vram", "insns")}, bucket=b, rank=r["rank"],
                        reach=r["reach"]))
        cnt[r["alias"]] += 1
        used.add(w.find(k))
    if len(got) < size or any(cnt[a] < n for a, n in NEED.items()):
        print(f"wave: refused -- leverage pool short: {dict(cnt)} of --size {size}, need {NEED}")
        return None
    return got


def cmd_draw(root, wave, per, bounds, order="strata", size=None):
    bad = stale_inputs(root)
    if bad:
        print(f"wave: refused -- stale or missing input {bad[0]} (older than last src/config/splat commit; G31)")
        return 1
    out = root / "waves" / wave / "wave.json"
    if out.exists():
        print(f"wave: refused -- {out.relative_to(root)} exists")
        return 1
    w = World(root)
    if order == "leverage":
        targets = draw_leverage(w, size, bounds)
        if targets is None:
            return 1
        return write_wave(root, w, out, wave, bounds, targets)
    pool = sorted((r for r in w.draw if r["verdict"] == "draw" and r["rank"] is not None), key=lambda r: r["rank"])
    used, targets = set(), []
    for L, lo, hi in zip(letters(bounds), [0] + bounds, bounds):
        got, cnt = [], Counter()
        for r in pool:
            if len(got) == per:
                break
            if not lo < r["insns"] <= hi or w.invalid(r, used):
                continue
            short = sum(max(0, n - cnt[a]) for a, n in NEED.items() if a != r["alias"])
            if per - len(got) - 1 < short:
                continue
            got.append(r)
            cnt[r["alias"]] += 1
            used.add(w.find((r["alias"], r["name"])))
        if len(got) < per or any(cnt[a] < n for a, n in NEED.items()):
            print(f"wave: refused -- bucket {L} ({lo + 1}-{hi} insns) short: {dict(cnt)} of --per {per}, need {NEED}")
            return 1
        targets += [dict({k: r[k] for k in ("alias", "module", "name", "vram", "insns")}, bucket=L, rank=r["rank"],
                         reach=r["reach"]) for r in got]
    return write_wave(root, w, out, wave, bounds, targets)


def write_wave(root, w, out, wave, bounds, targets):
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps({"wave": wave, "date": datetime.date.today().isoformat(), "buckets": bounds,
                               "targets": targets}, indent=1) + "\n")
    n_bad, used = 0, set()
    for t in json.loads(out.read_text())["targets"]:
        why = w.invalid(t, used)
        used.add(w.find((t["alias"], t["name"])))
        if why:
            n_bad += 1
            print(f"wave: invalid {t['alias']}_{t['name']} {why}")
    print(f"wave: {wave} drew {len(targets)} targets, {n_bad} invalid")
    for k, v in sorted(lanes(w, bounds).items()):
        print(f"lane: {k} {v}")
    return 1 if n_bad else 0


def norm_insn(s):
    """splat insn text -> gcc -S style (`addu $2,$4,$0`) so levers.yaml tells can match."""
    s = re.sub(r"\$(" + "|".join(REGS) + r")\b", lambda m: f"${REGS.index(m.group(1))}", s)
    op, _, rest = s.partition(" ")
    return f"\t{op}\t" + re.sub(r"\s*,\s*", ",", rest.strip())


def src_lines(root):
    out = []
    for f in sorted(list((root / "src").rglob("*.c")) + list((root / "include").rglob("*.h"))):
        for i, ln in enumerate(f.read_text(errors="replace").splitlines(), 1):
            out.append((f.relative_to(root), i, ln))
    return out


def read_levers(root):
    lv = root / "docs/codegen-map/levers.yaml"
    return {x["id"]: x.get("tell") for x in json.loads(lv.read_text())} if lv.exists() else {}  # JSON is YAML


def banked_twins(w, k):
    """Sorted cluster partners of k with inventory status c (the card's banked twins)."""
    me = w.find(k)
    return sorted({p for p in set(w.inv) | {(m["alias"], m["name"]) for g in w.groups for m in g["members"]}
                   if p != k and w.find(p) == me and w.inv.get(p, {}).get("status") == "c"})


def matched_levers(body, levers):
    """Lever ids whose levers.yaml tell matches the norm_insn body."""
    norm = "\n".join(norm_insn(x) for x in body)
    return [lid for lid, tell in levers.items() if tell and re.search(tell, norm, re.M)]


def card_text(w, t, lines, levers, cook):
    root, alias, name = w.root, t["alias"], t["name"]
    body = asm_body(w.asm[alias][name], name)
    text = "\n".join(body)
    callees = list(dict.fromkeys(re.findall(r"\bjal\s+([A-Za-z_]\w*)", text)))
    globs = list(dict.fromkeys(re.findall(r"%(?:hi|lo|gp_rel)\(([A-Za-z_]\w*)", text)))
    partners = banked_twins(w, (alias, name))
    out = [f"# {alias}_{name}", "", "Laws: tools/wave/LAWS.md. Try: `waves.py try <draft.c> --target "
           f"{alias}_{name}`.", "", "## Target",
           f"alias {alias} · module {t['module']} · name {name} · vram {t['vram']} · insns {t['insns']} · "
           f"bucket {t['bucket']}", "", "## Dest file", f"src/{alias}/{name}.c", "", "## Banked twins"]
    for a, n in partners:
        hit = [p for p in [root / f"src/{a}/{n}.c"] if p.exists()] + sorted((root / "src").rglob(f"{n}.c"))
        out.append(f"- {a} {n}: {hit[0].relative_to(root) if hit else '(status c, no src file found)'}")
    out += [] if partners else ["none"]
    out += ["", "## Dest declarations"]
    syms = root / f"config/symbols.{alias}.txt"
    symtxt = syms.read_text().splitlines() if syms.exists() else []
    for s in callees + globs:
        hits = [f"{syms.relative_to(root)}: `{ln.strip()}`" for ln in symtxt if re.match(rf"\s*{s}\s*=", ln)]
        hits += [f"{f}:{i}: `{ln.strip()}`" for f, i, ln in lines if ln.startswith("extern") and re.search(rf"\b{s}\b", ln)]
        out.append(f"- {s}: " + ("; ".join(hits) if hits else "none"))
    out += [] if callees + globs else ["none (no symbol references)"]
    out += ["", "## Callee decl consensus"]
    for c in callees:
        pat = re.compile(rf"^(?:extern\s+)?[A-Za-z_][\w\s*]*\b{c}\s*\([^;{{]*\)\s*[;{{]?\s*$")
        cnt = Counter(" ".join(ln.replace("extern ", "", 1).rstrip("{; ").split()) + ";"
                      for _, _, ln in lines if pat.match(ln))
        out.append(f"- {c}: " + ("; ".join(f"{v}x `{d}`" for d, v in cnt.most_common()) if cnt else "none found"))
    out += [] if callees else ["none (no jal)"]
    led = root / "docs/ledger.md"
    past = [ln.strip() for ln in led.read_text().splitlines() if re.search(rf"\b{name}\b", ln)] if led.exists() else []
    out += ["", "## Past attempts"] + ([f"- {p}" for p in past] or ["none"])
    ids = matched_levers(body, levers)
    ids += [m for p in past for m in re.findall(r"\blever:([\w-]+)", p)]
    ids = list(dict.fromkeys(ids))
    out += ["", "## Levers"] + ([f"- {i}" for i in ids] or ["none matched"]) + [
        "Symptom index: docs/codegen-map/SYMPTOMS.md", "", "## Same-unit neighbours"]
    nb = sorted(r["name"] for r in w.inv.values() if r["alias"] == alias and r["status"] == "c"
                and r["name"] != name and unit(r) == unit(t))
    hits = [f"- {f}:{i}: `{ln.strip()}`" for f, i, ln in lines if f.stem in nb and f.parts[1] == alias
            and ln[:1] not in ("", " ", "\t", "#", "/", "}", "{") and any(re.search(rf"\b{g}\b", ln) for g in globs)]
    out += hits or [f"none ({len(nb)} neighbours in unit {unit(t)}, no shared globals)"]
    md = "\n".join(out) + "\n"
    unres = [i for i in ids if i not in levers and i not in cook]
    unres += [c for c in dict.fromkeys(re.findall(r"\bC\d{4}\b", md)) if c not in cook]
    return md, unres


def cmd_card(root, wave):
    wj = root / "waves" / wave / "wave.json"
    if not wj.exists():
        print(f"card: refused -- {wj.relative_to(root)} missing")
        return 1
    w = World(root)
    levers = read_levers(root)
    ci =root / "cookbook/INDEX.md"
    cook = set(re.findall(r"^(C\d{4}) \|", ci.read_text(), re.M)) if ci.exists() else set()
    lines, bad, n = src_lines(root), 0, 0
    for t in json.loads(wj.read_text())["targets"]:
        md, unres = card_text(w, t, lines, levers, cook)
        key = f"{t['alias']}_{t['name']}"
        if unres:
            bad += 1
            print(f"card: refused {key} -- unresolved {' '.join(unres)} (G44)")
            continue
        d = root / ".run/wave" / wave / "packs" / key
        d.mkdir(parents=True, exist_ok=True)
        (d / "card.md").write_text(md)
        (d / "target.s").unlink(missing_ok=True)
        (d / "target.s").symlink_to(w.asm[t["alias"]][t["name"]].resolve())
        n += 1
    print(f"card: {wave} {n} packs, {bad} refused")
    return 1 if bad else 0


def compile_func(draft, tag, name):
    """try's compile path: draft -> probe.compile_obj (reconcile.triple(), scratch .run/probe/<tag>/) -> read_func.
    -> (text bytes, masks, None) | (None, None, stage)."""
    import probe
    import reconcile
    obj, stage = probe.compile_obj(Path(draft).resolve(), tag, reconcile.triple())
    if obj is None:
        return None, None, stage
    try:
        ours, masks = probe.read_func(obj, name)
    except KeyError:
        return None, None, "symbol"
    return ours, masks, None


def cmd_try(draft, target):
    import probe
    alias, _, name = target.partition("_")
    row = {(r["alias"], r["name"]): r for r in jsonl(ROOT / INV)}.get((alias, name))
    if row is None:
        print(f"try: refused -- {target} not in {INV}")
        return 2
    tag = f"wave/{alias}_{name}"
    scratch = ROOT / ".run/probe" / tag
    assert f"{alias}_{name}" == scratch.name, scratch  # per-target scratch: drafts never share a dir
    ours, masks, stage = compile_func(draft, tag, name)
    w, detail = row["insns"], []
    if ours is None:
        res, d = f"error {stage}", None
        import reconcile
        err = scratch / reconcile.triple()["id"] / f"{stage}.err"  # probe.compile_obj's stderr (our draft, no bytes)
        detail = (err.read_text(errors="replace").splitlines() if err.exists() else [])[:5]
    else:
        tb = probe.target_bytes({"alias": alias, "module": unit(row), "vram": int(row["vram"], 16), "size": 4 * w})
        d = probe.diff_words(ours, tb, masks)
        res = "match" if d == 0 else f"diff {d} of {w} words"
        a, b = probe.masked(ours, masks), probe.masked(tb, masks)
        offs = [f"+0x{4 * i:X}" for i in range(max(len(a), len(b))) if i >= min(len(a), len(b)) or a[i] != b[i]]
        detail = [f"differing word offsets: {' '.join(offs[:16])}" + (" ..." if len(offs) > 16 else "")] if d else []
    log = ROOT / ".run/wave/try" / f"{alias}_{name}.jsonl"
    log.parent.mkdir(parents=True, exist_ok=True)
    with log.open("a") as f:
        f.write(json.dumps({"draft": str(draft), "result": res.split()[0], "d": d, "w": w}) + "\n")
    print(f"try: {name} {res}")
    for ln in detail:
        print(f"try:   {ln}")
    return 0 if res == "match" else 1 if res.startswith("diff") else 2


def wave_dirs(waves):
    """Every waves/W<k>/ dir name, k ascending."""
    return sorted((p.name for p in Path(waves).glob("W*") if p.is_dir() and p.name[1:].isdigit()),
                  key=lambda n: int(n[1:]))


def status_counts(wdir):
    """-> (drafts, banked, failed, no-verdict, drafts without a verdict row) over waves/W<k>/."""
    drafts = {tuple(p.stem.split("_", 1)) for p in (wdir / "drafts").glob("*.c")}
    vp = wdir / "verdicts.jsonl"
    rows = jsonl(vp) if vp.exists() else []
    c = Counter(r["verdict"] for r in rows)
    missing = sorted(drafts - {(r["alias"], r["name"]) for r in rows})
    return len(drafts), c["banked"], c["failed"], c["no-verdict"], missing


def cmd_status(waves, wave, drafts_only=False):
    if wave is None:
        ws = wave_dirs(waves)
        return max([cmd_status(waves, w, drafts_only) for w in ws] or [1])
    wdir = Path(waves) / wave
    if drafts_only:
        targets = json.loads((wdir / "wave.json").read_text())["targets"]
        ap = wdir / "attempts.jsonl"
        # T2 rows {alias,name,...}; T4 rows {target="<alias>_<name>",...}
        tried = {r.get("target") or f"{r['alias']}_{r['name']}" for r in jsonl(ap)} if ap.exists() else set()
        n = sum((wdir / "drafts" / f"{t['alias']}_{t['name']}.c").exists() and f"{t['alias']}_{t['name']}" in tried
                for t in targets)
        print(f"wave: {wave} {n} of {len(targets)} targets drafted")
        return 0 if n == len(targets) else 1
    d, b, f, n, missing = status_counts(wdir)
    for a, nm in missing:
        print(f"wave: no verdict row {a}_{nm}")
    print(f"wave: {wave} {d} drafts = {b} banked + {f} failed + {n} no-verdict")
    return 0 if d == b + f + n and not missing else 1


ROUTE = re.compile(r"^route: (\S+) (draft|draft-twin|defer) cap (\d+) tries")


def r3(bi, ai):  # R3: insns banked rate >= 50% draft, 20-50% draft-twin, < 20% defer.
    return "draft" if bi * 2 >= ai else "draft-twin" if bi * 5 >= ai else "defer"


def rate_per(wdir, per):
    """Add waves/W<k>/'s per-bucket [bi, ai, bh, ah, ctx] into per (a wave without wave.json adds nothing)."""
    wj, vp = wdir / "wave.json", wdir / "verdicts.jsonl"
    targets = json.loads(wj.read_text())["targets"] if wj.exists() else []
    verdict = {f"{r['alias']}_{r['name']}": r["verdict"] for r in (jsonl(vp) if vp.exists() else [])}
    ap = wdir / "attempts.jsonl"
    ctx = Counter()  # T2 rows {alias,name,...}; T4 rows {target="<alias>_<name>",...} (as status)
    for r in jsonl(ap) if ap.exists() else []:
        ctx[r.get("target") or f"{r['alias']}_{r['name']}"] += r.get("ctx_k") or 0
    for t in targets:
        k = f"{t['alias']}_{t['name']}"
        s = per.setdefault(t["bucket"], [0, 0, 0, 0, 0.0])  # bi ai bh ah ctx
        won = verdict.get(k) == "banked"
        s[0] += t["insns"] * won
        s[1] += t["insns"]
        s[2] += won
        s[3] += 1
        s[4] += ctx[k]
    return per


def cmd_rate(waves, wave, check=False, routing=ROOT / "docs/routing.md"):
    per, ws = {}, [wave] if wave else wave_dirs(waves)
    if not ws:
        print("rate: no waves")
        return 1
    for w in ws:
        rate_per(Path(waves) / w, per)
    order = sorted(per.items(), key=lambda kv: (kv[0].startswith(">"), kv[0]))  # A..D, then the >last-bound lane
    lines = [f"rate: {b} {bi} of {ai} insns banked, {bh} of {ah} heads, "
             f"{(c / bi if bi else 0):.2f} k ctx per banked insn" for b, (bi, ai, bh, ah, c) in order]
    unmeasured = ">200" not in per  # a drawn >200 target (heads > 0) is measured like A-D
    if unmeasured:
        lines.append("rate: >200 unmeasured, 0 of 0 heads")
    if wave:
        (Path(waves) / wave / "rate.txt").write_text("\n".join(lines) + "\n")
    print("\n".join(lines))
    if not check:
        return 0
    text = Path(routing).read_text().splitlines() if Path(routing).exists() else []
    got = {m[1]: m[2] for m in map(ROUTE.match, text) if m}
    bad = 0
    for b, (bi, ai, *_) in order:
        if b in got and got[b] != r3(bi, ai):
            print(f"routing: {b} routed {got[b]}, R3 says {r3(bi, ai)}")
            bad += 1
    r = sum(b in got for b in per)
    if unmeasured:  # `unmeasured` route required only while no wave measured >200
        r += any(x.startswith("route: >200") and "unmeasured" in x for x in text)
    m = len(per) + unmeasured
    print(f"routing: {r} of {m} buckets routed")
    return 0 if r == m and not bad else 1


def selftest():
    tmp = ROOT / ".run/wave/selftest"
    shutil.rmtree(tmp, ignore_errors=True)
    shutil.copytree(FIX, tmp, copy_function=shutil.copy)  # fresh mtimes: not stale

    def call(f, *a):
        b = io.StringIO()
        with contextlib.redirect_stdout(b):
            rc = f(*a)
        return rc, b.getvalue()

    rc, out = call(cmd_draw, tmp, "W0", 5, [20])
    assert rc == 0 and "wave: W0 drew 5 targets, 0 invalid" in out, out
    got = [t["name"] for t in json.loads((tmp / "waves/W0/wave.json").read_text())["targets"]]
    assert got == ["fa", "fd", "ff", "ra", "rb"], got  # planted: fb_c status c, fc_noasm no .s, fe_twin, fg excluded
    # strata unchanged by --order leverage: this exact list (and order) is the pre-leverage draw
    assert sum(int(x.split()[-1]) for x in out.splitlines() if x.startswith("lane:")) == 12, out
    w = World(tmp)
    for n in ("fb_c", "fc_noasm", "fg"):
        assert w.invalid(w.dr[("slus", n)], set()), n
    assert w.invalid(w.dr[("slus", "fe_twin")], {w.find(("slus", "fa"))}) == "cluster"
    assert call(cmd_draw, tmp, "W0", 5, [20])[0] == 1  # no overwrite
    assert "bucket A" in call(cmd_draw, tmp, "W1", 6, [20])[1]  # pool too small
    names = lambda wk: [t["name"] for t in json.loads((tmp / f"waves/{wk}/wave.json").read_text())["targets"]]
    rc, out = call(cmd_draw, tmp, "W3", 5, [20], "leverage", 5)
    assert rc == 0 and names("W3") == ["big", "fa", "fd", "ra", "rb"], (out, names("W3"))  # unrouted: big leads
    (tmp / "docs/routing.md").write_text("route: A draft cap 5 tries\nroute: >20 defer cap 3 tries\n")
    rc, out = call(cmd_draw, tmp, "W4", 5, [20], "leverage", 5)
    assert rc == 0 and "wave: W4 drew 5 targets, 0 invalid" in out and "lane:" in out, out
    assert names("W4") == ["fa", "fd", "ff", "ra", "rb"], names("W4")  # planted: big in a defer bucket, not drawn
    (tmp / "docs/routing.md").write_text("route: A draft cap 5 tries\nroute: >20 draft-twin cap 3 tries\n")
    rc, out = call(cmd_draw, tmp, "W5", 5, [20], "leverage", 5)
    assert rc == 0 and "big" not in names("W5"), out  # draft-twin: big has no banked twin, no lever
    (tmp / "docs/routing.md").unlink()
    rc, out = call(cmd_card, tmp, "W0")
    assert rc == 0 and "card: W0 5 packs, 0 refused" in out, out
    c = (tmp / ".run/wave/W0/packs/slus_fd/card.md").read_text()
    assert "src/slus/fbank.c" in c and "fbank: 1x `int fbank(int a);`" in c, c
    assert "- addu_ret" in (tmp / ".run/wave/W0/packs/slus_ff/card.md").read_text()
    assert (tmp / ".run/wave/W0/packs/slus_fa/target.s").is_symlink()
    (tmp / "docs/ledger.md").write_text("- slus_fa fa lever:bogus_lever see C9999\n")
    rc, out = call(cmd_card, tmp, "W0")
    assert rc == 1 and "unresolved bogus_lever C9999" in out, out
    os.utime(tmp / TWINS, (0, 0))
    rc, out = call(cmd_draw, tmp, "W2", 5, [20])
    assert rc == 1 and TWINS in out, out
    wd = tmp / "waves/W0"  # rate: fa banked (insns from draw), ra failed; others no row
    (wd / "verdicts.jsonl").write_text('{"alias":"slus","name":"fa","verdict":"banked"}\n'
                                       '{"alias":"rockx5","name":"ra","verdict":"failed"}\n')
    (wd / "attempts.jsonl").write_text('{"target":"slus_fa","ctx_k":10}\n{"alias":"rockx5","name":"ra","ctx_k":5}\n')
    rc, out = call(cmd_rate, tmp / "waves", "W0")
    assert rc == 0 and out.count("rate:") == 2 and "1 of 5 heads" in out, out
    bi, ai = (int(x) for x in re.search(r"rate: A (\d+) of (\d+)", out).groups())
    route = tmp / "routing.md"
    for wrong in ("draft", "draft-twin", "defer"):
        if wrong != r3(bi, ai):
            break
    route.write_text(f"route: A {wrong} cap 3 tries\nroute: >200 unmeasured\n")
    rc, out = call(cmd_rate, tmp / "waves", "W0", True, route)
    assert rc == 1 and "R3 says" in out, out  # planted wrong route refused
    route.write_text(f"route: A {r3(bi, ai)} cap 3 tries\nroute: >200 unmeasured\n")
    rc, out = call(cmd_rate, tmp / "waves", "W0", True, route)
    assert rc == 0 and "routing: 2 of 2 buckets routed" in out, out
    rt = (wd / "rate.txt").read_text()  # aggregate (R5): A summed over every wave, no rate.txt written
    ws = wave_dirs(tmp / "waves")
    assert len(ws) > 1 and not (tmp / "waves" / ws[-1] / "rate.txt").exists(), ws
    agg = call(cmd_rate, tmp / "waves", None)[1]
    abi, aai = (int(x) for x in re.search(r"rate: A (\d+) of (\d+)", agg).groups())
    assert abi == bi and aai > ai and (wd / "rate.txt").read_text() == rt, agg
    route.write_text(f"route: A {r3(abi, aai)} cap 3 tries\nroute: >20 defer cap 3 tries\nroute: >200 unmeasured\n")
    rc, out = call(cmd_rate, tmp / "waves", None, True, route)  # W3's leverage draw adds bucket >20 (big, unbanked)
    assert rc == 0 and "routing: 3 of 3 buckets routed" in out and f"A {abi} of {aai}" in out, out
    mw = tmp / "waves200/W9"  # measured >200: one line, after A..D, replaces `unmeasured`; routed by R3
    mw.mkdir(parents=True)
    (mw / "wave.json").write_text(json.dumps({"targets": [
        {"alias": "slus", "name": "h", "insns": 300, "bucket": ">200"},
        {"alias": "slus", "name": "a", "insns": 10, "bucket": "A"}]}))
    (mw / "verdicts.jsonl").write_text('{"alias":"slus","name":"h","verdict":"banked"}\n')
    rc, out = call(cmd_rate, tmp / "waves200", "W9")
    rl = (mw / "rate.txt").read_text().splitlines()
    assert rc == 0 and len(rl) == 2 and rl[0].startswith("rate: A ") and rl[1].startswith("rate: >200 300 of 300"), rl
    route.write_text("route: A defer cap 3 tries\nroute: >200 defer cap 3 tries\nroute: >200 unmeasured\n")
    rc, out = call(cmd_rate, tmp / "waves200", "W9", True, route)
    assert rc == 1 and "routing: >200 routed defer, R3 says draft" in out and "of 2 buckets" in out, out
    route.write_text("route: A defer cap 3 tries\nroute: >200 draft cap 3 tries\n")
    rc, out = call(cmd_rate, tmp / "waves200", "W9", True, route)
    assert rc == 0 and "routing: 2 of 2 buckets routed" in out, out
    rc, out = call(cmd_status, tmp / "waves", None)
    assert rc == 1 and [x.split()[1] for x in out.splitlines()] == ws, out  # W0: rows, no drafts -> fails all
    assert call(cmd_rate, tmp / "none", None)[0] == 1 and call(cmd_status, tmp / "none", None)[0] == 1
    print("wave: control OK -- invalid target refused")
    return 0


def main(argv=None):
    if argv is None:
        argv = sys.argv[1:]
    if argv == ["--selftest"]:
        return selftest()
    ap = argparse.ArgumentParser(prog="waves.py")
    sp = ap.add_subparsers(dest="cmd", required=True)
    d = sp.add_parser("draw")
    d.add_argument("wave")
    d.add_argument("--per", type=int, default=6)
    d.add_argument("--buckets", default="20,50,100,200")
    d.add_argument("--order", choices=["strata", "leverage"], default="strata")
    d.add_argument("--size", type=int)
    sp.add_parser("card").add_argument("wave")
    t = sp.add_parser("try")
    t.add_argument("draft")
    t.add_argument("--target", required=True)
    s = sp.add_parser("status")
    s.add_argument("wave", nargs="?")
    s.add_argument("--drafts-only", action="store_true")
    s.add_argument("--waves", default=str(ROOT / "waves"))
    r = sp.add_parser("rate")
    r.add_argument("wave", nargs="?")
    r.add_argument("--check", action="store_true")
    a = ap.parse_args(argv)
    if a.cmd == "rate":
        return cmd_rate(ROOT / "waves", a.wave, a.check)
    if a.cmd == "draw":
        if a.order == "leverage" and not a.size:
            ap.error("--order leverage needs --size N")
        return cmd_draw(ROOT, a.wave, a.per, [int(x) for x in a.buckets.split(",")], a.order, a.size)
    if a.cmd == "card":
        return cmd_card(ROOT, a.wave)
    if a.cmd == "status":
        return cmd_status(a.waves, a.wave, a.drafts_only)
    return cmd_try(a.draft, a.target)


if __name__ == "__main__":
    sys.exit(main())
