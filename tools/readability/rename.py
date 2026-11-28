"""Rename one X5 symbol everywhere the build and the living docs read it (stdlib + the tracked clang-format).

  rename.py <alias>:0x<VRAM> <new> [--reason TEXT] [--dry-run] [--root DIR]
  rename.py --from config/names.tsv [--dry-run] [--root DIR]
  rename.py --twin <body rel|owner name> <name> [--dry-run] [--root DIR]
  rename.py --selftest

Adapted from mmx6 @93515c1f tools/mmx6/rename.py, AGPL-3.0 (THIRD_PARTY.md).
Resolve: the current name is the config/us/symbols.<alias>.txt symbol at VRAM. rockx5 vrams repeat across overlays, so
the overlay is the new name's `_ovlNN` (main names carry none). No line: the placeholder func_/D_<VRAM>[_ovlNN] that a
splat label or a src/<alias>/ or src/shared/ file carries.
Edits (planned in memory for every job; written only when nothing refuses; contents first, then `git mv`):
  word-bounded old-name tokens in src/, include/, config/us/{symbols,splat,reloc_addrs}.*, config/us/dedup.yaml,
  config/us/shift/, mk/*.mk, tools/ (not tools/readability/fixtures/), docs/ (not generated, not docs/retired/),
  cookbook/, rules/, README.md, CONTRIBUTING.md. #include, #define and #undef lines (a twin's `#define <owner> <site>`)
  and the registry's `renames:` pairs are rewritten too: files are named by function. src|include/**/<old>.<ext> moves to <new>.<ext> (shared bodies).
  A run file (layout.run_file: a shared unit, named for its first body) never moves: renaming that first body leaves
  the `shared/<old>.c` path text alone everywhere (registry `body:`, sites' #include, docs); the rest is renamed.
  No symbol line: `<new> = 0x<VRAM>; // type:func [rom:0x<off>]` (data: no type:func) is inserted in address order.
  config/names.tsv: the row of the same image whose new_name is <old> turns `rejected`, its reason gains
  `; 3.7 T4: replaced by <new>` (or --reason, its `{new}` the new name). names.tsv is never token-rewritten.
  Changed .c/.h files are formatted with .venv/bin/clang-format --style=file.
--from: every names.tsv row, not rejected, whose new_name config/us/symbols.<image>.txt does not carry; the address is
  old_name's hex, else the symbols line of old_name. An overlay image (`ovl24`, as psxd_img.py promote writes) is
  rockx5, and its new_name must end in `_ovl24`. A row whose address nothing in the build carries (no symbol line,
  splat label or src file: asm-only) is skipped (`rename: skipped <n> rows not in the build`). One refusal refuses the
  whole batch.
Refusals (`rename: REFUSE <alias:vram> <why>`, exit 1, nothing written): unknown alias:vram, bad name,
  <new> already defined, <new> rejected, wrong _ovlNN, define cycle a->b.
Lines: `rename: <alias:vram> <old> -> <new>`, `rename: EDIT <path>`, `rename: MOVE <old> <new>`,
  `rename: LEFT <path> raw|generated (regen: <cmd>)|other`; last line
  `rename: <n> renamed, <e> files edited, <m> moved, <l> left (raw <r>, generated <g>, other <o>)`.
--twin: one config/us/dedup.yaml group into the OVL form (include/mmx5/ovl.h). Each member is renamed as above to
  `<name>_ovlNN` (rockx5, NN from its module) or `<name>` (main). The body moves to src/shared/<name>.c, gains
  `#include "mmx5/ovl.h"` after its top includes, and every owner token in it becomes `OVL(<name>)`. Each site drops
  its `#define <owner> <site>` and `#undef <owner>` lines (callee defines stay); registry body:/name: follow.
  Refusals (whole job): unknown group, run-file body, inline member (renames:), two members in one overlay, more
  than one main member, bad name (or one ending _ovlNN), <name> or a member's new name already defined, no site
  (the member's file lacks the body's #include). Extra line: `rename: TWIN <old body> -> src/shared/<name>.c`.
Never reads or touches asm/, build/, expected/, extracted/.
--selftest: copies fixtures/rename/ (invented names) to .run/<phase>/rename-selftest/, runs the cases, removes it;
prints `rename: control OK -- <k> cases` or `rename: selftest FAIL <case>` (exit 1).
"""

import hashlib
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(HERE.parent / "build"))
import layout  # noqa: E402
FIX = HERE / "fixtures" / "rename"
CLANG = ROOT / ".venv" / "bin" / "clang-format"
NAMES = "config/names.tsv"
OVL_ALIASES = ("rockx5",)
NEVER = ("asm/", "build/", "expected/", "extracted/", ".git/")  # layout: other-tree the ignored trees, every version
RAW = ("waves/", "phase-ends/", ".claude-state/", "docs/retired/")
EDIT_DIRS = ("src/", "include/", f"{layout.config_path('shift')}/", "tools/", "docs/", "cookbook/", "rules/")
EDIT_FILES = ("README.md", "CONTRIBUTING.md", layout.DEDUP)
IMGTAB = "PY tools/sig/imgtab.py x6 --from-table docs/oracle/x6-twins.tsv --x6-root <mmx6> --leads --systems"
REGEN = {"docs/oracle/annotations.jsonl": "ExportAnnotations.java, docs/oracle/README.md",
         "docs/oracle/loadmap.json": "PY tools/loadmap/loadmap.py derive",
         "docs/oracle/x5-leads.tsv": IMGTAB,
         "docs/ledger.md": "PY tools/wave/ledger.py build"}
SYM = re.compile(r"^\s*([A-Za-z_]\w*)\s*=\s*0x([0-9A-Fa-f]+)\s*;(.*)$")
LABEL = re.compile(r"^\s*-\s*\[\s*0x([0-9A-Fa-f]+)\s*,\s*\w+\s*,\s*([A-Za-z_]\w*)\s*\]")
DEFINE = re.compile(r"^\s*#\s*define\s+([A-Za-z_]\w*)\s+([A-Za-z_]\w*)")
IDENT = re.compile(r"^[A-Za-z_]\w*$")
OVL = re.compile(r"_ovl\d+$")
HEX = re.compile(r"_([0-9A-Fa-f]{8})(?:_ovl\d+)?$")
NOISE = re.compile(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\\n])*"', re.S)


def phase_scratch(root):
    """The open phase's temp folder (as tools/run.sh: `# Phase <id>` line 1 of PHASE_PLAN.md), else .run (no plan)."""
    try:
        line = (root / "phase-ends/current/PHASE_PLAN.md").read_text().split("\n", 1)[0]
    except OSError:
        line = ""
    m = re.match(r"#\s*Phase\s+([A-Za-z0-9._-]+)", line)
    return root / ".run" if not m or m.group(1) in (".", "..") else root / ".run" / m.group(1)


class Refuse(Exception):
    pass


def word(name):
    return re.compile(r"(?<![A-Za-z0-9_])" + re.escape(name) + r"(?![A-Za-z0-9_])")


def code_hit(text, rx):
    """rx on a code line: comments and string literals blanked (newlines kept), preprocessor lines skipped."""
    text = NOISE.sub(lambda m: re.sub(r"[^\n]", " ", m.group(0)), text)
    return any(rx.search(ln) for ln in text.split("\n") if not ln.lstrip().startswith("#"))


def cycle(pairs):
    srcs = {a for a, _ in pairs}
    for a, b in pairs:
        if b != a and b in srcs:
            return f"{a}->{b}"
    return None


class Tree:
    """The tracked files of root, with planned texts and moves held in memory until commit()."""

    def __init__(self, root):
        self.root = Path(root)
        self.git = (self.root / ".git").exists()
        if self.git:
            out = subprocess.run(["git", "ls-files", "-z"], cwd=self.root, capture_output=True, text=True, check=True)
            files = [f for f in out.stdout.split("\0") if f]
        else:
            files = [p.relative_to(self.root).as_posix() for p in self.root.rglob("*") if p.is_file()]
        self.files = {f for f in files if not f.startswith(NEVER) and f != layout.TSV and (self.root / f).is_file()}
        self.orig, self.over, self.origin = {}, {}, {}

    def text(self, rel):
        if rel in self.over:
            return self.over[rel]
        o = self.origin.get(rel, rel)
        if o not in self.orig:
            try:
                with open(self.root / o, encoding="utf-8", newline="") as fh:
                    self.orig[o] = fh.read()
            except (OSError, UnicodeDecodeError):
                self.orig[o] = None
        return self.orig[o]

    def put(self, rel, text):
        self.text(rel)
        self.over[rel] = text

    def move(self, a, b):
        self.text(a)
        self.files.discard(a)
        self.files.add(b)
        self.origin[b] = self.origin.pop(a, a)
        if a in self.over:
            self.over[b] = self.over.pop(a)

    def changed(self):
        return {r: t for r, t in self.over.items() if t != self.orig[self.origin.get(r, r)]}

    def moves(self):
        return sorted((o, r) for r, o in self.origin.items() if o != r)

    def commit(self):
        for rel, text in sorted(self.changed().items()):
            with open(self.root / self.origin.get(rel, rel), "w", encoding="utf-8", newline="") as fh:
                fh.write(text)
        for o, r in self.moves():
            if self.git:
                subprocess.run(["git", "mv", o, r], cwd=self.root, check=True)
            else:
                (self.root / r).parent.mkdir(parents=True, exist_ok=True)
                os.rename(self.root / o, self.root / r)


def aliases(tree):
    sym = re.compile(re.escape(str(layout.config_path("symbols."))) + r"(\w+)\.txt")
    return sorted(m.group(1) for f in tree.files if (m := sym.fullmatch(f)))


def symbols(tree, alias):
    """[(name, vram, tail)] of config/us/symbols.<alias>.txt, file order."""
    out = []
    for ln in (tree.text(str(layout.config_path(f"symbols.{alias}.txt"))) or "").split("\n"):
        if not ln.lstrip().startswith("//") and (m := SYM.match(ln)):
            out.append((m.group(1), int(m.group(2), 16), m.group(3)))
    return out


def labels(tree, alias):
    """{name: rom offset} of the splat labels of config/us/splat.<alias>.yaml."""
    t = tree.text(str(layout.config_path(f"splat.{alias}.yaml"))) or ""
    return {m.group(2): int(m.group(1), 16) for ln in t.split("\n") if (m := LABEL.match(ln))}


def generated(tree, rel):
    """The regen command of a generated file, else None."""
    if rel in REGEN:
        return REGEN[rel]
    if re.fullmatch(r"docs/oracle/x6-[^/]+\.tsv", rel):
        return IMGTAB
    if rel.startswith("docs/"):
        head = (tree.text(rel) or "").split("\n", 1)[0]
        if "never hand-edit" in head and (m := re.search(r"generated by ([^;]+)", head)):
            return "PY " + m.group(1).strip()
    return None


def kind(tree, rel):
    if rel.startswith(RAW):
        return "raw"
    if generated(tree, rel):
        return "generated"
    if rel.startswith("tools/readability/fixtures/"):
        return "other"
    bound = tuple(str(layout.config_path(f"{k}.")) for k in ("symbols", "splat", "reloc_addrs"))
    if rel.startswith(EDIT_DIRS) or rel in EDIT_FILES or rel.startswith(bound) \
            or re.fullmatch(r"mk/[^/]+\.mk", rel):
        return "edit"
    return "other"


def row_alias(image):
    """The symbols alias of a names.tsv image: an overlay unit (`ovl24`, as psxd_img.py promote writes) is rockx5."""
    return OVL_ALIASES[0] if re.fullmatch(r"ovl\d+", image) else image


def names_rows(tree):
    """[(line index, columns)] of the config/names.tsv rows (header and blank lines skipped)."""
    out = []
    for i, ln in enumerate((tree.text(NAMES) or "").split("\n")):
        c = ln.split("\t")
        if ln.strip() and not ln.startswith("#") and c[0] != "kind":
            out.append((i, c + [""] * (8 - len(c))))
    return out


def resolve(tree, alias, vram, new):
    """(old name, True when a symbols line carries it) or raise Refuse."""
    if alias not in aliases(tree) or vram is None:
        raise Refuse("unknown alias:vram")
    sfx = OVL.search(new)
    ovl = alias in OVL_ALIASES
    if ovl != bool(sfx):
        raise Refuse("wrong _ovlNN")
    tail = sfx.group(0) if sfx else ""
    syms = symbols(tree, alias)
    hit = [(("type:func" not in t), n) for n, a, t in syms
           if a == vram and (not ovl or (OVL.search(n) and OVL.search(n).group(0) == tail))]
    if hit:
        return min(hit)[1], True
    labs = labels(tree, alias)
    for ph in (f"func_{vram:08X}{tail}", f"D_{vram:08X}{tail}"):
        if ph in labs or any(layout.locate(d, ph, tree.root).as_posix() in tree.files for d in (alias, "shared")):
            return ph, False
    other = re.compile(rf"(func|D)_{vram:08X}_ovl\d+")
    if ovl and (any(a == vram for _, a, _ in syms) or any(other.fullmatch(n) for n in labs)):
        raise Refuse("wrong _ovlNN")
    raise Refuse("unknown alias:vram")


def taken(tree, new):
    """Raise Refuse when a symbols line, a src|include file stem or a code token already carries new."""
    nrx = word(new)
    if any(n == new for a in aliases(tree) for n, _, _ in symbols(tree, a)) or \
            any(f.startswith(("src/", "include/")) and os.path.basename(f).split(".", 1)[0] == new
                for f in tree.files) or \
            any(f.startswith(("src/", "include/")) and f.endswith((".c", ".h")) and new in (tree.text(f) or "")
                and code_hit(tree.text(f), nrx) for f in tree.files):
        raise Refuse(f"{new} already defined")


def plan(tree, alias, vram, new, reason):
    """Plan one rename into tree (in memory): (old, left [(rel, kind)]), None when nothing changes, or raise Refuse."""
    if not IDENT.match(new):
        raise Refuse("bad name")
    old, has_line = resolve(tree, alias, vram, new)
    if old == new:
        return None
    rows = names_rows(tree)
    if any(row_alias(c[1]) == alias and c[4] == new and c[5] == "rejected" for _, c in rows):
        raise Refuse(f"{new} rejected")
    taken(tree, new)
    # a run file named for old keeps its name (its other bodies' owners keep theirs): its path text stays
    keep = {os.path.basename(os.path.dirname(f)) + "/" for f in tree.files
            if f.startswith(("src/", "include/")) and os.path.basename(f) == f"{old}.c" and layout.run_file(f, tree.root)}
    rx, edits = word(old), {}

    def path_at(t, m):
        return t[m.end():m.end() + 2] == ".c" and any(t[:m.start()].endswith(k) for k in keep)

    def sub(t):
        return rx.sub(lambda m: m.group(0) if path_at(t, m) else new, t) if keep else rx.sub(new, t)

    def hit(t):
        return any(not path_at(t, m) for m in rx.finditer(t)) if keep else rx.search(t)
    for f in sorted(tree.files):
        t = tree.text(f)
        if f != NAMES and t and old in t and kind(tree, f) == "edit":
            out = sub(t)
            if out != t:
                edits[f] = out
    if not has_line:
        rel = str(layout.config_path(f"symbols.{alias}.txt"))
        lines = edits.get(rel, tree.text(rel)).split("\n")
        tags = ["type:func"] if old.startswith("func_") else []
        key = vram
        if alias in OVL_ALIASES:
            key = labels(tree, alias).get(old)
            if key is None:
                raise Refuse("unknown alias:vram")
            tags.append(f"rom:0x{key:X}")
        add = f"{new} = 0x{vram:08X};" + (" // " + " ".join(tags) if tags else "")

        def lkey(ln):
            m = SYM.match(ln) if not ln.lstrip().startswith("//") else None
            if not m:
                return None
            if alias in OVL_ALIASES:
                r = re.search(r"rom:0x([0-9A-Fa-f]+)", m.group(3))
                return int(r.group(1), 16) if r else None
            return int(m.group(2), 16)
        at = next((i for i, ln in enumerate(lines) if (k := lkey(ln)) is not None and k > key), None)
        if at is None:
            at = len(lines) - 1 if lines and lines[-1] == "" else len(lines)
        lines.insert(at, add)
        edits[rel] = "\n".join(lines)
    nl = (tree.text(NAMES) or "").split("\n")
    for i, c in rows:
        if row_alias(c[1]) == alias and c[4] == old and c[5] != "rejected":
            note = reason.replace("{new}", new) if reason else f"3.7 T4: replaced by {new}"
            c[5], c[7] = "rejected", (f"{c[7]}; {note}" if c[7] else note)
            nl[i] = "\t".join(c)
    if nl != (tree.text(NAMES) or "").split("\n"):
        edits[NAMES] = "\n".join(nl)
    for f, t in sorted(edits.items()):
        if f.startswith(("src/", "include/")):
            pairs = [m.groups() for ln in t.split("\n") if (m := DEFINE.match(ln))]
            if any(new in p for p in pairs) and (cyc := cycle(pairs)):
                raise Refuse(f"define cycle {cyc}")
    moves = []
    for f in sorted(tree.files):
        stem, dot, ext = os.path.basename(f).partition(".")
        if f.startswith(("src/", "include/")) and stem == old and not layout.run_file(f, tree.root):
            moves.append((f, f"{os.path.dirname(f)}/{new}{dot}{ext}"))
    for f, t in edits.items():
        tree.put(f, t)
    for a, b in moves:
        tree.move(a, b)
    done = set(edits) | {b for _, b in moves} | {NAMES}
    left = []
    for f in sorted(tree.files - done):
        t = tree.text(f)
        if t and old in t and hit(t):
            k = kind(tree, f)
            left.append((f, "other" if k == "edit" else k))
    return old, left


def fmt(tree):
    """clang-format (stdin, --assume-filename) every changed .c/.h text, in memory."""
    for rel, text in sorted(tree.changed().items()):
        if rel.endswith((".c", ".h")):
            r = subprocess.run([str(CLANG), "--style=file", f"--assume-filename={tree.root.resolve() / rel}"],
                               input=text, capture_output=True, text=True, check=True)
            tree.over[rel] = r.stdout


def run(root, jobs, dry, reason=None):
    """jobs [(alias, vram|None, new, label[, unit])] -> (rc, lines). Writes only when nothing refuses and not dry.
    unit: the names.tsv overlay image (`ovl24`); new must then end in `_<unit>`."""
    tree, lines, refused, n, left = Tree(root), [], [], 0, []
    for alias, vram, new, label, *unit in jobs:
        try:
            if unit and not new.endswith(f"_{unit[0]}"):
                raise Refuse("wrong _ovlNN")
            got = plan(tree, alias, vram, new, reason)
        except Refuse as e:
            refused.append(f"rename: REFUSE {label} {e}")
            continue
        if got is None:
            lines.append(f"rename: {label} {new} unchanged")
            continue
        n += 1
        lines.append(f"rename: {label} {got[0]} -> {new}")
        left += got[1]
    if refused:
        return 1, refused
    return report(root, tree, lines, n, left, dry)


def report(root, tree, lines, n, left, dry):
    """Format, list and (not dry) write a planned tree: (0, lines)."""
    if not dry:
        fmt(tree)
    changed = tree.changed()
    lines += [f"rename: EDIT {f}" for f in sorted(changed)]
    lines += [f"rename: MOVE {a} {b}" for a, b in tree.moves()]
    for f, k in left:
        lines.append(f"rename: LEFT {f} {k}" + (f" (regen: {generated(tree, f)})" if k == "generated" else ""))
    cnt = {k: sum(1 for _, x in left if x == k) for k in ("raw", "generated", "other")}
    lines.append(f"rename: {n} renamed, {len(changed)} files edited, {len(tree.moves())} moved, {len(left)} left "
                 f"(raw {cnt['raw']}, generated {cnt['generated']}, other {cnt['other']})")
    if not dry:
        tree.commit()
        layout.regen(root)  # a unit or body renamed: config/layout.tsv follows
    return 0, lines


def groups(tree):
    """[(body, [(alias, module, vram, name, inline)])] of the registry, file order."""
    out = []
    for ln in (tree.text(layout.DEDUP) or "").split("\n"):
        if m := layout.BODY.match(ln):
            out.append((m.group(1), []))
        elif out and (m := layout.MEMBER.match(ln)):
            mod, vr = re.search(r"\bmodule: ([\w/]+)", ln), re.search(r"\bvram: 0x([0-9A-Fa-f]+)", ln)
            out[-1][1].append((m.group(1), mod.group(1) if mod else "", int(vr.group(1), 16) if vr else None,
                               m.group(2), "renames:" in ln))
    return out


def twin_refusal(tree, body, members):
    """Why a registry group cannot take the OVL form, else None."""
    if layout.run_file(body, tree.root):
        return "run-file body"
    if inl := [n for _, _, _, n, i in members if i]:
        return f"inline member {inl[0]}"
    seen = set()
    for alias, mod, _, n, _ in members:
        if alias not in (OVL_ALIASES[0], layout.MAIN):
            return f"member alias {alias}"
        if alias == layout.MAIN:
            continue
        m = re.match(rf"{alias}/ovl(\d+)", mod)
        if not m:
            return f"no overlay in {mod or n}"
        if m.group(1) in seen:
            return f"two members in ovl{m.group(1)}"
        seen.add(m.group(1))
    if sum(1 for a, *_ in members if a == layout.MAIN) > 1:
        return f"more than one {layout.MAIN} member"
    return None


def twin_plan(tree, key, name, reason):
    """Plan one group's OVL form into tree: (lines, renamed count, left), or raise Refuse."""
    hits = [(b, ms) for b, ms in groups(tree) if key in (b, Path(b).stem)]
    if not hits:
        raise Refuse("unknown group")
    body, members = hits[0]
    if (why := twin_refusal(tree, body, members)) or len(hits) > 1:
        raise Refuse(why or "ambiguous group")
    if not IDENT.match(name) or OVL.search(name):
        raise Refuse("bad name")
    taken(tree, name)
    owner = Path(body).stem
    if owner not in [n for *_, n, _ in members]:
        raise Refuse(f"no member named {owner}")
    inc = f'#include "{Path(body).relative_to("src").as_posix()}"'
    undef = re.compile(r"^\s*#\s*undef\s+" + re.escape(owner) + r"\s*$")
    for alias, _, _, n, _ in members:
        site = layout.locate(alias, n, tree.root).as_posix()
        t = tree.text(site) if site in tree.files else None
        if not t or inc not in t:
            raise Refuse(f"no site for {n}")
        keep = [ln for ln in t.split("\n") if not undef.match(ln) and not ((d := DEFINE.match(ln)) and d.group(1) == owner)]
        tree.put(site, "\n".join(keep))
    lines, n_done, left, own = [], 0, [], owner
    for alias, mod, vram, n, _ in members:
        new = name if alias == layout.MAIN else f"{name}_ovl{re.match(rf'{alias}/ovl(\d+)', mod).group(1)}"
        got = plan(tree, alias, vram, new, reason)
        if got and got[0] != n:
            raise Refuse(f"{n} resolves to {got[0]}")
        if n == owner:
            own = new
        if got:
            n_done += 1
            lines.append(f"rename: {alias}:0x{vram:08X} {n} -> {new}")
            left += got[1]
    cur = next(r for r in tree.files if tree.origin.get(r, r) == body)
    dest = (layout.src_root("shared") / f"{name}.c").as_posix()
    if cur != dest:
        tree.move(cur, dest)
    path = re.compile(r"\bshared/" + re.escape(own) + r"\.c\b")
    for f in sorted(tree.files):
        t = tree.text(f)
        if own != name and t and f"shared/{own}.c" in t and kind(tree, f) == "edit":
            tree.put(f, path.sub(f"shared/{name}.c", t))
    bl = word(own).sub(f"OVL({name})", tree.text(dest)).split("\n")
    if '#include "mmx5/ovl.h"' not in bl:
        at = 0
        for i, ln in enumerate(bl):
            if ln.startswith("#include"):
                at = i + 1
            elif ln.strip() and not ln.lstrip().startswith(("/*", "*", "//")):
                at = at or i
                break
        bl.insert(at, '#include "mmx5/ovl.h"')
    tree.put(dest, "\n".join(bl))
    lines.append(f"rename: TWIN {body} -> {dest}")
    return lines, n_done, left


def run_twin(root, key, name, dry, reason=None):
    """--twin: one registry group (body path or owner name) into the OVL form -> (rc, lines)."""
    tree = Tree(root)
    try:
        lines, n, left = twin_plan(tree, key, name, reason)
    except Refuse as e:
        return 1, [f"rename: REFUSE {key} {e}"]
    return report(root, tree, lines, n, left, dry)


def built(tree, alias, vram):
    """True when a symbols line, a splat label or a src/<alias>|shared/ file of alias carries vram."""
    if any(a == vram for _, a, _ in symbols(tree, alias)):
        return True
    ph = re.compile(rf"(?:func|D)_{vram:08X}(?:_ovl\d+)?")
    return any(ph.fullmatch(n) for n in labels(tree, alias)) or any(
        f.endswith(".c") and ph.fullmatch(n := Path(f).stem)
        and f in (layout.locate(alias, n, tree.root).as_posix(), layout.locate("shared", n, tree.root).as_posix())
        for f in tree.files)


def from_rows(root, path):
    """(jobs, skipped): rows not rejected whose new_name the image's symbols file does not carry, file order;
    skipped counts the rows whose address nothing in the build carries."""
    tree = Tree(root)
    carried = {a: {n for n, _, _ in symbols(tree, a)} for a in aliases(tree)}
    jobs, skipped = [], 0
    for ln in (Path(root) / path).read_text(encoding="utf-8").split("\n"):
        c = ln.split("\t")
        if not ln.strip() or ln.startswith("#") or c[0] == "kind" or len(c) < 6 or c[5] == "rejected":
            continue
        unit, old, new = c[1], c[3], c[4]
        image = row_alias(unit)
        if new in carried.get(image, {new}):
            continue
        m = HEX.search(old)
        vram = int(m.group(1), 16) if m else \
            next((a for n, a, _ in (symbols(tree, image) if image in carried else []) if n == old), None)
        if image in carried and vram is not None and not built(tree, image, vram):
            skipped += 1
            continue
        job = (image, vram, new, f"{image}:{old}" if vram is None else f"{image}:0x{vram:08X}")
        jobs.append(job + (unit,) if unit != image else job)
    return jobs, skipped


def selftest():
    scratch = phase_scratch(ROOT) / "rename-selftest"
    cf = lambda name: str(layout.config_path(name))

    def fresh():
        shutil.rmtree(scratch, ignore_errors=True)
        shutil.copytree(FIX, scratch)

    def rd(rel):
        p = scratch / rel
        return p.read_text(encoding="utf-8") if p.is_file() else ""

    def digest():
        h = hashlib.sha256()
        for p in sorted(scratch.rglob("*")):
            if p.is_file():
                h.update(p.relative_to(scratch).as_posix().encode() + b"\0" + p.read_bytes())
        return h.hexdigest()

    def at(alias, name):
        return layout.locate(alias, name, scratch)

    def go(alias, vram, new):
        return run(scratch, [(alias, vram, new, f"{alias}:0x{vram:08X}")], False)

    checks, cases = [], 0
    try:
        cases += 1  # (1) main function: caller, extern, #define alias, carve label, symbol line, rockx5 caller
        fresh()
        rc, out = go(layout.MAIN, 0x80020100, "alpha_read")
        boot = rd(at(layout.MAIN, "boot_main"))
        checks += [
            ("1 rc", rc == 0),
            ("1 tally", out[-1] == "rename: 1 renamed, 8 files edited, 1 moved, 3 left (raw 1, generated 1, other 1)"),
            ("1 moved", rd(at(layout.MAIN, "alpha_read")).count("s32 alpha_read(s32 a0) {") == 1
             and not (scratch / at(layout.MAIN, "alpha_load")).exists()),
            ("1 caller", "alpha_read(1);" in boot and "alpha_loader" in boot and "#define alpha_alias alpha_read" in boot),
            ("1 extern", "extern s32 alpha_read(s32 a0);" in rd("include/common.h")),
            ("1 rockx5 caller", "alpha_read(3);" in rd(at("rockx5", "func_80100800_ovl07"))),
            ("1 symbol", "alpha_read = 0x80020100; // type:func\n" in rd(cf(f"symbols.{layout.MAIN}.txt"))),
            ("1 label", "- [0x1100, c, alpha_read]" in rd(cf(f"splat.{layout.MAIN}.yaml"))),
            ("1 names row", "func_80020100\talpha_load\trejected\tfix:1\tfixture row; 3.7 T4: replaced by alpha_read"
             in rd("config/names.tsv")),
            ("1 left", "rename: LEFT waves/W01/notes.md raw" in out and "rename: LEFT notes.txt other" in out
             and any(x.startswith("rename: LEFT docs/oracle/x6-twins.tsv generated (regen: ") for x in out)),
            ("1 docs", "alpha_read" in rd("docs/notes.md") and "alpha_load" in rd("waves/W01/notes.md")),
        ]
        cases += 1  # (6) a second run is a no-op
        h = digest()
        rc, out = go(layout.MAIN, 0x80020100, "alpha_read")
        checks.append(("6 rerun", rc == 0 and digest() == h and out[-1] == "rename: 0 renamed, 0 files edited, "
                       "0 moved, 0 left (raw 0, generated 0, other 0)"))
        cases += 1  # (2) rockx5 member with a shared body, twin copies and the dedup entry
        fresh()
        rc, out = go("rockx5", 0x80100200, "fx_spawn_ovl05")
        twin, inl, dd = rd(at("rockx5", "func_80100200_ovl06")), rd(at("rockx5", "func_80100A00_ovl08")), \
            rd(layout.DEDUP)
        sy = rd(cf("symbols.rockx5.txt"))
        checks += [
            ("2 rc", rc == 0 and "rename: rockx5:0x80100200 func_80100200_ovl05 -> fx_spawn_ovl05" in out),
            ("2 moves", (scratch / at("shared", "fx_spawn_ovl05")).exists() and (scratch / at("rockx5", "fx_spawn_ovl05"))
             .exists() and not (scratch / at("shared", "func_80100200_ovl05")).exists()),
            ("2 member", '#include "shared/fx_spawn_ovl05.c"' in rd(at("rockx5", "fx_spawn_ovl05"))
             and "#define" not in rd(at("rockx5", "fx_spawn_ovl05"))),
            ("2 twin", "#define fx_spawn_ovl05 func_80100200_ovl06\n" in twin and "#undef fx_spawn_ovl05\n" in twin
             and '#include "shared/fx_spawn_ovl05.c"' in twin and ".NON_MATCHING" not in twin),
            ("2 inline", "void func_80100A00_ovl08(void) {" in inl
             and "name: func_80100A00_ovl08, renames: [fx_spawn_ovl05 func_80100A00_ovl08.NON_MATCHING]}" in dd),
            ("2 body", "void fx_spawn_ovl05(void) {" in rd(at("shared", "fx_spawn_ovl05"))),
            ("2 dedup", f"body: {at('shared', 'fx_spawn_ovl05')}" in dd and "name: fx_spawn_ovl05}" in dd
             and "name: func_80100200_ovl06}" in dd),
            ("2 symbol", "fx_spawn_ovl05 = 0x80100200; // type:func rom:0x2200\nfunc_80100200_ovl06 = " in sy),
            ("2 label", "- [0x2200, c, fx_spawn_ovl05]" in rd(cf("splat.rockx5.yaml"))
             and "- [0x3200, c, func_80100200_ovl06]" in rd(cf("splat.rockx5.yaml"))),
        ]
        cases += 1  # (3) a data symbol line with no type:func
        fresh()
        rc, out = go(layout.MAIN, 0x80030000, "g_beta_table")
        checks.append(("3 data", rc == 0 and "\ng_beta_table = 0x80030000;\n" in rd(cf(f"symbols.{layout.MAIN}.txt"))
                       and "extern s32 g_beta_table[];" in rd("include/common.h")
                       and "g_beta_table[0] = 0;" in rd(at(layout.MAIN, "boot_main"))))
        cases += 1  # (4) refusals write nothing
        fresh()
        (scratch / "batch.tsv").write_text("kind\timage\tscope\told_name\tnew_name\tdecision\tevidence\treason\n"
                                           "function\tmain\t\tfunc_80020600\tdelta_run\tprovisional\tfix:9\t\n"
                                           "function\tmain\t\tfunc_80020300\tzeta_bad\tprovisional\tfix:9\t\n"
                                           "function\tmain\t\tfunc_80029990\tnu_asm\tprovisional\tfix:9\t\n")
        h = digest()
        for tag, job, want in [
            ("taken", (layout.MAIN, 0x80020100, "boot_main"), "boot_main already defined"),
            ("rejected", (layout.MAIN, 0x80020100, "zeta_bad"), "zeta_bad rejected"),
            ("ovl other", ("rockx5", 0x80100200, "fx_spawn_ovl09"), "wrong _ovlNN"),
            ("ovl none", ("rockx5", 0x80100200, "fx_spawn"), "wrong _ovlNN"),
            ("ovl slus", (layout.MAIN, 0x80020100, "alpha_ovl05"), "wrong _ovlNN"),
            ("cycle", (layout.MAIN, 0x80020400, "kappa_next"), "define cycle kappa_alias->kappa_next"),
            ("unknown", (layout.MAIN, 0x80029990, "nu_name"), "unknown alias:vram"),
        ]:
            rc, out = go(*job)
            checks.append((f"4 {tag}", rc == 1 and out == [f"rename: REFUSE {job[0]}:0x{job[1]:08X} {want}"]
                           and digest() == h))
        jobs, skipped = from_rows(scratch, "batch.tsv")
        rc, out = run(scratch, jobs, False)
        checks.append(("4 batch", rc == 1 and out == [f"rename: REFUSE {layout.MAIN}:0x80020300 zeta_bad rejected"]
                       and digest() == h))
        checks.append(("4 skip asm-only", skipped == 1 and [j[2] for j in jobs] == ["delta_run", "zeta_bad"]))
        cases += 1  # (5) --from applies only the uncarried rows; the replaced row turns rejected
        fresh()
        jobs = from_rows(scratch, NAMES)[0]
        rc, out = run(scratch, jobs, False)
        nm, sy = rd(NAMES), rd(cf(f"symbols.{layout.MAIN}.txt"))
        checks += [
            ("5 rows", [j[2] for j in jobs] == ["gamma_read", "delta_run"]),
            ("5 rc", rc == 0 and out[-1].startswith("rename: 2 renamed, ")),
            ("5 rejected", "func_80020300\tgamma_peek\trejected\tfix:3\tfixture row; 3.7 T4: replaced by gamma_read"
             in nm and "func_80020300\tgamma_read\tprovisional\t" in nm),
            ("5 insert", "taken_name = 0x80020500; // type:func\ndelta_run = 0x80020600; // type:func\n" in sy
             and "gamma_read = 0x80020300; // type:func" in sy and (scratch / at(layout.MAIN, "delta_run")).exists()),
        ]
        h = digest()
        rc, out = run(scratch, from_rows(scratch, NAMES)[0], False)
        checks.append(("6 from rerun", rc == 0 and digest() == h and out[-1].startswith("rename: 0 renamed, 0 files")))
        cases += 1  # (8) the body file also holds a second group's body (a run file): renamed in place, path text kept
        run_rel = at("shared", "func_80100200_ovl05").as_posix()  # a one-body file until unit() runs

        def unit():
            fresh()
            body = scratch / run_rel
            body.write_text(body.read_text() + "\nvoid func_80100300_ovl05(void) {\n}\n")
            with open(scratch / layout.DEDUP, "a") as fh:
                fh.write(f"  - group: 8888\n    body: {run_rel}\n    members:\n"
                         "      - {alias: rockx5, module: rockx5/ovl05, vram: 0x80100300, name: func_80100300_ovl05}\n")
            with open(scratch / cf("symbols.rockx5.txt"), "a") as fh:
                fh.write("func_80100300_ovl05 = 0x80100300; // type:func rom:0x2300\n")
            return body.read_text().split("\nvoid func_80100300_ovl05")[1]
        tail = unit()
        rc, out = go("rockx5", 0x80100200, "fx_spawn_ovl05")
        txt, dd = rd(run_rel), rd(layout.DEDUP)
        checks += [
            ("8 run file", rc == 0 and "rename: rockx5:0x80100200 func_80100200_ovl05 -> fx_spawn_ovl05" in out
             and not any(x.startswith("rename: MOVE src/shared/") for x in out)
             and not (scratch / Path(run_rel).with_name("fx_spawn_ovl05.c")).exists()),
            ("8 body", "void fx_spawn_ovl05(void) {" in txt and "func_80100200_ovl05" not in txt
             and txt.split("\nvoid func_80100300_ovl05")[1] == tail),
            ("8 path kept", dd.count(f"body: {run_rel}") == 2 and "name: fx_spawn_ovl05}" in dd
             and "renames: [fx_spawn_ovl05 func_80100A00_ovl08.NON_MATCHING]" in dd
             and '#include "shared/func_80100200_ovl05.c"' in rd(at("rockx5", "fx_spawn_ovl05"))
             and '#include "shared/func_80100200_ovl05.c"' in rd(at("rockx5", "func_80100200_ovl06"))
             and "#define fx_spawn_ovl05 func_80100200_ovl06" in rd(at("rockx5", "func_80100200_ovl06"))),
            ("8 locate", at("shared", "fx_spawn_ovl05").as_posix() == run_rel),
        ]
        cases += 1  # (9) a run file's second body: renamed in place, the file and its first body untouched
        tail = unit()
        head = rd(run_rel).split("\nvoid func_80100300_ovl05")[0]
        rc, out = go("rockx5", 0x80100300, "fx_tail_ovl05")
        txt = rd(run_rel)
        checks.append(("9 second body", rc == 0 and not any(x.startswith("rename: MOVE src/shared/") for x in out)
                       and txt.split("\nvoid fx_tail_ovl05")[0] == head and "void fx_tail_ovl05(void) {" in txt
                       and "name: fx_tail_ovl05}" in rd(layout.DEDUP)))
        cases += 1  # (10) control: a run-file rename still refuses a taken name, nothing written
        unit()
        h = digest()
        rc, out = go("rockx5", 0x80100200, "func_80100300_ovl05")
        checks.append(("10 run taken", rc == 1 and out == ["rename: REFUSE rockx5:0x80100200 "
                                                           "func_80100300_ovl05 already defined"] and digest() == h))
        cases += 1  # (7) --from with an overlay image row (old_name without _ovlNN, as psxd_img.py promote writes)
        fresh()
        (scratch / "ovl.tsv").write_text("kind\timage\tscope\told_name\tnew_name\tdecision\tevidence\treason\n"
                                         "function\tovl08\t\tfunc_80100A00\tomega_bad_ovl07\tprovisional\tfix:9\t\n")
        h = digest()
        rc, out = run(scratch, from_rows(scratch, "ovl.tsv")[0], False)
        checks.append(("7 ovl refuse", rc == 1 and out == ["rename: REFUSE rockx5:0x80100A00 wrong _ovlNN"]
                       and digest() == h))
        (scratch / "ovl.tsv").write_text("kind\timage\tscope\told_name\tnew_name\tdecision\tevidence\treason\n"
                                         "function\tovl07\t\tfunc_80100800\tomega_tick_ovl07\tprovisional\tfix:9\t\n")
        jobs = from_rows(scratch, "ovl.tsv")[0]
        rc, out = run(scratch, jobs, False)
        checks.append(("7 ovl rename", rc == 0 and [j[0] for j in jobs] == ["rockx5"]
                       and "rename: rockx5:0x80100800 func_80100800_ovl07 -> omega_tick_ovl07" in out
                       and "omega_tick_ovl07 = 0x80100800; // type:func rom:0x4800" in rd(cf("symbols.rockx5.txt"))
                       and (scratch / at("rockx5", "omega_tick_ovl07")).exists()))
        cases += 1  # (11) --twin, 3 rockx5 sites (one in a merged unit) and outside callers; a dry run writes nothing
        fresh()
        h = digest()
        rc, out = run_twin(scratch, "func_80110000_ovl11", "zap_spin", True)
        checks.append(("11 dry", rc == 0 and digest() == h and "rename: TWIN src/shared/func_80110000_ovl11.c -> "  # layout: other-tree fixture
                       "src/shared/zap_spin.c" in out and out[-1].startswith("rename: 3 renamed, ")))  # layout: other-tree fixture
        rc, out = run_twin(scratch, "func_80110000_ovl11", "zap_spin", False)
        body, s12, mu = rd("src/shared/zap_spin.c"), rd("src/rockx5/zap_spin_ovl12.c"), rd("src/rockx5/80130000.c")  # layout: other-tree fixture
        dd, sy = rd(layout.DEDUP), rd(cf("symbols.rockx5.txt"))
        checks += [
            ("11 rc", rc == 0 and all(f"rename: rockx5:0x{v} {o} -> zap_spin_{s}" in out for v, o, s in [
                ("80110000", "func_80110000_ovl11", "ovl11"), ("80120000", "func_80120000_ovl12", "ovl12"),
                ("80130100", "func_80130100_ovl13", "ovl13")])),
            ("11 body", '#include "common.h"\n#include "mmx5/ovl.h"\n' in body and "s32 OVL(zap_spin)(s32 a0) {" in body
             and "return OVL(zap_spin)(a0 - 1);" in body and "func_80119990_ovl11();" in body
             and not (scratch / "src/shared/func_80110000_ovl11.c").exists()  # layout: other-tree fixture
             and not (scratch / "src/shared/zap_spin_ovl11.c").exists()),  # layout: other-tree fixture
            ("11 site", '#include "shared/zap_spin.c"' in s12 and "zap_spin_ovl1" not in s12
             and "#define func_80119990_ovl11 func_80129990_ovl12\n" in s12 and "#undef func_80119990_ovl11" in s12),
            ("11 merged", "zap_spin_ovl13(4);" in mu and "#define" not in mu and "#undef" not in mu
             and '#include "shared/zap_spin.c"' in mu),
            ("11 owner", rd("src/rockx5/zap_spin_ovl11.c") == '#include "common.h"\n\n#include "shared/zap_spin.c"\n'),  # layout: other-tree fixture
            ("11 callers", "zap_spin_ovl12(1);" in rd("src/rockx5/func_80120800_ovl12.c")  # layout: other-tree fixture
             and "zap_spin_ovl11(2);" in rd("src/rockx5/func_80110800_ovl11.c")),  # layout: other-tree fixture
            ("11 registry", "body: src/shared/zap_spin.c\n" in dd and all(f"name: zap_spin_ovl{k}}}" in dd  # layout: other-tree fixture
                                                                          for k in ("11", "12", "13"))),
            ("11 symbols", "zap_spin_ovl11 = 0x80110000; // type:func rom:0x7000\n" in sy
             and "zap_spin_ovl13 = 0x80130100; // type:func rom:0x9100\n" in sy),
        ]
        cases += 1  # (12) --twin by body path, a rockx5 owner and a main site
        fresh()
        rc, out = run_twin(scratch, "src/shared/func_80140000_ovl14.c", "zap_tick", False)  # layout: other-tree fixture
        sl = rd(f"src/{layout.MAIN}/zap_tick.c")  # layout: other-tree fixture
        checks += [
            ("12 rc", rc == 0 and f"rename: {layout.MAIN}:0x80040000 func_80040000 -> zap_tick" in out
             and "rename: rockx5:0x80140000 func_80140000_ovl14 -> zap_tick_ovl14" in out),
            ("12 body", rd("src/shared/zap_tick.c") == '/* Shared body (fixture). */\n#include "mmx5/ovl.h"\n'  # layout: other-tree fixture
             'void OVL(zap_tick)(void) {\n}\n'),
            ("12 slus site", sl == '#include "common.h"\n\n#include "shared/zap_tick.c"\n'),
            ("12 symbols", "\nzap_tick = 0x80040000; // type:func\n" in rd(cf(f"symbols.{layout.MAIN}.txt"))
             and "zap_tick_ovl14 = 0x80140000; // type:func rom:0xA000" in rd(cf("symbols.rockx5.txt"))),
        ]
        cases += 1  # (13) --twin refusals write nothing
        fresh()
        with open(scratch / layout.DEDUP, "a") as fh:
            fh.write("  - group: 3333\n    body: src/shared/func_80150000_ovl15.c\n    members:\n"  # layout: other-tree fixture
                     "      - {alias: rockx5, module: rockx5/ovl15_80150000, vram: 0x80150000, name: func_80150000_ovl15}\n"
                     "      - {alias: rockx5, module: rockx5/ovl15_80150000, vram: 0x80150400, name: func_80150400_ovl15}\n"
                     "  - group: 4444\n    body: src/shared/func_80160000_ovl16.c\n    members:\n"  # layout: other-tree fixture
                     "      - {alias: rockx5, module: rockx5/ovl16_80160000, vram: 0x80160000, name: func_80160000_ovl16}\n"
                     "      - {alias: main, module: main/main_80050000, vram: 0x80050000, name: func_80050000}\n"
                     "      - {alias: main, module: main/main_80050400, vram: 0x80050400, name: func_80050400}\n")
        h = digest()
        for key, name, want in [
            ("func_80150000_ovl15", "zap_two", "two members in ovl15"),
            ("func_80160000_ovl16", f"zap_{layout.MAIN}", f"more than one {layout.MAIN} member"),
            ("func_80100200_ovl05", "zap_inline", "inline member func_80100A00_ovl08"),
            ("func_80110000_ovl11", "9zap", "bad name"),
            ("func_80110000_ovl11", "zap_ovl03", "bad name"),
            ("func_80110000_ovl11", "boot_main", "boot_main already defined"),
            ("func_80110000_ovl11", "func_80119990", "func_80119990_ovl11 already defined"),
            ("func_8011FFFF_ovl11", "zap_none", "unknown group"),
        ]:
            rc, out = run_twin(scratch, key, name, False)
            checks.append((f"13 {want}", rc == 1 and out == [f"rename: REFUSE {key} {want}"] and digest() == h))
        unit()
        h = digest()
        rc, out = run_twin(scratch, run_rel, "zap_run", False)
        checks.append(("13 run file", rc == 1 and out == [f"rename: REFUSE {run_rel} run-file body"] and digest() == h))
    finally:
        shutil.rmtree(scratch, ignore_errors=True)
    bad = [n for n, ok in checks if not ok]
    if bad:
        print(f"rename: selftest FAIL {bad[0]}")
        return 1
    print(f"rename: control OK -- {cases} cases")
    return 0


def main(argv):
    if "--selftest" in argv:
        return selftest()
    root = Path(argv[argv.index("--root") + 1]) if "--root" in argv else ROOT
    dry = "--dry-run" in argv
    reason = argv[argv.index("--reason") + 1] if "--reason" in argv else None
    if "--twin" in argv:
        i = argv.index("--twin")
        if len(argv) < i + 3:
            print(__doc__.split("\n\n")[1])
            return 2
        rc, lines = run_twin(root, argv[i + 1], argv[i + 2], dry, reason)
        print("\n".join(lines))
        return rc
    if "--from" in argv:
        path = argv[argv.index("--from") + 1]
        jobs, skipped = from_rows(root, path)
        print(f"rename: from {path}: {len(jobs)} rows to apply")
        if skipped:
            print(f"rename: skipped {skipped} rows not in the build")
    else:
        pos = [a for i, a in enumerate(argv) if not a.startswith("--") and (i == 0 or argv[i - 1] not in
                                                                            ("--root", "--reason", "--from"))]
        if len(pos) != 2:
            print(__doc__.split("\n\n")[1])
            return 2
        m = re.fullmatch(r"(\w+):0x([0-9A-Fa-f]{1,8})", pos[0])
        jobs = [(m.group(1), int(m.group(2), 16), pos[1], pos[0]) if m else ("", None, pos[1], pos[0])]
    rc, lines = run(root, jobs, dry, reason)
    print("\n".join(lines))
    return rc


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
