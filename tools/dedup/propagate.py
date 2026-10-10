#!/usr/bin/env python3
"""Propagation: instantiate one shared body (src/shared/<rep>.c) at every member of its dup group, fail-closed.

  propagate.py run <body> [--dry-run]
  propagate.py check
  propagate.py --selftest

Members (keyed (alias, name), C0019) = the fresh census dup group (census.load + census.group in-process) whose
signature equals the body's, unioned with sig.py's exact cluster (equal signature). Signature = sha1 hex of the
dup_key words (LE u32), as sig.py. The body's own signature = that of the function named by the body's stem.
Only byte twins in place stay members (twin()): raw words equal to the stem function's, jal targets free when the
body takes DEDUP_CALLEE. A masked-only member (a %hi/%lo or jal relocation differs) can never be instantiated from
this body (its SHA fails); it is skipped, counted `dedup: <k> masked-only skipped (not byte twins in place)`.
run: per member, the member file = reconcile.member_text (DEDUP_NAME; DEDUP_CALLEE = the member's own jal target when
  the body uses it; r3's externs for implicitly declared callees), compiled standalone in .run/dedup/propagate/cc and
  masked-compared with the member's target bytes; then carve.apply (yaml line edits, G43) per passing member and
  `make split build BINARY=<a>` per touched binary (whole-binary SHA). A member already carved whose C file includes
  the body counts as gated. A failing member is not carved (a failing binary: all its new carves reverted), printed
  `dedup: FAIL <alias> <name> -- <why>`, exit 1. Gated members are registered in config/dedup.us.yaml by line inserts
  (no YAML round trip, comments kept, DK-77). Last line `dedup: <g> of <n> members byte-gated`.
  --dry-run: the same in the scratch worktree .run/carve/wt-<pid> (carve.make_wt; body and registry copied in); the main
  tree is untouched.
check: exit 1 on a C-banked function (yaml `c` cut) whose dup group has a member not in the registry that is a
  byte twin in place of a C-banked member other than itself (twin(); jal free when that member's registered body
  takes DEDUP_CALLEE) (unregistered), or a registry member without its yaml `c` cut or a C file including the body
  (ungated); else `dedup: registry OK (<g> groups, <n> members, 0 unregistered, 0 ungated)`. Masked-only members
  (fail-closed: any raw word differs, so no body of a banked member instantiates them) are counted on the line
  `dedup: <m> masked-only members (not byte twins in place of a banked member)`; they stay ordinary asm targets.
--selftest: tools/dedup/fixtures/propagate (hand-written yaml + asm) with reconcile's fixture body/callee/target C:
  3 members gated, a planted member with differing target bytes refused, a planted unregistered member caught.
Stdlib only. Target bytes are never printed or written (G12).
"""

import contextlib
import hashlib
import io
import re
import shutil
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT / "tools/census"), str(ROOT / "tools/probe"), str(ROOT / "tools/dedup")]
import carve  # noqa: E402
import census  # noqa: E402
import probe  # noqa: E402
import reconcile  # noqa: E402

RUN = ROOT / ".run/dedup/propagate"
FIX = Path(__file__).resolve().parent / "fixtures" / "propagate"
REGISTRY = "config/dedup.us.yaml"
HEADER = ("# Dedup registry, version USA SLUS-01334 (the one target). One entry per propagated group.\n"
          "# group = the body's signature hex (sha1 of census dup_key words, LE u32); census group ids are not stable.\n"
          "# members: every site the body is instantiated at (src/<alias>/<name>.c includes it), each byte-gated.\n"
          "# Edited by tools/dedup/propagate.py through line inserts only (DK-77): hand comments survive.\n"
          "groups:\n")
G_RE = re.compile(r"^  - group: (\w+)")
B_RE = re.compile(r"^    body: (\S+)")
M_RE = re.compile(r"^      - \{alias: (\w+), module: (\S+), vram: 0x([0-9A-Fa-f]+), name: (\w+)\}")
JAL = re.compile(r"\bjal\s+(\w+)")


def signature(words):
    """= sig.py band(): sha1 hex of the dup_key words."""
    n = census.dup_key(words)
    return hashlib.sha1(struct.pack(f"<{len(n)}I", *n)).hexdigest()


def twin(a, b, callee):
    """Byte twin in place: equal raw words; jal targets free when the body takes DEDUP_CALLEE."""
    if callee:
        a, b = (tuple(w & ~0x3FFFFFF if w >> 26 == 3 else w for w in x) for x in (a, b))
    return tuple(a) == tuple(b)


def members(fns, stem, callee=False):
    """-> (signature, byte-twin member rows sorted by alias, vram, name, masked-only count), or raise SystemExit."""
    sigs = {id(f): signature(f["words"]) for f in fns}
    s = {sigs[id(f)] for f in fns if f["name"] == stem}
    if len(s) != 1:
        raise SystemExit(f"dedup: refused -- body stem {stem} names {len(s)} signatures (want 1)")
    s = s.pop()
    grp = next((g["members"] for g in census.group(fns) if g["kind"] == "dup" and sigs[id(g["members"][0])] == s), [])
    out = {(f["alias"], f["name"]): f for f in grp + [f for f in fns if sigs[id(f)] == s]}
    reps = [f["words"] for f in fns if f["name"] == stem]
    tw = [f for f in out.values() if any(twin(f["words"], r, callee) for r in reps)]
    return s, sorted(tw, key=lambda f: (f["alias"], int(f["vram"], 16), f["name"])), len(out) - len(tw)


def fresh_fns():
    with contextlib.redirect_stdout(io.StringIO()) as out:
        rc, fns, _ = census.load()
    if rc:
        raise SystemExit(f"dedup: refused -- census.load exit {rc}: {out.getvalue().strip()[:300]}")
    return fns


# ---- registry: line-level read and insert ----
def registry(root):
    """-> {group: {"body", "members": [(alias, name)], "last": line index}}, lines."""
    p = root / REGISTRY
    lines = p.read_text().splitlines(keepends=True) if p.exists() else []
    reg, cur = {}, None
    for i, ln in enumerate(lines):
        if m := G_RE.match(ln):
            cur = reg.setdefault(m.group(1), {"body": None, "members": [], "last": i})
        elif cur and (m := B_RE.match(ln)):
            cur["body"], cur["last"] = m.group(1), i
        elif cur and (m := M_RE.match(ln)):
            cur["members"].append((m.group(1), m.group(4)))
            cur["last"] = i
    return reg, lines


def member_line(f):
    return f"      - {{alias: {f['alias']}, module: {f['module']}, vram: 0x{f['vram']}, name: {f['name']}}}\n"


def register(root, sig, body, fs):
    reg, lines = registry(root)
    lines = lines or [HEADER]
    if sig in reg:
        have = set(reg[sig]["members"])
        i = reg[sig]["last"] + 1
        lines[i:i] = [member_line(f) for f in fs if (f["alias"], f["name"]) not in have]
    else:
        if lines and not lines[-1].endswith("\n"):
            lines[-1] += "\n"
        lines += [f"  - group: {sig}\n", f"    body: {body}\n", "    members:\n"] + [member_line(f) for f in fs]
    (root / REGISTRY).write_text("".join(lines))


def yaml_c(root, alias):
    return {m.group(1) for ln in (root / f"config/splat.{alias}.yaml").read_text().splitlines()
            if (m := re.match(r"^\s*- \[0x[0-9A-Fa-f]+, c, (\w+)\]", ln))}


def includes(root, alias, name, body_name):
    c = root / f"src/{alias}/{name}.c"
    return c.exists() and f'#include "../shared/{body_name}"' in c.read_text()


# ---- run ----
def gate(root, cx, f, body, target):
    """-> ("have", None) | ("new", member text) | ("fail", why). Never writes the tree."""
    alias, name = f["alias"], f["name"]
    if (root / f"src/{alias}/{name}.c").exists():
        if includes(root, alias, name, body.name) and name in yaml_c(root, alias):
            return "have", None
        return "fail", "c-exists, not an instance of this body"
    try:
        p = carve.plan(cx, int(f["vram"], 16), carve.module_of(f))
    except carve.Refused as e:
        return "fail", f"carve refused {e}"
    defs = []
    if "DEDUP_CALLEE" in body.read_text():
        jals = sorted({j for ln in p[2]["body"] for j in JAL.findall(ln)})
        if len(jals) != 1:
            return "fail", f"{len(jals)} jal targets for DEDUP_CALLEE (want 1)"
        defs = [("DEDUP_CALLEE", jals[0])]
    cc = RUN / "cc/src"
    (cc / alias).mkdir(parents=True, exist_ok=True)
    link = cc / "shared"
    if link.is_symlink() or link.exists():
        link.unlink()
    link.symlink_to(body.resolve().parent)
    src = cc / alias / f"{name}.c"
    src.write_text(reconcile.member_text(name, body, defs))
    reconcile.fmt(src)
    tgt = target(f, p)
    why, err = reconcile.compare(src, name, tgt, f"propagate_{name}", warn=True)
    if why and why.startswith("compile"):
        return "fail", why
    implicit = sorted(set(reconcile.IMPLICIT.findall(err)))
    externs = [reconcile.extern_for(x, root, alias) for x in implicit]
    if None in externs:
        return "fail", f"no declaration source for {implicit[externs.index(None)]}"
    src.write_text(reconcile.member_text(name, body, defs, externs))
    reconcile.fmt(src)
    text = src.read_text()  # formatted: the member text the tree gets
    why, _ = reconcile.compare(src, name, tgt, f"propagate_{name}")
    return ("fail", why) if why else ("new", text)


def real_target(f, p):
    return probe.target_bytes({"alias": f["alias"], "module": carve.module_of(f), "vram": int(f["vram"], 16),
                               "size": p[4] - p[3]})


def run(body, root=ROOT, fns=None, target=real_target, build=True, asm_root=ROOT):
    body = Path(body)
    sig, ms, masked = members(fns if fns is not None else fresh_fns(), body.stem, "DEDUP_CALLEE" in body.read_text())
    if masked:
        print(f"dedup: {masked} masked-only skipped (not byte twins in place)")
    cxs = {a: carve.Ctx(root, a, asm_root=asm_root) for a in sorted({f["alias"] for f in ms})}
    gated, new, failed = [], {}, []
    for f in ms:
        verdict, x = gate(root, cxs[f["alias"]], f, body, target)
        if verdict == "fail":
            failed.append((f, x))
        elif verdict == "have":
            gated.append(f)
        else:
            new.setdefault(f["alias"], []).append((f, x))
    for alias, items in new.items():
        cx = cxs[alias]
        for f, text in items:
            carve.apply(cx, carve.plan(cx, int(f["vram"], 16), carve.module_of(f)), text)
        rc = 0
        if build:
            log = RUN / f"{alias}.build.log"
            log.parent.mkdir(parents=True, exist_ok=True)
            with open(log, "w") as fh:
                rc = subprocess.run(["make", "split", "build", f"BINARY={alias}", f"PY={sys.executable}"], cwd=root,
                                    stdout=fh, stderr=subprocess.STDOUT).returncode
        if rc:  # ponytail: an SHA fail is not attributed per member; every new carve of the binary is reverted
            for f, _ in reversed(items):
                carve.revert(cx, int(f["vram"], 16), carve.module_of(f))
                failed.append((f, f"make split build exit {rc} ({log.relative_to(ROOT)}); binary's new carves reverted"))
        else:
            gated += [f for f, _ in items]
    if gated:
        register(root, sig, body.relative_to(root).as_posix(),
                 sorted(gated, key=lambda f: (f["alias"], int(f["vram"], 16), f["name"])))
    for f, why in failed:
        print(f"dedup: FAIL {f['alias']} {f['name']} -- {why}")
    print(f"dedup: {len(gated)} of {len(ms)} members byte-gated")
    return 1 if failed else 0


def dry_run(body):
    wt = carve.make_wt()
    try:
        for rel in (Path(body).resolve().relative_to(ROOT), Path(REGISTRY)):
            if (ROOT / rel).exists():
                (wt / rel).parent.mkdir(parents=True, exist_ok=True)
                shutil.copy2(ROOT / rel, wt / rel)
        return run(wt / Path(body).resolve().relative_to(ROOT), root=wt)
    finally:
        carve.drop_wt(wt)  # this process's worktree only


# ---- check ----
def check(root=ROOT, fns=None):
    fns = fns if fns is not None else fresh_fns()
    reg, _ = registry(root)
    regd = {k: e for e in reg.values() for k in e["members"]}
    aliases = sorted(p.name.split(".")[1] for p in (root / "config").glob("splat.*.yaml"))
    cset = {(a, n) for a in aliases for n in yaml_c(root, a)}
    words = {(f["alias"], f["name"]): f["words"] for f in fns}
    unreg, masked = set(), set()
    for g in census.group(fns):
        keys = [(x["alias"], x["name"]) for x in g["members"]]
        banked = [(c, regd[c]["body"] and "DEDUP_CALLEE" in (root / regd[c]["body"]).read_text() if c in regd else
                   False) for c in keys if c in cset]
        if g["kind"] == "dup" and banked:
            for k in keys:
                if k in regd:
                    continue
                if any(c != k and twin(words[k], words[c], cal) for c, cal in banked):
                    unreg.add(k)
                elif k not in cset:
                    masked.add(k)
    ungated = {k for k, e in regd.items()
               if k not in cset or not e["body"] or not includes(root, *k, Path(e["body"]).name)}
    for k in sorted(unreg):
        print(f"dedup: unregistered {k[0]} {k[1]}")
    for k in sorted(ungated):
        print(f"dedup: ungated {k[0]} {k[1]}")
    for e in reg.values():  # byte-gated = yaml c cut + C file including the body; the SHA is health rung 0
        g = sum(k not in ungated for k in e["members"])
        print(f"dedup: {g} of {len(e['members'])} members byte-gated ({Path(e['body'] or '?').stem})")
    print(f"dedup: {len(masked)} masked-only members (not byte twins in place of a banked member)")
    ok = not unreg and not ungated
    print(f"dedup: registry {'OK' if ok else 'FAIL'} ({len(reg)} groups, {len(regd)} members, "
          f"{len(unreg)} unregistered, {len(ungated)} ungated)")
    return 0 if ok else 1


# ---- selftest ----
def selftest():
    work = RUN / "selftest"
    shutil.rmtree(work, ignore_errors=True)
    shutil.copytree(FIX, work)
    shutil.copytree(reconcile.FIX / "src", work / "src")
    body = work / "src/shared/func_80001000.c"  # the rep's name: the stem names the body's signature
    (work / "src/shared/fx_body.c").rename(body)
    obj, _ = probe.compile_obj(reconcile.FIX / "target.c", "propagate_selftest_target", reconcile.triple())
    tgt = probe.read_func(obj, "func_80001000")[0]
    planted = bytes([tgt[0] ^ 4]) + tgt[1:]  # word 0 (frame setup, never relocated) differs
    words = struct.unpack(f"<{len(tgt) // 4}I", tgt)
    fns = [{"alias": "fx", "module": "fx/main", "kind": "game", "name": f"func_{v:08X}", "vram": f"{v:08X}",
            "insns": len(words), "words": words} for v in (0x80001000, 0x80001010, 0x80001020, 0x80001030)]
    fns.append({**fns[0], "name": "func_80002000", "vram": "80002000", "words": (0,) * len(words)})  # not a member
    ok, out = True, io.StringIO()
    with contextlib.redirect_stdout(out):
        rc = run(body, root=work, fns=fns, target=lambda f, p: planted if f["name"] == "func_80001030" else tgt,
                 build=False, asm_root=work)
        ok &= rc == 1
        ok &= all(includes(work, "fx", f"func_8000{v}", body.name) for v in ("1000", "1010", "1020"))
        ok &= not (work / "src/fx/func_80001030.c").exists() and "func_80001030" not in yaml_c(work, "fx")
        ok &= "extern void fx_callee(u8* o);" in (work / "src/fx/func_80001010.c").read_text()
        ok &= twin((0x0C000001, 0), (0x0C000002, 0), True) and not twin((0x0C000001, 0), (0x0C000002, 0), False)
        ok &= not twin((0x3C010001,), (0x3C010002,), True)  # a %hi relocation differs: masked-only, never a twin
        ok &= check(work, fns) == 1  # the planted member: in the banked group, not registered
        ok &= check(work, fns[:3] + fns[4:]) == 0
        (work / "src/fx/func_80001020.c").unlink()
        ok &= check(work, fns[:3] + fns[4:]) == 1  # ungated
    lines = out.getvalue().splitlines()
    want = ["dedup: FAIL fx func_80001030 -- word 0 (+0x0) differs", "dedup: 3 of 4 members byte-gated",
            "dedup: unregistered fx func_80001030",
            "dedup: registry OK (1 groups, 3 members, 0 unregistered, 0 ungated)", "dedup: ungated fx func_80001020"]
    ok &= all(w in lines for w in want)
    if not ok:
        print(out.getvalue(), end="")
    print("dedup: control OK -- fixture body 3 members gated, planted differing member refused, "
          "unregistered member caught" if ok else "dedup: selftest FAIL")
    return 0 if ok else 1


def main(argv):
    if argv[:1] == ["--selftest"]:
        return selftest()
    if argv[:1] == ["check"]:
        return check()
    if len(argv) >= 2 and argv[0] == "run":
        body = Path(argv[1]).resolve()
        if not body.exists() or body.parent != ROOT / "src/shared":
            print(f"dedup: refused -- body must be src/shared/<rep>.c: {argv[1]}")
            return 2
        return dry_run(body) if "--dry-run" in argv[2:] else run(body)
    print(__doc__)
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
