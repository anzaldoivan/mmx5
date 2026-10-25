#!/usr/bin/env python3
"""imgtab.py -- tables made from disc images: the X5/X6 twins, and the units file of tools/psxd_img.py (stdlib).

mmx5's side of tools/psxd_img.py (psxdecomp's map core: the mask of a stream, the map, the strings, strnames). Both
commands read X5's retail files (`--retail <dir>`: a folder with SLUS_013.34 and ROCK_X5.BIN, as
tools/extract/extract.py writes it; default: the build's expected/ files of census.py), docs/oracle/loadmap.json and
the two splat configurations. They write keys, addresses and counts only (G12): no word of a game reaches a tracked
file. The mask is census.dup_key for a body with a known start. A stream has no function start, so it gets
psxd_img.loose(): dup_key with every base register taken as set by a lui.
  units    `slus` (the executable's text) and `ovlNN` (each code overlay of loadmap.json that has a destination).
  state    X5: `c` at the address of a `c` subsegment of config/splat.*.yaml, else `asm`. X6: as its list states it.

  imgtab.py x6 --functions <X6 functions.jsonl> --x6-root <mmx6 checkout> [--retail <dir>]
      Each X6 function of lane `game` with >= 8 words (its words: extracted/retail/ of the checkout, the bases of
      its config/loadmap.txt) is searched in every X5 unit. A hit is a place where X5's words have the same dup_key
      over the full length. A hit is found by its bytes: the X5 address is a function start only when the state is
      `c` or the name is known (a `c` subsegment, or a row of x4-partners.tsv), else the name is `-`.
      -> docs/oracle/x6-twins.tsv, one row per class member: key, words, game, unit, 0xVRAM, name, state.
         key = sha1 of the dup_key words (the signature of sig.py). A class = one key with members of both games,
         X5's members first. X6 keeps its own unit names (SLUS_013.95, rock_NN).
         `IMGTAB x6 <c> classes; X5 <n>, X6 <m>; donors X6 c -> X5 asm <a>, X5 c -> X6 asm <b>`
         (a = X5 members in state asm of a class with an X6 member in state c; b = the reverse).
  imgtab.py x6 --leads ...  (the same, then)
      -> docs/oracle/x6-leads.tsv, one row per X5 asm member of a class whose X6 member in state c has a C
         definition (src/<prog>/*.c of the X6 checkout and the files they #include, under their #define renames):
         X5 unit, 0xVRAM, name, words, X6 unit, 0xVRAM, name, the X6 C path, `x6name=x5name;...`.
         -> docs/oracle/x5-leads.tsv, the reverse: X6 asm|include_asm members and X5's C (src/slus, src/rockx5).
         The map: the own name first, then the relocated fields of the two bodies walked in parallel (j/jal targets
         outside the body; lui + a LO_OPS immediate on that register), each target named from its game's symbols
         (X5: config/symbols.*.txt and the C names; X6: config/symbols.<prog>.txt), a data target with no symbol as
         <base>+offset when both games share the base and offset, else D_/func_<addr>[_ovlNN]. A pair is kept only
         when the donor's C file names it (spelled as the file spells it). Lines
         `IMGTAB leads X6 c -> X5 asm <r> rows, <k> classes -> docs/oracle/x6-leads.tsv` and the X5 -> X6 line.
  imgtab.py units [--retail <dir>]
      -> config/oracle.units.tsv (the contract of tools/psxd_img.py): `slus` in SLUS_013.34 after its header, and
         each `ovlNN` in ROCK_X5.BIN at its file offset, at the addresses of loadmap.json. Two `#` lines, then rows.
         X5 has no census list on every host, so mmx5 writes no .run/oracle/functions.tsv: psxd_img.py strnames
         finds each start by a scan. config/oracle.retail names .run/imgtab/retail (the extractor's flat folder,
         whose file names the units file uses).
  imgtab.py --selftest
      Synthetic words that the test encodes (no game data): the core's LO_OPS are census.LO_OPS, a planted twin is
      found, a body with one changed opcode is not, the classes and the donor counts, the leads in both directions (the
      relocation map, a #define spelling, a dropped pair), the C index, the units rows. The map and the
      strings are tested in `tools/psxd_img.py --self-test`. Last line `imgtab: control OK`.
"""
import argparse
import json
import re
import struct
import sys
import tempfile
from bisect import bisect_right
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "census"))
import census  # noqa: E402  (dup_key, LO_OPS, EXE, OVL, LOADMAP, h, parse_yaml)
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import psxd_img as imgcore  # noqa: E402  (tools/psxd_img.py, psxdecomp's)
from psxd_img import HEADER, MIN_WORDS, key, loose, words, write  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
ORACLE = ROOT / "docs/oracle"
PARTNERS = ORACLE / "x4-partners.tsv"
UNITS = ROOT / "config/oracle.units.tsv"
YAMLS = {"slus": ROOT / "config/splat.slus.yaml", "rockx5": ROOT / "config/splat.rockx5.yaml"}


def die(msg):
    sys.exit(f"imgtab: {msg}")


if imgcore.LO_OPS != census.LO_OPS:
    die("psxd_img.LO_OPS is not census.LO_OPS: the mask of a stream is not dup_key's")


# ---- X5's units and states -------------------------------------------------------------------------------------------

def retail_files(retail):
    exe, ovl = (Path(retail) / census.EXE.name, Path(retail) / census.OVL.name) if retail else (census.EXE, census.OVL)
    for p in (exe, ovl, census.LOADMAP, *YAMLS.values()):
        if not p.is_file():
            die(f"{p} missing (--retail <dir>: a folder with {census.EXE.name} and {census.OVL.name})")
    return exe.read_bytes(), ovl.read_bytes()


def x5_units(exe, ovl):
    """({unit: (vram, words)}, [(unit, first word of the overlay file, words, vram)]) as census.load cuts them."""
    lm = json.loads(census.LOADMAP.read_text())
    by_off = {s["start"]: n for n, s in census.parse_yaml(YAMLS["rockx5"])[2].items()}
    units = {"slus": (census.h(lm["exe"]["t_addr"]), words(exe[HEADER:HEADER + census.h(lm["exe"]["t_size"])]))}
    cuts = []
    for o in lm["overlays"]:
        off, n = census.h(o["bin_offset"]), by_off.get(census.h(o["bin_offset"]))
        if n and o.get("dest"):
            units[n] = (census.h(o["dest"]), words(ovl[off:off + census.h(o["size"])]))
            cuts.append((n, off // 4, len(units[n][1]), units[n][0]))
    return units, cuts


def x5_names():
    """({(unit, vram): name} of the `c` subsegments, {(unit, vram): name} of the partner table)."""
    c = {}
    for alias, path in YAMLS.items():
        for n, s in census.parse_yaml(path)[2].items():
            for off, kind, name in s["subs"]:
                if kind == "c":
                    c["slus" if alias == "slus" else n, s["vram"] + off - s["start"]] = name
    known = {}
    if PARTNERS.is_file():
        for line in PARTNERS.read_text().splitlines():
            col = line.split("\t")
            known[col[0], int(col[1], 16)] = col[2]
    return c, known


# ---- the twins -------------------------------------------------------------------------------------------------------

def index(units):
    """{the loose words of an 8-word window: [(unit, word index)]}: a sound prefilter for an equal dup_key."""
    ix = defaultdict(list)
    for u, (_, ws) in units.items():
        lw = loose(ws)
        for i in range(len(lw) - MIN_WORDS + 1):
            ix[lw[i:i + MIN_WORDS]].append((u, i))
    return ix


def find(body, units, ix):
    """[(unit, vram)]: every place where a unit's words have the dup_key of body over its full length."""
    dk = census.dup_key(body)
    return sorted((u, units[u][0] + 4 * i) for u, i in ix.get(loose(body[:MIN_WORDS]), ())
                  if census.dup_key(units[u][1][i:i + len(body)]) == dk)


def x6_units(root):
    """{prog: (vram, words)}: X6's executable and its overlay files, at the bases of its config/loadmap.txt."""
    root = Path(root)
    exe = root / "extracted/retail/iso/SLUS_013.95"
    lm = root / "config/loadmap.txt"
    for p in (exe, lm):
        if not p.is_file():
            die(f"{p} missing (--x6-root: an mmx6 checkout with its extracted files)")
    b = exe.read_bytes()
    units = {exe.name: (struct.unpack_from("<I", b, 0x18)[0], words(b[HEADER:]))}
    for line in lm.read_text().splitlines():
        col = line.split()
        if len(col) >= 3 and col[0].isdigit() and col[2] == "code":
            p = root / f"extracted/retail/rock/{int(col[0]):02d}.bin"
            if p.is_file():
                units[f"rock_{int(col[0]):02d}"] = (int(col[1], 16), words(p.read_bytes()))
    return units


def twins(fns, x6, x5, names):
    """(rows, counts): the classes of x6-twins.tsv. fns: X6's function rows."""
    ix, c, known = index(x5), *names
    cls = {}
    for f in fns:
        if f["lane"] != "game" or f["words"] < MIN_WORDS:
            continue
        if f["prog"] not in x6:
            die(f"{f['prog']}: no code unit of this name in the X6 checkout")
        base, ws = x6[f["prog"]]
        o = (int(f["vram"], 16) - base) // 4
        body = ws[o:o + f["words"]]
        if o < 0 or len(body) != f["words"]:
            die(f"{f['prog']} {f['vram']} {f['name']}: outside the unit's file")
        k = key(census.dup_key(body))
        if k not in cls:
            cls[k] = (len(body), find(body, x5, ix), [])
        cls[k][2].append((f["prog"], int(f["vram"], 16), f["name"], f["state"]))
    rows, n5, n6, a, b = [], 0, 0, 0, 0
    for k, (n, m5, m6) in sorted(cls.items(), key=lambda kv: (kv[1][1], kv[0])):
        if not m5:
            continue
        m5 = [(u, v, c.get((u, v)) or known.get((u, v), "-"), "c" if (u, v) in c else "asm") for u, v in m5]
        a += sum(m[3] == "asm" for m in m5) if any(m[3] == "c" for m in m6) else 0
        b += sum(m[3] != "c" for m in m6) if any(m[3] == "c" for m in m5) else 0
        n5, n6 = n5 + len(m5), n6 + len(m6)
        rows += [(k, str(n), g, u, f"0x{v:08X}", name, st) for g, ms in (("X5", m5), ("X6", sorted(m6)))
                 for u, v, name, st in ms]
    return rows, (len({r[0] for r in rows}), n5, n6, a, b)


def cmd_x6(a):
    exe, ovl = retail_files(a.retail)
    fns = [json.loads(x) for x in Path(a.functions).read_text().splitlines() if x]
    x6, x5 = x6_units(a.x6_root), x5_units(exe, ovl)[0]
    rows, n = twins(fns, x6, x5, x5_names())
    write(ORACLE / "x6-twins.tsv", rows)
    print("IMGTAB x6 %d classes; X5 %d, X6 %d; donors X6 c -> X5 asm %d, X5 c -> X6 asm %d" % n)
    if a.leads:
        x6root = Path(a.x6_root)
        sides = {"X5": Side(x5, x5_symbols(), "slus", lambda u: "" if u == "slus" else "_" + u,
                            c_index(ROOT, ("slus", "rockx5")), lambda u: "slus" if u == "slus" else "rockx5"),
                 "X6": Side(x6, x6_symbols(x6root, x6), X6_EXE, lambda u: "",
                            c_index(x6root, sorted(x6)), lambda u: u, x6root)}
        for name, (donor, taker) in (("x6-leads.tsv", ("X6", "X5")), ("x5-leads.tsv", ("X5", "X6"))):
            got, m = leads(rows, sides[donor], sides[taker], donor, taker)
            write(ORACLE / name, got)
            print(f"IMGTAB leads {donor} c -> {taker} asm {len(got)} rows, {m} classes -> docs/oracle/{name}")
    return 0


# ---- the leads: a donor's C for each open twin, and the names its relocations take in each game ----------------------

X6_EXE = "SLUS_013.95"
SYM = re.compile(r"^\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+)\s*;", re.M)
CDEF = re.compile(r"^(?!INCLUDE_ASM\b|static\s+inline\b)[A-Za-z_][^;{}()#:]*?\b([A-Za-z_]\w*)\s*\([^;{}]*?\)\s*\{(\s*\})?",
                  re.M)  # mmx6 tools/mmx6/corpus.py CDEF_RE: a C definition at column 0 (clang-formatted)
DIRECTIVE = re.compile(r'^#(define|undef)[ \t]+(\w+)(?:[ \t]+(\w+))?[ \t]*$|^#include "([^"]+\.c)"[ \t]*$', re.M)
NEAR = 0x1000  # a data target with no symbol of its own is <base>+offset when both games' bases are this close
OPEN = ("asm", "include_asm")


class Side:
    """One game for the leads: its units {u: (vram, words)}, symbols {u: {addr: name}}, the unit whose symbols every
    other unit sees, the suffix of a default name, its C index, the src/ folder of a unit and its checkout."""

    def __init__(self, units, syms, base, suffix, cix, folder, root=ROOT):
        self.units, self.syms, self.base, self.suffix, self.cix, self.folder = units, syms, base, suffix, cix, folder
        self.root = Path(root)
        self.sorted = {u: sorted(t) for u, t in syms.items()}

    def table(self, u, t):
        """An overlay owns every address from its base up (its bss lies past its file); the rest is the base unit's."""
        return u if u != self.base and t >= self.units.get(u, (0xFFFFFFFF, ()))[0] else self.base

    def exact(self, u, t):
        return self.syms.get(self.table(u, t), {}).get(t)

    def default(self, u, t, kind):
        tu = self.table(u, t)
        return f"{kind}_{t:08X}" + (self.suffix(tu) if tu != self.base else "")

    def near(self, u, t):
        """(base address, name) of the nearest symbol at or below t in t's table, or None."""
        tu = self.table(u, t)
        addrs = self.sorted.get(tu, [])
        i = bisect_right(addrs, t) - 1
        return (addrs[i], self.syms[tu][addrs[i]]) if i >= 0 and t - addrs[i] < NEAR else None

    def body(self, u, vram, n):
        base, ws = self.units[u]
        return ws[(vram - base) // 4:(vram - base) // 4 + n]


def symtab(path, keep=lambda name: True):
    return {int(a, 16): n for n, a in reversed(SYM.findall(path.read_text())) if keep(n)} if path.is_file() else {}


def x5_symbols():
    """{unit: {addr: name}}: config/symbols.slus.txt, symbols.rockx5.txt by its `_ovlNN` suffix, then the C names."""
    tabs = defaultdict(dict, slus=symtab(ROOT / "config/symbols.slus.txt"))
    for t, n in symtab(ROOT / "config/symbols.rockx5.txt").items():
        m = re.search(r"_(ovl\d\d)$", n)
        if m:
            tabs[m[1]].setdefault(t, n)
    for (u, t), n in (lambda c, k: {**k, **c})(*x5_names()).items():
        tabs[u].setdefault(t, n)
    return tabs


def x6_symbols(root, units):
    """{prog: {addr: name}}: the mmx6 checkout's config/symbols.<prog>.txt."""
    return {p: symtab(root / f"config/symbols.{p}.txt") for p in units}


def c_index(root, folders):
    """{(folder, name): (path, {name in the build: name in the file})}: every non-empty C definition of
    src/<folder>/*.c and of the .c files they #include, under the #define renames in force at the #include."""
    out = {}

    def walk(f, folder, defs, depth):
        text = f.read_text(errors="replace")
        rel = str(f.resolve().relative_to(root.resolve()))
        for m in CDEF.finditer(text):
            if not m[2]:
                out.setdefault((folder, defs.get(m[1], m[1])), (rel, {b: a for a, b in defs.items()}))
        active = {}
        for m in DIRECTIVE.finditer(text):
            if m[1] == "define" and m[3]:
                active[m[2]] = m[3]
            elif m[1] == "undef":
                active.pop(m[2], None)
            elif m[4] and depth < 3 and (f.parent / m[4]).is_file():
                walk(f.parent / m[4], folder, {**defs, **active}, depth + 1)

    for folder in folders:
        for f in sorted((Path(root) / "src" / folder).glob("*.c")):
            walk(f, folder, {}, 0)
    return out


def targets(ws, vram):
    """{word index: (address, kind)}: the relocated fields of a body: a j/jal target outside it, or a lui value plus
    the immediate of a LO_OPS word on that register (kind func for a jump, else D)."""
    hi, out, end = {}, {}, vram + 4 * len(ws)
    for i, w in enumerate(ws):
        op, rs, rt, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
        if op in (2, 3):
            t = (vram + 4 * i) & 0xF0000000 | (w & 0x3FFFFFF) << 2
            if not vram <= t < end:
                out[i] = (t, "func")
        elif op == 15:
            hi[rt] = imm << 16
        elif op in census.LO_OPS and rs in hi:
            out[i] = ((hi[rs] | imm) if op == 13 else (hi[rs] + imm - (imm >> 15 << 16)) & 0xFFFFFFFF, "D")
            if op in (9, 13) or 32 <= op <= 38:  # addiu/ori/loads write rt: it holds no lui value after this word
                hi.pop(rt, None)
    return out


def relocation_map(d, du, dv, t, tu, tv, n, spell):
    """[(donor name, taker name)]: the two bodies' relocated fields walked in parallel; the donor's names spelled as
    its C file spells them (spell: the file's #define renames, inverted). leads() keeps a pair only when the donor's
    file names it: a lui pair that builds a constant, or an offset from another base, renames nothing."""
    td, tt, pairs = targets(d.body(du, dv, n), dv), targets(t.body(tu, tv, n), tv), []
    for i in sorted(td.keys() & tt.keys()):
        (a, kind), (b, _) = td[i], tt[i]
        na, nb = d.exact(du, a), t.exact(tu, b)
        if kind == "D" and not (na and nb):
            ba, bb = d.near(du, a), t.near(tu, b)
            if ba and bb and a - ba[0] == b - bb[0]:
                na, nb = ba[1], bb[1]
        na, nb = spell.get(na or d.default(du, a, kind), na or d.default(du, a, kind)), nb or t.default(tu, b, kind)
        if na != nb and (na, nb) not in pairs:
            pairs.append((na, nb))
    return pairs


def leads(rows, d, t, dg, tg):
    """(rows, classes): one row per open member of game tg in a class with a member of game dg in state c whose C
    definition the index finds (a `c` subsegment that still holds INCLUDE_ASM is no donor): tg unit, 0xVRAM, name, words, dg unit, 0xVRAM, name, C path, `donor=taker;...` (the function's own name first)."""
    cls = defaultdict(list)
    for r in rows:
        cls[r[0]].append(r)
    out, n = [], 0
    for k, ms in cls.items():
        donors = [m for m in ms if m[2] == dg and m[6] == "c" and (d.folder(m[3]), m[5]) in d.cix]
        open_ = [m for m in ms if m[2] == tg and (m[6] in OPEN if tg == "X6" else m[6] == "asm")]
        if not donors or not open_:
            continue
        n += 1
        donor = min(donors, key=lambda m: (m[3], m[4]))
        path, spell = d.cix[d.folder(donor[3]), donor[5]]
        dv, text = int(donor[4], 16), (d.root / path).read_text(errors="replace") if (d.root / path).is_file() else ""
        for m in open_:
            tv, words = int(m[4], 16), int(m[1])
            own = m[5] if m[5] != "-" else t.default(m[3], tv, "func")
            pairs = [(spell.get(donor[5], donor[5]), own)]
            pairs += [p for p in relocation_map(d, donor[3], dv, t, m[3], tv, words, spell)
                      if p not in pairs and re.search(rf"\b{p[0]}\b", text)]
            out.append((m[3], m[4], m[5], m[1], donor[3], donor[4], donor[5], path,
                        ";".join(f"{a}={b}" for a, b in pairs)))
    return sorted(out, key=lambda r: (r[0] != "slus", r[0], r[1])), n


# ---- the units file of tools/psxd_img.py --------------------------------------------------------------------------

def unit_rows(units, cuts):
    """The rows of config/oracle.units.tsv: x5_units() as the contract states it."""
    return [("slus", census.EXE.name, f"0x{HEADER:X}", f"0x{units['slus'][0]:08X}", str(len(units["slus"][1])), "exe")] + \
        [(u, census.OVL.name, f"0x{4 * first:X}", f"0x{vram:08X}", str(n), "code") for u, first, n, vram in cuts]


def cmd_units(a):
    rows = unit_rows(*x5_units(*retail_files(a.retail)))
    write(UNITS, rows, "# config/oracle.units.tsv -- written by tools/sig/imgtab.py units; do not edit\n# "
          + "\t".join(imgcore.UNIT_COLUMNS) + "\n")
    print(f"IMGTAB units: {len(rows)} rows ({len(rows) - 1} code overlays)")
    return 0


# ---- self-test on synthetic words ------------------------------------------------------------------------------------

def selftest():
    body, filler, fails = imgcore.body, imgcore.filler, []

    def case(name, ok, text):
        print(f"selftest: {name} {'pass' if ok else 'FAIL'} ({text})")
        if not ok:
            fails.append(name)

    a, b = body(0x8009, 0x1234, 0x4000), body(0x800A, 0x4321, 0x5000)
    case("mask", imgcore.LO_OPS == census.LO_OPS and loose(census.dup_key(a)) == loose(a) != census.dup_key(a),
         "the core's LO_OPS are census.LO_OPS; loose() clears every field that dup_key clears, and the frame's too")
    units = {"slus": (0x80010000, filler(1, 40) + b + filler(2, 40)),
             "ovl00": (0x800EE970, filler(3, 24) + body(0x800B, 0x10, 0x6000, store=41) + filler(4, 8) + b)}
    ix = index(units)
    got = find(a, units, ix)
    case("planted twin", got == [("ovl00", 0x800EE970 + 4 * 44), ("slus", 0x80010000 + 4 * 40)],
         f"{[(u, hex(v)) for u, v in got]}")
    got = find(body(0, 0, 0, store=41), units, ix)  # the planted body with one other opcode (sh for sw, word 8)
    case("changed opcode", got == [("ovl00", 0x800EE970 + 96)], "it is no twin above, and its own search finds it")
    fns = [{"prog": "x6", "vram": "0x80020000", "words": 12, "name": "twin", "state": "c", "lane": "game"},
           {"prog": "x6", "vram": "0x80020030", "words": 12, "name": "alone", "state": "c", "lane": "game"},
           {"prog": "x6", "vram": "0x80020060", "words": 12, "name": "vendor", "state": "asm", "lane": "lib"}]
    x6 = {"x6": (0x80020000, a + body(1, 2, 3, store=40) + a)}
    rows, n = twins(fns, x6, units, ({("slus", 0x800100A0): "banked"}, {}))
    case("classes", n == (1, 2, 1, 1, 0) and [r[2:] for r in rows] == [
        ("X5", "ovl00", "0x800EEA20", "-", "asm"), ("X5", "slus", "0x800100A0", "banked", "c"),
        ("X6", "x6", "0x80020000", "twin", "c")], f"{n}")
    with tempfile.TemporaryDirectory() as tmp:
        t = Path(tmp)
        for f, text in (("src/x6/T.c", "void twin(void) {\n    six_fn(g_six);\n}\n"),
                        ("src/shared/b.c", "void DEDUP_NAME(void) {\n    g_five = 0;\n}\n"),
                        ("src/shared/s.c", "void body_a(void) {\n    x();\n}\n"),
                        ("src/p/T.c", '#define body_a own_b\n#include "../shared/s.c"\n#undef body_a\n'
                                      'INCLUDE_ASM("asm/p", gone);\nvoid empty(void) {\n}\nint here(int a) {\n'
                                      '    return a;\n}\n')):
            (t / f).parent.mkdir(parents=True, exist_ok=True)
            (t / f).write_text(text)
        x5s = Side(units, {"slus": {0x800A4321: "g_five"}}, "slus", lambda u: "_" + u, {}, lambda u: "slus", t)
        x6s = Side(x6, {"x6": {0x80091234: "g_six", 0x80010000: "six_fn"}}, "x6", lambda u: "",
                   {("x6", "twin"): ("src/x6/T.c", {})}, lambda u: u, t)
        got, m = leads(rows, x6s, x5s, "X6", "X5")
        case("leads", m == 1 and got == [("ovl00", "0x800EEA20", "-", "12", "x6", "0x80020000", "twin", "src/x6/T.c",
                                          "twin=func_800EEA20_ovl00;g_six=g_five;six_fn=func_80014000")],
             "own name first; a lui+addiu pair by symbol; a store at +8 by the base both games share; a jal with no "
             f"X5 symbol by its default name: {got}")
        x5s.cix = {("slus", "banked"): ("src/shared/b.c", {"banked": "DEDUP_NAME"})}
        rev = [r[:6] + ("asm",) if r[2] == "X6" else r for r in rows]
        got, m = leads(rev, x5s, x6s, "X5", "X6")
        case("reverse", m == 1 and got == [("x6", "0x80020000", "twin", "12", "slus", "0x800100A0", "banked",
                                            "src/shared/b.c", "DEDUP_NAME=twin;g_five=g_six")],
             f"the donor's names spelled as its file spells them; the call its file does not name is dropped: {got}")
        ix = c_index(t, ("p",))
    case("c index", ix == {("p", "own_b"): ("src/shared/s.c", {"own_b": "body_a"}), ("p", "here"): ("src/p/T.c", {})},
         f"an #include under a #define, a definition in place, no empty body, no INCLUDE_ASM: {ix}")
    case("units", unit_rows({"slus": (0x80010000, (0,) * 10)}, [("ovl00", 4, 6, 0x800EE970)]) == [
        ("slus", census.EXE.name, "0x800", "0x80010000", "10", "exe"),
        ("ovl00", census.OVL.name, "0x10", "0x800EE970", "6", "code")], "the executable after its header, an overlay "
         "at its file offset")
    print("imgtab: control " + ("FAIL " + " ".join(fails) if fails else "OK"))
    return 1 if fails else 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--selftest", action="store_true")
    sub = ap.add_subparsers(dest="cmd")
    x = sub.add_parser("x6", help="docs/oracle/x6-twins.tsv")
    x.add_argument("--functions", required=True, help="X6's function list (build/corpus/functions.jsonl)")
    x.add_argument("--x6-root", required=True, help="an mmx6 checkout with extracted/retail/ and config/loadmap.txt")
    x.add_argument("--leads", action="store_true", help="also docs/oracle/x6-leads.tsv and x5-leads.tsv")
    u = sub.add_parser("units", help="config/oracle.units.tsv")
    for s in (x, u):
        s.add_argument("--retail", help="a folder with X5's SLUS_013.34 and ROCK_X5.BIN (default: expected/build)")
    a = ap.parse_args(argv)
    if a.selftest:
        return selftest()
    if a.cmd == "x6":
        return cmd_x6(a)
    if a.cmd == "units":
        return cmd_units(a)
    ap.print_usage(sys.stderr)
    return 2


if __name__ == "__main__":
    sys.exit(main())
