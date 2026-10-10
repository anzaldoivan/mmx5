#!/usr/bin/env python3
"""Write an ld script defining every symbol the objects reference but nothing defines, at the vram in its name.

usage: undef_by_name.py <out.ld> <obj>...   (readelf from tools/bin/binutils; nm hides `.L` names)
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


def main():
    out, objs = sys.argv[1], sys.argv[2:]
    undef, defined = set(), set()
    for o in objs:
        res = subprocess.run([READELF, "-sW", o], capture_output=True, text=True, check=True, env=ENV)
        for line in res.stdout.splitlines():
            p = line.split()  # Num: Value Size Type Bind Vis Ndx Name
            if len(p) != 8 or not p[0].endswith(":"):
                continue
            if p[6] == "UND":
                undef.add(p[7])
            elif p[4] in ("GLOBAL", "WEAK"):
                defined.add(p[7])
    lines = []
    for name in sorted(undef - defined):
        m = ADDR.match(name)
        if m:
            lines.append(f"{name} = 0x{m.group(1)};\n")
    open(out, "w", encoding="utf-8").write("".join(lines))


if __name__ == "__main__":
    main()
