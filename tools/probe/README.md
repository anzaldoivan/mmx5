# tools/probe — compiler-ladder probe

`PY tools/probe/probe.py ladder [--probe NAME] [--triple ID]` · `PY tools/probe/probe.py --selftest`

- `ladder.toml` holds 30 `[[triple]]`: the rungs L3 (gcc-2.95.2-psx), L3b (gcc-2.91.66-psx), L4 (gcc-2.7.2-psx),
  L5 (gcc-2.8.1-psx), L6 (gcc-2.7.2, -G8) × aspsx 2.56/2.67/2.77/2.79/2.81/2.86. The fields are `id cc1 cflags aspsx
  maspsx_flags asflags [constitution]`. An id has the form `<rung>-<cc>-as<ver>`, e.g. `L4-gcc272psx-as256`.
- `probes.toml` holds `[[probe]] alias name vram size src module`. The file header has the schema.
- The pipeline per probe × triple is `tools/bin/cc/<name>/cpp` (flags + `-undef` except 2.95.2-psx) → cc1 →
  `refs/maspsx/maspsx.py --aspsx-version=X` → `tools/bin/mipsel-linux-gnu-as -EL -march=r3000 -no-pad-sections`.
  The scratch directory is `.run/probe/<probe>/<triple>/` (`*.err` per stage).
- The tool compares the function's `.text` (symbol value/size from the .o) against `size` target bytes from
  `expected/build/<alias>/`. It masks the relocated fields on both sides (R_MIPS_26 low 26 bits, HI16/LO16/GPREL16
  low 16). For slus, the target bytes are at vram − t_addr + 0x800. For rockx5, they are at overlay `start` + vram −
  overlay `vram` in config/splat.rockx5.yaml.
- The output is `<probe> <triple> match|diff <n>|error <stage>` (n = differing words, and a length mismatch counts),
  then `pin: <triple|none> -- <k> of <n> probes, <m> triples`. The exit is 0 iff exactly one triple matches every
  probe.
- `--selftest` takes selftest.c under L4-gcc272psx-as256 as its own target → `match`. One flipped non-relocated byte
  → `diff 1`. `--selftest` adds an informational line vs L3-gcc2952psx-as286. The exit is 0 iff both controls
  behave.
- `PY tools/probe/fingerprint.py [--alias A]` writes the per-module asm tells T1-T6 to
  `.run/probe/fingerprint.txt`. Refer to docs/ops/compiler-pin.md.
- Firewall G12: the tool never prints or writes target bytes, only counts.
