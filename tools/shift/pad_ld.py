#!/usr/bin/env python3
"""pad_ld.py — splat ld script -> shifted-build ld script (`make ... SHIFT=1`, tools/shift/README.md).

usage: pad_ld.py <alias> <in.ld> <out.ld> [--pad N] [--objdir DIR]
Every object path build/<alias>/ -> DIR/ (default build/shift/<alias>; shifted objects never share build/<alias>/).
rockx5 only: `. += N` before each code overlay's RODATA, TEXT, DATA (never data overlays 13/15/17/19, pad/toc), and
after every overlay `ASSERT(ovlNN_VRAM_END <= bound)`, bound from config/shift/regions.txt (A.lo overrides A; B).
slus only: .main reordered TEXT, DATA (minus the zero tail 82430.data.o), RODATA, `. += N` before each block;
ASSERT the three end at or below the pinned tail 0x80091C30 (_gp), advance there, the tail, ASSERT <= 0x80092000;
`. = 0x80092000` before .main_bss. The tail is bss-like (docs/memory-map.md), so it stays with bss. Every
other address moves; with N = 0 the image size is unchanged (free fill is 0, so any N > 0 fails the ASSERT).
Inside an output section `.` is a section offset (ABSOLUTE(.) and ADDR(.main) fail there): targets are vram - 0x80010000.
"""
import argparse
import re

TAIL_OBJ = "/data/82430.data.o("  # config/splat.slus.yaml [0x82430, data, 82430]
MAIN_VRAM, TAIL_VRAM, BSS_VRAM = 0x80010000, 0x80091C30, 0x80092000
DATA_OVLS = {13, 15, 17, 19}  # data-only overlays (config/splat.rockx5.yaml)
REGIONS = "config/shift/regions.txt"


def block(lines, start, end):
    """lines from the one holding `start` up to (excluding) the one holding `end`."""
    i = next(k for k, s in enumerate(lines) if start in s)
    j = next(k for k, s in enumerate(lines) if end in s)
    return i, j


def reorder(lines, pad):
    r0, t0 = block(lines, "main_RODATA_START = .;", "main_TEXT_START = .;")
    _, d0 = block(lines, "main_TEXT_START = .;", "main_DATA_START = .;")
    d1 = next(k for k, s in enumerate(lines) if "main_DATA_SIZE" in s) + 1
    assert f".main 0x{MAIN_VRAM:08X} :" in "".join(lines[:r0]), "pad_ld: .main vram moved"
    rodata, text, data = lines[r0:t0], lines[t0:d0], lines[d0:d1]
    tail = [s for s in data if TAIL_OBJ in s]
    assert len(tail) == 1, f"pad_ld: want one {TAIL_OBJ} in .main DATA, found {len(tail)}"
    data = [s for s in data if TAIL_OBJ not in s]
    ind = " " * 8
    step = [f"{ind}. += 0x{pad:X}; /* SHIFT_PAD */\n"]
    # MAX: an overrun reaches the ASSERT instead of ld's "cannot move location counter backwards"
    mid = step + text + step + data + step + rodata + [
        f'{ind}ASSERT(. <= 0x{TAIL_VRAM - MAIN_VRAM:X}, "SHIFT_PAD: .main overruns the pinned tail 0x{TAIL_VRAM:08X}");\n',
        f"{ind}. = MAX(., 0x{TAIL_VRAM - MAIN_VRAM:X});\n"] + tail + [
        f'{ind}ASSERT(. <= 0x{BSS_VRAM - MAIN_VRAM:X}, "SHIFT_PAD: tail overruns bss 0x{BSS_VRAM:08X}");\n']
    out = lines[:r0] + mid + lines[d1:]
    b = next(k for k, s in enumerate(out) if "main_bss_VRAM = ADDR(.main_bss);" in s)
    return out[:b] + [f"    . = 0x{BSS_VRAM:08X};\n"] + out[b:]


def bounds(path=REGIONS):
    """{ovl index: bound} from regions.txt rows A, B, then A.lo (overrides A)."""
    rows = {}
    for s in open(path, encoding="utf-8"):
        m = re.match(r"(\S+) .*members=(\S+) .*bound=([0-9A-Fa-f]+)", s)
        if m and not s.startswith("#"):
            rows[m[1]] = m[2], int(m[3], 16)
    out = {}
    for name in ("A", "B", "A.lo"):
        members, bound = rows[name]
        for part in members.replace("ovl", "").split(","):
            lo, _, hi = part.partition("-")
            out.update((k, bound) for k in range(int(lo), int(hi or lo) + 1))
    assert sorted(out) == list(range(59)), "pad_ld: regions.txt does not cover ovl00-58"
    return out


def pad_ovls(lines, pad):
    bound = bounds()
    out = []
    for s in lines:
        m = re.match(r"\s*ovl(\d\d)_(RODATA|TEXT|DATA)_START = \.;", s)
        if m and int(m[1]) not in DATA_OVLS:
            out.append(f"        . += 0x{pad:X}; /* SHIFT_OVL_PAD */\n")
        out.append(s)
        m = re.match(r"\s*ovl(\d\d)_VRAM_END = \.;", s)
        if m:
            b = bound[int(m[1])]
            # no `;`: a SECTIONS-level ASSERT with one is a syntax error in this ld
            out.append(f'    ASSERT(ovl{m[1]}_VRAM_END <= 0x{b:08X}, "region bound: ovl{m[1]} overruns {b:08X}")\n')
    assert sum("ASSERT(ovl" in s for s in out) == 59, "pad_ld: want 59 overlay ASSERTs"
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("alias")
    ap.add_argument("src")
    ap.add_argument("dst")
    ap.add_argument("--pad", type=lambda s: int(s, 0), default=0)
    ap.add_argument("--objdir")
    a = ap.parse_args()
    objdir = (a.objdir or f"build/shift/{a.alias}").rstrip("/") + "/"
    lines = [s.replace(f"build/{a.alias}/", objdir)
             for s in open(a.src, encoding="utf-8").readlines()]
    if a.alias == "slus":
        lines = reorder(lines, a.pad)
    elif a.alias == "rockx5":
        lines = pad_ovls(lines, a.pad)
    open(a.dst, "w", encoding="utf-8").writelines(lines)


if __name__ == "__main__":
    main()
