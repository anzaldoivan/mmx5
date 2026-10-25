#!/usr/bin/env python3
"""Run decomp-permuter (refs/decomp-permuter, `tools/codegen/stage.sh --permuter`) on one draft, counting for itself.

  permute.py run <draft.c> --fn <sym> --iters N [--seed S] [--timeout SEC]
  permute.py --selftest     ROM-free: fixture target, planted idle run must be refused

Stages .run/permuter/<fn>/: base.c (the draft through our cpp, flat), target.o (the function's own bytes from
expected/build/slus/, assembled as .word; never leaves .run/, G12), settings.toml, compile.sh (a logger that
records each candidate's sha1, then runs tools/permuter/compile.sh). Iterations = candidate compiles after the base,
distinct = distinct candidate sha1s, both read from that log, never from the permuter's stdout. base/best are the
stock scorer's scores, recomputed here (base.c and the best output's source.c, compiled and scored).
Exit nonzero when 0 iterations ran.
"""
import argparse
import hashlib
import os
import re
import signal
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
HERE = ROOT / "tools/permuter"
PERMUTER = ROOT / "refs/decomp-permuter"
sys.path.insert(0, str(ROOT / "tools/probe"))
sys.path.insert(0, str(PERMUTER))
import probe  # noqa: E402

CPP = ROOT / "tools/bin/cc/gcc-2.95.2-psx/cpp"
BINUTILS = ROOT / "tools/bin/binutils/usr"
# docs/ops/toolchain.md ## objdump: the deb's objdump needs its own lib dir; host objdump has no MIPS target.
OBJDUMP = f"env LD_LIBRARY_PATH={BINUTILS}/lib/x86_64-linux-gnu {BINUTILS}/bin/mipsel-linux-gnu-objdump -drz"
if not BINUTILS.is_dir():  # system binutils (tools/bootstrap.sh system route; undef_by_name.py likewise)
    OBJDUMP = "mipsel-linux-gnu-objdump -drz"


def sh(cmd, **kw):
    subprocess.run(cmd, check=True, **kw)


def fn_span(fn):
    """(vram, size) of a carved slus subsegment `[rom, c|asm, fn]`: size runs to the next subsegment."""
    lines = (ROOT / "config/splat.slus.yaml").read_text().splitlines()
    roms = [(int(m.group(1), 16), m.group(2)) for m in
            (re.match(r"\s+- \[(0x[0-9A-Fa-f]+), \w+, (\w+)\]", ln) for ln in lines) if m]
    for (rom, name), (nxt, _) in zip(roms, roms[1:]):
        if name == fn:
            return 0x80010000 + rom - 0x800, nxt - rom  # main: start 0x800, vram 0x80010000
    raise SystemExit(f"permute: {fn} is not its own subsegment in config/splat.slus.yaml")


def target_from_rom(fn, out):
    vram, size = fn_span(fn)
    b = probe.target_bytes({"alias": "slus", "vram": vram, "size": size})
    words = ", ".join(f"0x{w:08X}" for w in probe.masked(b, {}))
    s = out / "target.s"
    s.write_text(f".set noreorder\n.set noat\n.text\n.globl {fn}\n{fn}:\n.word {words}\n")
    sh([str(probe.AS), "-EL", "-march=r3000", "-no-pad-sections", "-G0", str(s), "-o", str(out / "target.o")])
    s.unlink()


def stage(draft, fn, out, target_c=None):
    out.mkdir(parents=True, exist_ok=True)
    for p in out.glob("output-*"):
        sh(["rm", "-rf", str(p)])
    (out / "tmp").mkdir(exist_ok=True)
    sh([str(CPP), *probe.CPP_FLAGS, "-P", str(draft), str(out / "base.c")])
    if target_c:
        sh(["bash", str(HERE / "compile.sh"), str(target_c), "-o", str(out / "target.o")])
    else:
        target_from_rom(fn, out)
    (out / "settings.toml").write_text(
        f'func_name = "{fn}"\ncompiler_type = "gcc"\nobjdump_command = "{OBJDUMP}"\n')
    log = out / "compiles.log"
    log.write_text("")
    (out / "compile.sh").write_text(
        "#!/usr/bin/env bash\n# T5.c1: log the candidate's sha1 (permute.py counts these), then compile it.\n"
        f'sha1sum < "$1" | cut -c1-40 >> "{log}"\nexec bash "{HERE}/compile.sh" "$@"\n')
    return log


def score(out, src):
    from src.scorer import Scorer
    sc = Scorer(str(out / "target.o"), stack_differences=False, algorithm="difflib", debug_mode=False,
                ign_branch_targets=True, objdump_command=OBJDUMP)
    o = out / "tmp" / "score.o"
    sh(["bash", str(HERE / "compile.sh"), str(src), "-o", str(o)])
    return sc.score(str(o))[0]


def run(draft, fn, iters, seed, timeout, target_c=None, idle=False):
    out = ROOT / ".run/permuter" / fn
    log = stage(Path(draft).resolve(), fn, out, target_c)
    env = dict(os.environ, TMPDIR=str(out / "tmp"))
    with open(out / "permuter.log", "w") as plog:
        p = subprocess.Popen([sys.executable, str(PERMUTER / "permuter.py"), str(out), "--seed", str(seed),
                              "-j", "1", "--quiet"] + ["--debug"] * idle, stdout=plog, cwd=out, stderr=subprocess.STDOUT, env=env,
                             start_new_session=True)
        deadline = time.monotonic() + timeout
        while p.poll() is None and time.monotonic() < deadline:
            if len(log.read_text().split()) - 1 >= iters:  # line 1 is the base compile
                break
            time.sleep(0.1)
        if p.poll() is None:
            os.killpg(p.pid, signal.SIGKILL)
        p.wait()
    hashes = log.read_text().split()
    cands = hashes[1:]
    i, k = len(cands), len(set(cands))
    base = score(out, out / "base.c")
    outs = sorted(out.glob("output-*/source.c"), key=lambda q: int(q.parent.name.split("-")[1]))
    best = min([base] + [score(out, q) for q in outs[:1]])
    print(f"permuter: {fn} {i} iterations, {k} distinct candidates, base {base} best {best}")
    return 0 if i else 1


def selftest():
    fix = HERE / "fixtures"
    # planted idle run: --debug makes the permuter compile and score the base only, then exit
    idle = run(fix / "near.c", "fixture_fn", 5, 1, 60, target_c=fix / "target.c", idle=True)
    live = run(fix / "near.c", "fixture_fn", 5, 1, 120, target_c=fix / "target.c")
    if idle != 0 and live == 0:
        print("permuter: control OK -- idle run refused")
        return 0
    print(f"permuter: control FAILED -- idle rc {idle}, live rc {live}")
    return 1


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--selftest", action="store_true")
    sub = ap.add_subparsers(dest="cmd")
    r = sub.add_parser("run")
    r.add_argument("draft")
    r.add_argument("--fn", required=True)
    r.add_argument("--iters", type=int, required=True)
    r.add_argument("--seed", type=int, default=1)
    r.add_argument("--timeout", type=int, default=240, help="seconds before the permuter is stopped (default 240)")
    a = ap.parse_args()
    if a.selftest:
        return selftest()
    if a.cmd == "run":
        return run(a.draft, a.fn, a.iters, a.seed, a.timeout)
    ap.print_help()
    return 2


if __name__ == "__main__":
    sys.exit(main())
