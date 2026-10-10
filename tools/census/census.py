"""Census: duplicate and family groups over the function inventory, from the linked bytes.

  census.py dup|report [--selftest]

Inputs: .run/census/inventory.jsonl (run tools/census/inventory.py first; m = its row count),
expected/build/slus/SLUS_013.34 (exe text = loadmap exe t_addr/t_size at file offset 0x800),
expected/build/rockx5/ROCK_X5.BIN (overlay = loadmap overlay whose bin_offset is the row's yaml code segment start;
same-vram overlays resolved by module, C0019), docs/oracle/loadmap.json. Raw words decoded here (C0022);
no spimdisasm/splat/rabbitizer.

Dup key = the function's words with relocated fields masked (the target has no relocs; mirrors probe.py rel types 4-7):
  j/jal (op 2/3)                         26-bit target          (R_MIPS_26)
  lui (op 15)                            imm16                  (HI16)
  addiu/ori/loads/stores, rs set by a    imm16                  (LO16)
  lui earlier in the function
  addiu/ori/loads/stores, rs = $gp       imm16                  (GPREL16)
Family key = opcode skeleton per word: opcode; + funct for SPECIAL, rt for REGIMM, rs/fmt for COP0-3; registers and
immediates masked. Dup group = >= 2 functions with one dup key. Family group = a skeleton class with >= 2 members
spanning >= 2 distinct dup keys (all class members listed).

Output: .run/census/groups.jsonl rows {"group","kind":"dup"|"family","members":[{"alias","name","vram"}]} (stable
order); prints `census: dup|family <n> of <m> functions in <g> groups`, the same per lane (`census: game|vendor ...`;
vendor = kind libobj|libgap; a lane counts only its own members, g = groups with one of them) and
`census: cross-lane <k> groups`. Exit 0 green, 1 fail (coverage miss names the row; zero dup groups), 2 refused input.

report: same load + groups; writes and prints .run/census/report.txt. reach(f) = |f's dup group u f's family group|
(1 if neither); the family link counts only if insns >= FAMILY_MIN_INSNS (16; sub-floor family-only -> unique-tail). Per scope (fleet, each alias) and lane (all, game, vendor): `census: [<scope>] [<lane>] dup <n> of <m>`,
`family-only` (family group, no dup group), `unique-tail <n> of <m> functions, <i> insns` (reach 1), `excluded`
(inventory rows load() could not cover, counted, not fatal). Per scope: `reach x size [lo,hi) <n> of <m> functions`
(edges 1,16,64,256,1024,4096,inf; reach x insns), `matched (c) <n> of <m>`, top 20 by reach x size (one row per dup
group; tie-break alias, vram, name). First `excluded: <module> -- <reason>` (inventory.excluded); last
`census: lanes reconcile <sum> = <m>` (m = inventory.jsonl rows read independently). Any lane/bucket sum != m prints
`census: FAIL -- ...`, exit 1.
--selftest: tools/census/fixtures/census/functions.json (synthetic words encoded by us): groups, report lanes by name,
and a planted dropped lane member the reconcile check must catch.
"""
import argparse
import json
import struct
import sys
from bisect import bisect_right
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from boundaries import EXE, OVL, LOADMAP, INV, h  # noqa: E402
from inventory import ROOT, aliases_of, excluded, parse_yaml  # noqa: E402
sys.path.insert(0, str(ROOT / "tools/wave"))
import ledger  # noqa: E402  (tools/wave/ledger.py collect: the one ledger reader, R3)

OUT = ROOT / ".run/census/groups.jsonl"
REPORT = ROOT / ".run/census/report.txt"
EDGES = (1, 16, 64, 256, 1024, 4096)  # reach x size buckets [1,16) .. [4096,inf)
FIXTURE = ROOT / "tools/census/fixtures/census/functions.json"
GP = 28
LO_OPS = {9, 13} | set(range(32, 39)) | {40, 41, 42, 43, 46, 49, 50, 57, 58}  # addiu ori, lb..lwr, sb..swr, lwc/swc1-2
LANE = {"game": "game", "libobj": "vendor", "libgap": "vendor"}
FAMILY_MIN_INSNS = 16  # a family link below this size is a short-skeleton coincidence, not reach (docs/ops/census.md)


def dup_key(words):
    hi, out = set(), []  # ponytail: a lui'd reg stays "hi" for the whole function (over-masks after a clobber)
    for w in words:
        op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
        if op in (2, 3):
            w &= ~0x3FFFFFF
        elif op == 15:
            w &= ~0xFFFF
            hi.add(rt)
        elif op in LO_OPS and (rs in hi or rs == GP):
            w &= ~0xFFFF
        out.append(w & 0xFFFFFFFF)
    return tuple(out)


def skeleton(words):
    out = []
    for w in words:
        op = w >> 26
        out.append((op, w & 63 if op == 0 else (w >> 16) & 31 if op == 1 else (w >> 21) & 31 if 16 <= op <= 19 else 0))
    return tuple(out)


def group(fns):
    """fns: [{"alias","name","vram","kind","words"}]. Returns [{"group","kind","members"}] in stable order."""
    def mem(f):
        return {"alias": f["alias"], "name": f["name"], "vram": f["vram"]}

    def order(fs):
        return sorted(fs, key=lambda f: (f["alias"], f["vram"], f["name"]))

    dups, fams = defaultdict(list), defaultdict(list)
    for f in fns:
        f["dk"] = dup_key(f["words"])
        dups[f["dk"]].append(f)
        fams[skeleton(f["words"])].append(f)
    out = []
    for kind, cls, ok in (("dup", dups, lambda fs: len(fs) >= 2),
                          ("family", fams, lambda fs: len(fs) >= 2 and len({f["dk"] for f in fs}) >= 2)):
        gs = sorted((order(fs) for fs in cls.values() if ok(fs)),
                    key=lambda fs: (fs[0]["alias"], fs[0]["vram"], fs[0]["name"]))
        out += [{"group": f"{kind}{i:04d}", "kind": kind, "members": fs} for i, fs in enumerate(gs, 1)]
    return out


def summary(fns, groups):
    lane = {(f["alias"], f["name"], f["vram"]): LANE[f["kind"]] for f in fns}
    lines = []
    for ln in (None, "game", "vendor"):
        m = sum(1 for f in fns if ln is None or LANE[f["kind"]] == ln)
        for kind in ("dup", "family"):
            n = g = 0
            for gr in groups:
                k = sum(1 for x in gr["members"] if ln is None or lane[(x["alias"], x["name"], x["vram"])] == ln)
                n += k if gr["kind"] == kind else 0
                g += bool(k) and gr["kind"] == kind
            lines.append(f"census: {ln + ' ' if ln else ''}{kind} {n} of {m} functions in {g} groups")
    cross = sum(1 for gr in groups if len({lane[(x["alias"], x["name"], x["vram"])] for x in gr["members"]}) == 2)
    lines.append(f"census: cross-lane {cross} groups")
    return lines


def load():
    """(rc, fns): inventory rows with their words from the expected bytes."""
    for p in (EXE, OVL, LOADMAP, INV):
        if not p.exists():
            print(f"census: refused -- missing {p.relative_to(ROOT)}")
            return 2, []
    lm = json.loads(LOADMAP.read_text())
    code = parse_yaml(ROOT / "config/splat.rockx5.yaml")[2]
    by_off = {s["start"]: n for n, s in code.items()}
    exe = EXE.read_bytes()
    t_addr = h(lm["exe"]["t_addr"])
    mods = {"exe": (t_addr, exe[0x800:0x800 + h(lm["exe"]["t_size"])])}
    blob = OVL.read_bytes()
    for o in lm["overlays"]:
        n = by_off.get(h(o["bin_offset"]))
        if n and o.get("dest"):
            off = h(o["bin_offset"])
            mods[n] = (h(o["dest"]), blob[off:off + h(o["size"])])
    fns, miss = [], []
    for line in INV.read_text().splitlines():
        r = json.loads(line)
        mod = "exe" if r["alias"] == "slus" else r["module"].split("/")[1].split("_")[0]
        base, data = mods.get(mod, (0, b""))
        o, k = int(r["vram"], 16) - base, r["insns"]
        if mod not in mods or k < 1 or o < 0 or o + 4 * k > len(data) or r["kind"] not in LANE:
            print(f"census: coverage miss {r['alias']} {r['module']} {r['vram']} {r['name']} ({k} insns)")
            miss.append(r)
            continue
        fns.append({**r, "words": struct.unpack_from(f"<{k}I", data, o)})
    return (1 if miss else 0), fns, miss


def dup():
    rc, fns, _ = load()
    if rc:
        return rc
    groups = group(fns)
    for x in summary(fns, groups):
        print(x)
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text("".join(json.dumps({"group": g["group"], "kind": g["kind"], "members": [
        {"alias": f["alias"], "name": f["name"], "vram": f["vram"]} for f in g["members"]]}) + "\n" for g in groups))
    if not any(g["kind"] == "dup" for g in groups):
        print("census: FAIL -- zero dup groups on the fleet")
        return 1
    return 0


def classify(fns, groups):
    """{id(f): (lane, reach)}: lane dup | family-only | unique-tail; reach = |dup group u family group|, 1 if neither.
    The family link counts only if f's insns >= FAMILY_MIN_INSNS."""
    dg, fg = {}, {}
    for g in groups:
        ids = {id(f) for f in g["members"]}
        for f in g["members"]:
            if g["kind"] == "dup":
                dg[id(f)] = ids
            elif f["insns"] >= FAMILY_MIN_INSNS:
                fg[id(f)] = ids
    return {id(f): ("dup" if id(f) in dg else "family-only" if id(f) in fg else "unique-tail",
                    max(len(dg.get(id(f), set()) | fg.get(id(f), set())), 1)) for f in fns}


def report_lines(rows, fns, groups, miss, m, led=frozenset()):
    """rows: every inventory row; fns: rows load() covered; miss: rows it could not; m: row count read independently;
    led: (alias, name) keys of docs/ledger.md rows (ledger.collect). Returns (lines, ok)."""
    cl = classify(fns, groups)
    gid = {id(f): id(g) for g in groups if g["kind"] == "dup" for f in g["members"]}
    lines, fails, tot = [], [], None
    for sc in ["fleet"] + sorted({r["alias"] for r in rows}):
        def ins(r):
            return sc == "fleet" or r["alias"] == sc
        srows, sf, sm = [r for r in rows if ins(r)], [f for f in fns if ins(f)], [r for r in miss if ins(r)]
        for ln in ("all", "game", "vendor"):
            def inl(r):
                return ln == "all" or LANE.get(r["kind"]) == ln
            lm, x = sum(map(inl, srows)), sum(map(inl, sm))
            c = Counter(cl[id(f)][0] for f in sf if inl(f))
            ui = sum(f["insns"] for f in sf if inl(f) and cl[id(f)][0] == "unique-tail")
            p = f"census: [{sc}] [{ln}]"
            lines += [f"{p} dup {c['dup']} of {lm}", f"{p} family-only {c['family-only']} of {lm}",
                      f"{p} unique-tail {c['unique-tail']} of {lm} functions, {ui} insns", f"{p} excluded {x} of {lm}"]
            s = c["dup"] + c["family-only"] + c["unique-tail"] + x
            if s != lm:
                fails.append(f"[{sc}] [{ln}] dup+family-only+unique-tail+excluded {s} != {lm}")
            if sc == "fleet" and ln == "all":
                tot = s
        def rxs(f):
            return cl[id(f)][1] * f["insns"]
        bk = Counter(bisect_right(EDGES, rxs(f)) - 1 for f in sf)
        for i, lo in enumerate(EDGES):
            hi = EDGES[i + 1] if i + 1 < len(EDGES) else "inf"
            lines.append(f"census: [{sc}] reach x size [{lo},{hi}) {bk[i]} of {len(srows)} functions")
        if sum(bk.values()) + len(sm) != len(srows):
            fails.append(f"[{sc}] buckets+excluded {sum(bk.values()) + len(sm)} != {len(srows)}")
        lines.append(f"census: [{sc}] matched (c) {sum(r.get('status') == 'c' for r in srows)} of {len(srows)}")
        seen, top = set(), []  # one row per dup group: members share rxs, so the first seen is the first member
        for f in sorted(sf, key=lambda f: (-rxs(f), f["alias"], f["vram"], f["name"])):
            k = gid.get(id(f), id(f))
            if k not in seen and len(top) < 20:
                seen.add(k)
                top.append(f)
        for i, f in enumerate(top, 1):
            lines.append(f"census: [{sc}] top {i} rxs {rxs(f)} reach {cl[id(f)][1]} insns {f['insns']} "
                         f"{f['alias']} {f['vram']} {f['name']}")
    lines += [f"census: FAIL -- {x}" for x in fails]
    if tot != m:
        lines.append(f"census: FAIL -- fleet lanes {tot} != inventory rows {m}")
    lines.append(f"census: lanes reconcile {tot} = {m}")
    g = [r for r in rows if r["kind"] == "game"]  # R3: a stub is a game asm row with no ledger row
    c = sum(r.get("status") == "c" for r in g)
    lg = sum(r.get("status") == "asm" and (r["alias"], r["name"]) in led for r in g)
    s = sum(r.get("status") == "asm" and (r["alias"], r["name"]) not in led for r in g)
    v = sum(LANE.get(r["kind"]) == "vendor" and r.get("status") == "asm" for r in rows)
    lines.append(f"census: stubs {s} of {len(g)} game functions ({c} c, {lg} ledgered); vendor {v} asm")
    return lines, not fails and tot == m


def report():
    rc, fns, miss = load()
    if rc == 2:
        return 2
    rows = [json.loads(x) for x in INV.read_text().splitlines()]
    pre = [f"excluded: {n} -- {why}" for a in aliases_of(ROOT)
           for n, why in excluded(ROOT, parse_yaml(ROOT / f"config/splat.{a}.yaml")[1])]
    led = {(r["alias"], r["name"]) for r in ledger.collect(ROOT / "waves", INV)[0]}
    lines, ok = report_lines(rows, fns, group(fns), miss, len(rows), led)
    text = "\n".join(pre + lines) + "\n"
    REPORT.parent.mkdir(parents=True, exist_ok=True)
    REPORT.write_text(text)
    print(text, end="")
    return 0 if ok else 1


def selftest():
    fx = json.loads(FIXTURE.read_text())["functions"]
    for f in fx:
        f["words"] = tuple(int(w, 16) for w in f["words"])
    groups = group(fx)
    for x in summary(fx, groups):
        print(x)
    got = sorted((g["kind"], tuple(f["name"] for f in g["members"])) for g in groups)
    want = [("dup", ("dup_a", "dup_b")), ("family", ("fam_a", "fam_b")), ("family", ("sub_a", "sub_b"))]
    ok = got == want
    print(f"selftest: groups {got}")
    print(f"selftest: {'pass' if ok else 'FAIL'} (want dup_a+dup_b dup, fam_a+fam_b and sub_a+sub_b family, near_a/near_b none)")
    for f in fx:
        f.setdefault("insns", len(f["words"]))
    lines, rok = report_lines(fx, fx, groups, [], len(fx))
    for x in lines:
        print(x)
    cl = classify(fx, groups)
    lanes = {f["name"]: cl[id(f)][0] for f in fx}
    want_l = {"dup_a": "dup", "dup_b": "dup", "fam_a": "family-only", "fam_b": "family-only",
              "near_a": "unique-tail", "near_b": "unique-tail", "sub_a": "unique-tail", "sub_b": "unique-tail"}
    must = ["census: [fleet] [vendor] dup 1 of 2", "census: [fleet] [vendor] unique-tail 1 of 2 functions, 4 insns",
            "census: [fleet] matched (c) 1 of 8", "census: lanes reconcile 8 = 8"]
    rep = rok and lanes == want_l and all(x in lines for x in must)
    print(f"selftest: report {'pass' if rep else 'FAIL'} lanes {lanes}")
    drop = [f for f in fx if f["name"] != "fam_b"]  # planted negative: a lane member dropped, not excluded
    nl, nok = report_lines(fx, drop, group(drop), [], len(fx))
    neg = not nok and any(x.startswith("census: FAIL") for x in nl)
    print(f"selftest: planted dropped member {'caught' if neg else 'MISSED'}: {[x for x in nl if 'FAIL' in x]}")
    if ok and rep and neg:
        print("census: control OK")
    return 0 if ok and rep and neg else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0], epilog=__doc__.split("\n\n", 1)[1],
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", nargs="?", choices=["dup", "report"])
    ap.add_argument("--selftest", action="store_true", help="synthetic dup / family / near-miss fixtures")
    a = ap.parse_args()
    if a.selftest:
        return selftest()
    if a.cmd is None:
        print("census: refused -- no command (dup|report)")
        return 2
    return dup() if a.cmd == "dup" else report()


if __name__ == "__main__":
    sys.exit(main())
