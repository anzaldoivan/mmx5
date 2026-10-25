#!/usr/bin/env python3
"""scan.py — pointer scanner: every value pointing into SLUS_013.34's range or an overlay region that no relocation
symbolizes; directions exe->exe, exe->ovl, ovl->exe, ovl->ovl.

  [--exe ELF] [--ovl ELF] [--allow F] [--report F] [--no-plant] [--baseline]   scan both -q linked ELFs
  --selftest                                                                   synthetic ELF, game-free
Kinds, range, plant, allowlist: tools/shift/README.md. Exit 0 iff 0 unsymbolized and every plant caught (--baseline: 0).
"""
import argparse, bisect, re, struct, sys
from pathlib import Path

EXE_LO, IMAGE_END, OVL_VRAM, GP = 0x80010000, 0x80092000, 0x800EE970, 0x80091C30
SHF_ALLOC, SHF_EXEC, SHT_SYMTAB, SHT_NOBITS, SHT_REL, SHN_ABS = 2, 4, 2, 8, 9, 0xFFF1
R32, R26, HI16, LO16, GPREL16 = 2, 4, 5, 6, 7
STT_FUNC, STT_SECTION, STT_FILE = 2, 3, 4
WINDOW = 8  # lui -> lo user: at most 8 following words, stopped early when rX is written
LO_OPS = {0x09, 0x0D, 0x20, 0x21, 0x23, 0x24, 0x25, 0x28, 0x29, 0x2B, 0x32, 0x3A}  # addiu ori l{b,h,w,bu,hu} s{b,h,w} lwc2 swc2
GP_OPS = LO_OPS - {0x0D}
KINDS = ("data", "hilo", "gprel", "jal", "abs")
DIRS = ("exe->exe", "exe->ovl", "ovl->exe", "ovl->ovl")


def parse(data):
    """-> {'secs': [dict], 'syms': [(name, value, size, type, shndx)], 'rel': {sec index: {vaddr: (type, sym)}},
    'glob': {(name, value)} of GLOBAL/WEAK symbols defined in a section (not UND, not ABS)}"""
    shoff, = struct.unpack_from("<I", data, 0x20)
    shent, shnum, shstr = struct.unpack_from("<HHH", data, 0x2E)
    raw = [struct.unpack_from("<10I", data, shoff + i * shent) for i in range(shnum)]
    cstr = lambda off: data[off:data.index(b"\0", off)].decode()
    secs = [dict(name=cstr(raw[shstr][4] + h[0]), type=h[1], flags=h[2], addr=h[3], size=h[5],
                 bytes=b"" if h[1] == SHT_NOBITS else data[h[4]:h[4] + h[5]], link=h[6], info=h[7]) for h in raw]
    syms, rel, glob = [], {}, set()
    for s in secs:
        if s["type"] == SHT_SYMTAB:
            st = secs[s["link"]]["bytes"]
            for o in range(0, len(s["bytes"]), 16):
                nm, val, size, info, _, shndx = struct.unpack_from("<IIIBBH", s["bytes"], o)
                syms.append((st[nm:st.index(b"\0", nm)].decode(), val, size, info & 15, shndx))
                if info >> 4 in (1, 2) and shndx not in (0, SHN_ABS):
                    glob.add((syms[-1][0], val))
    for s in secs:
        if s["type"] == SHT_REL:
            rel[s["info"]] = {off: (inf & 0xFF, inf >> 8) for off, inf in struct.iter_unpack("<II", s["bytes"])}
    return dict(secs=secs, syms=syms, rel=rel, glob=glob)


def load(path):
    """parse() + text ranges from the ld map beside the ELF (<name>.map)."""
    elf = parse(Path(path).read_bytes())
    elf["text"] = text_ranges(Path(path).with_suffix(".map"))
    return elf


def exe_range(exe):
    """Header b_size is 0: bss end = end of the exe's alloc NOBITS sections (splat bss subsegment) when present,
    else highest exe ABS symbol below overlay vram, rounded up to 4, + 1 word."""
    bss = [s["addr"] + s["size"] for s in exe["secs"] if s["type"] == SHT_NOBITS and s["flags"] & SHF_ALLOC
           and s["size"] and EXE_LO <= s["addr"] < OVL_VRAM]
    if bss:
        return EXE_LO, max(IMAGE_END, *bss)
    top = max([v for _, v, _, t, x in exe["syms"] if x == SHN_ABS and t != STT_FILE and v < OVL_VRAM] + [0])
    return EXE_LO, max(IMAGE_END, ((top + 3) & ~3) + 4)


def ovl_regions(ovl):
    """[(vram, max ovlNN_VRAM_END)] grouping rockx5 ovlNN by ovlNN_VRAM (ld map symbols in the ELF symtab).
    Asserts every .ovlNN output section starts at ovlNN_VRAM and spans ovlNN_ROM_END - ovlNN_ROM_START."""
    v = {n: x for n, x, *_ in ovl["syms"] if re.fullmatch(r"ovl\d+_(VRAM|VRAM_END|ROM_START|ROM_END)", n)}
    for s in ovl["secs"]:
        k = s["name"][1:]
        if re.fullmatch(r"ovl\d+", k) and (v.get(k + "_VRAM"), v.get(k + "_ROM_END", 0) - v.get(k + "_ROM_START", 0)) \
                != (s["addr"], s["size"]):
            raise SystemExit(f"shift-scan: .{k} does not match {k}_VRAM / {k}_ROM_START..END")
    reg = {}
    for n, x in v.items():
        if n.endswith("_VRAM"):
            reg[x] = max(reg.get(x, x), v[n + "_END"])
    return sorted(reg.items())


def direction(f, rng):
    return ("exe" if f[0] == "slus" else "ovl") + "->" + ("exe" if rng[0] <= f[3] < rng[1] else "ovl")


def text_ranges(map_path):
    """{output section: [(lo, hi)]} of `.text` inputs in the ld map, minus objects under asm/<a>/data/
    (splat textbin .incbin blobs). splat links text+data into one WAX section, so the flag alone cannot tell."""
    out, cur = {}, None
    for line in Path(map_path).read_text().splitlines():
        if m := re.match(r"(\.\w+)\s+0x", line):
            cur = m[1]
        elif (m := re.match(r" \.text\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+(\S+)", line)) and "/data/" not in m[3]:
            out.setdefault(cur, []).append((int(m[1], 16), int(m[1], 16) + int(m[2], 16)))
    return out


def text_mask(elf, s):
    """Word mask of instructions: an exec section's map text ranges; without a map, the whole exec section."""
    m = bytearray(len(s["bytes"]) // 4)
    if not s["flags"] & SHF_EXEC:
        return m
    if elf.get("text") is None:
        return bytearray(b"\1" * len(m))
    for lo, hi in elf["text"].get(s["name"], []):
        a, b = max(0, (lo - s["addr"]) // 4), min(len(m), (hi - s["addr"] + 3) // 4)
        m[a:b] = b"\1" * max(0, b - a)
    return m


def writes(u):
    op = u >> 26
    if op == 0:
        return (u >> 11) & 31
    if op == 3:
        return 31
    if 0x08 <= op <= 0x0F or 0x20 <= op <= 0x26 or (op in (0x10, 0x12) and (u >> 21) & 31 in (0, 2)):
        return (u >> 16) & 31
    return None


def scan(elf, alias, rngs, drop=None, exe_glob=frozenset()):
    """-> [(alias, kind, site, target, site section)]; rngs: target ranges [(lo, hi)] (exe range + overlay regions);
    drop: (section index, vaddr) whose relocation is ignored (a plant); sites keyed by section, overlays share vram.
    exe_glob: (name, value) of exe/rockx5 in-section globals; an ABS reloc symbol in it is symbolized (rockx5 links the
    exe's names as ABS: --just-symbols / exe_syms.ld)."""
    m = []
    for lo, hi in sorted(rngs):
        if m and lo <= m[-1][1]:
            m[-1][1] = max(m[-1][1], hi)
        else:
            m.append([lo, hi])
    inr = lambda v: any(lo <= v < hi for lo, hi in m)
    syms, out = elf["syms"], []
    for si, s in enumerate(elf["secs"]):
        if not s["flags"] & SHF_ALLOC or not s["bytes"]:
            continue
        rel, a, text = elf["rel"].get(si, {}), s["addr"], text_mask(elf, s)
        words = struct.unpack_from(f"<{len(s['bytes']) // 4}I", s["bytes"])
        rt_of = lambda va: None if (si, va) == drop else rel.get(va, (None, 0))[0]
        add = lambda k, va, t: out.append((alias, k, va, t, s["name"]))
        for i, w in enumerate(words):
            va = a + 4 * i
            r = rel.get(va) if (si, va) != drop else None
            if r and syms[r[1]][4] == SHN_ABS and inr(syms[r[1]][1]) and syms[r[1]][:2] not in exe_glob:
                add("abs", va, syms[r[1]][1])
                continue
            if inr(w) and rt_of(va) != R32:
                add("data", va, w)
                continue
            if not text[i]:
                continue
            op, rs, rt, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
            simm = imm - ((imm & 0x8000) << 1)
            if op in (2, 3) and rt_of(va) != R26:
                t = ((va + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
                if inr(t):
                    add("jal", va, t)
            elif op == 0x0F and rt_of(va) != HI16:
                for j in range(i + 1, min(i + 1 + WINDOW, len(words))):
                    u = words[j]
                    if not text[j]:
                        break
                    if u >> 26 in LO_OPS and (u >> 21) & 31 == rt:
                        if rt_of(a + 4 * j) != LO16:
                            l = u & 0xFFFF
                            t = (imm << 16) | l if u >> 26 == 0x0D else ((imm << 16) + l - ((l & 0x8000) << 1)) & 0xFFFFFFFF
                            if inr(t):
                                add("hilo", va, t)
                        break
                    if writes(u) == rt:
                        break
            elif rs == 28 and op in GP_OPS and rt_of(va) != GPREL16 and not (op == 0x09 and rt == 28):  # gp setup
                t = (GP + simm) & 0xFFFFFFFF
                if inr(t):
                    add("gprel", va, t)
    return out


def plant_site(exe, rngs):
    """(section index, vaddr) of the first R_MIPS_32 at a data (non-instruction) word, in-section symbol, value in rngs."""
    for si, s in enumerate(exe["secs"]):
        if not s["flags"] & SHF_ALLOC or not s["bytes"]:
            continue
        text = text_mask(exe, s)
        for va, (t, sym) in sorted(exe["rel"].get(si, {}).items()):
            i = (va - s["addr"]) // 4
            if t == R32 and not text[i] and exe["syms"][sym][4] != SHN_ABS:
                if any(lo <= struct.unpack_from("<I", s["bytes"], 4 * i)[0] < hi for lo, hi in rngs):
                    return si, va
    return None


def abs_in_data(elf, found):
    """Exe `abs` findings at non-instruction words (map data/rodata, textbin blobs)."""
    masks = {i: text_mask(elf, s) for i, s in enumerate(elf["secs"]) if s["flags"] & SHF_ALLOC and s["bytes"]}
    n = 0
    for al, k, va, *_ in found:
        if al == "slus" and k == "abs":
            i = next((i for i in masks if 0 <= va - elf["secs"][i]["addr"] < len(elf["secs"][i]["bytes"])), None)
            n += i is None or not masks[i][(va - elf["secs"][i]["addr"]) // 4]
    return n


def run(exe, ovl, allow, report, plant=True):
    """-> (findings, exe range, overlay regions, plants [(direction, (section index, vaddr) or None, caught)])"""
    rng = exe_range(exe)
    regs = ovl_regions(ovl) if ovl else []
    rngs, oglob = [rng] + regs, ovl["glob"] if ovl else frozenset()
    found = scan(exe, "slus", rngs, exe_glob=oglob) + (scan(ovl, "rockx5", rngs, exe_glob=exe["glob"] | oglob) if ovl else [])
    found = [f for f in found if (f[0], f[2], f[3]) not in allow]

    def caught(elf, alias, glob, site, d):
        return site is not None and any(f[1] == "data" and (f[2], f[4]) == (site[1], elf["secs"][site[0]]["name"])
                                        and direction(f, rng) == d for f in scan(elf, alias, rngs, site, glob))
    plants = []
    if plant:
        site = plant_site(exe, [rng])  # exe->exe: drop the reloc
        plants.append(("exe->exe", site, caught(exe, "slus", oglob, site, "exe->exe")))
        if site and regs:  # exe->ovl: same word patched to an overlay-region address, reloc dropped
            sec = dict(exe["secs"][site[0]])
            b = bytearray(sec["bytes"])
            struct.pack_into("<I", b, site[1] - sec["addr"], regs[0][0])
            sec["bytes"] = bytes(b)
            pat = dict(exe, secs=exe["secs"][:site[0]] + [sec] + exe["secs"][site[0] + 1:])
            plants.append(("exe->ovl", site, caught(pat, "slus", oglob, site, "exe->ovl")))
        else:
            plants.append(("exe->ovl", None, False))
        site = plant_site(ovl, regs) if ovl else None  # ovl->ovl: drop a rockx5 reloc into an overlay region
        plants.append(("ovl->ovl", site, ovl is not None and caught(ovl, "rockx5", exe["glob"] | oglob, site, "ovl->ovl")))
    if report:
        def table(elf, keep):
            named = sorted((v, n) for n, v, _, t, x in elf["syms"] if n and t not in (STT_SECTION, STT_FILE) and keep(x))
            return [v for v, _ in named], named
        exet = table(exe, lambda x: True)
        osec = {}
        for n, v, _, t, x in (ovl["syms"] if ovl else []):
            if n and t not in (STT_SECTION, STT_FILE) and x not in (0, SHN_ABS) and x < len(ovl["secs"]):
                osec.setdefault(ovl["secs"][x]["name"], []).append((v, n))
        osec = {k: ([v for v, _ in sorted(l)], sorted(l)) for k, l in osec.items()}
        oall = table(ovl, lambda x: x not in (0, SHN_ABS)) if ovl else ([], [])

        def near(t, tab):  # ovl target: rockx5 symbol of the site's overlay when the site is one, else of any overlay
            vals, named = tab
            k = bisect.bisect_right(vals, t) - 1
            return "-" if k < 0 else named[k][1] + (f"+0x{t - vals[k]:X}" if t != vals[k] else "")
        Path(report).parent.mkdir(parents=True, exist_ok=True)
        Path(report).write_text("".join(
            f"{f[0]} {f[4].lstrip('.')} {direction(f, rng)} {f[1]} {f[2]:08X} -> {f[3]:08X} "
            f"{near(f[3], exet if rng[0] <= f[3] < rng[1] else osec.get(f[4], oall) if f[0] == 'rockx5' else oall)}\n"
            for f in found))
    return found, rng, regs, plants


def load_allow(path):
    allow = set()
    if path and Path(path).exists():
        for line in Path(path).read_text().splitlines():
            f = line.split("--")[0].split()
            if len(f) == 3 and not line.lstrip().startswith("#"):
                allow.add((f[0], int(f[1], 16), int(f[2], 16)))
    return allow


def translate_allow(allow, retail, exe):
    """slus allowlist sites keyed by retail vaddr -> the scanned exe's: retail symbol containing the site (largest
    value <= site within size, else nearest preceding global) + offset, same name resolved in `exe`. Missing: exit 1."""
    def named(elf):
        return [(v, z, n) for n, v, z, t, x in elf["syms"] if n and t not in (STT_SECTION, STT_FILE) and x not in (0, SHN_ABS)]
    rs = sorted(named(retail))
    glob = sorted((v, n) for n, v in retail["glob"])
    where = {}
    for v, _, n in named(exe):
        where.setdefault(n, set()).add(v)
    out = set()
    for al, site, val in allow:
        if al != "slus":
            out.add((al, site, val))
            continue
        hit = [(v, n) for v, z, n in rs if v <= site < v + z]
        if hit:
            v, n = max(hit)
        else:
            k = bisect.bisect_right(glob, (site, "￿")) - 1
            if k < 0:
                raise SystemExit(f"shift-scan: allow slus {site:08X}: no retail symbol at or before it")
            v, n = glob[k]
        if len(where.get(n, ())) != 1:
            raise SystemExit(f"shift-scan: allow slus {site:08X}: {n} {'missing' if n not in where else 'ambiguous'}"
                             " in the scanned exe")
        out.add((al, next(iter(where[n])) + site - v, val))
    return out


def summary(found, rng, regs, plants, absd=0):
    c = {k: sum(f[1] == k for f in found) for k in KINDS}
    print(f"shift-scan: range {rng[0]:08X}..{rng[1]:08X}")
    print("shift-scan: ovl regions " + (", ".join(f"{lo:08X}..{hi:08X}" for lo, hi in regs) or "none"))
    print(f"shift-scan: {len(found)} unsymbolized (exe {sum(f[0] == 'slus' for f in found)}, "
          f"rockx5 {sum(f[0] == 'rockx5' for f in found)}; " + ", ".join(f"{k} {c[k]}" for k in KINDS) + f"); exe data "
          f"{sum(f[0] == 'slus' and f[1] == 'data' for f in found)}, abs-in-data {absd}")
    for d in DIRS:
        fs = [f for f in found if direction(f, rng) == d]
        print(f"shift-scan: {d} {len(fs)} (" + ", ".join(f"{k} {sum(f[1] == k for f in fs)}" for k in KINDS) + ")")
    for d, site, caught in plants:
        print(f"shift-scan: plant caught at {site[1]:08X} ({d})" if caught else f"shift-scan: plant NOT caught ({d})")


def elf32(secs, syms):
    """Minimal ELF32-LE ET_EXEC: secs [(name, type, flags, addr, bytes, link, info)], syms [(name, value, size, type, shndx)]."""
    strtab, symb = b"\0", b"\0" * 16
    for n, v, z, t, x in syms:
        symb += struct.pack("<IIIBBH", len(strtab), v, z, 0x10 | t, 0, x)
        strtab += n.encode() + b"\0"
    secs = secs + [(".symtab", SHT_SYMTAB, 0, 0, symb, len(secs) + 2, 1), (".strtab", 3, 0, 0, strtab, 0, 0)]
    shstr = b"\0" + b"".join(s[0].encode() + b"\0" for s in secs) + b".shstrtab\0"
    secs.append((".shstrtab", 3, 0, 0, shstr, 0, 0))
    body, hdrs, no = bytearray(52), [b"\0" * 40], 1
    for n, t, f, a, b, l, i in secs:
        hdrs.append(struct.pack("<10I", no, t, f, a, len(body), len(b), l, i, 4, 16 if t == SHT_SYMTAB else 0))
        body += b
        no += len(n) + 1
    shoff = len(body)
    body[:52] = b"\x7fELF\1\1\1" + b"\0" * 9 + struct.pack("<HHIIIIIHHHHHH", 2, 8, 1, 0, 0, shoff, 0, 52, 0, 0, 40,
                                                                   len(secs) + 1, len(secs))
    return bytes(body + b"".join(hdrs))


def selftest():
    T, D = 0x80010000, 0x80010100
    text = struct.pack("<6I", 0x3C048001, 0x24840100, 0x8F820100, 0x03E00008, 0, 0)  # lui/addiu a0; lw v0,0x100(gp)
    O = OVL_VRAM
    data = struct.pack("<4I", 0x80010004, D, 0x80095000, O + 8)  # raw; R32 to .data; R32 to ABS; raw exe->ovl
    rel = struct.pack("<4I", D + 4, (2 << 8) | R32, D + 8, (3 << 8) | R32)
    elf = elf32([(".text", 1, SHF_ALLOC | SHF_EXEC, T, text, 0, 0), (".data", 1, SHF_ALLOC | 1, D, data, 0, 0),
                 (".rel.data", SHT_REL, 0, 0, rel, 4, 2)],
                [("f", T, len(text), STT_FUNC, 1), ("d", D, 0, 1, 2), ("A", 0x80095000, 0, 0, SHN_ABS)])
    # overlay .ovl00: ABS "d" = exe global d at D (symbolized), ABS "A" (ABS in the exe too: reported, ovl->exe),
    # raw O+4 (ovl->ovl), R32 to in-section "o" (symbolized; the ovl->ovl plant)
    orel = struct.pack("<6I", O, (1 << 8) | R32, O + 4, (2 << 8) | R32, O + 12, (7 << 8) | R32)
    ovl = elf32([(".ovl00", 1, SHF_ALLOC | 1, O, struct.pack("<4I", D, 0x80095000, O + 4, O), 0, 0),
                 (".rel.ovl00", SHT_REL, 0, 0, orel, 3, 1)],
                [("d", D, 0, 1, SHN_ABS), ("A", 0x80095000, 0, 0, SHN_ABS), ("ovl00_VRAM", O, 0, 0, 1),
                 ("ovl00_VRAM_END", O + 16, 0, 0, 1), ("ovl00_ROM_START", 0x800, 0, 0, SHN_ABS),
                 ("ovl00_ROM_END", 0x810, 0, 0, SHN_ABS), ("o", O, 0, 1, 1)])
    found, rng, regs, plants = run(parse(elf), parse(ovl), set(), None)
    got = {(f[0], f[1], f[2], direction(f, rng)) for f in found}
    want = {("slus", "hilo", T, "exe->exe"), ("slus", "gprel", T + 8, "exe->exe"), ("slus", "data", D, "exe->exe"),
            ("slus", "abs", D + 8, "exe->exe"), ("slus", "data", D + 12, "exe->ovl"),
            ("rockx5", "abs", O + 4, "ovl->exe"), ("rockx5", "data", O + 8, "ovl->ovl")}
    if abs_in_data(parse(elf), found) != 1:
        raise SystemExit("shift-scan: selftest FAIL abs-in-data")
    if got != want or rng != (EXE_LO, 0x80095004) or regs != [(O, O + 16)] or plants != [
            ("exe->exe", (2, D + 4), True), ("exe->ovl", (2, D + 4), True), ("ovl->ovl", (1, O + 12), True)]:
        raise SystemExit(f"shift-scan: selftest FAIL got {sorted(got)} range {rng} regions {regs} plants {plants}")
    moved = dict(syms=[("f", T + 0x40, len(text), STT_FUNC, 1), ("d", D + 0x40, 0, 1, 2)])
    if translate_allow({("slus", T + 4, 1), ("slus", D + 8, 2), ("rockx5", O, 3)}, parse(elf), moved) != {
            ("slus", T + 0x44, 1), ("slus", D + 0x48, 2), ("rockx5", O, 3)}:
        raise SystemExit("shift-scan: selftest FAIL retail-exe allow translation")
    print("shift-scan: control OK")


def main():
    if "--selftest" in sys.argv[1:]:
        return selftest()
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--exe", default="build/slus/SLUS_013.34.elf")
    ap.add_argument("--ovl", default="build/rockx5/ROCK_X5.BIN.elf")
    ap.add_argument("--allow", default="config/shift/not_pointers.txt")
    ap.add_argument("--report", default=".run/shift/scan.txt")
    ap.add_argument("--no-plant", action="store_true")
    ap.add_argument("--baseline", action="store_true")
    ap.add_argument("--retail-exe", help="retail-linked exe ELF: slus allowlist sites translated by symbol+offset")
    a = ap.parse_args()
    exe = load(a.exe)
    allow = load_allow(a.allow)
    if a.retail_exe:
        allow = translate_allow(allow, parse(Path(a.retail_exe).read_bytes()), exe)
    found, rng, regs, plants = run(exe, load(a.ovl) if a.ovl else None, allow, a.report, not a.no_plant)
    summary(found, rng, regs, plants, abs_in_data(exe, found))
    ok = not found and all(c for _, _, c in plants)
    return 0 if ok or a.baseline else 1


if __name__ == "__main__":
    sys.exit(main())
