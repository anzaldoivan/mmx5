#!/usr/bin/env python3
"""Plateau classifier: name the residual a stalled permuter run left, and the label that routes it.

  plateau.py classify <draft.c> --fn <sym> [--iters N] [--expect-class C] [--no-permute]
  plateau.py --selftest     ROM-free: planted u16->s16 plateau, and a target-vs-itself control

classify: runs `permute.py run` (N iterations, default 100) unless --no-permute, takes its lowest-score
output-*/source.c (else the draft), compiles it at the pin (tools/dedup/reconcile.py triple()), masks both streams
with our object's relocs, decodes them with rabbitizer, aligns them (difflib on opcode+operand text), emits one
class of docs/codegen-map/README.md ## Residual classes and one plateau label:
  plateau: <fn> class <class> label <missing-transform|mis-classified|seed-structural|wall|none>
Target bytes come from expected/build/slus/ (permute.fn_span), are never printed or written (G12).
Not a gate: the byte gate decides a match (G61).
"""
import argparse
import collections
import difflib
import re
import subprocess
import sys
from pathlib import Path

import rabbitizer

ROOT = Path(__file__).resolve().parents[2]
HERE = ROOT / "tools/permuter"
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT / "tools/dedup"))
import permute  # noqa: E402
import probe  # noqa: E402  (permute puts tools/probe on sys.path)
from reconcile import triple  # noqa: E402

STRUCTURAL = {"WIDTH", "BRANCH-POLARITY", "ADDRESSING", "STRENGTH", "IMM-OFFSET", "SHIFT-DRIFT",
              "SIZE-MISMATCH"}
PERMUTER = {"REGALLOC-PERM", "REGALLOC-LOCAL", "SCHEDULE-REORDER", "DELAY-SLOT", "IMM-VALUE"}
WALL = {"MIXED", "OPCODE-MIXED", "UNKNOWN", "EMPTY"}

# Width/signedness family (checked before LENGTH-DRIFT: u8 vs s8 turns `andi 0xff` into `sll 24; sra 24`).
# Tokens are the mnemonic, plus the immediate for the masking/extension shifts; `move` rides along with one.
WIDTH_TOK = {"lb", "lbu", "lh", "lhu", "lw", "sb", "sh", "sw", "slt", "sltu", "slti", "sltiu",
             "div", "divu", "mult", "multu", "srl", "sra", "srlv", "srav",
             "andi 0xFF", "andi 0xFFFF", "sll 24", "sll 16", "sra 24", "sra 16", "srl 24", "srl 16"}
FAMILY = {
    "width": {"lb", "lbu", "lh", "lhu", "lw", "lwl", "lwr", "sb", "sh", "sw", "swl", "swr",
              "slt", "sltu", "slti", "sltiu", "div", "divu", "srl", "sra"},
    "branch": {"beq", "bne", "blez", "bgtz", "bltz", "bgez", "bltzal", "bgezal", "b", "beqz", "bnez"},
    "strength": {"mult", "multu", "div", "divu", "mfhi", "mflo", "sll", "srl", "sra", "sllv", "srlv", "srav"},
    "addressing": {"addu", "addiu", "add", "addi", "subu", "sub", "lui", "ori"},
}
REG = re.compile(r"\$\w+")


def insn(w):
    """(mnemonic, regs, imms, text) of one masked word; mnemonic None when rabbitizer does not cover it."""
    i = rabbitizer.Instruction(w)
    if not i.isValid():
        return None, (), (), f"?{w:08X}"
    text = " ".join(i.disassemble().split())
    m, _, ops = text.partition(" ")
    return m, tuple(REG.findall(ops)), tuple(re.findall(r"-?0x[0-9A-Fa-f]+|-?\b\d+\b", REG.sub("", ops))), text


def width_tok(d):
    m, regs, imms, _ = d
    if m == "addu" and regs[-1:] == ("$zero",):
        return "move"  # the copy an extension replaces (`andi 0xFF` vs `move`); never a width hunk alone
    if m in ("andi", "sll", "sra", "srl") and imms:
        t = f"{m} {imms[-1]}"
        return t if t in WIDTH_TOK else m if m in WIDTH_TOK else None
    return m if m in WIDTH_TOK else None


def is_width(dm, dt, ops):
    """Every hunk whose opcode multiset differs differs only in width-family tokens, and there is one."""
    seen = False
    for tag, a0, a1, b0, b1 in ops:
        if tag == "equal":
            continue
        ca = collections.Counter(d[0] for d in dm[a0:a1])
        cb = collections.Counter(d[0] for d in dt[b0:b1])
        if ca == cb:
            continue  # register/immediate-only noise inside the hunk
        diff = ((ca - cb) + (cb - ca)).keys()
        toks = [width_tok(d) for d in dm[a0:a1] + dt[b0:b1] if d[0] in diff]
        if None in toks or all(t == "move" for t in toks):
            return False
        seen = True
    return seen


def family(a, b):
    for f, s in FAMILY.items():
        if a in s and b in s:
            return f
    return None


def reg_map(pairs):
    m, inv = {}, {}
    for ra, rb in pairs:
        if len(ra) != len(rb):
            return None
        for x, y in zip(ra, rb):
            if m.setdefault(x, y) != y or inv.setdefault(y, x) != x:
                return None
    return m


def classify_words(mine, tgt):
    nm, nt = len(mine), len(tgt)
    if mine == tgt:
        return "MATCH"
    if not nm or not nt:
        return "EMPTY"
    dm, dt = [insn(w) for w in mine], [insn(w) for w in tgt]
    if any(d[0] is None for d in dm + dt):
        return "UNKNOWN"
    ops = difflib.SequenceMatcher(None, [d[3] for d in dm], [d[3] for d in dt], autojunk=False).get_opcodes()
    if is_width(dm, dt, ops):
        return "WIDTH"
    hunks = [o for o in ops if o[0] != "equal"]
    d = nm - nt
    if d:
        if len(hunks) == 1 and hunks[0][0] in ("insert", "delete"):
            return "LENGTH-DRIFT"  # one shift point explains the tail
        return "SIZE-MISMATCH" if abs(d) > max(2, 0.15 * nt) or abs(d) >= 0.5 * nt else "LENGTH-DRIFT"
    diffs = [i for i in range(nm) if mine[i] != tgt[i]]
    if len(diffs) > 8 and sorted(h[0] for h in hunks) == ["delete", "insert"]:
        return "SHIFT-DRIFT"  # an insert+delete pair realigns the middle
    kinds, regs, imms, opp = [], [], [], []
    for i in diffs:
        a, b = dm[i], dt[i]
        if a[0] != b[0]:
            kinds.append("op")
            opp.append((a[0], b[0]))
            continue
        dr, di = a[1] != b[1], a[2] != b[2]
        kinds.append("reg" if dr and not di else "imm" if di and not dr else "mixed")
        if dr:
            regs.append((a[1], b[1]))
        if di:
            imms.append((a[2], b[2]))
    only = lambda *ks: all(k in ks for k in kinds)  # noqa: E731
    if only("reg") and reg_map(regs) is not None:
        return "REGALLOC-PERM"
    if collections.Counter(mine[i] for i in diffs) == collections.Counter(tgt[i] for i in diffs):
        return "SCHEDULE-REORDER"
    nops = sum((mine[i] == 0) != (tgt[i] == 0) for i in diffs)
    if nops and nops >= len(diffs) / 2:
        return "DELAY-SLOT"
    if only("reg"):
        return "REGALLOC-LOCAL"
    if opp:
        fams = {family(a, b) for a, b in opp}
        if len(fams) == 1 and None not in fams:
            return {"width": "WIDTH", "branch": "BRANCH-POLARITY", "strength": "STRENGTH",
                    "addressing": "ADDRESSING"}[fams.pop()]
        return "OPCODE-MIXED"
    if only("imm") and imms:
        try:
            deltas = {int(y, 0) - int(x, 0) for a, b in imms for x, y in zip(a, b, strict=True) if x != y}
        except ValueError:
            deltas = {None, 0}
        return "IMM-OFFSET" if len(deltas) == 1 else "IMM-VALUE"
    return "MIXED"


def label(klass, nm, nt, expect=None, outcome=None):
    """outcome = (base, best) of the permuter run, None when it did not run."""
    if klass == "MATCH":
        return "none"
    if expect and expect.upper() != klass:
        return "mis-classified"
    if klass == "LENGTH-DRIFT":
        klass = "SIZE-MISMATCH" if abs(nm - nt) > 2 else "IMM-VALUE"  # big drift structural, small permuter
    if klass in WALL:
        return "wall"
    if klass in STRUCTURAL:
        return "seed-structural"
    base, best = outcome or (0, 1)
    return "missing-transform" if best == base or best > 0 else "wall"


def words(src, fn, target):
    """Masked (ours, target) word streams; our object's relocs mask both (target has none)."""
    obj, stage = probe.compile_obj(src, "plateau-" + fn, triple())
    if obj is None:
        raise SystemExit(f"plateau: {fn} compile failed at {stage} ({src})")
    ours, masks = probe.read_func(obj, fn)
    if len(target) > len(ours) and not any(target[len(ours):]):
        target = target[:len(ours)]  # the carved span runs to the next subsegment: zero alignment padding
    return probe.masked(ours, masks), probe.masked(target, masks)


def classify(draft, fn, iters, expect, no_permute):
    src, outcome = Path(draft).resolve(), None
    if not no_permute:
        r = subprocess.run([sys.executable, str(HERE / "permute.py"), "run", str(src), "--fn", fn,
                            "--iters", str(iters)], capture_output=True, text=True)
        m = re.search(r"base (\d+) best (\d+)", r.stdout)
        if m:
            outcome = int(m.group(1)), int(m.group(2))
        outs = sorted(ROOT.glob(f".run/permuter/{fn}/output-*/source.c"),
                      key=lambda q: (int(q.parent.name.split("-")[1]), q.parent.name))
        if outs:
            src = outs[0]
    vram, size = permute.fn_span(fn)
    mine, tgt = words(src, fn, probe.target_bytes({"alias": "slus", "vram": vram, "size": size}))
    k = classify_words(mine, tgt)
    print(f"plateau: {fn} class {k.lower()} label {label(k, len(mine), len(tgt), expect, outcome)}")
    return 0


def selftest():
    fix = HERE / "fixtures/width.c"
    tdir = ROOT / ".run/plateau/selftest"
    tdir.mkdir(parents=True, exist_ok=True)
    tgt_c = tdir / "target.c"
    tgt_c.write_text(fix.read_text().replace("s16 *p", "u16 *p"))
    obj, stage = probe.compile_obj(tgt_c, "plateau-selftest-target", triple())
    if obj is None:
        print(f"plateau: control FAILED -- target compile {stage}")
        return 1
    tbytes = probe.read_func(obj, "fixture_fn")[0]
    plant = classify_words(*words(fix, "fixture_fn", tbytes))
    ctrl = classify_words(*words(tgt_c, "fixture_fn", tbytes))
    pl, cl = label(plant, 1, 1), label(ctrl, 1, 1)
    if plant == "WIDTH" and pl == "seed-structural" and ctrl == "MATCH" and cl == "none":
        print("plateau: control OK -- planted plateau labelled seed-structural")
        return 0
    print(f"plateau: control FAILED -- plant {plant}/{pl}, control {ctrl}/{cl}")
    return 1


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--selftest", action="store_true")
    sub = ap.add_subparsers(dest="cmd")
    c = sub.add_parser("classify")
    c.add_argument("draft")
    c.add_argument("--fn", required=True)
    c.add_argument("--iters", type=int, default=100)
    c.add_argument("--expect-class")
    c.add_argument("--no-permute", action="store_true")
    a = ap.parse_args()
    if a.selftest:
        return selftest()
    if a.cmd == "classify":
        return classify(a.draft, a.fn, a.iters, a.expect_class, a.no_permute)
    ap.print_help()
    return 2


if __name__ == "__main__":
    sys.exit(main())
