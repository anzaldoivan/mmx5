#!/usr/bin/env python3
"""disc.py — rebuild the CD image from built + extracted files; gate on the track sha1.

build: dumpsxiso -s the original image -> build/disc/ref/layout.xml (layout, dates, license, trailing dummy);
       point every <file> at extracted/retail/<path> (ROCK_X5.BIN, SLUS_013.34 at our builds);
       mkpsxiso -> build/disc/mmx5.bin/.cue; sha1 vs config/medium.sha1 line 1.
build --out D --slus F --rockx5 F --no-gate: same into D/ from other inputs, no sha1 (make disc SHIFT=1).
build --file DISCPATH=SRC (repeatable): pack SRC (repo-relative) at DISCPATH, applied last (make disc-assets).
compare --image <bin>: the sha1 gate alone (exit 1 names first differing LBA, manifest extent, form).
"""
import argparse
import glob
import hashlib
import json
import os
import subprocess
import sys
import xml.etree.ElementTree as ET

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
TOOLS = os.path.join(ROOT, ".run/tools/mkpsxiso-2.30/mkpsxiso-2.30-Linux/bin")
REF = os.path.join(ROOT, "build/disc/ref")
OUT_BIN = os.path.join(ROOT, "build/disc/mmx5.bin")
OUT_CUE = os.path.join(ROOT, "build/disc/mmx5.cue")
XML = os.path.join(ROOT, "build/disc/mmx5.xml")
OVERRIDE = {"ROCK_X5.BIN": "build/disc/ROCK_X5.BIN", "SLUS_013.34": "build/slus/SLUS_013.34"}
SECTOR = 2352


def dump(ext):
    """The dump's .cue/.bin: beside bootstrap.sh's .run/dump-cue (as `make extract`), else disks/."""
    cue = os.path.join(ROOT, ".run/dump-cue")
    base = glob.escape(os.path.dirname(open(cue).read().strip())) if os.path.exists(cue) else "disks"
    return one(os.path.join(base, "*." + ext))


def one(pattern):
    hits = glob.glob(os.path.join(ROOT, pattern))
    if len(hits) != 1:
        sys.exit(f"disc: want exactly one {pattern}, found {len(hits)}")
    return hits[0]


def rewrite(src, dst, ref, override):
    tree = ET.parse(src)
    root = tree.getroot()
    lic = root.find(".//license")
    lic.set("file", os.path.join(ref, "license_data.dat"))

    def walk(node, prefix):
        for child in node:
            if child.tag == "dir":
                walk(child, prefix + child.get("name") + "/")
            elif child.tag == "file":
                path = prefix + child.get("name")
                child.set("source", os.path.join(ROOT, override.get(path, "extracted/retail/" + path)))

    walk(root.find(".//directory_tree"), "")
    tree.write(dst, encoding="utf-8", xml_declaration=True)


def compare(image):
    want = open(os.path.join(ROOT, "config/medium.sha1")).readline().split()[0]
    h = hashlib.sha1()
    with open(image, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    got = h.hexdigest()
    if got == want:
        print(f"disc: track sha1 {got} OK")
        return 0
    print(f"disc: track sha1 {got} != {want}")
    with open(image, "rb") as a, open(dump("bin"), "rb") as b:
        lba = 0
        while True:
            x, y = a.read(SECTOR), b.read(SECTOR)
            if x != y:
                break
            if not x:
                print("disc: sectors equal but sha differs (?)")
                return 1
            lba += 1
    where = "unmapped"
    with open(os.path.join(ROOT, "extracted/retail/manifest.jsonl")) as m:
        for line in m:
            r = json.loads(line)
            if r["lba"] <= lba < r["lba"] + r["sectors"]:
                where = f"{r['path']} (lba {r['lba']}+{r['sectors']})"
                break
    raw = y or x
    form = "form2" if len(raw) > 18 and raw[18] & 0x20 else "form1"
    size = f"(sizes {os.path.getsize(image)} vs ref)" if not x or not y else ""
    print(f"disc: first differing LBA {lba}: {where}, {form} {size}".rstrip())
    return 1


def build(out=None, slus=None, rockx5=None, gate=True, files=None):
    ref, xml, out_bin, out_cue = REF, XML, OUT_BIN, OUT_CUE
    if out:
        d = os.path.join(ROOT, out)
        ref, xml, out_bin, out_cue = (os.path.join(d, n) for n in ("ref", "mmx5.xml", "mmx5.bin", "mmx5.cue"))
    override = dict(OVERRIDE, **{k: v for k, v in (("SLUS_013.34", slus), ("ROCK_X5.BIN", rockx5)) if v})
    override.update(files or {})
    os.makedirs(ref, exist_ok=True)
    layout = os.path.join(ref, "layout.xml")
    subprocess.run([os.path.join(TOOLS, "dumpsxiso"), "-q", "-x", ref, "-s", layout, dump("cue")], check=True)
    rewrite(layout, xml, ref, override)
    subprocess.run([os.path.join(TOOLS, "mkpsxiso"), "-y", "-q", "-o", out_bin, "-c", out_cue, xml], check=True)
    if not gate:
        print(f"disc: {os.path.relpath(out_cue, ROOT)} built (sha gate skipped)")
        return 0
    return compare(out_bin)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    b = sub.add_parser("build")
    b.add_argument("--out", help="output dir (default build/disc)")
    b.add_argument("--slus", help="SLUS_013.34 to pack (default build/slus/SLUS_013.34)")
    b.add_argument("--rockx5", help="ROCK_X5.BIN to pack (default build/disc/ROCK_X5.BIN)")
    b.add_argument("--no-gate", action="store_true", help="skip the config/medium.sha1 compare")
    b.add_argument("--file", action="append", default=[], metavar="DISCPATH=SRC",
                   help="pack SRC (repo-relative) at DISCPATH; repeatable, applied last")
    c = sub.add_parser("compare")
    c.add_argument("--image", required=True)
    a = ap.parse_args()
    if a.cmd != "build":
        sys.exit(compare(a.image))
    files = {}
    for f in a.file:
        k, eq, v = f.partition("=")
        if not (k and eq and v):
            sys.exit("disc: --file wants <discpath>=<src>")
        files[k] = v
    sys.exit(build(a.out, a.slus, a.rockx5, not a.no_gate, files))


if __name__ == "__main__":
    main()
