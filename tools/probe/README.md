# tools/probe — compiler-ladder probe

`PY tools/probe/probe.py ladder [--probe NAME] [--triple ID]` · `PY tools/probe/probe.py --selftest`

- `ladder.toml`: 30 `[[triple]]` = rungs L3 (gcc-2.95.2-psx), L3b (gcc-2.91.66-psx), L4 (gcc-2.7.2-psx),
  L5 (gcc-2.8.1-psx), L6 (gcc-2.7.2, -G8) × aspsx 2.56/2.67/2.77/2.79/2.81/2.86. Fields: `id cc1 cflags aspsx
  maspsx_flags asflags [constitution]`. Ids `<rung>-<cc>-as<ver>`, e.g. `L4-gcc272psx-as256`.
- `probes.toml`: `[[probe]] alias name vram size src module` (schema in the file header).
- Pipeline per probe × triple: `tools/bin/cc/<name>/cpp` (flags + `-undef` except 2.95.2-psx) → cc1 →
  `refs/maspsx/maspsx.py --aspsx-version=X` → `tools/bin/mipsel-linux-gnu-as -EL -march=r3000 -no-pad-sections`.
  Scratch: `.run/probe/<probe>/<triple>/` (`*.err` per stage).
- Compare: the function's `.text` (symbol value/size from the .o), relocated fields masked on both sides
  (R_MIPS_26 low 26 bits; HI16/LO16/GPREL16 low 16), against `size` target bytes from `expected/build/<alias>/`
  (slus: vram − t_addr + 0x800; rockx5: overlay `start` + vram − overlay `vram` in config/splat.rockx5.yaml).
- Output: `<probe> <triple> match|diff <n>|error <stage>` (n = differing words; length mismatch counts),
  then `pin: <triple|none> -- <k> of <n> probes, <m> triples`. Exit 0 iff exactly one triple matches every probe.
- `--selftest`: selftest.c under L4-gcc272psx-as256 as its own target → `match`; one flipped non-relocated byte
  → `diff 1`; plus an informational line vs L3-gcc2952psx-as286. Exit 0 iff both controls behave.
- `PY tools/probe/fingerprint.py [--alias A]`: per-module asm tells T1-T6 → `.run/probe/fingerprint.txt`; docs/ops/compiler-pin.md.
- Firewall G12: target bytes are never printed or written; only counts.
