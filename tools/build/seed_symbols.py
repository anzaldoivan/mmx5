#!/usr/bin/env python3
"""Seed config/symbols.<alias>.txt (splat symbol_addrs format) from docs/oracle/annotations.jsonl.

Exe rows only: addr without `::`, kind function|label, LO <= addr < HI. Sorted by addr; a name
already taken gets `_<ADDR>` appended (deterministic); one symbol per addr (function wins). A label inside a
docs/oracle/segments.txt text range gets `// type:label` (an in-function label, not a glabel split; 1.5/T2).
A function inside a libobj text range whose bytes say it is no start (no jal target and not after `jr`+delay [+ zero
words] or zero padding, or a jump-table case target; boundaries.py tests over the expected exe) also gets
`// type:label`: psyq `<OBJ>_OBJ_<off>` in-function labels and crt0 fall-through (T2.1). EXTRA: game functions with no annotation row (jal'd, prologue; T2.1).
A name inside a config yaml `textbin` subsegment, not at its start, is untyped (splat defines it via
undefined_syms_auto; T2.1.c5).
Names and addresses only: no game bytes (G12).
"""
import argparse
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "census"))
import boundaries  # noqa: E402  (stdlib only, no spimdisasm)

LO, HI = 0x80010000, 0x80092000
IDENT = re.compile(r"^[A-Za-z_.$][A-Za-z0-9_.$]*$")
EXTRA = {0x80011FD4: "func_80011FD4", 0x80013288: "func_80013288"}  # inside main / func_8001303C (T2.1)


def start_ok(exe, v):
    """boundaries.boundary at v or after the zero words before it (a terminator's delay slot, then alignment nops)."""
    while not boundaries.boundary(exe, v):
        if exe.word(v - 4) != 0:
            return False
        v -= 4
    return True


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--src", default="docs/oracle/annotations.jsonl")
    ap.add_argument("--out", default="config/symbols.slus.txt")
    ap.add_argument("--segments", default="docs/oracle/segments.txt")
    ap.add_argument("--yaml", default="config/splat.slus.yaml")
    a = ap.parse_args()
    rows = [(p[2], tuple(int(x, 16) for x in p[3].split("-"))) for p in (ln.split() for ln in open(a.segments))
            if len(p) > 3 and p[0] == "slus"]
    text = [r for _, r in rows]
    lib = [r for k, r in rows if k == "libobj"]
    # textbin subsegments (main: rom 0x800 = LO) emit only their start symbol; an interior name stays untyped so splat
    # puts it in undefined_syms_auto (a type:label there would be left undefined at link)
    subs = [(int(o, 16), k) for o, k in re.findall(r"^ {6}- \[0x([0-9A-Fa-f]+), (\w+)", open(a.yaml).read(), re.M)]
    tbin = [(o - 0x800 + LO, subs[i + 1][0] - 0x800 + LO) for i, (o, k) in enumerate(subs[:-1]) if k == "textbin"]
    exe = boundaries.Module("slus", "exe", LO, open(boundaries.EXE, "rb").read()[0x800:], text)
    tabs, words = boundaries.find_tables(exe)
    cases = {t for ts in tabs.values() for t in ts}
    starts = boundaries.strong_starts(exe, None, words)[0]  # jal targets; ptr/lui only at a boundary
    by_addr = {v: (n, "function") for v, n in EXTRA.items()}
    for line in open(a.src, encoding="utf-8"):
        r = json.loads(line)
        addr = r.get("addr", "")
        if not addr or "::" in addr or r.get("kind") not in ("function", "label"):
            continue
        v = int(addr, 16)
        if not (LO <= v < HI) or not IDENT.match(r["name"]):
            continue
        prev = by_addr.get(v)
        if prev is None or (prev[1] != "function" and r["kind"] == "function"):
            by_addr[v] = (r["name"], r["kind"])
    used, out = set(), []
    for v in sorted(by_addr):
        name, kind = by_addr[v]
        if name in used:
            name = f"{name}_{v:08X}"
        used.add(name)
        lab = kind == "label" and any(s <= v < e for s, e in text)
        if kind == "function" and any(s <= v < e for s, e in lib) \
                and (v in cases or not (v in starts or start_ok(exe, v))):
            kind, lab = "label", True
        tag = " // type:func" if kind == "function" else " // type:label" if lab else ""
        if any(s < v < e for s, e in tbin):
            tag = ""
        out.append(f"{name} = 0x{v:08X};{tag}")
    with open(a.out, "w", encoding="utf-8", newline="\n") as f:
        f.write("\n".join(out) + "\n")
    print(f"seed_symbols: {len(out)} symbols -> {a.out}")


if __name__ == "__main__":
    main()
