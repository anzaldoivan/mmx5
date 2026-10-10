#!/usr/bin/env python3
"""Harness: eight question pairs, each one question answered by two independent paths; a disagreement fails.

  harness.py [--sample|--full] [--selftest]

Pairs (inputs; run on a post-`make check` tree, after `make compile-only` and the census tools):
  p1 fleet green     build/<a>.check.rc  vs  hashlib sha1 of the built binary against config/check.<a>.sha
  p2 function set    .run/census/inventory.jsonl (alias, name, vram)  vs  linker-map `.text` symbols
                     (build/<a>/*.map via tools/probe/fingerprint.py read_map; `= .` linker symbols dropped)
  p3 extents         inventory (vram, insns)  vs  tools/census/boundaries.py partition of the linked bytes
                     (expected/build/*, docs/oracle/loadmap.json); both ends trimmed of trailing zero words
  p4 matched set     config/splat.<a>.yaml `c` subsegments  vs  src/<a>/*.c and build/<a>/src/**/*.o
  p5 compiles        .run/compile-only/src/**/*.o  vs  build/<a>/src/**/*.o, per src/**/*.c: .text of the
                     function named by the file stem (tools/probe/probe.py read_func + masked); src/shared/ skipped
  p6 load addresses  docs/oracle/loadmap.json code overlays (bin_offset -> dest)  vs  config/splat.rockx5.yaml
                     `type: code` segments (start -> vram); null-dest code overlays excluded on both sides
  p7 census denominator  .run/census/report.txt [fleet] lane sums (dup+family-only+unique-tail+excluded per
                     all|game|vendor)  vs  inventory.jsonl rows counted here (vendor = kind libobj|libgap)
  p8 dedup registry  config/dedup.us.yaml members (alias, name)  vs  yaml `c` cuts whose src/<a>/<name>.c includes
                     `../shared/` (tools/dedup/propagate.py)
Modes: --sample (default) = p1 p2 p4 p5 p6 p7 p8 on the on-disk inputs (cheap, no re-derivation).
       --full = re-runs tools/census/inventory.py and census.py report, then all eight (p3 re-derives boundaries).
Output: one line per pair `pair <id>: agree|DISAGREE <a> vs <b>` or `pair <id>: not judged <why>` (missing input:
counts as a disagreement, never agree); last line `harness: <k> pairs, <d> disagreements`; copied to
.run/harness/last.txt. Exit 0 green, 1 any DISAGREE or not judged, 2 refused input (bad arguments).
--selftest: per pair a synthetic clean fixture (must agree), a planted disagreement (must DISAGREE) and a missing
input (must be not judged); fixtures are our own words, built under .run/harness/selftest/ (G12).
"""
import argparse
import contextlib
import hashlib
import io
import json
import re
import shutil
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT / "tools/probe"), str(ROOT / "tools/census")]
import fingerprint  # noqa: E402
import probe  # noqa: E402

OUT = ROOT / ".run/harness/last.txt"
SAMPLE = ["p1", "p2", "p4", "p5", "p6", "p7", "p8"]


class NotJudged(Exception):
    pass


def need(p):
    if not p.exists():
        raise NotJudged(f"missing {p.relative_to(ROOT) if p.is_relative_to(ROOT) else p}")
    return p


def aliases(r):
    return sorted(p.name.split(".")[1] for p in (r / "config").glob("splat.*.yaml"))


def inventory_rows(r):
    return [json.loads(x) for x in need(r / ".run/census/inventory.jsonl").read_text().splitlines() if x.strip()]


def p1(r):
    a, b = {}, {}
    shas = sorted((r / "config").glob("check.*.sha"))
    if not shas:
        raise NotJudged("no config/check.*.sha")
    for s in shas:
        al = s.name.split(".")[1]
        rc = need(r / f"build/{al}.check.rc").read_text().strip()
        a[al] = "green" if rc == "0" else f"rc{rc}"
        ok = True
        for line in s.read_text().splitlines():
            if line.strip():
                h, path = line.split(None, 1)
                ok &= hashlib.sha1(need(r / path.strip().lstrip("*")).read_bytes()).hexdigest() == h.lower()
        b[al] = "green" if ok else "sha1-differs"
    return "check.rc", a, "sha1", b


def p2(r):
    a = {(x["alias"], x["name"]): x["vram"] for x in inventory_rows(r)}
    b = {}
    # ponytail: the map cannot type a symbol; data (dlabel) and in-function (alabel) labels are typed by their directive
    other = {m.group(1) for p in need(r / "asm").rglob("*.s") for line in p.read_text().splitlines()
             if (m := re.match(r"\s*[ad]label (\w+)", line))}
    fingerprint.ROOT = r
    for al, mp in sorted(fingerprint.MAPS.items()):
        got = fingerprint.read_map(al)
        if got is None:
            raise NotJudged(f"missing {r / mp}")
        syms, sec, obj = got[0], None, None
        for line in (r / mp).read_text().splitlines():
            if m := re.match(r"^ (\.\S+)(?:\s+0x\S+\s+0x\S+\s+(\S+))?", line):
                sec, obj = m.group(1), m.group(2)
            elif sec and obj is None and (m := re.match(r"^\s+0x\S+\s+0x\S+\s+(\S+)$", line)):
                obj = m.group(1)  # long section name: address line follows
            elif not line.startswith(" "):
                sec = None
            elif (sec == ".text" and f"/asm/{al}/data/" not in obj and "= ." not in line  # data/: non-code subsegs
                  and (m := re.match(r"^\s+0x[0-9a-f]+\s+(\w+)\s*$", line)) and m.group(1) not in other):
                b[(al, m.group(1))] = f"{syms[m.group(1)]:08X}"
    return "inventory", a, "map .text symbols", b


def bytes_parts(run):
    """Runs boundaries code via `run(B)` with compare spied: {(alias, module): (Module, parts)}."""
    import boundaries as B
    rec, orig, out = {}, B.compare, B.OUT

    def spy(m, inv, parts, src):
        rec[(m.alias, m.name)] = (m, parts)
        return orig(m, inv, parts, src)
    B.compare, B.OUT = spy, None
    try:
        with contextlib.redirect_stdout(io.StringIO()):
            rc = run(B)
    finally:
        B.compare, B.OUT = orig, out
    return rc, rec, B.trim


def extents(rows, rec, trim):
    a = {}
    for x in rows:
        v, mod = int(x["vram"], 16), x["module"].split("/")[-1].split("_")[0]
        k = (x["alias"], mod) if (x["alias"], mod) in rec else (x["alias"], "exe")
        a[(x["alias"], k[1], x["vram"])] = f"{trim(rec[k][0], v, v + 4 * x['insns']):08X}" if k in rec else "no module"
    b = {(al, mod, f"{s:08X}"): f"{trim(m, s, e):08X}" if why is None else why
         for (al, mod), (m, parts) in rec.items() for s, (e, why) in parts.items()}
    return "inventory", a, "bytes partition", b


def p3(r):
    rows = inventory_rows(r)
    rc, rec, trim = bytes_parts(lambda B: B.run(aliases(r)))
    if rc == 2:
        raise NotJudged("boundaries.py refused input (expected/build bytes, loadmap or map missing)")
    return extents(rows, rec, trim)


def yaml_c(r, al):
    return {m.group(1) for line in (r / f"config/splat.{al}.yaml").read_text().splitlines()
            if (m := re.match(r"^\s*- \[0x[0-9A-Fa-f]+, c, (\w+)\]", line))}


def p4(r):
    a, b = set(), set()
    for al in aliases(r):
        names = yaml_c(r, al)
        a |= {(al, n, k) for n in names for k in ("src", "obj")}
        if names:
            need(r / "src" / al)
            need(r / "build" / al / "src")
        b |= {(al, p.stem, "src") for p in (r / "src" / al).glob("*.c")}
        b |= {(al, p.stem, "obj") for p in (r / "build" / al / "src").rglob("*.o")}
    return "yaml c", a, "src+obj", b


def p5(r):
    a, b = {}, {}
    srcs = sorted((r / "src").rglob("*.c"))
    if not srcs:
        raise NotJudged(f"no {r / 'src'}/**/*.c")
    for c in srcs:
        if c.relative_to(r).parts[1] == "shared":  # dedup bodies: included by members, never built alone
            continue
        rel = c.relative_to(r).with_suffix(".o")
        for d, obj in ((a, r / ".run/compile-only" / rel), (b, r / "build" / rel.parts[1] / rel)):
            try:
                d[str(rel)] = tuple(probe.masked(*probe.read_func(need(obj), c.stem)))
            except KeyError:
                d[str(rel)] = "no symbol"
    return "compile-only", a, "build", b


def hx(x):
    return x if isinstance(x, int) else int(x, 16)


def p6(r):
    lm = json.loads(need(r / "docs/oracle/loadmap.json").read_text())
    a, null = {}, set()
    for o in lm["overlays"]:
        if o.get("kind") == "code":
            if o.get("dest"):
                a[f"{hx(o['bin_offset']):X}"] = f"{hx(o['dest']):08X}"
            else:
                null.add(f"{hx(o['bin_offset']):X}")
    b, seg = {}, None
    for line in need(r / "config/splat.rockx5.yaml").read_text().splitlines():
        if m := re.match(r"  - (?:name: (\S+)$|\{)", line):
            seg = {} if m.group(1) else None
        elif seg is not None and (m := re.match(r"    (type|start|vram): (\S+)$", line)):
            seg[m.group(1)] = m.group(2)
            if seg.keys() >= {"type", "start", "vram"} and seg["type"] == "code":
                b[f"{int(seg['start'], 16):X}"] = f"{int(seg['vram'], 16):08X}"
                seg = None
    return "loadmap dest", a, "yaml vram", {k: v for k, v in b.items() if k not in null}


def p7(r):
    a = {}
    for line in need(r / ".run/census/report.txt").read_text().splitlines():
        if m := re.match(r"census: \[fleet\] \[(\w+)\] (dup|family-only|unique-tail|excluded) (\d+) of", line):
            a[m.group(1)] = a.get(m.group(1), 0) + int(m.group(3))
    if not a:
        raise NotJudged("report.txt has no [fleet] lane lines")
    rows = inventory_rows(r)
    b = {"all": len(rows), "game": sum(x["kind"] == "game" for x in rows),
         "vendor": sum(x["kind"] in ("libobj", "libgap") for x in rows)}
    return "census lanes", a, "inventory rows", b


def p8(r):
    a = {(m.group(1), m.group(2)) for line in need(r / "config/dedup.us.yaml").read_text().splitlines()
         if (m := re.match(r"^\s*- \{alias: (\w+), .*name: (\w+)\}", line))}
    b = {(al, n) for al in aliases(r) for n in yaml_c(r, al)
         if (c := r / "src" / al / f"{n}.c").exists() and '#include "../shared/' in c.read_text()}
    return "registry", a, "shared cuts", b


PAIRS = {"p1": p1, "p2": p2, "p3": p3, "p4": p4, "p5": p5, "p6": p6, "p7": p7, "p8": p8}


def short(x):
    return "/".join(map(str, x)) if isinstance(x, tuple) else str(x)


def judge(pid, thunk):
    """(line, verdict) with verdict agree|DISAGREE|not judged."""
    try:
        la, a, lb, b = thunk()
    except NotJudged as e:
        return f"pair {pid}: not judged {e}", "not judged"
    n = (lambda v: len(v) if isinstance(v, (set, dict)) else v)
    if a == b:
        return f"pair {pid}: agree {la} {n(a)} vs {lb} {n(b)}", "agree"
    if isinstance(a, dict):
        diff = sorted(k for k in a.keys() | b.keys() if a.get(k) != b.get(k))
        sv = (lambda v: v if isinstance(v, (str, int, type(None))) else "..")
        ds = [f"{short(k)}={sv(a.get(k))}|{sv(b.get(k))}" for k in diff]
    else:
        ds = [f"{short(k)} only {la if k in a else lb}" for k in sorted(a ^ b)]
    more = f" (+{len(ds) - 3})" if len(ds) > 3 else ""
    return f"pair {pid}: DISAGREE {la} {n(a)} vs {lb} {n(b)}: {', '.join(ds[:3])}{more}", "DISAGREE"


def run(ids, full):
    lines = []
    if full:
        for tool in ("inventory.py", "census.py report"):
            argv = [sys.executable, str(ROOT / "tools/census" / tool.split()[0])] + tool.split()[1:]
            rc = subprocess.run(argv, cwd=ROOT, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL).returncode
            lines.append(f"rederive: {tool} rc {rc}")
            print(lines[-1], flush=True)
    d = 0
    for pid in ids:
        line, v = judge(pid, lambda: PAIRS[pid](ROOT))
        d += v != "agree"
        lines.append(line)
        print(line, flush=True)
    lines.append(f"harness: {len(ids)} pairs, {d} disagreements")
    print(lines[-1])
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text("\n".join(lines) + "\n")
    return 1 if d else 0


# --- selftest: synthetic fixtures from our own words ------------------------------------------------------------------
JR_RA, NOP, ADDIU = 0x03E00008, 0, 0x24420001  # jr ra; nop; addiu v0,v0,1


def elf(name, words):
    """Minimal ELF32-LE .o: .text holding `words`, one func symbol `name` (what probe.read_func reads)."""
    text, strtab = struct.pack(f"<{len(words)}I", *words), b"\0" + name.encode() + b"\0"
    sym = bytes(16) + struct.pack("<IIIBBH", 1, 0, len(text), 0x12, 0, 1)
    shstr = b"\0.text\0.symtab\0.strtab\0.shstrtab\0"
    d, offs = bytearray(0x34), []
    for blob in (text, sym, strtab, shstr):
        offs.append(len(d))
        d += blob + bytes(-len(blob) % 4)
    sh = [(0,) * 10, (1, 1, 6, 0, offs[0], len(text), 0, 0, 4, 0), (7, 2, 0, 0, offs[1], len(sym), 3, 1, 4, 16),
          (15, 3, 0, 0, offs[2], len(strtab), 0, 0, 1, 0), (23, 3, 0, 0, offs[3], len(shstr), 0, 0, 1, 0)]
    struct.pack_into("<I", d, 0x20, len(d))
    struct.pack_into("<HHH", d, 0x2E, 40, 5, 4)
    d[:4] = b"\x7fELF"
    return bytes(d) + b"".join(struct.pack("<10I", *s) for s in sh)


def fixture(r):
    """Clean synthetic tree: alias zz (2 asm fns + 1 c fn), overlay yaml/loadmap, census report."""
    if r.exists():
        shutil.rmtree(r)
    files = {
        "config/splat.zz.yaml": "      - [0x0, asm]\n      - [0x10, c, func_80010010]\n",
        "config/splat.rockx5.yaml": "  - {name: toc, type: bin, start: 0x0}\n  - name: ovl00\n    type: code\n"
                                    "    start: 0x800\n    vram: 0x800F0000\n  - {name: ovl01, type: bin, start: 0x1000}\n",
        "docs/oracle/loadmap.json": json.dumps({"overlays": [
            {"bin_offset": "00000800", "kind": "code", "dest": "800F0000"},
            {"bin_offset": "00001000", "kind": "code", "dest": None}]}),
        "build/zz/ZZ.map": " .text          0x80010000       0x10 build/zz/asm/zz/a.o\n"
                           "                0x80010000                func_80010000\n"
                           "                0x80010008                func_80010008\n"
                           "                0x8001000C                D_8001000C\n"
                           " .text          0x80010020        0x4 build/zz/asm/zz/data/20.o\n"
                           "                0x80010020                __20_textbin\n"
                           " .text          0x80010010        0x8 build/zz/src/zz/func_80010010.o\n"
                           "                0x80010010                func_80010010\n"
                           "                0x80010018                a_TEXT_END = .\n"
                           " .data          0x80010018        0x4 build/zz/asm/zz/d.o\n"
                           "                0x80010018                D_80010018\n",
        "asm/zz/a.s": "glabel func_80010000\nglabel func_80010008\ndlabel D_8001000C\n",
        "build/zz.check.rc": "0\n",
        "src/zz/func_80010010.c": '#define DEDUP_NAME func_80010010\n#include "../shared/func_80010010.c"\n',
        "config/dedup.us.yaml": "groups:\n  - group: 00\n    body: src/shared/func_80010010.c\n    members:\n"
                                "      - {alias: zz, module: zz/a, vram: 0x80010010, name: func_80010010}\n",
        ".run/census/inventory.jsonl": "".join(json.dumps(
            {"alias": "zz", "module": "zz/a", "kind": k, "name": f"func_{v}", "vram": v, "insns": 2,
             "status": s}) + "\n" for v, k, s in (("80010000", "game", "asm"), ("80010008", "libobj", "asm"),
                                                  ("80010010", "game", "c"))),
        ".run/census/report.txt": "census: [fleet] [all] dup 1 of 3\ncensus: [fleet] [all] family-only 0 of 3\n"
                                  "census: [fleet] [all] unique-tail 2 of 3 functions, 4 insns\n"
                                  "census: [fleet] [all] excluded 0 of 3\ncensus: [fleet] [game] dup 1 of 2\n"
                                  "census: [fleet] [game] unique-tail 1 of 2 functions, 2 insns\n"
                                  "census: [fleet] [vendor] unique-tail 1 of 1 functions, 2 insns\n",
    }
    binary = struct.pack("<4I", ADDIU, JR_RA, NOP, NOP)
    for p, t in files.items():
        (r / p).parent.mkdir(parents=True, exist_ok=True)
        (r / p).write_text(t)
    (r / "build/zz/ZZ.BIN").write_bytes(binary)
    (r / "config/check.zz.sha").write_text(f"{hashlib.sha1(binary).hexdigest()}  build/zz/ZZ.BIN\n")
    for p in ("build/zz/src/zz/func_80010010.o", ".run/compile-only/src/zz/func_80010010.o"):
        (r / p).parent.mkdir(parents=True, exist_ok=True)
        (r / p).write_bytes(elf("func_80010010", [ADDIU, JR_RA, NOP]))


def edit(p, old, new):
    p.write_text(p.read_text().replace(old, new, 1))


# pid -> (planted disagreement, missing input), each a mutation of the clean tree at r
PLANTS = {
    "p1": (lambda r: (r / "build/zz/ZZ.BIN").write_bytes(b"\0" * 16), lambda r: (r / "build/zz.check.rc").unlink()),
    "p2": (lambda r: edit(r / ".run/census/inventory.jsonl", '"vram": "80010008"', '"vram": "8001000C"'),
           lambda r: (r / "build/zz/ZZ.map").unlink()),
    "p4": (lambda r: (r / "src/zz/func_80010010.c").unlink(), lambda r: shutil.rmtree(r / "build/zz/src")),
    "p5": (lambda r: (r / ".run/compile-only/src/zz/func_80010010.o").write_bytes(elf("func_80010010", [JR_RA, NOP])),
           lambda r: (r / ".run/compile-only/src/zz/func_80010010.o").unlink()),
    "p6": (lambda r: edit(r / "config/splat.rockx5.yaml", "0x800F0000", "0x800F0010"),
           lambda r: (r / "docs/oracle/loadmap.json").unlink()),
    "p7": (lambda r: edit(r / ".run/census/report.txt", "dup 1 of 3", "dup 2 of 3"),
           lambda r: (r / ".run/census/report.txt").unlink()),
    "p8": (lambda r: edit(r / "config/dedup.us.yaml", "name: func_80010010", "name: func_80010000"),
           lambda r: (r / "config/dedup.us.yaml").unlink()),
}


def selftest():
    r, ok = ROOT / ".run/harness/selftest", True
    maps = fingerprint.MAPS
    fingerprint.MAPS = {"zz": "build/zz/ZZ.map"}
    cases = []
    for pid, (plant, miss) in PLANTS.items():
        for label, mut, want in (("clean", None, "agree"), ("planted", plant, "DISAGREE"),
                                 ("missing", miss, "not judged")):
            cases.append((pid, label, mut, want, lambda: PAIRS[pid](r)))
    # p3: boundaries' own synthetic module; the inventory side is rows built from its fixture.
    try:
        import boundaries as B
        data, base, end, inv = B.build()
        mod = B.Module("fx", "ovl00", base, data, [(base, end)])
        rows = [{"alias": "fx", "module": "fx/ovl00_x", "vram": f"{v:08X}", "insns": n} for v, n, _ in inv]
        plant3 = [dict(x, insns=6) if i == 2 else x for i, x in enumerate(rows)]  # f2 shortened

        def p3fx(rws):
            _, rec, trim = bytes_parts(lambda B: B.analyze([mod], None, {"ovl00": []}))
            if not rws:
                raise NotJudged("missing inventory rows")
            return extents(rws, rec, trim)
        for label, rws, want in (("clean", rows, "agree"), ("planted", plant3, "DISAGREE"), ("missing", [], "not judged")):
            cases.append(("p3", label, None, want, lambda rws=rws: p3fx(rws)))
        for pid, label, mut, want, thunk in sorted(cases, key=lambda c: c[0]):
            if pid != "p3":
                fixture(r)
                if mut:
                    mut(r)
            line, v = judge(pid, thunk)
            good = v == want
            ok &= good
            print(f"selftest: {pid} {label}: {'ok' if good else 'WRONG'} -- {line}")
    finally:
        fingerprint.MAPS, fingerprint.ROOT = maps, ROOT
    print(f"selftest: {'pass' if ok else 'FAIL'}")
    if ok:
        print("harness: control OK")
    return 0 if ok else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0], epilog=__doc__.split("\n\n", 1)[1],
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group()
    g.add_argument("--sample", action="store_true", help="default: p1 p2 p4 p5 p6 p7 p8 on on-disk inputs")
    g.add_argument("--full", action="store_true", help="re-derive inventory + census report, then all 8 pairs")
    ap.add_argument("--selftest", action="store_true", help="synthetic clean/planted/missing case per pair")
    a = ap.parse_args()
    if a.selftest:
        return selftest()
    return run(list(PAIRS) if a.full else SAMPLE, a.full)


if __name__ == "__main__":
    sys.exit(main())
