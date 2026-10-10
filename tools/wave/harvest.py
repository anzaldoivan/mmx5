"""Harvest check (R8): every banked draft of a wave names its idiom and whether its rider is load-bearing.

  harvest.py check [W<k>] [--waves DIR]
  harvest.py rider <banked.c> <stripped.c> --target <alias>_<name>
  harvest.py --selftest

check: waves/W<k>/harvest.jsonl rows {name, [alias], idiom: C<nnnn>|covered:C<nnnn>|none,
  rider: load-bearing|inert|n/a}. Every `banked` row of waves/W<k>/verdicts.jsonl has exactly one harvest row (matched
  by alias+name when the row gives alias, else by name). A C id must exist as cookbook/C<nnnn>.md; a bad id or a rider
  `inert` is open. Prints `harvest: W<k> <h> of <b> banked harvested, <o> open`; exit 1 unless h == b and o == 0.
  W<k> omitted: every waves/W<k>/ dir (wave.wave_dirs, k ascending), one line each; exit 1 if any fails or no wave.
rider: compiles both files through waves.py try's compile path (wave.compile_func; scratch
  .run/probe/wave/rider/<alias>_<name>/{banked,stripped}/) and compares the function's words and reloc masks:
  differ -> `rider: <name> load-bearing` (exit 0); identical -> `rider: <name> inert` (exit 1); compile error ->
  `rider: <name> error <stage>` (exit 2).
--selftest: tools/wave/fixtures/harvest (synthetic, ROM-free; needs the cc1 toolchain):
  `harvest: control OK -- inert rider refused`.
Stdlib only.
"""

import argparse
import contextlib
import io
import json
import re
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
FIX = Path(__file__).resolve().parent / "fixtures" / "harvest"
sys.path.insert(0, str(ROOT / "tools/wave"))
import waves as wave  # noqa: E402  (tools/wave/waves.py)

IDIOM = re.compile(r"^(?:covered:)?(C\d{4})$")


def cmd_check(waves, wk, cookbook=ROOT / "cookbook"):
    if wk is None:
        return max([cmd_check(waves, w, cookbook) for w in wave.wave_dirs(waves)] or [1])
    wdir = Path(waves) / wk
    banked = [v for v in wave.jsonl(wdir / "verdicts.jsonl") if v["verdict"] == "banked"] \
        if (wdir / "verdicts.jsonl").exists() else []
    rows = wave.jsonl(wdir / "harvest.jsonl") if (wdir / "harvest.jsonl").exists() else []
    h = o = 0
    for v in banked:
        hit = [r for r in rows if r["name"] == v["name"] and r.get("alias", v["alias"]) == v["alias"]]
        if len(hit) != 1:
            print(f"harvest: {v['alias']}_{v['name']} has {len(hit)} rows")
            continue
        h += 1
        r = hit[0]
        m = IDIOM.match(r.get("idiom", ""))
        why = ("bad idiom " + str(r.get("idiom")) if not (m or r.get("idiom") == "none")
               else f"no cookbook/{m[1]}.md" if m and not (Path(cookbook) / f"{m[1]}.md").exists()
               else "rider inert" if r.get("rider") == "inert"
               else None if r.get("rider") in ("load-bearing", "n/a") else f"bad rider {r.get('rider')}")
        if why:
            o += 1
            print(f"harvest: open {v['alias']}_{v['name']} -- {why}")
    print(f"harvest: {wk} {h} of {len(banked)} banked harvested, {o} open")
    return 0 if h == len(banked) and o == 0 else 1


def cmd_rider(banked, stripped, target):
    alias, _, name = target.partition("_")
    got = []
    for src, sub in ((banked, "banked"), (stripped, "stripped")):
        ours, masks, stage = wave.compile_func(src, f"wave/rider/{alias}_{name}/{sub}", name)
        if ours is None:
            print(f"rider: {name} error {stage}")
            return 2
        got.append((ours, sorted(masks.items())))
    same = got[0] == got[1]
    print(f"rider: {name} {'inert' if same else 'load-bearing'}")
    return 1 if same else 0


def selftest():
    tmp = ROOT / ".run/wave/selftest_harvest"
    shutil.rmtree(tmp, ignore_errors=True)
    shutil.copytree(FIX, tmp)

    def call(f, *a):
        b = io.StringIO()
        with contextlib.redirect_stdout(b):
            rc = f(*a)
        return rc, b.getvalue()

    rc, o = call(cmd_rider, tmp / "banked.c", tmp / "inert.c", "slus_hf")
    assert rc == 1 and "rider: hf inert" in o, o
    rc, o = call(cmd_rider, tmp / "banked.c", tmp / "differ.c", "slus_hf")
    assert rc == 0 and "rider: hf load-bearing" in o, o
    waves, cook = tmp / "waves", tmp / "cookbook"
    rc, o = call(cmd_check, waves, "W0", cook)
    assert rc == 0 and "harvest: W0 2 of 2 banked harvested, 0 open" in o, o
    rc, o = call(cmd_check, waves, "W9", cook)
    assert rc == 0 and "harvest: W9 0 of 0 banked harvested, 0 open" in o, o
    (waves / "W10").mkdir()  # all waves (R5): W0 then W10, numeric order; any failing wave fails the run
    rc, o = call(cmd_check, waves, None, cook)
    assert rc == 0 and [x.split()[1] for x in o.splitlines()] == ["W0", "W10"], o
    assert call(cmd_check, tmp / "none", None, cook)[0] == 1
    p = waves / "W0/harvest.jsonl"
    p.write_text(p.read_text().replace('"load-bearing"', '"inert"'))
    rc, o = call(cmd_check, waves, "W0", cook)
    assert rc == 1 and "rider inert" in o and "2 of 2 banked harvested, 1 open" in o, o
    assert call(cmd_check, waves, None, cook)[0] == 1
    p.write_text(p.read_text().replace('"C0001"', '"C0002"'))
    rc, o = call(cmd_check, waves, "W0", cook)
    assert rc == 1 and "no cookbook/C0002.md" in o, o
    p.write_text(p.read_text().splitlines()[0] + "\n")
    rc, o = call(cmd_check, waves, "W0", cook)
    assert rc == 1 and "1 of 2 banked harvested" in o, o
    print("harvest: control OK -- inert rider refused")
    return 0


def main(argv=None):
    argv = sys.argv[1:] if argv is None else argv
    if argv == ["--selftest"]:
        return selftest()
    ap = argparse.ArgumentParser(prog="harvest.py")
    sp = ap.add_subparsers(dest="cmd", required=True)
    c = sp.add_parser("check")
    c.add_argument("wave", nargs="?")
    c.add_argument("--waves", default=str(ROOT / "waves"))
    r = sp.add_parser("rider")
    r.add_argument("banked")
    r.add_argument("stripped")
    r.add_argument("--target", required=True)
    a = ap.parse_args(argv)
    if a.cmd == "check":
        return cmd_check(Path(a.waves), a.wave)
    return cmd_rider(a.banked, a.stripped, a.target)


if __name__ == "__main__":
    sys.exit(main())
