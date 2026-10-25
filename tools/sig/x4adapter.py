#!/usr/bin/env python3
"""x4adapter.py -- mmx5's side of the shared X4 core (tools/sig/x4core.py; stdlib): everything X5-specific it asks for.

The core (x4core.py, the same bytes as mmx6's tools/mmx6/x4core.py) knows mmx4 and the tables; this module supplies
the game and the CLI.
  the pin         config/refs.toml `[[ref]] name = "mmx4"` (x4core.pin), read from this checkout (ROOT).
  the trees       ROOT = this checkout: every output (tables, doc, .run/x4/, the clone refs/mmx4). TREE = $X4_TREE when
                  set, else ROOT: every input (the game's functions, the toolchain, the annotations record), read only.
                  A read is repeated when one of its files changed while it ran (the other checkout may be building).
  the toolchain   triple `x5` of sig.TRIPLES (sig.py:297): TREE/tools/bin/cc/gcc-2.95.2-psx/cc1 `-O2 -G0 -quiet -w`,
                  TREE/refs/maspsx/maspsx.py `--aspsx-version=2.86` (no --expand-div),
                  TREE/tools/bin/mipsel-linux-gnu-as; cpp: the host's, mmx4's own defines (the core's default).
  the clone       CLONE = refs/mmx4 at the pin (x4core.ensure_clone; `bash tools/refs_fetch.sh mmx4` fetches the same).
                  Objects under .run/x4/obj/, per-file logs under .run/x4/log/.
  the functions   census.load() over TREE: .run/census/inventory.jsonl + expected/build. unit = `slus` or the overlay
                  (`ovlNN`, the Ghidra address space), state = the inventory status (c | asm).
  the match       --partners reads no game objects, so no game-side relocation mask: census.dup_key (heuristic mask) of the game words
                  picks the mmx4 candidates, then x4core.confirmed keys the game words under each candidate's own
                  relocation mask. The key column is the mmx4 object's key. A LO16 site the heuristic does not mask
                  (its base register not set by a lui) is missed by the prefilter: an undercount, never a false row.
  tier gate       banked(): state `c`.
  game objects    slots() -> Build: the object of a corpus row is the first of build/<alias>/src/<module>.o,
                  build/<alias>/src/<alias>/<name>.o, build/<alias>/asm/<alias>/<stem>.o (stem: the asm/<alias> .s whose
                  glabel is the name) that defines it; its relocations (propagate.relocs, types 26/LO16/GPREL16) pair
                  with the mmx4 twin's (Elf.refs) slot by slot (x4core.pair). A game symbol's address: its
                  `(func|D|jtbl)_8XXXXXXX(_ovlNN)?` spelling, else config/symbols.<alias>.txt; its program `slus` inside
                  build/slus/SLUS_013.34.elf's range, else the row's unit (overlays share vram). No object or symbol:
                  the anchor is unpaired. Without the executable ELF slots() is None (`slot lane unavailable`).
                  Slot names are leads, never renames.
  tables, doc     docs/oracle/x4-partners.tsv, x4-names.tsv, x4-names.md (x4core.SCHEMA; names, addresses, keys and
                  mmx4 paths only, G12).

  x4adapter.py --partners [--jobs N]
      -> clone at the pin, every US C file of mmx4 compiled alone under the x5 triple, the partner table written.
         `X4NAMES compiled <ok> of <n> mmx4 files at <pin7> [x5]; <k> functions`
         `X4NAMES partners <rows> rows of <N> X5 functions; prefilter <p>, confirmed <c>, multi-key <a>`
         (p = functions with a heuristic candidate, c = those confirmed, a = confirmed under more than one mmx4 key:
         the smallest key is kept). No compiled file is rc 1.
  x4adapter.py --build     -> x4-names.tsv from the partner table (admission, tiers); the core's count line.
  x4adapter.py --widen     -> + same-name rows and slot-vote rows, from the objects of --partners and build/.
  x4adapter.py --selftest  -> the slot lane on a hand-written game asm fixture (tools/sig/fixtures/x4slot/, assembled
                              with the pinned assembler) and a synthetic mmx4 object (x4core.make_obj), under
                              .run/x4adapter-selftest/: an agreeing slot admitted, a two-name slot refused, a missing
                              symbol unpaired. `x4adapter: control OK -- …`, else `x4adapter: control FAIL <case>`, rc 1.
  x4adapter.py --doc       -> docs/oracle/x4-names.md from x4-names.tsv.
  x4adapter.py --who <alias text | func_8XXXXXXX | UNIT:0xVRAM>
  x4adapter.py --ghidra --out <path> [--in <annotations jsonl>]
      -> the plate-comment mirror of the aliases (x4core.ghidra_aliases) in mmx5's annotation record shape
         `{"addr":"8003a008","ctype":"plate","kind":"comment","text":…}` (overlays `ovlNN::<8 hex>`): the input record
         (default TREE/docs/oracle/annotations.jsonl) with one line appended to the plate comment an aliased address
         already has and one new record per aliased address without one, in ExportAnnotations.java's line order
         ((addr, kind, name), then the line), written to <path> (scratch; docs/oracle/annotations.jsonl is never
         written here). Every other record keeps its bytes; mmx5's function record carries no comment field, so only
         comment records change. Never a rename. Last line
         `X4NAMES ghidra <n> aliases: <new> new plate comments, <appended> appended, <kept> already there`
  x4adapter.py --xref --other <the X6 partner table>
      -> docs/oracle/x4-xref.tsv (x4core.SCHEMA["xref"]): the `single` rows of x4core.xref, X6's table against this
         one. Refused when x4core.parity names a difference (core, pin, schema) with the core of the table's
         repository (its tools/*/x4core.py). A `multi` row joins every member of a class of equal bodies with every
         member, so it is counted and not written. Prints the core's count line, then
         `X4NAMES xref <kept> single rows of <all>; <n> mmx4 functions` (n: of the kept rows).
"""
import argparse
import contextlib
import functools
import io
import json
import os
import re
import shutil
import subprocess
import sys
import time
from pathlib import Path

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import sig  # noqa: E402  (TRIPLES, CC, GAS, MASPSX; puts tools/census on sys.path)
import census  # noqa: E402  (load, dup_key)
import x4core  # noqa: E402
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "dedup"))
import carve  # noqa: E402  (asm_index, SYM)
import propagate  # noqa: E402  (relocs: the game objects' relocations)

ROOT = Path(__file__).resolve().parents[2]
TREE = Path(os.environ.get("X4_TREE") or ROOT).resolve()
TAG, GAME = "X4NAMES", "X5"
TRIPLE = "x5"
CLONE = "refs/mmx4"
SCR = ".run/x4"
OBJROOT = f"{SCR}/obj"
PARTNERS = ROOT / "docs/oracle/x4-partners.tsv"
NAMES = ROOT / "docs/oracle/x4-names.tsv"
XREF = ROOT / "docs/oracle/x4-xref.tsv"
DOC = ROOT / "docs/oracle/x4-names.md"
SCRATCH = ROOT / SCR / "widen"  # --widen intermediates, never tracked
EXE_ELF = "build/slus/SLUS_013.34.elf"  # the slus executable: its range decides a slot's program
SPELLED = re.compile(r"^(?:func|D|jtbl)_(8[0-9A-Fa-f]{7})(?:_ovl\d+)?$")
FIXTURE = Path(__file__).resolve().parent / "fixtures/x4slot"
SELFTEST = ROOT / ".run/x4adapter-selftest"
ANNOTATIONS = "docs/oracle/annotations.jsonl"
SPLAT = "config/splat.rockx5.yaml"
WIDEN_HINT = "--widen runs after x4adapter.py --partners"
RETRIES = 5
INPUTS = {n: getattr(census, n) for n in ("EXE", "OVL", "LOADMAP", "INV")}  # census.load's files, under ROOT
DOC_TEXT = dict(title="X4 names for shared X5 code", tool="tools/sig/x4adapter.py", note="",
                lookup="alias text | func_8XXXXXXX | UNIT:0xVRAM", tail="")


def die(msg):
    sys.exit(f"{TAG.lower()}: {msg}")


def tree(p):
    """The TREE twin of a ROOT path."""
    return TREE / Path(p).relative_to(ROOT)


def steady(paths, read):
    """read(), repeated while a file of paths changed during it (TREE is another checkout, possibly mid-build)."""
    def stamp():
        return [(os.stat(p).st_mtime_ns, os.stat(p).st_size) if os.path.exists(p) else None for p in paths]
    for _ in range(RETRIES):
        before = stamp()
        out = read()
        if stamp() == before:
            return out
        time.sleep(1)
    die(f"inputs under {TREE} kept changing over {RETRIES} reads")


# ---- the toolchain ---------------------------------------------------------------------------------------------------

def tools():
    """The cc1, maspsx and assembler commands of x4core.compile_one (cpp: the core's default, mmx4's)."""
    cc, _, cflags, maspsx = sig.TRIPLES[TRIPLE]
    cc1, mas, gas = tree(sig.CC / cc / "cc1"), tree(sig.MASPSX), tree(sig.GAS)
    for p in (cc1, mas, gas):
        if not p.exists():
            die(f"{p} missing (the toolchain is read from X4_TREE, else this checkout)")
    return {"cc1": [str(cc1)] + cflags, "maspsx": [sys.executable, str(mas)] + maspsx, "as": [str(gas)] + x4core.AS[1:]}


# ---- the game's functions --------------------------------------------------------------------------------------------

def unit_of(r):
    return "slus" if r["alias"] == "slus" else r["module"].split("/")[1].split("_")[0]


def functions():
    """census.load() over TREE: the inventory rows with their words (coverage misses counted on stderr)."""
    census.ROOT = TREE
    for name, p in INPUTS.items():
        setattr(census, name, tree(p))

    def read():
        with contextlib.redirect_stdout(io.StringIO()) as log:
            res = census.load()
        return res, log.getvalue()

    res, log = steady([census.EXE, census.OVL, census.LOADMAP, census.INV, TREE / SPLAT], read)
    if res[0] == 2:
        die(log.strip() + f" (under {TREE}; run tools/census/inventory.py there, or set X4_TREE)")
    if res[2]:
        print(f"{TAG.lower()}: {len(res[2])} inventory rows without expected bytes, left out", file=sys.stderr)
    return res[1]


@functools.cache
def corpus():
    """{(unit, 0xVRAM): {"words", "name", "alias", "module"}} (x4core.widen: the game's functions)."""
    return {(unit_of(f), f"0x{int(f['vram'], 16):08X}"): {"words": len(f["words"]), "name": f["name"],
                                                          "alias": f["alias"], "module": f["module"]}
            for f in functions()}


def banked():
    return lambda col: col[8] == "c"


# ---- game objects: the X5 side of the relocation-slot pairing --------------------------------------------------------

def exe_range(path):
    """[lo, hi) of the allocated sections of the slus executable's ELF."""
    secs = [s for s in x4core.Elf(path).secs if s[2] & 2 and s[5] and s[3] >= x4core.RAM[0]]
    return min(s[3] for s in secs), max(s[3] + s[5] for s in secs)


class Build:
    """The X5 side of the pairing (see the module header): names {(unit, 0xVRAM): name}, [lo, hi) of slus, objects
    and asm/ under root."""

    def __init__(self, names, lo, hi, root=ROOT):
        self.names, self.lo, self.hi, self.root = names, lo, hi, Path(root)
        self.elfs, self.stems, self.syms = {}, {}, {}

    def elf(self, path):
        if path not in self.elfs:
            self.elfs[path] = x4core.Elf(path)
        return self.elfs[path]

    def obj(self, row):
        """The first built object defining row's function, or None."""
        a, name = row["alias"], row["name"]
        if a not in self.stems:
            idx, _ = carve.asm_index(self.root / "asm" / a)
            self.stems[a] = {v["name"]: Path(v["file"]).stem for v in idx.values()}
        b = self.root / "build" / a
        cands = [b / f"src/{row['module']}.o", b / f"src/{a}/{name}.o"]
        if name in self.stems[a]:
            cands.append(b / f"asm/{a}/{self.stems[a][name]}.o")
        return next((str(p) for p in cands if p.is_file() and self.elf(str(p)).defined(name)), None)

    def addr_of(self, alias):
        """game symbol -> address: its spelling, else config/symbols.<alias>.txt; None when neither."""
        if alias not in self.syms:
            sp = self.root / f"config/symbols.{alias}.txt"
            self.syms[alias] = {m.group(1): int(m.group(2), 16) for ln in
                                (sp.read_text().splitlines() if sp.is_file() else ()) if (m := carve.SYM.match(ln))}
        syms = self.syms[alias]
        return lambda n: int(m.group(1), 16) if (m := SPELLED.match(n)) else syms.get(n)

    def x6sym(self, prog, a, is_text):
        return self.names.get((prog, f"0x{a:08X}"), "-")

    def votes(self, row, x4obj, xf, voter):
        """The votes of one anchor (corpus row, mmx4 function xf of x4obj), or raise x4core.Skip."""
        o = self.obj(row)
        if o is None or not os.path.isfile(x4obj):
            raise x4core.Skip(f"no object for {row['name']} | {x4obj}")
        g = propagate.relocs(o, row["name"])
        if g is None:
            raise x4core.Skip(f"no symbol {row['name']} in {o}")
        r6 = {i: (t, s, e) for i, t, s, e in g if t in (4, 6, 7)}
        r4 = self.elf(x4obj).refs(xf, row["words"])
        unit = unit_of(row)
        return [("slus" if self.lo <= a < self.hi else unit, a, jump, sym, voter)
                for a, jump, sym in x4core.pair(r4, r6, self.addr_of(row["alias"]))]


def slots():
    """Build over TREE's build/ (game objects are inputs), or None without the slus executable's ELF."""
    if not (TREE / EXE_ELF).is_file():
        return None
    return Build({k: v["name"] for k, v in corpus().items()}, *exe_range(TREE / EXE_ELF), root=TREE)


def selftest():
    """The slot lane on fixtures/x4slot (module header): ROM-free, no build/, no clone."""
    shutil.rmtree(SELFTEST, ignore_errors=True)
    for d in ("asm/fx", "build/fx/asm/fx", "config", "x4"):
        os.makedirs(SELFTEST / d)
    shutil.copy(FIXTURE / "game.s", SELFTEST / "asm/fx/game.s")
    shutil.copy(FIXTURE / "symbols.fx.txt", SELFTEST / "config/symbols.fx.txt")
    obj = SELFTEST / "build/fx/asm/fx/game.o"
    subprocess.run([str(sig.GAS)] + x4core.AS[1:] + ["-o", str(obj), str(SELFTEST / "asm/fx/game.s")], check=True)
    n = {nm: len(w) for nm, w, _ in x4core.functions(str(obj))}
    # mmx4 twins: the call and the first global agree in all three; the second global is planted_b in x_three
    rel = lambda b: [(2, 4, "planted_callee"), (4, 5, "planted_global"), (5, 6, "planted_global"), (6, 5, b), (7, 6, b)]
    x4obj = str(SELFTEST / "x4/a.c.o")
    x4core.make_obj(x4obj, [(xf, [0] * 12, True, rel(b)) for xf, b in
                            (("x_one", "planted_a"), ("x_two", "planted_a"), ("x_three", "planted_b"))],
                    ("planted_callee", "planted_global", "planted_a", "planted_b"))
    b = Build({("slus", "0x80018000"): "fx_callee"}, 0x80010000, 0x80020000, root=SELFTEST)
    votes, fails = [], []
    for name, xf in (("func_80020100", "x_one"), ("func_80020200", "x_two"), ("func_80020300", "x_three")):
        row = {"alias": "fx", "module": "fx/ovl01_80020100", "name": name, "words": n.get(name, 0)}
        votes += b.votes(row, x4obj, xf, f"src/a.c:{xf}")
    try:
        b.votes({"alias": "fx", "module": "fx/ovl01_80020100", "name": "func_80020400", "words": 12}, x4obj, "x_one",
                "src/a.c:x_one")
        fails.append("skip")
    except x4core.Skip:
        pass
    admitted, conflicts = x4core.tally(votes)
    if admitted != {("slus", 0x80018000): ("planted_callee", 3, True), ("ovl01", 0x80030000): ("planted_global", 3, False)}:
        fails.append(f"slot_votes {sorted(admitted.items())}")
    if conflicts != [("two-names", "ovl01", 0x80030010, "planted_a:2 planted_b:1")] or ("ovl01", 0x80030010) in admitted:
        fails.append(f"slot_disagree {conflicts}")
    if b.x6sym("slus", 0x80018000, True) != "fx_callee" or b.x6sym("ovl01", 0x80030000, False) != "-":
        fails.append("x6sym")
    for f in fails:
        print(f"x4adapter: control FAIL {f}")
    if fails:
        return 1
    print(f"x4adapter: control OK -- {len(votes)} votes of 3 anchors; admitted slus 0x80018000 planted_callee (jump) "
          "and ovl01 0x80030000 planted_global, 3 voters each; ovl01 0x80030010 two names (planted_a:2 planted_b:1) "
          "refused; a missing symbol unpaired")
    return 0


def widen_inputs():
    return OBJROOT, str(PARTNERS)


# ---- the partner table -----------------------------------------------------------------------------------------------

def partners(jobs=None):
    os.chdir(ROOT)
    ref = x4core.pin(ROOT)
    x4core.ensure_clone(CLONE, ref)
    srcs, objs = x4core.compile_all(CLONE, tools(), f"{SCR}/inc", OBJROOT, f"{SCR}/log", jobs)
    by_key, _ = x4core.partner_map(OBJROOT, objs)
    cands = {}
    for o in objs:
        for _, w, m in x4core.functions(o):
            cands.setdefault(census.dup_key(w), {})[(tuple(w), tuple(m))] = (w, m)
    print(f"{TAG} compiled {len(objs)} of {len(srcs)} mmx4 files at {x4core.short(ref)} [{TRIPLE}]; "
          f"{sum(len(v) for v in by_key.values())} functions")
    if not objs:
        print(f"{TAG.lower()}: no mmx4 file compiled (see {SCR}/log/)", file=sys.stderr)
        return 1
    fns = functions()
    game, pre, multi = [], 0, 0
    for f in fns:
        c = cands.get(census.dup_key(f["words"]))
        if not c:
            continue
        pre += 1
        keys = sorted(x4core.confirmed(list(f["words"]), list(c.values())))
        if keys:
            multi += len(keys) > 1
            game.append((unit_of(f), int(f["vram"], 16), f["name"], len(f["words"]), keys[0], f["status"]))
    rows = x4core.write_partners(PARTNERS, game, by_key)
    print(f"{TAG} partners {len(rows)} rows of {len(fns)} {GAME} functions; prefilter {pre}, confirmed {len(game)}, "
          f"multi-key {multi}")
    return 0


# ---- the Ghidra plate-comment mirror ---------------------------------------------------------------------------------

def ghidra(out, src=None):
    """Untouched records keep their bytes; an appended plate line is spliced into the record's trailing text field."""
    src = Path(src) if src else TREE / ANNOTATIONS
    recs = [[json.loads(x), x] for x in steady([src], lambda: src.read_text(encoding="utf-8")).splitlines() if x]
    plate = {r["addr"]: e for e in recs for r in e[:1] if r.get("kind") == "comment" and r.get("ctype") == "plate"}
    new = appended = kept = 0
    aliases = x4core.ghidra_aliases(NAMES)
    for unit, vram, text in aliases:
        addr = ("" if unit == "slus" else f"{unit}::") + f"{int(vram, 16):08x}"
        quoted = json.dumps(text, ensure_ascii=False)[1:-1]
        e = plate.get(addr)
        if e is None:
            r = {"addr": addr, "ctype": "plate", "kind": "comment", "text": text}
            plate[addr] = [r, f'{{"addr":"{addr}","ctype":"plate","kind":"comment","text":"{quoted}"}}']
            recs.append(plate[addr])
            new += 1
        elif text in e[0]["text"].split("\n"):
            kept += 1
        else:
            line = e[1][:-2] + "\\n" + quoted + '"}'
            e[0]["text"] += "\n" + text
            if not e[1].endswith('"}') or json.loads(line) != e[0]:
                die(f"{src}: the plate record at {addr} does not end with its text field")
            e[1] = line
            appended += 1
    # ExportAnnotations.java's order: (addr, kind, name), then the whole line
    lines = sorted((r.get("addr") or "", r.get("kind") or "", r.get("name") or "", x) for r, x in recs)
    os.makedirs(os.path.dirname(os.path.abspath(out)), exist_ok=True)
    with open(out, "w", newline="\n", encoding="utf-8") as f:
        f.write("".join(x[3] + "\n" for x in lines))
    print(f"{TAG} ghidra {len(aliases)} aliases: {new} new plate comments, {appended} appended, {kept} already there")
    return 0


# ---- the cross-reference with X6 -------------------------------------------------------------------------------------

def xref(other):
    if not Path(other).is_file() or not PARTNERS.is_file():
        die(f"{other if PARTNERS.is_file() else PARTNERS} missing")
    cores = sorted(x4core.root_of(other).glob("tools/*/x4core.py"))
    if len(cores) != 1:
        die(f"one tools/*/x4core.py expected in the repository of {other}, found {len(cores)}")
    bad = x4core.parity(cores[0])
    if bad:
        die(f"xref refused: parity FAIL {' '.join(bad)} against {cores[0]}")
    rows, ref = x4core.xref(other, PARTNERS)
    kept = [r for r in rows if r[10] == "single"]
    with open(XREF, "w", newline="\n") as f:
        f.write("".join("\t".join(r) + "\n" for r in kept))
    print(f"x4core: xref {len(rows)} rows, {len({r[:2] for r in rows})} mmx4 functions, pin {x4core.short(ref)}")
    print(f"{TAG} xref {len(kept)} single rows of {len(rows)}; {len({r[:2] for r in kept})} mmx4 functions")
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--partners", action="store_true", help="clone, compile mmx4 [x5], write the partner table")
    g.add_argument("--build", action="store_true", help="the names table from the partner table")
    g.add_argument("--widen", action="store_true", help="add the same-name rows (after --partners)")
    g.add_argument("--doc", action="store_true", help="docs/oracle/x4-names.md from the names table")
    g.add_argument("--who", metavar="TEXT", help="alias text | func_8XXXXXXX | UNIT:0xVRAM")
    g.add_argument("--ghidra", action="store_true", help="the plate-comment mirror (needs --out)")
    g.add_argument("--xref", action="store_true", help="the cross-reference with X6 (needs --other)")
    g.add_argument("--selftest", action="store_true", help="the slot lane on a hand-written fixture (ROM-free)")
    ap.add_argument("--jobs", type=int, help="--partners: parallel compiles (default: the cpu count)")
    ap.add_argument("--out", help="--ghidra: the merged annotations file to write (scratch)")
    ap.add_argument("--in", dest="src", help="--ghidra: the annotations record to merge into")
    ap.add_argument("--other", help="--xref: the X6 partner table (in its repository)")
    a = ap.parse_args(argv)
    me = sys.modules[__name__]
    if a.selftest:
        return selftest()
    if a.partners:
        return partners(a.jobs)
    if a.build:
        if not PARTNERS.is_file():
            die(f"{PARTNERS} missing (run --partners)")
        x4core.build(PARTNERS, NAMES, banked(), x4core.short(x4core.pin(ROOT)), TAG)
        return 0
    if a.widen:
        return x4core.widen(me)
    if a.doc:
        return x4core.doc(me)
    if a.who:
        return x4core.who(NAMES, a.who, TAG)
    if a.xref:
        if not a.other:
            ap.error("--xref needs --other")
        return xref(a.other)
    if not a.out:
        ap.error("--ghidra needs --out")
    return ghidra(a.out, a.src)


if __name__ == "__main__":
    sys.exit(main())
