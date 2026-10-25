#!/usr/bin/env python3
"""Write an ld script defining every symbol the objects reference but nothing defines, at the vram in its name.

usage: undef_by_name.py [--just-symbols <exe.elf>] <out.ld> <obj>...   (readelf from tools/bin/binutils; nm hides `.L` names)
       undef_by_name.py exe-syms <exe.elf> <out.txt>   splat symbol_addrs of the exe's globals (rockx5 split),
                                                       and <out>.ld: the same names as ld assignments
--just-symbols: names that ELF defines are skipped; any other undefined name whose vram is in the exe range
[0x80010000, 0x800EE970) is listed and the exit is non-zero (it needs an exe label, config/symbols.slus.txt).
All-asm overlay splits leave splat-named refs unresolved where spimdisasm typed a target as data inside text
(e.g. `.L800EEB40_ovl00` inside `D_800EEB14_ovl00`) or as a func in another naming (`func_800EEB64` vs `D_`).
Names are `<prefix><8 hex vram>[_<seg>]`, so the address is exact; bytes only depend on it. Unparseable names are
left out (the link then fails loudly). Names and addresses only (G12).
"""
import os
import re
import subprocess
import sys

BU = "tools/bin/binutils/usr"
READELF = f"{BU}/bin/mipsel-linux-gnu-readelf"
if not os.path.exists(READELF):  # system binutils (bootstrap links as/ld/objcopy from PATH; readelf likewise)
    READELF = "mipsel-linux-gnu-readelf"
ENV = dict(os.environ, LD_LIBRARY_PATH=f"{BU}/lib/x86_64-linux-gnu")
ADDR = re.compile(r"^(?:\.L|L|D_|func_|jtbl_)([0-9A-F]{8})(?:_\w+)?$")
EXE_LO, EXE_HI = 0x80010000, 0x800EE970  # exe image + bss; ovl vram starts at EXE_HI
LINKER_SYM = re.compile(r"_[A-Z_]*(VRAM|START|END|SIZE)$")  # splat segment-boundary symbols


def symbols(path):
    """-> [(value, size, type, bind, ndx, name)] from readelf -sW."""
    res = subprocess.run([READELF, "-sW", path], capture_output=True, text=True, check=True, env=ENV)
    out = []
    for line in res.stdout.splitlines():
        p = line.split()  # Num: Value Size Type Bind Vis Ndx Name
        if len(p) == 8 and p[0].endswith(":") and p[0] != "Num:":
            out.append((int(p[1], 16), p[2], p[3], p[4], p[6], p[7]))
    return out


def exe_syms(elf, out):
    """One name per exe-range address: FUNC/OBJECT before NOTYPE, splat boundary symbols last; no ABS, no `.L`
    (gas-local), no `*.NON_MATCHING`. The .ld twin works around bfd: MIPS ELF32 --just-symbols values are
    sign-extended (0xFFFFFFFF8...), so every R_MIPS_26 to one fails "relocation truncated to fit" (bits are right);
    a script assignment of the same name overrides it with the zero-extended value. Region bases ovl<X>_VRAM (exe
    in-section, at/after the exe's end; rockx5 places its segments there) go to the .ld only, not to splat (T4.1)."""
    best, region = {}, {}
    for v, _, t, b, x, n in symbols(elf):
        if b == "GLOBAL" and x not in ("UND", "ABS") and re.fullmatch(r"ovl[A-Z]_VRAM", n):
            region[n] = v
        if b != "GLOBAL" or x in ("UND", "ABS") or not EXE_LO <= v < EXE_HI:
            continue
        if n.startswith(".L") or n.endswith(".NON_MATCHING"):
            continue
        rank = (t not in ("FUNC", "OBJECT"), bool(LINKER_SYM.search(n)))
        if v not in best or rank < best[v][0]:
            best[v] = (rank, n, t)
    open(out, "w", encoding="utf-8").write("".join(
        f"{n} = 0x{v:08X}; // absolute:True" + (" type:func" if t == "FUNC" else "") + "\n"  # no rockx5 segment holds it
        for v, (_, n, t) in sorted(best.items())))
    open(os.path.splitext(out)[0] + ".ld", "w", encoding="utf-8").write(
        "".join(f"{n} = 0x{v:08X};\n" for v, (_, n, _) in sorted(best.items()))
        + "".join(f"{n} = 0x{v:08X};\n" for n, v in sorted(region.items())))


def main():
    args = sys.argv[1:]
    if args[0] == "exe-syms":
        return exe_syms(args[1], args[2])
    just = None
    if args[0] == "--just-symbols":
        just, args = args[1], args[2:]
    out, objs = args[0], args[1:]
    undef, defined = set(), set()
    for o in objs:
        for _, _, _, b, x, n in symbols(o):
            if x == "UND":
                undef.add(n)
            elif b in ("GLOBAL", "WEAK"):
                defined.add(n)
    if just:
        defined |= {n for _, _, _, b, x, n in symbols(just) if x != "UND" and b in ("GLOBAL", "WEAK")}
    lines, exe = [], []
    for name in sorted(undef - defined):
        m = ADDR.match(name)
        if m:
            lines.append(f"{name} = 0x{m.group(1)};\n")
            if just and EXE_LO <= int(m.group(1), 16) < EXE_HI:
                exe.append(name)
    open(out, "w", encoding="utf-8").write("".join(lines))
    for name in exe:
        print(f"undef_by_name: exe-range name not in {just}: {name}", file=sys.stderr)
    if exe:
        sys.exit(f"undef_by_name: {len(exe)} exe-range undefined names (label them in config/symbols.slus.txt)")


if __name__ == "__main__":
    main()
