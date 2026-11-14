#!/usr/bin/env python3
"""Run decomp-permuter (refs/decomp-permuter, `tools/codegen/stage.sh --permuter`) on one draft, counting for itself.

  permute.py run <draft.c> --fn <sym> --iters N [--seed S] [--timeout SEC]
  permute.py --selftest     ROM-free: fixture target, planted idle run must be refused

Any .run/census/inventory.jsonl function (slus or rockx5; `--fn` is its name or `<alias>_<name>`): the span is
the row's vram and 4*insns. Stages .run/permuter/<fn>/ (flock'd: a second run on the same fn exits 2): base.c (the
draft through our cpp, flat), target.o (the row's bytes from expected/build/<alias>/, assembled as .word, with our
base compile's relocs re-emitted as .reloc and their fields taken from our word; never leaves .run/, G12),
settings.toml, compile.sh (a logger that records each candidate's sha1, then runs tools/permuter/compile.sh with
BINARY=<alias>). Iterations = candidate compiles after the base,
distinct = distinct candidate sha1s, both read from that log, never from the permuter's stdout. base/best are the
stock scorer's scores, recomputed here (base.c and the best output's source.c, compiled and scored).
Exit nonzero when 0 iterations ran.
"""
import argparse
import contextlib
import fcntl
import hashlib
import json
import os
import re
import signal
import struct
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


INV = ROOT / ".run/census/inventory.jsonl"
RTYPE = {4: "R_MIPS_26", 5: "R_MIPS_HI16", 6: "R_MIPS_LO16", 7: "R_MIPS_GPREL16"}


def field(typ):
    return 0x03FFFFFF if typ == 4 else 0xFFFF


def inv_row(fn, inv=INV):
    """The inventory row whose name (or `<alias>_<name>`) is fn; names are unique."""
    rows = Path(inv).read_text().splitlines() if Path(inv).exists() else []
    for r in map(json.loads, rows):
        if fn in (r["name"], f"{r['alias']}_{r['name']}"):
            return r
    raise SystemExit(f"permute: {fn} is not in {inv}")


def span_bytes(row, root=None):
    """The row's linked bytes (probe.target_bytes; module as waves.unit()). root: a ROM-free stand-in for ROOT
    with config/splat.rockx5.yaml and expected/build/rockx5/ROCK_X5.BIN (the selftest's splat text and BIN)."""
    p = {"alias": row["alias"], "vram": int(row["vram"], 16), "size": 4 * row["insns"],
         "module": row["module"].split("/")[1].split("_")[0] if row["alias"] == "rockx5" else row["module"]}
    old, probe.ROOT = probe.ROOT, Path(root) if root else probe.ROOT
    try:
        return probe.target_bytes(p)
    finally:
        probe.ROOT = old


def compile_c(src, obj, alias):
    """tools/permuter/compile.sh at BINARY=alias; CalledProcessError on a failed compile."""
    sh(["bash", str(HERE / "compile.sh"), str(src), "-o", str(obj)], env=dict(os.environ, BINARY=alias))


def func_relocs(obj, fn):
    """(text bytes of fn, [(offset in fn, type, symbol)]) of an ELF32 LE .o; a section symbol reads as its section's
    name (probe.read_func's walk, keeping the symbol)."""
    d = Path(obj).read_bytes()
    shoff, = struct.unpack_from("<I", d, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 0x2E)
    sh_ = [struct.unpack_from("<IIIIIIIIII", d, shoff + i * shentsize) for i in range(shnum)]
    nm = lambda off, base: d[base + off: d.index(b"\0", base + off)].decode()  # noqa: E731
    sname = [nm(s[0], sh_[shstrndx][4]) for s in sh_]
    ti, si = sname.index(".text"), sname.index(".symtab")
    syms = [struct.unpack_from("<IIIBBH", d, sh_[si][4] + k * 16) for k in range(sh_[si][5] // 16)]
    symname = lambda s: sname[s[5]] if s[3] & 0xF == 3 else nm(s[0], sh_[sh_[si][6]][4])  # noqa: E731  STT_SECTION
    hit = [s for s in syms if s[5] == ti and s[3] & 0xF != 3 and symname(s) == fn]
    if not hit:
        raise SystemExit(f"permute: {fn} is not defined in {obj}")
    value, size = hit[0][1], hit[0][2]
    rels = []
    if ".rel.text" in sname:
        rel = sh_[sname.index(".rel.text")]
        for k in range(rel[5] // 8):
            off, info = struct.unpack_from("<II", d, rel[4] + k * 8)
            if value <= off < value + size:
                if info & 0xFF not in RTYPE:
                    raise SystemExit(f"permute: {fn} +0x{off - value:X} reloc type {info & 0xFF} not handled")
                rels.append((off - value, info & 0xFF, symname(syms[info >> 8])))
    return d[sh_[ti][4] + value: sh_[ti][4] + value + size], rels


def target_from_rom(row, base_o, out, root=None):
    """target.o = the row's linked words; at each reloc of our base compile the field is ours, beside a `.reloc`."""
    fn = row["name"]
    ours, rels = func_relocs(base_o, fn)
    b = span_bytes(row, root)
    tw, ow = list(struct.unpack(f"<{len(b) // 4}I", b)), struct.unpack(f"<{len(ours) // 4}I", ours)
    rels = [r for r in rels if r[0] // 4 < len(tw)]
    for off, typ, _ in rels:
        f = field(typ)
        tw[off // 4] = (tw[off // 4] & ~f & 0xFFFFFFFF) | (ow[off // 4] & f)
    words = ", ".join(f"0x{w:08X}" for w in tw)
    relocs = "".join(f".reloc {off}, {RTYPE[typ]}, {sym}\n" for off, typ, sym in rels)
    secs = "".join(f".section {x}\n" for x in sorted({r[2] for r in rels if r[2].startswith(".")} - {".text"}))
    s = out / "target.s"
    s.write_text(f".set noreorder\n.set noat\n.text\n.globl {fn}\n{fn}:\n.word {words}\n{relocs}{secs}")
    sh([str(probe.AS), "-EL", "-march=r3000", "-no-pad-sections", "-G0", str(s), "-o", str(out / "target.o")])
    s.unlink()


@contextlib.contextmanager
def locked(out, fn):
    """One run per fn: an flock on out/.lock; a second holder refuses with one line, exit 2."""
    out.mkdir(parents=True, exist_ok=True)
    with open(out / ".lock", "w") as fd:
        try:
            fcntl.flock(fd, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except BlockingIOError:
            print(f"permute: {fn} refused -- another run holds {out / '.lock'}")
            sys.exit(2)
        yield


def stage(draft, row, out, target_c=None, root=None):
    alias = row["alias"]
    for p in out.glob("output-*"):
        sh(["rm", "-rf", str(p)])
    (out / "tmp").mkdir(exist_ok=True)
    sh([str(CPP), *probe.CPP_FLAGS, "-P", str(draft), str(out / "base.c")])
    if target_c:
        compile_c(target_c, out / "target.o", alias)
    else:
        compile_c(out / "base.c", out / "tmp/base.o", alias)
        target_from_rom(row, out / "tmp/base.o", out, root)
    (out / "settings.toml").write_text(
        f'func_name = "{row["name"]}"\ncompiler_type = "gcc"\nobjdump_command = "{OBJDUMP}"\n')
    log = out / "compiles.log"
    log.write_text("")
    (out / "compile.sh").write_text(
        "#!/usr/bin/env bash\n# T5.c1: log the candidate's sha1 (permute.py counts these), then compile it.\n"
        f'sha1sum < "$1" | cut -c1-40 >> "{log}"\nBINARY={alias} exec bash "{HERE}/compile.sh" "$@"\n')
    return log


def score(out, src, alias):
    from src.scorer import Scorer
    sc = Scorer(str(out / "target.o"), stack_differences=False, algorithm="difflib", debug_mode=False,
                ign_branch_targets=True, objdump_command=OBJDUMP)
    o = out / "tmp" / "score.o"
    compile_c(src, o, alias)
    return sc.score(str(o))[0]


def run(draft, fn, iters, seed, timeout, target_c=None, idle=False, inv=INV, root=None):
    row = {"alias": "slus", "name": fn} if target_c else inv_row(fn, inv)
    fn = row["name"]
    out = ROOT / ".run/permuter" / fn
    with locked(out, fn):
        log = stage(Path(draft).resolve(), row, out, target_c, root)
        env = dict(os.environ, TMPDIR=str(out / "tmp"))
        with open(out / "permuter.log", "w") as plog:
            p = subprocess.Popen([sys.executable, str(PERMUTER / "permuter.py"), str(out), "--seed", str(seed),
                                  "-j", "1", "--quiet"] + ["--debug"] * idle, stdout=plog, cwd=out,
                                 stderr=subprocess.STDOUT, env=env, start_new_session=True)
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
        base = score(out, out / "base.c", row["alias"])
        outs = sorted(out.glob("output-*/source.c"), key=lambda q: int(q.parent.name.split("-")[1]))
        best = min([base] + [score(out, q, row["alias"]) for q in outs[:1]])
    print(f"permuter: {fn} {i} iterations, {k} distinct candidates, base {base} best {best}")
    return 0 if i else 1


def fixture_root(d):
    """ROM-free rockx5 stand-in under d: inventory.jsonl (one row, alias rockx5), config/splat.rockx5.yaml (one
    segment) and expected/build/rockx5/ROCK_X5.BIN, built from fixtures/reloc.c's own compile with nonzero fake
    "linked" values in its reloc fields. -> (inventory path, row)."""
    fn, vram, start = "fixture_reloc", 0x80100000, 0x100
    (d / "config").mkdir(parents=True, exist_ok=True)
    (d / "expected/build/rockx5").mkdir(parents=True, exist_ok=True)
    compile_c(HERE / "fixtures/reloc.c", d / "reloc.o", "rockx5")
    text, rels = func_relocs(d / "reloc.o", fn)
    w = list(struct.unpack(f"<{len(text) // 4}I", text))
    for off, typ, _ in rels:
        f = field(typ)
        w[off // 4] = (w[off // 4] & ~f & 0xFFFFFFFF) | ((0x1234 + off) & f)
    (d / "expected/build/rockx5/ROCK_X5.BIN").write_bytes(bytes(start) + struct.pack(f"<{len(w)}I", *w) + bytes(16))
    (d / "config/splat.rockx5.yaml").write_text(
        f"segments:\n  - name: ovl99\n    type: code\n    start: 0x{start:X}\n    vram: 0x{vram:X}\n")
    row = {"alias": "rockx5", "module": f"rockx5/ovl99_{vram:X}", "kind": "game", "name": fn,
           "vram": f"{vram:X}", "insns": len(w), "status": "c"}
    (d / "inventory.jsonl").write_text(json.dumps(row) + "\n")
    return d / "inventory.jsonl", row


def selftest():
    fix = HERE / "fixtures"
    # planted idle run: --debug makes the permuter compile and score the base only, then exit
    idle = run(fix / "near.c", "fixture_fn", 5, 1, 60, target_c=fix / "target.c", idle=True)
    live = run(fix / "near.c", "fixture_fn", 5, 1, 120, target_c=fix / "target.c")
    # rockx5 reloc-aware target: our own C scores 0 against fake-linked fields, a planted constant scores > 0
    d = ROOT / ".run/permuter/selftest-rockx5"
    inv, row = fixture_root(d)
    (d / "planted.c").write_text((fix / "reloc.c").read_text().replace("+ 3;", "+ 4;"))
    out = ROOT / ".run/permuter" / row["name"]
    scores = []
    for src in (fix / "reloc.c", d / "planted.c"):
        with locked(out, row["name"]):
            stage(src, inv_row(row["name"], inv), out, root=d)
            scores.append(score(out, out / "base.c", "rockx5"))
    if idle != 0 and live == 0 and scores[0] == 0 and scores[1] > 0:
        print("permuter: control OK -- idle run refused")
        return 0
    print(f"permuter: control FAILED -- idle rc {idle}, live rc {live}, rockx5 own {scores[0]} planted {scores[1]}")
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
