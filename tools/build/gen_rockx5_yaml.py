#!/usr/bin/env python3
"""One-time seeder: docs/oracle/loadmap.json `overlays[]` -> config/splat.rockx5.yaml (hand-edited after).

Segments: TOC sector bin; code overlay with dest -> code segment ovlNN (vram=dest, exclusive_ram_id per
dest group, asm + bin tail when size % 4); data overlays and null-dest overlays -> bin; gaps -> bin padNN.
Offsets and sizes only: no game bytes (G12).
"""
import argparse
import json

EOF = 0x152000
HEAD = """\
# splat config for ROCK_X5.BIN (alias rockx5). All-asm split; `make split build BINARY=rockx5` must hash-match
# config/check.rockx5.sha. Seeded by tools/build/gen_rockx5_yaml.py from docs/oracle/loadmap.json; outputs ignored.
# Code segments: align 1 (splat default 0x10 pads ROM after odd-sized overlays).
# Overlays sharing a dest share one exclusive_ram_id; symbol names carry the segment ($VRAM_$SEG) so they link.
name: ROCK_X5.BIN
sha1: 3ab6c9cf7532d9702699b655d761c0dc0c2a7fab
options:
  basename: ROCK_X5.BIN
  target_path: extracted/retail/ROCK_X5.BIN
  base_path: ..
  platform: psx
  compiler: PSYQ

  asm_path: asm/rockx5
  src_path: src/rockx5
  build_path: build/rockx5
  ld_script_path: build/rockx5/ROCK_X5.BIN.ld
  elf_path: build/rockx5/ROCK_X5.BIN.elf
  generated_asm_macros_directory: asm/rockx5/include
  asset_path: assets/rockx5

  find_file_boundaries: False
  gp_value: 0x80091C30  # exe $gp (docs/ops/toolchain.md ## $gp); overlays run under it
  o_as_suffix: True
  use_legacy_include_asm: False
  section_order: [".rodata", ".text", ".data", ".bss"]
  symbol_name_format: $VRAM_$SEG

  symbol_addrs_path:
    - config/symbols.rockx5.txt
  undefined_funcs_auto_path: build/rockx5/undefined_funcs_auto.txt
  undefined_syms_auto_path: build/rockx5/undefined_syms_auto.txt

  subalign: 1  # odd-sized overlay tails: SUBALIGN(2) fills after them (slus uses 2)
  ld_align_section_vram_end: False
  ld_align_segment_vram_end: False
  string_encoding: ASCII
  data_string_encoding: ASCII

segments:
  - name: toc
    type: bin
    start: 0x0
"""


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--src", default="docs/oracle/loadmap.json")
    ap.add_argument("--out", default="config/splat.rockx5.yaml")
    a = ap.parse_args()
    ovls = sorted(json.load(open(a.src, encoding="utf-8"))["overlays"], key=lambda o: o["bin_offset"])
    out = [HEAD]
    pos = 0x800
    for o in ovls:
        n, start, size, dest = o["index"], o["bin_offset"], o["size"], o["dest"]
        assert start >= pos, (n, hex(start), hex(pos))
        if start > pos:
            out.append(f"  - {{name: pad{n:02d}, type: bin, start: 0x{pos:X}}}\n")
        if o["kind"] == "code" and dest:
            ram = "ovlA" if dest == "800EE970" else "ovlB"
            out.append(f"  - name: ovl{n:02d}\n    type: code\n    start: 0x{start:X}\n"
                       f"    vram: 0x{dest}\n    align: 1\n    exclusive_ram_id: {ram}\n    subsegments:\n"
                       f"      - [0x{start:X}, asm]\n")
            if size % 4:
                out.append(f"      - [0x{start + size // 4 * 4:X}, bin]\n")
        else:
            out.append(f"  - {{name: ovl{n:02d}, type: bin, start: 0x{start:X}}}\n")
        pos = start + size
    if pos < EOF:
        out.append(f"  - {{name: padend, type: bin, start: 0x{pos:X}}}\n")
    out.append(f"  - [0x{EOF:X}]\n")
    open(a.out, "w", encoding="utf-8").write("".join(out))


if __name__ == "__main__":
    main()
