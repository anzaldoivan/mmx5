#!/usr/bin/env python3
"""ovl_syms.py — shifted exe link, pass 2 (T8): exe->ovl names at the shifted rockx5's addresses.

  gen   --pinned config/shift/ovl_syms.ld --map <rockx5 .map> --out <ld>
        copy of the pinned script (header lines verbatim), every `NAME = 0x...;` value = NAME's address in the map;
        exit 1 naming any pinned name the map lacks
  check --pass1 <exe elf> --pass2 <exe elf> --map <rockx5 .map> --pinned <ld>
        (a) every exe symbol not pinned has the same address in pass 1 and 2; (b) ovlA/B_VRAM unchanged;
        (c) every pinned name's pass-2 exe value == its map value. One OK line, or the diffs and exit 1.
Names and addresses only (G12). Symbols via tools/build/undef_by_name.py (readelf).
"""
import argparse, re, sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "build"))
from undef_by_name import symbols  # noqa: E402

PIN = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*) = 0x[0-9A-Fa-f]+;$")
MAP = re.compile(r"^\s+0x([0-9a-f]+)\s+([A-Za-z_][A-Za-z0-9_]*)(?:$| = )")
REGIONS = ("ovlA_VRAM", "ovlB_VRAM")


def pinned(path):
    lines = Path(path).read_text(encoding="utf-8").splitlines()
    return lines, [m.group(1) for m in map(PIN.match, lines) if m]


def map_syms(path, names):
    want, out = set(names), {}
    for line in Path(path).read_text(encoding="utf-8", errors="replace").splitlines():
        m = MAP.match(line)
        if m and m.group(2) in want:
            v = int(m.group(1), 16)
            if out.setdefault(m.group(2), v) != v:
                sys.exit(f"ovl_syms: {m.group(2)} has two addresses in {path}")
    missing = sorted(want - set(out))
    if missing:
        sys.exit(f"ovl_syms: {len(missing)} pinned names not in {path}: {' '.join(missing[:20])}")
    return out


def gen(a):
    lines, names = pinned(a.pinned)
    addr = map_syms(a.map, names)
    out = [f"{m.group(1)} = 0x{addr[m.group(1)]:08X};" if (m := PIN.match(l)) else l for l in lines]
    got = [m.group(1) for m in map(PIN.match, out) if m]
    if Counter(got) != Counter(names):
        sys.exit(f"ovl_syms: name set differs: missing {set(names) - set(got)}, extra {set(got) - set(names)}")
    Path(a.out).write_text("\n".join(out) + "\n", encoding="utf-8")
    print(f"ovl_syms: gen {len(names)} names -> {a.out}")


def check(a):
    _, names = pinned(a.pinned)
    pin = set(names)
    addr = map_syms(a.map, names)
    s1, s2 = symbols(a.pass1), symbols(a.pass2)
    c1 = Counter((n, v) for v, *_, n in s1 if n not in pin)
    c2 = Counter((n, v) for v, *_, n in s2 if n not in pin)
    errs = [f"(a) pass1 only: {n} 0x{v:08X}" for n, v in sorted(c1 - c2)]
    errs += [f"(a) pass2 only: {n} 0x{v:08X}" for n, v in sorted(c2 - c1)]
    r1 = {n: v for v, *_, n in s1 if n in REGIONS}
    r2 = {n: v for v, *_, n in s2 if n in REGIONS}
    errs += [f"(b) {n} pass1 {r1.get(n)} pass2 {r2.get(n)}" for n in REGIONS if n not in r1 or r1.get(n) != r2.get(n)]
    v2 = {}
    for v, *_, n in s2:
        if n in pin:
            v2.setdefault(n, set()).add(v)
    errs += [f"(c) {n}: exe {sorted(map(hex, v2.get(n, ())))} map 0x{addr[n]:08X}"
             for n in names if v2.get(n) != {addr[n]}]
    if errs:
        print("\n".join(errs[:40]) + (f"\n... {len(errs)} diffs" if len(errs) > 40 else ""))
        sys.exit(1)
    print(f"ovl_syms: check OK ({len(names)} pinned at map values; {sum(c2.values())} other exe symbols unchanged; "
          + ", ".join(f"{n} 0x{r2[n]:08X}" for n in REGIONS) + ")")


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest="cmd", required=True)
    g = sub.add_parser("gen")
    g.add_argument("--pinned", required=True); g.add_argument("--map", required=True); g.add_argument("--out", required=True)
    c = sub.add_parser("check")
    for f in ("--pass1", "--pass2", "--map", "--pinned"):
        c.add_argument(f, required=True)
    a = p.parse_args()
    (gen if a.cmd == "gen" else check)(a)


if __name__ == "__main__":
    main()
