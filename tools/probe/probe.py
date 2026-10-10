#!/usr/bin/env python3
"""Compiler-ladder probe: compile probe C under each triple, compare masked .text with the target.

  probe.py ladder [--probe NAME] [--triple ID]   one line per probe x triple, then the pin line
  probe.py --selftest                            known-true and off-by-one controls

Pipeline: cpp -> cc1 -> maspsx -> as, scratch under .run/probe/<probe>/<triple>/.
Target bytes come only from expected/build/<alias>/ and are never printed or written (G12).
Exit 0 only when exactly one triple matches every probe (selftest: both controls behave).
"""
import argparse
import re
import struct
import subprocess
import sys
import tomllib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
HERE = ROOT / "tools/probe"
AS = ROOT / "tools/bin/mipsel-linux-gnu-as"
if not AS.exists():  # bootstrap skips the wrapper when a system mipsel as is on PATH
    import shutil
    AS = Path(shutil.which("mipsel-linux-gnu-as") or AS)
MASPSX = ROOT / "refs/maspsx/maspsx.py"
# docs/ops/toolchain.md: cpp flags; -undef for every candidate except gcc-2.95.2-psx
CPP_FLAGS = ["-lang-c", "-D__GNUC__=2", "-Dmips", "-D__mips__", "-Dpsx", "-D__psx__",
             "-D_MIPSEL", "-D__CHAR_UNSIGNED__", "-D__OPTIMIZE__", "-I" + str(ROOT / "include")]
SELFTEST_TRIPLE, SELFTEST_OTHER = "L4-gcc272psx-as256", "L3-gcc2952psx-as286"
R_26, R_HI16, R_LO16, R_GPREL16 = 4, 5, 6, 7


def compile_obj(src, probe, t):
    out = ROOT / ".run/probe" / probe / t["id"]
    out.mkdir(parents=True, exist_ok=True)
    cc1 = ROOT / t["cc1"]
    cpp = [str(cc1.parent / "cpp")] + CPP_FLAGS
    if "gcc-2.95.2-psx" not in t["cc1"]:
        cpp.append("-undef")
    steps = [
        ("cpp", cpp + [str(src), str(out / "probe.i")], None, None),
        ("cc1", [str(cc1)] + t["cflags"] + [str(out / "probe.i"), "-o", str(out / "probe.cc.s")], None, None),
        ("maspsx", [sys.executable, str(MASPSX), f"--aspsx-version={t['aspsx']}"] + t["maspsx_flags"],
         out / "probe.cc.s", out / "probe.s"),
        ("as", [str(AS), "-EL", "-march=r3000", "-no-pad-sections"] + t["asflags"]
         + [str(out / "probe.s"), "-o", str(out / "probe.o")], None, None),
    ]
    for stage, cmd, fin, fout in steps:
        with open(fin or "/dev/null", "rb") as i, open(fout or out / f"{stage}.out", "wb") as o:
            r = subprocess.run(cmd, stdin=i, stdout=o, stderr=open(out / f"{stage}.err", "wb"))
        if r.returncode:
            return None, stage
    return out / "probe.o", None


def read_func(obj, name):
    """(text bytes of `name`, masks per word offset) from an ELF32 LE .o."""
    d = obj.read_bytes()
    shoff, = struct.unpack_from("<I", d, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 0x2E)
    sh = [struct.unpack_from("<IIIIIIIIII", d, shoff + i * shentsize) for i in range(shnum)]
    names = sh[shstrndx][4]
    nm = lambda off, base: d[base + off: d.index(b"\0", base + off)].decode()
    secs = {nm(s[0], names): (i, s) for i, s in enumerate(sh)}
    ti, text = secs[".text"]
    _, symtab = secs[".symtab"]
    strtab = sh[symtab[6]][4]
    for k in range(symtab[5] // 16):
        st_name, value, size, info, other, shndx = struct.unpack_from("<IIIBBH", d, symtab[4] + k * 16)
        if shndx == ti and nm(st_name, strtab) == name:
            break
    else:
        raise KeyError(name)
    masks = {}
    if ".rel.text" in secs:
        rel = secs[".rel.text"][1]
        for k in range(rel[5] // 8):
            off, info = struct.unpack_from("<II", d, rel[4] + k * 8)
            typ = info & 0xFF
            if value <= off < value + size and typ in (R_26, R_HI16, R_LO16, R_GPREL16):
                masks[off - value] = 0x03FFFFFF if typ == R_26 else 0xFFFF
    return d[text[4] + value: text[4] + value + size], masks


def masked(b, masks):
    words = list(struct.unpack_from(f"<{len(b) // 4}I", b))
    for off, m in masks.items():
        if off // 4 < len(words):
            words[off // 4] &= ~m & 0xFFFFFFFF
    return words


def diff_words(ours, target, masks):
    a, b = masked(ours, masks), masked(target, masks)
    return sum(x != y for x, y in zip(a, b)) + abs(len(a) - len(b))


def rockx5_offset(module, vram):
    seg = None
    for line in (ROOT / "config/splat.rockx5.yaml").read_text().splitlines():
        m = re.match(r"  - name: (\S+)$", line)
        if m:
            seg = {"name": m.group(1)}
        elif seg is not None and seg["name"] == module:
            m = re.match(r"    (start|vram): (0x[0-9A-Fa-f]+)$", line)
            if m:
                seg[m.group(1)] = int(m.group(2), 16)
                if "start" in seg and "vram" in seg:
                    return seg["start"] + vram - seg["vram"]
    raise KeyError(f"rockx5 module {module}")


def target_bytes(p):
    if p["alias"] == "slus":
        exe = (ROOT / "expected/build/slus/SLUS_013.34").read_bytes()
        t_addr, = struct.unpack_from("<I", exe, 0x18)
        off = p["vram"] - t_addr + 0x800
    else:
        exe = (ROOT / "expected/build/rockx5/ROCK_X5.BIN").read_bytes()
        off = rockx5_offset(p["module"], p["vram"])
    return exe[off: off + p["size"]]


def run_one(src, name, t, target):
    """'match' | 'diff <n>' | 'error <stage>'"""
    obj, stage = compile_obj(src, name, t)
    if obj is None:
        return f"error {stage}"
    try:
        ours, masks = read_func(obj, name)
    except KeyError:
        return "error symbol"
    n = diff_words(ours, target, masks)
    return "match" if n == 0 else f"diff {n}"


def ladder(args, triples):
    probes = tomllib.loads((HERE / "probes.toml").read_text()).get("probe", [])
    probes = [p for p in probes if args.probe in (None, p["name"])]
    triples = [t for t in triples if args.triple in (None, t["id"])]
    wins = {t["id"]: 0 for t in triples}
    for p in probes:
        tgt = target_bytes(p)
        for t in triples:
            res = run_one(ROOT / p["src"], p["name"], t, tgt)
            print(f"{p['name']} {t['id']} {res}")
            wins[t["id"]] += res == "match"
    full = [tid for tid, w in wins.items() if probes and w == len(probes)]
    best = max(wins.values(), default=0)
    pin = full[0] if len(full) == 1 else "none"
    print(f"pin: {pin} -- {best} of {len(probes)} probes, {len(full)} triple{'s' * (len(full) != 1)}")
    return 0 if len(full) == 1 else 1


def selftest(triples):
    by = {t["id"]: t for t in triples}
    src = HERE / "selftest.c"
    obj, stage = compile_obj(src, "selftest", by[SELFTEST_TRIPLE])
    if obj is None:
        print(f"control known-true {SELFTEST_TRIPLE} error {stage}")
        return 1
    tgt, masks = read_func(obj, "selftest")
    r1 = run_one(src, "selftest", by[SELFTEST_TRIPLE], tgt)
    print(f"control known-true {SELFTEST_TRIPLE} {r1}")
    flip = bytearray(tgt)
    i = next(o for o in range(0, len(flip), 4) if o not in masks)  # first non-relocated word
    flip[i] ^= 1
    r2 = run_one(src, "selftest", by[SELFTEST_TRIPLE], bytes(flip))
    print(f"control off-by-one {SELFTEST_TRIPLE} {r2}")
    print(f"info other-triple {SELFTEST_OTHER} {run_one(src, 'selftest', by[SELFTEST_OTHER], tgt)}")
    return 0 if (r1, r2) == ("match", "diff 1") else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", nargs="?", choices=["ladder"])
    ap.add_argument("--probe")
    ap.add_argument("--triple")
    ap.add_argument("--selftest", action="store_true")
    args = ap.parse_args()
    triples = tomllib.loads((HERE / "ladder.toml").read_text())["triple"]
    if args.selftest:
        return selftest(triples)
    if args.cmd == "ladder":
        return ladder(args, triples)
    ap.print_help()
    return 2


if __name__ == "__main__":
    sys.exit(main())
