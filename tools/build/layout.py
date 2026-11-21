#!/usr/bin/env python3
"""layout -- the one place that decides a unit's file paths (stdlib only; phase 4.1 T4).

Rule: a unit's folder is the `dir:` key of the config/splat.<alias>.yaml segment that declares it ('' when the
segment has none), as splat 0.50.0 places it (segtypes/common/c.py:129,157; codesubsegment.py:221; data.py:20).
All paths are repo-relative Paths; `root` selects the tree (fixtures pass their own root).

  Library: locate(alias, name) source .c; asm_s, nonmatchings, data_s, obj, asm_obj the split paths; units(alias)
      [(name, path)] in yaml order (alias `shared`: the bodies of config/dedup.us.yaml); src_root, asm_root (tree roots,
      for recursive walks only); home(alias, name) the final layout (an overlay unit: src/<alias>/<ovlNN>/<name>.c;
      a slus unit: src/slus/<system>/<name>.c when placement() places it, else flat; shared: the flat path). An
      undeclared name takes the segment its `_<seg>` suffix or `<seg>_` prefix names.
      data_root the split data folder; split_s(asm dir) its code .s (text, nonmatchings), recursive; include_path an
      `#include` under `-I src`; regen(root) gen() unprinted, for tools that add, remove or rename a unit or body.
      merged(alias) {member: unit stem} of the units apply merged: locate/home of a member give its unit file.
      A stem (first vram) repeats across overlays: locate/home take the yaml row's segment as `seg`.
      run_files() {body: [(owner, line)]} of the shared unit files (a body two or more groups name; owner = the
      function it defines that names a group member); locate("shared", owner) gives the file; run_file(body).

  layout.py gen [--check]
      -> config/layout.tsv, rows `unit binary overlay system path cu cu_system` sorted (binary, overlay, unit).
         system = the docs/oracle/x6-systems.tsv folders of the unit's rows (leading shared/ or SLUS_013.95/
         stripped; empty, SLUS_013.95 and rock_NN dropped), joined by `,`, else `-`; a shared body takes its members'
         systems. cu = the config/units.tsv unit whose members hold (binary, unit), `held:<home ids>` for a held
         ledger function, else `-`. cu_system = that row's system. No units.tsv: both `-`.
      -> docs/units/placement.tsv, rows `unit names system cause`, one per slus config/units.tsv unit holding an
         admitted name (config/names.tsv function, accepted|provisional, class x6-twin|x4|loadmap|string|xref). A
         name's stem: the longest docs/oracle/x6-stems.tsv glossary stem among its token spans after the verb, else
         the name when it is a system stem, else those tokens. Placed (cause `-`): every name's stem has one system.
         Flat (system `-`): `disagree <name>:<sys>,...`, `no-system <stem>`, `x6 <folder>,...` (X6 folders differ).
         A placed yaml row is `- {start: 0x.., type: c, name: <n>, dir: <system>}`; list_form() reads it as a list row.
         --check writes nothing, lists the differing rows of both, exit 1 when stale.

  layout.py check [--paths] [--selftest] [--waived]
      -> findings `file:line <kind> <text>`, last line `layout: <h> hard-coded paths, <m> misplaced files`; exit 0
         only when every count is 0. h scans tools/**/*.{py,sh,toml,mk,lua}, mk/*.mk, Makefile (not tools/bin,
         __pycache__, fixtures/, this file; comments and .py docstrings skipped) for P1 a literal
         [build/<x>/](src|asm)/<binary folder>/<more> (<more> holds [A-Za-z0-9_{%$(] and is not `include`, the
         split tree's macro folder), P2 a pathlib join descending from "src"/"asm"[/<x>] (not ending in .rglob(); a
         bare "src"/"asm" joined to a quoted literal that is no binary folder is not a unit path), P3 a
         non-recursive .glob() of units. A line ending `layout: other-tree <what>` is not
         counted (--waived lists them). m: a unit file at locate() != home(); a unit or body with no file; a run
         file defining no member of one of its groups; a stray .c under src/; a stale config/layout.tsv or placement.tsv row. --paths: the scan only. --selftest: planted controls in
         .run/layout/selftest/ (the slus ones: a named unit
         left flat, a placeholder and a disagreeing unit in a folder), last line `layout: control OK`.

  layout.py move --overlay <ovlNN[,ovlMM...]> | --binary slus [--units <stem,...>] [--dry-run]
      -> gives each named segment (no dir: yet) `dir: <seg>` and git-mv's its units to home(); --binary: each unit
         whose locate() is not home() (or each listed one) gets the flow row with `dir: <system>` (owner rows too when
         OWNER_DIR), its file and its patches/<p>/ twin git-mv'd, layout.tsv and placement.tsv regenerated.
         Proof first: each unit
         is cpp'd (CPP, CPPFLAGS of mk/slus.mk) at its old path in the real tree and at its new path in a staged tree
         (.run/layout/move/: the units, include/ and src/shared/ symlinked; deleted at the end), `#` and blank
         lines dropped; a difference, a cpp error or an INCLUDE_ASM (its folder string would go stale) refuses with
         nothing written. Last line `move: <k> of <k> units identical, <k> renamed`; --dry-run adds
         `move: dry run, nothing written`.

  layout.py proof --since <rev>
      -> rewrite proof. Changed: `git diff --name-only <rev>` plus untracked files, under the -I dirs of
         CPPFLAGS. Reached: each .c under src/ but not src/shared/ that is changed or quote-includes one, transitively,
         in the include graph of either tree. Each is cpp'd as move does, at <rev> (git archive into
         .run/layout/proof/, deleted at the end) and in the worktree. One line per unit `proof: identical <path>` or
         `proof: differs <path>: line <n>: -<old> | +<new>` (or `only at <rev>|worktree`, `cpp error at ...`); last
         line `proof: <k> of <n> units identical since <rev>`; exit 0 only when k == n.

  layout.py apply --overlay <ovlNN[,ovlMM...]> [--dry-run] | --selftest
      -> merges each config/units.tsv unit of two or more functions that docs/units/dryrun.tsv calls identical into
         src/<alias>/<ovlNN>/<first vram>.c: members in address order, header includes and those of each included
         shared body hoisted (fallback: left in place), each member's defines #undef'd after it. Held: conflict/differ,
         include-asm, included, rodata-order, alias-window <header> (every text identical but enters a header inside
         an alias window, or fails cc1), config/merge-holds.tsv `unit<TAB>cause` rows (cause as given). Proof: the unit's object equals the `ld -r` of the members' (unitmap's pipeline, staged in .run/layout/apply/).
         Then one yaml c row and one .rodata/.data row per unit, git add/rm, layout.tsv, docs/units/merge.tsv. Last
         line `apply: <ovls>: merged <m> of <n> units (<f> functions)...`. A failure writes nothing and exits 1.
         Without unitmap.py it exits 2. --selftest: last line `apply: control OK (9 of 9 caught)`.
"""
import argparse
import ast
import io
import os
import re
import shutil
import subprocess
import sys
import tokenize
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SELF = Path(__file__).resolve()
TSV = "config/layout.tsv"
DEDUP = "config/dedup.us.yaml"
SYSTEMS = "docs/oracle/x6-systems.tsv"
UNITS = "config/units.tsv"
HOLDS = "config/merge-holds.tsv"  # hand-edited `unit<TAB>cause` rows apply holds; no file: no holds
FLAT = ("shared",)  # binaries whose home is today's flat path
STEMS = "docs/oracle/x6-stems.tsv"  # `stem glossary system`, from mmx6 (its first line names the source)
PLACEMENT = "docs/units/placement.tsv"
NAMES = str(Path(UNITS).with_name("names.tsv"))
GAME_CLASSES = ("x6-twin", "x4", "loadmap", "string", "xref")  # the game-name evidence classes, docs/ops/readability.md
OWNER_DIR = False  # True: move gives a placed unit's .rodata/.data owner rows its dir: too (when splat needs it)

SEG = re.compile(r"^  - name: (\w+)")
SEG_FLOW = re.compile(r"^  - \{name: (\w+)(.*)")
SEG_LIST = re.compile(r"^  - \[")
DIR = re.compile(r"^    dir: (\S+)")
FLOW_DIR = re.compile(r"\bdir: ([^,}\s]+)")
CUNIT = re.compile(r"^\s*- \[0x[0-9A-Fa-f]+, c, (\w+)\]")  # list form; a flow row reads through list_form()
FLOW_SUB = re.compile(r"^(\s*- )\{start: (0x[0-9A-Fa-f]+), type: ([.\w]+), name: (\w+)(?:, dir: ([^,}\s]+))?\}")
START = re.compile(r"^    start: (0x[0-9A-Fa-f]+)")
FLOW_START = re.compile(r"\bstart: (0x[0-9A-Fa-f]+)")
LIST_START = re.compile(r"^  - \[(0x[0-9A-Fa-f]+)")
HEX = re.compile(r"[0-9A-F]+$")  # a split stem splat names by its rom offset
MKVAR = re.compile(r"^(\w+) :?= (.*)$")
OPT = re.compile(r"^  (src_path|asm_path|build_path): (\S+)")
BODY = re.compile(r"^\s*body: (\S+)")
MEMBER = re.compile(r"^\s*- \{alias: (\w+),.*\bname: (\w+)[,}]")  # an inline member's line adds `renames: [...]`
MARKER = re.compile(r"layout: other-tree (.+?)\s*$")
FUNC_DEF = re.compile(r"^(?:[A-Za-z_]\w*[ \t*]+)+([A-Za-z_]\w*)\s*\([^;{}]*\)\s*\{", re.M)
ROCK = re.compile(r"rock_\d+$")

_cache = {}


def list_form(line):
    """A placed flow subsegment row `- {start: S, type: T, name: N, dir: D}` as the list row `- [S, T, N]` (dir
    dropped, the rest of the line kept), for readers that parse list rows; any other line unchanged."""
    m = FLOW_SUB.match(line)
    return f"{m.group(1)}[{m.group(2)}, {m.group(3)}, {m.group(4)}]{line[m.end():]}" if m else line


def row_text(lead, start, typ, name, d=None):
    """One subsegment row: the list form, or the flow form when it carries a dir: (splat's dict subsegment)."""
    return f"{lead}{{start: {start}, type: {typ}, name: {name}, dir: {d}}}" if d else f"{lead}[{start}, {typ}, {name}]"


class Yaml:
    def __init__(self, opts, segs, units, starts=(), rdir=None):
        self.opts, self.segs, self.units = opts, segs, units  # segs {name: (dir, line)}; units [(name, seg, line)]
        self.starts = starts  # [(rom start, seg or None)] in yaml order (None: a top-level list segment)
        self.rdir = rdir or {}  # {(type without '.', name): dir} of the flow rows that carry dir: (under the segment's)
        self.segs_of = {}  # {name: [segments declaring it]}: a merged unit's stem, its first vram, repeats across overlays
        for n, s, _ in units:
            self.segs_of.setdefault(n, []).append(s)
        self.seg_of = {n: ss[0] for n, ss in self.segs_of.items() if len(ss) == 1}  # names one segment declares


def _cached(path, parse):
    try:
        st = os.stat(path)
    except FileNotFoundError:
        return None
    key = (str(path), parse.__name__)
    hit = _cache.get(key)
    if hit and hit[0] == (st.st_mtime_ns, st.st_size):
        return hit[1]
    val = parse(Path(path).read_text().splitlines())
    _cache[key] = ((st.st_mtime_ns, st.st_size), val)
    return val


def _parse_yaml(lines):
    opts, segs, units, starts, rdir, cur = {}, {}, [], [], {}, None
    for i, line in enumerate(lines, 1):
        line = line.split("  #")[0].rstrip()
        if (m := FLOW_SUB.match(line)) and m.group(5):
            rdir[(m.group(3).lstrip("."), m.group(4))] = m.group(5)
        line = list_form(line)
        if m := OPT.match(line):
            opts[m.group(1)] = m.group(2)
        elif m := SEG.match(line):
            cur = m.group(1)
            segs[cur] = ["", i]
        elif m := SEG_FLOW.match(line):
            cur = m.group(1)
            d = FLOW_DIR.search(m.group(2))
            segs[cur] = [d.group(1) if d else "", i]
            if s := FLOW_START.search(m.group(2)):
                starts.append((int(s.group(1), 16), cur))
        elif SEG_LIST.match(line):  # top-level list segment or end marker: no dir
            cur = None
            if s := LIST_START.match(line):
                starts.append((int(s.group(1), 16), None))
            if m := CUNIT.match(line):
                units.append((m.group(1), None, i))
        elif cur and (m := DIR.match(line)):
            segs[cur][0] = m.group(1)
        elif cur and (m := START.match(line)):
            starts.append((int(m.group(1), 16), cur))
        elif m := CUNIT.match(line):
            units.append((m.group(1), cur, i))
    return Yaml(opts, {k: tuple(v) for k, v in segs.items()}, units, starts, rdir)


def _yaml_file(alias, root):
    return Path(root) / f"config/splat.{alias}.yaml"


def _yaml(alias, root):
    y = _cached(_yaml_file(alias, root), _parse_yaml)
    return y if y is not None else Yaml({}, {}, [])


def _parse_unit_rows(lines):
    """{(binary, unit id): [members]} of the config/units.tsv `unit` rows of two or more functions."""
    out = {}
    for line in lines:
        c = line.split("\t")
        if c[0] == "unit" and len(c) >= 14 and c[6].isdigit() and int(c[6]) >= 2:
            out[(c[2], c[1])] = c[13].split(",")
    return out


def _merged_at(alias, root=ROOT):
    """{member: (unit stem, segment)} for each multi-function unit of `alias` (config/units.tsv) whose stem, the unit id
    without `_<seg>` (its first vram), is a yaml `c` row in the unit's segment: those members live in that one file.
    A stem may repeat across overlays, so the segment, not the stem alone, names the file."""
    y, cu = _yaml(alias, root), _cached(Path(root) / UNITS, _parse_unit_rows) or {}
    key = ("merged", alias, str(root))
    hit = _cache.get(key)
    if hit and hit[0] is y and hit[1] is cu:
        return hit[2]
    out = {}
    for (b, u), members in cu.items():
        stem, _, seg = u.partition("_")
        segs = y.segs_of.get(stem, [])
        if b == alias and (seg in segs if seg else stem in y.seg_of):
            out.update((m, (stem, seg or y.seg_of[stem])) for m in members)
    _cache[key] = (y, cu, out)
    return out


def merged(alias, root=ROOT):
    """{member: unit stem} of _merged_at (the stem alone; locate/home key the file by (segment, stem))."""
    return {m: stem for m, (stem, _) in _merged_at(alias, root).items()}


def _parse_dedup(lines):
    bodies, body = [], None  # [(body path, line, [(alias, name)])]
    for i, line in enumerate(lines, 1):
        if m := BODY.match(line):
            body = (m.group(1), i, [])
            bodies.append(body)
        elif body and (m := MEMBER.match(line)):
            body[2].append((m.group(1), m.group(2)))
    return bodies


def _dedup(root):
    return _cached(Path(root) / DEDUP, _parse_dedup) or []


def _parse_defs(lines):
    return FUNC_DEF.findall("\n".join(lines))


def run_files(root=ROOT):
    """{run file: [(owner or None, registry line)]} for each body two or more groups name (a shared unit): the owner
    is the function the file defines whose name is one of that group's members."""
    root, reg = Path(root), _dedup(root)
    key = ("runs", str(root))
    hit = _cache.get(key)
    if not (hit and hit[0] is reg):
        by = {}
        for body, ln, members in reg:
            by.setdefault(body, []).append((ln, {n for _, n in members}))
        hit = _cache[key] = (reg, {b: gs for b, gs in by.items() if len(gs) > 1}, None, None)
    defs = tuple(_cached(root / b, _parse_defs) for b in hit[1])  # re-stat: a run file may be written after the registry
    if hit[2] is not None and all(x is y for x, y in zip(defs, hit[2])):
        return hit[3]
    out = {b: [(next((d for d in ds or () if d in names), None), ln) for ln, names in gs]
           for (b, gs), ds in zip(hit[1].items(), defs)}
    _cache[key] = (reg, hit[1], defs, out)
    return out


def run_file(body, root=ROOT):
    """True when `body` (repo-relative) is a shared unit file: writers refuse it (one function per body assumed)."""
    return Path(body).as_posix() in run_files(root)


def aliases(root=ROOT):
    return sorted(p.name.split(".")[1] for p in (Path(root) / "config").glob("splat.*.yaml"))


def segment(alias, name, root=ROOT):
    """Declaring segment of `name`, else the segment its `_<seg>` suffix or `<seg>_` prefix names, else None."""
    y = _yaml(alias, root)
    if name in y.seg_of:
        return y.seg_of[name]
    for s in y.segs:
        if name.endswith("_" + s) or name.startswith(s + "_"):
            return s
    return None


def _dir(alias, name, root, seg=None, typ="c"):  # the segment's dir:, then the `typ` row's own (splat joins them)
    s, y = seg or segment(alias, name, root), _yaml(alias, root)
    return "/".join(d for d in (y.segs[s][0] if s else "", y.rdir.get((typ, name), "")) if d)


def _stem_dir(alias, stem, root, seg=None):
    """Folder of a split stem: `seg`'s dir: when given; else the stem's, `.<type>` dropped, an all-hex stem read as
    the rom offset splat named it by (the segment whose start covers it), any other name as _dir() reads it; then
    the stem's own `<type>` row dir: when it has one."""
    y = _yaml(alias, root)
    base, _, typ = stem.partition(".")
    if seg is None:
        if not HEX.match(base) or len(base) == 8:  # 8 digits: a merged unit's first vram (rom offsets have 6 at most)
            return _dir(alias, base, root, typ=typ or "c")
        seg = next((s for st, s in reversed(y.starts) if st <= int(base, 16)), None)
    return _dir(alias, base, root, seg, typ or "c") if seg in y.segs else ""


def src_root(alias, root=ROOT):
    return Path("src/shared") if alias == "shared" else Path(_yaml(alias, root).opts.get("src_path", f"src/{alias}"))


def asm_root(alias, root=ROOT):
    return Path(_yaml(alias, root).opts.get("asm_path", f"asm/{alias}"))


def locate(alias, name, root=ROOT, seg=None):  # seg: the declaring segment of a yaml row (a stem may repeat across them)
    if alias == "shared":
        owner = {o: b for b, gs in run_files(root).items() for o, _ in gs if o}
        return Path(owner.get(name, f"src/shared/{name}.c"))
    name, seg = _merged_at(alias, root).get(name, (name, seg))
    return src_root(alias, root) / _dir(alias, name, root, seg) / f"{name}.c"


def asm_s(alias, name, root=ROOT, seg=None):
    return asm_root(alias, root) / _stem_dir(alias, name, root, seg) / f"{name}.s"


def nonmatchings(alias, name, root=ROOT):
    return asm_root(alias, root) / "nonmatchings" / _dir(alias, name, root) / name


def data_root(alias, root=ROOT):  # splat's data_path: the non-code split output (recursive walks and path tests only)
    return asm_root(alias, root) / "data"


def data_s(alias, name, root=ROOT, seg=None):
    """`name` is the stem splat writes, without `.s`: `<name>.<type>` for data/rodata (data.py:20), `<name>` for
    textbin/rodatabin (textbin.py:50). The folder is `seg`'s dir: when given, else the stem's (_stem_dir)."""
    return data_root(alias, root) / _stem_dir(alias, name, root, seg) / f"{name}.s"


def obj(alias, name, root=ROOT):
    return Path(f"build/{alias}") / locate(alias, name, root).with_suffix(".o")


def asm_obj(alias, name, root=ROOT, seg=None):
    return Path(f"build/{alias}") / asm_s(alias, name, root, seg).with_suffix(".o")


def split_s(adir):
    """A binary's split code .s under its asm root `adir` (any dir: folders): (text files, nonmatchings files), each
    sorted; data/ and include/ are not code."""
    adir = Path(adir)
    text = sorted(p for p in adir.rglob("*.s") if p.relative_to(adir).parts[0] not in ("data", "include", "nonmatchings"))
    return text, sorted((adir / "nonmatchings").rglob("*.s"))


def include_path(inc, root=ROOT):
    """`#include "<inc>"` (e.g. shared/x.c) resolved under the compiler's `-I src` root."""
    return Path("src") / inc


def regen(root=ROOT):
    """gen() for a tool that added, removed or renamed a unit or body: no printed line; a tree with no config/ is skipped."""
    if (Path(root) / "config").is_dir():
        import contextlib
        with contextlib.redirect_stdout(io.StringIO()):
            gen(root)


def home(alias, name, root=ROOT, seg=None):  # seg as in locate
    if alias != "shared":
        name, seg = _merged_at(alias, root).get(name, (name, seg))
    if alias in FLAT:
        return Path(f"src/{alias}/{name}.c")
    if alias == "slus":  # a unit placed in a system folder (placement()), else flat
        return src_root(alias, root) / _placed(root).get(name, "") / f"{name}.c"
    s = seg or segment(alias, name, root)
    return src_root(alias, root) / (s or "") / f"{name}.c"


def units(alias, root=ROOT):
    if alias == "shared":
        seen, out = set(), []
        for body, _, _ in _dedup(root):
            name = Path(body).stem
            if name not in seen:
                seen.add(name)
                out.append((name, locate("shared", name, root)))
        return out
    return [(n, locate(alias, n, root, s)) for n, s, _ in _yaml(alias, root).units]


# ---- gen ----

def _systems(root):
    out = {}
    p = Path(root) / SYSTEMS
    if not p.exists():
        return out
    for line in p.read_text().splitlines():
        c = line.split("\t")
        if len(c) < 6:
            continue
        f = c[5]
        for pre in ("shared/", "SLUS_013.95/"):
            f = f.removeprefix(pre)
        if f and f != "SLUS_013.95" and not ROCK.match(f):
            out.setdefault((c[0], c[2]), set()).add(f)
    return out


def _units(root):
    """{(binary, function): (cu, cu_system)} from config/units.tsv, read as data (unitmap is private, C0396)."""
    out = {}
    p = Path(root) / UNITS
    if not p.exists():
        return out
    for line in p.read_text().splitlines():
        c = line.split("\t")
        if line.startswith("#") or len(c) < 14:
            continue
        if c[0] == "unit":
            for m in c[13].split(","):
                out[(c[2], m)] = (c[1], c[11])
        elif c[0] == "held":
            out[(c[2], c[1])] = ("held:" + c[10], c[11])
    return out


# Adapted from mmx6 tools/mmx6/layout.py glossary_stems, slus_systems, system_of (f0ad66bb2)

def _admitted(root):
    """{name} of the config/names.tsv slus function rows, accepted or provisional, of a game evidence class."""
    p, out = Path(root) / NAMES, set()
    for line in p.read_text().splitlines() if p.exists() else ():
        c = line.split("\t")
        if (len(c) >= 7 and c[0] == "function" and c[1] == "slus" and c[5] in ("accepted", "provisional")
                and c[6].split(":")[0] in GAME_CLASSES):
            out.add(c[4])
    return out


def _stems(root):
    """(glossary stems, {stem: system}) of docs/oracle/x6-stems.tsv."""
    p, glos, sysm = Path(root) / STEMS, set(), {}
    for line in p.read_text().splitlines() if p.exists() else ():
        c = line.split("\t")
        if line.startswith("#") or len(c) < 3:
            continue
        if c[1] == "y":
            glos.add(c[0])
        if c[2] != "-":
            sysm[c[0]] = c[2]
    return glos, sysm


def name_stem(name, glos, sysm):
    """The longest glossary stem among the token spans after the verb (ties: more tokens, more chars, earliest);
    else the name itself when it is a system stem; else the tokens after the verb joined (a one-token name: itself)."""
    toks = name.split("_")[1:]
    spans = [(j - i, len(s), -i, s) for i in range(len(toks)) for j in range(i + 1, len(toks) + 1)
             if (s := "_".join(toks[i:j])) in glos]
    if spans:
        return max(spans)[3]
    return name if name in sysm else ("_".join(toks).strip("_") or name)


def placement(root=ROOT):
    """[(unit id, [names], system, cause, [members])] for each slus config/units.tsv unit holding an admitted name: system the one
    system of all its names, cause '-'; else system '-' and cause `disagree <name>:<sys>,...`, `no-system <stem>`
    or `x6 <folder>,...` (the X6 folders of its members, docs/oracle/x6-systems.tsv, are not that one system)."""
    p = Path(root) / UNITS
    adm, (glos, sysm), x6, out = _admitted(root), _stems(root), _systems(root), []
    for line in p.read_text().splitlines() if p.exists() else ():
        c = line.split("\t")
        if c[0] != "unit" or len(c) < 14 or c[2] != "slus":
            continue
        members = c[13].split(",")
        names = [m for m in members if m in adm]
        if not names:
            continue
        stems = {n: name_stem(n, glos, sysm) for n in names}
        got = {n: sysm.get(s) for n, s in stems.items()}
        systems = set(got.values())
        folders = set().union(*(x6.get(("slus", m), set()) for m in members))
        if len(systems) > 1:
            cause = "disagree " + ",".join(f"{n}:{s or '-'}" for n, s in got.items())
        elif None in systems:
            cause = "no-system " + ",".join(dict.fromkeys(stems.values()))
        elif folders and folders != systems:
            cause = "x6 " + ",".join(sorted(folders))
        else:
            out.append((c[1], names, systems.pop(), "-", members))
            continue
        out.append((c[1], names, "-", cause, members))
    return out


def _placed(root):
    """{member or unit stem: system} of the placed units of placement(), cached on its inputs' stat."""
    paths = [Path(root) / f for f in (NAMES, UNITS, STEMS, SYSTEMS)]
    key = ("placed", str(root))
    st = tuple((s.st_mtime_ns, s.st_size) if (s := p.stat() if p.exists() else None) else None for p in paths)
    hit = _cache.get(key)
    if hit and hit[0] == st:
        return hit[1]
    out = {}
    for u, _, s, cause, members in placement(root):
        if cause == "-":
            out.update((n, s) for n in [u.partition("_")[0], *members])
    _cache[key] = (st, out)
    return out


def rows(root=ROOT):
    sysm, unitm, out = _systems(root), _units(root), []

    def image(alias, name):
        return "slus" if alias == "slus" else segment(alias, name, root)

    for a in aliases(root):
        held_by = {}  # a merged unit's (segment, stem) -> its members, each keeping its own row
        for m, (stem, sg) in _merged_at(a, root).items():
            held_by.setdefault((sg, stem), []).append(m)
        for u, sg, _ in _yaml(a, root).units:
            for n in held_by.get((sg, u), [u]):
                ns = sg or segment(a, n, root)
                ov = "-" if a == "slus" else (ns or "-")
                s = sysm.get(("slus" if a == "slus" else ns, n), set())
                cu = unitm.get((a, n), ("-", "-"))
                out.append((n, a, ov, ",".join(sorted(s)) or "-", str(locate(a, n, root, sg))) + cu)
    seen, of = set(), {}
    for body, _, members in _dedup(root):  # a shared unit file: one row, its groups' members together
        of.setdefault(Path(body).stem, []).extend(members)
    for body, _, _ in _dedup(root):
        n = Path(body).stem
        if n in seen:
            continue
        seen.add(n)
        members = of[n]
        s = set().union(*(sysm.get((image(a, m), m), set()) for a, m in members)) if members else set()
        out.append((n, "shared", "-", ",".join(sorted(s)) or "-", str(locate("shared", n, root)), "-", "-"))
    return sorted(out, key=lambda r: (r[1], r[2], r[0]))


HEADER = ("# config/layout.tsv is generated by tools/build/layout.py gen, so do not edit it by hand.\n"
          "# inputs: config/splat.*.yaml, config/dedup.us.yaml, docs/oracle/x6-systems.tsv, config/units.tsv\n"
          "# unit\tbinary\toverlay\tsystem\tpath\tcu\tcu_system\n")


PLACEMENT_HEADER = (f"# {PLACEMENT} is generated by tools/build/layout.py gen, so do not edit it by hand.\n"
                    f"# inputs: {NAMES}, {UNITS}, {STEMS}, {SYSTEMS}\n"
                    "# unit\tnames\tsystem\tcause\n")


def placement_rows(root=ROOT):
    return [(u, ",".join(ns), s, cause) for u, ns, s, cause, _ in placement(root)]


def _stale_table(p, want, key, required=True):
    """[(line, text)] for each row of the table at `p` that differs from `want` {key: line}; `key` reads a row's key.
    A missing file is stale when `required` or `want` has rows."""
    if not p.exists():
        return [(1, f"stale file missing ({len(want)} rows)")] if required or want else []
    have, last = {}, 0
    for i, line in enumerate(p.read_text().splitlines(), 1):
        last = i
        if line.startswith("#") or not line.strip():
            continue
        have[key(line.split("\t"))] = (i, line)
    out = []
    for k in sorted(set(want) | set(have)):
        if k not in have:
            out.append((last + 1, f"stale missing row {want[k]!r}"))
        elif k not in want:
            out.append((have[k][0], f"stale extra row {have[k][1]!r}"))
        elif have[k][1] != want[k]:
            out.append((have[k][0], f"stale want {want[k]!r}"))
    return sorted(out)


def stale(root=ROOT):
    """[(file, line, text)] for each config/layout.tsv row that differs from rows(), keyed by (binary, overlay, unit),
    then each docs/units/placement.tsv row that differs from placement_rows(), keyed by unit."""
    lay = {(r[1], r[2], r[0]): "\t".join(r) for r in rows(root)}
    out = [(TSV, ln, t) for ln, t in _stale_table(Path(root) / TSV, lay, lambda c: (
        c[1] if len(c) > 1 else "", c[2] if len(c) > 2 else "", c[0]))]
    pl = {r[0]: "\t".join(r) for r in placement_rows(root)}
    return out + [(PLACEMENT, ln, t) for ln, t in _stale_table(Path(root) / PLACEMENT, pl, lambda c: c[0], False)]


def gen(root=ROOT, check=False):
    if check:
        diff = stale(root)
        for f, ln, text in diff:
            print(f"{f}:{ln} {text}")
        print(f"layout: gen --check {len(diff)} stale rows")
        return 1 if diff else 0
    body = "".join("\t".join(r) + "\n" for r in rows(root))
    (Path(root) / TSV).write_text(HEADER + body)
    print(f"layout: wrote {TSV} {body.count(chr(10))} rows")
    pl = "".join("\t".join(r) + "\n" for r in placement_rows(root))
    if pl or (Path(root) / PLACEMENT).exists():
        (Path(root) / PLACEMENT).parent.mkdir(parents=True, exist_ok=True)
        (Path(root) / PLACEMENT).write_text(PLACEMENT_HEADER + pl)
        print(f"layout: wrote {PLACEMENT} {pl.count(chr(10))} rows")
    return 0


# ---- check: hard-coded paths ----

EXTS = {".py", ".sh", ".toml", ".mk", ".lua"}


def scan_files(root):
    root = Path(root)
    out = []
    for p in (root / "tools").rglob("*"):
        rel = p.relative_to(root)
        if (p.suffix not in EXTS or not p.is_file() or rel.parts[:2] == ("tools", "bin")
                or "__pycache__" in rel.parts or "fixtures" in rel.parts or p.resolve() == SELF):
            continue
        out.append(p)
    out += [p for p in (root / "mk").glob("*.mk")]
    if (root / "Makefile").is_file():
        out.append(root / "Makefile")
    return sorted(set(out))


def _blank(lines, l0, c0, l1, c1):
    for ln in range(l0, l1 + 1):
        s = lines[ln - 1]
        a = c0 if ln == l0 else 0
        b = c1 if ln == l1 else len(s)
        lines[ln - 1] = s[:a] + " " * (b - a) + s[b:]


def code_lines(path):
    """Code text per line: comments (and .py docstrings, expression-statement strings) blanked."""
    text = path.read_text(errors="replace")
    lines = text.split("\n")
    if path.suffix == ".py":
        try:
            for t in tokenize.generate_tokens(io.StringIO(text).readline):
                if t.type == tokenize.COMMENT:
                    _blank(lines, t.start[0], t.start[1], t.end[0], t.end[1])
            for node in ast.walk(ast.parse(text)):
                if isinstance(node, ast.Expr) and (isinstance(node.value, ast.JoinedStr) or (
                        isinstance(node.value, ast.Constant) and isinstance(node.value.value, str))):
                    _blank(lines, node.lineno, node.col_offset, node.end_lineno, node.end_col_offset)
            return lines
        except (SyntaxError, tokenize.TokenError):
            pass
    cm = "--" if path.suffix == ".lua" else "#"
    pat = re.compile(r"(?:^|(?<=\s))" + re.escape(cm) + r".*$")
    return [pat.sub("", s) for s in lines]


def _binaries(root):
    names = {"slus", "rockx5", "shared", *aliases(root)}
    for p in (Path(root) / "tools").rglob("splat.*.yaml"):
        if "fixtures" in p.parts:
            names.add(p.name.split(".")[1])
    return names


def patterns(root):
    bf = "|".join(sorted(map(re.escape, _binaries(root)))) + r"|\{[^}/]*\}|%s|\$\([^)]*\)|\$\{[^}]*\}|\([^)]*\)"
    p1 = re.compile(r"(?<![\w.-])(?:build/[^/\s\"']+/)?(?:src|asm)/(?:" + bf + r")/([^\s\"'`,;)\]]*)")
    p2 = re.compile(r"(?<![\w])[fFrRbB]{0,2}([\"'])(?:src|asm)((?:/[^\"'/\s]+)?)\1\s*/(?![/=])")
    p3 = re.compile(r"\.glob\(\s*[fFrR]{0,2}([\"'])([^\"']*)\1")
    return p1, p2, p3, _binaries(root)


NAMECH = re.compile(r"[A-Za-z0-9_{%$(]")
NEXT_LIT = re.compile(r"\s*[rRbB]{0,2}([\"'])([^\"'{]*)\1")


def _p1(more):  # R-a: <more> holds a name character or substitution; R-b: the split tree's macro include folder
    return bool(more) and not more.startswith(("%", "$*")) and bool(NAMECH.search(more)) and more != "include"


def _p2(m, code, bins):  # R-c: bare "src"/"asm" then a quoted literal that is no binary folder: no unit lives there
    if ".rglob(" in code[m.end():]:
        return False
    if not m.group(2) and (n := NEXT_LIT.match(code, m.end())) and n.group(2).split("/")[0] not in bins:
        return False
    return True


def hits(code, is_py, pats):
    p1, p2, p3, bins = pats
    kinds = []
    if any(_p1(m.group(1)) for m in p1.finditer(code)):
        kinds.append("P1")
    if is_py and any(_p2(m, code, bins) for m in p2.finditer(code)):
        kinds.append("P2")
    if any("**" not in m.group(2) and (m.group(2).endswith((".c", ".s", ".o")) or "nonmatchings/*" in m.group(2))
           for m in p3.finditer(code)):
        kinds.append("P3")
    return kinds


def scan(root=ROOT):
    """-> (findings [(file, line, kind, text)], waived [(file, line, what)])."""
    root = Path(root)
    pats, found, waived = patterns(root), [], []
    for p in scan_files(root):
        rel = p.relative_to(root)
        raw = p.read_text(errors="replace").split("\n")
        for i, (code, line) in enumerate(zip(code_lines(p), raw), 1):
            if m := MARKER.search(line):
                waived.append((rel, i, m.group(1)))
                continue
            if kinds := hits(code, p.suffix == ".py", pats):
                found.append((rel, i, ",".join(kinds), line.strip()[:140]))
    return found, waived


# ---- check: misplaced files ----

def misplaced(root=ROOT):
    """-> (printed lines, m). (a) unit file at locate() != home(); (b) no file at locate(); (c) stray .c; (d) stale."""
    root = Path(root)
    out, m, known, moved = [], 0, set(), {}
    for a in aliases(root):
        y = _yaml(a, root)
        for n, s, ln in y.units:
            loc = locate(a, n, root, s)
            known.add(loc)
            if not (root / loc).is_file():
                out.append(f"config/splat.{a}.yaml:{ln} missing {loc}")
                m += 1
            elif loc != home(a, n, root, s):
                moved.setdefault((a, s), []).append((loc, home(a, n, root, s)))
    for (a, s), files in sorted(moved.items(), key=lambda kv: (kv[0][0], kv[0][1] or "")):
        m += len(files)
        if len(files) > 20:
            ln = _yaml(a, root).segs[s][1] if s else 1
            dests = {}
            for _, h in files:
                dests[h.parent] = dests.get(h.parent, 0) + 1
            out += [f"config/splat.{a}.yaml:{ln} misplaced {k} {s} units not in {d}/" for d, k in sorted(dests.items())]
        else:
            out += [f"{loc}:1 misplaced home {h}" for loc, h in files]
    for body, ln, _ in _dedup(root):
        loc = locate("shared", Path(body).stem, root)
        known.add(loc)
        if not (root / loc).is_file():
            out.append(f"{DEDUP}:{ln} missing {loc}")
            m += 1
    for body, gs in run_files(root).items():
        for owner, ln in gs:
            if owner is None and (root / body).is_file():
                out.append(f"{DEDUP}:{ln} run file {body} defines no member of this group")
                m += 1
    if (root / "src").is_dir():
        for p in sorted((root / "src").rglob("*.c")):
            rel = p.relative_to(root)
            if rel not in known:
                out.append(f"{rel}:1 stray no yaml c unit or shared body")
                m += 1
    for f, ln, text in stale(root):
        out.append(f"{f}:{ln} {text}")
        m += 1
    return out, m


def check(root=ROOT, paths_only=False):
    """-> (lines, h, m, waived); m is None with paths_only."""
    found, waived = scan(root)
    lines = [f"{f}:{ln} {k} {t}" for f, ln, k, t in found]
    m = None
    if not paths_only:
        mis, m = misplaced(root)
        lines += mis
    return lines, len(found), m, waived


def summary(h, m):
    return f"layout: {h} hard-coded paths" + ("" if m is None else f", {m} misplaced files")


# ---- move ----

def _mkvars(root=ROOT):
    """`NAME := value` lines of mk/slus.mk, earlier $(NAME)s expanded (CPP, CPPFLAGS)."""
    v = {}
    for line in (Path(root) / "mk/slus.mk").read_text().splitlines():
        if m := MKVAR.match(line):
            v[m.group(1)] = re.sub(r"\$\((\w+)\)", lambda r: v.get(r.group(1), r.group(0)), m.group(2).strip())
    return v


def _cpp_text(cmd, cwd, path):
    r = subprocess.run(cmd + [str(path)], cwd=cwd, capture_output=True)
    if r.returncode or r.stderr:
        return None
    return "\n".join(ln for ln in r.stdout.decode("latin-1").splitlines() if ln.strip() and not ln.startswith("#"))


def _slus_plan(root, binary, only):
    """-> (plan [(binary, seg, [(old, new, name)])], refusal or None): the units of `binary` whose locate() is not
    their home(), or the `only` stems (each a c row with somewhere to go)."""
    rows_ = _yaml(binary, root).units
    if only:
        known = {n for n, _, _ in rows_}
        if bad := [n for n in only if n not in known]:
            return [], f"move: refused -- {','.join(bad)} not a {binary} c row"
    mv = [(locate(binary, n, root, s), home(binary, n, root, s), n) for n, s, _ in rows_ if not only or n in only]
    mv = [r for r in mv if r[0] != r[1]]
    if only and len(mv) != len(set(only)):
        return [], f"move: refused -- {len(set(only)) - len(mv)} of the listed units already home"
    if not mv:
        return [], f"move: refused -- {binary} has no unit to move"
    return [(binary, None, mv)], None


def _slus_yaml(lines, mv, root, binary):
    """Each moved unit's c row (and, with OWNER_DIR, its .rodata/.data rows) in the flow form with its home's folder
    as dir: (the list form when home is flat); a trailing comment is kept."""
    base = src_root(binary, root)
    want = {n: (str(h.parent.relative_to(base)) if h.parent != base else None) for _, h, n in mv}
    for i, ln in enumerate(lines):
        lf = list_form(ln.rstrip("\n"))
        m = C_ROW.match(lf) or (OWNER_DIR and DATA_ROW.match(lf))
        if m and m.group(m.lastindex) in want:
            typ = "c" if m.re is C_ROW else m.group(3)
            lines[i] = row_text(m.group(1)[:-1], m.group(2), typ, m.group(m.lastindex), want[m.group(m.lastindex)]) \
                + lf[m.end():] + "\n"
    return lines


def _twins(root, binary, old, new):
    """[(old, new)] repo-relative for each patch twin (mk/patches.mk: patches/<p>/<path under src/>) of `old`."""
    top, pd = src_root(binary, root).parent, Path("patches")
    return [(pd / d.name / old.relative_to(top), pd / d.name / new.relative_to(top))
            for d in sorted((Path(root) / pd).iterdir()) if (d / old.relative_to(top)).is_file()] \
        if (Path(root) / pd).is_dir() else []


def move(root, ovls, dry_run=False, mk_root=ROOT, binary=None, only=None):
    """-> (printed lines, rc). Nothing is written unless every unit of every segment in `ovls` (or each unit of
    `binary` not at home, or the `only` ones) is proved identical."""
    root = Path(root)
    plan, out = [], []  # [(alias, seg, [(old, new)])]
    if binary:
        plan, why = _slus_plan(root, binary, only)
        if why:
            return [why], 1
    for s in ovls:
        hit = [a for a in aliases(root) if s in _yaml(a, root).segs]
        if len(hit) != 1:
            return [f"move: refused -- segment {s} in {len(hit)} yaml files"], 1
        a, y = hit[0], _yaml(hit[0], root)
        if y.segs[s][0]:
            return [f"move: refused -- {s} already has dir: {y.segs[s][0]}"], 1
        mv = [(locate(a, n, root), home(a, n, root)) for n, sg, _ in y.units if sg == s]
        mv = [(o, n) for o, n in mv if o != n]
        if not mv:
            return [f"move: refused -- {s} has no unit to move"], 1
        plan.append((a, s, mv))
    pairs = [(r[0], r[1]) for _, _, mv in plan for r in mv]
    bad = [f"move: missing {o}" for o, _ in pairs if not (root / o).is_file()]
    bad += [f"move: exists {n}" for _, n in pairs if (root / n).exists()]
    if bad:
        return bad[:20] + [f"move: refused -- 0 of {len(pairs)} units identical, nothing written"], 1
    v = _mkvars(mk_root)
    cmd = [str(mk_root / v["CPP"])] + v["CPPFLAGS"].split()
    stage = mk_root / ".run/layout/move"
    if stage.exists():
        shutil.rmtree(stage)
    try:
        for d in ("include", "src/shared"):
            if (root / d).is_dir():
                (stage / d).parent.mkdir(parents=True, exist_ok=True)
                (stage / d).symlink_to((root / d).resolve(), target_is_directory=True)
        for o, n in pairs:
            (stage / n).parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(root / o, stage / n)

        def one(pair):
            o, n = pair
            if "INCLUDE_ASM" in (root / o).read_text(errors="replace"):
                return f"move: include_asm {o}"
            a, b = _cpp_text(cmd, root, o), _cpp_text(cmd, stage, n)
            if a is None or b is None:
                return f"move: cpp error {o if a is None else n}"
            return None if a == b and a else f"move: differs {o} -> {n}"

        with ThreadPoolExecutor(16) as ex:
            res = list(ex.map(one, pairs))
    finally:
        shutil.rmtree(stage, ignore_errors=True)
    bad = [r for r in res if r]
    same = len(pairs) - len(bad)
    if bad:
        return bad[:20] + [f"move: refused -- {same} of {len(pairs)} units identical, nothing written"], 1
    if dry_run:
        return [f"move: {same} of {len(pairs)} units identical, {len(pairs)} renamed", "move: dry run, nothing written"], 0
    lst = mk_root / ".run/layout/move.list"
    lst.parent.mkdir(parents=True, exist_ok=True)
    try:
        by = {}  # {dest folder: [old path]}: a segment's units share one, a binary's units go to their systems
        for _, _, mv in plan:
            for o, n, *_ in mv:
                by.setdefault(n.parent, []).append(o)
                for to, tn in _twins(root, binary, o, n) if binary else ():
                    by.setdefault(tn.parent, []).append(to)
        for dest, olds in by.items():
            (root / dest).mkdir(parents=True, exist_ok=True)
            lst.write_text("".join(f"{o}\n" for o in olds))
            subprocess.run(["xargs", "-a", str(lst), "sh", "-c", f'git mv -- "$@" {dest}/', "sh"], cwd=root, check=True)
    finally:
        lst.unlink(missing_ok=True)
    if binary:
        yp = _yaml_file(binary, root)
        yp.write_text("".join(_slus_yaml(yp.read_text().splitlines(keepends=True), plan[0][2], root, binary)))
    for a in sorted({a for a, s, _ in plan if s}):
        yp = _yaml_file(a, root)
        lines = yp.read_text().splitlines(keepends=True)
        for s in sorted((s for b, s, _ in plan if b == a and s), key=lambda s: -_yaml(a, root).segs[s][1]):
            i = _yaml(a, root).segs[s][1]  # 1-based segment line; dir: goes before its `    subsegments:`
            while lines[i].rstrip("\n") != "    subsegments:":
                i += 1
            lines.insert(i, f"    dir: {s}\n")
        yp.write_text("".join(lines))
    regen(root)
    moved = sum(1 for o, n in pairs if (root / n).is_file() and not (root / o).exists())
    return [f"move: {same} of {len(pairs)} units identical, {moved} renamed"], 0 if moved == len(pairs) else 1


# ---- apply ----

MERGE_TSV = "docs/units/merge.tsv"
MERGE_HEADER = ("# docs/units/merge.tsv is generated by tools/build/layout.py apply, so do not edit it by hand.\n"
                "# unit\tbinary\toverlay\tcount\tstatus\tcause\n")
APPLY_STAGE = ".run/layout/apply"
APPLY_FIXTURES = Path("tools/build/fixtures/layout/apply")
INC_LINE = re.compile(r'^\s*#\s*include\s+[<"]([^>"]+)[>"]')
UNDEF = re.compile(r"^#\s*undef\s+(\w+)", re.M)
DATA_ROW = re.compile(r"^(\s*- \[)(0x[0-9A-Fa-f]+), (\.rodata|\.data), (\w+)\]")
C_ROW = re.compile(r"^(\s*- \[)(0x[0-9A-Fa-f]+), c, (\w+)\]")


def _row_dir(line):
    return (m := FLOW_SUB.match(line)) and m.group(5)


def hoistable(line):  # a header include, which apply moves to the top of a merged unit
    m = INC_LINE.match(line)
    return bool(m) and not (m.group(1).startswith("shared/") and m.group(1).endswith(".c"))


def _undefs(body, defines):
    """`#undef` lines for each name `body` leaves defined: its last #define comes after its last #undef."""
    out = []
    for n in dict.fromkeys(defines.findall(body)):
        last_def = max(m.start() for m in defines.finditer(body) if m.group(1) == n)
        last_undef = max((m.start() for m in UNDEF.finditer(body) if m.group(1) == n), default=-1)
        if last_def > last_undef:
            out.append(f"#undef {n}\n")
    return "".join(out)


def merge_text(bodies, defines, hoist=True, shared=None):
    """One unit's text from its member texts in address order. hoist: header includes (not shared/*.c) move to the
    top, once, in first-seen order; with `shared` (include -> body path), so do the header includes of each shared
    body a member includes, as the body writes them. Else they stay in place and a later duplicate is dropped. Each
    member but the last is followed by an #undef of what it leaves defined."""
    head, seen, parts = [], set(), []
    for i, body in enumerate(bodies):
        keep = []
        for line in body.splitlines():
            if hoist and shared and (m := INC_LINE.match(line)) and not hoistable(line):
                for bl in shared(m.group(1)).read_text(encoding="latin-1").splitlines():
                    if hoistable(bl) and not INC_LINE.match(bl).group(1).endswith(".c") and bl.strip() not in seen:
                        seen.add(bl.strip())
                        head.append(bl.strip() + "\n")
            if hoistable(line):
                key = line.strip()
                if key in seen:
                    continue
                seen.add(key)
                if hoist:
                    head.append(key + "\n")
                    continue
            keep.append(line)
        text = re.sub(r"\n{3,}", "\n\n", "\n".join(keep).strip("\n") + "\n")
        parts.append(text + (_undefs(body, defines) if i < len(bodies) - 1 else ""))
    return "".join(head) + ("\n" if head else "") + "\n".join(parts)


ALIAS = re.compile(r"^#\s*define\s+(\w+)\s+([A-Za-z_]\w*)\s*$")
LINEMARK = re.compile(r'^# (\d+) "([^"]+)"(.*)$')


def _alias_window(cpp, unit_c, text):
    """The first header whose first entry, in the cpp linemarkers of `unit_c` (holding `text`), comes from a unit line
    inside an alias window (`#define <owner> <site>` .. `#undef <owner>` or end, around a shared/*.c include), else None."""
    lines = text.splitlines()
    incs = [i + 1 for i, ln in enumerate(lines) if INC_LINE.match(ln)]
    wins = []
    for i, ln in enumerate(lines):
        if m := ALIAS.match(ln):
            end = next((j + 1 for j in range(i + 1, len(lines))
                        if (u := UNDEF.match(lines[j])) and u.group(1) == m.group(1)), len(lines) + 1)
            if any(INC_LINE.match(lines[j]) and not hoistable(lines[j]) for j in range(i + 1, end - 1)):
                wins.append((i + 1, end))
    if not wins:
        return None
    r = subprocess.run(cpp + [str(unit_c)], cwd=ROOT, capture_output=True)
    depth, seen, pending, first = 0, set(), [], None
    for ln in r.stdout.decode("latin-1").splitlines():
        if not (m := LINEMARK.match(ln)):
            continue
        flags = m.group(3).split()
        if "1" in flags:
            depth += 1
            if m.group(2) not in seen and not m.group(2).endswith(".c"):
                seen.add(m.group(2))
                pending.append(m.group(2))
        elif "2" in flags:
            depth -= 1
            if depth == 0:
                at = max((n for n in incs if n <= int(m.group(1))), default=0)
                if any(a < at < e for a, e in wins) and pending:
                    first = first or pending[0]
                pending = []
    if first is None:
        return None
    p = Path(first)
    return str(p.relative_to(ROOT)) if p.is_absolute() and p.is_relative_to(ROOT) else first


def _prove_unit(um, tools, unit_c, out, srcs, texts, binary):
    """-> (index of the first of `texts` whose object equals the `ld -r` of the members' objects and that has no
    _alias_window header, None) or (None, `alias-window <header>` of the first such text when every text fails only
    that check or cc1 (a hoisted header declaring a name above its alias), else the failing stage or first differing
    section of the last other failure). `unit_c` is where each text is compiled (in a
    mirror of the unit's folder, so quote includes resolve as in place). `out` holds the objects. All paths are absolute.
    The members link as `binary` links them (unitmap.merge_ld)."""
    out.mkdir(parents=True, exist_ok=True)
    unit_c.parent.mkdir(parents=True, exist_ok=True)
    objs = []
    for k, s in enumerate(srcs):
        o = out / f"member{k}.o"
        if err := um.dry_compile(tools, s, o):
            return None, f"member {err[0]}"
        objs.append(str(o))
    (out / "merge.ld").write_text(um.merge_ld(binary))
    r = subprocess.run(tools["ld"] + ["-r", "-T", str(out / "merge.ld"), "-o", str(out / "merged.o")] + objs,
                       cwd=um.ROOT, capture_output=True)
    if r.returncode:
        return None, "ld"
    why, alias, other = "-", [], set()
    for k, text in enumerate(texts):
        unit_c.write_text(text, encoding="latin-1")
        if err := um.dry_compile(tools, unit_c, out / "unit.o"):
            why = err[0]
            other.add(why)
            continue
        cls, sec, _ = um.dry_compare(out / "unit.o", out / "merged.o")
        if cls == "identical" and not (h := _alias_window(tools["cpp"], unit_c, text)):
            return k, None
        if cls == "identical":
            alias.append(f"alias-window {h}")
        else:
            why = sec
            other.add(why)
    return None, alias[0] if alias and other <= {"cc1"} else why


def _import_unitmap():
    try:
        import unitmap
    except ImportError:
        return None
    return unitmap


def _yaml_edits(lines, stem, members):
    """{line index: new line or None (deleted)} joining `members`' c rows into one `c, <stem>` row and their
    .rodata/.data owner rows into one row per type at the first. None when the rows are not one adjacent run each."""
    c_at = {m.group(3): i for i, ln in enumerate(lines) if (m := C_ROW.match(list_form(ln)))}
    idx = [c_at.get(n) for n in members]
    if None in idx or idx != list(range(idx[0], idx[0] + len(idx))):
        return None
    m = C_ROW.match(list_form(lines[idx[0]]))
    edits = {idx[0]: row_text(m.group(1)[:-1], m.group(2), "c", stem, _row_dir(lines[idx[0]])) + "\n",
             **{i: None for i in idx[1:]}}
    by_type = {}
    for i, ln in enumerate(lines):
        if (m := DATA_ROW.match(list_form(ln))) and m.group(4) in members:
            by_type.setdefault(m.group(3), []).append(i)
    for typ, rows in by_type.items():
        if rows != list(range(rows[0], rows[0] + len(rows))):
            return None
        m = DATA_ROW.match(list_form(lines[rows[0]]))
        edits[rows[0]] = row_text(m.group(1)[:-1], m.group(2), typ, stem, _row_dir(lines[rows[0]])) + "\n"
        edits.update((i, None) for i in rows[1:])
    return edits


def apply(root, ovls=(), dry_run=False, batch=None):
    """-> (printed lines, rc). Merges each identical multi-function unit of `ovls`, or of `batch` (binary, first, last:
    the units of that binary whose first address lies in first..last), into `<first vram>.c`. Nothing is written
    unless every unit not held is proved (else rc 1), and nothing at all under dry_run. rc 2: no unitmap."""
    root = Path(root)
    um = _import_unitmap()
    if um is None:
        return ["apply: needs tools/build/unitmap.py (private), not found"], 2
    dry = {}
    for ln in (root / um.DRYRUN_TSV).read_text().splitlines():
        c = ln.split("\t")
        if not ln.startswith("#") and len(c) >= 7:
            dry[(c[0], c[1])] = c[4:7]
    units = []  # [(unit, binary, overlay, members)]
    for ln in (root / UNITS).read_text().splitlines():
        c = ln.split("\t")
        if c[0] != "unit" or len(c) < 14 or int(c[6]) < 2:
            continue
        if (c[3] in ovls if batch is None
                else c[2] == batch[0] and batch[1] <= int(c[1].partition("_")[0], 16) <= batch[2]):
            units.append((c[1], c[2], c[3], c[13].split(",")))
    v = _mkvars(root)
    flags = v["CPPFLAGS"].split()
    idirs = [Path(flags[i + 1]) for i, f in enumerate(flags[:-1]) if f == "-I"]
    top = [str(d) for d in idirs if (root / d).is_dir()]
    included = set().union(*_inc_graph(root, top, idirs).values()) if units else set()
    ylines = {b: _yaml_file(b, root).read_text().splitlines(keepends=True) for b in {b for _, b, _, _ in units}}
    hp = root / HOLDS
    holds = dict(ln.split("\t", 1) for ln in (hp.read_text().splitlines() if hp.is_file() else [])
                 if "\t" in ln and not ln.startswith("#"))
    status, work, edits = {}, [], {}
    for u, b, ov, members in units:
        srcs = [locate(b, n, root) for n in members]
        stem = u.partition("_")[0]
        cls = dry.get((u, b), ["missing", "-", "-"])
        if len(set(srcs)) == 1:
            status[u] = ("merged", "-")
            continue
        if u in holds:
            status[u] = ("held", holds[u].strip())
            continue
        if cls[0] != "identical":
            status[u] = ("held", " ".join(cls))
            continue
        texts = [(root / s).read_text(encoding="latin-1") for s in srcs]
        why = ("include-asm" if any("INCLUDE_ASM" in t for t in texts)
               else "included" if any(s in included for s in srcs) else None)
        e = None if why else _yaml_edits(ylines[b], stem, members)
        if why or e is None:
            status[u] = ("held", f"identical - {why or 'rodata-order'}")
            continue
        dest = src_root(b, root) / _dir(b, members[0], root) / f"{stem}.c"
        work.append((u, b, dest, srcs, texts, e))
    stage = ROOT / APPLY_STAGE
    shutil.rmtree(stage, ignore_errors=True)
    tools = {b: um.dry_tools(b) for b in {w[1] for w in work}}
    miss = next((x for t in tools.values() if (x := um.dry_missing_tool(t))), None)
    if miss:
        return [f"apply: FAIL: missing tool {miss}", "apply: FAIL: nothing written"], 1
    for d in {w[2].parent for w in work}:
        (stage / d).mkdir(parents=True, exist_ok=True)
        for p in (root / d).iterdir():
            (stage / d / p.name).symlink_to(p.resolve())

    def one(w):
        u, b, dest, srcs, texts, _ = w
        tx = [merge_text(texts, um.DEFINE, shared=lambda inc: root / include_path(inc, root)),
              merge_text(texts, um.DEFINE, hoist=False)]
        k, why = _prove_unit(um, tools[b], stage / dest, stage / "obj" / u, [root / s for s in srcs], tx, b)
        return k, why, tx

    with ThreadPoolExecutor(16) as ex:
        res = list(ex.map(one, work))
    out = [f"apply: FAIL {w[0]}: {why}" for w, (k, why, _) in zip(work, res)
           if k is None and not why.startswith("alias-window ")]
    if out:
        return out + [f"apply: FAIL: nothing written (scratch kept in {APPLY_STAGE})"], 1
    out = [f"apply: fallback {w[0]}: includes in place" for w, (k, _, _) in zip(work, res) if k == 1]
    shutil.rmtree(stage, ignore_errors=True)
    for w, (k, why, _) in zip(work, res):
        status[w[0]] = ("merged", "-") if k is not None else ("held", f"identical - {why}")
    keep = [i for i, r in enumerate(res) if r[0] is not None]
    work, res = [work[i] for i in keep], [res[i] for i in keep]
    for w in work:
        edits.setdefault(w[1], {}).update(w[5])
    held = [(u, c) for u, (s, c) in status.items() if s == "held"]
    nc = sum(c.startswith("conflict ") for _, c in held)
    nd = sum(c.startswith("differ ") for _, c in held)
    fn = sum(len(m) for u, _, _, m in units if status[u][0] == "merged")
    name = ",".join(ovls) if batch is None else f"{batch[0]}:{batch[1]:08X}..{batch[2]:08X}"
    head = (f"apply: {name}: {'proven' if dry_run else 'merged'} {len(units) - len(held)} of {len(units)} "
            f"units ({fn} functions); held {len(held)} (conflict {nc}, differ {nd}, other {len(held) - nc - nd})")
    if dry_run:
        return out + [head + "; dry run, nothing written"], 0
    for w, (k, _, tx) in zip(work, res):
        (root / w[2]).write_text(tx[k], encoding="latin-1")
    git = lambda *a, inp: subprocess.run(["git", *a, "--pathspec-from-file=-"], cwd=root, check=True,
                                         input="".join(f"{p}\n" for p in inp), text=True, capture_output=True)
    if work:
        git("add", inp=[w[2] for w in work])
        git("rm", "-q", inp=[s for w in work for s in w[3]])
    for b, e in edits.items():
        _yaml_file(b, root).write_text("".join(e.get(i, ln) or "" for i, ln in enumerate(ylines[b])))
    regen(root)
    p = root / MERGE_TSV
    rows, picked = {}, {(u, b) for u, b, _, _ in units}
    if p.is_file():
        for ln in p.read_text().splitlines():
            c = ln.split("\t")
            if not ln.startswith("#") and len(c) >= 6 and (c[0], c[1]) not in picked:
                rows[(c[0], c[1])] = ln + "\n"
    for u, b, ov, m in units:
        rows[(u, b)] = "\t".join([u, b, ov, str(len(m)), *status[u]]) + "\n"
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(MERGE_HEADER + "".join(rows[u] for u in sorted(rows)))
    return out + [head], 0


# ---- proof ----

QINC = re.compile(r'^\s*#\s*include\s+"([^"]+)"', re.M)


def _inc_graph(tree, top, idirs):
    """{file: {included files}} over the files under `top` of `tree`, repo-relative; a quote include resolves as cpp
    does: the including file's folder, then each -I dir in order (unresolved includes are dropped)."""
    g = {}
    for t in top:
        for p in (tree / t).rglob("*"):
            if not p.is_file() or p.suffix not in (".c", ".h", ".inc"):
                continue
            rel = p.relative_to(tree)
            hits = set()
            for inc in QINC.findall(p.read_text(errors="replace")):
                for d in (rel.parent, *idirs):
                    q = Path(os.path.normpath(d / inc))
                    if (tree / q).is_file():
                        hits.add(q)
                        break
            g[rel] = hits
    return g


def _first_diff(a, b):
    a, b = a.splitlines(), b.splitlines()
    for i, (x, y) in enumerate(zip(a, b), 1):
        if x != y:
            return f"line {i}: -{x} | +{y}"
    i = min(len(a), len(b)) + 1
    return f"line {i}: -{a[i - 1] if i <= len(a) else ''} | +{b[i - 1] if i <= len(b) else ''}"


def proof(root, rev, mk_root=ROOT):
    """-> (printed lines, rc). Each translation unit that is, or textually includes, a file changed since `rev` is
    cpp'd at `rev` (a git-archive stage in .run/layout/proof/) and in the worktree; rc 0 only when all are identical."""
    root = Path(root)
    v = _mkvars(mk_root)
    flags = v["CPPFLAGS"].split()
    idirs = [Path(flags[i + 1]) for i, f in enumerate(flags[:-1]) if f == "-I"]
    top = [str(d) for d in idirs if (root / d).is_dir()]
    git = lambda *a: subprocess.run(["git", *a], cwd=root, capture_output=True, text=True, check=True).stdout.split()
    changed = {Path(p) for p in git("diff", "--name-only", rev, "--", *top)
               + git("ls-files", "--others", "--exclude-standard", "--", *top)}
    cmd = [str(mk_root / v["CPP"])] + flags
    stage = mk_root / ".run/layout/proof"
    if stage.exists():
        shutil.rmtree(stage)
    stage.mkdir(parents=True)
    try:
        arc = subprocess.run(["git", "archive", rev, *top], cwd=root, capture_output=True, check=True).stdout
        subprocess.run(["tar", "-x"], cwd=stage, input=arc, check=True)
        graphs = [_inc_graph(root, top, idirs), _inc_graph(stage, top, idirs)]
        edges = {}
        for g in graphs:
            for f, hs in g.items():
                edges.setdefault(f, set()).update(hs)
        shared = src_root("shared")  # its bodies compile inside their includers, never alone

        def reached(f):
            seen, todo = set(), [f]
            while todo:
                x = todo.pop()
                if x in changed:
                    return True
                if x not in seen:
                    seen.add(x)
                    todo += edges.get(x, ())
            return False

        tus = sorted(f for f in edges if f.suffix == ".c" and f.parts[0] == shared.parts[0]
                     and shared not in f.parents and reached(f))

        def one(u):
            a = _cpp_text(cmd, stage, u) if (stage / u).is_file() else "missing"
            b = _cpp_text(cmd, root, u) if (root / u).is_file() else "missing"
            if "missing" in (a, b):
                return f"proof: differs {u}: only at {'worktree' if a == 'missing' else rev}"
            if a is None or b is None:
                return f"proof: differs {u}: cpp error at {rev if a is None else 'worktree'}"
            return f"proof: identical {u}" if a == b and a else f"proof: differs {u}: {_first_diff(a, b)}"

        with ThreadPoolExecutor(16) as ex:
            res = list(ex.map(one, tus))
    finally:
        shutil.rmtree(stage, ignore_errors=True)
    k = sum(r.startswith("proof: identical") for r in res)
    return res + [f"proof: {k} of {len(res)} units identical since {rev}"], 0 if k == len(res) else 1


# ---- selftest ----

def _fixture(root, extra_seg=""):
    """Scratch tree: alias fx with overlay segments ovl00/ovl01 carrying dir:, one shared body, a clean tool."""
    if root.exists():
        shutil.rmtree(root)
    for d in ("config", "docs/oracle", "tools", "src"):
        (root / d).mkdir(parents=True, exist_ok=True)
    (root / "config/splat.fx.yaml").write_text(
        "options:\n  asm_path: asm/fx\n  src_path: src/fx\n  build_path: build/fx\nsegments:\n"
        "  - name: ovl00\n    type: code\n    start: 0x0\n    dir: ovl00\n    subsegments:\n"
        "      - [0x0, c, func_80001000_ovl00]\n      - [0x10, c, func_80001010_ovl00]\n"
        "  - name: ovl01\n    type: code\n    start: 0x100\n    dir: ovl01\n    subsegments:\n"
        "      - [0x100, c, func_80002000_ovl01]  # a comment\n" + extra_seg + "  - [0x400]\n")
    (root / DEDUP).write_text(
        "groups:\n  - group: 00\n    body: src/shared/func_80001010_ovl00.c\n    members:\n"
        "      - {alias: fx, module: fx/a, vram: 0x80001010, name: func_80001010_ovl00}\n")
    (root / SYSTEMS).write_text("ovl00\t0x80001010\tfunc_80001010_ovl00\tf\tsrc/shared/entity/f.c\tshared/entity\n"
                                "ovl01\t0x80002000\tfunc_80002000_ovl01\tg\tsrc/rock_01/g.c\trock_01\n")
    (root / UNITS).write_text("# kind\tunit\n"
                              "unit\t80001000_ovl00\tfx\tovl00\t-\t-\t1\t-\t-\t-\t-\tsave\t-\tfunc_80001000_ovl00\n"
                              "held\tfunc_80002000_ovl01\tfx\tovl01\t-\t-\t1\t-\t-\t-\t-\t-\t-\tfunc_80002000_ovl01\n")
    for a in ("fx", "shared"):
        for _, p in units(a, root):
            (root / p).parent.mkdir(parents=True, exist_ok=True)
            (root / p).write_text("/* fixture */\n")
    (root / "tools/fx_tool.py").write_text(
        '"""Docstring names src/fx/ovl00/func_80001000_ovl00.c and asm/fx/ovl00/x.s."""\n'
        "# comment: src/fx/ovl00/func_80001000_ovl00.c\n"
        'R = "src/fx/"\n'
        'P = "refs/mmx6/src/fx/a.c"  # layout: other-tree mmx6 fixture\n'
        'W = list((ROOT / "src").rglob("*.c"))\n'
        "def f():\n    'src/fx/ovl01/inner_doc.c'\n    return 0\n")
    (root / "tools/fx.mk").write_text("build/fx/src/fx/%.o: src/fx/%.c  # src/fx/x.c in a comment\n\tcc $<\n")
    gen(root)


SLUS_WALK = "player_walk"


def _slus_fixture(root, specs):
    """A slus yaml of `specs` rows `<start>, c, <name>, <dir or ''>` (a dir: gives the flow form), each unit's file at
    locate(); names.tsv admits player_walk (unit 80010000) and the pair player_clear_dash, player_clear_attack (merged
    unit 80010020, systems dash and attack); func_80010010 is a placeholder."""
    rows_ = [row_text("      - ", *(c.strip() for c in sp.split(",")[:3]), sp.split(",")[3].strip()) + "\n"
             for sp in specs]
    _yaml_file("slus", root).write_text("options:\n  src_path: src/slus\nsegments:\n  - name: main\n    type: code\n"
                                        "    start: 0x0\n    subsegments:\n" + "".join(rows_) + "  - [0x100]\n")
    (root / NAMES).write_text("kind\timage\tscope\told_name\tnew_name\tdecision\tevidence\treason\n" + "".join(
        f"function\tslus\t\tfunc_{a}\t{n}\taccepted\tx6-twin:fixture\t\n" for a, n in (
            ("80010000", SLUS_WALK), ("80010020", "player_clear_dash"), ("80010024", "player_clear_attack"))))
    unit = lambda u, ms: "\t".join(["unit", u, "slus", "-", "-", "-", str(len(ms)), *"------", ",".join(ms)]) + "\n"
    with open(root / UNITS, "a") as fh:
        fh.write(unit("80010000", [SLUS_WALK]) + unit("80010010", ["func_80010010"])
                 + unit("80010020", ["player_clear_dash", "player_clear_attack"]))
    (root / STEMS).write_text("# fixture\nwalk\ty\tplayer\ndash\ty\tdash\nattack\ty\tattack\n")
    for _, p in units("slus", root):
        (root / p).parent.mkdir(parents=True, exist_ok=True)
        (root / p).write_text("/* fixture */\n")
    gen(root)


def selftest():
    root = ROOT / ".run/layout/selftest"
    fails = []

    def expect(cond, why):
        if not cond:
            fails.append(why)

    def run(name, plant, dh, dm, needle):
        _fixture(root, plant.get("seg", ""))
        if "tool" in plant:
            (root / "tools/fx_plant.py").write_text(plant["tool"] + "\n")
        if "file" in plant:
            (root / plant["file"]).parent.mkdir(parents=True, exist_ok=True)
            (root / plant["file"]).write_text("/* plant */\n")
        if "seg" in plant:
            for _, p in units("fx", root):
                (root / p).parent.mkdir(parents=True, exist_ok=True)
                (root / p).touch()
            gen(root)
        if "tsv" in plant:
            t = (root / TSV).read_text().split("\n")
            c = t[3].split("\t")
            c[plant["tsv"][0]] = plant["tsv"][1]
            t[3] = "\t".join(c)
            (root / TSV).write_text("\n".join(t))
        if "slus" in plant:
            _slus_fixture(root, plant["slus"])
        if "run" in plant:  # a second group whose body is the first group's file: a shared unit
            with open(root / DEDUP, "a") as fh:
                fh.write("  - group: 01\n    body: src/shared/func_80001010_ovl00.c\n    members:\n"
                         "      - {alias: fx, module: fx/b, vram: 0x80002000, name: func_80002000_ovl01}\n")
            (root / "src/shared/func_80001010_ovl00.c").write_text(plant["run"])
            gen(root)
        lines, h, m, _ = check(root)
        expect((h, m) == (dh, dm), f"{name}: want h={dh} m={dm}, got h={h} m={m}: {lines}")
        expect(not needle or any(ln.startswith(needle) for ln in lines), f"{name}: no finding names {needle}")
        return lines

    import contextlib
    with contextlib.redirect_stdout(io.StringIO()):
        lines = run("clean", {}, 0, 0, None)
        _, waived = scan(root)
        expect(len(waived) == 1 and waived[0][1] == 4, f"marker: want 1 waived at line 4, got {waived}")
        expect(locate("fx", "func_X_ovl01", root) == Path("src/fx/ovl01/func_X_ovl01.c"), "undeclared _ovl01 suffix")
        expect(locate("fx", "ovl01_X", root) == Path("src/fx/ovl01/ovl01_X.c"), "undeclared ovl01_ prefix")
        rows_ = {r[0]: r for r in rows(root)}
        expect(rows_["func_80001010_ovl00"][3] == "entity" and rows_["func_80002000_ovl01"][3] == "-", "system col")
        expect(rows_["func_80001000_ovl00"][5:] == ("80001000_ovl00", "save")
               and rows_["func_80002000_ovl01"][5:] == ("held:-", "-")
               and rows_["func_80001010_ovl00"][5:] == ("-", "-"), "cu cols")
        # splat rule: src_path/dir/name.c, nonmatchings_path/dir/name, asm_path/dir/name.s, data_path/dir/name;
        # with dir '' each is today's flat path
        n = "func_Y"
        flat = [locate("fx", n, root), asm_s("fx", n, root), nonmatchings("fx", n, root), data_s("fx", n, root),
                obj("fx", n, root), asm_obj("fx", n, root)]
        expect(flat == [Path(p) for p in ("src/fx/func_Y.c", "asm/fx/func_Y.s", "asm/fx/nonmatchings/func_Y",
                                           "asm/fx/data/func_Y.s", "build/fx/src/fx/func_Y.o",
                                           "build/fx/asm/fx/func_Y.o")], f"flat paths {flat}")
        n = "func_80001000_ovl00"
        got = [locate("fx", n, root), asm_s("fx", n, root), nonmatchings("fx", n, root), data_s("fx", n, root),
               obj("fx", n, root), home("fx", n, root)]
        expect(got == [Path(p) for p in (f"src/fx/ovl00/{n}.c", f"asm/fx/ovl00/{n}.s",
                                          f"asm/fx/nonmatchings/ovl00/{n}", f"asm/fx/data/ovl00/{n}.s",
                                          f"build/fx/src/fx/ovl00/{n}.o", f"src/fx/ovl00/{n}.c")], f"dir paths {got}")
        stems = [data_s("fx", "100.rodata", root), data_s("fx", "400", root), asm_obj("fx", "0", root, "ovl00"),
                 asm_s("fx", "ovl01_80002000", root), data_s("fx", "func_80001000_ovl00.data", root)]
        expect(stems == [Path(p) for p in ("asm/fx/data/ovl01/100.rodata.s", "asm/fx/data/400.s",
                                            "build/fx/asm/fx/ovl00/0.o", "asm/fx/ovl01/ovl01_80002000.s",
                                            "asm/fx/data/ovl00/func_80001000_ovl00.data.s")], f"stem dirs {stems}")
        run("P1", {"tool": 'p = f"src/fx/{name}.c"'}, 1, 0, "tools/fx_plant.py:1 P1")
        run("P2", {"tool": 'p = root / "src/fx" / name'}, 1, 0, "tools/fx_plant.py:1 P2")
        run("P3", {"tool": 'p = (root / d).glob("*.c")'}, 1, 0, "tools/fx_plant.py:1 P3")
        # R-a, R-b, R-c: line 1 is not a unit path; line 2 still is
        run("R-a", {"tool": 'm = "the body lives in src/shared/. */"\np = f"src/shared/{n}.c"'}, 1, 0,
            "tools/fx_plant.py:2 P1")
        run("R-b", {"tool": 'f = "-I asm/fx/include"\np = "asm/fx/include_x.s"'}, 1, 0, "tools/fx_plant.py:2 P1")
        run("R-c", {"tool": 'p = repo / "src" / "walk.c"\nq = repo / "src" / "fx" / n'}, 1, 0,
            "tools/fx_plant.py:2 P2")
        run("outside", {"seg": "  - name: ovl02\n    type: code\n    start: 0x200\n    subsegments:\n"
                               "      - [0x200, c, func_80003000_ovl02]\n"}, 0, 1, "src/fx/func_80003000_ovl02.c:1")
        run("stray", {"file": "src/fx/ovl00/stray_func.c"}, 0, 1, "src/fx/ovl00/stray_func.c:1 stray")
        run("stale", {"tsv": (4, "src/fx/wrong.c")}, 0, 1, f"{TSV}:4 stale")
        run("stale-cu", {"tsv": (5, "80009999_ovl00")}, 0, 1, f"{TSV}:4 stale")
        two = "void func_80001010_ovl00(void) {\n}\n\nvoid func_80002000_ovl01(void) {\n}\n"
        run("run", {"run": two}, 0, 0, None)
        expect(locate("shared", "func_80002000_ovl01", root) == Path("src/shared/func_80001010_ovl00.c")
               and run_file("src/shared/func_80001010_ovl00.c", root)
               and locate("shared", "func_Z", root) == Path("src/shared/func_Z.c"), "run file locate")
        run("run-owner", {"run": two.split("\n\n")[0]}, 0, 1, f"{DEDUP}:7 run file")
        # slus placement: a named unit in its system folder, a placeholder and a disagreeing pair flat (clean); each
        # control plants one of them in the wrong place
        walk, ph, pair = (f"0x0, c, {SLUS_WALK}, player", "0x10, c, func_80010010, ", "0x20, c, 80010020, ")
        run("slus", {"slus": (walk, ph, pair)}, 0, 0, None)
        expect(locate("slus", SLUS_WALK, root) == home("slus", SLUS_WALK, root) == Path(f"src/slus/player/{SLUS_WALK}.c")
               and [r[2:] for r in placement_rows(root)] == [("player", "-"), ("-", "disagree player_clear_dash:dash,"
                                                                                 "player_clear_attack:attack")]
               and not stale(root), f"slus placement {placement_rows(root)}")
        run("named-flat", {"slus": (walk.rsplit(",", 1)[0] + ", ", ph, pair)}, 0, 1, f"src/slus/{SLUS_WALK}.c:1 misplaced")
        run("placeholder-folder", {"slus": (walk, ph + "player", pair)}, 0, 1,
            "src/slus/player/func_80010010.c:1 misplaced")
        run("disagree-folder", {"slus": (walk, ph, pair + "dash")}, 0, 1, "src/slus/dash/80010020.c:1 misplaced")
        # move proof: a segment with no dir: proves identical (dry run writes nothing); a sibling quote-include that
        # the new folder cannot see refuses with nothing written
        seg2 = "  - name: ovl02\n    type: code\n    start: 0x200\n    subsegments:\n      - [0x200, c, func_80003000_ovl02]\n"
        for name, body, want in (("move", "int x = 1;\n", "move: dry run, nothing written"),
                                 ("move-include", '#include "fx_local.h"\nint y = Y;\n', "move: refused -- 0 of 1")):
            _fixture(root, seg2)
            (root / "src/fx/fx_local.h").write_text("#define Y 2\n")
            unit = root / "src/fx/func_80003000_ovl02.c"
            unit.write_text(body)
            ytext = (root / "config/splat.fx.yaml").read_text()
            got, rc = move(root, ["ovl02"], dry_run=True)
            expect(got[-1].startswith(want) and rc == (0 if name == "move" else 1), f"{name}: {got}")
            expect(name != "move" or got[0] == "move: 1 of 1 units identical, 1 renamed", f"{name}: {got}")
            expect(unit.is_file() and (root / "config/splat.fx.yaml").read_text() == ytext
                   and not (ROOT / ".run/layout/move").exists(), f"{name}: wrote or left the stage")
        # rewrite proof: a.c's alias renames a name its included body uses (cpp text changes); c.c's alias is unused
        # (identical); a header edit reaches its includer d.c
        _fixture(root)
        sh = src_root("shared", root)
        (root / sh / "b.c").write_text("int foo;\n")
        (root / "src/fx/a.c").write_text(f'#define foo bar.NON_MATCHING\n#include "{sh.name}/b.c"\n')
        (root / "src/fx/c.c").write_text("#define qux zap.NON_MATCHING\nint c;\n")
        (root / "include").mkdir(exist_ok=True)
        (root / "include/fx.h").write_text("#define W 1\n")
        (root / "src/fx/d.c").write_text('#include "fx.h"\nint d = W;\n')
        g = lambda *a: subprocess.run(["git", *a], cwd=root, capture_output=True, check=True)
        g("init", "-q")
        g("add", "-A")
        g("-c", "user.name=selftest", "-c", "user.email=selftest@invalid", "commit", "-qm", "fixture")
        for f in ("src/fx/a.c", "src/fx/c.c"):
            (root / f).write_text("".join((root / f).read_text().splitlines(keepends=True)[1:]))
        got, rc = proof(root, "HEAD")
        expect(rc == 1 and any(ln.startswith("proof: differs src/fx/a.c: line 1: -int bar.NON_MATCHING") for ln in got)
               and "proof: identical src/fx/c.c" in got and got[-1] == "proof: 1 of 2 units identical since HEAD",
               f"proof alias: {got}")
        g("checkout", "-q", "--", "src")
        (root / "include/fx.h").write_text("#define W 2\n")
        got, rc = proof(root, "HEAD")
        expect(rc == 1 and got[0].startswith("proof: differs src/fx/d.c: line 1:") and len(got) == 2
               and not (ROOT / ".run/layout/proof").exists(), f"proof header: {got}")
    shutil.rmtree(root)
    if fails:
        print("layout: control FAIL " + " | ".join(fails))
        return 1
    print("layout: control OK")
    return 0


def apply_selftest():
    """Four planted units the apply proof must refuse: a differ pair, a conflict pair, a clean pair merged in swapped
    member order, an alias-window pair (its objects match; only the alias-window check may catch it; its header sits
    in a nested body the hoist does not open). A fifth, the cure pair, must prove with its body's header hoisted and
    trip the window without it. The mixed pair (hoisted text fails cc1, in-place text trips the window) must hold as
    alias-window. Three tree controls: one merged stem in two overlays must check 0/0 and locate per overlay; a unit
    listed in the holds file must be held with its cause; an exe batch must take only its window's units and keep the
    merge.tsv rows of an earlier exe batch and of an overlay. The clean pair in its own order must prove, or the controls
    prove nothing."""
    um = _import_unitmap()
    if um is None:
        print("apply: needs tools/build/unitmap.py (private), not found")
        return 2
    tools = um.dry_tools("slus")
    if miss := um.dry_missing_tool(tools):
        print(f"apply: control FAIL: missing tool {miss}")
        return 1
    fx, stage = ROOT / APPLY_FIXTURES, ROOT / APPLY_STAGE / "selftest"
    shutil.rmtree(stage, ignore_errors=True)

    def prove(name, files, swap=False, bodies=True, hdrs=()):
        texts = [(fx / f).read_text(encoding="latin-1") for f in files]
        texts = texts[::-1] if swap else texts
        tx = [merge_text(texts, um.DEFINE, h, shared=(lambda inc: fx / inc) if bodies else None) for h in (True, False)]
        (stage / name).mkdir(parents=True, exist_ok=True)
        (stage / name / "shared").symlink_to(fx / "shared")
        for h in hdrs:  # a body header the hoisted text includes by its bare name, beside the unit
            (stage / name / h).symlink_to(fx / "shared" / h)
        return _prove_unit(um, tools, stage / name / "unit.c", stage / name, [fx / f for f in files], tx, "slus")

    order = ["order_a.c", "order_b.c"]
    clean = prove("clean", order)
    got = [prove("differ", ["pooled_a.c", "pooled_b.c"]), prove("conflict", ["conflict_a.c", "conflict_b.c"]),
           prove("swap", order, swap=True)]
    alias = prove("alias", ["alias_a.c", "alias_b.c"])
    got.append(alias if alias[1] and alias[1].startswith("alias-window ") else (0, alias[1]))
    cure, bare = prove("cure", ["cure_a.c", "cure_b.c"]), prove("cure_bare", ["cure_a.c", "cure_b.c"], bodies=False)
    got.append((None, "cured") if cure == (0, None) and (bare[1] or "").startswith("alias-window ")
               else (0, f"cure {cure}, without body headers {bare}"))
    mixed = prove("mixed", ["mixed_a.c", "mixed_b.c"], hdrs=["apply_mixed.h"])
    got.append(mixed if (mixed[1] or "").startswith("alias-window ") else (0, f"mixed {mixed}"))
    import contextlib
    with contextlib.redirect_stdout(io.StringIO()):
        got += _apply_tree_controls(um)
    caught = sum(k is None for k, _ in got)
    if clean != (0, None) or caught != len(got):
        print(f"apply: control FAIL (clean pair {clean}; {caught} of {len(got)} caught: {got})")
        return 1
    shutil.rmtree(ROOT / APPLY_STAGE, ignore_errors=True)
    print(f"apply: control OK ({caught} of {len(got)} caught)")
    return 0


def _apply_tree_controls(um):
    """[(None, why) when caught, else (0, why)] for the stem, hold and exe batch controls, on a _fixture tree."""
    tree = ROOT / ".run/layout/apply-tree"
    unit = lambda u, ov, ms: "\t".join(["unit", u, "fx", ov, "-", "-", str(len(ms)), *"----", "save", "-", ",".join(ms)])
    seg = lambda ov, st: (f"  - name: {ov}\n    type: code\n    start: 0x{st}\n    dir: {ov}\n    subsegments:\n"
                          f"      - [0x{st}, c, 80003000]\n")
    _fixture(tree, seg("ovl02", "200") + seg("ovl03", "300"))
    rows_ = [unit("80001000_ovl00", "ovl00", ["func_80001000_ovl00", "func_80001010_ovl00"])]
    rows_ += [unit(f"80003000_{ov}", ov, [f"func_80003000_{ov}", f"func_80003004_{ov}"]) for ov in ("ovl02", "ovl03")]
    (tree / UNITS).write_text("# kind\tunit\n" + "\n".join(rows_) + "\n")
    for _, p in units("fx", tree):
        (tree / p).parent.mkdir(parents=True, exist_ok=True)
        (tree / p).write_text("/* fixture */\n")
    gen(tree)
    out = []
    lines, h, m, _ = check(tree)
    locs = [locate("fx", f"func_80003004_{ov}", tree) for ov in ("ovl02", "ovl03")]
    homes = [home("fx", f"func_80003000_{ov}", tree) for ov in ("ovl02", "ovl03")]
    want = [Path(f"src/fx/{ov}/80003000.c") for ov in ("ovl02", "ovl03")]
    out.append((None, "stem") if (h, m) == (0, 0) and locs == homes == want
               else (0, f"stem: check {h}/{m} {lines}; locate {locs}; home {homes}"))
    (tree / HOLDS).write_text("# unit\tcause\n80001000_ovl00\tcontrol hold\n")
    (tree / um.DRYRUN_TSV).parent.mkdir(parents=True, exist_ok=True)
    (tree / um.DRYRUN_TSV).write_text("")
    (tree / "mk").mkdir(exist_ok=True)
    (tree / "mk/slus.mk").write_text("CPPFLAGS := -I include\n")
    got, rc = apply(tree, ["ovl00"])
    mt = (tree / MERGE_TSV).read_text() if (tree / MERGE_TSV).is_file() else ""
    out.append((None, "hold") if rc == 0 and "80001000_ovl00\tfx\tovl00\t2\theld\tcontrol hold\n" in mt
               and got[-1].endswith("held 1 (conflict 0, differ 0, other 1)")
               else (0, f"hold: rc {rc} {got} merge.tsv {mt!r}"))
    exe = {"80010000": 2, "80012000": 2, "80012100": 2, "80012200": 1, "80020000": 2}
    fns = [f"func_{int(u, 16) + 4 * i:08X}" for u, n in exe.items() for i in range(n)]
    _yaml_file("slus", tree).write_text(
        "options:\n  src_path: src/slus\nsegments:\n  - name: main\n    type: code\n    start: 0x0\n    subsegments:\n"
        + "".join(f"      - [0x{4 * i:X}, c, {f}]\n" for i, f in enumerate(fns)) + "  - [0x100]\n")
    rows_ += ["\t".join(["unit", u, "slus", "-", "-", "-", str(n), *"----", "-", "-",
                         ",".join(f"func_{int(u, 16) + 4 * i:08X}" for i in range(n))]) for u, n in exe.items()]
    (tree / UNITS).write_text("# kind\tunit\n" + "\n".join(rows_) + "\n")
    for f in fns:
        (tree / "src/slus").mkdir(parents=True, exist_ok=True)
        (tree / "src/slus" / f"{f}.c").write_text("/* fixture */\n")
    earlier = "80010000\tslus\t-\t2\tmerged\t-\n"
    (tree / MERGE_TSV).write_text(mt + earlier)
    got, rc = apply(tree, batch=("slus", 0x80012000, 0x80012100))
    mt = (tree / MERGE_TSV).read_text()
    want = MERGE_HEADER + "".join(sorted(["80001000_ovl00\tfx\tovl00\t2\theld\tcontrol hold\n", earlier]
                                         + [f"{u}\tslus\t-\t2\theld\tmissing - -\n" for u in ("80012000", "80012100")]))
    out.append((None, "exe batch") if rc == 0 and mt == want
               and got[-1].startswith("apply: slus:80012000..80012100: merged 0 of 2 units")
               else (0, f"exe batch: rc {rc} {got} merge.tsv {mt!r}"))
    shutil.rmtree(tree)
    return out


def main():
    ap = argparse.ArgumentParser(description="One locator for unit paths; config/layout.tsv; the layout check.")
    sub = ap.add_subparsers(dest="cmd", required=True)
    g = sub.add_parser("gen", help="write config/layout.tsv (--check: compare only, exit 1 when stale)")
    g.add_argument("--check", action="store_true")
    c = sub.add_parser("check", help="count hard-coded paths and misplaced files; exit 0 only when all are 0")
    c.add_argument("--paths", action="store_true", help="the hard-coded path scan only")
    c.add_argument("--selftest", action="store_true", help="planted controls in .run/layout/selftest/")
    c.add_argument("--waived", action="store_true", help="also list every `layout: other-tree` marker")
    mv = sub.add_parser("move", help="give overlays (or slus units) dir: and git-mv their units home, after a cpp proof")
    mx = mv.add_mutually_exclusive_group(required=True)
    mx.add_argument("--overlay", help="ovlNN[,ovlMM...]")
    mx.add_argument("--binary", choices=["slus"], help="each unit of the binary whose file is not at its home")
    mv.add_argument("--units", help="with --binary: only these unit stems (stem[,stem...])")
    mv.add_argument("--dry-run", action="store_true", help="the proof only; nothing written")
    pr = sub.add_parser("proof", help="cpp-identity of every unit reached by the src/include changes since a rev")
    pr.add_argument("--since", required=True, help="git rev to compare the worktree against")
    ay = sub.add_parser("apply", help="merge each identical multi-function unit into one file, after an object proof")
    ay.add_argument("--overlay", help="ovlNN[,ovlMM...]")
    ay.add_argument("--batch", help="<binary>:<first>..<last>, hex first addresses, inclusive (slus:80012F8C..80020FA0)")
    ay.add_argument("--dry-run", action="store_true", help="the proof only, nothing written")
    ay.add_argument("--selftest", action="store_true", help="planted controls in .run/layout/apply/")
    a = ap.parse_args()
    if a.cmd == "gen":
        return gen(ROOT, a.check)
    if a.cmd == "apply":
        if a.selftest:
            return apply_selftest()
        if bool(a.overlay) == bool(a.batch):
            ap.error("apply needs exactly one of --overlay, --batch (or --selftest)")
        if a.batch:
            m = re.fullmatch(r"(\w+):([0-9A-Fa-f]+)\.\.([0-9A-Fa-f]+)", a.batch)
            if not m:
                ap.error("--batch is <binary>:<first>..<last>, e.g. slus:80012F8C..80020FA0")
            lines, rc = apply(ROOT, dry_run=a.dry_run, batch=(m.group(1), int(m.group(2), 16), int(m.group(3), 16)))
        else:
            lines, rc = apply(ROOT, a.overlay.split(","), a.dry_run)
        print("\n".join(lines))
        return rc
    if a.cmd == "move":
        if a.units and not a.binary:
            ap.error("--units needs --binary")
        lines, rc = move(ROOT, a.overlay.split(",") if a.overlay else [], a.dry_run, binary=a.binary,
                         only=a.units.split(",") if a.units else None)
        print("\n".join(lines))
        return rc
    if a.cmd == "proof":
        lines, rc = proof(ROOT, a.since)
        print("\n".join(lines))
        return rc
    if a.selftest:
        return selftest()
    lines, h, m, waived = check(ROOT, a.paths)
    for ln in lines:
        print(ln)
    if a.waived:
        for f, ln, what in waived:
            print(f"{f}:{ln} waived other-tree {what}")
    print(summary(h, m))
    return 0 if h == 0 and not m else 1


if __name__ == "__main__":
    sys.exit(main())
