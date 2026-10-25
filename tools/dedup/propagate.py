#!/usr/bin/env python3
"""Propagation: instantiate one shared body (src/shared/<rep>.c) at every member of its dup group, fail-closed.

  propagate.py run <body> [--dry-run]
  propagate.py check
  propagate.py sweep [--dry-run] [--binary <alias>]
  propagate.py --selftest

Members (keyed (alias, name), C0019) = the fresh census dup group (census.load + census.group in-process) whose
signature equals the body's, unioned with sig.py's exact cluster (equal signature). Signature = sha1 hex of the
dup_key words (LE u32), as sig.py. The body's own signature = that of the function named by the body's stem.
Byte twins in place are members (twin()): raw words equal to the stem function's, jal targets free when the body
takes DEDUP_CALLEE. A masked-only member M (a %hi/%lo or jal relocation differs) is reloc-gated (relocs(): the
relocations of the rep's and M's built objects, x4core.Elf; rep = build/<a>/src/<a>/<name>.o, M = its asm file's
build/<a>/asm/<a>/<file>.o) when, slot by slot, types and in-place addends (C0039, HI16/LO16 paired) agree, the map
sym_R -> sym_M is a function, every sym_M is in M's own object (an `_ovlNN` suffix = M's own overlay; none = the main
exe), no renamed sym_R is a struct field (.x/->x), param or local in the body, and raw words are equal outside the
relocated fields; it is then instantiated with `#define sym_R sym_M` per differing symbol (jal symbols excepted when
the body takes DEDUP_CALLEE). Else refused: `dedup: FAIL <alias> <name> -- <why>` (exit code unchanged). Printed
`dedup: <m> masked-only: <a> reloc-gated, <k> refused`. The byte gate below stays the arbiter (C0071).
run: per member, the member file = reconcile.member_text (DEDUP_NAME; DEDUP_CALLEE = the member's own jal target when
  the body uses it; the reloc-gated renames; r3's externs for implicitly declared callees), compiled standalone in .run/dedup/propagate/cc and
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
  3 members gated, a planted member with differing target bytes refused, a planted unregistered member caught; then
  fixtures/propagate/reloc (hand-written body + objects): a masked-only member reloc-gated by rename, a planted
  masked-only member whose global lives in another overlay refused.
sweep --dry-run: first the fixtures/propagate/reloc control in-process (`dedup: sweep control refused fx func_80001120
  -- ...`, else `dedup: sweep control FAIL`, exit 1). Then every dup group with a C-banked member and masked-only
  members (as check() counts them): its rep = the registered body, else src/shared/<name>.c of a banked member, else
  made from the first banked member's C file (rep_text/rep_callee, as gate.py rescan; its C file -> member_text), all in
  one scratch worktree (carve.make_wt, dropped at the end; the main tree is untouched). Per rep, run(build=False) (the
  members() reloc gate, gate() compile + word compare, carve.apply); then per binary (sequential, slus first and left
  at its green set: the rockx5 build links slus) `make split` +
  `make -j build` once with every rep's carves, a red build bisected by rep (gate.bisect; losers refused `sha`). One
  line per masked-only member `dedup: sweep <alias> <name> gated|refused <why>`, then `dedup: sweep refused <count>
  <reason-class>` per class, `dedup: sweep <c> of <F> gated members already C`, last
  `dedup: sweep <F> of <n> masked-only members byte-gated, <r> refused`. Build logs .run/dedup/propagate/sweep.*.log.
sweep (wet, no --dry-run): the same in the main tree (no worktree): the green set's carves stay, the losers' are
  reverted (`dedup: sweep <alias> <name> refused sha: ...`), a made body none of whose members ends gated is removed,
  and each rep's gated members (+ the rep when its C file includes the body) are registered (register(), line
  inserts). The final tree is not rebuilt: run `make split build BINARY=<a>` after. --binary <alias>: only that
  alias's masked-only members are carved, built and registered (reps from any binary serve; an out-of-scope rep keeps
  its own C file, its made body still serves); without it every binary, slus first. Run slus before rockx5.
Stdlib only. Target bytes are never printed or written (G12).
"""

import collections
import contextlib
import hashlib
import os
import io
import re
import shutil
import struct
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT / "tools/census"), str(ROOT / "tools/probe"), str(ROOT / "tools/dedup"), str(ROOT / "tools/sig")]
import carve  # noqa: E402
import census  # noqa: E402
import probe  # noqa: E402
import reconcile  # noqa: E402
import x4core  # noqa: E402

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
OVL = re.compile(r"_(ovl\d+)$")
CTYPE = r"(?:void|char|short|int|long|float|double|signed|unsigned|[us](?:8|16|32|64)|f32|f64|\w+_t|(?:struct|union|enum)\s+\w+)"


def signature(words):
    """= sig.py band(): sha1 hex of the dup_key words."""
    n = census.dup_key(words)
    return hashlib.sha1(struct.pack(f"<{len(n)}I", *n)).hexdigest()


def twin(a, b, callee):
    """Byte twin in place: equal raw words; jal targets free when the body takes DEDUP_CALLEE."""
    if callee:
        a, b = (tuple(w & ~0x3FFFFFF if w >> 26 == 3 else w for w in x) for x in (a, b))
    return tuple(a) == tuple(b)


def relocs(obj, name):
    """[(word index, reloc type, symbol, addend)] of function name in ELF obj (x4core.Elf), None when not defined.
    addend = the in-place field (REL, C0039): 26 -> target << 2; HI16/LO16 paired as Elf.refs (a LO16 with the nearest
    HI16 before it, a HI16 with the nearest LO16 after it); a section symbol -> the symbol holding it (Elf.resolve)."""
    e = x4core.Elf(obj)
    s = e.defined(name)
    n = next((len(w) for nm, w, _ in x4core.functions(e) if nm == name), 0)
    if s is None or not n:
        return None
    sh, base = s[4], s[1]
    rels = [(off, info & 0xFF, info >> 8) for off, info in e.rels.get(sh, [])]

    def lo16(off):
        w = e.word(sh, off) & 0xFFFF
        return w - ((w & 0x8000) << 1)

    out = []
    for off, t, si in rels:
        if not base <= off < base + 4 * n:
            continue
        w = e.word(sh, off)
        if t == 4:
            a = (w & 0x3FFFFFF) << 2
        elif t in (5, 6):
            his = sorted(o for o, u, x in rels if u == 5 and x == si)
            hi = off if t == 5 else max((o for o in his if o <= off), default=his[0] if his else None)
            lo = off if t == 6 else min((o for o, u, x in rels if u == 6 and x == si and o >= off), default=None)
            a = ((e.word(sh, hi) & 0xFFFF) << 16 if hi is not None else 0) + (lo16(lo) if lo is not None else 0)
            a = (a + 0x80000000) % (1 << 32) - 0x80000000
        elif t == 7:
            a = lo16(off)
        else:
            a = w
        sym, a = e.resolve(si, a)
        out.append(((off - base) // 4, t, sym, a))
    return sorted(out)


def misuse(text, sym):
    """'' when `#define sym ...` renames only the symbol in body text, else how the body uses sym otherwise."""
    s = re.escape(sym)
    if re.search(rf"(?:\.|->)\s*{s}\b", text):
        return "struct field"
    if re.search(rf"\bDEDUP_NAME\s*\([^)]*\b{s}\b", text):
        return "param"
    fn = text[text.find("{", max(text.find("DEDUP_NAME"), 0)):]
    for m in re.finditer(rf"\b{CTYPE}[\s*]+{s}\s*[;=\[,)]", fn):  # ponytail: type-led declarator; fails closed
        if "extern" not in fn[fn.rfind("\n", 0, m.start()) + 1:m.start()]:
            return "local"
    return ""


def reloc_gate(r, f, relocs_of, callee, text):
    """-> (None, {sym_R: sym_M} differing renames) when masked-only member f is reloc-gated against rep r, else (why, None)."""
    ra, ma = relocs_of(r), relocs_of(f)
    if ra is None or ma is None:
        return f"no object with relocations for {(f if ma is None else r)['name']}", None
    if len(r["words"]) != len(f["words"]):
        return f"size {len(f['words'])} words, rep {len(r['words'])}", None
    rd, md = {i: (t, a) for i, t, _, a in ra}, {i: (t, a) for i, t, _, a in ma}
    if rd != md or len(ra) != len(ma):
        k = min({i for i in rd.keys() | md.keys() if rd.get(i) != md.get(i)}, default=0)
        return f"reloc type/addend mismatch at word {k}", None
    ren, own = {}, carve.module_of(f)
    for (_, t, sr, _), (_, _, sm, _) in zip(ra, ma):
        if not sr or not sm or sr[0] in ".$" or sm[0] in ".$":
            return f"unresolvable reloc symbol {sr or '?'} -> {sm or '?'}", None
        if (o := OVL.search(sm)) and o.group(1) != own:
            return f"foreign-object target {sm}", None
        if callee and t == 4:
            continue  # jal: DEDUP_CALLEE carries it
        if ren.setdefault(sr, sm) != sm:
            return f"non-functional map {sr} -> {ren[sr]} | {sm}", None
    ren = {a: b for a, b in ren.items() if a != b}
    for sr in sorted(ren):
        if u := misuse(text, sr):
            return f"{sr} is a {u} in the body, not a symbol", None
    for i, (x, y) in enumerate(zip(r["words"], f["words"])):
        if (x ^ y) & ~(x4core.MASKS.get(rd[i][0], 0) if i in rd else 0):
            return f"raw word {i} (+0x{4 * i:X}) differs outside a relocated field", None
    return None, ren


def members(fns, stem, callee=False, relocs_of=None, text=""):
    """-> (signature, member rows (byte twins + reloc-gated) sorted by alias, vram, name, {(alias, name): rename map}
    of the reloc-gated, refused masked-only [(row, why)]), or raise SystemExit. relocs_of(row) -> relocs() or None."""
    sigs = {id(f): signature(f["words"]) for f in fns}
    s = {sigs[id(f)] for f in fns if f["name"] == stem}
    if len(s) != 1:
        raise SystemExit(f"dedup: refused -- body stem {stem} names {len(s)} signatures (want 1)")
    s = s.pop()
    grp = next((g["members"] for g in census.group(fns) if g["kind"] == "dup" and sigs[id(g["members"][0])] == s), [])
    out = {(f["alias"], f["name"]): f for f in grp + [f for f in fns if sigs[id(f)] == s]}
    reps = [f for f in fns if f["name"] == stem]
    tw = [f for f in out.values() if any(twin(f["words"], r["words"], callee) for r in reps)]
    tk = {(f["alias"], f["name"]) for f in tw}
    maps, refused = {}, []
    for k, f in sorted(out.items()):
        if k in tk:
            continue
        why, ren = "no reloc source", None
        for r in reps if relocs_of else ():
            why, ren = reloc_gate(r, f, relocs_of, callee, text)
            if ren is not None:
                break
        if ren is None:
            refused.append((f, why))
        else:
            maps[k] = ren
            tw.append(f)
    return s, sorted(tw, key=lambda f: (f["alias"], int(f["vram"], 16), f["name"])), maps, refused


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
def gate(root, cx, f, body, target, ren=None):
    """-> ("have", None) | ("new", member text) | ("fail", why). Never writes the tree. ren: {sym_R: sym_M} defines."""
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
    defs += sorted((ren or {}).items())
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


def real_obj(f, cx):
    """The built object holding row f: build/<a>/src/<a>/<name>.o when C-banked, else its asm file's object; or None."""
    a, name = f["alias"], f["name"]
    if (cx.root / f"src/{a}/{name}.c").exists():
        return ROOT / f"build/{a}/src/{a}/{name}.o"
    try:
        p = carve.plan(cx, int(f["vram"], 16), carve.module_of(f))
    except carve.Refused:
        return None
    return ROOT / f"build/{a}/asm/{a}/{Path(p[2]['file']).stem}.o"


def reloc_source(cx_of, obj=real_obj):
    """-> relocs_of(row) for members(): relocs() of obj(row, cx_of(alias)), None without a built object."""
    return lambda f: relocs(o, f["name"]) if (o := obj(f, cx_of(f["alias"]))) and Path(o).exists() else None


def run(body, root=ROOT, fns=None, target=real_target, build=True, asm_root=ROOT, obj=real_obj, cxs=None, reg=True,
        only=None):
    """reg=False: no registry write (sweep registers after its builds); only: carve members of that alias only."""
    body = Path(body)
    text = body.read_text()
    cxs = {} if cxs is None else cxs  # sweep shares the per-alias Ctx (its asm index scan) across reps

    def cx_of(a):
        if a not in cxs:
            cxs[a] = carve.Ctx(root, a, asm_root=asm_root)
        return cxs[a]

    sig, ms, maps, refused = members(fns if fns is not None else fresh_fns(), body.stem, "DEDUP_CALLEE" in text,
                                     reloc_source(cx_of, obj), text)
    if only:
        ms = [f for f in ms if f["alias"] == only]
        maps = {k: v for k, v in maps.items() if k[0] == only}
        refused = [(f, w) for f, w in refused if f["alias"] == only]
    if maps or refused:
        print(f"dedup: {len(maps) + len(refused)} masked-only: {len(maps)} reloc-gated, {len(refused)} refused")
    for f, why in refused:  # ponytail: a refusal is the old masked-only skip with a reason; it does not set the exit
        print(f"dedup: FAIL {f['alias']} {f['name']} -- {why}")
    gated, new, failed = [], {}, []
    for f in ms:
        verdict, x = gate(root, cx_of(f["alias"]), f, body, target, maps.get((f["alias"], f["name"])))
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
    if gated and reg:
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
def banked_groups(root, fns):
    """-> (registry, {(alias, name): its registry entry}, yaml-c keys, [(banked [(key, callee)], unregistered keys,
    masked-only keys)] per dup group with a C-banked member): check()'s counting, shared with sweep."""
    reg, _ = registry(root)
    regd = {k: e for e in reg.values() for k in e["members"]}
    aliases = sorted(p.name.split(".")[1] for p in (root / "config").glob("splat.*.yaml"))
    cset = {(a, n) for a in aliases for n in yaml_c(root, a)}
    words = {(f["alias"], f["name"]): f["words"] for f in fns}
    out = []
    for g in census.group(fns):
        keys = [(x["alias"], x["name"]) for x in g["members"]]
        banked = [(c, regd[c]["body"] and "DEDUP_CALLEE" in (root / regd[c]["body"]).read_text() if c in regd else
                   False) for c in keys if c in cset]
        if g["kind"] == "dup" and banked:
            unreg, masked = [], []
            for k in keys:
                if k in regd:
                    continue
                if any(c != k and twin(words[k], words[c], cal) for c, cal in banked):
                    unreg.append(k)
                elif k not in cset:
                    masked.append(k)
            out.append((banked, unreg, masked))
    return reg, regd, cset, out


def check(root=ROOT, fns=None):
    fns = fns if fns is not None else fresh_fns()
    reg, regd, cset, groups = banked_groups(root, fns)
    unreg = {k for _, u, _ in groups for k in u}
    masked = {k for _, _, m in groups for k in m}
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


# ---- reps from banked C (gate.py rescan imports these) ----
CALL = re.compile(r"\b([A-Za-z_]\w*)\s*\((?!\s*\*)")  # `void (*)()` in a cast is not a call (T4.c6)
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


# ---- sweep ----
FAIL_RE = re.compile(r"^dedup: FAIL (\w+) (\w+) -- (.*)$", re.M)


def reason(why):
    """Refusal class: why up to its first detail, without numbered or symbol tokens."""
    w = re.split(r",| -> |: ", why)[0].split()
    return " ".join(t for t in w if not re.search(r"[\d_]", t)) or w[0]


def sweep(dry=True, only=None):
    """dry: in a scratch worktree, dropped; else in the main tree, the green set registered. only: that alias's members."""
    out = io.StringIO()
    with contextlib.redirect_stdout(out):
        ok = reloc_control(fixture_work("sweep_control"))
    if not ok or CONTROL not in out.getvalue().splitlines():
        print(out.getvalue(), end="")
        print("dedup: sweep control FAIL -- the planted foreign-overlay member was not refused")
        return 1
    print("dedup: sweep control refused" + CONTROL.removeprefix("dedup: FAIL"))
    fns = fresh_fns()
    rows = {(f["alias"], f["name"]): f for f in fns}
    order = lambda k: (k[0], int(rows[k]["vram"], 16), k[1])  # noqa: E731
    _, regd, _, groups = banked_groups(ROOT, fns)
    jobs = []  # (rep key, registered/shared body rel or None = made from the rep's C file, masked-only keys)
    for banked, _, masked in groups:
        masked = [k for k in masked if not only or k[0] == only]
        if masked:
            keys = sorted((c for c, _ in banked), key=order)
            body = next((regd[c]["body"] for c in keys if c in regd and regd[c]["body"]), None) or next(
                (f"src/shared/{c[1]}.c" for c in keys if (ROOT / f"src/shared/{c[1]}.c").exists()), None)
            jobs.append((next((c for c in keys if body and c[1] == Path(body).stem), keys[0]), body, masked))
    n = sum(len(m) for *_, m in jobs)
    print(f"dedup: sweep {len(jobs)} reps, {n} masked-only members", flush=True)
    res, state = {}, {}  # res: key -> (gated, why); state: job -> {"carves": {alias: [(vram, module, text)]}, "swap"}
    wt = carve.make_wt() if dry else ROOT
    made = {}  # job -> its body made from the rep's C file (removed when none of its members ends gated)

    def undo(j, swap):
        if swap and swap[1].read_text() == swap[3]:  # ponytail: back to the committed text, not rebuilt
            swap[1].write_text(swap[2])
        if j in made:
            made.pop(j).unlink(missing_ok=True)

    try:
        cxs = {a: carve.Ctx(wt, a, asm_root=ROOT) for a in sorted({k[0] for k in rows})}
        for j, ((a, name), body, masked) in enumerate(jobs):
            b, swap = wt / (body or f"src/shared/{name}.c"), None
            if body is None:  # = gate.py propagate_rep's rep step, in the worktree
                cf = wt / f"src/{a}/{name}.c"
                callee = rep_callee(name, cf, rows[a, name]["words"])
                text = rep_text(name, cf, callee)
                if text is None:
                    res.update((k, (False, "rep refused: no DEDUP_NAME(...) { definition")) for k in masked)
                    continue
                old = cf.read_text()
                b.write_text(text)
                reconcile.fmt(b)
                made[j] = b
                if not only or a == only:  # an out-of-scope rep keeps its C file; its body still serves
                    cf.write_text(reconcile.member_text(name, b, [("DEDUP_CALLEE", callee)] if callee else []))
                    reconcile.fmt(cf)
                    swap = (a, cf, old, cf.read_text())
            before, buf = set((wt / "src").rglob("*.c")), io.StringIO()
            with contextlib.redirect_stdout(buf):
                try:
                    run(b, root=wt, fns=fns, build=False, cxs=cxs, reg=False, only=only)
                except SystemExit as e:
                    print(f"dedup: sweep-refused -- {str(e).removeprefix('dedup: refused -- ')}")
            if m := re.search(r"^dedup: sweep-refused -- (.*)$", buf.getvalue(), re.M):
                res.update((k, (False, m.group(1))) for k in masked)
                undo(j, swap)
                continue
            fails = {(x[1], x[2]): x[3] for x in FAIL_RE.finditer(buf.getvalue())}
            new = set((wt / "src").rglob("*.c")) - before
            if not new:  # nothing carved: no build for this rep
                undo(j, swap)
                swap = None
            st = state[j] = {"carves": {}, "swap": swap}
            for p in sorted(new):
                f = rows[p.parent.name, p.stem]
                st["carves"].setdefault(f["alias"], []).append((int(f["vram"], 16), carve.module_of(f), p.read_text()))
            for k in masked:
                p = wt / f"src/{k[0]}/{k[1]}.c"
                res[k] = ((False, fails[k]) if k in fails else (True, f"by {name}") if p in new else
                          (True, f"by {name} (already C)") if includes(wt, *k, b.name) else
                          (False, "not a member of the body"))
        sys.path.insert(0, str(ROOT / "tools/wave"))
        from gate import bisect  # noqa: E402 -- lazy: gate.py imports this module
        # sequential, never two binaries at once; slus first: the rockx5 build links slus too (mk/rockx5.mk:41), so
        # slus is left at its green set before rockx5 is bisected
        for alias in sorted((a for a in cxs if not only or a == only), key=lambda a: (a != "slus", a)):
            keys = [j for j, st in state.items() if alias in st["carves"] or (st["swap"] and st["swap"][0] == alias)]
            if not keys:
                continue
            cx, on, logs = cxs[alias], set(keys), []

            def put(want):
                for j in keys:
                    st = state[j]
                    if (j in want) == (j in on):
                        continue
                    cs = st["carves"].get(alias, [])
                    for vram, mod, text in (cs if j in want else reversed(cs)):
                        if j in want:
                            carve.apply(cx, carve.plan(cx, vram, mod), text)
                        else:
                            carve.revert(cx, vram, mod)
                    if st["swap"] and st["swap"][0] == alias:
                        st["swap"][1].write_text(st["swap"][3] if j in want else st["swap"][2])
                    on.symmetric_difference_update({j})

            def ok(want):
                put(want)
                log = RUN / f"sweep.{alias}.{len(logs)}.build.log"
                log.parent.mkdir(parents=True, exist_ok=True)
                t = time.time()
                with open(log, "w") as fh:
                    rc = subprocess.run(["make", "split", f"BINARY={alias}", f"PY={sys.executable}"], cwd=wt,
                                        stdout=fh, stderr=subprocess.STDOUT).returncode or subprocess.run(
                        ["make", f"-j{os.cpu_count()}", "build", f"BINARY={alias}", f"PY={sys.executable}"], cwd=wt,
                        stdout=fh, stderr=subprocess.STDOUT).returncode
                logs.append(log)
                print(f"dedup: sweep build {alias} {len(want)} of {len(keys)} reps exit {rc} {time.time() - t:.0f}s "
                      f"({log.relative_to(ROOT)})", flush=True)
                return rc == 0

            good = set(bisect(keys, ok))
            put(good)  # the green set stays applied for the next binary's build
            for j in set(keys) - good:
                rep_red = bool(state[j]["swap"]) and state[j]["swap"][0] == alias  # the rep's own C file: all of it
                for k in jobs[j][2]:
                    if res[k][0] and (k[0] == alias or rep_red and dry):  # wet: the body stays for the others
                        res[k] = (False, f"sha: {alias} build red with this rep's carves (bisected)")
        for j, ((a, name), body, masked) in enumerate(jobs if not dry else ()):  # register the green set
            gk = [k for k in masked if res.get(k, (False,))[0]]
            if not gk:
                undo(j, state.get(j, {}).get("swap"))
                continue
            b = ROOT / (body or f"src/shared/{name}.c")
            ks = set(gk) | ({(a, name)} if includes(ROOT, a, name, b.name) else set())
            register(ROOT, signature(rows[a, name]["words"]), b.relative_to(ROOT).as_posix(),
                     sorted((rows[k] for k in ks), key=lambda f: (f["alias"], int(f["vram"], 16), f["name"])))
    finally:
        if dry:
            carve.drop_wt(wt)  # this process's worktree only
    for k in sorted(res, key=order):
        print(f"dedup: sweep {k[0]} {k[1]} {'gated' if res[k][0] else 'refused'} {res[k][1]}")
    g = [k for k in res if res[k][0]]
    for cls, c in sorted(collections.Counter(reason(w) for x, w in res.values() if not x).items(),
                         key=lambda e: (-e[1], e[0])):
        print(f"dedup: sweep refused {c} {cls}")
    print(f"dedup: sweep {sum('already C' in res[k][1] for k in g)} of {len(g)} gated members already C")
    print(f"dedup: sweep {len(g)} of {n} masked-only members byte-gated, {n - len(g)} refused")
    return 0


# ---- selftest ----
CONTROL = "dedup: FAIL fx func_80001120 -- foreign-object target fx_d_c_ovl09"


def fixture_work(name):
    """A fresh scratch copy of fixtures/propagate with reconcile's fixture src, under .run/dedup/propagate/<name>."""
    work = RUN / name
    shutil.rmtree(work, ignore_errors=True)
    shutil.copytree(FIX, work)
    shutil.copytree(reconcile.FIX / "src", work / "src")
    return work


def reloc_control(work):
    """fixtures/propagate/reloc in work: a masked-only member reloc-gated by rename, a planted masked-only member whose
    global lives in another overlay refused (prints CONTROL) -> ok."""
    rb = work / "src/shared/func_80001100.c"  # reloc gating: rep, a renamed member, a foreign-object member
    shutil.copy(FIX / "reloc/body.c", rb)
    robj, _ = probe.compile_obj(FIX / "reloc/objs.c", "propagate_selftest_reloc", reconcile.triple())
    rt = probe.read_func(robj, "func_80001100")[0]
    rw = struct.unpack(f"<{len(rt) // 4}I", rt)
    k = relocs(robj, "func_80001100")[-1][0]  # the %lo slot: the members' globals sit elsewhere
    moved = rw[:k] + (rw[k] ^ 4,) + rw[k + 1:]
    rf = [{"alias": "fx", "module": "fx/main", "kind": "game", "name": f"func_{v:08X}", "vram": f"{v:08X}",
           "insns": len(rw), "words": w} for v, w in ((0x80001100, rw), (0x80001110, moved), (0x80001120, moved))]
    ok = run(rb, root=work, fns=rf, target=lambda f, p: rt, build=False, asm_root=work, obj=lambda f, cx: robj) == 0
    ok &= "#define fx_d_a fx_d_b" in (work / "src/fx/func_80001110.c").read_text()
    return ok and not (work / "src/fx/func_80001120.c").exists()


def selftest():
    work = fixture_work("selftest")
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
        ok &= reloc_control(work)
    lines = out.getvalue().splitlines()
    want = ["dedup: FAIL fx func_80001030 -- word 0 (+0x0) differs", "dedup: 3 of 4 members byte-gated",
            "dedup: unregistered fx func_80001030",
            "dedup: registry OK (1 groups, 3 members, 0 unregistered, 0 ungated)", "dedup: ungated fx func_80001020",
            "dedup: 2 masked-only: 1 reloc-gated, 1 refused", CONTROL, "dedup: 2 of 2 members byte-gated"]
    ok &= all(w in lines for w in want)
    if not ok:
        print(out.getvalue(), end="")
    print("dedup: control OK -- fixture body 3 members gated, planted differing member refused, "
          "unregistered member caught, reloc-gated member renamed, foreign-object member refused" if ok
          else "dedup: selftest FAIL")
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
    if argv[:1] == ["sweep"]:
        rest, only = [x for x in argv[1:] if x != "--dry-run"], None
        if rest[:1] == ["--binary"] and len(rest) == 2 and (ROOT / f"config/splat.{rest[1]}.yaml").exists():
            rest, only = [], rest[1]
        if rest:
            print(f"dedup: refused -- sweep [--dry-run] [--binary <alias>]: {' '.join(argv[1:])}")
            return 2
        return sweep("--dry-run" in argv, only)
    print(__doc__)
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
