# tools/permuter — decomp-permuter on one draft (T5.c1)

For the setup, run `bash tools/codegen/stage.sh --permuter`. The command clones refs/decomp-permuter at its
config/refs.toml pin. Install the `toml` pin of requirements-python.txt into PY with
`pip install --user --require-hashes`. `toml` is the only non-stdlib import of the permuter. The permuter vendors
perm_pycparser.

Health: `make tools-health` runs `permute.py run` on `drafts/func_80027474.near.c` and `plateau.py classify` on
`drafts/func_80027474.width.c` (rungs 16-17). `make tools-selftest` runs both `--selftest`.

    PY tools/permuter/permute.py run <draft.c> --fn <sym> --iters N [--seed S] [--timeout SEC]
    PY tools/permuter/permute.py --selftest

`run` stages `.run/permuter/<fn>/`:
- `base.c` is the draft through our cpp (`-P`, flat). The permuter's own host-cpp pass sees no includes.
- `target.o` holds the function's own bytes. `run` takes them from `expected/build/slus/` at the vram/size of the
  function's carved splat subsegment (`config/splat.slus.yaml`) and assembles them as `.word`s. The file holds game
  bytes. It never leaves `.run/` (G12). This is for slus only.
- `settings.toml` holds `compiler_type = "gcc"` and `objdump_command` (docs/ops/toolchain.md ## objdump).
- `compile.sh` appends the candidate's sha1 to `compiles.log`, then runs `tools/permuter/compile.sh`. That script is
  the mk/slus.mk C rule. Its object is `cmp`-identical to the `make` object.

The permuter runs single-threaded with `--seed S` (default 1). The candidate stream is deterministic. `run` kills
the permuter once `compiles.log` holds N candidates or after `--timeout` (240 s). The in-flight candidate may make
the count N+1.

The output is `permuter: <fn> <i> iterations, <k> distinct candidates, base <b> best <s>`.
- `i` and `k` come from `compiles.log` (line 1 = base), never from the permuter's stdout.
- `run` recomputes `base` and `best` here with the stock scorer, on base.c and the lowest
  `output-<score>-*/source.c`.
- When `i == 0`, `run` exits 1.

The permuter's stdout goes to `.run/permuter/<fn>/permuter.log`. Improved candidates go to `output-<score>-<n>/`.

The scorer is stock (difflib, branch targets ignored). We did not adopt masked scoring: func_80027474 carries no
relocations, so the stock scorer's reloc handling never enters (T5.c1 log).

`--selftest` is ROM-free. It compiles the target from `fixtures/target.c`. The draft is `fixtures/near.c`. A planted
idle run (`--debug`: base only, 0 iterations) must exit nonzero and a 5-iteration run must exit 0. `--selftest`
prints `permuter: control OK -- idle run refused`.

The demo draft is `drafts/func_80027474.near.c`, our own near-miss of `src/slus/func_80027474.c`.

## plateau.py

    PY tools/permuter/plateau.py classify <draft.c> --fn <sym> [--iters N] [--expect-class C] [--no-permute]
    PY tools/permuter/plateau.py --selftest

`plateau.py` needs `rabbitizer` (requirements-python.txt pin, docs/ops/toolchain.md).

`classify` runs `permute.py run` (N = 100 by default). `--no-permute` skips that run. `classify` takes the
lowest-score `.run/permuter/<fn>/output-*/source.c` (else the draft) and compiles it at the pin
(`reconcile.triple()`, `probe.compile_obj`). It masks ours and the target with our relocs, aligns the rabbitizer text
(difflib) and prints `plateau: <fn> class <c> label <l>`. The classes are in docs/codegen-map/README.md
`## Residual classes`.

`classify` tests the width/signedness family per hunk before LENGTH-DRIFT, since an extension changes the hunk's
length. The family is lbu/lb, lhu/lh, sb/sh, `andi 0xFF|0xFFFF` vs `sll+sra 24|16`, sltu/slt, divu/div and srl/sra.
`move` counts only alongside one of them. `classify` trims the zero padding of the carved span past our function's
end.

Label (first match wins):
- MATCH → `none` (not a plateau).
- `--expect-class` given and not the bytes' class → `mis-classified`.
- MIXED, OPCODE-MIXED, UNKNOWN, EMPTY → `wall`.
- WIDTH, BRANCH-POLARITY, ADDRESSING, STRENGTH, IMM-OFFSET, SHIFT-DRIFT, SIZE-MISMATCH, LENGTH-DRIFT with |Δ| > 2
  → `seed-structural`.
- REGALLOC-PERM/-LOCAL, SCHEDULE-REORDER, DELAY-SLOT, IMM-VALUE, LENGTH-DRIFT with |Δ| ≤ 2, plateaued
  (best == base or best > 0) → `missing-transform`.

`--selftest` is ROM-free and has no permuter run. `fixtures/width.c` (`s16 *p`) against its own `u16 *p` twin must be
`width`/`seed-structural`. `--selftest` writes the twin to `.run/plateau/selftest/`. The twin against itself must be
`match`/`none`. `--selftest` prints `plateau: control OK -- planted plateau labelled seed-structural`.

The demo draft `drafts/func_80027474.width.c` changes `u8 to` → `s8 to`. The function has no u16, so the flip is
u8 → s8. The flip is a param, not the return type: an `s8` return re-schedules the early-return moves and shifts a
branch offset (a mixed residual). But `s8 to` leaves sll+sra 24 vs `andi 0xFF`, slt vs sltu and `andi 0xFF` vs `move`
only.
