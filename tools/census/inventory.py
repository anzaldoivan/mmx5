#!/usr/bin/env python3
"""Function inventory (the corpus oracle): one row per function of the fleet.

  inventory.py [--alias A] [--selftest]

Aliases = config/splat.<a>.yaml. Functions = `glabel`s in `.text` sections of asm/<a>/**/*.s (status asm) plus the
yaml `c` subsegments (status c, extent from the linker map .text section). Text bytes (the over-approximating set) =
map .text sections + docs/oracle/segments.txt text ranges. Each text byte is classed by precedence
rodata (segments.txt rodata range, `dlabel` words, non-asm text subsegments e.g. textbin, words after a function's
last jr/j (+ delay) or break when its tail is `invalid instruction` words) > function > padding
(unlabelled zero word) > uncovered. Writes .run/census/inventory.jsonl rows
{"alias","module","kind","name","vram","insns","status"} keyed (alias, module, vram). Exit 0 green, 1 fail
(uncovered text bytes, map/asm function mismatch, c control), 2 refused input (missing asm/ or map).
Stdlib only; never imports spimdisasm/splat (independence of the second oracle). Counts/addresses/names only (G12).
"""
import argparse
import json
import re
import shutil
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
FIXTURE = ROOT / "tools/census/fixtures/ok"
SEG = re.compile(r"^  - name: (\w+)")
SEG_FLOW = re.compile(r"^  - \{name: (\w+), type: (\w+), start: (0x[0-9A-Fa-f]+)")
SEG_END = re.compile(r"^  - \[(0x[0-9A-Fa-f]+)\]")
KEY = re.compile(r"^    (type|start|vram): (\S+)")
SUB = re.compile(r"^      - \[(0x[0-9A-Fa-f]+), (\w+)(?:, ([\w.]+))?\]")
OPT = re.compile(r"^  (basename|build_path|asm_path): (\S+)")
ITEM = re.compile(r"^\s*/\* [0-9A-F]+ ([0-9A-F]{8})(?: ([0-9A-F]+))? \*/\s+(\S+)")
MAPSEC = re.compile(r"^ \.text\s+0x([0-9a-f]+)\s+0x([0-9a-f]+) (\S+)\.o$")
MAPSYM = re.compile(r"^\s+0x([0-9a-f]+)\s+([A-Za-z_.$][\w.$]*)\s*$")
SIZE = {".short": 2, ".half": 2, ".byte": 1}
TEXT, FN, RO, PAD = 1, 2, 3, 4  # byte classes; 0 = not text


def stem(p):
    return Path(p).name.split(".")[0]


def parse_yaml(path):
    opts, segs, cur = {}, [], None
    for line in path.read_text().splitlines():
        line = line.split("  #")[0].rstrip()
        if m := OPT.match(line):
            opts[m.group(1)] = m.group(2)
        elif m := SEG.match(line):
            cur = {"name": m.group(1), "type": None, "start": None, "vram": None, "subs": []}
            segs.append(cur)
        elif m := SEG_FLOW.match(line):
            cur = {"name": m.group(1), "type": m.group(2), "start": int(m.group(3), 16), "vram": None, "subs": []}
            segs.append(cur)
        elif m := SEG_END.match(line):
            segs.append({"name": None, "type": "end", "start": int(m.group(1), 16), "vram": None, "subs": []})
            cur = None
        elif cur and (m := KEY.match(line)):
            cur[m.group(1)] = m.group(2) if m.group(1) == "type" else int(m.group(2), 16)
        elif cur and (m := SUB.match(line)):
            cur["subs"].append((int(m.group(1), 16), m.group(2), m.group(3) or "%X" % int(m.group(1), 16)))
    for a, b in zip(segs, segs[1:]):
        a["size"] = b["start"] - a["start"]
    code = {s["name"]: s for s in segs if s["type"] == "code"}
    stems = {sub[2]: (s["name"], sub[1]) for s in code.values() for sub in s["subs"]}
    return opts, segs, code, stems


def parse_map(path):
    """[(stem, vram, size, [(addr, name)])] for every non-empty .text input section."""
    secs, cur = [], None
    for line in path.read_text().splitlines():
        if m := MAPSEC.match(line):
            cur = None
            if int(m.group(2), 16):
                cur = (stem(m.group(3)), int(m.group(1), 16), int(m.group(2), 16), [])
                secs.append(cur)
        elif cur and (m := MAPSYM.match(line)):
            cur[3].append((int(m.group(1), 16), m.group(2).removesuffix(".NON_MATCHING")))
        elif re.match(r"^ ?\S", line):
            cur = None
    return secs


def parse_segments(path, alias):
    rows = []  # (tu, kind, seg_or_None, start, end, [(seg_or_None, s, e)])
    def rng(t):
        seg, _, r = t.rpartition(":")
        s, e = r.split("-")
        return seg or None, int(s, 16), int(e, 16)
    for line in path.read_text().splitlines():
        p = line.split()
        if line.startswith("#") or len(p) < 4 or p[0] != alias:
            continue
        seg, s, e = rng(p[3])
        ro = [rng(t) for t in p[5].split(",")] if len(p) > 5 and p[4] == "rodata" else []
        rows.append((p[1], "game" if p[2] == "overlay" else p[2], seg, s, e, ro))
    return rows


def excluded(root, segs):
    lm = root / "docs/oracle/loadmap.json"
    if not lm.exists():
        return []
    by_start = {s["start"]: s for s in segs if s["name"]}
    out = []
    for o in json.loads(lm.read_text()).get("overlays", []):
        off = o["bin_offset"] if isinstance(o["bin_offset"], int) else int(o["bin_offset"], 16)
        s = by_start.get(off)
        why = "null dest" if not o.get("dest") else "data overlay" if o.get("kind") == "data" else None
        if s and why and s["type"] != "code":
            out.append((s["name"], why))
    return out


def run(root, aliases, outfile, classes=None):
    """returns (exit code, rows, c_count, c_expected); classes (dict) receives {alias: (code segs, byte-class arrays)}."""
    rc, all_rows, c_got, c_want = 0, [], 0, 0
    for alias in aliases:
        opts, segs, code, stems = parse_yaml(root / f"config/splat.{alias}.yaml")
        mpath = root / opts.get("build_path", f"build/{alias}") / f"{opts.get('basename', alias)}.map"
        adir = root / opts.get("asm_path", f"asm/{alias}")
        if not mpath.exists() or not adir.is_dir():
            print(f"inventory: refused -- missing {mpath if not mpath.exists() else adir} (run make check)")
            return 2, [], 0, 0
        single = next(iter(code)) if len(code) == 1 else None
        arr = {n: bytearray(s["size"]) for n, s in code.items()}
        msyms, textsec = set(), {}
        for st, vram, size, syms in parse_map(mpath):
            if st not in stems:
                print(f"inventory: {alias} map .text {st} not in yaml")
                rc = 1
                continue
            seg = stems[st][0]
            off = vram - code[seg]["vram"]
            arr[seg][off:off + size] = bytes([TEXT]) * size
            textsec[st] = (vram, size)
            msyms |= {(seg, a) for a, _ in syms}
        rows = parse_segments(root / "docs/oracle/segments.txt", alias)
        for tu, kind, seg, s, e, _ in rows:
            seg = seg or single
            b = code[seg]["vram"]
            for i in range(s - b, e - b):
                arr[seg][i] = arr[seg][i] or TEXT

        def module(seg, vram):
            mine = [r for r in rows if (r[2] or single) == seg]
            hit = [r for r in mine if r[3] <= vram < r[4]] or (mine if len(mine) == 1 else [])
            return (hit[0][0], hit[0][1]) if hit else (None, None)

        fns = []
        for path in sorted(adir.rglob("*.s")):
            if "include" in path.relative_to(adir).parts or stem(path) not in stems:
                continue
            seg, subtype = stems[stem(path)]
            b, a = code[seg]["vram"], arr[seg]
            if subtype != "asm":  # textbin etc.: classed by yaml extent below
                continue
            text, cur = False, None
            for line in path.read_text().splitlines():
                s = line.strip()
                if s.startswith(".section"):
                    text, cur = s.split()[1].rstrip(",") == ".text", None
                elif not text:
                    continue
                elif s.startswith("glabel "):
                    cur = {"seg": seg, "name": s.split()[1], "vram": None, "items": []}
                    fns.append(cur)
                elif s.startswith("dlabel "):
                    cur = "data"
                elif s.startswith(("endlabel", "enddlabel")):
                    cur = None
                elif m := ITEM.match(line):
                    vram, size = int(m.group(1), 16), SIZE.get(m.group(3), 4)
                    o = vram - b
                    if not 0 <= o <= len(a) - size:
                        print(f"inventory: {alias} {path.name} {vram:08X} outside segment {seg}")
                        rc = 1
                        continue
                    if cur == "data":
                        a[o:o + size] = bytes([RO]) * size
                    elif cur:
                        cur["vram"] = cur["vram"] if cur["vram"] is not None else vram
                        w = int.from_bytes(bytes.fromhex(m.group(2) or ""), "little") if size == 4 else None
                        cur["items"].append((o, size, w, "invalid instruction" in line))
                        a[o:o + size] = bytes([FN]) * size
                    elif m.group(2) and int(m.group(2), 16) == 0:
                        a[o:o + size] = bytes([PAD]) * size
        for fn in fns:  # trailing `invalid instruction` words after the last terminator -> rodata (data in text)
            it, a, n = fn["items"], arr[fn["seg"]], len(fn["items"])
            while n and it[n - 1][3]:
                n -= 1
            for k in range(n - 1 if n < len(it) else -1, -1, -1):
                w = it[k][2]
                if w is not None and (w >> 26 == 2 or (w >> 26 == 0 and w & 0x3F in (8, 13))):  # j, jr, break
                    for o, sz, *_ in it[k + 1 + (w >> 26 == 2 or w & 0x3F == 8):]:  # jr/j keep the delay slot
                        a[o:o + sz] = bytes([RO]) * sz
                    break
        for seg, sg in code.items():  # non-code subsegments (bin, textbin, rodata, data) inside text -> rodata
            ends = [x[0] for x in sg["subs"][1:]] + [sg["start"] + sg["size"]]
            for (off, t, _), end in zip(sg["subs"], ends):
                if t not in ("asm", "c"):
                    a = arr[seg]
                    for i in range(off - sg["start"], end - sg["start"]):
                        if a[i]:
                            a[i] = RO
        for tu, kind, seg, s, e, ro in rows:
            for rseg, rs, re_ in ro:
                rseg = rseg or single
                b, a = code[rseg]["vram"], arr[rseg]
                for i in range(rs - b, re_ - b):
                    if a[i]:
                        a[i] = RO
        if classes is not None:
            classes[alias] = (code, arr)
        out = []
        for fn in fns:
            if fn["vram"] is None:
                continue
            insns = sum(1 for o, sz, *_ in fn["items"] if sz == 4 and arr[fn["seg"]][o] == FN)
            out.append((fn["seg"], fn["vram"], fn["name"], insns, "asm"))
        for seg, s in code.items():
            for off, t, name in s["subs"]:
                if t != "c":
                    continue
                c_want += 1
                if name not in textsec:
                    print(f"inventory: {alias} c subsegment {name} has no map .text section")
                    rc = 1
                    continue
                vram, size = textsec[name]
                arr[seg][vram - s["vram"]:vram - s["vram"] + size] = bytes([FN]) * size
                out.append((seg, vram, name, size // 4, "c"))
        n_rows = []
        for seg, vram, name, insns, status in out:
            mod, kind = module(seg, vram)
            if mod is None:
                print(f"inventory: {alias} {name} {seg}:{vram:08X} in no segments.txt module")
                rc = 1
            n_rows.append({"alias": alias, "module": mod, "kind": kind, "name": name, "vram": f"{vram:08X}",
                           "insns": insns, "status": status})
            c_got += status == "c"
        # map denominator: linked .text symbol starts, less data (rodata class) and in-function labels (jlabel)
        fkeys = {(seg, vram) for seg, vram, *_ in out}
        m_keys = {k for k in msyms if arr[k[0]][k[1] - code[k[0]]["vram"]] not in (RO, FN)} | fkeys
        for seg, vram in sorted(m_keys - fkeys)[:20]:
            print(f"inventory: {alias} map symbol {seg}:{vram:08X} has no inventory row")
        if m_keys - fkeys:
            rc = 1
        # byte accounting per module
        tot = defaultdict(lambda: [0, 0, 0, 0, 0])  # text, fn, ro, pad, uncovered
        unc = []
        for seg, a in arr.items():
            b, run_start = code[seg]["vram"], None
            for i, c in enumerate(a):
                if c:
                    mod = module(seg, b + i)[0] or f"{alias}/{seg}?"
                    t = tot[mod]
                    t[0] += 1
                    t[{FN: 1, RO: 2, PAD: 3, TEXT: 4}[c]] += 1
                if c == TEXT and run_start is None:
                    run_start = i
                elif c != TEXT and run_start is not None:
                    unc.append((seg, b + run_start, b + i))
                    run_start = None
            if run_start is not None:
                unc.append((seg, b + run_start, b + len(a)))
        for seg, s, e in unc[:40]:
            print(f"uncovered: {alias} {module(seg, s)[0]} {seg}:{s:08X}-{e:08X} ({e - s} bytes)")
        for mod, (t, f, r, p, u) in sorted(tot.items()):
            if f + r + p != t:
                print(f"inventory: {alias} {mod} functions {f} + rodata {r} + padding {p} != text {t}")
                rc = 1
        T = [sum(v[i] for v in tot.values()) for i in range(5)]
        print(f"inventory: {len(n_rows)} of {len(m_keys)} functions [{alias}]")
        print(f"inventory: {T[1]} of {T[0]} text bytes [{alias}]")
        print(f"bytes: functions {T[1]} + rodata {T[2]} + padding {T[3]} + uncovered {T[4]} = {T[0]} [{alias}]")
        if T[4]:
            rc = 1
        for name, why in excluded(root, segs):
            print(f"excluded: {name} -- {why}")
        all_rows += sorted(n_rows, key=lambda r: (r["module"] or "", r["vram"], r["name"]))
    if outfile:
        outfile.parent.mkdir(parents=True, exist_ok=True)
        outfile.write_text("".join(json.dumps(r) + "\n" for r in all_rows))
    if c_got == c_want:
        print(f"inventory: control OK -- {c_got} of {c_want} c")
    else:
        print(f"inventory: control FAIL -- {c_got} of {c_want} c")
        rc = 1
    return rc, all_rows, c_got, c_want


def aliases_of(root):
    return sorted(p.name.split(".")[1] for p in (root / "config").glob("splat.*.yaml"))


def selftest():
    print("selftest: clean fixture")
    rc, rows, c, cw = run(FIXTURE, aliases_of(FIXTURE), None)
    ok = rc == 0 and len(rows) == 4 and c == cw == 1
    gap = ROOT / ".run/census/selftest"
    shutil.rmtree(gap, ignore_errors=True)
    shutil.copytree(FIXTURE, gap)
    s = gap / "asm/fx/ovl00_8010001C.s"
    s.write_text(s.read_text().replace("glabel func_8010001C_ovl00\n", ""))
    print("selftest: planted gap (one glabel removed; must fail)")
    rc2 = run(gap, aliases_of(gap), None)[0]
    ok = ok and rc2 == 1
    tw = ROOT / ".run/census/selftest_ro"  # synthetic: `break` then one invalid word -> 1 insn, 4 bytes rodata
    shutil.rmtree(tw, ignore_errors=True)
    shutil.copytree(FIXTURE, tw)
    (tw / "asm/fx/ovl02_80100000.s").write_text(
        '.section .text, "ax"\n\nglabel func_80100000_ovl02\n'
        "    /* 130 80100000 0D000000 */  break\n"
        "    /* 134 80100004 00002000 */ .word 0x00200000 /* invalid instruction */\n"
        "endlabel func_80100000_ovl02\n")
    k0, k1 = {}, {}
    run(FIXTURE, aliases_of(FIXTURE), None, k0)
    rc3, rows3, *_ = run(tw, aliases_of(tw), None, k1)
    ro = [sum(a.count(RO) for a in k["fx"][1].values()) for k in (k0, k1)]
    n3 = next(r["insns"] for r in rows3 if r["name"] == "func_80100000_ovl02")
    print(f"selftest: trailing invalid words (rc {rc3}, insns {n3}, rodata +{ro[1] - ro[0]} bytes)")
    ok = ok and rc3 == 0 and n3 == 1 and ro[1] - ro[0] == 4
    print(f"selftest: {'pass' if ok else 'FAIL'} (clean rc {rc}, {len(rows)} of 4 functions; gap rc {rc2})")
    if ok:
        print("inventory: control OK")
    return 0 if ok else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--alias")
    ap.add_argument("--selftest", action="store_true")
    a = ap.parse_args()
    if a.selftest:
        return selftest()
    al = aliases_of(ROOT)
    if a.alias and a.alias not in al:
        print(f"inventory: refused -- unknown alias {a.alias} (have {' '.join(al)})")
        return 2
    return run(ROOT, [a.alias] if a.alias else al, ROOT / ".run/census/inventory.jsonl")[0]


if __name__ == "__main__":
    sys.exit(main())
