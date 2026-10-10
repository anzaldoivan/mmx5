#!/usr/bin/env python3
"""Overlay header and data-tail splits for config/splat.rockx5.yaml, derived from bytes + docs/oracle/loadmap.json.

usage: rockx5_splits.py --write | --check
  --write  rewrites the generated subsegment lines (marked `# gen:rockx5_splits`) in config/splat.rockx5.yaml
  --check  exit 0 if the yaml already carries exactly the generated lines, 1 on drift, 2 refused input
Per code overlay (loadmap kind code, non-null dest), bytes of extracted/retail/ROCK_X5.BIN:
  header: word 0 is a small id (< 0x100), then a run of data words (pointer into the overlay or exe text, zero,
    R3000-invalid encoding) trimmed to its last overlay pointer; split when the next word is not data:
    `[start, textbin]` + `[code, asm]`.
  tail: everything after the last `jr ra` + delay slot, when it holds no `addiu sp,sp,-N` and no jal target:
    `[tail, textbin]` (pointer tables / structs spimdisasm otherwise glabels as functions).
Hand lines (unmarked) are kept (ovl05's header was one: word 9 decodes as `jalr $zero,$zero`, gas rejects it); a hand line inside a generated range is refused, except carve.py's `# carve` lines (an owned-rodata split
of the header; one at the header start stands in for the generated line). Offsets only (G12).
No spimdisasm: words are classified here (boundaries.invalid for SPECIAL).
"""
import argparse
import json
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools/census"))
from boundaries import invalid, h  # noqa: E402

YAML = ROOT / "config/splat.rockx5.yaml"
BIN = ROOT / "extracted/retail/ROCK_X5.BIN"
LOADMAP = ROOT / "docs/oracle/loadmap.json"
MARK = "  # gen:rockx5_splits"
SUB = re.compile(r"^      - \[0x([0-9A-F]+), ([.\w]+)(.*?)\](.*)$")
BAD_OP = {*range(0x14, 0x20), 0x27, 0x2C, 0x2D, 0x2F, *range(0x34, 0x38), *range(0x3C, 0x40)}  # undefined on R3000


def splits(blob, lm):
    """{overlay index: (bin_offset, header code vram or None, tail vram or None, vram)}."""
    ta, ts = h(lm["exe"]["t_addr"]), h(lm["exe"]["t_size"])
    out = {}
    for o in lm["overlays"]:
        if o.get("kind") != "code" or not o.get("dest"):
            continue
        off, size, v = h(o["bin_offset"]), h(o["size"]), h(o["dest"])
        n = size // 4
        ws = struct.unpack_from(f"<{n}I", blob, off)

        def ptr(w):
            return v <= w < v + size

        def data(w):
            op = w >> 26
            return (ptr(w) or ta <= w < ta + ts or w == 0 or invalid(w) or op in BAD_OP
                    or (op == 1 and (w >> 16) & 31 not in (0, 1, 16, 17)))

        hdr = None
        if ws[0] < 0x100:
            i, last = 1, 0
            while i < n and data(ws[i]):
                last = i if ptr(ws[i]) else last
                i += 1
            if not data(ws[last + 1]):
                hdr = v + 4 * (last + 1)
        jr = [i for i, w in enumerate(ws) if w == 0x03E00008]
        t = jr[-1] + 2 if jr else n
        tail = None
        if t < n:
            tv = v + 4 * t
            pro = any(w >> 16 == 0x27BD and w & 0x8000 for w in ws[t:])
            jal = any(w >> 26 == 3 and tv <= ((v & 0xF0000000) | (w & 0x3FFFFFF) << 2) < v + size for w in ws[:t])
            tail = None if pro or jal else tv
        out[o["index"]] = (off, hdr, tail, v)
    return out


def render(text, sp):
    lines, out, seg, i = text.splitlines(keepends=True), [], None, 0
    while i < len(lines):
        ln = lines[i]
        m = re.match(r"^  - name: ovl(\d\d)$", ln.rstrip("\n"))
        if m:
            seg = sp.get(int(m.group(1)))
        if seg is None or ln.rstrip("\n") != "    subsegments:":
            out.append(ln)
            i += 1
            continue
        out.append(ln)
        i += 1
        subs = []
        while i < len(lines) and SUB.match(lines[i].rstrip("\n")):
            if MARK not in lines[i] or "  # carve" in lines[i]:  # carve.py lines (and their `was:` undo) are hand
                subs.append((int(SUB.match(lines[i]).group(1), 16), lines[i]))
            i += 1
        off, hdr, tail, v = seg
        if not any(o == off for o, _ in subs):
            subs.append((off, f"      - [0x{off:X}, asm]\n"))
        gen = []
        if hdr:
            subs = [s for s in subs if not (s[0] == off and SUB.match(s[1]).group(2) == "asm")]  # incl. named TU head
            if not any(o == off for o, _ in subs):  # a carve line replaced the header line
                gen.append((off, f"      - [0x{off:X}, textbin]{MARK}\n"))
            if not any(o == off + hdr - v for o, _ in subs):  # a hand TU line at the code start stays
                gen.append((off + hdr - v, f"      - [0x{off + hdr - v:X}, asm]{MARK}\n"))
        if tail:
            gen.append((off + tail - v, f"      - [0x{off + tail - v:X}, textbin]{MARK}\n"))
        lo, hi = off + (hdr - v if hdr else 0), off + (tail - v if tail else 1 << 32)
        for o, s in subs:
            if "  # carve" in s:
                continue
            if (hdr and off <= o < lo) or (o >= hi and SUB.match(s).group(2) != "bin"):
                sys.exit(f"rockx5_splits: refused -- hand line inside a generated range: {s.strip()}")
        out += [s for _, s in sorted(subs + gen, key=lambda x: x[0])]
        seg = None
    return "".join(out)


def main():
    ap = argparse.ArgumentParser()
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--write", action="store_true")
    g.add_argument("--check", action="store_true")
    a = ap.parse_args()
    for p in (YAML, BIN, LOADMAP):
        if not p.exists():
            print(f"rockx5_splits: refused -- missing {p.relative_to(ROOT)}")
            return 2
    sp = splits(BIN.read_bytes(), json.loads(LOADMAP.read_text()))
    old = YAML.read_text()
    new = render(old, sp)
    nh, nt = sum(1 for s in sp.values() if s[1]), sum(1 for s in sp.values() if s[2])
    if a.check:
        ok = new == old
        print(f"rockx5_splits: {'OK' if ok else 'DRIFT'} ({nh} headers, {nt} tails)")
        return 0 if ok else 1
    YAML.write_text(new)
    print(f"rockx5_splits: wrote {nh} headers, {nt} tails")
    return 0


if __name__ == "__main__":
    sys.exit(main())
