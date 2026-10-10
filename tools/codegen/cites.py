#!/usr/bin/env python3
"""cites.py — audit `gcc/<path>:<line> <symbol>` citations against the staged cc1 source tree.

  check [--docs DIR] [--tree DIR]   scan DIR (default docs/codegen-map) *.md/*.yaml/*.yml; a cite is
                                    stale when the file is missing, the line is out of range, or the
                                    line does not contain the symbol. Exit 1 if any stale / tree unstaged.
  --selftest                        fixture tree + doc (one good, one stale cite); ROM- and network-free.

Tree: refs/gcc-2.95.2-psx/ staged by tools/codegen/stage.sh (.staged records its provenance).
"""
import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
TREE = ROOT / "refs" / "gcc-2.95.2-psx"
DOCS = ROOT / "docs" / "codegen-map"
FIX = Path(__file__).resolve().parent / "fixtures"
CITE = re.compile(r"(gcc/[\w./+-]+?):(\d+)`?\s+`?([A-Za-z_]\w*)`?")


def scan(docs, tree):
    """-> (n, [(docfile, docline, cite, reason)])"""
    n, stale = 0, []
    if not docs.is_dir():
        return n, stale
    files = sorted(p for p in docs.rglob("*") if p.suffix in (".md", ".yaml", ".yml") and p.is_file())
    for doc in files:
        for ln, text in enumerate(doc.read_text(encoding="utf-8", errors="replace").splitlines(), 1):
            for m in CITE.finditer(text):
                n += 1
                path, line, sym = m.group(1), int(m.group(2)), m.group(3)
                src = tree / path
                if not src.is_file():
                    reason = "file missing"
                else:
                    # split on \n only: splitlines() also breaks at \f, which GCC sources use (grep numbering)
                    lines = src.read_text(encoding="latin-1").split("\n")
                    if lines and lines[-1] == "":
                        lines.pop()
                    if not 1 <= line <= len(lines):
                        reason = f"line out of range ({len(lines)} lines)"
                    elif sym not in lines[line - 1]:
                        reason = "symbol not on line"
                    else:
                        continue
                stale.append((doc.relative_to(ROOT) if doc.is_relative_to(ROOT) else doc, ln,
                              f"{path}:{line} {sym}", reason))
    return n, stale


def report(n, stale):
    print(f"cites: {n - len(stale)} of {n} citations resolve, {len(stale)} stale")
    for doc, ln, cite, reason in stale:
        print(f"cites: STALE {doc}:{ln} {cite} {reason}")
    return 1 if stale else 0


def check(docs, tree):
    staged = tree / ".staged"
    if not staged.is_file():
        print(f"cites: tree {tree} unstaged (run bash tools/codegen/stage.sh)")
        return 1
    kv = [l.split("=", 1) for l in staged.read_text().splitlines() if "=" in l]
    sha = next((v for k, v in kv if k == "tarball_sha256"), "?")
    k = sum(1 for key, _ in kv if key == "patch")
    print(f"cites: tree {tree.name} {sha[:12]} +{k} patches")
    return report(*scan(docs, tree))


def selftest():
    n, stale = scan(FIX / "docs", FIX / "tree")
    assert n == 2, n
    assert [s[2] for s in stale] == ["gcc/beta.c:2 fixture_gone"], stale
    print("cites: control OK -- stale citation refused")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", nargs="?", choices=["check"])
    ap.add_argument("--docs", type=Path, default=DOCS)
    ap.add_argument("--tree", type=Path, default=TREE)
    ap.add_argument("--selftest", action="store_true")
    a = ap.parse_args()
    if a.selftest:
        return selftest()
    if a.cmd == "check":
        return check(a.docs.resolve(), a.tree.resolve())
    ap.print_help()
    return 2


if __name__ == "__main__":
    sys.exit(main())
