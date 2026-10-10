"""Static overlay load map of ROCK_X5.BIN, derived from SLUS_013.34 code and tables.

derive: writes docs/oracle/loadmap.json (addresses only; no game bytes).
check:  evaluates config/loadmap.controls.txt against the json.
"""
import hashlib
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from psexe import HEADER, parse  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
EXE = ROOT / "extracted/retail/SLUS_013.34"
BIN = ROOT / "extracted/retail/ROCK_X5.BIN"
OUT = ROOT / "docs/oracle/loadmap.json"
CONTROLS = ROOT / "config/loadmap.controls.txt"
SECTOR = 2048
JR_RA = 0x03E00008

# Ovl_ReadToc 80015DDC: table addr lui/addiu, loop count `addiu a2,zero,0x3a` + bgez (count = imm+1).
TABLE_LUI, TABLE_ADDIU, COUNT_ADDIU = 0x80015E68, 0x80015E6C, 0x80015E74
# Ovl_Load 80015EB4(a0=index, a1=dest) call sites: (a1 source, index table, extent in bytes).
# 800136EC: a1 = *(lui 800136C4 / lw 800136D0) (variable base), index = 8006FD50[stage*2+sub], 48 bytes.
# 800136B4: a1 = lui/ori 8001369C/800136B8, index = 8006FD80[stage], 19 bytes.
# 80013568: a1 = lui/ori 80013528/8001356C, index = 8006FC5A+stage for stage 2..9 -> 8 bytes at 8006FC5C.
CALLS = (
    ("lw", 0x800136C4, 0x800136D0, 0x8006FD50, 48),
    ("ori", 0x8001369C, 0x800136B8, 0x8006FD80, 19),
    ("ori", 0x80013528, 0x8001356C, 0x8006FC5C, 8),
)


def h8(v):
    return f"{v:08X}"


def derive():
    hdr = parse(EXE)
    exe = EXE.read_bytes()
    t_addr, t_end = hdr["t_addr"], hdr["t_addr"] + hdr["t_size"]

    def off(a):
        assert t_addr <= a < t_end, h8(a)
        return a - t_addr + HEADER

    def word(a):
        return struct.unpack_from("<I", exe, off(a))[0]

    def dec(a):  # -> (op, rs, rt, imm16)
        w = word(a)
        return w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF

    def hi_lo(lui_at, lo_at, lo_op):
        op, _, rt, hi = dec(lui_at)
        assert op == 0x0F, f"{h8(lui_at)}: not lui"
        op2, rs, rt2, lo = dec(lo_at)
        assert op2 == lo_op and rs == rt, f"{h8(lo_at)}: op {op2:#x} rs {rs} vs lui rt {rt}"
        if lo_op == 0x09:  # addiu: sign-extended
            lo = lo - 0x10000 if lo & 0x8000 else lo
        if lo_op == 0x0D:  # ori: needs rt==rs (a1 |= imm)
            assert rt2 == rs
            return (hi << 16) | lo, rt2
        return ((hi << 16) + lo) & 0xFFFFFFFF, rt2

    table, _ = hi_lo(TABLE_LUI, TABLE_ADDIU, 0x09)
    op, rs, rt, imm = dec(COUNT_ADDIU)
    assert (op, rs, rt) == (0x09, 0, 6), f"{h8(COUNT_ADDIU)}: not addiu a2,zero,imm"
    count = imm + 1  # bgez loop runs imm+1 times

    bin_ = BIN.read_bytes()
    rows = [struct.unpack_from("<II", bin_, 8 * i) for i in range(count + 1)]
    assert rows[count] == (0, 0), "TOC terminator row not all-zero"

    dest = {}
    for kind, a_hi, a_lo, tab, ext in CALLS:
        if kind == "lw":
            op, _, rt, hi = dec(a_hi)
            op2, base, rt2, lo = dec(a_lo)
            assert op == 0x0F and op2 == 0x23 and base == rt and rt2 == 5 and lo < 0x8000, h8(a_lo)
            var = (hi << 16) + lo
            val, via = word(var), "*" + h8(var)  # initial value of the variable base
        else:
            val, reg = hi_lo(a_hi, a_lo, 0x0D)
            assert reg == 5, f"{h8(a_lo)}: not a1"
            via = None
        for i in range(ext):
            idx = exe[off(tab + i)]
            if idx < count and idx not in dest:
                dest[idx] = (val, tab + i, via)

    overlays = []
    for i in range(count):
        sec, size = rows[i]
        bo = sec * SECTOR
        blob = bin_[bo:bo + size]
        code = any(w == JR_RA for (w,) in struct.iter_unpack("<I", blob[: len(blob) & ~3]))
        o = {"index": i, "bin_offset": bo, "size": size, "kind": "code" if code else "data",
             "source": h8(table + 8 * i), "dest": None}
        if i in dest:
            val, src, via = dest[i]
            o.update(dest=h8(val), dest_source=h8(src))
            if via:
                o["dest_via"] = via
        overlays.append(o)

    addr_keys = {"pc0", "gp0", "t_addr", "d_addr", "b_addr", "s_addr"}
    doc = {
        "exe": {k: h8(v) if k in addr_keys else v for k, v in hdr.items()},
        "overlays": overlays,
        "table": {"addr": h8(table), "count": count, "terminator": count, "bin_size": len(bin_),
                  "bin_sha1": hashlib.sha1(bin_).hexdigest()},
    }
    OUT.write_text(json.dumps(doc, sort_keys=True, indent=1) + "\n")
    print(f"loadmap: {count} overlays -> {OUT.relative_to(ROOT)}")


def check():
    doc = json.loads(OUT.read_text())
    env = {"__builtins__": {}, "j": doc, "exe": doc["exe"], "ov": doc["overlays"], "table": doc["table"],
           "len": len, "all": all, "any": any, "sum": sum, "sorted": sorted, "set": set, "range": range,
           "list": list, "int": int, "zip": zip}
    # ponytail: restricted eval of our own tracked controls file; not a sandbox for untrusted input.
    ev = lambda e: eval(e, env)  # noqa: E731
    passed = failed = 0
    for n, line in enumerate(CONTROLS.read_text().splitlines(), 1):
        if not line.strip() or line.lstrip().startswith("#"):
            continue
        cid, kind, expr = (s.strip() for s in line.split("|", 2))
        try:
            ok = bool(ev(expr))
        except Exception as e:  # a broken control is a failure, never a silent pass
            print(f"error {cid} (line {n}): {e!r}")
            failed += 1
            continue
        if kind == "positive":
            passed, failed = (passed + 1, failed) if ok else (passed, failed + 1)
            if not ok:
                print(f"FAIL {cid}: {expr}")
        elif kind == "negative":  # planted false statement: caught when it does not hold
            passed, failed = (passed + 1, failed) if not ok else (passed, failed + 1)
            if ok:
                print(f"FAIL {cid}: negative control holds (uncaught): {expr}")
        elif kind == "lead":
            if ok:
                print(f"lead-agrees {cid} {expr}")
            else:
                lhs = expr.rsplit(" == ", 1)[0]
                try:
                    ours = ev(lhs)
                except Exception as e:
                    ours = repr(e)
                print(f"lead-differs {cid} {expr} (ours: {ours})")
        else:
            print(f"error {cid} (line {n}): unknown kind {kind}")
            failed += 1
    print(f"controls: {passed} passed, {failed} failed")
    return 1 if failed else 0


if __name__ == "__main__":
    cmd = sys.argv[1] if len(sys.argv) > 1 else ""
    if cmd == "derive":
        derive()
    elif cmd == "check":
        sys.exit(check())
    else:
        sys.exit("usage: loadmap.py derive|check")
