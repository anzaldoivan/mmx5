#!/usr/bin/env python3
"""levers.py — prove codegen levers: a C reproducer pair whose codegen differs in a named tell.

  check            per docs/codegen-map/levers.yaml record: compile before/after at the pin; the tell regex
                   must match before.cc.s and not after.cc.s, and the masked words of `fn` must differ.
                   Prints `levers: <g> of 4 pass groups proven, <n> of <m> levers byte-proven`; exit 1 on any FAIL.
  dump <file.c>    compile at the pin with cc1 -da; per-pass RTL dumps land in .run/codegen/dumps/<stem>/.
  --selftest       planted inert lever (fixtures/levers/, same codegen both sides) must be refused; ROM-free.

levers.yaml is JSON (valid YAML; no yaml module under PY): a list of
{id, group: sched|regalloc|loop|cse_expr, tell, before, after, fn, cite, cookbook, proven_on}.
Side copies: .run/codegen/levers/<id>/{before,after}.cc.s.
"""
import argparse
import json
import re
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT / "tools/probe"), str(ROOT / "tools/dedup")]
import probe  # noqa: E402
import reconcile  # noqa: E402

LEVERS = ROOT / "docs/codegen-map/levers.yaml"
FIX = Path(__file__).resolve().parent / "fixtures/levers"
GROUPS = ("sched", "regalloc", "loop", "cse_expr")
RUN = ROOT / ".run/codegen"


def prove(rec):
    """-> None (proven) or a failure reason."""
    t = reconcile.triple()
    out = RUN / "levers" / rec["id"]
    out.mkdir(parents=True, exist_ok=True)
    words = {}
    for side in ("before", "after"):
        obj, stage = probe.compile_obj(ROOT / rec[side], f"levers-{rec['id']}-{side}", t)
        if obj is None:
            return f"{side} compile failed at {stage}"
        shutil.copy(obj.parent / "probe.cc.s", out / f"{side}.cc.s")
        try:
            words[side] = probe.read_func(obj, rec["fn"])
        except KeyError:
            return f"{side} has no symbol {rec['fn']}"
    tell = re.compile(rec["tell"], re.M)
    if not tell.search((out / "before.cc.s").read_text()):
        return "tell absent in before"
    if tell.search((out / "after.cc.s").read_text()):
        return "tell present in after"
    (b, bm), (a, am) = words["before"], words["after"]
    if probe.diff_words(b, a, {**bm, **am}) == 0:
        return "masked words identical"
    return None


def check(path=LEVERS):
    recs = json.loads(path.read_text())
    ok, groups, bad = 0, set(), 0
    for rec in recs:
        why = "unknown group " + str(rec.get("group")) if rec.get("group") not in GROUPS else prove(rec)
        if why:
            bad += 1
            print(f"levers: FAIL {rec['id']} {why}")
        else:
            ok += 1
            groups.add(rec["group"])
    print(f"levers: {len(groups)} of 4 pass groups proven, {ok} of {len(recs)} levers byte-proven")
    return 1 if bad else 0


def dump(src):
    src = Path(src).resolve()
    out = RUN / "dumps" / src.stem
    out.mkdir(parents=True, exist_ok=True)
    t = reconcile.triple()
    # cc1 names dumps <dumpbase>.<pass>; -da = every pass (refs/gcc-2.95.2-psx/gcc/toplev.c:4936)
    t = dict(t, cflags=t["cflags"] + ["-da", "-dumpbase", str(out / src.name)])
    obj, stage = probe.compile_obj(src, f"dump-{src.stem}", t)
    if obj is None:
        print(f"levers: dump {src.name} failed at {stage}")
        return 1
    print(f"levers: dump {src.name} -> {out.relative_to(ROOT)} ({len(list(out.iterdir()))} files)")
    return 0


def selftest():
    rec = {"id": "selftest-inert", "group": "cse_expr", "tell": r"\baddu\b", "fn": "fixture_inert",
           "before": str(FIX / "inert.before.c"), "after": str(FIX / "inert.after.c")}
    why = prove(rec)
    assert why in ("tell present in after", "masked words identical"), why
    print("levers: control OK -- inert lever refused")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", nargs="?", choices=["check", "dump"])
    ap.add_argument("file", nargs="?")
    ap.add_argument("--selftest", action="store_true")
    a = ap.parse_args()
    if a.selftest:
        return selftest()
    if a.cmd == "check":
        return check()
    if a.cmd == "dump" and a.file:
        return dump(a.file)
    ap.print_help()
    return 2


if __name__ == "__main__":
    sys.exit(main())
