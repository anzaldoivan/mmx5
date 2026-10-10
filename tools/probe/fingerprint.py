#!/usr/bin/env python3
"""Compiler fingerprint: count aspsx/gcc asm tells T1-T6 per game module (docs/ops/compiler-pin.md).

  fingerprint.py [--alias slus|rockx5]

Modules: docs/oracle/segments.txt rows `slus * game` and `rockx5 * overlay` (libobj/libgap never read);
source asm/<tu_name>.s, decoded from the raw word in each spimdisasm comment, never from mnemonics.
Writes .run/probe/fingerprint.txt (full per-module table); prints the summary, majority profile, outliers and
`modules: <n> (slus game <k> + rockx5 overlays <m>)`. Exit 1 when m != `type: code` count in
config/splat.rockx5.yaml or a module's asm is missing. Counts, addresses and names only (G12).
"""
import argparse
import re
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
MAPS = {"slus": "build/slus/SLUS_013.34.map", "rockx5": "build/rockx5/ROCK_X5.BIN.map"}
INSN = re.compile(r"^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/\s+(\S+)\s*(.*)$")
SYMREF = re.compile(r"%(?:hi|lo)\(([A-Za-z_.$][\w.$]*)")
ADDR_IN_NAME = re.compile(r"_([0-9A-F]{8})(?:_\w+)?$")
RAM_END = 0x80200000
LOADS = {0x20, 0x21, 0x23, 0x24, 0x25, 0x22, 0x26}  # lb lh lw lbu lhu lwl lwr (+ lwc2 0x32)
ALIGNED = {0x20, 0x21, 0x23, 0x24, 0x25}  # lb lh lw lbu lhu: maspsx aligned_load_mnemonics
STORES = {0x28, 0x29, 0x2A, 0x2B, 0x2E}
BRK7_GNU, BRK7_MAS, BRK6_GNU, BRK6_MAS = 0x0007000D, 0x000001CD, 0x0006000D, 0x0000018D
TGE93 = (93 << 6) | 0x30


def f(w):
    """(op, rs, rt, rd, funct, simm)"""
    imm = w & 0xFFFF
    return w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31, w & 63, imm - 0x10000 if imm & 0x8000 else imm


def reads(w):
    op, rs, rt, rd, fn, _ = f(w)
    if w == 0:
        return set()
    if op == 0:
        if fn in (0, 2, 3):
            r = {rt}
        elif fn in (8, 9, 0x11, 0x13):
            r = {rs}
        elif fn in (0x10, 0x12, 0x0C, 0x0D):
            r = set()
        else:
            r = {rs, rt}
    elif op == 1 or op in (6, 7):
        r = {rs}
    elif op in (4, 5):
        r = {rs, rt}
    elif op in (2, 3, 0x0F):
        r = set()
    elif op in (0x10, 0x12):  # cop0/cop2: mtc/ctc read rt
        r = {rt} if rs in (4, 6) else set()
    elif op in (0x22, 0x26) or op in STORES:
        r = {rs, rt}
    else:
        r = {rs}
    return r - {0}


def load_dest(w):
    op, _, rt, *_ = f(w)
    return rt if op in LOADS and rt else None


def is_muldiv(w):
    return w >> 26 == 0 and 0x18 <= (w & 63) <= 0x1B


def segments():
    rows = []
    for line in (ROOT / "docs/oracle/segments.txt").read_text().splitlines():
        p = line.split()
        if line.startswith("#") or len(p) < 4:
            continue
        if (p[0], p[2]) in (("slus", "game"), ("rockx5", "overlay")):
            rows.append((p[0], p[1], p[3]))
    return rows


def read_map(alias):
    """symbol -> addr, plus bss starts {name_prefix: start}; None when the map is absent."""
    path = ROOT / MAPS[alias]
    if not path.exists():
        return None
    syms, bss = {}, {}
    for line in path.read_text().splitlines():
        m = re.match(r"^\s+0x([0-9a-f]+)\s+(\w+)(?: = \.)?\s*$", line)
        if m:
            syms[m.group(2)] = int(m.group(1), 16)
            if m.group(2).endswith("_BSS_START"):
                bss[m.group(2)[:-10]] = int(m.group(1), 16)
    return syms, bss


def sym_addr(name, syms):
    m = ADDR_IN_NAME.search(name)
    if m:
        return int(m.group(1), 16)
    return syms.get(name) if syms else None


def parse(path):
    """list of functions, each a list of (vram, word, mnem, ops)."""
    fns, cur = [], None
    for line in path.read_text().splitlines():
        s = line.strip()
        if s.startswith("glabel "):
            cur = []
            fns.append(cur)
        elif s.startswith(("dlabel ", "endlabel ", "enddlabel ")):
            cur = None
        else:
            m = INSN.match(line)
            if m and cur is not None and not m.group(3).startswith("."):
                cur.append((int(m.group(1), 16), int(m.group(2)[6:8] + m.group(2)[4:6] + m.group(2)[2:4]
                                                       + m.group(2)[0:2], 16), m.group(3), m.group(4)))
    return fns


def count(fns, bss_own, bss_exe, syms):
    c = Counter()
    frames, refs = Counter(), set()
    for fn in fns:
        ws = [x[1] for x in fn] + [0, 0, 0, 0]
        n = len(fn)
        size = None
        for i in range(n):
            w = ws[i]
            op, rs, rt, rd, fn_, imm = f(w)
            # T1 divide
            if op == 0 and fn_ in (0x1A, 0x1B) and rs | rt:  # word 0x1A at overlay heads is not a div
                # check = `bnez rt` then break 7 (either encoding); adj = right after div (as-expanded
                # shape), sched = later, after mflo (cc1-emitted check, scheduled), none = unchecked
                k, kind = "div" if fn_ == 0x1A else "divu", "none"
                for j in range(i + 1, n):
                    o1, s1, t1, *_ = f(ws[j])
                    if o1 == 5 and s1 == rt and t1 == 0 and {ws[j + 1], ws[j + 2]} & {BRK7_GNU, BRK7_MAS}:
                        kind = "adj" if j == i + 1 else "sched"
                        break
                c[f"{k}_{kind}"] += 1
            for name, val in (("brk7_gnu", BRK7_GNU), ("brk7_mas", BRK7_MAS), ("brk6_gnu", BRK6_GNU),
                              ("brk6_mas", BRK6_MAS), ("tge93", TGE93)):
                c[name] += w == val
            # T2 li / la / $at
            if op == 0x0D and rs == 0 and rt and (w & 0xFFFF) < 0x8000:
                c["li_ori"] += 1
            if op == 9 and rs == 0 and rt and 0 < imm < 0x8000:
                c["li_addiu"] += 1
            if op == 0x0F:
                o1, s1, t1, d1, f1, _ = f(ws[i + 1])
                if rt == 1 and o1 == 9 and s1 == 1 and t1 == 1:
                    o2, s2, t2, d2, f2, _ = f(ws[i + 2])
                    o3, s3, *_, i3 = f(ws[i + 3])
                    if o2 == 0 and f2 == 0x21 and d2 == 1 and 1 in (s2, t2) and s3 == 1 and i3 == 0:
                        c["at4"] += 1
                elif rt == 1 and o1 == 0 and f1 == 0x21 and d1 == 1 and 1 in (s1, t1):
                    o2, s2, *_ = f(ws[i + 2])
                    if s2 == 1 and (o2 in LOADS or o2 in STORES):
                        c["at3"] += 1
                elif rt != 1 and o1 == 9 and s1 == rt and t1 == rt:
                    c["la"] += 1
            # T3 load delay
            d = load_dest(w)
            if op == 0x32:
                c["lwc2"] += 1
            if d or op == 0x32:
                w1, w2 = ws[i + 1], ws[i + 2]
                if i + 1 >= n:
                    pass
                elif w1 == 0:
                    if d and d in reads(w2):
                        c["ld_nop_use"] += 1
                    elif d and w2 >> 26 in ALIGNED and (w2 >> 16) & 31 == d:
                        c["ld_nop_lwlw"] += 1
                    else:
                        c["ld_nop_other"] += 1
                elif d and d in reads(w1):
                    c["ld_dep"] += 1
                else:
                    c["ld_indep"] += 1
            if op == 0 and fn_ in (0x10, 0x12):
                k = next((j for j in range(3) if is_muldiv(ws[i + 1 + j])), None)
                if k is not None:
                    c["mf_hazard" if k < 2 else "mf_nop%d" % sum(x == 0 for x in ws[i + 1:i + 3])] += 1
            # T4 $gp
            if op not in (0, 1, 2, 3, 0x0F, 0x10, 0x12) and rs == 28:
                c["gp"] += 1
            # T5 frames
            if op == 9 and rs == 29 and rt == 29 and imm < 0 and size is None:
                size = -imm
            if op == 0 and fn_ in (0x21, 0x25) and rd == 30 and 29 in (rs, rt):
                c["fp"] += 1
            if op == 0x2B and rt == 31 and rs == 29 and size:
                c["ra_" + ("s-4" if imm == size - 4 else "s-8" if imm == size - 8 else "other")] += 1
            if op == 0 and fn_ == 8 and rs == 31 and size:
                o1, s1, t1, *_, i1 = f(ws[i + 1])
                c["ep_slot" if o1 == 9 and s1 == 29 and t1 == 29 and i1 > 0 else "ep_before"] += 1
            # T6 bss refs
            for sym in SYMREF.findall(fn[i][3]):
                refs.add(sym)
        c["fns"] += 1
        if size is None:
            c["leaf"] += 1
        else:
            frames[size] += 1
            c["frame_not8"] += size % 8 != 0
    if bss_own is not None:
        for sym in refs:
            a = sym_addr(sym, syms)
            if a is None:
                c["bss_unres"] += 1
            elif bss_own[0] <= a < bss_own[1]:
                c["bss_own"] += 1
            elif bss_exe and bss_exe[0] <= a < bss_exe[1]:
                c["bss_exe"] += 1
    return c, frames


def mix(a, b, na, nb):
    return "-" if not (a or b) else na if not b else nb if not a else "mixed"


def profile(c):
    return {
        "div": max(("adj", "sched", "none"), key=lambda k: c["div_" + k] + c["divu_" + k])
        if any(c[f"{d}_{k}"] for d in ("div", "divu") for k in ("adj", "sched", "none")) else "-",
        "break": mix(c["brk7_gnu"] + c["brk6_gnu"], c["brk7_mas"] + c["brk6_mas"], "gnu", "maspsx"),
        "tge": "yes" if c["tge93"] else "no",
        "li": mix(c["li_ori"], c["li_addiu"], "ori", "addiu"),
        "at": mix(c["at4"], c["at3"], "at4", "at3"),
        "nop_lwlw": "yes" if c["ld_nop_lwlw"] else "no",
        "mf": mix(c["mf_nop2"] + c["mf_nop1"], c["mf_hazard"], "padded", "hazard"),
        "gp": "yes" if c["gp"] else "no",
        "fp": "yes" if c["fp"] else "no",
        "ra_other": "yes" if c["ra_other"] else "no",  # s-4 vs s-8 both occur in nearly every module
        "ep": mix(c["ep_slot"], c["ep_before"], "slot", "before"),
    }


COLS = ["fns", "leaf", "frame_not8", "div_adj", "div_sched", "div_none", "divu_adj", "divu_sched", "divu_none",
        "brk7_gnu", "brk7_mas", "brk6_gnu", "brk6_mas", "tge93", "li_ori", "li_addiu", "at4", "at3", "la", "ld_nop_use", "ld_nop_lwlw",
        "ld_nop_other", "ld_indep", "ld_dep", "lwc2", "mf_hazard", "mf_nop2", "mf_nop1", "mf_nop0", "gp", "fp",
        "ra_s-4", "ra_s-8", "ra_other", "ep_slot", "ep_before", "bss_own", "bss_exe", "bss_unres"]


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--alias", choices=sorted(MAPS))
    args = ap.parse_args()
    rows = segments()
    k = sum(a == "slus" for a, *_ in rows)
    m = len(rows) - k
    want = sum(1 for line in (ROOT / "config/splat.rockx5.yaml").read_text().splitlines()
               if line.strip() == "type: code")
    if m != want:
        print(f"error: {m} rockx5 overlay rows in segments.txt, {want} code segments in splat.rockx5.yaml")
        return 1
    maps = {a: read_map(a) for a in MAPS}
    ovl_base = min(int(x, 16) for x in re.findall(r"^\s*vram: (0x[0-9A-Fa-f]+)",
                                                  (ROOT / "config/splat.rockx5.yaml").read_text(), re.M))
    exe_bss = (maps["slus"][1]["main"], ovl_base) if maps["slus"] else None
    out, results = [], {}
    for alias, tu, rng in rows:
        if args.alias and alias != args.alias:
            continue
        path = ROOT / "asm" / (tu + ".s")
        if not path.exists():
            print(f"error: {path.relative_to(ROOT)} missing: run make split BINARY={alias}")
            return 1
        mp = maps[alias]
        if mp is None:
            own = None
        elif alias == "slus":
            own = exe_bss
        else:
            own = (mp[1][rng.split(":")[0]], RAM_END)
        c, frames = count(parse(path), own, exe_bss if alias == "rockx5" else None, mp[0] if mp else None)
        results[tu] = (c, frames)
        bss = "bss: n/a" if own is None else ""
        out.append(f"{tu} " + " ".join(f"{col}={c[col]}" for col in COLS if not (bss and col.startswith("bss")))
                   + (" " + bss if bss else "") + " frames=" + ",".join(
                       f"{s:#x}:{v}" for s, v in sorted(frames.items(), key=lambda x: (-x[1], x[0]))[:6]))
    tot, ftot = Counter(), Counter()
    for c, fr in results.values():
        tot.update(c)
        ftot.update(fr)
    out.append("TOTAL " + " ".join(f"{col}={tot[col]}" for col in COLS) + " frames=" + ",".join(
        f"{s:#x}:{v}" for s, v in sorted(ftot.items(), key=lambda x: (-x[1], x[0]))[:10]))
    profs = {tu: profile(c) for tu, (c, _) in results.items()}
    major = {}
    for key in next(iter(profs.values())):
        vals = Counter(p[key] for p in profs.values() if p[key] != "-")
        major[key] = vals.most_common(1)[0][0] if vals else "-"
    out.append("majority: " + " ".join(f"{a}={b}" for a, b in major.items()))
    outl = []
    for tu, p in profs.items():
        dif = [f"{a}={b}" for a, b in p.items() if b != "-" and major[a] != "-" and b != major[a]]
        if dif:
            outl.append(f"outlier: {tu} " + " ".join(dif))
    out += outl or ["outliers: none"]
    ks = sum(tu.startswith("slus/") for tu in results)
    out.append(f"modules: {len(results)} (slus game {ks} + rockx5 overlays {len(results) - ks})")
    dest = ROOT / ".run/probe/fingerprint.txt"
    dest.parent.mkdir(parents=True, exist_ok=True)
    dest.write_text("\n".join(out) + "\n")
    print("\n".join(out))
    return 0


if __name__ == "__main__":
    sys.exit(main())
