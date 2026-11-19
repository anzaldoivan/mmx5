#!/usr/bin/env python3
"""layout -- the one place that decides a unit's file paths (stdlib only; phase 4.1 T4).

Rule: a unit's folder is the `dir:` key of the config/splat.<alias>.yaml segment that declares it ('' when the
segment has none), as splat 0.50.0 places it (segtypes/common/c.py:129,157; codesubsegment.py:221; data.py:20).
All paths are repo-relative Paths; `root` selects the tree (fixtures pass their own root).

  Library: locate(alias, name) source .c; asm_s, nonmatchings, data_s, obj, asm_obj the split paths; units(alias)
      [(name, path)] in yaml order (alias `shared`: the bodies of config/dedup.us.yaml); src_root, asm_root (tree roots,
      for recursive walks only); home(alias, name) the final layout (an overlay unit: src/<alias>/<ovlNN>/<name>.c;
      slus and shared: the flat path). An undeclared name takes the segment its `_<seg>` suffix or `<seg>_` prefix names.
      data_root the split data folder; split_s(asm dir) its code .s (text, nonmatchings), recursive; include_path an
      `#include` under `-I src`; regen(root) gen() unprinted, for tools that add, remove or rename a unit or body.

  layout.py gen [--check]
      -> config/layout.tsv, rows `unit binary overlay system path cu cu_system` sorted (binary, overlay, unit).
         system = the docs/oracle/x6-systems.tsv folders of the unit's rows (leading shared/ or SLUS_013.95/
         stripped; empty, SLUS_013.95 and rock_NN dropped), joined by `,`, else `-`; a shared body takes its members'
         systems. cu = the config/units.tsv unit whose members hold (binary, unit), `held:<home ids>` for a held
         ledger function, else `-`. cu_system = that row's system. No units.tsv: both `-`.
         --check writes nothing, lists the differing rows, exit 1 when stale.

  layout.py check [--paths] [--selftest] [--waived]
      -> findings `file:line <kind> <text>`, last line `layout: <h> hard-coded paths, <m> misplaced files`; exit 0
         only when every count is 0. h scans tools/**/*.{py,sh,toml,mk,lua}, mk/*.mk, Makefile (not tools/bin,
         __pycache__, fixtures/, this file; comments and .py docstrings skipped) for P1 a literal
         [build/<x>/](src|asm)/<binary folder>/<more> (<more> holds [A-Za-z0-9_{%$(] and is not `include`, the
         split tree's macro folder), P2 a pathlib join descending from "src"/"asm"[/<x>] (not ending in .rglob(); a
         bare "src"/"asm" joined to a quoted literal that is no binary folder is not a unit path), P3 a
         non-recursive .glob() of units. A line ending `layout: other-tree <what>` is not
         counted (--waived lists them). m: a unit file at locate() != home(); a unit or body with no file; a stray
         .c under src/; a stale config/layout.tsv row. --paths: the scan only. --selftest: planted controls in
         .run/layout/selftest/, last line `layout: control OK`.

  layout.py move --overlay <ovlNN[,ovlMM...]> [--dry-run]
      -> gives each named segment (no dir: yet) `dir: <seg>` and git-mv's its units to home(). Proof first: each unit
         is cpp'd (CPP, CPPFLAGS of mk/slus.mk) at its old path in the real tree and at its new path in a staged tree
         (.run/layout/move/: the units, include/ and src/shared/ symlinked; deleted at the end), `#` and blank
         lines dropped; a difference, a cpp error or an INCLUDE_ASM (its folder string would go stale) refuses with
         nothing written. Last line `move: <k> of <k> units identical, <k> renamed`; --dry-run adds
         `move: dry run, nothing written`.
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
FLAT = ("slus", "shared")  # binaries whose home is today's flat path until 4.5/4.6

SEG = re.compile(r"^  - name: (\w+)")
SEG_FLOW = re.compile(r"^  - \{name: (\w+)(.*)")
SEG_LIST = re.compile(r"^  - \[")
DIR = re.compile(r"^    dir: (\S+)")
FLOW_DIR = re.compile(r"\bdir: ([^,}\s]+)")
CUNIT = re.compile(r"^\s*- \[0x[0-9A-Fa-f]+, c, (\w+)\]")
START = re.compile(r"^    start: (0x[0-9A-Fa-f]+)")
FLOW_START = re.compile(r"\bstart: (0x[0-9A-Fa-f]+)")
LIST_START = re.compile(r"^  - \[(0x[0-9A-Fa-f]+)")
HEX = re.compile(r"[0-9A-F]+$")  # a split stem splat names by its rom offset
MKVAR = re.compile(r"^(\w+) :?= (.*)$")
OPT = re.compile(r"^  (src_path|asm_path|build_path): (\S+)")
BODY = re.compile(r"^\s*body: (\S+)")
MEMBER = re.compile(r"^\s*- \{alias: (\w+),.*\bname: (\w+)\}")
MARKER = re.compile(r"layout: other-tree (.+?)\s*$")
ROCK = re.compile(r"rock_\d+$")

_cache = {}


class Yaml:
    def __init__(self, opts, segs, units, starts=()):
        self.opts, self.segs, self.units = opts, segs, units  # segs {name: (dir, line)}; units [(name, seg, line)]
        self.starts = starts  # [(rom start, seg or None)] in yaml order (None: a top-level list segment)
        self.seg_of = {n: s for n, s, _ in units}


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
    opts, segs, units, starts, cur = {}, {}, [], [], None
    for i, line in enumerate(lines, 1):
        line = line.split("  #")[0].rstrip()
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
    return Yaml(opts, {k: tuple(v) for k, v in segs.items()}, units, starts)


def _yaml(alias, root):
    y = _cached(Path(root) / f"config/splat.{alias}.yaml", _parse_yaml)
    return y if y is not None else Yaml({}, {}, [])


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


def _dir(alias, name, root):
    s = segment(alias, name, root)
    return _yaml(alias, root).segs[s][0] if s else ""


def _stem_dir(alias, stem, root, seg=None):
    """Folder of a split stem: `seg`'s dir: when given; else the stem's, `.<type>` dropped, an all-hex stem read as
    the rom offset splat named it by (the segment whose start covers it), any other name as _dir() reads it."""
    y = _yaml(alias, root)
    if seg is None:
        base = stem.split(".")[0]
        if not HEX.match(base):
            return _dir(alias, base, root)
        seg = next((s for st, s in reversed(y.starts) if st <= int(base, 16)), None)
    return y.segs[seg][0] if seg in y.segs else ""


def src_root(alias, root=ROOT):
    return Path("src/shared") if alias == "shared" else Path(_yaml(alias, root).opts.get("src_path", f"src/{alias}"))


def asm_root(alias, root=ROOT):
    return Path(_yaml(alias, root).opts.get("asm_path", f"asm/{alias}"))


def locate(alias, name, root=ROOT):
    if alias == "shared":
        return Path(f"src/shared/{name}.c")
    return src_root(alias, root) / _dir(alias, name, root) / f"{name}.c"


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


def home(alias, name, root=ROOT):
    if alias in FLAT:
        return Path(f"src/{alias}/{name}.c")
    s = segment(alias, name, root)
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
    return [(n, locate(alias, n, root)) for n, _, _ in _yaml(alias, root).units]


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


def rows(root=ROOT):
    sysm, unitm, out = _systems(root), _units(root), []

    def image(alias, name):
        return "slus" if alias == "slus" else segment(alias, name, root)

    for a in aliases(root):
        for n, _, _ in _yaml(a, root).units:
            ov = "-" if a == "slus" else (segment(a, n, root) or "-")
            s = sysm.get((image(a, n), n), set())
            cu = unitm.get((a, n), ("-", "-"))
            out.append((n, a, ov, ",".join(sorted(s)) or "-", str(locate(a, n, root))) + cu)
    seen = set()
    for body, _, members in _dedup(root):
        n = Path(body).stem
        if n in seen:
            continue
        seen.add(n)
        s = set().union(*(sysm.get((image(a, m), m), set()) for a, m in members)) if members else set()
        out.append((n, "shared", "-", ",".join(sorted(s)) or "-", str(locate("shared", n, root)), "-", "-"))
    return sorted(out, key=lambda r: (r[1], r[2], r[0]))


HEADER = ("# config/layout.tsv is generated by tools/build/layout.py gen, so do not edit it by hand.\n"
          "# inputs: config/splat.*.yaml, config/dedup.us.yaml, docs/oracle/x6-systems.tsv, config/units.tsv\n"
          "# unit\tbinary\toverlay\tsystem\tpath\tcu\tcu_system\n")


def stale(root=ROOT):
    """[(line, text)] for each config/layout.tsv row that differs from rows(), keyed by (binary, overlay, unit)."""
    p = Path(root) / TSV
    want = {(r[1], r[2], r[0]): "\t".join(r) for r in rows(root)}
    if not p.exists():
        return [(1, f"stale file missing ({len(want)} rows)")]
    have, last = {}, 0
    for i, line in enumerate(p.read_text().splitlines(), 1):
        last = i
        if line.startswith("#") or not line.strip():
            continue
        c = line.split("\t")
        have[(c[1] if len(c) > 1 else "", c[2] if len(c) > 2 else "", c[0])] = (i, line)
    out = []
    for k in sorted(set(want) | set(have)):
        if k not in have:
            out.append((last + 1, f"stale missing row {want[k]!r}"))
        elif k not in want:
            out.append((have[k][0], f"stale extra row {have[k][1]!r}"))
        elif have[k][1] != want[k]:
            out.append((have[k][0], f"stale want {want[k]!r}"))
    return sorted(out)


def gen(root=ROOT, check=False):
    if check:
        diff = stale(root)
        for ln, text in diff:
            print(f"{TSV}:{ln} {text}")
        print(f"layout: gen --check {len(diff)} stale rows")
        return 1 if diff else 0
    body = "".join("\t".join(r) + "\n" for r in rows(root))
    (Path(root) / TSV).write_text(HEADER + body)
    print(f"layout: wrote {TSV} {body.count(chr(10))} rows")
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
            loc = locate(a, n, root)
            known.add(loc)
            if not (root / loc).is_file():
                out.append(f"config/splat.{a}.yaml:{ln} missing {loc}")
                m += 1
            elif loc != home(a, n, root):
                moved.setdefault((a, segment(a, n, root)), []).append((loc, home(a, n, root)))
    for (a, s), files in sorted(moved.items(), key=lambda kv: (kv[0][0], kv[0][1] or "")):
        m += len(files)
        if len(files) > 20:
            ln = _yaml(a, root).segs[s][1] if s else 1
            out.append(f"config/splat.{a}.yaml:{ln} misplaced {len(files)} {s} units not in {files[0][1].parent}/")
        else:
            out += [f"{loc}:1 misplaced home {h}" for loc, h in files]
    for body, ln, _ in _dedup(root):
        loc = locate("shared", Path(body).stem, root)
        known.add(loc)
        if not (root / loc).is_file():
            out.append(f"{DEDUP}:{ln} missing {loc}")
            m += 1
    if (root / "src").is_dir():
        for p in sorted((root / "src").rglob("*.c")):
            rel = p.relative_to(root)
            if rel not in known:
                out.append(f"{rel}:1 stray no yaml c unit or shared body")
                m += 1
    for ln, text in stale(root):
        out.append(f"{TSV}:{ln} {text}")
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


def move(root, ovls, dry_run=False, mk_root=ROOT):
    """-> (printed lines, rc). Nothing is written unless every unit of every segment in `ovls` is proved identical."""
    root = Path(root)
    plan, out = [], []  # [(alias, seg, [(old, new)])]
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
    pairs = [(o, n) for _, _, mv in plan for o, n in mv]
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
        for a, s, mv in plan:
            dest = mv[0][1].parent
            (root / dest).mkdir(parents=True, exist_ok=True)
            lst.write_text("".join(f"{o}\n" for o, _ in mv))
            subprocess.run(["xargs", "-a", str(lst), "sh", "-c", f'git mv -- "$@" {dest}/', "sh"], cwd=root, check=True)
    finally:
        lst.unlink(missing_ok=True)
    for a in sorted({a for a, _, _ in plan}):
        yp = root / f"config/splat.{a}.yaml"
        lines = yp.read_text().splitlines(keepends=True)
        for s in sorted((s for b, s, _ in plan if b == a), key=lambda s: -_yaml(a, root).segs[s][1]):
            i = _yaml(a, root).segs[s][1]  # 1-based segment line; dir: goes before its `    subsegments:`
            while lines[i].rstrip("\n") != "    subsegments:":
                i += 1
            lines.insert(i, f"    dir: {s}\n")
        yp.write_text("".join(lines))
    regen(root)
    moved = sum(1 for o, n in pairs if (root / n).is_file() and not (root / o).exists())
    return [f"move: {same} of {len(pairs)} units identical, {moved} renamed"], 0 if moved == len(pairs) else 1


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
    shutil.rmtree(root)
    if fails:
        print("layout: control FAIL " + " | ".join(fails))
        return 1
    print("layout: control OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description="One locator for unit paths; config/layout.tsv; the layout check.")
    sub = ap.add_subparsers(dest="cmd", required=True)
    g = sub.add_parser("gen", help="write config/layout.tsv (--check: compare only, exit 1 when stale)")
    g.add_argument("--check", action="store_true")
    c = sub.add_parser("check", help="count hard-coded paths and misplaced files; exit 0 only when all are 0")
    c.add_argument("--paths", action="store_true", help="the hard-coded path scan only")
    c.add_argument("--selftest", action="store_true", help="planted controls in .run/layout/selftest/")
    c.add_argument("--waived", action="store_true", help="also list every `layout: other-tree` marker")
    mv = sub.add_parser("move", help="give overlays dir: and git-mv their units home, after a cpp-identity proof")
    mv.add_argument("--overlay", required=True, help="ovlNN[,ovlMM...]")
    mv.add_argument("--dry-run", action="store_true", help="the proof only; nothing written")
    a = ap.parse_args()
    if a.cmd == "gen":
        return gen(ROOT, a.check)
    if a.cmd == "move":
        lines, rc = move(ROOT, a.overlay.split(","), a.dry_run)
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
