#!/usr/bin/env python3
"""Extract a PS1 MODE2/2352 CUE/BIN to <out>/<disc path> and write <out>/manifest.jsonl.

Payload convention (docs/formats.md): a file whose sectors are all Form 1 is written as 2048 user
bytes/sector truncated to its ISO size; a file with any Form 2 sector is written as 2336 bytes/sector
(raw 16..2352: subheader + data), sectors = ceil(size/2048). Stdlib only, deterministic.
"""
import argparse
import glob
import hashlib
import json
import os
import re
import sys

RAW = 2352
USER = 2048
XA = 2336
CHUNK = 256  # sectors per streamed read


def parse_cue(cue):
    text = open(cue, encoding="utf-8", errors="replace").read()
    files = re.findall(r'^\s*FILE\s+"([^"]+)"\s+BINARY', text, re.M)
    tracks = re.findall(r"^\s*TRACK\s+\d+\s+(\S+)", text, re.M)
    if len(files) != 1 or tracks != ["MODE2/2352"]:
        sys.exit(f"extract: {cue}: want one FILE and one MODE2/2352 track, got {files} {tracks}")
    return os.path.join(os.path.dirname(cue), files[0])


class Disc:
    def __init__(self, path):
        self.f = open(path, "rb")
        self.size = os.path.getsize(path)
        if self.size % RAW:
            sys.exit(f"extract: bin size {self.size} not a multiple of {RAW}")
        self.total = self.size // RAW

    def raw(self, lba, n=1):
        self.f.seek(lba * RAW)
        data = self.f.read(n * RAW)
        if len(data) != n * RAW:
            sys.exit(f"extract: short read at LBA {lba}+{n}")
        return data

    def user(self, lba, n=1):  # Form 1 user data
        r = self.raw(lba, n)
        return b"".join(r[i * RAW + 24 : i * RAW + 24 + USER] for i in range(n))

    def chunks(self, lba, n):
        for s in range(lba, lba + n, CHUNK):
            k = min(CHUNK, lba + n - s)
            yield self.raw(s, k), k


def form2(raw, i):
    return bool(raw[i * RAW + 18] & 0x20)  # subheader submode bit 5


def u32(b, o):
    return int.from_bytes(b[o : o + 4], "little")


def walk(disc, lba, size, prefix):
    """Yield (path, lba, size, is_dir) for every record below a directory extent."""
    data = disc.user(lba, -(-size // USER))[:size]
    o = 0
    while o < len(data):
        n = data[o]
        if n == 0:  # records never cross a sector boundary
            o = (o // USER + 1) * USER
            continue
        rec = data[o : o + n]
        o += n
        name = rec[33 : 33 + rec[32]]
        if name in (b"\x00", b"\x01"):
            continue
        name = name.decode("ascii").split(";")[0]
        path = f"{prefix}{name}"
        elba, esize, isdir = u32(rec, 2), u32(rec, 10), bool(rec[25] & 2)
        yield path, elba, esize, isdir
        if isdir:
            yield from walk(disc, elba, esize, path + "/")


def record(kind, path, lba, sectors, size, mode, h, nonzero):
    r = {"kind": kind, "path": path, "lba": lba, "sectors": sectors, "size": size, "mode": mode}
    if nonzero:
        r["sha1"] = h
    else:
        r["content_sha1"], r["trivial"] = h, True
    return r


def mode_of(disc, lba, sectors):
    forms = set()
    for raw, k in disc.chunks(lba, sectors):
        forms.update(form2(raw, i) for i in range(k))
    if forms == {True}:
        return "form2"
    return "mixed" if len(forms) == 2 else "form1"


def extract_file(disc, kind, path, lba, size, dest):
    sectors = -(-size // USER)
    mode = mode_of(disc, lba, sectors)
    h, nonzero, left = hashlib.sha1(), False, size
    out = open(dest, "wb") if dest else None
    for raw, k in disc.chunks(lba, sectors):
        if mode == "form1":
            buf = b"".join(raw[i * RAW + 24 : i * RAW + 24 + USER] for i in range(k))[:left]
            left -= len(buf)
        else:
            buf = b"".join(raw[i * RAW + 16 : (i + 1) * RAW] for i in range(k))
        h.update(buf)
        nonzero = nonzero or buf.count(0) != len(buf)
        if out:
            out.write(buf)
    if out:
        out.close()
    return record(kind, path, lba, sectors, size, mode, h.hexdigest(), nonzero)


def system_record(disc, path, lba, sectors):
    h, nonzero, forms = hashlib.sha1(), False, set()
    for raw, k in disc.chunks(lba, sectors):
        h.update(raw)
        nonzero = nonzero or raw.count(0) != len(raw)
        forms.update(form2(raw, i) for i in range(k))
    mode = "mixed" if len(forms) == 2 else ("form2" if forms == {True} else "form1")
    return record("system", path, lba, sectors, sectors * RAW, mode, h.hexdigest(), nonzero)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--cue")
    ap.add_argument("--out", required=True)
    a = ap.parse_args(argv)
    cue = a.cue
    if not cue:
        cues = sorted(glob.glob("disks/*.cue"))
        if len(cues) != 1:
            sys.exit(f"extract: want exactly one disks/*.cue, found {len(cues)}; pass --cue")
        cue = cues[0]
    disc = Disc(parse_cue(cue))
    os.makedirs(a.out, exist_ok=True)

    pvd = disc.user(16)
    if pvd[:6] != b"\x01CD001":
        sys.exit("extract: no ISO9660 PVD at LBA 16")
    recs = [system_record(disc, "@system/area", 0, 16)]
    vd = 16
    while disc.user(vd)[0] != 255:
        vd += 1
    recs.append(system_record(disc, "@system/descriptors", 16, vd - 15))
    pt_sectors = -(-u32(pvd, 132) // USER)
    for name, off, endian in (("l", 140, "little"), ("l2", 144, "little"), ("m", 148, "big"), ("m2", 152, "big")):
        lba = int.from_bytes(pvd[off : off + 4], endian)
        if lba:
            recs.append(system_record(disc, f"@system/pathtable_{name}", lba, pt_sectors))

    root = pvd[156:190]
    rlba, rsize = u32(root, 2), u32(root, 10)
    entries = [("/", rlba, rsize, True)] + list(walk(disc, rlba, rsize, ""))
    for path, lba, size, isdir in entries:
        if isdir:
            if path != "/":
                os.makedirs(os.path.join(a.out, path), exist_ok=True)
            recs.append(extract_file(disc, "dir", path, lba, size, None))
        else:
            recs.append(extract_file(disc, "file", path, lba, size, os.path.join(a.out, path)))
    recs.sort(key=lambda r: (r["lba"], r["path"]))

    covered = set()
    for r in recs:
        covered.update(range(r["lba"], r["lba"] + r["sectors"]))
    covered &= set(range(disc.total))
    gaps, start = [], None
    for s in range(disc.total + 1):
        if s < disc.total and s not in covered:
            start = s if start is None else start
        elif start is not None:
            gaps.append((start, s - 1))
            start = None
    with open(os.path.join(a.out, "manifest.jsonl"), "w", newline="\n") as m:
        for r in recs:
            m.write(json.dumps(r, sort_keys=True) + "\n")
        cov = {"kind": "coverage", "sectors_total": disc.total, "sectors_accounted": len(covered)}
        m.write(json.dumps(cov, sort_keys=True) + "\n")
    kinds = {}
    for r in recs:
        kinds[r["kind"]] = kinds.get(r["kind"], 0) + 1
    print(f"extract: {cue} -> {a.out}: {json.dumps(kinds, sort_keys=True)} {json.dumps(cov, sort_keys=True)}")
    for g0, g1 in gaps:
        print(f"extract: gap LBA {g0}-{g1} ({g1 - g0 + 1} sectors)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
