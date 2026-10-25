#!/usr/bin/env python3
"""Mirror config/symbols.*.txt names into the Ghidra project (ghidra/mmx5, program SLUS_013.34).

apply: write .run/mirror/spec.tsv, run ApplySymbols.java headless (compare-before-write; saves the program);
       if any applied, re-export docs/oracle/annotations.jsonl (ExportAnnotations.java, as roundtrip.sh).
       Prints `mirror: <n> names, <k> applied, <d> diffs`; a second apply prints `0 applied`.
check: reopen read-only (-readOnly -noanalysis), ExportSymbols.java dumps the primary name per address to
       .run/mirror/export.tsv; prints each diff, then `mirror: <n> names, <d> diffs`; exit 1 if d > 0.
Symbol line: `<name> = 0x<ADDR>; // type:<t> [rom:0x<off>]`. symbols.slus.txt -> main space; symbols.rockx5.txt ->
the overlay block `ovlNN` (tools/ghidra/scripts/ImportOverlays.java) holding rom, cross-checked with an `_ovlNN` suffix.
Names and addresses only (G12); spec/export files under .run/ only.
"""
import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT / ".run" / "mirror"
LINE = re.compile(r"^\s*(\S+)\s*=\s*0x([0-9A-Fa-f]+);(?:\s*//(.*))?$")


def overlays():
    lm = json.loads((ROOT / "docs/oracle/loadmap.json").read_text())
    return [o for o in lm["overlays"] if o["kind"] == "code" and o["dest"]]


def symbols():
    """[(name, ghidra addr string)] across config/symbols.*.txt, file order."""
    ovl, rows = overlays(), []
    for f in sorted((ROOT / "config").glob("symbols.*.txt")):
        for i, ln in enumerate(f.read_text().splitlines(), 1):
            if not ln.strip() or ln.lstrip().startswith("//"):
                continue
            m = LINE.match(ln)
            if not m:
                sys.exit(f"mirror: unparsed {f.name}:{i}: {ln}")
            name, addr, tail = m.group(1), int(m.group(2), 16), m.group(3) or ""
            a = f"{addr:08x}"
            if f.name != "symbols.slus.txt":
                rom = re.search(r"rom:0x([0-9A-Fa-f]+)", tail)
                hit = [o for o in ovl if rom and o["bin_offset"] <= int(rom.group(1), 16) < o["bin_offset"] + o["size"]]
                sfx = re.search(r"_ovl(\d+)$", name)
                if len(hit) != 1 or (sfx and int(sfx.group(1)) != hit[0]["index"]) or \
                        int(hit[0]["dest"], 16) + int(rom.group(1), 16) - hit[0]["bin_offset"] != addr:
                    sys.exit(f"mirror: no overlay for {f.name}:{i}: {name}")
                a = f"ovl{hit[0]['index']:02d}::{a}"
            rows.append((name, a))
    return rows


def headless(tag, *args):
    env = subprocess.run(["bash", "-c", f"source {ROOT}/tools/ghidra/env.sh; echo $GHIDRA_HOME; echo $GHIDRA_PROJ; echo $PROJ_NAME"],
                         capture_output=True, text=True, check=True).stdout.split()
    out = OUT / f"{tag}.out"
    with open(out, "w") as fh:
        r = subprocess.run([f"{env[0]}/support/analyzeHeadless", env[1], env[2], "-process", "SLUS_013.34", "-noanalysis",
                            "-scriptPath", str(ROOT / "tools/ghidra/scripts"), "-log", str(OUT / f"{tag}.analyze.log"),
                            "-scriptlog", str(OUT / f"{tag}.script.log"), *args], stdout=fh, stderr=subprocess.STDOUT)
    text = out.read_text()
    if r.returncode:
        print("\n".join(text.splitlines()[-20:]))
        sys.exit(f"mirror: headless {tag} failed; see {out}")
    return text


def clean(s):
    return re.sub(r"\s*\(GhidraScript\)\s*$", "", s)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", choices=["apply", "check"])
    a = ap.parse_args()
    rows = symbols()
    OUT.mkdir(parents=True, exist_ok=True)
    spec = OUT / "spec.tsv"
    spec.write_text("".join(f"{n}\t{ad}\n" for n, ad in rows))
    if a.cmd == "apply":
        text = headless("apply", "-postScript", "ApplySymbols.java", str(spec))
        for ln in text.splitlines():
            if "mirror-error: " in ln:
                print(clean(ln[ln.index("mirror-error: "):]))
        m = re.search(r"mirror-apply: (\d+) names, (\d+) applied, (\d+) diffs, (\d+) errors", text)
        if not m:
            sys.exit(f"mirror: ApplySymbols printed no summary; see {OUT / 'apply.out'}")
        n, k, d, e = map(int, m.groups())
        if k:  # renames become user-sourced annotations: keep the record current (roundtrip.sh cmp A record)
            headless("export-ann", "-readOnly", "-postScript", "ExportAnnotations.java",
                     str(ROOT / "docs/oracle/annotations.jsonl"))
        print(f"mirror: {n} names, {k} applied, {d + e} diffs")
        sys.exit(1 if d + e or n != len(rows) else 0)
    exp = OUT / "export.tsv"
    headless("check", "-readOnly", "-postScript", "ExportSymbols.java", str(spec), str(exp))
    got = [ln.split("\t") for ln in exp.read_text().splitlines()]
    diffs = 0 if len(got) == len(rows) else 1
    for (name, ad), (gad, gname) in zip(rows, got):
        if gad != ad or gname != name:
            diffs += 1
            print(f"mirror: diff {ad}: want {name}, ghidra {gname}")
    print(f"mirror: {len(rows)} names, {diffs} diffs")
    sys.exit(1 if diffs else 0)


if __name__ == "__main__":
    main()
