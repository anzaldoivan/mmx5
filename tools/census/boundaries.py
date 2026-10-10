#!/usr/bin/env python3
"""Second boundary oracle: function starts/extents from the linked bytes alone, compared with the inventory.

  boundaries.py [--alias A] [--selftest]

Inputs: expected/build/slus/SLUS_013.34 (exe text = loadmap exe t_addr/t_size at file offset 0x800),
expected/build/rockx5/ROCK_X5.BIN (code overlays = loadmap overlays kind code, non-null dest), docs/oracle/loadmap.json,
.run/census/inventory.jsonl (run tools/census/inventory.py first). The only splat-derived input is the code scope per
module: the inventory's text bytes (map .text + segments.txt text ranges) minus its rodata class (yaml non-asm/non-c
subsegments, segments.txt rodata, `dlabel` words), via inventory.run.
Inside that scope the function partition is bytes-only: raw MIPS words decoded here (no spimdisasm/splat/rabbitizer).

Strong starts: jal targets (overlay -> own overlay or exe; exe -> overlay ignored, C0019), code-address words in the
module's non-code bytes (less jump-table entries), lui+addiu/ori code-address pairs; ptr/lui starts only after a
`jr`+delay slot or zero padding and never at a forward branch target; no start (any source, jal too) where the two words
before are plain non-zero code (execution falls into it: a jal into a shared tail). Jump tables: `jr rX` (X != ra) traced back to `lw rX` and its base through
addu/addiu to `lui`; entries = consecutive words valued in the module code scope, capped by the `sltiu` bound; they
are data, their targets extend the owner, never start. Extent: linear walk tracking the furthest forward target; ends at
`jr ra`, tail `j`, unresolved `jr`, backward `b`/`j` (+ delay slot) or `break` before data when nothing is pending;
else `no terminator` at the next strong start. Next sweep start = first non-zero word after the end. SPECIAL words with a
nonzero reserved field or undefined funct (`invalid`) are data: never a start; they end a walk like table words.

Output: prints `boundaries: <n> of <m> functions confirmed` (m = inventory rows), `boundaries: <p> phantoms, <t>
truncations`, per-row `phantom inventory-only|bytes-only <alias> <module> <addr>` / `truncation <alias> <module> <addr>
<why>`; writes .run/census/boundaries.txt (one line per inventory fn + bytes-only rows). Exit 0 green (0 phantoms,
0 truncations), 1 fail, 2 refused input. --selftest: synthetic module of words encoded here (no game bytes).
"""
import argparse
import contextlib
import io
import json
import struct
import sys
from bisect import bisect_right
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import inventory  # noqa: E402
from inventory import ROOT, parse_yaml, excluded  # noqa: E402

EXE = ROOT / "expected/build/slus/SLUS_013.34"
OVL = ROOT / "expected/build/rockx5/ROCK_X5.BIN"
LOADMAP = ROOT / "docs/oracle/loadmap.json"
INV = ROOT / ".run/census/inventory.jsonl"
OUT = ROOT / ".run/census/boundaries.txt"
LUI_WINDOW = 16  # words a lui stays live for an addiu/ori pair


def h(x):
    return x if isinstance(x, int) else int(x, 16)


class Module:
    """name, vram, raw bytes, code ranges [(s, e)] in vram (merged, sorted)."""

    def __init__(self, alias, name, vram, data, code):
        self.alias, self.name, self.vram, self.data = alias, name, vram, data
        self.end = vram + len(data)
        merged = []
        for s, e in sorted(code):
            if merged and s <= merged[-1][1]:
                merged[-1][1] = max(merged[-1][1], e)
            else:
                merged.append([s, e])
        self.code = [(s, e) for s, e in merged]
        self._cs = [s for s, _ in self.code]

    def word(self, a):
        o = a - self.vram
        return struct.unpack_from("<I", self.data, o)[0] if 0 <= o <= len(self.data) - 4 else None

    def in_code(self, a):
        i = bisect_right(self._cs, a) - 1
        return i >= 0 and a < self.code[i][1] and a % 4 == 0


def jtarget(pc, w):
    return ((pc + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)


def branch(pc, w):
    """(target, unconditional) for a PC-relative branch, else None. bal/bltzal/bgezal are calls: None."""
    op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
    t = pc + 4 + (((w & 0xFFFF) ^ 0x8000) - 0x8000) * 4
    if op in (4, 20):  # beq/beql
        return t, rs == rt
    if op in (5, 6, 7, 21, 22, 23):
        return t, False
    if op == 1 and rt in (0, 1, 2, 3):  # bltz/bgez(l); bgez $zero = b
        return t, rt == 1 and rs == 0
    if op in (16, 17, 18) and rs == 8:  # bcNf/t
        return t, False
    return None


# SPECIAL funct -> mask of fields that must be zero (bits 25..6: rs rt rd sa); a set bit = invalid encoding = data.
# Undefined functs are invalid outright. syscall/break carry a free code field.
_RS, _RT, _RD, _SA = 31 << 21, 31 << 16, 31 << 11, 31 << 6
SPECIAL_ZERO = {0: _RS, 2: _RS, 3: _RS, 4: _SA, 6: _SA, 7: _SA, 8: _RT | _RD | _SA, 9: _RT | _SA, 12: 0, 13: 0,
                16: _RS | _RT | _SA, 17: _RT | _RD | _SA, 18: _RS | _RT | _SA, 19: _RT | _RD | _SA,
                **{f: _RD | _SA for f in (24, 25, 26, 27)}, **{f: _SA for f in (32, 33, 34, 35, 36, 37, 38, 39, 42, 43)}}


def invalid(w):
    """SPECIAL word with a nonzero reserved field or undefined funct (psyq stamps, crt0 data tails): never code."""
    return w is not None and not w >> 26 and (w & 63 not in SPECIAL_ZERO or bool(w & SPECIAL_ZERO[w & 63]))


def find_tables(m):
    """{jr_pc: [targets]} and table word set, for jr rX resolved via lw rX, lo(rY) + lui rY, hi."""
    jrs, words, cap = {}, set(), {}
    for s, e in m.code:
        for pc in range(s, e, 4):
            w = m.word(pc)
            if w >> 26 or w & 63 != 8 or (w >> 21) & 31 == 31:
                continue
            x, base = (w >> 21) & 31, None
            for p in range(pc - 4, max(s, pc - 48) - 4, -4):
                v = m.word(p)
                if v >> 26 == 35 and (v >> 16) & 31 == x:
                    # base register traced back through addu (index add) and addiu (%lo) to its lui (%hi)
                    regs, lo = {(v >> 21) & 31}, ((v & 0xFFFF) ^ 0x8000) - 0x8000
                    for q in range(p - 4, max(s, p - 64) - 4, -4):
                        u = m.word(q)
                        uo, ur, ut, ud = u >> 26, (u >> 21) & 31, (u >> 16) & 31, (u >> 11) & 31
                        if uo == 15 and ut in regs:
                            base = (((u & 0xFFFF) << 16) + lo) & 0xFFFFFFFF
                            break
                        if uo == 0 and u & 63 in (32, 33) and ud in regs:
                            regs = (regs - {ud}) | {ur, ut}
                        elif uo == 9 and ut in regs:
                            regs, lo = (regs - {ut}) | {ur}, lo + ((u & 0xFFFF) ^ 0x8000) - 0x8000
                    break
            if base is not None and m.vram <= base < m.end:
                jrs[pc] = base
                # case count from the bounds check `sltiu rZ, rI, N` (else open: consecutive code words)
                n = next((m.word(p) & 0xFFFF for p in range(pc - 4, max(s, pc - 96) - 4, -4)
                          if m.word(p) >> 26 == 11), None)
                cap[base] = max(cap.get(base) or 0, n or 0) or None
    bset = set(cap)
    tabs = {}
    for base in sorted(bset):
        a, ts = base, []
        while (v := m.word(a)) is not None and m.in_code(v) and (a == base or a not in bset) \
                and (cap[base] is None or len(ts) < cap[base]):
            ts.append(v)
            words.add(a)
            a += 4
        tabs[base] = ts
    return {pc: tabs[b] for pc, b in jrs.items()}, words


def boundary(m, t):
    """t can begin a function: code-range start, after a `jr`'s delay slot, or after zero padding. (`j`/`b` are
    excluded: data pointers from same-vram overlays land on if/else joins after them; the sweep covers tails.)"""
    if not m.in_code(t - 4) or not m.in_code(t - 8):
        return True
    w, p = m.word(t - 8), m.word(t - 4)
    return (not w >> 26 and w & 63 == 8) or (p == 0 and w == 0)


def strong_starts(m, exe, words):
    """(own starts, starts into exe) as {addr: source jal|ptr|lui} from jal, data pointers, lui pairs."""
    own, ext = {}, {}
    fwd = {b[0] for s, e in m.code for pc in range(s, e, 4)
           if pc not in words and (b := branch(pc, m.word(pc))) and b[0] > pc}  # forward branch targets: labels

    def flows_in(t):
        # t-8, t-4 plain non-zero code (no branch/jump/jr/jalr/syscall/break, no data): execution falls into t
        for a in (t - 8, t - 4):
            w = m.word(a)
            if not m.in_code(a) or a in words or not w or invalid(w) or branch(a, w) or w >> 26 in (1, 2, 3) \
                    or (not w >> 26 and w & 63 in (8, 9, 12, 13)):
                return False
        return True

    def add(t, src):
        # ptr/lui into mid-function code (labels, same-vram overlays' tables): no start. A forward branch target
        # (ptr/lui) or a fall-through point (any source, incl. jal into a shared tail) is mid-function too.
        if m.in_code(t) and not flows_in(t) and (src == "jal" or t not in fwd):
            if src == "jal" or boundary(m, t):
                own.setdefault(t, src)
        elif exe is not None and exe is not m and exe.in_code(t):
            if src == "jal" or boundary(exe, t):
                ext.setdefault(t, src)

    for s, e in m.code:
        hi = {}
        for pc in range(s, e, 4):
            if pc in words:
                continue
            w = m.word(pc)
            op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
            if op == 3:
                add(jtarget(pc, w), "jal")
            elif op == 15:
                hi[rt] = ((w & 0xFFFF) << 16, pc)
            elif op in (9, 13) and rs in hi and pc - hi[rs][1] <= 4 * LUI_WINDOW:
                lo = w & 0xFFFF
                add((hi[rs][0] + ((lo ^ 0x8000) - 0x8000) if op == 9 else hi[rs][0] | lo) & 0xFFFFFFFF, "lui")
    a = m.vram
    while a + 4 <= m.end:  # non-code bytes: data, rodata, bin
        if not m.in_code(a) and a not in words:
            add(m.word(a), "ptr")
        a += 4
    return own, ext


def partition(m, starts, tables, words):
    """{start: (end, terminated, why)} over the code scope."""
    out = {}
    ss = sorted(t for t in starts if t not in words and m.word(t) and not invalid(m.word(t)))
    for s, e in m.code:
        pc = s
        while pc < e:
            if pc in words or not m.word(pc) or invalid(m.word(pc)):
                pc += 4
                continue
            st = pc
            i = bisect_right(ss, st)
            limit = min(ss[i] if i < len(ss) else e, e)
            maxt, end, why = st, None, None
            while pc < limit:
                w = m.word(pc)
                if pc in words or invalid(w):
                    limit = pc
                    break
                op, rs = w >> 26, (w >> 21) & 31
                stop = False
                # break: no delay slot; ends a fn only when no code follows (crt0 `jal main; nop; break` + data words;
                # a debug stub `break; jr ra` resumes)
                if op == 0 and w & 63 == 13 and maxt < pc + 4 and (pc + 4 in words or invalid(m.word(pc + 4))
                                                                   or not m.in_code(pc + 4)):
                    end = pc + 4
                    break
                if b := branch(pc, w):
                    t, unc = b
                    maxt = max(maxt, t)
                    stop = unc and t <= pc
                elif op == 2:
                    t = jtarget(pc, w)
                    if st <= t < limit and t > pc:
                        maxt = max(maxt, t)
                    else:
                        stop = True  # tail (outside) or backward loop end
                elif op == 0 and w & 63 == 8:
                    for t in tables.get(pc, ()):
                        maxt = max(maxt, t)
                    stop = True
                if stop and maxt < pc + 8:
                    end = pc + 8
                    break
                pc += 4
            if end is None:
                end, why = limit, "no terminator" + (" (target past next start)" if maxt >= limit else "")
            out[st] = (end, why)
            pc = end
    return out


def trim(m, s, e):
    while e - 4 > s and not m.word(e - 4):
        e -= 4
    return e


def compare(m, inv, parts, src):
    """inv: [(vram, insns, name)]. Returns result lines [(kind, addr, why, name)] incl. confirmed."""
    res = []
    inv = sorted(inv)
    spans = [(v, v + 4 * n) for v, n, _ in inv]
    pstarts = sorted(parts)
    for v, n, name in inv:
        ie = trim(m, v, v + 4 * n)
        if v not in parts:
            res.append(("phantom inventory-only", v, "", name))
            continue
        be, why = parts[v]
        be = trim(m, v, be)
        inside = [p for p in pstarts[bisect_right(pstarts, v):] if p < ie][:1]
        if ie < be:
            res.append(("truncation", v, f"ends {ie:08X} before bytes flow end {be:08X}", name))
        elif inside:
            res.append(("truncation", v, f"contains start {inside[0]:08X} ({src.get(inside[0], 'sweep')})", name))
        elif why:
            res.append(("truncation", v, why, name))
        else:
            res.append(("confirmed", v, "", name))
    for p in pstarts:
        if not any(s <= p < e for s, e in spans):
            res.append(("phantom bytes-only", p, "", ""))
    return res


def analyze(mods, exe, inv_by_mod):
    """mods: [Module]; exe: the exe Module or None. Returns {module name: result lines}."""
    tab = {m.name: find_tables(m) for m in mods}
    starts = defaultdict(dict)
    for m in mods:
        own, ext = strong_starts(m, exe, tab[m.name][1])
        starts[m.name].update(own)
        if exe is not None:
            starts[exe.name].update(ext)
    return {m.name: compare(m, inv_by_mod.get(m.name, []), partition(m, starts[m.name], *tab[m.name]),
                            starts[m.name]) for m in mods}


def report(alias_res, out):
    """alias_res: [(alias, module, lines)]. Prints the summary; returns exit code."""
    n = m = ph = tr = 0
    lines = []
    for alias, mod, res in alias_res:
        for kind, a, why, name in res:
            lines.append(f"{kind} {alias} {mod} {a:08X} {name} {why}".rstrip())
            m += kind != "phantom bytes-only"
            n += kind == "confirmed"
            ph += kind.startswith("phantom")
            tr += kind == "truncation"
            if kind != "confirmed":
                print(f"{kind} {alias} {mod} {a:08X}" + (f" {why}" if why else ""))
    print(f"boundaries: {n} of {m} functions confirmed")
    print(f"boundaries: {ph} phantoms, {tr} truncations")
    if out:
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text("".join(x + "\n" for x in lines))
    return 1 if ph or tr else 0


def scope(alias):
    """{segment: [(s, e)] vram code ranges} = inventory text bytes less its rodata class (yaml non-asm/non-c,
    segments.txt rodata, `dlabel` words), taken from inventory.run (the only splat-derived input)."""
    cls = {}
    with contextlib.redirect_stdout(io.StringIO()):
        inventory.run(ROOT, [alias], None, cls)
    segs = parse_yaml(ROOT / f"config/splat.{alias}.yaml")[1]
    if alias not in cls:
        return None, segs, {}
    code, arr = cls[alias]
    out = {}
    for seg, a in arr.items():
        r, b = [], code[seg]["vram"]
        for i in range(0, len(a) - 3, 4):
            if a[i] and a[i] != inventory.RO:
                if r and r[-1][1] == b + i:
                    r[-1][1] += 4
                else:
                    r.append([b + i, b + i + 4])
        out[seg] = [tuple(x) for x in r]
    return out, segs, code


def run(aliases):
    for p in (EXE, OVL, LOADMAP, INV):
        if not p.exists():
            print(f"boundaries: refused -- missing {p.relative_to(ROOT)}")
            return 2
    lm = json.loads(LOADMAP.read_text())
    inv = defaultdict(list)
    for line in INV.read_text().splitlines():
        r = json.loads(line)
        if r["alias"] in aliases:
            mod = "exe" if r["alias"] == "slus" else r["module"].split("/")[1].split("_")[0]
            inv[(r["alias"], mod)].append((int(r["vram"], 16), r["insns"], r["name"]))
    sc, _, scode = scope("slus")
    if sc is None:
        print("boundaries: refused -- missing slus map (run make check)")
        return 2
    t_addr, t_size = h(lm["exe"]["t_addr"]), h(lm["exe"]["t_size"])
    exe = Module("slus", "exe", t_addr, EXE.read_bytes()[0x800:0x800 + t_size], sc[next(iter(scode))])
    mods = {"slus": [exe], "rockx5": []}
    if "rockx5" in aliases:
        osc, segs, ocode = scope("rockx5")
        if osc is None:
            print("boundaries: refused -- missing rockx5 map (run make check)")
            return 2
        skip = {n for n, _ in excluded(ROOT, segs)}
        blob = OVL.read_bytes()
        by_off = {s["start"]: n for n, s in ocode.items()}
        for o in lm["overlays"]:
            n = by_off.get(h(o["bin_offset"]))
            if o.get("kind") != "code" or not o.get("dest") or n is None or n in skip:
                continue
            if h(o["dest"]) != ocode[n]["vram"]:
                print(f"boundaries: refused -- {n} loadmap dest {o['dest']} != yaml vram {ocode[n]['vram']:08X}")
                return 2
            off, size = h(o["bin_offset"]), h(o["size"])
            mods["rockx5"].append(Module("rockx5", n, h(o["dest"]), blob[off:off + size], osc.get(n, [])))
    allm = mods["slus"] + mods["rockx5"]
    res = analyze(allm, exe, {m: v for (a, m), v in inv.items()})
    stray = [k for k in inv if k[1] not in res]
    for a, m in stray:
        print(f"boundaries: {a} {m} inventory rows in no analyzed module")
    out = [(m.alias, m.name, res[m.name]) for m in allm if m.alias in aliases]
    return report(out, OUT) or (1 if stray else 0)


# --- selftest: a synthetic module of words encoded here ---------------------------------------------------------------
def R(rs, rt, rd, fn):
    return (rs << 21) | (rt << 16) | (rd << 11) | fn


def I(op, rs, rt, imm):
    return (op << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def J(op, t):
    return (op << 26) | ((t >> 2) & 0x3FFFFFF)


def build():
    """Returns (bytes, base, code_end, inventory [(vram, insns, name)])."""
    B, SP, RA, V0, AT, A0 = 0x80100000, 29, 31, 2, 1, 4
    JR_RA, NOP = R(RA, 0, 0, 8), 0
    hi = lambda a: ((a + 0x8000) >> 16) & 0xFFFF  # noqa: E731
    code, labels, fix = [], {}, []

    def L(n):
        labels[n] = B + 4 * len(code)

    def emit(*ws):
        code.extend(ws)

    def ref(kind, n, *a):
        fix.append((len(code), kind, n, a))
        code.append(0)

    L("f0"); emit(I(9, SP, SP, -8)); ref("jal", "f1"); emit(NOP); ref("jal", "f2"); emit(NOP)
    ref("hi", "f3", V0); ref("lo", "f3", V0); emit(I(9, SP, SP, 8), R(0, 0, 0, 13), R(1, 0, 0, 0))  # break; data
    L("f1"); ref("beq", "f1x", A0, 0); emit(NOP, I(9, V0, V0, 1)); L("f1x"); emit(JR_RA, NOP)
    L("f2"); emit(I(11, A0, AT, 2)); ref("beq", "f2e", AT, 0); emit(NOP)
    ref("hi", "tbl", AT); emit(R(AT, A0, AT, 33)); ref("lwlo", "tbl", AT, V0); emit(R(V0, 0, 0, 8), NOP)
    L("c0"); emit(I(9, 0, V0, 1)); ref("b", "f2e"); emit(NOP)
    L("c1"); emit(I(9, 0, V0, 2))
    L("f2e"); emit(JR_RA, NOP, NOP)
    L("f3"); emit(I(9, A0, A0, 1)); ref("j", "f1"); emit(NOP)
    L("f4"); emit(I(9, A0, A0, -1)); L("f4l"); emit(I(9, V0, V0, 1)); ref("b", "f4l"); emit(NOP, NOP)
    end = B + 4 * len(code)
    L("tbl"); ref("w", "c0"); ref("w", "c1")
    ref("w", "f4")  # function pointer in data
    for i, kind, n, a in fix:
        t, pc = labels[n], B + 4 * i
        off = ((t - pc - 4) >> 2) & 0xFFFF
        code[i] = {"jal": lambda: J(3, t), "j": lambda: J(2, t), "w": lambda: t,
                   "hi": lambda: I(15, 0, a[0], hi(t)), "lo": lambda: I(9, a[0], a[0], t),
                   "lwlo": lambda: I(35, a[0], a[1] if len(a) > 1 else 0, t),
                   "beq": lambda: I(4, a[0], a[1] if len(a) > 1 else 0, off), "b": lambda: I(4, 0, 0, off)}[kind]()
    inv = [(labels[f], n, f) for f, n in (("f0", 9), ("f1", 5), ("f2", 14), ("f3", 3), ("f4", 5))]
    return struct.pack(f"<{len(code)}I", *code), B, end, inv


def selftest():
    data, base, end, inv = build()
    m = Module("fx", "ovl00", base, data, [(base, end)])
    cases = [("clean twin", inv, 0, (0, 0)),
             ("planted phantom (f4 dropped from inventory)", inv[:4], 1, (1, 0)),
             ("planted truncation (f2 shortened)", [r if r[2] != "f2" else (r[0], 6, "f2") for r in inv], 1, (0, 1))]
    ok = True
    for label, iv, want, (wp, wt) in cases:
        print(f"selftest: {label}")
        res = analyze([m], None, {"ovl00": iv})["ovl00"]
        rc = report([("fx", "ovl00", res)], None)
        p, t = sum(k.startswith("phantom") for k, *_ in res), sum(k == "truncation" for k, *_ in res)
        good = rc == want and (p, t) == (wp, wt) and (want or all(k == "confirmed" for k, *_ in res))
        ok = ok and good
        print(f"selftest: {label}: {'ok' if good else 'WRONG'} (rc {rc}, {p} phantoms, {t} truncations)")
    print(f"selftest: {'pass' if ok else 'FAIL'}")
    if ok:
        print("boundaries: control OK")
    return 0 if ok else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0], epilog=__doc__.split("\n\n", 1)[1],
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--alias", help="only this alias (slus|rockx5); exe text is always analyzed as jal target")
    ap.add_argument("--selftest", action="store_true", help="synthetic clean twin + planted phantom/truncation")
    a = ap.parse_args()
    if a.selftest:
        return selftest()
    al = sorted(p.name.split(".")[1] for p in (ROOT / "config").glob("splat.*.yaml"))
    if a.alias and a.alias not in al:
        print(f"boundaries: refused -- unknown alias {a.alias} (have {' '.join(al)})")
        return 2
    return run([a.alias] if a.alias else al)


if __name__ == "__main__":
    sys.exit(main())
