#!/usr/bin/env python3
"""rockx5.py — rebuild ROCK_X5.BIN (overlay archive) from the linked image, generating the sector-0 TOC.

  pack --map M --elf-bin B --out O [--ref R]   cut ovlNN/padNN from B by the ld map's _ROM_START/_ROM_END,
                                               lay out + write TOC, write O, cmp against R (R '' : no cmp)
  --selftest                                   synthetic blobs, game-free
Layout + TOC: docs/formats.md "ROCK_X5.BIN TOC (inverse)". TOC semantics: tools/loadmap/loadmap.py (`<II`, SECTOR 2048).
"""
import argparse, re, struct, sys
from pathlib import Path

SECTOR = 2048
NOVL = 59  # exe: addiu a2,zero,0x3a -> 0x3a+1 rows
ROM_RE = re.compile(r"^\s*0x([0-9a-fA-F]+)\s+(\w+)_ROM_(START|END) = __romPos\s*$")


def align(n):
    return -(-n // SECTOR) * SECTOR


def layout(blobs, pads=None):
    """blobs: list of bytes; pads: {i: bytes} non-zero gap after blob i (len must equal the rounding remainder).
    Returns (image bytes, toc rows [(sector, size)])."""
    pads = pads or {}
    out, rows = bytearray(SECTOR), []
    for i, b in enumerate(blobs):
        assert len(out) % SECTOR == 0
        rows.append((len(out) // SECTOR, len(b)))
        out += b
        gap = align(len(out)) - len(out)
        p = pads.get(i, bytes(gap))
        assert len(p) == gap, f"pad after blob {i}: {len(p)} != remainder {gap}"
        out += p
    toc = b"".join(struct.pack("<II", *r) for r in rows + [(0, 0)])
    assert len(toc) <= SECTOR
    out[:len(toc)] = toc
    return bytes(out), rows


def cmp(out, ref):
    if out == ref:
        return None
    n = min(len(out), len(ref))
    i = next((k for k in range(n) if out[k] != ref[k]), n)
    msg = f"first diff at 0x{i:x}"
    if len(out) != len(ref):
        msg += f"; size {len(out)} != ref {len(ref)}"
    return msg


def cut(seg, b, shift=False):
    """Cut ovlNN blobs from b by seg's ROM START/END. Default: every gap is the rounding remainder, non-zero ones
    become pads. shift: gaps may be any length (padNN keep retail length while overlays grow) but must be zero;
    they are dropped and layout() relays each overlay. Returns (blobs, pads, gaps); ValueError names a bad gap."""
    names = [f"ovl{i:02d}" for i in range(NOVL)]
    blobs, pads, gaps = [], {}, []
    for i, n in enumerate(names):
        s, e = seg[n]["START"], seg[n]["END"]
        nxt = seg[names[i + 1]]["START"] if i + 1 < NOVL else seg["padend"]["END"]
        pad = 'padend' if i + 1 == NOVL else f'pad{i + 1:02d}'
        g = b[e:nxt]
        if shift:
            if nxt < e or any(g):
                raise ValueError(f"rockx5: shifted gap after {n} ({pad}) is not zero")
        elif s != align(s) or nxt - e != align(e) - e:
            raise ValueError(f"rockx5: gap after {n} is 0x{nxt - e:x}, not the rounding remainder 0x{align(e) - e:x}")
        elif any(g):  # non-zero pad: a named input
            pads[i] = g
            print(f"rockx5: non-zero pad after {n} ({pad})")
        blobs.append(b[s:e])
        gaps.append(nxt - e)
    return blobs, pads, gaps


def pack(a):
    seg = {}
    for line in Path(a.map).read_text().splitlines():
        m = ROM_RE.match(line)
        if m:
            seg.setdefault(m[2], {})[m[3]] = int(m[1], 16)
    shift = not a.ref
    try:
        blobs, pads, gaps = cut(seg, Path(a.elf_bin).read_bytes(), shift)
    except ValueError as x:
        print(x)
        return 1
    img, rows = layout(blobs, pads)
    if not shift and (seg["ovl00"]["START"] != SECTOR or len(img) != seg["padend"]["END"]):
        print(f"rockx5: layout size 0x{len(img):x} != map end 0x{seg['padend']['END']:x}")
        return 1
    Path(a.out).parent.mkdir(parents=True, exist_ok=True)
    Path(a.out).write_bytes(img)
    print(f"rockx5: gaps {len(gaps)}, nonzero {len(gaps) - gaps.count(0)}, max 0x{max(gaps):x}, nonzero pads {len(pads)}")
    if not a.ref:  # --ref '': shifted build (make disc SHIFT=1), bytes differ by design
        back = Path(a.out).read_bytes()
        got = [struct.unpack_from("<II", back, 8 * i) for i in range(NOVL)]
        want = [(r[0], seg[f"ovl{i:02d}"]["END"] - seg[f"ovl{i:02d}"]["START"]) for i, r in enumerate(rows)]
        if got != want or len(back) != align(rows[-1][0] * SECTOR + rows[-1][1]):
            print("rockx5: shifted TOC/size read-back FAIL")
            return 1
        ret = Path(a.retail).read_bytes()  # read-only; retail rows for the report only
        rr = [struct.unpack_from("<II", ret, 8 * i) for i in range(NOVL)]
        print(f"rockx5: relaid {len(back) // SECTOR} sectors (retail {len(ret) // SECTOR}); rows vs retail: "
              f"size differs {sum(g[1] != r[1] for g, r in zip(got, rr))}, sector differs {sum(g[0] != r[0] for g, r in zip(got, rr))}")
        print(f"rockx5: ROCK_X5.BIN {NOVL} overlays, toc generated, cmp skipped")
        return 0
    d = cmp(img, Path(a.ref).read_bytes())
    if d:
        print(f"rockx5: cmp FAIL {d}")
        return 1
    print(f"disc: ROCK_X5.BIN {NOVL} overlays, toc generated, cmp OK")
    return 0


def selftest():
    blobs = [bytes([i + 1]) * n for i, n in enumerate((100, 2048, 3000, 5))]
    img, rows = layout(blobs)
    assert rows == [(1, 100), (2, 2048), (3, 3000), (5, 5)], rows
    assert len(img) == 6 * SECTOR and struct.unpack_from("<II", img, 8 * 4) == (0, 0)
    blobs2 = list(blobs)
    blobs2[1] = blobs[1] + bytes(2048)
    img2, rows2 = layout(blobs2)
    assert rows2[:2] == [(1, 100), (2, 4096)]
    assert all(r2[0] == r[0] + 1 for r, r2 in zip(rows[2:], rows2[2:])), rows2
    assert cmp(img, img) is None and cmp(img, img2) is not None  # planted negative: mismatching ref fails
    assert cmp(img, img[:-1]) is not None
    try:
        layout(blobs, {0: b"\1"})
        raise SystemExit("rockx5: selftest FAIL bad pad accepted")
    except AssertionError:
        pass
    # shifted: ovl00 grew 0x10 -> 0x20, pad01 kept retail length 0x7f0 > remainder 0x7e0; zero -> dropped, relaid
    seg = {f"ovl{i:02d}": {"START": s, "END": e} for i, (s, e) in enumerate([(0x800, 0x820), (0x1010, 0x1110)]
                                                                             + [(0x1110, 0x1110)] * (NOVL - 2))}
    seg["padend"] = {"END": 0x1110}
    sb = bytes(0x800) + b"\1" * 0x20 + bytes(0x7f0) + b"\2" * 0x100
    try:
        cut(seg, sb)
        raise SystemExit("rockx5: selftest FAIL oversized gap accepted unshifted")
    except ValueError:
        pass
    sblobs, spads, _ = cut(seg, sb, shift=True)
    _, srows = layout(sblobs, spads)
    assert srows[:3] == [(1, 0x20), (2, 0x100), (3, 0)], srows[:3]
    bad = bytearray(sb)
    bad[0x900] = 1  # planted non-zero gap byte in pad01
    try:
        cut(seg, bytes(bad), shift=True)
        raise SystemExit("rockx5: selftest FAIL non-zero shifted gap accepted")
    except ValueError as x:
        assert "pad01" in str(x), x
    print("rockx5: control OK")
    return 0


def main():
    if "--selftest" in sys.argv[1:]:
        return selftest()
    ap = argparse.ArgumentParser()
    sp = ap.add_subparsers(dest="cmd", required=True)
    p = sp.add_parser("pack")
    p.add_argument("--map", required=True)
    p.add_argument("--elf-bin", required=True)
    p.add_argument("--out", required=True)
    p.add_argument("--ref", default="extracted/retail/ROCK_X5.BIN")
    p.add_argument("--retail", default="extracted/retail/ROCK_X5.BIN")  # shift report only, read-only
    return pack(ap.parse_args())


if __name__ == "__main__":
    sys.exit(main())
