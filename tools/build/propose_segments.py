#!/usr/bin/env python3
"""Propose translation units (TUs) per alias (slus, rockx5) from docs/oracle/boundaries.txt + the generated asm.

usage: propose_segments.py --write | --check [--segments <path>]
  --write  writes docs/oracle/segments.txt (generated, tracked) and prints counts (docs/oracle/segmentation.md cites them)
  --check  validates a segments file (default docs/oracle/segments.txt); exit 0 green, 1 on any violation
           also checks config/splat.<alias>.yaml carries each TU as a named `asm` subsegment at its text offset
Rule (docs/oracle/segmentation.md): libobj span = one TU; gap between adjacent libobj spans = one `libgap` TU; game
text (exe outside libobj, each code overlay's text) cut at padding indicators (`jr $ra` + delay slot, >= 1 extra nop,
next glabel 8-aligned); a cut breaking jumptable rodata order is dropped. Needs `make split BINARY=<alias>` asm.
The yamls are build truth: every `asm` subsegment start (and the one after a `c` probe) in game/overlay text is a TU
start; `textbin` spans hold no function (a libobj starting in one starts at its end; overlay text ends at a tail one).
Addresses and names only (G12): no bytes, no disassembly is written.
"""
import argparse
import glob
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ORACLE = os.path.join(ROOT, "docs/oracle")
SEGMENTS = os.path.join(ORACLE, "segments.txt")
EXE_RODATA = (0x80010000, 0x80011DC8)  # config/splat.slus.yaml: rodata 0x800, text 0x25C8
EXCLUDED_DOC = "data overlays 13/15/17/19"
INSN = re.compile(r"^\s*/\*\s+([0-9A-F]+)\s+([0-9A-F]{8})\s+[0-9A-F]{8}\s+\*/\s+(\S+)\s*(.*)$")
GLABEL = re.compile(r"^\s*glabel\s+(\S+)")
OWNER = re.compile(r"^FUN_(?:ovl(\d\d)__)?([0-9a-fA-F]{8})$")
JR = re.compile(r"jr ([0-9A-F]{8})\s*$")


def die(msg):
    print(f"propose_segments: {msg}", file=sys.stderr)
    sys.exit(2)


def fmt(ovl, a):
    return f"{'ovl%02d:' % ovl if ovl is not None else ''}{a:08X}"


def parse_range(s):
    ovl = None
    if s.startswith("ovl"):
        o, s = s.split(":", 1)
        ovl = int(o[3:])
    a, b = s.split("-")
    return ovl, int(a, 16), int(b, 16)


def load_boundaries():
    libobj, jts = [], []
    for line in open(os.path.join(ORACLE, "boundaries.txt")):
        if not line.strip() or line.startswith("#"):
            continue
        rng, kind, owner, ev = [f.strip() for f in line.split("|", 3)]
        ovl, s, e = parse_range(rng)
        if kind == "libobj":
            libobj.append((s, e, owner))
        else:
            m = JR.search(ev)
            if not m:
                die(f"jumptable without jr evidence: {line.strip()}")
            jts.append(dict(ovl=ovl, s=s, e=e, owner=owner, jr=int(m.group(1), 16)))
    return sorted(libobj), jts


def load_asm(alias, ranges):
    """Instructions and function glabels per region key (None = exe, NN = overlay), from asm/<alias> text files.
    ranges: list of (key, rom_lo, rom_hi) or None (exe: one key)."""
    files = [f for f in glob.glob(os.path.join(ROOT, "asm", alias, "**", "*.s"), recursive=True)
             if "/data/" not in f and "/include/" not in f]
    if not files:
        die(f"no asm under asm/{alias}: run `make split BINARY={alias} PY=...` first")
    insns, glabels = {}, {}  # key -> [(vram, mnem, ops)], key -> {vram: name}
    for f in sorted(files):
        pending = []
        for line in open(f):
            g = GLABEL.match(line)
            if g:
                pending.append(g.group(1))
                continue
            m = INSN.match(line)
            if not m:
                continue
            rom, va = int(m.group(1), 16), int(m.group(2), 16)
            key = None
            if ranges is not None:
                key = next((k for k, lo, hi in ranges if lo <= rom < hi), "skip")
                if key == "skip":
                    pending = []
                    continue
            insns.setdefault(key, []).append((va, m.group(3), m.group(4).strip()))
            for name in pending:
                glabels.setdefault(key, {})[va] = name
            pending = []
    for k in insns:
        insns[k].sort()
    return insns, glabels


def is_fn(name):
    return not name.startswith(("D_", "jtbl_"))


def padding_sites(ins, starts):
    """Function starts preceded by `jr $ra` + delay slot + >= 1 extra nop and 8-aligned; also the predecessor's real end."""
    idx = {va: i for i, (va, _, _) in enumerate(ins)}
    out = {}
    for va in starts:
        i = idx.get(va)
        if i is None or i == 0:  # no decoded insn there (annotation/owner start in code typed as .word): no indicator
            out[va] = (False, None)
            continue
        n = 0
        while n < i and ins[i - 1 - n][1] == "nop":
            n += 1
        jr = lambda j: j >= 0 and ins[j][1] == "jr" and ins[j][2] == "$ra"
        ind, end = False, None
        a = i - n - 1  # last non-nop
        if a >= 0 and jr(a) and n >= 2:  # delay slot = first nop
            ind, end = True, ins[a][0] + 8
        elif a >= 1 and jr(a - 1) and n >= 1:
            ind, end = True, ins[a][0] + 4
        elif a >= 0:
            end = ins[a][0] + (8 if jr(a) else 4)
        out[va] = (ind and va % 8 == 0, end)
    return out


def yaml_subs(alias):
    """config/splat.<alias>.yaml subsegments as [(key, vram, type, name or None)] in file order (key None = main)."""
    out, key, start, vram = [], "skip", 0, 0
    for line in open(os.path.join(ROOT, f"config/splat.{alias}.yaml")):
        m = re.match(r"\s+- name: (\S+)", line)
        if m:
            seg = m.group(1)
            key = None if seg == "main" else int(seg[3:]) if re.fullmatch(r"ovl\d\d", seg) else "skip"
        m = re.match(r"\s+(start|vram): 0x([0-9A-Fa-f]+)", line)
        if m:
            start, vram = (int(m.group(2), 16), vram) if m.group(1) == "start" else (start, int(m.group(2), 16))
        m = re.match(r"\s+- \[0x([0-9A-Fa-f]+), (\w+)(?:, (\S+?))?\]", line)
        if m and key != "skip":  # ponytail: line-regex yaml reader (no PyYAML under $PY); fits the seeded layout only
            out.append((key, int(m.group(1), 16) - start + vram, m.group(2), m.group(3)))
    return out


def yaml_facts():
    """Build truth from the yamls: textbin spans {key: [(s, e)]} (non-function; e = next subsegment, else open) and
    forced TU starts {key: {va}} (every `asm` subsegment, incl. unnamed gen:rockx5_splits header code, and the
    subsegment after a `c` probe), used inside game/overlay text only."""
    tb, forced = {}, {}
    for alias in ("slus", "rockx5"):
        subs = yaml_subs(alias)
        for i, (key, va, typ, _) in enumerate(subs):
            nxt = subs[i + 1] if i + 1 < len(subs) and subs[i + 1][0] == key else None
            if typ == "textbin":
                tb.setdefault(key, []).append((va, nxt[1] if nxt else 0xFFFFFFFF))
            if typ == "asm":
                forced.setdefault(key, set()).add(va)
            if typ == "c" and nxt:
                forced.setdefault(key, set()).add(nxt[1])
    return tb, forced


def in_tb(tb, key, va):
    return next((e for s, e in tb.get(key, []) if s <= va < e), None)


def tu_name(owner, used):
    base = "_".join(p.rsplit(".", 1)[0] for p in owner.split("/"))
    name, k = base, 1
    while name in used:
        k += 1
        name = f"{base}_{k}"
    used.add(name)
    return name


def load_all():
    """boundaries, code overlays, asm, annotation function starts {name: (ovl, va)}; owner start `os` per jumptable."""
    libobj, jts = load_boundaries()
    tb, forced = yaml_facts()
    # a libobj span starting in a yaml textbin (psyq stamp) starts its TU at the textbin end
    libobj = [(in_tb(tb, None, s) or s, e, owner) for s, e, owner in libobj]
    lm = json.load(open(os.path.join(ORACLE, "loadmap.json")))
    ann = {}
    for line in open(os.path.join(ORACLE, "annotations.jsonl")):
        r = json.loads(line)
        if r.get("kind") == "function" and r.get("addr"):
            a = r["addr"]  # `800ef7bc` or `ovl21::800ef7bc`
            ann[r["name"]] = (int(a[3:5]), int(a.rsplit(":", 1)[1], 16)) if a.startswith("ovl") else (None, int(a, 16))
    code_ovls = [o for o in lm["overlays"] if o["kind"] == "code" and o.get("dest")]
    s_ins, s_gl = load_asm("slus", None)
    r_ins, r_gl = load_asm("rockx5", [(o["index"], o["bin_offset"], o["bin_offset"] + o["size"]) for o in code_ovls])
    missing = [o["index"] for o in code_ovls if o["index"] not in r_ins]
    if missing:
        die(f"rockx5 asm missing overlays {missing}: run `make split BINARY=rockx5 PY=...`")
    name2va = {(k, nm): va for k, gl in list(s_gl.items()) + list(r_gl.items()) for va, nm in gl.items()}
    for j in jts:
        m = OWNER.match(j["owner"])
        if m:
            j["os"] = int(m.group(2), 16)
        elif ann.get(j["owner"], (-1,))[0] == j["ovl"]:
            j["os"] = ann[j["owner"]][1]
        elif (j["ovl"], j["owner"]) in name2va:
            j["os"] = name2va[(j["ovl"], j["owner"])]
        else:
            die(f"unresolved jumptable owner {j['owner']}")
    return libobj, jts, lm, code_ovls, ann, s_ins, s_gl, r_ins, r_gl, tb, forced


def propose():
    libobj, jts, lm, code_ovls, ann, s_ins, s_gl, r_ins, r_gl, tb, forced = load_all()
    stats = {"excluded": [o["index"] for o in lm["overlays"] if o not in code_ovls]}

    tus = []  # dict(alias, key, name, kind, s, e, starts)
    used = set()
    # --- slus: game text before/after libobj, libobj spans, libgaps between
    ins = s_ins[None]
    t_lo, t_hi = ins[0][0], ins[-1][0] + 4
    fstarts = sorted(va for va, nm in s_gl[None].items() if is_fn(nm) and t_lo <= va < t_hi)
    pad = padding_sites(ins, fstarts)
    allstarts = sorted(set(fstarts) | {a for o2, a in ann.values() if o2 is None} | {s for s, _, _ in libobj}
                       | {j["os"] for j in jts if j["ovl"] is None})
    ystarts = {va for key, va, _, _ in yaml_subs("slus") if key is None}
    regions, dup, ext = [], [], []
    cur = t_lo
    for i, (s, e, owner) in enumerate(libobj):
        if i and (s, e) == libobj[i - 1][:2]:  # same span matched by two libraries' objs: one TU
            dup.append(f"{s:08X}-{e:08X} {libobj[i - 1][2]} = {owner}")
            continue
        if s > cur and (in_tb(tb, None, cur) or 0) < s:  # a gap that is all yaml textbin is no TU
            regions.append(("game" if i == 0 else "libgap", cur, s, None))
        # a span ending mid-function, or where the yaml (build truth) has no split: the TU runs to the next function
        # start (judgment call)
        nxt = min([x[0] for x in libobj if x[0] > s] + [t_hi])
        te = e if e in ystarts else min([a for a in allstarts if e < a] + [nxt])
        if te != e:
            ext.append(f"{owner} {e:08X}->{te:08X}")
        regions.append(("libobj", s, te, owner))
        cur = te
    stats["libobj_dup"], stats["libobj_ext"] = dup, ext
    if cur < t_hi:
        regions.append(("game", cur, t_hi, None))
    for kind, s, e, owner in regions:
        if kind == "libobj":
            tus.append(dict(alias="slus", key=None, name="slus/" + tu_name(owner, used), kind=kind, s=s, e=e))
        elif kind == "libgap":
            tus.append(dict(alias="slus", key=None, name=f"slus/libgap_{s:08X}", kind=kind, s=s, e=e))
        else:
            pc = {va for va in fstarts if s < va < e and pad[va][0]}  # padding cuts (droppable)
            cuts = sorted(pc | {va for va in forced.get(None, set()) if s < va < e})  # yaml starts: never dropped
            for a, b in zip([s] + cuts, cuts + [e]):
                tus.append(dict(alias="slus", key=None, name=f"slus/game_{a:08X}", kind="game", s=a, e=b,
                                cut=a in pc and a not in forced.get(None, set())))
    # libobj validation: starts whose predecessor ends unaligned
    v = dict(starts=0, unaligned_pred=0, unaligned_pred_padded=0, aligned_pred=0)
    for s, _, _ in libobj:
        if s not in pad or pad[s][1] is None:
            continue
        v["starts"] += 1
        if pad[s][1] % 8:
            v["unaligned_pred"] += 1
            v["unaligned_pred_padded"] += pad[s][0]
        else:
            v["aligned_pred"] += 1
    stats["libobj_validation"] = v
    # --- rockx5 overlays
    r_subs = yaml_subs("rockx5")
    for o in code_ovls:
        k = o["index"]
        dest = int(o["dest"], 16)
        ins = r_ins[k]
        fst = sorted({va for va, nm in r_gl.get(k, {}).items() if is_fn(nm)} | {a for o2, a in ann.values() if o2 == k}
                     | {j["os"] for j in jts if j["ovl"] == k}  # owner = Ghidra fn start (code typed as .word)
                     | {va for key, va, typ, _ in r_subs if key == k and typ == "c"})  # carved: no glabel in asm
        fst = [a for a in fst if in_tb(tb, k, a) is None]  # yaml textbin (header/tail data) holds no function
        if not fst:
            die(f"ovl{k:02d}: no function glabel")
        pad = padding_sites(ins, fst)
        # rodata (jumptables) heads the overlay (section_order); text = first fn start at/after the last jumptable
        # and after a yaml header textbin (a yaml asm start there, e.g. header code, counts as one); text ends at
        # the first yaml textbin/bin after it (tail data)
        lo = max([j["e"] for j in jts if j["ovl"] == k] + [dest, in_tb(tb, k, dest) or dest])
        fc = forced.get(k, set())
        s = min(a for a in set(fst) | fc if a >= lo)
        e = min([va for key, va, typ, _ in r_subs if key == k and va > s and typ not in ("asm", "c")]
                + [dest + o["size"]])
        pc = {va for va in fst if s < va < e and pad[va][0]}  # padding cuts (droppable)
        cuts = sorted(pc | {va for va in fc if s < va < e})  # yaml starts: never dropped
        for a, b in zip([s] + cuts, cuts + [e]):
            tus.append(dict(alias="rockx5", key=k, name=f"rockx5/ovl{k:02d}_{a:08X}", kind="overlay", s=a, e=b,
                            cut=a in pc and a not in fc))

    # --- jumptables -> owner TU; rodata order (drop violating game/overlay cuts)
    def assign():
        for t in tus:
            t["jt"] = []
        for j in jts:
            t = next((t for t in tus if t["key"] == j["ovl"] and t["s"] <= j["os"] < t["e"]), None)
            if t is None:
                die(f"jumptable owner {j['owner']} outside every TU")
            t["jt"].append(j)
    assign()
    # compare each TU with the previous TU that has jumptables (same alias/region); merge across droppable cuts only
    dropped, violations = [], []
    i, last = 0, None
    while i < len(tus):
        t = tus[i]
        if last is not None and (tus[last]["alias"], tus[last]["key"]) != (t["alias"], t["key"]):
            last = None
        if t["jt"] and last is not None and max(j["e"] for j in tus[last]["jt"]) > min(j["s"] for j in t["jt"]):
            span = tus[last + 1:i + 1]
            if all(x.get("cut") for x in span):
                dropped += [fmt(x["key"], x["s"]) for x in span]
                p = tus[last]
                p["e"], p["jt"] = t["e"], p["jt"] + [j for x in span for j in x["jt"]]
                del tus[last + 1:i + 1]
                i = last + 1
                continue
            violations.append(f"{tus[last]['name']} > {t['name']}")
        if t["jt"]:
            last = i
        i += 1
    stats["dropped"], stats["order_violations"] = dropped, violations

    # unowned rodata between consecutive TU jumptable groups
    gaps = []
    groups = {}
    for t in tus:
        if t["jt"]:
            groups.setdefault(t["key"], []).append((min(j["s"] for j in t["jt"]), max(j["e"] for j in t["jt"])))
    covered = {}
    for j in jts:
        covered.setdefault(j["ovl"], []).append((j["s"], j["e"]))
    for key, gs in groups.items():
        gs.sort()
        for (a0, a1), (b0, b1) in zip(gs, gs[1:]):
            if b0 > a1:
                gaps.append((key, a1, b0))
    stats["unowned"] = (len(gaps), sum(b - a for _, a, b in gaps))

    # unresolved computed jumps
    jr_ev = {(j["ovl"], j["jr"]) for j in jts}
    unres = []
    for key, ins in [(None, s_ins[None])] + [(k, r_ins[k]) for k in sorted(r_ins)]:
        alias = "slus" if key is None else "rockx5"
        for va, mn, ops in ins:
            if mn == "jr" and ops != "$ra" and (key, va) not in jr_ev:
                unres.append(f"{alias} {fmt(key, va)}")
    stats["unresolved"] = unres
    return tus, stats


def coalesce(spans):
    out = []
    for s, e in sorted(spans):
        if out and out[-1][1] == s:
            out[-1][1] = e
        else:
            out.append([s, e])
    return out


def write(tus, stats):
    lines = ["# docs/oracle/segments.txt -- generated by tools/build/propose_segments.py --write; never hand-edit.",
             "# <alias> <tu_name> <kind> <text start>-<end> [rodata <s>-<e>,...]  (addresses/names only, G12)",
             f"# excluded overlays: {EXCLUDED_DOC}",
             f"# dropped cuts (rodata order): {' '.join(stats['dropped']) or 'none'}"]
    lines += [f"# unresolved computed jump: {u}" for u in stats["unresolved"]]
    for t in tus:
        k = t["key"]
        line = f"{t['alias']} {t['name']} {t['kind']} {fmt(k, t['s'])}-{t['e']:08X}"
        if t["jt"]:
            line += " rodata " + ",".join(f"{fmt(k, s)}-{e:08X}" for s, e in coalesce((j["s"], j["e"]) for j in t["jt"]))
        lines.append(line)
    open(SEGMENTS, "w").write("\n".join(lines) + "\n")
    for alias in ("slus", "rockx5"):
        by = {}
        for t in tus:
            if t["alias"] == alias:
                by[t["kind"]] = by.get(t["kind"], 0) + 1
        cuts = sum(1 for t in tus if t["alias"] == alias and t.get("cut"))
        print(f"{alias}: TUs {sum(by.values())} {by}; padding cuts kept {cuts}")
    print(f"dropped cuts (rodata order): {len(stats['dropped'])} {stats['dropped']}")
    print(f"non-droppable rodata order violations: {len(stats['order_violations'])} {stats['order_violations']}")
    print(f"unowned rodata between TU jumptable groups: count {stats['unowned'][0]}, bytes {stats['unowned'][1]}")
    print(f"unresolved computed jumps: {len(stats['unresolved'])}")
    print(f"libobj padding validation: {stats['libobj_validation']}")
    print(f"libobj duplicate spans (one TU): {stats['libobj_dup']}")
    print(f"libobj TUs extended to next function start: {stats['libobj_ext']}")
    print(f"excluded overlays: {stats['excluded']}")
    print(f"wrote {os.path.relpath(SEGMENTS, ROOT)}")


def check(path):
    libobj, jts, lm, code_ovls, ann, s_ins, s_gl, r_ins, r_gl, _, _ = load_all()
    tus = []
    for line in open(path):
        if not line.strip() or line.startswith("#"):
            continue
        f = line.split()
        key, s, e = parse_range(f[3])
        ro = [parse_range(r)[1:] for r in f[5].split(",")] if len(f) > 5 and f[4] == "rodata" else []
        tus.append(dict(alias=f[0], name=f[1], kind=f[2], key=key, s=s, e=e, ro=ro))
    starts = {(None, va) for va in s_gl.get(None, {})} | {(k, va) for k, gl in r_gl.items() for va in gl}
    starts |= set(ann.values()) | {(None, s) for s, _, _ in libobj} | {(j["ovl"], j["os"]) for j in jts}
    errs = []

    def text_tu(key, a):
        return [t for t in tus if t["key"] == key and t["s"] <= a < t["e"]]

    for s, e, owner in libobj:
        hit = [t for t in tus if t["key"] is None and t["s"] <= s and e <= t["e"]]
        if len(hit) != 1:
            errs.append(f"libobj {s:08X}-{e:08X} {owner} in {len(hit)} TUs")
    for j in jts:
        hit = [t for t in tus if t["key"] == j["ovl"] and any(a <= j["s"] and j["e"] <= b for a, b in t["ro"])]
        if len(hit) != 1:
            errs.append(f"jumptable {fmt(j['ovl'], j['s'])} in {len(hit)} TU rodata lists")
        elif j.get("os") is not None and hit[0] not in text_tu(j["ovl"], j["os"]):
            errs.append(f"jumptable {fmt(j['ovl'], j['s'])} not in its owner's TU")
        if j.get("os") is not None:
            a, b = text_tu(j["ovl"], j["os"]), text_tu(j["ovl"], j["jr"])
            if len(a) != 1 or a != b:
                errs.append(f"jumptable owner range {fmt(j['ovl'], j['os'])}-{j['jr']:08X} straddles a cut")
    for alias in ("slus", "rockx5"):
        for kind in ("text", "rodata"):
            sp = {}
            for t in tus:
                if t["alias"] == alias:
                    for a, b in ([(t["s"], t["e"])] if kind == "text" else t["ro"]):
                        sp.setdefault(t["key"], []).append((a, b, t["name"]))
            for key, l in sp.items():
                l.sort()
                for x, y in zip(l, l[1:]):
                    if y[0] < x[1]:
                        errs.append(f"{alias} {kind} overlap {x[2]} / {y[2]}")
    for t in tus:
        if (t["key"], t["s"]) not in starts:
            errs.append(f"TU {t['name']} start {fmt(t['key'], t['s'])} is not a function start")
    errs += check_yamls(tus)
    for x in errs[:40]:
        print("FAIL", x)
    print(f"check: {len(tus)} TUs, {len(libobj)} libobj, {len(jts)} jumptables, {len(errs)} violations")
    return 1 if errs else 0


def check_yamls(tus):
    """Every TU is a named `asm` subsegment at its text offset in config/splat.<alias>.yaml; no extra named asm.
    An unnamed `asm` line (gen:rockx5_splits header code) stands for the TU starting at it."""
    errs = []
    for alias in ("slus", "rockx5"):
        want = {}
        for t in tus:
            if t["alias"] == alias:
                want[t["name"].split("/", 1)[1]] = ("main" if t["key"] is None else "ovl%02d" % t["key"], t["s"])
        have, anon = {}, set()
        for key, va, typ, name in yaml_subs(alias):
            if typ == "asm":
                seg = "main" if key is None else "ovl%02d" % key
                if name:
                    have[name] = (seg, va)
                else:
                    anon.add((seg, va))
        for n, w in want.items():
            if n not in have and w in anon:
                have[n] = w
        for n in sorted(set(want) | set(have)):
            if want.get(n) != have.get(n):
                errs.append(f"{alias} yaml: {n} want {want.get(n)} have {have.get(n)}")
    return errs


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--write", action="store_true")
    g.add_argument("--check", action="store_true")
    ap.add_argument("--segments", default=SEGMENTS)
    a = ap.parse_args()
    if a.write:
        write(*propose())
        return 0
    return check(a.segments)


if __name__ == "__main__":
    sys.exit(main())
