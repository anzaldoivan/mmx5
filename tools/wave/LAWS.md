# Drafter laws (tools/wave)

- Pin + C rule: every draft builds as `mk/slus.mk:43`: `cpp | cc1 | maspsx | as`, gcc-2.95.2-psx cc1, `-O2 -G0 -quiet -w`,
  maspsx `--aspsx-version=2.86`, `-D__CHAR_UNSIGNED__` (pin L3-gcc2952psx-as286: docs/ops/compiler-pin.md ## Pin,
  docs/ops/toolchain.md). Never another compiler, flag or `#pragma`.
- Includes: `#include "types.h"` (include/types.h; a signed byte is `signed char`); `include/include_asm.h` only for
  INCLUDE_ASM of bodies not yet drafted. Grow types one proven field at a time (G62); no speculative struct.
- Dest: `src/<alias>/<name>.c` (the card's Dest file); declarations from the card (dest decls, callee consensus).
- Try loop: `PY tools/wave/waves.py try <draft.c> --target <alias>_<name>` only; never `make` in the tree.
  `try: <name> match` = done; `diff <d> of <w> words` = iterate; exit 2 = compile error.
- Cap: 30 tries per target (counted from `.run/wave/try/<alias>_<name>.jsonl`), then stop and report the best diff.
- No asm paste: no `__asm__` bodies standing in for C, no pasted disassembly in drafts, cards, logs or commits (G12).
- Stuck on a diff: docs/codegen-map/SYMPTOMS.md (symptom -> cookbook entry -> lever), levers by id only.
