#!/usr/bin/env python3
"""gen_objdiff.py — objdiff.json for the byte-matching build of the boot executable (stdlib only; modelled on mmx6's
tools/gen_objdiff.py, itself on sozud/mmx4's). Run after `make split build BINARY=slus`, from the repository root.

Reads config/splat.slus.yaml (tracked) and the objects under build/slus/.

Unit = one code subsegment (`c` or `asm`) of the splat config -> one object:
          c   -> build/slus/src/slus/<name>.o
          asm -> build/slus/asm/slus/<name>.o
target_path = that object (the build is byte-identical to the disc, so it IS the expected object).
base_path   = c unit: the same object (splat's `nonmatching` macro emits <func>.NON_MATCHING for an INCLUDE_ASM body,
              so objdiff drops that function on the base side: it counts as not matched);
              asm unit: build/slus/empty.o (nothing decompiled).
Categories (config/categories.tsv; ids are frozen once published): a PsyQ library object (LIB*, libgap*) is `sdk`,
every other unit is `game` + `main`. ROCK_X5.BIN joins when it has C: a new top-level id, never a rename.
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
SUB = re.compile(r"^\s*- \[0x[0-9A-Fa-f]+,\s*(c|asm),\s*([\w.]+)\]")
SDK = re.compile(r"^(LIB[A-Z0-9]+_|libgap_)")
CATEGORIES = ["# config/categories.tsv -- from tools/gen_objdiff.py. id parent name status",
              "id\tparent\tname\tstatus", "game\t\tGame code\tactive", "sdk\t\tPsyQ SDK libraries\tactive",
              "main\t\t%s (boot executable)\tactive" % EXE]


def units():
    out = []
    for line in open("config/splat.%s.yaml" % ALIAS):
        m = SUB.match(line)
        if m:
            kind, name = m.groups()
            d = "src" if kind == "c" else "asm"
            out.append(dict(name="main/" + name, kind=kind, src="%s/%s/%s.%s" % (d, ALIAS, name, "c" if kind == "c" else "s"),
                            obj="build/%s/%s/%s/%s.o" % (ALIAS, d, ALIAS, name),
                            cats=["sdk"] if SDK.match(name) else ["game", "main"]))
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
    us = units()
    missing = [u["obj"] for u in us if not os.path.exists(u["obj"])]
    if missing or not us:
        sys.exit("missing objects (did `make split build BINARY=%s` run?): %d, e.g. %s" % (ALIAS, len(missing), missing[:3]))
    if a.categories_out:
        open(a.categories_out, "w").write("\n".join(CATEGORIES) + "\n")
    empty = ensure_empty()
    cats = [r.split("\t") for r in CATEGORIES[2:]]
    cfg = {"build_base": False, "build_target": False,
           "units": [{"name": u["name"], "target_path": u["obj"], "base_path": u["obj"] if u["kind"] == "c" else empty,
                      "metadata": {"source_path": u["src"], "progress_categories": u["cats"]}}
                     for u in sorted(us, key=lambda u: u["name"])],
           "progress_categories": [{"id": c[0], "name": c[2]} for c in cats]}
    with open(a.out, "w") as f:
        json.dump(cfg, f, indent=2)
        f.write("\n")
    n_c = sum(u["kind"] == "c" for u in us)
    print("%s: %d units (%d C, %d asm; %d sdk)" % (a.out, len(us), n_c, len(us) - n_c, sum(u["cats"] == ["sdk"] for u in us)))


main()
