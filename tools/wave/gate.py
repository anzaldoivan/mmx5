#!/usr/bin/env python3
"""Wave gate: bank a wave's drafts through the reconcile ladder; exactly one verdict row per draft.

  gate.py run W<k> [--alias a] [--waves DIR]
  gate.py recover W<k> [--alias a] [--waves DIR]
  gate.py rescan W<k> [--waves DIR]
  gate.py --selftest

Inputs waves/W<k>/{wave.json, drafts/<alias>_<name>.c}; --waves overrides the waves/ root. Output
waves/W<k>/verdicts.jsonl, one row per draft keyed (alias,name), rewritten in place:
  {alias, module, name, vram, verdict: banked|failed|no-verdict, rung, reason, date}.
run: refused when `git status --porcelain src config` is non-empty. Per alias, under flock .run/wave/lock.<alias>:
  r1 every draft (reconcile plain mode, main-tree scratch); a carve refusal -> no-verdict `refused <why>`, r1 still
  reported by the standalone compare (waves.py try). r1-green -> worktree .run/wave/wt/<alias> (carve.make_wt), reconcile
  bank --slate per draft there (r2-r5) -> `make split` + `make -j<nproc> build` (SHA); red -> bisect halves (carve.revert,
  rebuild). R4: then `shapes.py check` on the worktree with the SHA-green set applied; red -> bisect it with the
  types predicate, culprits no-verdict `refused types` (G35), not adopted. Greens are adopted into the main tree (carve.apply, the worktree C text), one `make split build`;
  red -> all adopted reverted, no-verdict. Green -> `reconcile verify` per draft: `banked` only on its line
  `reconcile: <name> banked at rung rN, body unchanged` (printed); a verify FAIL is reverted, no-verdict.
  Ends with the waves.py status assertion (exit 1 when it fails). Never commits: prints `gate: commit <paths>`.
recover: each `failed` row at r1: r1 again with r3 externs (reconcile.extern_for, decls from src/) for the draft's
  implicitly declared callees; match -> the run plumbing (draft untouched); else stays failed, reason `body: <diff>`.
  Prints `recover: <p> plumbing banked, <b> body`.
rescan (R6, G46): refused on a dirty src/config. Refreshes census/inventory.py -> census/census.py dup -> sig/sig.py
  band (full), logs .run/wave/rescan.<step>.log. Per `banked` row: open members = its exact twins (.run/sig/twins.jsonl)
  ∪ its census dup group, inventory status asm, kept only when a byte twin in place (propagate.twin; jal free when the
  rep takes DEDUP_CALLEE; masked-only members are counted `gate: <a>_<name> <k> masked-only skipped`) (t = their
  count). A banked function with >= 1 open member becomes a dedup rep (src/shared/<name>.c = its C file, name ->
  DEDUP_NAME; when its words have one jal target and its body calls one function, that callee -> DEDUP_CALLEE; refused
  when no `DEDUP_NAME(...) {` definition; its own C file -> reconcile.member_text; its r1
  record -> the shared body, `reconcile verify` re-run), then `propagate.py run src/shared/<name>.c`
  (.run/wave/rescan.propagate.<alias>_<name>.log); p = open members now including the body. On a failure the rep's
  files, yamls, registry and r1 record are restored from a snapshot, created C files deleted, the aliases rebuilt;
  `rescan: FAIL ...`, exit 1. Prints `rescan: <b> banked, <t> open twins, <p> propagated`, then `gate: commit <paths>`.
--selftest: tools/wave/fixtures/gate (synthetic, ROM-free): a wave dir missing one verdict row must be refused; a
  planted raw-cast slate draft must get no-verdict `refused types` (`gate: control OK -- raw cast refused`).
Target bytes are never printed or written (G12). Stdlib only.
"""

import argparse
import contextlib
import datetime
import fcntl
import io
import json
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
FIX = Path(__file__).resolve().parent / "fixtures" / "gate"
for d in ("tools/dedup", "tools/probe", "tools/wave"):
    sys.path.insert(0, str(ROOT / d))
import carve  # noqa: E402
import propagate  # noqa: E402
import reconcile  # noqa: E402
import shapes  # noqa: E402
import waves as wave  # noqa: E402

RUN = ROOT / ".run/wave"
PYV = f"PY={sys.executable}"
BANKED = re.compile(r"^reconcile: \w+ banked at rung (r\d), body unchanged$", re.M)
FAIL = re.compile(r"^reconcile: (r\d) FAIL -- (.*)$", re.M)


def quiet(f, *a, **k):
    b = io.StringIO()
    with contextlib.redirect_stdout(b):
        rc = f(*a, **k)
    return rc, b.getvalue()


def last_line(out):
    return (out.strip().splitlines() or [""])[-1]


def module(t):
    """carve/probe module: the rockx5 yaml segment (ovlNN); slus segments are found by vram."""
    return wave.unit(t) if t["alias"] == "rockx5" else None


def make(root, log, *targets, jobs=False):
    with open(log, "w") as fh:
        return subprocess.run(["make", *([f"-j{os.cpu_count()}"] if jobs else []), *targets, PYV], cwd=root,
                              stdout=fh, stderr=subprocess.STDOUT).returncode


class Wave:
    def __init__(self, waves, wk):
        self.wk, self.dir = wk, Path(waves) / wk
        self.targets = {(t["alias"], t["name"]): t for t in json.loads((self.dir / "wave.json").read_text())["targets"]}
        self.vpath = self.dir / "verdicts.jsonl"

    def drafts(self, alias=None):
        out = []
        for p in sorted((self.dir / "drafts").glob("*.c")):
            a, name = p.stem.split("_", 1)
            if alias in (None, a):
                out.append((a, name, p.resolve()))
        return out

    def rows(self):
        return {(r["alias"], r["name"]): r for r in wave.jsonl(self.vpath)} if self.vpath.exists() else {}

    def put(self, a, name, verdict, rung, reason):
        t = self.targets.get((a, name), {})
        RUN.mkdir(parents=True, exist_ok=True)
        with open(RUN / "lock.verdicts", "w") as lk:  # aliases run in parallel; one writer at a time
            fcntl.flock(lk, fcntl.LOCK_EX)
            rows = self.rows()
            rows[(a, name)] = {"alias": a, "module": t.get("module"), "name": name, "vram": t.get("vram"),
                               "verdict": verdict, "rung": rung, "reason": reason,
                               "date": datetime.date.today().isoformat()}
            self.vpath.write_text("".join(json.dumps(r) + "\n" for r in rows.values()))
        print(f"gate: {a}_{name} {verdict}" + (f" {rung}" if rung else "") + (f" -- {reason}" if reason else ""))


def job_for(w, a, name, draft):
    """-> reconcile.Job (main tree, plain) or None after writing the no-verdict row."""
    t = w.targets.get((a, name))
    if t is None:
        w.put(a, name, "no-verdict", None, "not in wave.json")
        return None
    try:
        return reconcile.Job(a, int(t["vram"], 16), draft, module(t), plain=True)
    except carve.Refused as e:
        _, out = quiet(wave.cmd_try, str(draft), f"{a}_{name}")
        print(f"gate: {a}_{name} r1 standalone {(out.splitlines() or [''])[0]}")  # the result line; detail follows
        w.put(a, name, "no-verdict", None, f"refused {e}")
        return None


def bisect(keys, ok, base=()):
    """Largest found subset of keys green on top of base (green); ok(set) applies the set and builds.
    The second half is bisected against base + the first half's greens, so an a-x-b interaction (W2: two drafts
    with one struct shape under two names) drops only the culprit, never half b whole."""
    if ok(set(base) | set(keys)):
        return keys
    if len(keys) == 1:
        return []
    h = len(keys) // 2
    a = bisect(keys[:h], ok, base)
    return a + bisect(keys[h:], ok, (*base, *a))


def types_gate(w, alias, good, put_set, root):
    """R4: shapes.py check on root with the SHA-green set applied (once per slate); red -> bisect it with the types
    predicate as the SHA bisect does; culprits -> no-verdict `refused types` (G35: never failed), not adopted."""
    def ok(want):
        put_set(want)
        return quiet(shapes.check, root)[0] == 0

    typed = bisect(good, ok) if good else []
    print(f"gate: {alias} worktree {len(typed)} of {len(good)} types green")
    for n in sorted(set(good) - set(typed)):
        w.put(alias, n, "no-verdict", None, "refused types")
    return typed


def plumb(w, alias, greens):
    """greens: [(name, main-tree Job after r1 match)] -> banked [(name, path)]."""
    if not greens:
        return []
    wt = carve.make_wt(RUN / "wt" / alias)
    cands = {}  # name -> (job, worktree C text)
    for name, job in greens:
        try:
            wj = reconcile.Job(alias, job.vram, job.body, job.module, root=wt, plain=True)
        except carve.Refused as e:
            w.put(alias, name, "no-verdict", None, f"refused {e} (worktree)")
            continue
        rc, out = quiet(reconcile.bank, wj, slate=True)
        if rc:
            m = FAIL.search(out)
            w.put(alias, name, "failed", m.group(1) if m else None, m.group(2) if m else last_line(out))
            continue
        cands[name] = (job, wj.cfile().read_text())
    wcx, applied = carve.Ctx(wt, alias, asm_root=ROOT), set(cands)
    log = RUN / f"{alias}.wt.build.log"

    def put_set(want):
        for n in sorted(applied - want):
            carve.revert(wcx, cands[n][0].vram, cands[n][0].module)
            applied.discard(n)
        for n in sorted(want - applied):
            j = cands[n][0]
            carve.apply(wcx, carve.plan(wcx, j.vram, j.module), cands[n][1])
            applied.add(n)

    def ok(want):
        put_set(want)
        return (make(wt, log, "split", f"BINARY={alias}") == 0
                and make(wt, log.with_suffix(".2.log"), "build", f"BINARY={alias}", jobs=True) == 0)

    good = bisect(sorted(cands), ok) if cands else []
    print(f"gate: {alias} worktree {len(good)} of {len(cands)} build SHA green")
    for n in sorted(set(cands) - set(good)):
        w.put(alias, n, "failed", "r6", f"whole-binary SHA red in worktree ({log.relative_to(ROOT)})")
    good = types_gate(w, alias, good, put_set, wt)
    # adopt into the main tree
    cx, adopted = carve.Ctx(ROOT, alias), []
    for n in good:
        j = cands[n][0]
        try:
            carve.apply(cx, carve.plan(cx, j.vram, j.module), cands[n][1])
            adopted.append(n)
        except carve.Refused as e:
            w.put(alias, n, "no-verdict", None, f"refused {e} (adopt)")
    if not adopted:
        return []
    mlog = RUN / f"{alias}.main.build.log"
    if make(ROOT, mlog, "split", "build", f"BINARY={alias}"):
        for n in adopted:
            carve.revert(cx, cands[n][0].vram, cands[n][0].module)
            w.put(alias, n, "no-verdict", None, f"adopt build red ({mlog.relative_to(ROOT)}), reverted")
        rebuild(alias)
        return []
    banked, dropped = [], False
    for n in adopted:
        j = cands[n][0]
        rc, out = quiet(reconcile.verify, alias, j.vram, j.module)
        m = BANKED.search(out)
        if rc == 0 and m:
            print(m.group(0))
            w.put(alias, n, "banked", m.group(1), None)
            banked.append((n, j.cfile()))
        else:
            carve.revert(cx, j.vram, j.module)
            dropped = True
            w.put(alias, n, "no-verdict", None, f"verify: {last_line(out)}, reverted")
    if dropped:
        rebuild(alias)
    return banked


def rebuild(alias):
    log = RUN / f"{alias}.main.rebuild.log"
    rc = make(ROOT, log, "split", "build", f"BINARY={alias}")
    print(f"gate: {alias} main tree rebuilt after revert, SHA {'OK' if rc == 0 else f'FAIL ({log.relative_to(ROOT)})'}")


def r1_run(w, alias):
    greens, rows = [], w.rows()
    for a, name, draft in w.drafts(alias):
        if rows.get((a, name), {}).get("verdict") == "banked":  # a re-run keeps banks (carved: plan says not-found)
            continue
        job = job_for(w, a, name, draft)
        if job is None:
            continue
        rc, out = quiet(reconcile.r1, job)
        if rc:
            w.put(a, name, "failed", "r1", last_line(out).split(" -- ", 1)[-1])
        else:
            greens.append((name, job))
    return greens


def r1_recover(w, alias):
    greens, body = [], 0
    rows = w.rows()
    for a, name, draft in w.drafts(alias):
        r = rows.get((a, name), {})
        if r.get("verdict") != "failed" or r.get("rung") != "r1":
            continue
        job = job_for(w, a, name, draft)
        if job is None:
            continue
        why, err = reconcile.compare(draft, job.name, job.target(), f"gate_recover_{job.name}", warn=True)
        implicit = sorted(set(reconcile.IMPLICIT.findall(err)))
        ext = [reconcile.extern_for(x, ROOT, a) for x in implicit]
        if None not in ext:
            job.externs = ext
            rc, out = quiet(reconcile.r1, job)
            if rc == 0:
                greens.append((name, job))
                continue
            why = last_line(out).split(" -- ", 1)[-1]
        body += 1
        w.put(a, name, "failed", "r1", f"body: {why}")
    return greens, body


def main_run(waves, wk, alias, recover=False):
    dirty = subprocess.run(["git", "status", "--porcelain", "src", "config"], cwd=ROOT, capture_output=True,
                           text=True, check=True).stdout
    if dirty.strip():
        print("gate: refused -- src/ or config/ has uncommitted changes")
        return 1
    w = Wave(waves, wk)
    aliases = [alias] if alias else sorted({a for a, _, _ in w.drafts()})
    banked, p, b = [], 0, 0
    for a in aliases:
        RUN.mkdir(parents=True, exist_ok=True)
        with open(RUN / f"lock.{a}", "w") as lk:
            fcntl.flock(lk, fcntl.LOCK_EX)
            if recover:
                greens, nb = r1_recover(w, a)
                got = plumb(w, a, greens)
                p, b = p + len(got), b + nb
            else:
                got = plumb(w, a, r1_run(w, a))
            banked += [(a, path) for _, path in got]
    if recover:
        print(f"recover: {p} plumbing banked, {b} body")
    paths = sorted({str(path.relative_to(ROOT)) for _, path in banked} | {f"config/splat.{a}.yaml" for a, _ in banked})
    print("gate: commit " + " ".join(paths + [os.path.relpath(w.vpath, ROOT)]))
    return wave.cmd_status(waves, wk)


def porcelain():
    return subprocess.run(["git", "status", "--porcelain", "-uall", "src", "config"], cwd=ROOT, capture_output=True,
                          text=True, check=True).stdout


def jsonl_rows(p):
    return [json.loads(ln) for ln in p.read_text().splitlines() if ln.strip()]


def refresh():
    """inventory -> census dup -> sig band (full); -> None or the failing step."""
    for name, cmd in (("inventory", ["tools/census/inventory.py"]), ("census", ["tools/census/census.py", "dup"]),
                      ("sig", ["tools/sig/sig.py", "band"])):
        log = RUN / f"rescan.{name}.log"
        with open(log, "w") as fh:
            if subprocess.run([sys.executable, *cmd], cwd=ROOT, stdout=fh, stderr=subprocess.STDOUT).returncode:
                return f"{name} ({log.relative_to(ROOT)})"
    return None


def open_twins(banked):
    """-> {(alias, name): sorted open members}: exact twins ∪ dup-group members, inventory status asm."""
    status = {(r["alias"], r["name"]): r["status"] for r in jsonl_rows(ROOT / ".run/census/inventory.jsonl")}
    out = {k: set() for k in banked}
    for r in jsonl_rows(ROOT / ".run/sig/twins.jsonl"):
        a, b = (r["a"]["alias"], r["a"]["name"]), (r["b"]["alias"], r["b"]["name"])
        if r["tier"] == "exact":
            for x, y in ((a, b), (b, a)):
                if x in out:
                    out[x].add(y)
    for g in jsonl_rows(ROOT / ".run/census/groups.jsonl"):
        keys = {(m["alias"], m["name"]) for m in g["members"]}
        if g["kind"] == "dup":
            for k in keys & set(out):
                out[k] |= keys
    return {k: sorted(m for m in v if m != k and status.get(m) == "asm") for k, v in out.items()}


CALL = re.compile(r"\b([A-Za-z_]\w*)\s*\(")
NOTCALL = {"if", "while", "for", "switch", "return", "sizeof"}


def rep_callee(name, cfile, words):
    """The banked fn's sole callee when its words have one jal target and its body calls one function, else None."""
    if len({w for w in words if w >> 26 == 3}) != 1:
        return None
    s = cfile.read_text()
    m = re.search(rf"\b{name}\s*\([^;{{}}]*\)\s*\{{", s)
    macros = set(re.findall(r"^\s*#\s*define\s+(\w+)", s, re.M))
    calls = {c for c in CALL.findall(s[m.end():]) if c not in NOTCALL | macros} if m else set()
    return calls.pop() if len(calls) == 1 else None


def rep_text(name, cfile, callee=None):
    """The banked plain C file as a shared body (DEDUP_NAME, callee -> DEDUP_CALLEE), or None without its definition."""
    s = re.sub(rf"\b{name}\b", "DEDUP_NAME", cfile.read_text())
    if callee:
        s = re.sub(rf"\b{callee}\b", "DEDUP_CALLEE", s)
    if not re.search(r"\bDEDUP_NAME\s*\([^;{}]*\)\s*\{", s):
        return None
    if '#include "types.h"' not in s:
        s = '#include "types.h"\n' + s
    return f"/* Shared body (DK-5), from the banked draft of {name} by tools/wave/gate.py rescan. */\n" + s


def propagate_rep(alias, name, members, callee=None):
    """Make the banked (alias, name) a dedup rep and propagate it -> (members gated, None | why). Restores on failure."""
    shared, cfile = ROOT / f"src/shared/{name}.c", ROOT / f"src/{alias}/{name}.c"
    recs = [p for p in reconcile.RUN.glob(f"{alias}_*.json") if json.loads(p.read_text())["name"] == name]
    if len(recs) != 1:
        return 0, f"{len(recs)} r1 records"
    # ponytail: snapshot texts, not git checkout -- earlier reps of this rescan are uncommitted and must survive
    keep = [*ROOT.glob("config/splat.*.yaml"), ROOT / "config/dedup.us.yaml", cfile, shared, recs[0]]
    snap = {p: p.read_text() if p.exists() else None for p in keep}
    srcs = set((ROOT / "src").rglob("*.c"))

    def restore(why):
        for p, t in snap.items():
            if t is None:
                p.unlink(missing_ok=True)
            else:
                p.write_text(t)
        for p in set((ROOT / "src").rglob("*.c")) - srcs:
            p.unlink()
        for a in sorted({alias} | {m[0] for m in members}):
            rebuild(a)
        return 0, why

    if not shared.exists():  # a rerun finds the rep already made
        text = rep_text(name, cfile, callee)
        if text is None:
            return 0, "rep refused: no DEDUP_NAME(...) { definition in the file"
        shared.write_text(text)
        cfile.write_text(reconcile.member_text(name, shared, [("DEDUP_CALLEE", callee)] if callee else []))
        reconcile.fmt(shared)
        reconcile.fmt(cfile)
        rec = json.loads(recs[0].read_text())
        for k in ("plain", "externs"):
            rec.pop(k, None)
        recs[0].write_text(json.dumps(dict(rec, body=str(shared), body_hash=reconcile.body_hash(shared))) + "\n")
        rc, out = quiet(reconcile.verify, alias, int(rec["vram"], 16), rec["module"])
        if rc:
            return restore(f"rep verify: {last_line(out)}")
    log = RUN / f"rescan.propagate.{alias}_{name}.log"
    with open(log, "w") as fh:
        rc = subprocess.run([sys.executable, "tools/dedup/propagate.py", "run", str(shared.relative_to(ROOT))],
                            cwd=ROOT, stdout=fh, stderr=subprocess.STDOUT).returncode
    print(f"gate: {alias}_{name} {last_line(log.read_text())}")
    if rc:
        return restore(f"propagate exit {rc} ({log.relative_to(ROOT)}), restored")
    inc = f'#include "../shared/{shared.name}"'
    return sum((c := ROOT / f"src/{a}/{n}.c").exists() and inc in c.read_text() for a, n in members), None


def main_rescan(waves, wk):
    if porcelain().strip():
        print("gate: refused -- src/ or config/ has uncommitted changes")
        return 1
    w = Wave(waves, wk)
    banked = sorted(k for k, r in w.rows().items() if r["verdict"] == "banked")
    bad = refresh() if banked else None
    if bad:
        print(f"rescan: refused -- refresh failed: {bad}")
        return 1
    twins = open_twins(banked) if banked else {}
    words = {(f["alias"], f["name"]): f["words"] for f in propagate.fresh_fns()} if banked else {}
    callees = {}
    for (a, name), ms in twins.items():
        shared = ROOT / f"src/shared/{name}.c"
        callees[a, name] = (("DEDUP_CALLEE" in shared.read_text()) if shared.exists()
                            else rep_callee(name, ROOT / f"src/{a}/{name}.c", words[a, name]))
        tw = [m for m in ms if propagate.twin(words[m], words[a, name], callees[a, name])]
        if len(tw) < len(ms):
            print(f"gate: {a}_{name} {len(ms) - len(tw)} masked-only skipped")
        twins[a, name] = tw
    p, fails = 0, 0
    for (a, name), ms in sorted(twins.items()):
        if not ms:
            continue
        print(f"gate: {a}_{name} {len(ms)} open: " + " ".join(f"{x}_{y}" for x, y in ms))
        got, why = propagate_rep(a, name, ms, callees[a, name] or None)
        p += got
        if why:
            fails += 1
            print(f"rescan: FAIL {a}_{name} -- {why}")
    print(f"rescan: {len(banked)} banked, {sum(map(len, twins.values()))} open twins, {p} propagated")
    paths = sorted(ln[3:] for ln in porcelain().splitlines())
    if paths:
        print("gate: commit " + " ".join(paths))
    return 1 if fails else 0


def selftest():
    tmp = RUN / "selftest_gate"
    shutil.rmtree(tmp, ignore_errors=True)
    shutil.copytree(FIX, tmp)
    waves = tmp / "waves"
    rc, out = quiet(wave.cmd_status, waves, "W0")
    assert rc == 1 and "wave: no verdict row slus_fb" in out, out
    assert quiet(wave.cmd_status, waves, "W0", True)[0] == 0
    w = Wave(waves, "W0")
    quiet(w.put, "slus", "fb", "no-verdict", None, "refused c-exists")
    rc, out = quiet(wave.cmd_status, waves, "W0")
    assert rc == 0 and "wave: W0 2 drafts = 0 banked + 1 failed + 1 no-verdict" in out, out
    print("gate: control OK -- missing verdict refused")
    slate = {"fa": (FIX / "waves/W0/drafts/slus_fa.c").read_text(),  # planted: fb's slate draft has a raw cast (R4)
             "fb": "int fb(int a) { return *(int *)0x80001000 + a; }\n"}
    (tmp / "src/slus").mkdir(parents=True)

    def put_set(want):
        for n, text in slate.items():
            p = tmp / f"src/slus/{n}.c"
            if n in want:
                p.write_text(text)
            else:
                p.unlink(missing_ok=True)

    rc, out = quiet(types_gate, w, "slus", ["fa", "fb"], put_set, tmp)
    row = w.rows()[("slus", "fb")]
    assert rc == ["fa"] and (row["verdict"], row["reason"]) == ("no-verdict", "refused types"), (rc, row, out)
    assert "gate: slus worktree 1 of 2 types green" in out, out
    assert bisect([0, 1, 2, 3], lambda s: not {1, 3} <= s) == [0, 1, 2]  # a-x-b clash drops the culprit only
    print("gate: control OK -- raw cast refused")
    return 0


def main(argv=None):
    argv = sys.argv[1:] if argv is None else argv
    if argv == ["--selftest"]:
        return selftest()
    ap = argparse.ArgumentParser(prog="gate.py", formatter_class=argparse.RawDescriptionHelpFormatter, description=(
        "subcommands:\n"
        "  run      bank a wave's drafts: r1, worktree slate + SHA + types bisect, adopt, verify; one verdict per draft\n"
        "  recover  retry `failed` r1 rows with r3 externs; a match goes through the run plumbing\n"
        "  rescan   refresh census/sig, make banked functions dedup reps, propagate to their byte twins"))
    ap.add_argument("cmd", choices=["run", "recover", "rescan"])
    ap.add_argument("wave")
    ap.add_argument("--alias")
    ap.add_argument("--waves", default=str(ROOT / "waves"))
    a = ap.parse_args(argv)
    if a.cmd == "rescan":
        return main_rescan(Path(a.waves).resolve(), a.wave)
    return main_run(Path(a.waves).resolve(), a.wave, a.alias, a.cmd == "recover")


if __name__ == "__main__":
    sys.exit(main())
