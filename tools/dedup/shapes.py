"""Type check over our own C: one definition per name, one name per shape, no raw address casts.

  shapes.py check | --selftest

check scans src/**/*.c (src/shared/ included), include/*.h. Each file is parsed once, so a header included by many
sources is one definition. Supported subset: tools/dedup/README.md. Unsupported struct syntax is refused (G28).

Refusals (exit 1, one line each, `types: refused <file>:<line>: <why>`):
  - a struct/union whose member (type, offset) sequence equals an earlier one's under a different name;
  - a second definition of a typedef name or struct/union tag;
  - a raw address cast: a nonzero integer literal cast to a pointer, `(T *)0x8...` (`T *p = 0;` is allowed);
  - a struct member whose leading `/* 0xNN */` comment differs from its computed offset.
Plain char is unsigned char (-D__CHAR_UNSIGNED__). Offsets use psx sizes: char 1, short 2, int/long/pointer 4, natural alignment, arrays.
Success prints `types: <n> shapes, 0 duplicates, 0 raw casts`, exit 0.
--selftest: tools/dedup/fixtures/{clean,dup,cast}; prints `shapes: control OK -- planted duplicate refused`.
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
FIX = Path(__file__).resolve().parent / "fixtures"

SCALAR = {  # canonical name -> size (alignment = size)
    "char": 1, "signed char": 1, "unsigned char": 1, "short": 2, "unsigned short": 2,
    "int": 4, "unsigned int": 4, "long": 4, "unsigned long": 4, "void": 0,
}
QUAL = {"const", "volatile", "register", "static", "extern"}
TOK = re.compile(r"[A-Za-z_]\w*|0[xX][0-9A-Fa-f]+|\d+|\"(?:\\.|[^\"])*\"|'(?:\\.|[^'])*'|\S")
CAST = re.compile(r"\(\s*[A-Za-z_][\w\s]*?\*[\s*]*\)\s*\(*\s*(0[xX][0-9A-Fa-f]+|\d+)")


class Refused(Exception):
    pass


def strip(text):
    """Comments and preprocessor lines -> blanks, newlines kept so line numbers hold."""
    text = re.sub(r"/\*.*?\*/|//[^\n]*", lambda m: re.sub(r"[^\n]", " ", m.group()), text, flags=re.S)
    return re.sub(r"^[ \t]*#(?:[^\n]*\\\n)*[^\n]*", lambda m: re.sub(r"[^\n]", " ", m.group()), text, flags=re.M)


def tokens(text):
    out, line, pos = [], 1, 0
    for m in TOK.finditer(text):
        line += text.count("\n", pos, m.start())
        pos = m.start()
        out.append((m.group(), line))
    return out


class Checker:
    def __init__(self):
        self.types = {}   # typedef name / "struct tag" -> (canonical, size, align)
        self.where = {}   # name -> "file:line" of its definition
        self.shapes = {}  # member sequence -> (name, file:line)
        self.errors = []
        self.at, self.notes = "", {}  # current file; line -> the offset its leading `/* 0xNN */` comment names

    def refuse(self, at, why):
        self.errors.append(f"types: refused {at}: {why}")

    def define(self, name, info, at):
        if name in self.types:
            raise Refused(f"second definition of {name} (first at {self.where[name]})")
        self.types[name], self.where[name] = info, at

    def base(self, toks, i):
        """Parse a type specifier at toks[i] -> (canonical, size, align, next i)."""
        words = []
        while i < len(toks) and toks[i][0] in QUAL:
            i += 1
        t = toks[i][0]
        if t in ("struct", "union"):
            if toks[i + 1][0] == "{":
                raise Refused("nested struct/union definition (unsupported)")
            key = f"{t} {toks[i + 1][0]}"
            if key not in self.types:
                raise Refused(f"unknown type {key}")
            return (*self.types[key], i + 2)
        while i < len(toks) and toks[i][0] in ("signed", "unsigned", "char", "short", "int", "long"):
            words.append(toks[i][0])
            i += 1
        if words:
            sign = "unsigned " if "unsigned" in words else ("signed " if "signed" in words else "")
            core = [w for w in words if w not in ("signed", "unsigned")]
            core = "char" if "char" in core else "short" if "short" in core else "long" if "long" in core else "int"
            name = (sign if core == "char" or sign == "unsigned " else "") + core
            name = "unsigned char" if name == "char" else name  # -D__CHAR_UNSIGNED__
            return name, SCALAR[name], SCALAR[name], i
        if t == "void":
            return "void", 0, 1, i + 1
        if t in self.types:
            return (*self.types[t], i + 1)
        raise Refused(f"unknown type {t}")

    def declarator(self, toks, i, base):
        """`*`* name `[N]`* -> (name, canonical, size, align, next i)."""
        canon, size, align = base
        while toks[i][0] in ("*",) or toks[i][0] in QUAL:
            if toks[i][0] == "*":
                canon, size, align = canon + "*", 4, 4
            i += 1
        if toks[i][0] == "(":
            raise Refused("function pointer declarator (unsupported)")
        name = toks[i][0]
        if not re.fullmatch(r"[A-Za-z_]\w*", name):
            raise Refused(f"unexpected token {name!r} in declarator")
        i += 1
        dims = []
        while toks[i][0] == "[":
            j = i + 1
            expr = []
            while toks[j][0] != "]":
                expr.append(toks[j][0])
                j += 1
            s = " ".join(expr)
            if not re.fullmatch(r"[\s0-9A-Fa-fxX()+\-*/]+", s):
                raise Refused(f"array size {s!r} is not an integer expression (unsupported)")
            dims.append(int(eval(s.replace("/", "//"), {"__builtins__": {}})))  # ponytail: literals only
            i = j + 1
        if toks[i][0] == ":":
            raise Refused("bitfield (unsupported)")
        for d in reversed(dims):
            canon, size = f"{canon}[{d}]", size * d
        return name, canon, size, align, i

    def body(self, toks, i, kind):
        """toks[i] == '{' -> (members, size, align, next i after '}')."""
        i += 1
        members, off, size, align = [], 0, 0, 1
        while toks[i][0] != "}":
            line = toks[i][1]
            base = self.base(toks, i)
            i = base[3]
            while True:
                _, canon, msize, malign, i = self.declarator(toks, i, base[:3])
                if kind == "struct":
                    off = (off + malign - 1) // malign * malign
                    note = self.notes.pop(line, off)
                    if note != off:
                        self.refuse(f"{self.at}:{line}", f"member offset 0x{off:X}, comment says 0x{note:X}")
                    members.append((canon, off))
                    off += msize
                    size = off
                else:
                    members.append((canon, 0))
                    size = max(size, msize)
                align = max(align, malign)
                if toks[i][0] == ",":
                    i += 1
                    continue
                if toks[i][0] != ";":
                    raise Refused(f"expected ';' in {kind} body, got {toks[i][0]!r}")
                i += 1
                break
        size = (size + align - 1) // align * align
        return tuple(members), size, align, i + 1

    def record(self, toks, i, path):
        """toks[i] is struct/union. Returns (canonical, size, align, next i, at) or None if no body here."""
        kind, at = toks[i][0], f"{path}:{toks[i][1]}"
        tag = None
        j = i + 1
        if re.fullmatch(r"[A-Za-z_]\w*", toks[j][0]):
            tag, j = toks[j][0], j + 1
        if toks[j][0] != "{":
            return None
        members, size, align, j = self.body(toks, j, kind)
        name = f"{kind} {tag}" if tag else None
        return members, kind, name, size, align, j, at

    def shape(self, members, kind, name, at):
        key = (kind, members)
        if key in self.shapes and self.shapes[key][0] != name:
            prev = self.shapes[key]
            raise Refused(f"{name} duplicates the shape of {prev[0]} ({prev[1]})")
        self.shapes.setdefault(key, (name, at))

    def file(self, path, text):
        clean = strip(text)
        self.at = path
        self.notes = {n: int(m[1], 16) for n, ln in enumerate(text.splitlines(), 1)
                      if (m := re.match(r"\s*/\*\s*0x([0-9A-Fa-f]+)\s*\*/", ln))}
        for n, line in enumerate(clean.splitlines(), 1):
            for m in CAST.finditer(line):
                if int(m.group(1), 0) != 0:
                    self.refuse(f"{path}:{n}", f"raw address cast {m.group().strip()!r}")
        toks = tokens(clean) + [("", 0)] * 4
        i = 0
        while toks[i][0]:
            t, line = toks[i]
            at = f"{path}:{line}"
            try:
                if t == "typedef":
                    i += 1
                    if toks[i][0] in ("struct", "union"):
                        rec = self.record(toks, i, path)
                    else:
                        rec = None
                    if rec:
                        members, kind, tagname, size, align, i, _ = rec
                        if tagname:
                            self.define(tagname, (tagname, size, align), at)
                        names = []
                        while toks[i][0] != ";":
                            if toks[i][0] != ",":
                                names.append(toks[i][0])
                            i += 1
                        if len(names) != 1 or not re.fullmatch(r"[A-Za-z_]\w*", names[0]):
                            raise Refused("typedef of a record must name exactly one plain type (unsupported)")
                        self.shape(members, kind, names[0], at)
                        self.define(names[0], (tagname or names[0], size, align), at)
                    else:
                        base = self.base(toks, i)
                        name, canon, size, align, i = self.declarator(toks, base[3], base[:3])
                        if toks[i][0] != ";":
                            raise Refused("typedef with several declarators (unsupported)")
                        self.define(name, (canon, size, align), at)
                    i += 1
                    continue
                if t in ("struct", "union"):
                    rec = self.record(toks, i, path)
                    if rec:
                        members, kind, tagname, size, align, i, _ = rec
                        if not tagname:
                            raise Refused("anonymous struct/union outside a typedef (unsupported)")
                        self.shape(members, kind, tagname, at)
                        self.define(tagname, (tagname, size, align), at)
                        continue
            except Refused as e:
                self.refuse(at, str(e))
                while toks[i][0] and toks[i][0] != ";":  # resync after the statement
                    i += 1
            except IndexError:
                self.refuse(at, "unterminated declaration (unsupported)")
                break
            i += 1


def run(files, root):
    c = Checker()
    for f in files:
        try:
            text = f.read_text(encoding="utf-8")
        except FileNotFoundError:  # globbed, then deleted by a concurrent writer: not ours to check
            continue
        c.file(f.relative_to(root).as_posix(), text)
    for e in c.errors:
        print(e)
    casts = sum("raw address cast" in e for e in c.errors)
    dups = sum("duplicates the shape" in e or "second definition" in e for e in c.errors)
    return c, dups, casts


def sources(root):
    src = sorted((root / "src").rglob("*.c"))  # includes src/shared/ when present
    # types.h first: other headers (addr.h) use its typedefs
    return sorted((root / "include").glob("*.h"), key=lambda p: (p.name != "types.h", p.name)) + src


def check(root=ROOT):
    c, dups, casts = run(sources(root), root)
    if c.errors:
        print(f"types: {len(c.shapes)} shapes, {dups} duplicates, {casts} raw casts; {len(c.errors)} refused")
        return 1
    print(f"types: {len(c.shapes)} shapes, 0 duplicates, 0 raw casts")
    return 0


def selftest():
    res = {}
    for case in ("clean", "dup", "cast"):
        files = sorted((FIX / case).glob("*.[ch]"))
        res[case] = run(files, FIX)
    ok = (not res["clean"][0].errors and res["dup"][1] >= 1 and res["cast"][2] >= 1
          and res["clean"][0].shapes)
    if not ok:
        print("shapes: selftest FAIL")
        return 1
    print("shapes: control OK -- planted duplicate refused")
    return 0


def main(argv):
    if argv == ["check"]:
        return check()
    if argv == ["--selftest"]:
        return selftest()
    print(__doc__)
    return 0 if argv in (["-h"], ["--help"]) else 2


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
