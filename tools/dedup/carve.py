"""The carve chain: cut one asm function into its own splat `c` subsegment (C0027) and back.

  carve.py plan|apply|revert <alias> <vram> [--name N] [--module M] [--body FILE]
  carve.py own [<alias>]
  carve.py sample [--per N]
  carve.py --selftest

<vram> is hex. --module = the yaml code segment (rockx5 `ovlNN`); required when overlays share the vram (C0019).
Rodata ownership by gaps, per code segment: region = a rodata/textbin/rodatabin subsegment ahead of the segment's first
  asm/c sub; label = a region address referenced (%hi/%lo/%gp_rel, jtbl_) from text (asm/<alias>/*.s and
  nonmatchings/); range = label .. next label (or region end): owned (one referencing function), shared (2+),
  unreferenced (none, incl. a region head before its first label). Refs outside the own segment's regions (resident
  segment, other binary, .data, a textbin after text) are externs. A function whose region refs all fall in ranges it
  owns, forming one contiguous span, is plannable and carries that span.
plan prints the cut(s) it would write, or `carve: refused <reason> <alias> <vram>` (exit 1). Reasons:
  not-found (no asm function starts there), ambiguous (vram in several segments, no --module),
  outside-asm (start/end not inside one asm subsegment), rodata-shared (a region ref into a shared range or a
  non-contiguous span; a jtbl there too), jump-table (a `jtbl_` ref outside the own regions, or `jlabel` with no
  `jtbl_` ref), c-exists (src/<alias>/<name>.c already present).
apply edits config/splat.<alias>.yaml only (G43) by line inserts, no YAML round trip, and writes src/<alias>/<name>.c
  (INCLUDE_ASM placeholder, or --body text). Lines it writes end `# carve`; a line it replaces keeps its text after
  `# carve was: `, so the yaml is its own undo log. An owner's span also splits its region: `[a, .rodata, <name>]`
  (paired with the `c` sub; splat migrate_rodata_to_functions writes the bytes into the INCLUDE_ASM .s), then the
  remainder (`rodata, <hex>` or `rodatabin`); a textbin head before the span becomes `rodatabin` (.rodata links
  ahead of .text). A span whose last label is a `jtbl_` ends pad-free: after the table's consecutive in-function
  address words (read from the yaml's target_path), its alignment pad going to the remainder.
revert restores those lines and removes the C file: the yaml returns byte-for-byte (newest carve first in a subsegment).
own prints per alias `carve: rodata <alias> owned <o> shared <s> unreferenced <u> ranges; owners <f> fns`
  (f = plannable owners: every region ref owned, one contiguous span; carved `.rodata` subs are no longer regions).
sample: a scratch `git worktree` at .run/carve/wt-<pid> (never the main tree, G16; ignored inputs symlinked), every k-th
  plannable game-lane asm function of the inventory per alias (sorted alias+vram), apply all, `make split build`,
  whole-binary SHA per alias. Prints `carve: <n> of <n> carves build` and `carve: refused <reason> <count>` (over
  every game-lane asm function); exit 1 on any SHA fail. Needs a post-`make check` tree (asm/, build maps).
--selftest: tools/dedup/fixtures/carve (hand-written yaml + asm, no game bytes): apply+revert byte-identical, an
  owned-rodata control (region split), a jtbl + 4-byte pad control (fx.bin, synthetic: remainder at the pad),
  planted unresolved jump table and shared rodata refused.
Stdlib only.
"""

import contextlib
import io
import os
import re
import shutil
import subprocess
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
FIX = Path(__file__).resolve().parent / "fixtures" / "carve"
sys.path.insert(0, str(ROOT / "tools" / "census"))

SUB = re.compile(r"^(\s+)- \[(0x[0-9A-Fa-f]+)(?:, ([.\w]+))?(?:, (\w+))?\](.*)$")
TOP = re.compile(r"^  - ")
START = re.compile(r"start: (0x[0-9A-Fa-f]+)")
VRAM = re.compile(r"vram: (0x[0-9A-Fa-f]+)")
NAME = re.compile(r"name: (\w+)")
WORD = re.compile(r"/\*\s+([0-9A-F]+)\s+([0-9A-F]{8})\s")
REF = re.compile(r"%(?:hi|lo|gp_rel)\((\w+)")
SYM = re.compile(r"^\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+)")
HEXNAME = re.compile(r"^(?:D|jtbl)_([0-9A-F]{8})")
DADDR = re.compile(r"/\*\s+[0-9A-F]+\s+([0-9A-F]{8})\b")
RODATA = ("rodata", "textbin", "rodatabin")
MARK, WAS = "  # carve", "  # carve was: "


class Refused(Exception):
    pass


def parse(lines):
    """Code segments: [{name, start, vram, ram_id, end, subs: [(line idx, off, type, name, end)]}]."""
    tops, segs = [], []
    for i, ln in enumerate(lines):
        if TOP.match(ln):
            tops.append(i)
    tops.append(len(lines))
    starts = []
    for a, b in zip(tops, tops[1:]):
        blk = lines[a:b]
        m = START.search("".join(blk)) or re.match(r"  - \[(0x[0-9A-Fa-f]+)", blk[0])
        starts.append(int(m.group(1), 16) if m else None)
        text = "".join(blk)
        if "type: code" not in text:
            continue
        subs = []
        for k, ln in enumerate(blk):
            s = SUB.match(ln)
            if s:
                subs.append([a + k, int(s.group(2), 16), s.group(3), s.group(4)])
        segs.append({"name": NAME.search(text).group(1), "start": starts[-1], "vram": int(VRAM.search(text).group(1), 16),
                     "ram_id": "exclusive_ram_id" in text, "subs": subs, "top": len(starts) - 1})
    for sg in segs:
        nxt = next((s for s in starts[sg["top"] + 1:] if s is not None), None)
        sg["end"] = nxt
        ends = [s[1] for s in sg["subs"][1:]] + [nxt]
        for s, e in zip(sg["subs"], ends):
            s.append(e)
    return segs


def asm_index(adir):
    """rom offset -> {name, size, body lines, file}; plus the set of dlabel names in text files."""
    idx, dl = {}, set()
    for f in sorted(adir.glob("*.s")) + sorted(adir.glob("nonmatchings/*/*.s")):  # + INCLUDE_ASM-carved functions
        lines = f.read_text().splitlines()
        size, cur = {}, None
        for ln in lines:
            t = ln.split()
            if not t:
                continue
            if t[0] == "nonmatching" and len(t) == 3:
                size[t[1].rstrip(",")] = int(t[2], 16)
            elif t[0] == "glabel":
                cur = {"name": t[1], "size": size.get(t[1]), "body": [], "file": f.name}
            elif t[0] == "dlabel":
                dl.add(t[1])
            elif t[0] == "endlabel":
                if cur and cur["body"]:
                    m = WORD.search(cur["body"][0]) or next(WORD.search(x) for x in cur["body"] if WORD.search(x))
                    idx[int(m.group(1), 16)] = cur
                cur = None
            elif cur is not None:
                cur["body"].append(ln)
    return idx, dl


class Ctx:
    """One alias under one root: yaml lines, asm index (from asm_root), symbols, rodata ranges."""

    def __init__(self, root, alias, asm_root=None):
        self.root, self.alias = Path(root), alias
        self.yaml = self.root / f"config/splat.{alias}.yaml"
        self.idx, self.dl = asm_index(Path(asm_root or root) / f"asm/{alias}")
        self.syms = {}
        sp = self.root / f"config/symbols.{alias}.txt"
        if sp.exists():
            for ln in sp.read_text().splitlines():
                m = SYM.match(ln)
                if m:
                    self.syms[m.group(1)] = int(m.group(2), 16)
        self.dla = {}  # dlabel name -> vram, every .s under asm/<alias> (rodata/data files included)
        for f in sorted((Path(asm_root or root) / f"asm/{alias}").rglob("*.s")):
            pend = None
            for ln in f.read_text().splitlines():
                if ln.startswith("dlabel "):
                    pend = ln.split()[1]
                elif pend and (m := DADDR.search(ln)):
                    self.dla.setdefault(pend, int(m.group(1), 16))
                    pend = None
        self._own = None

    def lines(self):
        return self.yaml.read_text().splitlines(keepends=True)

    def addr(self, name):
        m = HEXNAME.match(name)
        return int(m.group(1), 16) if m else self.syms.get(name, self.dla.get(name))

    def own(self):
        """Rodata ownership by gaps (cached). -> (ranges [(seg, lo, hi, owner roms)], fns {rom: {"spans", "ok"}}).
        Region = a rodata/textbin/rodatabin subsegment of the function's own code segment ahead of its first asm/c sub
        (.rodata links first; a textbin after text is .text/.data: extern); labels = region addresses
        referenced (%hi/%lo/%gp_rel, jtbl_) from text; range = label .. next label or region end."""
        if self._own is None:
            segs = [s for s in parse(self.lines()) if s["end"] is not None]
            regs = [(sg["name"], sg["vram"] + s[1] - sg["start"], sg["vram"] + s[4] - sg["start"])
                    for sg in segs for s in sg["subs"] if s[2] in RODATA and s[4] is not None
                    and s[1] < next((x[1] for x in sg["subs"] if x[2] in ("asm", "c")), 1 << 32)]
            labels, refs = {g: {} for g in regs}, {}
            for rom, fn in sorted(self.idx.items()):
                sg = next((s for s in segs if s["start"] <= rom < s["end"]), None)
                for r in REF.findall("\n".join(fn["body"])) if sg else ():
                    a = self.addr(r)
                    g = next((g for g in regs if g[0] == sg["name"] and a is not None and g[1] <= a < g[2]), None)
                    if g:
                        labels[g].setdefault(a, set()).add(rom)
                        refs.setdefault(rom, set()).add((g, a))
            ranges, at = [], {}
            for g, lab in labels.items():
                cuts = sorted(lab)
                if not cuts or cuts[0] > g[1]:
                    ranges.append((g[0], g[1], cuts[0] if cuts else g[2], frozenset()))
                for a, b in zip(cuts, cuts[1:] + [g[2]]):
                    ranges.append((g[0], a, b, frozenset(lab[a])))
                    at[(g, a)] = ranges[-1]
            fns = {}
            for rom, rs in refs.items():
                sp = sorted(at[x] for x in rs)
                ok = all(r[3] == {rom} for r in sp) and all(x[2] == y[1] for x, y in zip(sp, sp[1:]))
                fns[rom] = {"span": (sp[0][0], sp[0][1], sp[-1][2]), "ok": ok}
            self._own = ranges, fns
        return self._own


def remainder_name(alias, seg, vram):
    return f"game_{vram:08X}" if alias == "slus" else f"{seg['name']}_{vram:08X}"


def plan(cx, vram, module=None, name=None):
    """-> (segment, sub, fn, rom, end, name) or raise Refused(reason)."""
    segs = [s for s in parse(cx.lines()) if s["end"] is not None and s["vram"] <= vram < s["vram"] + s["end"] - s["start"]
            and (module is None or s["name"] == module)]
    if not segs:
        raise Refused("not-found")
    if len(segs) > 1:
        raise Refused("ambiguous")
    sg = segs[0]
    rom = sg["start"] + vram - sg["vram"]
    fn = cx.idx.get(rom)
    if fn is None or fn["size"] is None:
        raise Refused("not-found")
    end = rom + fn["size"]
    sub = next((s for s in sg["subs"] if s[1] <= rom < s[4]), None)
    if sub is None or sub[2] != "asm" or end > sub[4]:
        raise Refused("outside-asm")
    body = "\n".join(fn["body"])
    own = cx.own()[1].get(rom)
    if own and not own["ok"]:
        raise Refused("rodata-shared")
    jt = [r for r in REF.findall(body) if r.startswith("jtbl_")]
    if re.search(r"^\s*jlabel\b", body, re.M) and not jt:
        raise Refused("jump-table")
    for r in jt:  # a jtbl outside the own segment's regions: no owner to move with the function
        a = cx.addr(r)
        if not own or a is None or not own["span"][1] <= a < own["span"][2]:
            raise Refused("jump-table")
    name = name or fn["name"]
    if (cx.root / f"src/{cx.alias}/{name}.c").exists():
        raise Refused("c-exists")
    return sg, sub, fn, rom, end, name, own and own["span"]


def cut_lines(cx, p):
    """-> (line index, number of lines replaced, new lines)."""
    sg, sub, fn, rom, end, name, _ = p
    i, off = sub[0], sub[1]
    old = cx.lines()[i]
    ind = SUB.match(old).group(1)
    new = [f"{ind}- [0x{rom:X}, c, {name}]" + (WAS + old.strip() if rom == off else MARK) + "\n"]
    if end < sub[4]:
        new.append(f"{ind}- [0x{end:X}, asm, {remainder_name(cx.alias, sg, sg['vram'] + end - sg['start'])}]{MARK}\n")
    return i + (rom != off), int(rom == off), new


def jtbl_end(cx, p, a, b):
    """Span end (rom) trimmed to a trailing jump table: when the span's last label is a `jtbl_`, end it after the
    consecutive words that are addresses inside the function, so the alignment pad after the table goes to the
    remainder. Bytes from the yaml's target_path (the extracted binary); absent -> b unchanged."""
    sg, fn, rom = p[0], p[2], p[3]
    lo, v0 = sg["vram"] - sg["start"], sg["vram"] + rom - sg["start"]
    labs = {cx.addr(r): r for r in REF.findall("\n".join(fn["body"]))}
    last = max((x for x in labs if x is not None and a + lo <= x < b + lo), default=None)
    m = re.search(r"target_path: (\S+)", "".join(cx.lines()))
    if last is None or not labs[last].startswith("jtbl_") or not m or not (cx.root / m.group(1)).exists():
        return b
    with open(cx.root / m.group(1), "rb") as f:
        f.seek(last - lo)
        data = f.read(b - (last - lo))
    n = 0
    while 4 * n + 4 <= len(data) and v0 <= int.from_bytes(data[4 * n:4 * n + 4], "little") < v0 + fn["size"]:
        n += 1
    return last - lo + 4 * n if n else b


def ro_lines(cx, p):
    """The owned rodata span's region split -> (line index, number of lines replaced, new lines), or None.
    `[a, .rodata, <name>]` pairs with the `c` sub (splat migrate_rodata_to_functions puts the bytes in the INCLUDE_ASM
    .s); a textbin prefix becomes rodatabin (it would otherwise link after .rodata); remainder after it."""
    sg, sp, name = p[0], p[6], p[5]
    if not sp:
        return None
    a, b = (sg["start"] + v - sg["vram"] for v in sp[1:])
    s = next(s for s in sg["subs"] if s[2] in RODATA and s[1] <= a and b <= s[4])
    b = jtbl_end(cx, p, a, b)
    old = cx.lines()[s[0]]
    m = SUB.match(old)
    ind, new = m.group(1), []
    if a > s[1] and s[2] == "textbin":
        new.append(f"{ind}- [0x{s[1]:X}, rodatabin{', ' + s[3] if s[3] else ''}]{WAS}{old.strip()}\n")
    new.append(f"{ind}- [0x{a:X}, .rodata, {name}]" + (WAS + old.strip() if a == s[1] else MARK) + "\n")
    if b < s[4]:
        new.append(f"{ind}- [0x{b:X}, " + (f"rodata, {b:X}" if s[2] == "rodata" else "rodatabin") + f"]{MARK}\n")
    nrep = int(a == s[1] or s[2] == "textbin")
    return s[0] + (1 - nrep), nrep, new


def c_text(cx, p):
    fn, name = p[2], p[5]
    return (f'#include "include_asm.h"\n\nINCLUDE_ASM("asm/{cx.alias}/nonmatchings/{name}", {fn["name"]});\n')


def unstale(cx, old):
    """splat writes a textbin/rodatabin .s only when it is absent (segtypes/common/textbin.py split): one whose sub this
    yaml edit retyped (a textbin head <-> rodatabin) would keep its old section in a reused tree, so it goes."""
    def bins(ls):
        return {int(m[2], 16): (m[3], m[4]) for m in map(SUB.match, ls) if m and m[3] in ("textbin", "rodatabin")}
    a, b = bins(old), bins(cx.lines())
    for off in a.keys() & b.keys():
        if a[off] != b[off]:
            for n in {a[off][1], b[off][1]}:
                (cx.root / f"asm/{cx.alias}/data/{n or f'{off:X}'}.s").unlink(missing_ok=True)


def apply(cx, p, body=None):
    lines = cx.lines()
    old = list(lines)
    for i, nrep, new in sorted(filter(None, (cut_lines(cx, p), ro_lines(cx, p))), key=lambda e: -e[0]):
        lines[i:i + nrep] = new
    cf = cx.root / f"src/{cx.alias}/{p[5]}.c"
    cf.parent.mkdir(parents=True, exist_ok=True)
    cf.write_text(body if body is not None else c_text(cx, p))
    cx.yaml.write_text("".join(lines))
    unstale(cx, old)


def revert(cx, vram, module=None):
    lines = cx.lines()
    old = list(lines)
    for sg in parse(lines):
        if module is not None and sg["name"] != module:
            continue
        if sg["end"] is None or not sg["vram"] <= vram < sg["vram"] + sg["end"] - sg["start"]:
            continue
        rom = sg["start"] + vram - sg["vram"]
        for k, s in enumerate(sg["subs"]):
            ln = lines[s[0]]
            if s[1] != rom or s[2] != "c" or not (ln.rstrip("\n").endswith(MARK) or WAS in ln):
                continue
            nxt = sg["subs"][k + 1] if k + 1 < len(sg["subs"]) else None
            drop = [s[0]]
            if nxt and nxt[2] == "asm" and lines[nxt[0]].rstrip("\n").endswith(MARK):
                drop.append(nxt[0])
            if WAS in ln:
                ind = SUB.match(ln).group(1)
                lines[s[0]] = ind + ln.rstrip("\n").split(WAS, 1)[1] + "\n"
                drop = drop[1:]
            r = next((j for j, x in enumerate(sg["subs"]) if x[2] == ".rodata" and x[3] == s[3]), None)
            if r is not None:  # the owned rodata split (ro_lines), above the c sub in the yaml
                rs, ln = sg["subs"][r], lines[sg["subs"][r][0]]
                nx = sg["subs"][r + 1] if r + 1 < len(sg["subs"]) else None
                pv = sg["subs"][r - 1] if r else None
                if nx and nx[2] in RODATA and lines[nx[0]].rstrip("\n").endswith(MARK):
                    drop.append(nx[0])
                if WAS in ln:
                    lines[rs[0]] = SUB.match(ln).group(1) + ln.rstrip("\n").split(WAS, 1)[1] + "\n"
                else:
                    drop.append(rs[0])
                    nn = next((x for x in sg["subs"][r + 1:] if x[0] not in drop), None)
                    if (pv and pv[2] == "rodatabin" and WAS in lines[pv[0]] and ", textbin" in lines[pv[0]].split(WAS)[1]
                            and not (nn and nn[2] == ".rodata")):  # textbin prefix retyped by this carve
                        lines[pv[0]] = SUB.match(lines[pv[0]]).group(1) + lines[pv[0]].rstrip("\n").split(WAS, 1)[1] + "\n"
            for d in sorted(drop, reverse=True):
                del lines[d]
            cx.yaml.write_text("".join(lines))
            unstale(cx, old)
            (cx.root / f"src/{cx.alias}/{s[3]}.c").unlink(missing_ok=True)
            return s[3]
    raise Refused("no-carve")


# ---- sample: scratch worktree ----
LINKED = ["extracted", "refs", ".venv", "expected", "tools/bin"]  # ignored inputs the build reads
SAMPLE_PER = 50


def git(*a, cwd=ROOT):
    return subprocess.run(["git", *a], cwd=cwd, check=True, capture_output=True, text=True).stdout


def unlink_links(wt):
    for x in LINKED:
        p = wt / x
        if p.is_symlink():
            p.unlink()
        elif p.is_dir():
            for d, dirs, files in os.walk(p):  # does not follow links
                for f in dirs + files:
                    if os.path.islink(os.path.join(d, f)):
                        os.unlink(os.path.join(d, f))


def link(src, dst):
    """Symlink src at dst; where dst is a tracked dir (extracted/, tools/bin), link its missing entries instead."""
    if not dst.exists():
        dst.symlink_to(src)
    elif dst.is_dir() and not dst.is_symlink() and src.is_dir():
        for p in src.iterdir():
            link(p, dst / p.name)


def drop_wt(wt):
    """Remove this caller's own worktree only; prune drops just entries whose dir is gone (siblings safe)."""
    if wt.exists():
        unlink_links(wt)  # never let a recursive delete reach a linked input (G18)
        git("worktree", "remove", "--force", str(wt))
    git("worktree", "prune")


def make_wt(path=None):
    wt = Path(path) if path else ROOT / f".run/carve/wt-{os.getpid()}"  # per process: concurrent runs never share
    drop_wt(wt)
    wt.parent.mkdir(parents=True, exist_ok=True)
    git("worktree", "add", "--detach", str(wt), "HEAD")
    for f in git("ls-files", "-m").split():  # carry the main tree's uncommitted tracked edits (mk/, tools/)
        shutil.copy2(ROOT / f, wt / f)
    for x in LINKED:
        if (ROOT / x).exists():
            link(ROOT / x, wt / x)
    return wt


def inventory_rows():
    import inventory
    with contextlib.redirect_stdout(io.StringIO()):
        rc, rows, *_ = inventory.run(ROOT, inventory.aliases_of(ROOT), None)
    if rc:
        raise SystemExit(f"carve: refused -- inventory exit {rc} (run make check)")
    return rows


def module_of(r):
    m = re.search(r"_(ovl\d+)$", r["name"])
    return m.group(1) if m else None


def sample(per):
    rows = sorted((r for r in inventory_rows() if r["kind"] == "game" and r["status"] == "asm"),
                  key=lambda r: (r["alias"], int(r["vram"], 16), r["module"] or "", r["name"]))
    refused, picks = Counter(), {}
    for alias in sorted({r["alias"] for r in rows}):
        cx = Ctx(ROOT, alias)
        ok = []
        for r in (r for r in rows if r["alias"] == alias):
            try:
                plan(cx, int(r["vram"], 16), module_of(r))
                ok.append(r)
            except Refused as e:
                refused[str(e)] += 1
        k = max(1, len(ok) // per)
        picks[alias] = ok[::k]
    wt = make_wt()
    done, fail = 0, []
    try:
        for alias, sel in picks.items():
            cx = Ctx(wt, alias, asm_root=ROOT)
            n = 0
            for r in sel:
                try:
                    apply(cx, plan(cx, int(r["vram"], 16), module_of(r)))
                    n += 1
                except Refused as e:
                    refused[f"in-sample-{e}"] += 1
            log = ROOT / f".run/carve/{alias}.build.log"
            with open(log, "w") as fh:
                rc = subprocess.run(["make", "split", "build", f"BINARY={alias}", f"PY={sys.executable}"], cwd=wt,
                                    stdout=fh, stderr=subprocess.STDOUT).returncode
            print(f"carve: {alias} {n} carved, build {'SHA green' if rc == 0 else f'FAIL (exit {rc}, {log})'}")
            if rc == 0:
                done += n
            else:
                fail.append(alias)
    finally:
        drop_wt(wt)
    tot = sum(len(v) for v in picks.values())
    print(f"carve: {done} of {tot} carves build")
    for why, c in sorted(refused.items()):
        print(f"carve: refused {why} {c}")
    return 1 if fail or done != tot else 0


def selftest():
    work = ROOT / ".run/carve/selftest"
    shutil.rmtree(work, ignore_errors=True)
    shutil.copytree(FIX, work)
    cx = Ctx(work, "fx")
    before = cx.yaml.read_bytes()
    ok = True
    for vram in (0x80001000, 0x80001010, 0x80001020):  # at a subsegment start, mid, at its end
        p = plan(cx, vram)
        apply(cx, p)
        if not (work / f"src/fx/{p[5]}.c").exists() or cx.yaml.read_bytes() == before:
            ok = False
        split = "- [0xF80, .rodata, func_80001010]  # carve\n      - [0xFC0, rodata, FC0]  # carve\n"
        if (vram == 0x80001010) != (split in cx.yaml.read_text()):  # owned-rodata control: the region split
            print(f"carve: selftest FAIL -- {vram:08X} owned rodata split {'missing' if vram == 0x80001010 else 'stray'}")
            ok = False
        revert(cx, vram)
        if cx.yaml.read_bytes() != before or (work / f"src/fx/{p[5]}.c").exists():
            print(f"carve: selftest FAIL -- {vram:08X} apply+revert not byte-identical")
            ok = False
    apply(cx, plan(cx, 0x80002010))  # jtbl + 4-byte pad: the remainder starts at the pad, not the region end
    jt = "- [0x1104, .rodata, func_80002010]  # carve\n      - [0x110C, rodata, 110C]  # carve\n" in cx.yaml.read_text()
    revert(cx, 0x80002010)
    if not jt or cx.yaml.read_bytes() != before:
        print("carve: selftest FAIL -- 80002010 jtbl span not pad-free or revert not byte-identical")
        ok = False
    else:
        print("carve: control OK -- jtbl span ends pad-free, remainder [0x110C, rodata]")
    for vram, want in ((0x80001030, "jump-table"), (0x80001040, "rodata-shared"), (0x80001050, "outside-asm")):
        try:
            plan(cx, vram)
            print(f"carve: selftest FAIL -- {vram:08X} not refused ({want})")
            ok = False
        except Refused as e:
            if str(e) != want:
                print(f"carve: selftest FAIL -- {vram:08X} refused {e}, want {want}")
                ok = False
    print("carve: control OK -- apply+revert byte-identical, owned rodata split, planted jump table and shared rodata "
          "refused" if ok else "carve: selftest FAIL")
    return 0 if ok else 1


def main(argv):
    if argv[:1] == ["--selftest"]:
        return selftest()
    if argv[:1] == ["own"]:
        for alias in argv[1:2] or ["slus", "rockx5"]:
            ranges, fns = Ctx(ROOT, alias).own()
            n = Counter("unreferenced" if not r[3] else "owned" if len(r[3]) == 1 else "shared" for r in ranges)
            print(f"carve: rodata {alias} owned {n['owned']} shared {n['shared']} unreferenced {n['unreferenced']} "
                  f"ranges; owners {sum(f['ok'] for f in fns.values())} fns")
        return 0
    if argv[:1] == ["sample"]:
        return sample(int(argv[argv.index("--per") + 1]) if "--per" in argv else SAMPLE_PER)
    if len(argv) < 3 or argv[0] not in ("plan", "apply", "revert"):
        print(__doc__)
        return 2
    cmd, alias, vram = argv[0], argv[1], int(argv[2], 16)
    opt = {k: argv[argv.index(k) + 1] for k in ("--name", "--module", "--body") if k in argv}
    cx = Ctx(ROOT, alias)
    try:
        if cmd == "revert":
            print(f"carve: reverted {alias} {revert(cx, vram, opt.get('--module'))}")
            return 0
        p = plan(cx, vram, opt.get("--module"), opt.get("--name"))
        for i, nrep, new in filter(None, (ro_lines(cx, p), cut_lines(cx, p))):
            for j, ln in enumerate(new):
                print(f"carve: {cmd} {cx.yaml.relative_to(ROOT)}:{i + 1 + j} {ln.strip()}")
        if cmd == "apply":
            apply(cx, p, Path(opt["--body"]).read_text() if "--body" in opt else None)
            print(f"carve: wrote src/{alias}/{p[5]}.c")
        return 0
    except Refused as e:
        print(f"carve: refused {e} {alias} {vram:08X}")
        return 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
