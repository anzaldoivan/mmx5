"""Readability scan over our own C: six classes of unreadable or unexplained code.

  scan.py [--selftest]

Scans src/**/*.c, src/**/*.h, include/*.h and config/symbols.*.txt. Classes (tools/readability/README.md):
  pin        `register ... asm("$..")` / `__asm__("$..")` binding without `// !FAKE:` on the same or previous line;
  macro      `#define` whose replacement list has `{` or `;`, or a `\\` continuation, outside include/include_asm.h;
  cast       integer literal cast to a pointer, outside include/addr.h (comments stripped, #define lines kept);
  duplicate  struct shape duplicate / second definition, from tools/dedup/shapes.py (not re-parsed here);
  struct     struct/union definition (`{`) outside include/;
  name       non-placeholder name in config/symbols.*.txt or function defined in src/ without a
             config/names.tsv row that is not rejected (symbols match on (image, new_name), src/ on new_name alone;
             absent file = none based).
Prints `readability: <kind> <file>:<line>: <detail>` per offender, then the summary line; exit 1 if any count > 0.
--selftest: tools/readability/fixtures/ (one planted file per class + control.c); prints
`readability: control OK -- 6 planted offenders refused`.
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

KINDS = ("pin", "macro", "cast", "duplicate", "struct", "name")
PIN = re.compile(r"\bregister\b[^;]*\b(?:asm|__asm__)\s*\(\s*\"\$")
DEFINE = re.compile(r"^[ \t]*#[ \t]*define[ \t]+(\w+)(\([^)]*\))?(.*)$")
STRUCT = re.compile(r"\b(struct|union)\b\s*(\w*)\s*\{")
FUNC = re.compile(r"^[A-Za-z_][^;{}()=#]*?\b([A-Za-z_]\w*)\s*\([^;{}]*\)\s*\{", re.M)
PLACEHOLDER = re.compile(r"^(func|inl|D|L|jtbl|sub)_[0-9A-Fa-f]{8}(_\w+)?$")
SYMBOL = re.compile(r"^\s*([A-Za-z_]\w*)\s*=")
KEYWORDS = {"if", "for", "while", "switch", "return", "sizeof", "DEDUP_NAME"}  # DEDUP_NAME: the includer names it


def nocomments(text):
    return re.sub(r"/\*.*?\*/|//[^\n]*", lambda m: re.sub(r"[^\n]", " ", m.group()), text, flags=re.S)


def lineno(text, pos):
    return text.count("\n", 0, pos) + 1


def basis(root):
    """({(image, new_name)}, {new_name}) of the rows of config/names.tsv (NAME1's columns) that are not rejected."""
    p = root / "config" / "names.tsv"
    if not p.exists():
        return set(), set()
    rows = [ln.split("\t") for ln in p.read_text(encoding="utf-8").splitlines()[1:] if ln.strip()]
    rows = [r for r in rows if len(r) > 5 and r[5] != "rejected"]
    return {(r[1], r[4]) for r in rows}, {r[4] for r in rows}


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
            if m and (ln.rstrip().endswith("\\") or "{" in m.group(3) or ";" in m.group(3)):
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
                if name not in KEYWORDS and not PLACEHOLDER.match(name) and name not in names:
                    out.append(("name", f"{rel}:{lineno(bare, m.start(1))}", name))
    for p in sorted((root / "config").glob("symbols.*.txt")):
        alias = p.name.split(".")[1]
        for n, ln in enumerate(p.read_text(encoding="utf-8").splitlines(), 1):
            m = SYMBOL.match(ln)
            if m and not PLACEHOLDER.match(m.group(1)) and (alias, m.group(1)) not in pairs:
                out.append(("name", f"config/{p.name}:{n}", m.group(1)))
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
            f"{k['duplicate']} duplicate shapes, {k['struct']} stray structs, {k['name']} unbased names")


def check():
    out = scan(ROOT)
    for kind, at, detail in out:
        print(f"readability: {kind} {at}: {detail}")
    print(summary(out))
    return 1 if out else 0


def selftest():
    planted = {"pin": ["src/pin.c"], "macro": ["src/macro.c"], "cast": ["src/cast.c"], "duplicate": ["include/dup.h"],
               "struct": ["src/stray.c"], "name": ["src/names.c", "config/symbols.fix.txt"]}
    got = {}
    for kind, at, _ in scan(FIX):
        got.setdefault(at.rsplit(":", 1)[0], set()).add(kind)
    ok = all(got.get(f) == {kind} for kind, fs in planted.items() for f in fs)
    ok = ok and "src/control.c" not in got and len(got) == sum(map(len, planted.values()))
    if not ok:
        print(f"readability: selftest FAIL {sorted((f, sorted(k)) for f, k in got.items())}")
        return 1
    print(f"readability: control OK -- {len(planted)} planted offenders refused")
    return 0


if __name__ == "__main__":
    if sys.argv[1:] == ["--selftest"]:
        sys.exit(selftest())
    if sys.argv[1:]:
        print(__doc__)
        sys.exit(0 if sys.argv[1:] in (["-h"], ["--help"]) else 2)
    sys.exit(check())
