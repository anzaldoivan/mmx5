"""Lift every struct/union definition out of src/**/*.c into include/types.h.

  lift.py

Each top-level `typedef struct|union [Tag] {..} Name;` or `struct|union Tag {..};` in src/**/*.c (src/shared/ included)
is cut from its file (with the comment lines directly above it) and appended verbatim, in source order, to a delimited
block at the end of include/types.h (before `#endif`). Shapes come from tools/dedup/shapes.py: a def whose shape is
already in types.h is not re-added; under a different name it becomes `typedef <Canonical> <Name>;` (names are kept,
never invented). A source missing `#include "types.h"` gets it. Re-runnable: nothing left to move -> `lift: 0 moves`.
Prints `lift: <n> moves, <d> deduplicated`; exit 1 (nothing written) on a def it cannot place.
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools" / "dedup"))
import shapes  # noqa: E402

TYPES = ROOT / "include" / "types.h"
BEGIN = "/* lift: struct/union definitions lifted from src/ by tools/readability/lift.py */"
END = "/* lift: end */"
START = re.compile(r"^(?:typedef[ \t]+)?(?:struct|union)\b[^;{()=]*\{", re.M)


def defs(raw):
    """-> [(start, end)] character spans of top-level record definitions, incl. attached comment lines above."""
    bare, out, pos = shapes.strip(raw), [], 0
    for m in START.finditer(bare):
        if m.start() < pos:
            continue
        depth, i = 0, m.end() - 1
        while True:
            depth += {"{": 1, "}": -1}.get(bare[i], 0)
            if depth == 0:
                break
            i += 1
        end = bare.index(";", i) + 1
        end = raw.index("\n", end) + 1 if "\n" in raw[end:] else len(raw)
        start = m.start()
        while start > 0:  # attached comment lines: non-blank in raw, blank once stripped
            prev = raw.rfind("\n", 0, start - 1) + 1
            if raw[prev:start].strip() and not bare[prev:start].strip():
                start = prev
            else:
                break
        out.append((start, end))
        pos = end
    return out


def shape_of(c, text):
    """-> (shape key, tag name or None, typedef name or None) via shapes.Checker.record."""
    toks = shapes.tokens(shapes.strip(text)) + [("", 0)] * 4
    i = next(k for k, t in enumerate(toks) if t[0] in ("struct", "union"))
    members, kind, tag, _, _, j, _ = c.record(toks, i, "lift")
    name = toks[j][0] if toks[0][0] == "typedef" else None
    return (kind, members), tag, name


def main():
    c = shapes.Checker()
    types = TYPES.read_text(encoding="utf-8")
    c.file("include/types.h", types)
    added, moves, dedup, edits = [], 0, 0, {}
    for f in sorted((ROOT / "src").rglob("*.c")):
        raw = f.read_text(encoding="utf-8")
        spans = defs(raw)
        if not spans:
            continue
        rel = f.relative_to(ROOT).as_posix()
        for s, e in spans:
            text = raw[s:e].rstrip("\n")
            try:
                key, tag, name = shape_of(c, text)
            except (shapes.Refused, IndexError, StopIteration) as ex:
                print(f"lift: refused {rel}:{raw.count(chr(10), 0, s) + 1}: {ex}")
                return 1
            own = name or tag
            if key in c.shapes and c.shapes[key][0] != own:
                if tag:  # code may say `struct Tag`; a typedef alias cannot provide the tag
                    print(f"lift: refused {rel}: tagged {own} duplicates {c.shapes[key][0]}")
                    return 1
                text = f"typedef {c.shapes[key][0]} {name};"
                dedup += 1
            elif key in c.shapes:
                text = None  # already lifted under this name
            if text:
                c.file("include/types.h", text)
                added.append(f"/* {rel} */\n{text}")
            moves += 1
        out = raw
        for s, e in reversed(spans):
            before, after = out[:s], out[e:]
            if before.endswith("\n\n") and (after.startswith("\n") or not after):
                after = after[1:]
            out = before + after
        if '#include "types.h"' not in out:
            out = '#include "types.h"\n' + out
        edits[f] = out
    if c.errors:
        print("\n".join(c.errors))
        return 1
    if added:
        if BEGIN in types:
            head, tail = types.split(END, 1)
            types = head.rstrip("\n") + "\n\n" + "\n\n".join(added) + "\n" + END + tail
        else:
            head, tail = types.rsplit("#endif", 1)
            types = head.rstrip("\n") + "\n\n" + BEGIN + "\n\n" + "\n\n".join(added) + "\n" + END + "\n\n#endif" + tail
        TYPES.write_text(types, encoding="utf-8")
    for f, out in edits.items():
        f.write_text(out, encoding="utf-8")
    print(f"lift: {moves} moves, {dedup} deduplicated")
    return 0


if __name__ == "__main__":
    if sys.argv[1:]:
        print(__doc__)
        sys.exit(0 if sys.argv[1:] in (["-h"], ["--help"]) else 2)
    sys.exit(main())
