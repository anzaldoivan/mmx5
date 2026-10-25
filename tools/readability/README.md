# tools/readability

`scan.py` is the readability scan over our own C (stdlib + tools/dedup/shapes.py).

    make readability-check          # = $(PY) tools/readability/scan.py
    PY tools/readability/scan.py --selftest
    PY tools/readability/lift.py    # src/**/*.c struct/union defs -> include/types.h `lift:` block. It prints `lift: <n> moves, <d> deduplicated`

The scope is src/**/*.c, src/**/*.h, include/*.h and config/symbols.*.txt. The basis rows come from
config/names.tsv (NAME1's columns). If the file is absent, every non-placeholder name is unbased.

Classes:
- `pin` is `register ... asm("$..")` / `__asm__("$..")` without `// !FAKE:` on the same or previous line.
- `macro` is a `#define` whose replacement list has `{` or `;`, or a `\` continuation. Params (`#define K V`) and
  expression accessors are not bodies. The file include/include_asm.h (splat's INCLUDE_ASM/INCLUDE_RODATA build
  mechanism) is exempt from this class only.
- `cast` is an integer literal (nonzero) cast to a pointer, e.g. `(*(u8**)0x1F800000)`, anywhere except
  include/addr.h. The scan strips comments and counts `#define` lines.
- `duplicate` is a duplicate struct shape or a second definition, as `shapes.py` refuses it (imported, not re-parsed).
- `struct` is a struct/union definition (`{`) outside include/.
- `name` is a non-placeholder name in config/symbols.<alias>.txt without an (alias, name) basis row. A non-placeholder
  function defined in src/**/*.c without a basis row for that name is also a `name`. A placeholder matches
  `^(func|inl|D|L|jtbl|sub)_[0-9A-Fa-f]{8}(_\w+)?$`. The scan skips `DEDUP_NAME` (named by the includer).

The output is one `readability: <kind> <file>:<line>: <detail>` per offender, then
`readability: <p> unmarked pins, <m> macro bodies, <c> raw casts, <d> duplicate shapes, <s> stray structs, <u> unbased names`.
If any count > 0, the exit is 1.

`--selftest`: fixtures/ (game-free, hand-written) is a mini tree. It has one planted file per class (src/pin.c,
src/macro.c, src/cast.c, include/dup.h, src/stray.c, src/names.c + config/symbols.fix.txt). It has src/control.c,
include/ctl.h and include/addr.h as clean controls. Each planted file must be refused with exactly its class and the
controls not at all. `--selftest` prints `readability: control OK -- 6 planted offenders refused`, else
`readability: selftest FAIL ...` and exit 1.

## names.tsv

`config/names.tsv` (NAME1's columns, `rules/NAME1.md`) holds the evidence behind each non-placeholder name that the
`name` class checks. A row that is not `rejected` bases its name: symbols match on (`image`, `new_name`), src/ on
`new_name` alone. `evidence` is `<class>:<path>:<line>`.

The one-shot seed of phase 1.10 wrote the earlier `config/names.basis.tsv`. Its 2088 rows became rows of
`config/names.tsv`, and the seed was removed on 2026-10-14 (git history keeps it). New names get rows by hand, or by
`python3 tools/psxd_img.py promote`.
