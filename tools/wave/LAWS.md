# Drafter laws (tools/wave)

- Pin + C rule: every draft builds as `mk/slus.mk:43`: `cpp | cc1 | maspsx | as`, gcc-2.95.2-psx cc1, `-O2 -G0 -quiet -w`,
  maspsx `--aspsx-version=2.86`, `-D__CHAR_UNSIGNED__`. The pin is L3-gcc2952psx-as286 (docs/ops/compiler-pin.md ## Pin,
  docs/ops/toolchain.md). Never use another compiler, flag or `#pragma`.
- Includes: use `#include "types.h"` (include/types.h). A signed byte is `signed char`. Use `include/include_asm.h`
  only for INCLUDE_ASM of bodies not yet drafted. Grow types one proven field at a time (G62). Write no speculative
  struct.
- Dest: the file is `src/<alias>/<name>.c` (the card's Dest file). Take the declarations from the card (dest decls,
  callee consensus).
- Twin in X6: when the card names one, seed from that C (`refs/mmx6/`) and rename by the card's map. Keep X5's types,
  and spell X6's plain `char` as `u8`/`s8`. It is adapted AGPL-3.0 code (THIRD_PARTY.md). `try` decides, not the lead.
- Try loop: run `PY tools/wave/waves.py try <draft.c> --target <alias>_<name>` only. Never run `make` in the tree.
  `try: <name> match` means done. `diff <d> of <w> words` means iterate. Exit 2 means a compile error.
- Cap: 30 tries per target, counted from `.run/wave/try/<alias>_<name>.jsonl`. Then stop and report the best diff.
- No asm paste: use no `__asm__` bodies standing in for C. Put no pasted disassembly in drafts, cards, logs or commits
  (G12).
- If you are stuck on a diff, read docs/codegen-map/SYMPTOMS.md (symptom -> cookbook entry -> lever). Refer to levers
  by id only.
