#!/usr/bin/env python3
"""The reconcile ladder: bank one dedup member (a shared body + a generated member file) rung by rung.

  reconcile.py r1   <alias> <vram> --body F [--module M] [--def K=V]... [--plain]
  reconcile.py bank <alias> <vram> --body F [--module M] [--def K=V]... [--plain] [--slate]
  reconcile.py verify <alias> <vram> [--module M]
  reconcile.py --selftest

Member text (generated): comment, `#include "types.h"`, `#define DEDUP_NAME <name>`, one `#define K V` per --def,
  r3's extern decls, `#include "../shared/<body basename>"`. <name> = carve.plan's function name.
r1: compile the member text standalone (.run/reconcile/src/<alias>/, shared -> body dir) with the pinned triple,
  masked compare (probe.read_func/masked) with probe.target_bytes; equal -> record the body hash to
  .run/reconcile/<alias>_<vram>.json. Body hash = sha1 of the text between the body's outermost braces,
  whitespace runs collapsed (the expert may reformat, never redraft).
bank: refuse (exit 1) without an r1 record or when the body hash changed. Then each rung probes first:
  r2 carve.apply(--body member text)   r3 decl sync (-Wimplicit; extern per implicitly declared callee)
  r4 masked compare of the carved TU (casts not automated: a differing word is FAIL)
  r5 the make object build/<a>/src/<a>/<name>.o vs target   r6 `make split build BINARY=<a>` (whole-binary SHA)
  Prints `reconcile: <rung> <applied|not needed|FAIL>`; r4-r6 are checks: green = `not needed`. Last line
  `reconcile: <name> banked at rung <r>, body unchanged` (r = last applied rung). Any FAIL -> carve.revert, exit 1.
verify (a banked member, re-checked): the r1 record .run/reconcile/<alias>_<vram>[_<module>].json (missing -> exit 1;
  the module suffix keeps same-vram overlay members apart; a legacy unsuffixed record of the same module still reads),
  body hash == record, the yaml `c` cut and src/<alias>/<name>.c including the body present, r1 re-run standalone on
  the current member file text (masked equal), r5 object masked equal. Rung = r3 if the member file carries externs,
  else r2. Last line `reconcile: <name> banked at rung <r>, body unchanged`; any mismatch `reconcile: FAIL ...`, exit 1.
--selftest: tools/dedup/fixtures/reconcile (hand-written C) over the carve fixture, scratch .run/reconcile/selftest;
  the banked fixture must verify, the changed body must fail verify.
fmt(path): `$CLANG_FORMAT -i --style=file` (default .venv/bin/clang-format; missing = exit), run by every bank
  writer (bank, propagate.gate, wave/gate.propagate_rep) before its compare; --selftest's fmt control: a
  mis-formatted C fails `--dry-run --Werror` before fmt and passes after. Plain verify formats the expected text.
--plain (plain-draft mode, tools/wave/gate.py): --body is a whole-function draft TU, not a src/shared body. The C
  text is the draft itself, r3 externs inserted after its last `#include`; body hash = the whole draft, whitespace
  runs collapsed; the r1 record carries `plain` and the externs (r1 may be given externs: gate recover). verify
  checks the C file == draft + recorded externs. bank --slate: r5 and the rest run in the job root, r6 is deferred
  (`reconcile: r6 deferred (slate)`); the caller owns the whole-binary build.
Stdlib only. Target bytes are never printed or written (G12).
"""

import contextlib
import hashlib
import io
import json
import os
import re
import shutil
import subprocess
import sys
import tomllib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools" / "probe"))
sys.path.insert(0, str(ROOT / "tools" / "dedup"))
import carve  # noqa: E402
import probe  # noqa: E402

RUN = ROOT / ".run/reconcile"
FIX = Path(__file__).resolve().parent / "fixtures" / "reconcile"
PIN = "L3-gcc2952psx-as286"  # docs/ops/compiler-pin.md
IMPLICIT = re.compile(r"implicit declaration of function [`'\"]?(\w+)")
SPLAT_AUTO = re.compile(r"^func_[0-9A-Fa-f]{8}$")
CLANG_FORMAT = os.environ.get("CLANG_FORMAT", str(ROOT / ".venv/bin/clang-format"))


def fmt(path):
    """`$CLANG_FORMAT -i --style=file path`: every bank writer formats the C it wrote before its byte compare."""
    if not shutil.which(CLANG_FORMAT):
        sys.exit(f"reconcile: FAIL -- clang-format not found: {CLANG_FORMAT} (set CLANG_FORMAT)")
    subprocess.run([CLANG_FORMAT, "-i", "--style=file", str(path)], check=True)


def triple(warn=False):
    t = next(t for t in tomllib.loads((ROOT / "tools/probe/ladder.toml").read_text())["triple"] if t["id"] == PIN)
    if warn:
        t = dict(t, cflags=[f for f in t["cflags"] if f != "-w"] + ["-Wimplicit"])
    return t


def body_hash(path):
    s = Path(path).read_text()
    i, depth = s.index("{"), 0
    for j in range(i, len(s)):
        depth += {"{": 1, "}": -1}.get(s[j], 0)
        if depth == 0:
            break
    return hashlib.sha1(" ".join(s[i + 1:j].split()).encode()).hexdigest()


def draft_hash(path, plain):
    return hashlib.sha1(" ".join(Path(path).read_text().split()).encode()).hexdigest() if plain else body_hash(path)


def plain_text(body, externs=()):
    """A plain draft's C text: the draft, externs inserted after its last #include line."""
    lines = Path(body).read_text().splitlines(keepends=True)
    k = max((i + 1 for i, ln in enumerate(lines) if ln.startswith("#include")), default=0)
    return "".join(lines[:k] + [f"{e}\n" for e in externs] + lines[k:])


def member_text(name, body, defs, externs=()):
    return ("/* Dedup member (generated by tools/dedup/reconcile.py): the body lives in src/shared/. */\n"
            '#include "types.h"\n\n'
            f"#define DEDUP_NAME {name}\n"
            + "".join(f"#define {k} {v}\n" for k, v in defs)
            + ("\n" + "".join(f"{e}\n" for e in externs) if externs else "")
            + f'\n#include "../shared/{Path(body).name}"\n')


def compare(src, name, target, tag, warn=False):
    """-> (None | reason, cc1 stderr)."""
    obj, stage = probe.compile_obj(src, tag, triple(warn))
    err = (ROOT / ".run/probe" / tag / PIN / "cc1.err").read_text(errors="replace")
    if obj is None:
        return f"compile error at {stage}", err
    return word_diff(obj, name, target), err


def word_diff(obj, name, target):
    try:
        ours, masks = probe.read_func(obj, name)
    except KeyError:
        return f"symbol {name} missing"
    a, b = probe.masked(ours, masks), probe.masked(target, masks)
    if len(a) != len(b):
        return f"size {len(a)} words, target {len(b)}"
    k = next((k for k, (x, y) in enumerate(zip(a, b)) if x != y), None)
    return None if k is None else f"word {k} (+0x{4 * k:X}) differs"


def extern_for(x, root, alias):
    """The extern decl r3 inserts for implicitly declared x, or None (FAIL)."""
    for f in sorted((root / "src").rglob("*.c")):
        if f.parent.name == "shared":
            continue
        m = re.search(rf"^([A-Za-z_][\w \t*]*?)\b{x}\s*\(([^)]*)\)\s*\{{", f.read_text(), re.M)
        if m:
            return f"extern {m.group(1).strip()} {x}({m.group(2).strip()});"
    for a in (alias, "slus"):
        sp = root / f"config/symbols.{a}.txt"
        if sp.exists() and re.search(rf"^\s*{x}\s*=.*type:func", sp.read_text(), re.M):
            return f"extern int {x}();"
    return f"extern int {x}();" if SPLAT_AUTO.match(x) else None


def rec_path(alias, vram, module=None, fixture=False):
    """r1 record path; module-suffixed so same-vram overlay members do not collide (legacy unsuffixed read-through)."""
    d = RUN / "selftest" if fixture else RUN
    if module is None:
        return d / f"{alias}_{vram:08X}.json"
    p, old = d / f"{alias}_{vram:08X}_{module.replace('/', '_')}.json", d / f"{alias}_{vram:08X}.json"
    if not p.exists() and old.exists() and json.loads(old.read_text()).get("module") == module:
        return old
    return p


class Job:
    """One member: alias, vram, module, body, defs; root (main tree or selftest scratch); target bytes (selftest)."""

    def __init__(self, alias, vram, body, module=None, defs=(), root=ROOT, target=None, fixture=False, plain=False):
        self.alias, self.vram, self.module, self.body = alias, vram, module, Path(body)
        self.defs, self.root, self.fixture = list(defs), Path(root), fixture
        self.plain, self.externs = plain, []
        self.cx = carve.Ctx(self.root, alias, asm_root=None if fixture else ROOT)
        # r2's probe: refuses c-exists (already carved: revert first); the body's extern rodata stays in the region
        self.plan = carve.plan(self.cx, vram, module, ctext=self.body.read_text() if self.body.is_file() else None)
        self.name = self.plan[5]
        self._target = target
        self.rec = rec_path(alias, vram, module, fixture)

    def target(self):
        if self._target is None:
            self._target = probe.target_bytes({"alias": self.alias, "module": self.module, "vram": self.vram,
                                               "size": self.plan[4] - self.plan[3]})
        return self._target

    def cfile(self):
        return self.root / f"src/{self.alias}/{self.name}.c"

    def text(self, externs=()):
        return plain_text(self.body, externs) if self.plain else member_text(self.name, self.body, self.defs, externs)


def r1(job):
    d = RUN / ("selftest/r1" if job.fixture else "r1")
    (d / "src" / job.alias).mkdir(parents=True, exist_ok=True)
    link = d / "src/shared"
    if link.is_symlink():
        link.unlink()
    link.symlink_to(job.body.resolve().parent)
    src = d / "src" / job.alias / f"{job.name}.c"
    src.write_text(job.text(job.externs))
    why, _ = compare(src, job.name, job.target(), f"reconcile_r1_{job.name}")
    if why:
        print(f"reconcile: r1 FAIL -- {job.name} {why}")
        return 1
    h = draft_hash(job.body, job.plain)
    job.rec.parent.mkdir(parents=True, exist_ok=True)
    rec = {"alias": job.alias, "vram": f"{job.vram:08X}", "module": job.module,
           "name": job.name, "body": str(job.body), "body_hash": h}
    if job.plain:
        rec.update(plain=True, externs=job.externs)
    job.rec.write_text(json.dumps(rec) + "\n")
    print(f"reconcile: r1 match {job.name} body {h}")
    return 0


def r5(alias, name, cfile, target, fixture, root=ROOT):
    """-> None | reason: the make object build/<a>/src/<a>/<name>.o (fixture: the C file compiled) vs target."""
    if fixture:
        return compare(cfile, name, target, f"reconcile_r5_{name}")[0]
    obj = f"build/{alias}/src/{alias}/{name}.o"
    r = subprocess.run(["make", "--no-print-directory", obj, f"BINARY={alias}", f"PY={sys.executable}"],
                       cwd=root, capture_output=True, text=True)
    return f"make {obj} exit {r.returncode}" if r.returncode else word_diff(Path(root) / obj, name, target)


def bank(job, slate=False):
    if not job.rec.exists():
        print(f"reconcile: refused {job.name} -- no r1 record ({job.rec.relative_to(ROOT)})")
        return 1
    rec = json.loads(job.rec.read_text())
    if draft_hash(job.body, job.plain) != rec["body_hash"]:
        print(f"reconcile: refused {job.name} -- body hash changed since r1 (redraft: rerun r1)")
        return 1
    if job.plain:
        job.externs = rec.get("externs", [])
    last, carved = "r1", False

    def fail(rung, why):
        print(f"reconcile: {rung} FAIL -- {why}")
        if carved:
            carve.revert(job.cx, job.vram, job.module)
        return 1

    # r2: carve the cut, member text as the C file
    carve.apply(job.cx, job.plan, job.text(job.externs))
    carved, last = True, "r2"
    fmt(job.cfile())
    print("reconcile: r2 applied")
    # r3: decl sync for implicitly declared callees
    why, err = compare(job.cfile(), job.name, job.target(), f"reconcile_r3_{job.name}", warn=True)
    if why and why.startswith("compile"):
        return fail("r3", why)
    implicit = sorted(set(IMPLICIT.findall(err)))
    if implicit:
        externs = [extern_for(x, job.root, job.alias) for x in implicit]
        if None in externs:
            return fail("r3", f"no declaration source for {implicit[externs.index(None)]}")
        externs = job.externs + externs
        job.cfile().write_text(job.text(externs))
        fmt(job.cfile())
        why, err = compare(job.cfile(), job.name, job.target(), f"reconcile_r3_{job.name}", warn=True)
        if IMPLICIT.search(err) or (why and why.startswith("compile")):
            return fail("r3", why or "implicit declaration remains")
        if job.plain:
            job.externs = externs
            job.rec.write_text(json.dumps(dict(rec, externs=externs)) + "\n")
        last = "r3"
        print("reconcile: r3 applied")
    else:
        print("reconcile: r3 not needed")
    # r4: masked compare of the carved TU (pinned flags); callee casts are not automated
    why, _ = compare(job.cfile(), job.name, job.target(), f"reconcile_r4_{job.name}")
    if why:
        return fail("r4", why)
    print("reconcile: r4 not needed")
    # r5: the real build object
    why = r5(job.alias, job.name, job.cfile(), job.target(), job.fixture, job.root)
    if why:
        return fail("r5", why)
    print("reconcile: r5 not needed")
    # r6: whole-binary SHA from the job root
    if job.fixture:
        print("reconcile: r6 not run (fixture)")
    elif slate:
        print("reconcile: r6 deferred (slate)")
    else:
        log = RUN / f"{job.alias}.build.log"
        with open(log, "w") as fh:
            rc = subprocess.run(["make", "split", "build", f"BINARY={job.alias}", f"PY={sys.executable}"],
                                cwd=job.root, stdout=fh, stderr=subprocess.STDOUT).returncode
        if rc:
            return fail("r6", f"make split build exit {rc} ({log.relative_to(ROOT)})")
        print("reconcile: r6 not needed")
    print(f"reconcile: {job.name} banked at rung {last}, body unchanged")
    return 0


def verify(alias, vram, module=None, root=ROOT, target=None, fixture=False):
    rec = rec_path(alias, vram, module, fixture)

    def fail(why):
        print(f"reconcile: FAIL {alias} {vram:08X} -- {why}")
        return 1
    if not rec.exists():
        return fail(f"no r1 record {rec.relative_to(ROOT)}")
    r = json.loads(rec.read_text())
    name, body = r["name"], Path(r["body"])
    if module is not None and module != r["module"]:
        return fail(f"record module {r['module']}, asked {module}")
    plain = r.get("plain", False)
    if not body.exists() or draft_hash(body, plain) != r["body_hash"]:
        return fail(f"{name} body hash changed since r1 ({body.name})")
    cx_lines = (Path(root) / f"config/splat.{alias}.yaml").read_text().splitlines(keepends=True)
    sub = next((s for sg in carve.parse(cx_lines) if r["module"] in (None, sg["name"])
                for s in sg["subs"] if s[2] == "c" and s[3] == name), None)
    if sub is None:
        return fail(f"{name} has no yaml c cut")
    cfile = Path(root) / f"src/{alias}/{name}.c"
    text = cfile.read_text() if cfile.exists() else ""
    want = RUN / "verify.want.c"  # plain: the draft + externs, formatted as bank wrote it
    if plain:
        want.parent.mkdir(parents=True, exist_ok=True)
        want.write_text(plain_text(body, r.get("externs", [])))
        fmt(want)
    if plain and text != want.read_text():
        return fail(f"{cfile.relative_to(root)} missing or not the draft {body.name} + recorded externs")
    if not plain and f'#include "../shared/{body.name}"' not in text:
        return fail(f"{cfile.relative_to(ROOT)} missing or does not include {body.name}")
    if target is None:
        target = probe.target_bytes({"alias": alias, "module": r["module"], "vram": vram, "size": sub[4] - sub[1]})
    # r1 re-run standalone on the current member file text
    d = RUN / ("selftest/verify" if fixture else "verify")
    (d / "src" / alias).mkdir(parents=True, exist_ok=True)
    link = d / "src/shared"
    if link.is_symlink():
        link.unlink()
    link.symlink_to(body.resolve().parent)
    src = d / "src" / alias / f"{name}.c"
    src.write_text(text)
    why, _ = compare(src, name, target, f"reconcile_verify_{name}")
    if why:
        return fail(f"r1 {name} {why}")
    why = r5(alias, name, cfile, target, fixture, root)
    if why:
        return fail(f"r5 {name} {why}")
    rung = "r3" if (r.get("externs") if plain else re.search(r"^extern ", text, re.M)) else "r2"
    print(f"reconcile: {name} banked at rung {rung}, body unchanged")
    return 0


def selftest():
    work = RUN / "selftest"
    shutil.rmtree(work, ignore_errors=True)
    shutil.copytree(carve.FIX, work)
    shutil.copytree(FIX / "src", work / "src")
    body = work / "src/shared/fx_body.c"
    DEFS = [("DEDUP_CALLEE", "fx_callee")]
    # target: our own fixture C, compiled with the pin (no game bytes)
    obj, _ = probe.compile_obj(FIX / "target.c", "reconcile_selftest_target", triple())
    tgt = probe.read_func(obj, "func_80001000")[0]
    ok, out = True, io.StringIO()
    with contextlib.redirect_stdout(out):
        job = Job("fx", 0x80001000, body, defs=DEFS, root=work, target=tgt, fixture=True)
        ok &= r1(job) == 0 and bank(job) == 0
        vout = io.StringIO()
        with contextlib.redirect_stdout(vout):
            ok &= verify("fx", 0x80001000, root=work, target=tgt, fixture=True) == 0
        print(vout.getvalue(), end="")
    lines = out.getvalue().splitlines()
    want = ["reconcile: r2 applied", "reconcile: r3 applied", "reconcile: r4 not needed",
            "reconcile: func_80001000 banked at rung r3, body unchanged"]
    ok &= all(w in lines for w in want)
    ok &= vout.getvalue().splitlines() == ["reconcile: func_80001000 banked at rung r3, body unchanged"]
    ok &= "extern void fx_callee(u8* o);" in job.cfile().read_text()
    # refusal: the body changed after r1
    out2 = io.StringIO()
    with contextlib.redirect_stdout(out2):
        job2 = Job("fx", 0x80001010, body, defs=DEFS, root=work, target=tgt, fixture=True)
        job.rec.rename(job2.rec)
        body.write_text(body.read_text().replace("o[3] = 0;", "o[3] = 1;"))
        ok &= bank(job2) == 1
        job2.rec.rename(job.rec)  # the banked member, its body now mutated: verify must fail
        ok &= verify("fx", 0x80001000, root=work, target=tgt, fixture=True) == 1
    ok &= "body hash changed" in out2.getvalue() and not job2.cfile().exists()
    ok &= "reconcile: FAIL fx 80001000 -- func_80001000 body hash changed since r1 (fx_body.c)" in out2.getvalue()
    # fmt: a deliberately mis-formatted C must fail the dry-run before fmt and pass it after
    bad, dry = work / "src/fx/fmt_control.c", [CLANG_FORMAT, "--dry-run", "--Werror", "--style=file"]
    bad.write_text("int  fx_fmt(int a){if(a)return 1;return 0;}\n")
    pre = subprocess.run(dry + [str(bad)], capture_output=True).returncode
    fmt(bad)
    post = subprocess.run(dry + [str(bad)], capture_output=True).returncode
    if pre == 0 or post != 0:
        ok = False
        print(f"reconcile: fmt control FAIL -- dry-run exit {pre} before fmt (want !=0), {post} after (want 0)")
    if not ok:
        print(out.getvalue() + out2.getvalue(), end="")
    print("reconcile: control OK -- fixture banked at r3 and verified, changed body refused and fails verify"
          if ok else "reconcile: selftest FAIL")
    return 0 if ok else 1


def main(argv):
    if argv[:1] == ["--selftest"]:
        return selftest()
    if len(argv) >= 3 and argv[0] == "verify":
        return verify(argv[1], int(argv[2], 16), argv[argv.index("--module") + 1] if "--module" in argv else None)
    if len(argv) < 3 or argv[0] not in ("r1", "bank") or "--body" not in argv:
        print(__doc__)
        return 2
    opt = {k: argv[argv.index(k) + 1] for k in ("--module", "--body") if k in argv}
    defs = [tuple(argv[i + 1].split("=", 1)) for i, a in enumerate(argv) if a == "--def"]
    try:
        job = Job(argv[1], int(argv[2], 16), ROOT / opt["--body"], opt.get("--module"), defs, plain="--plain" in argv)
    except carve.Refused as e:
        print(f"reconcile: refused {e} {argv[1]} {argv[2]}")
        return 1
    return r1(job) if argv[0] == "r1" else bank(job, slate="--slate" in argv)


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
