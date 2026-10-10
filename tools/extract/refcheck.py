#!/usr/bin/env python3
"""Cross-check extracted/retail/ against a reference extractor (dumpsxiso, mkpsxiso v2.30).

Runs dumpsxiso into --ref (fresh each run), then compares every manifest `file` record byte-for-byte
with the reference's file of the same path. dumpsxiso writes form2/mixed files as 2336 bytes/sector
(raw 16..2351), the same layout as ours (docs/formats.md), so no normalisation is applied.
Exit 0 iff differences == 0 and every manifest file record is compared or listed under "no reference".
"""
import argparse
import filecmp
import glob
import json
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--cue", default=None, help="CUE path (default: disks/*.cue)")
    ap.add_argument("--ref", default=".run/ref", help="reference output dir (wiped each run)")
    ap.add_argument("--ours", default="extracted/retail", help="our extraction dir")
    a = ap.parse_args()

    cue = a.cue or (sorted(glob.glob(str(ROOT / "disks/*.cue"))) or [None])[0]
    tools = sorted(glob.glob(str(ROOT / ".run/tools/**/bin/dumpsxiso"), recursive=True))
    if not cue or not tools:
        sys.exit(f"refcheck: missing {'cue' if not cue else 'dumpsxiso under .run/tools/'}")
    ref, ours = ROOT / a.ref, ROOT / a.ours

    shutil.rmtree(ref, ignore_errors=True)
    ref.mkdir(parents=True)
    r = subprocess.run([tools[-1], "-q", "-n", "-x", str(ref), cue], capture_output=True, text=True)
    if r.returncode != 0:
        sys.exit(f"refcheck: dumpsxiso exit {r.returncode}: {r.stderr.strip()[-400:]}")

    recs = [json.loads(l) for l in (ours / "manifest.jsonl").read_text().splitlines() if l.strip()]
    files = [x for x in recs if x["kind"] == "file"]
    counts = {"form1": 0, "form2": 0, "mixed": 0, "trivial": 0}
    compared, noref, diffs = [], [], []
    for x in files:
        cls = "trivial" if x.get("trivial") else x["mode"]
        counts[cls] += 1
        rp, op = ref / x["path"], ours / x["path"]
        if not rp.is_file():
            noref.append(f"{x['path']} (not produced by dumpsxiso)")
            continue
        compared.append(x["path"])
        if not op.is_file() or not filecmp.cmp(rp, op, shallow=False):
            diffs.append(x["path"])

    print(" ".join(f"{k}: {v}" for k, v in counts.items()))
    print(f"compared: {len(compared)}")
    print(f"no reference: {len(noref)}" + "".join(f"\n  {n}" for n in noref))
    print(f"differences: {len(diffs)}" + "".join(f"\n  {d}" for d in diffs))
    ok = not diffs and len(compared) + len(noref) == len(files)
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
