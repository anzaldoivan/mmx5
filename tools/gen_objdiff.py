#!/usr/bin/env python3
"""gen_objdiff.py — objdiff.json for the byte-matching build of the boot executable (stdlib only; modelled on mmx6's
tools/gen_objdiff.py, itself on sozud/mmx4's). Run after `make split build BINARY=slus` and `BINARY=rockx5`, from the
repository root.

Reads config/splat.slus.yaml + config/splat.rockx5.yaml (tracked) and the objects under build/slus/, build/rockx5/.

Unit = one code subsegment (`c` or `asm`) of the splat config -> one object:
          c   -> build/<alias>/src/<alias>/<name>.o
          asm -> build/<alias>/asm/<alias>/<name>.o   (an unnamed rockx5 subsegment is named by its hex offset, as splat does)
Unit names: slus `main/<name>`, rockx5 `rock/<ovl>/<name>`.
target_path = that object (the build is byte-identical to the disc, so it IS the expected object).
base_path   = c unit: the same object (splat's `nonmatching` macro emits <func>.NON_MATCHING for an INCLUDE_ASM body,
              so objdiff drops that function on the base side: it counts as not matched);
              asm unit: build/slus/empty.o (nothing decompiled).
Categories (config/categories.tsv; ids are frozen once published): a PsyQ library object (LIB*, libgap*) is `sdk`,
every other unit is `game` + `main`; a ROCK_X5.BIN unit is `game` + `rock` + `rock.<ovl>` (one id per overlay with code).
build_base/build_target are false: objdiff-cli never runs make.

  gen_objdiff.py [--out objdiff.json] [--categories-out config/categories.tsv]
"""
import argparse
import json
import os
import re
import subprocess
import sys

EXE, ALIAS = "SLUS_013.34", "slus"
SUB = re.compile(r"^\s*- \[0x([0-9A-Fa-f]+),\s*(c|asm)(?:,\s*([\w.]+))?\]")
SEG = re.compile(r"^  - name: (\w+)")
SDK = re.compile(r"^(LIB[A-Z0-9]+_|libgap_)")
CATEGORIES = ["# config/categories.tsv -- from tools/gen_objdiff.py. id parent name status",
              "id\tparent\tname\tstatus", "game\t\tGame code\tactive", "sdk\t\tPsyQ SDK libraries\tactive",
              "main\t\t%s (boot executable)\tactive" % EXE, "rock\t\tROCK_X5.BIN overlays\tactive"]


def units(alias):
    out, seg = [], None
    for line in open("config/splat.%s.yaml" % alias):
        m = SEG.match(line)
        if m:
            seg = m.group(1)
        m = SUB.match(line)
        if m:
            off, kind, name = m.groups()
            name = name or off.upper()
            d = "src" if kind == "c" else "asm"
            if alias == ALIAS:
                uname, cats = "main/" + name, ["sdk"] if SDK.match(name) else ["game", "main"]
            else:
                uname, cats = "rock/%s/%s" % (seg, name), ["game", "rock", "rock." + seg]
            out.append(dict(name=uname, kind=kind, src="%s/%s/%s.%s" % (d, alias, name, "c" if kind == "c" else "s"),
                            obj="build/%s/%s/%s/%s.o" % (alias, d, alias, name), cats=cats))
    return out


def ensure_empty():
    p = "build/%s/empty.o" % ALIAS
    if not os.path.exists(p):
        local = "tools/bin/mipsel-linux-gnu-as"
        subprocess.run([local if os.path.exists(local) else "mipsel-linux-gnu-as", "-EL", "-march=r3000", "-o", p,
                        os.devnull], check=True)
    return p


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default="objdiff.json")
    ap.add_argument("--categories-out", default=None)
    a = ap.parse_args()
    us = units(ALIAS) + units("rockx5")
    missing = [u["obj"] for u in us if not os.path.exists(u["obj"])]
    if missing or not us:
        sys.exit("missing objects (did `make split build BINARY=slus|rockx5` run?): %d, e.g. %s" % (len(missing), missing[:3]))
    assert len({u["name"] for u in us}) == len(us), "duplicate unit names"
    ovls = sorted({u["cats"][2] for u in us if len(u["cats"]) == 3})
    rows = CATEGORIES + ["%s\trock\tOverlay %s\tactive" % (o, o[len("rock.ovl"):]) for o in ovls]
    if a.categories_out:
        open(a.categories_out, "w").write("\n".join(rows) + "\n")
    empty = ensure_empty()  # ponytail: one empty object serves as the asm base of both binaries
    cats = [r.split("\t") for r in rows[2:]]
    cfg = {"build_base": False, "build_target": False,
           "units": [{"name": u["name"], "target_path": u["obj"], "base_path": u["obj"] if u["kind"] == "c" else empty,
                      "metadata": {"source_path": u["src"], "progress_categories": u["cats"]}}
                     for u in sorted(us, key=lambda u: u["name"])],
           "progress_categories": [{"id": c[0], "name": c[2]} for c in cats]}
    with open(a.out, "w") as f:
        json.dump(cfg, f, indent=2)
        f.write("\n")
    n_c = sum(u["kind"] == "c" for u in us)
    print("%s: %d units (%d C, %d asm; %d sdk; %d rock)" % (a.out, len(us), n_c, len(us) - n_c,
                                                          sum(u["cats"] == ["sdk"] for u in us), sum("rock" in u["cats"] for u in us)))


main()
