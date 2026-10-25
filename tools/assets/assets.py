#!/usr/bin/env python3
"""ROCK_X5.DAT asset tool. Layout: docs/formats.md `## ROCK_X5.DAT (inverse)`.

survey: parse the sector-0 TOC and the pack form, print one line per top-level
member (`idx sector size kind`), then a level-1 and a level-2 census, then
the entry-type census (class = type >> 16, kind = type & 0xFFFF).
Prints offsets, sizes and counts only (no game bytes).

export/import/roundtrip: container class. Raw members and pack entries become
`.bin` files plus dat/index.json; import rebuilds headers, TOC and padding
from index.json. apply <name>: copy the export tree, apply asset-edits/<name>/edit.json
(op `fill`: offset, length, byte) to one entry, size unchanged. --selftest: synthetic DAT from fixtures/synth.json.
"""
import argparse
import hashlib
import json
import os
import random
import shutil
import struct
import sys

SECTOR = 2048


def align(n):
    return (n + SECTOR - 1) // SECTOR * SECTOR


def toc(dat):
    """Rows `<II (start_sector, size_bytes)` from sector 0 until (0,0)."""
    rows = []
    for off in range(0, SECTOR, 8):
        start, size = struct.unpack_from("<II", dat, off)
        if (start, size) == (0, 0):
            break
        rows.append((start, size))
    return rows


def pack_entries(m):
    """Entry slices if `m` is a valid pack, else None."""
    if len(m) < 8:
        return None
    n, total = struct.unpack_from("<II", m, 0)
    if not (0 < n and 8 + 8 * n <= SECTOR and total == len(m)):
        return None
    sizes = [struct.unpack_from("<II", m, 8 + 8 * k)[1] for k in range(n)]
    if SECTOR + sum(align(s) for s in sizes) != total:
        return None
    out, off = [], SECTOR
    for s in sizes:
        out.append(m[off:off + s])
        off += align(s)
    return out


def classify(m):
    """Order: zero, pack, tim, raw."""
    if not any(m):
        return "zero"
    if pack_entries(m) is not None:
        return "pack"
    if len(m) >= 8:
        ident, flags = struct.unpack_from("<II", m, 0)
        if ident == 0x10 and flags & ~0xB == 0:
            return "tim"
    return "raw"


def counts(kinds):
    return {k: kinds.count(k) for k in ("pack", "tim", "raw", "zero")}


def types(m, n):
    return [struct.unpack_from("<I", m, 8 + 8 * k)[0] for k in range(n)]


def census(tys):
    """{class: {kind: n}} over entry type words (class = type >> 16, kind = type & 0xFFFF)."""
    out = {}
    for t in tys:
        d = out.setdefault(t >> 16, {})
        d[t & 0xFFFF] = d.get(t & 0xFFFF, 0) + 1
    return out


def survey(path):
    with open(path, "rb") as f:
        dat = f.read()
    l1, l2, tys = [], [], []
    for i, (start, size) in enumerate(toc(dat)):
        m = dat[start * SECTOR:start * SECTOR + size]
        kind = classify(m)
        l1.append(kind)
        print(f"{i} {start} {size} {kind}")
        if kind == "pack":
            ents = pack_entries(m)
            l2 += [classify(e) for e in ents]
            tys += types(m, len(ents))
    c = counts(l1)
    line = f"survey: {len(l1)} members, {c['pack']} pack, {c['tim']} tim, {c['raw']} raw"
    print(line + (f", {c['zero']} zero" if c["zero"] else ""))
    c = counts(l2)
    print(f"survey: level 2: {len(l2)} entries, {c['pack']} pack, {c['tim']} tim, "
          f"{c['raw']} raw, {c['zero']} zero")
    cen = census(tys)
    cls = sorted(set(cen) | {0, 1, 2})
    print("survey: classes " + " ".join(f"{c}:{sum(cen.get(c, {}).values())}" for c in cls))
    for c in cls:
        print(f"survey: class {c} kinds " + " ".join(f"0x{k:04x}:{n}" for k, n in sorted(cen.get(c, {}).items())))


def sha1(b):
    return hashlib.sha1(b).hexdigest()


def read(path):
    with open(path, "rb") as f:
        return f.read()


def write(path, b):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "wb") as f:
        f.write(b)


def items(dat):
    """(name, bytes) per raw member (`iii`) or pack entry (`iii/sss`)."""
    out = []
    for i, (start, size) in enumerate(toc(dat)):
        m = dat[start * SECTOR:start * SECTOR + size]
        ents = pack_entries(m)
        if ents is None:
            out.append((f"{i:03d}", m))
        else:
            out += [(f"{i:03d}/{k:03d}", e) for k, e in enumerate(ents)]
    return out


def export(src, out):
    dat = read(os.path.join(src, "ROCK_X5.DAT"))
    shutil.rmtree(os.path.join(out, "dat"), ignore_errors=True)
    rows, man = [], []
    for i, (start, size) in enumerate(toc(dat)):
        m = dat[start * SECTOR:start * SECTOR + size]
        row = {"idx": i, "sector": start, "size": size, "kind": classify(m), "sha1": sha1(m)}
        ents = pack_entries(m)
        if ents is None:
            files = [(f"dat/{i:03d}.bin", m)]
        else:
            row["entries"] = [{"sub": k, "type": t, "kind": t & 0xFFFF, "class": t >> 16,
                               "size": len(e), "sha1": sha1(e)}
                              for k, (t, e) in enumerate(zip(types(m, len(ents)), ents))]
            files = [(f"dat/{i:03d}/{k:03d}.bin", e) for k, e in enumerate(ents)]
        for path, b in files:
            write(os.path.join(out, path), b)
            man.append({"path": path, "sha1": sha1(b), "class": "container"})
        rows.append(row)
    with open(os.path.join(out, "dat", "index.json"), "w") as f:
        json.dump({"toc": rows}, f, indent=1)
    with open(os.path.join(out, "manifest.jsonl"), "w") as f:
        f.writelines(json.dumps(r) + "\n" for r in sorted(man, key=lambda r: r["path"]))
    print(f"assets: exported {len(man)} files (container)")


def load(src, path, size):
    b = read(os.path.join(src, path))
    if len(b) != size:
        print(f"assets: {path} size changed, relayout not proven")
        sys.exit(1)
    return b


def pad(b):
    return b + bytes(align(len(b)) - len(b))


def import_(src, out):
    with open(os.path.join(src, "dat", "index.json")) as f:
        rows = json.load(f)["toc"]
    members = []
    for r in rows:
        if "entries" not in r:
            members.append(load(src, f"dat/{r['idx']:03d}.bin", r["size"]))
            continue
        es = r["entries"]
        body = [load(src, f"dat/{r['idx']:03d}/{e['sub']:03d}.bin", e["size"]) for e in es]
        head = struct.pack("<II", len(es), SECTOR + sum(align(e["size"]) for e in es))
        head += b"".join(struct.pack("<II", e["type"], e["size"]) for e in es)
        members.append(pad(head) + b"".join(pad(b) for b in body))  # total = 2048 + sum(align)
    sector, tab = 1, b""
    for m in members:
        tab += struct.pack("<II", sector, len(m))
        sector += align(len(m)) // SECTOR
    dat = pad(tab + bytes(8)) + b"".join(pad(m) for m in members)
    write(os.path.join(out, "ROCK_X5.DAT"), dat)
    print(f"assets: imported ROCK_X5.DAT {len(members)} members")


def apply(name, src, out):
    """Copy src to out, apply asset-edits/<name>/edit.json to one entry; import checks sizes only, not sha1."""
    with open(os.path.join("asset-edits", name, "edit.json")) as f:
        e = json.load(f)
    assert e["op"] == "fill", e["op"]  # ponytail: one op; add others when a recipe needs them
    shutil.rmtree(out, ignore_errors=True)
    shutil.copytree(src, out)
    p = os.path.join(out, "dat", e["entry"] + ".bin")
    b = bytearray(read(p))
    n = len(b)
    assert e["offset"] + e["length"] <= n, (e, n)
    b[e["offset"]:e["offset"] + e["length"]] = bytes([e["byte"]]) * e["length"]
    assert len(b) == n
    write(p, bytes(b))
    print(f"assets: applied {name} to {e['entry']} ({e['length']} of {n} B, size unchanged)")


def compare(ref, new):
    """First differing item name, or None; prints the container count line."""
    a, b = items(ref), items(new)
    same = sum(x == y for x, y in zip(a, b))
    diff = [x[0] for x, y in zip(a, b) if x != y] or ([] if len(a) == len(b) else ["item count"])
    print(f"assets: container {same} of {len(a)} identical, {len(a) - same} differences")
    return diff[0] if diff else None


def roundtrip(src, work, plant=None):
    shutil.rmtree(work, ignore_errors=True)
    export(src, os.path.join(work, "x"))
    if plant:
        p = os.path.join(work, "x", plant)
        b = bytearray(read(p))
        b[0] ^= 1
        write(p, bytes(b))
    import_(os.path.join(work, "x"), os.path.join(work, "out"))
    ref = read(os.path.join(src, "ROCK_X5.DAT"))
    new = read(os.path.join(work, "out", "ROCK_X5.DAT"))
    bad = compare(ref, new) or (None if sha1(ref) == sha1(new) else "whole DAT sha1")
    if bad:
        print(f"assets: roundtrip FAIL first difference {bad}")
        return bad
    print("assets: roundtrip OK (1 class)")


def selftest():
    """Synthetic DAT built here (independent of import_), round-tripped, then a planted byte."""
    with open(os.path.join(os.path.dirname(__file__), "fixtures", "synth.json")) as f:
        spec = json.load(f)["members"]
    gen = lambda s, n: bytes(n) if s is None else random.Random(s).randbytes(n)
    ms = []
    for m in spec:
        if "raw" in m:
            ms.append(gen(m["raw"]["seed"], m["raw"]["size"]))
            continue
        es = m["pack"]
        hdr = struct.pack("<II", len(es), SECTOR + sum(align(e["size"]) for e in es))
        hdr += b"".join(struct.pack("<II", e["type"], e["size"]) for e in es)
        blob = hdr.ljust(SECTOR, b"\0")
        for e in es:
            blob = blob.ljust(align(len(blob)), b"\0") + gen(e["seed"], e["size"])
        ms.append(blob.ljust(align(len(blob)), b"\0"))
    dat, tab = b"", b""
    for m in ms:
        tab += struct.pack("<II", 1 + len(dat) // SECTOR, len(m))
        dat += m.ljust(align(len(m)), b"\0")
    work = ".run/assets-selftest"
    write(f"{work}/src/ROCK_X5.DAT", tab.ljust(SECTOR, b"\0") + dat)
    assert classify(ms[1]) == "pack" and [e[0] for e in items(tab.ljust(SECTOR, b"\0") + dat)] == \
        ["000", "001/000", "001/001", "001/002", "001/003"]
    cen = census([e["type"] for m in spec if "pack" in m for e in m["pack"]])
    assert set(cen) == {0, 1, 2} and cen == {0: {3: 1, 5: 1}, 1: {1: 1}, 2: {2: 1}}, cen
    if roundtrip(f"{work}/src", f"{work}/rt"):
        raise SystemExit("assets: selftest FAIL clean roundtrip differs")
    if roundtrip(f"{work}/src", f"{work}/plant", plant="dat/001/002.bin") != "001/002":
        raise SystemExit("assets: selftest FAIL planted byte not caught")
    print("assets: control OK")


def main():
    if "--selftest" in sys.argv[1:]:
        return selftest()
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    sub = ap.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("survey", help="TOC + pack census of ROCK_X5.DAT")
    s.add_argument("--dat", default="extracted/retail/ROCK_X5.DAT")
    s = sub.add_parser("export", help="DAT -> .bin files + dat/index.json + manifest.jsonl")
    s.add_argument("--src", default="extracted/retail")
    s.add_argument("--out", default="assets/retail")
    s = sub.add_parser("import", help="export tree -> <out>/ROCK_X5.DAT")
    s.add_argument("--src", default="assets/retail")
    s.add_argument("--out", default="build/assets")
    s = sub.add_parser("apply", help="copy export tree, apply asset-edits/<name>/edit.json")
    s.add_argument("name")
    s.add_argument("--src", default="assets/retail")
    s.add_argument("--out")
    sub.add_parser("roundtrip", help="export+import under .run/assets-rt, compare to retail")
    a = ap.parse_args()
    if a.cmd == "survey":
        survey(a.dat)
    elif a.cmd == "export":
        export(a.src, a.out)
    elif a.cmd == "import":
        import_(a.src, a.out)
    elif a.cmd == "apply":
        apply(a.name, a.src, a.out or f"assets/work/{a.name}")
    elif a.cmd == "roundtrip":
        return 1 if roundtrip("extracted/retail", ".run/assets-rt") else 0


if __name__ == "__main__":
    sys.exit(main())
