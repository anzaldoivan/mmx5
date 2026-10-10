# tools/permuter — decomp-permuter on one draft (T5.c1)

Setup: `bash tools/codegen/stage.sh --permuter` (clones refs/decomp-permuter at its config/refs.toml pin);
`pip install --user --require-hashes` the `toml` pin of requirements-python.txt into PY (the permuter's only
non-stdlib import; it vendors perm_pycparser).

Health: `make tools-health` runs `permute.py run` on `drafts/func_80027474.near.c` and `plateau.py classify` on `drafts/func_80027474.width.c` (rungs 16-17); `make tools-selftest` runs both `--selftest`.

    PY tools/permuter/permute.py run <draft.c> --fn <sym> --iters N [--seed S] [--timeout SEC]
    PY tools/permuter/permute.py --selftest

`run` stages `.run/permuter/<fn>/`:
- `base.c`: the draft through our cpp (`-P`, flat; the permuter's own host-cpp pass sees no includes).
- `target.o`: the function's own bytes, `expected/build/slus/` at the vram/size of its carved splat subsegment
  (`config/splat.slus.yaml`), assembled as `.word`s. Game bytes: it never leaves `.run/` (G12). slus only.
- `settings.toml`: `compiler_type = "gcc"`, `objdump_command` (docs/ops/toolchain.md ## objdump).
- `compile.sh`: appends the candidate's sha1 to `compiles.log`, then runs `tools/permuter/compile.sh`
  (= the mk/slus.mk C rule; `cmp`-identical to the `make` object).

The permuter runs single-threaded with `--seed S` (default 1; the candidate stream is deterministic) and is killed
once `compiles.log` holds N candidates (the in-flight one may make it N+1) or after `--timeout` (240 s).
Output: `permuter: <fn> <i> iterations, <k> distinct candidates, base <b> best <s>`.
- `i`, `k`: from `compiles.log` (line 1 = base), never the permuter's stdout.
- `base`, `best`: the stock scorer recomputed here on base.c and the lowest `output-<score>-*/source.c`.
- exit 1 when `i == 0`.
Permuter stdout: `.run/permuter/<fn>/permuter.log`; improved candidates: `output-<score>-<n>/`.

Scorer: stock (difflib, branch targets ignored). Masked scoring not adopted: func_80027474 carries no relocations,
so the stock scorer's reloc handling never enters (T5.c1 log).

`--selftest` (ROM-free): target compiled from `fixtures/target.c`, draft `fixtures/near.c`. A planted idle run
(`--debug`: base only, 0 iterations) must exit nonzero and a 5-iteration run must exit 0;
prints `permuter: control OK -- idle run refused`.

Demo draft: `drafts/func_80027474.near.c`, our own near-miss of `src/slus/func_80027474.c`.

## plateau.py

    PY tools/permuter/plateau.py classify <draft.c> --fn <sym> [--iters N] [--expect-class C] [--no-permute]
    PY tools/permuter/plateau.py --selftest

Needs `rabbitizer` (requirements-python.txt pin; docs/ops/toolchain.md). `classify` runs `permute.py run` (N = 100
by default; `--no-permute` skips it), takes the lowest-score `.run/permuter/<fn>/output-*/source.c` (else the draft),
compiles it at the pin (`reconcile.triple()`, `probe.compile_obj`), masks ours and the target with our relocs, aligns
the rabbitizer text (difflib) and prints `plateau: <fn> class <c> label <l>`; classes: docs/codegen-map/README.md
`## Residual classes`. The width/signedness family (lbu/lb, lhu/lh, sb/sh, `andi 0xFF|0xFFFF` vs `sll+sra 24|16`,
sltu/slt, divu/div, srl/sra; `move` only alongside one) is tested per hunk before LENGTH-DRIFT, since an extension
changes the hunk's length. Carved span zero padding past our function's end is trimmed.

Label (first match wins):
- MATCH → `none` (not a plateau).
- `--expect-class` given and not the bytes' class → `mis-classified`.
- MIXED, OPCODE-MIXED, UNKNOWN, EMPTY → `wall`.
- WIDTH, BRANCH-POLARITY, ADDRESSING, STRENGTH, IMM-OFFSET, SHIFT-DRIFT, SIZE-MISMATCH, LENGTH-DRIFT with |Δ| > 2
  → `seed-structural`.
- REGALLOC-PERM/-LOCAL, SCHEDULE-REORDER, DELAY-SLOT, IMM-VALUE, LENGTH-DRIFT with |Δ| ≤ 2, plateaued
  (best == base or best > 0) → `missing-transform`.

`--selftest` (ROM-free, no permuter run): `fixtures/width.c` (`s16 *p`) against its own `u16 *p` twin written to
`.run/plateau/selftest/` must be `width`/`seed-structural`; the twin against itself must be `match`/`none`; prints
`plateau: control OK -- planted plateau labelled seed-structural`.

Demo draft `drafts/func_80027474.width.c`: `u8 to` → `s8 to`. The function has no u16, so the flip is u8 → s8; a
param, not the return type: `s8` return re-schedules the early-return moves and shifts a branch offset (a mixed
residual), while `s8 to` leaves sll+sra 24 vs `andi 0xFF`, slt vs sltu and `andi 0xFF` vs `move` only.
