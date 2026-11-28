"""Readability scan over our own C: nine classes of unreadable or unexplained code.

  scan.py [--selftest]

Scans src/**/*.c, src/**/*.h, include/*.h and config/<v>/symbols.*.txt of each registered version
(comment classes: src/**/*.[ch], include/**/*.h).
Classes (tools/readability/README.md):
  pin        `register ... asm("$..")` / `__asm__("$..")` binding without `// !FAKE:` on the same or previous line;
  macro      `#define` whose replacement list has `{` or `;`, or a `\\` continuation, outside include/include_asm.h
             (`#define OVL` exempt);
  cast       integer literal cast to a pointer, outside include/addr.h (comments stripped, #define lines kept);
  duplicate  struct shape duplicate / second definition, from tools/dedup/shapes.py (not re-parsed here);
  struct     struct/union definition (`{`) outside include/;
  name       non-placeholder name in config/<v>/symbols.*.txt or function defined in src/ without a
             config/names.tsv row that is not rejected (symbols match on (image, new_name), src/ on new_name alone;
             absent file = none based); `OVL(x)` is based by a new_name `x_ovl<NN>`;
  taskid     comment holding a W or T id (`W10`, `T4`, `T5.c43`);
  banner     comment with a run of 4+ of one char from `-=*#~_/`;
  endmarker  comment whose whole body is an end marker (`end`, `endif`, `end if|for|while|switch`, `end of <word>`).
The three comment classes read the raw `//` and `/* */` spans and skip a comment holding `!FAKE:`, `DISABLED:`,
`Adapted from`, or whose body starts with `was `.
Prints `readability: <kind> <file>:<line>: <detail>` per offender, then the summary line; exit 1 if any count > 0.
--selftest: tools/readability/fixtures/ (one planted file per class + control.c, kept.c); prints
`readability: control OK -- 9 planted offenders refused; kept markers and OVL(fixovl) passed`.
"""

import contextlib
import io
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
FIX = Path(__file__).resolve().parent / "fixtures"
sys.path.insert(0, str(ROOT / "tools" / "dedup"))
import shapes  # noqa: E402

sys.path.insert(0, str(ROOT / "tools" / "build"))
import layout  # noqa: E402

KINDS = ("pin", "macro", "cast", "duplicate", "struct", "name", "taskid", "banner", "endmarker")
PIN = re.compile(r"\bregister\b[^;]*\b(?:asm|__asm__)\s*\(\s*\"\$")
DEFINE = re.compile(r"^[ \t]*#[ \t]*define[ \t]+(\w+)(\([^)]*\))?(.*)$")
STRUCT = re.compile(r"\b(struct|union)\b\s*(\w*)\s*\{")
FUNC = re.compile(r"^[A-Za-z_][^;{}()=#]*?\b([A-Za-z_]\w*)\s*\([^;{}]*\)\s*\{", re.M)
PLACEHOLDER = re.compile(r"^(func|inl|D|L|jtbl|sub)_[0-9A-Fa-f]{8}(_\w+)?$")
SYMBOL = re.compile(r"^\s*([A-Za-z_]\w*)\s*=")
KEYWORDS = {"if", "for", "while", "switch", "return", "sizeof", "DEDUP_NAME"}  # DEDUP_NAME: the includer names it
COMMENT = re.compile(r"/\*.*?\*/|//[^\n]*", re.S)
OVLARG = re.compile(r"\s*\(\s*(\w+)\s*\)")
TASKID = re.compile(r"\b[WT]\d+(\.c\d+)?\b")
BANNER = re.compile(r"([-=*#~_/])\1{3,}")
ENDMARK = re.compile(r"end|endif|end (if|for|while|switch)|end of \w+", re.I)
KEPT = ("!FAKE:", "DISABLED:", "Adapted from")


def nocomments(text):
    return re.sub(r"/\*.*?\*/|//[^\n]*", lambda m: re.sub(r"[^\n]", " ", m.group()), text, flags=re.S)


def comment_hits(rel, raw):
    """(kind, "file:line", detail) of the taskid, banner and endmarker comments of the raw text."""
    out = []
    for m in COMMENT.finditer(raw):
        c = m.group()
        body = c[2:-2] if c.startswith("/*") else c[2:]
        if any(k in c for k in KEPT) or body.strip().startswith("was "):
            continue
        at, detail = f"{rel}:{lineno(raw, m.start())}", c.splitlines()[0].strip()[:60]
        for kind, hit in (("taskid", TASKID.search(body)), ("banner", BANNER.search(body)),
                          ("endmarker", ENDMARK.fullmatch(body.strip()))):
            if hit:
                out.append((kind, at, detail))
    return out


def lineno(text, pos):
    return text.count("\n", 0, pos) + 1


def basis(root):
    """({(image, new_name)}, {new_name}) of the rows of config/names.tsv (NAME1's columns) that are not rejected."""
    p = root / "config" / "names.tsv"
    if not p.exists():
        return set(), set()
    rows = [ln.split("\t") for ln in p.read_text(encoding="utf-8").splitlines()[1:] if ln.strip()]
    rows = [r for r in rows if len(r) > 5 and r[5] != "rejected"]
    return {("rockx5" if re.fullmatch(r"ovl\d+", r[1]) else r[1], r[4]) for r in rows}, {r[4] for r in rows}


def symbol_files(root):
    """config/<v>/symbols.*.txt under root for each version of config/versions.tsv, placed by layout.config_path."""
    keep, out = layout.version(), []
    for v in layout.versions():
        layout.set_version(v)
        out += sorted(root.glob(str(layout.config_path("symbols.*.txt"))))
    layout.set_version(keep)
    return out


def scan(root):
    out = []  # (kind, "file:line", detail)
    files = sorted((root / "include").glob("*.h")) + sorted((root / "src").rglob("*.[ch]"))
    pairs, names = basis(root)
    for f in files:
        rel = f.relative_to(root).as_posix()
        raw = f.read_text(encoding="utf-8")
        lines, nc, bare = raw.splitlines(), nocomments(raw), shapes.strip(raw)
        for n, ln in enumerate(bare.splitlines(), 1):
            if PIN.search(ln) and not any("!FAKE:" in lines[k] for k in (n - 1, n - 2) if k >= 0):
                out.append(("pin", f"{rel}:{n}", ln.strip()))
        # include_asm.h holds splat's INCLUDE_ASM/INCLUDE_RODATA build macros, not game code
        for n, ln in enumerate(nc.splitlines() if rel != "include/include_asm.h" else [], 1):
            m = DEFINE.match(ln)
            if m and m.group(1) != "OVL" and (ln.rstrip().endswith("\\") or "{" in m.group(3) or ";" in m.group(3)):
                out.append(("macro", f"{rel}:{n}", f"#define {m.group(1)}"))
        if rel != "include/addr.h":
            for m in shapes.CAST.finditer(nc):
                if int(m.group(1), 0) != 0:
                    out.append(("cast", f"{rel}:{lineno(nc, m.start())}", m.group().strip()))
        if not rel.startswith("include/"):
            for m in STRUCT.finditer(bare):
                out.append(("struct", f"{rel}:{lineno(bare, m.start())}", f"{m.group(1)} {m.group(2)}".strip()))
        if rel.startswith("src/") and rel.endswith(".c"):
            for m in FUNC.finditer(bare):
                name = m.group(1)
                if name == "OVL":
                    a = OVLARG.match(bare, m.end(1)).group(1)
                    if not any(re.fullmatch(rf"{a}_ovl\d+", n) for n in names):
                        out.append(("name", f"{rel}:{lineno(bare, m.start(1))}", f"OVL({a})"))
                elif name not in KEYWORDS and not PLACEHOLDER.match(name) and name not in names:
                    out.append(("name", f"{rel}:{lineno(bare, m.start(1))}", name))
    for f in sorted((root / "include").rglob("*.h")) + sorted((root / "src").rglob("*.[ch]")):
        out += comment_hits(f.relative_to(root).as_posix(), f.read_text(encoding="utf-8"))
    for p in symbol_files(root):
        alias = p.name.split(".")[1]
        for n, ln in enumerate(p.read_text(encoding="utf-8").splitlines(), 1):
            m = SYMBOL.match(ln)
            if m and not PLACEHOLDER.match(m.group(1)) and (alias, m.group(1)) not in pairs:
                out.append(("name", f"{p.relative_to(root).as_posix()}:{n}", m.group(1)))
    with contextlib.redirect_stdout(io.StringIO()):  # shapes.run prints its refusals; we re-emit only duplicates
        c, _, _ = shapes.run(shapes.sources(root), root)
    for e in c.errors:
        if "duplicates the shape" in e or "second definition" in e:
            at, why = e.removeprefix("types: refused ").split(": ", 1)
            out.append(("duplicate", at, why))
    return out


def summary(out):
    k = {kind: sum(o[0] == kind for o in out) for kind in KINDS}
    return (f"readability: {k['pin']} unmarked pins, {k['macro']} macro bodies, {k['cast']} raw casts, "
            f"{k['duplicate']} duplicate shapes, {k['struct']} stray structs, {k['name']} unbased names, "
            f"{k['taskid']} task ids, {k['banner']} banners, {k['endmarker']} end markers")


def check():
    out = scan(ROOT)
    for kind, at, detail in out:
        print(f"readability: {kind} {at}: {detail}")
    print(summary(out))
    return 1 if out else 0


def selftest():
    planted = {"pin": ["src/pin.c"], "macro": ["src/macro.c"], "cast": ["src/cast.c"], "duplicate": ["include/dup.h"],
               "struct": ["src/stray.c"], "name": ["src/names.c", "config/us/symbols.fix.txt"],
               "taskid": ["src/taskid.c"], "banner": ["src/banner.c"], "endmarker": ["src/endmarker.c"]}
    got = {}
    for kind, at, _ in scan(FIX):
        got.setdefault(at.rsplit(":", 1)[0], set()).add(kind)
    ok = all(got.get(f) == {kind} for kind, fs in planted.items() for f in fs)
    ok = ok and "src/control.c" not in got and "src/kept.c" not in got and len(got) == sum(map(len, planted.values()))
    if not ok:
        print(f"readability: selftest FAIL {sorted((f, sorted(k)) for f, k in got.items())}")
        return 1
    print(f"readability: control OK -- {len(planted)} planted offenders refused; kept markers and OVL(fixovl) passed")
    return 0


if __name__ == "__main__":
    if sys.argv[1:] == ["--selftest"]:
        sys.exit(selftest())
    if sys.argv[1:]:
        print(__doc__)
        sys.exit(0 if sys.argv[1:] in (["-h"], ["--help"]) else 2)
    sys.exit(check())
