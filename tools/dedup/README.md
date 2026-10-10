# tools/dedup

`shapes.py check | --selftest` (`make types-check`): the type check over our own C (see the module docstring).
A file globbed but deleted before it is read (a concurrent writer) is skipped, not fatal.

## Supported C subset (anything else in a declaration it parses is refused, file:line, G28)
- Scanned: `include/*.h`, `src/**/*.c` (so `src/shared/`). Each file once; `#` lines and comments ignored.
- Parsed statements: `typedef <type> <declarator>;`, `typedef struct|union [tag] { ... } Name;`,
  `struct|union tag { ... };`. Everything else is skipped (only the raw-cast scan reads it).
- Types: `[signed|unsigned] char|short|int|long`, `void`, earlier typedef names, `struct|union tag`. Plain `char`
  counts as `unsigned char` (`-D__CHAR_UNSIGNED__`).
- Declarators: `*`... name `[N]`..., several per member line with `,`; `N` an integer expression of literals.
- Refused as unsupported: nested or anonymous inline records in a body, bitfields, function-pointer declarators,
  typedefs of a record with more than one name, anonymous records outside a typedef, unknown type names.
- Raw cast: `(T *)` followed (through any `(`) by a nonzero integer literal. `(T *)0` and `T *p = 0;` are allowed.
- Sizes: char 1, short 2, int/long/pointer 4; natural alignment; struct size padded to its alignment.

Fixtures (`fixtures/{clean,dup,cast}`) are synthetic C written for the selftest, not game-derived.

## carve.py (the carve chain, C0027)
`carve.py plan|apply|revert <alias> <vram> [--name N] [--module M] [--body FILE]`, `own [<alias>]`, `sample [--per N]`,
`--selftest`.
- rodata ownership by gaps (T3, phase 3.x): region = rodata|textbin|rodatabin sub ahead of the code segment's first
  asm/c sub; label = region address referenced from text (%hi/%lo/%gp_rel, jtbl_); range = label .. next label or
  region end; owned (1 referencing fn) / shared (2+) / unreferenced. Refs outside the own regions (resident, other
  binary, .data, tail textbin) are externs. `own` prints `carve: rodata <alias> owned <o> shared <s> unreferenced <u>
  ranges; owners <f> fns`.
- plan: the cut(s) it would write, or `carve: refused <reason>` (exit 1): not-found, ambiguous (rockx5 same-vram
  overlays: pass `--module ovlNN`, C0019), outside-asm, rodata-shared (region ref into a shared range or a
  non-contiguous span, jtbl included), jump-table (`jtbl_` resolving to no own region, or `jlabel` without a jtbl
  ref), c-exists. Extent = `nonmatching <name>, <size>` of the split asm (asm/<alias>/*.s + nonmatchings/).
- apply: line edits to `config/splat.<alias>.yaml` only (G43): `[rom, c, <name>]` + remainder `[end, asm,
  game_<VRAM>|ovlNN_<VRAM>]`, each ending `# carve`; a replaced line keeps its text after `# carve was: `. Writes
  `src/<alias>/<name>.c`: `INCLUDE_ASM("asm/<alias>/nonmatchings/<name>", <name>)` or the `--body` text.
- owner apply also splits the region: `[a, .rodata, <name>]  # carve` (pairs with the c sub: splat
  migrate_rodata_to_functions writes the span into the INCLUDE_ASM .s, so its .c.o(.rodata) links there), remainder
  `[b, rodata, <B>]` / `[b, rodatabin]`; a textbin head before `a` is retyped `rodatabin` (`# carve was:`), since
  .rodata links ahead of .text. tools/build/rockx5_splits.py keeps `# carve` lines inside its header range.
  Span ending in a `jtbl_` range ends pad-free (T17): label + 4*n, n = consecutive words that are addresses in the fn
  (bytes from the yaml target_path); the alignment pad goes to the remainder.
- revert: restores the lines, deletes the C file; the yaml is byte-identical (newest carve first within a subsegment).
- sample: worktree `.run/carve/wt-<pid>` (ignored inputs symlinked: extracted, refs, .venv, expected, tools/bin; links
  removed before the worktree is), every k-th plannable game-lane asm inventory function per alias (k = plannable / N,
  N = 50), apply all, `make split build`; build logs `.run/carve/<alias>.build.log`. Needs a post-`make check` tree.
- worktree per process (`make_wt()` default `.run/carve/wt-<pid>`, or the caller's path); each caller removes only its own (`drop_wt`, try/finally); `git worktree prune` drops only entries whose dir is gone.
- INCLUDE_ASM path (include/include_asm.h): `.include "macro.inc"` via CC_ASFLAGS `-I asm/$(BINARY)/include`,
  noat/noreorder around the body; mk/slus.mk assembles `nonmatchings/` only through their .c.
- 2026-10-05: sample 102 of 102 carves build (51 slus, 51 rockx5), refused rodata 2467, jump-table 161; ~1 min.
Fixture `fixtures/carve/` (yaml + asm) is hand-written, no game bytes.

## draw.py (the draw filter)
`draw.py [--selftest]` -> `.run/dedup/draw.jsonl` `{alias,module,name,vram,insns,verdict,reason,rank,reach[,detail]}`.
- Inputs: `.run/census/inventory.jsonl`, `groups.jsonl` (census dup), `.run/sig/twins.jsonl` (sig band), carve `plan`
  in-process (rockx5 passes the yaml segment as module, C0019), `config/dedup.exclude.yaml`. Refresh them first.
- One reason per refused fn, first match: vendor (libobj|libgap), excluded-module (inventory.excluded module or census
  load() miss), already-c (status c / plan c-exists), exclude-list, uncarveable (`detail` = plan refusal), dup-member
  (dup group with a C member: all others; else all but the first (alias, vram, name) not refused above).
- reach = |dup u family (insns >= census.FAMILY_MIN_INSNS) u own sig cluster u near-linked sig clusters (near links only between fns >= the floor)|; drawable
  rank by reach x insns desc, tie alias, vram, name.
- Prints `draw: <d> of <m> drawable, <r> refused`, six `draw: refused <reason> <c>`, `draw: uncarveable <detail> <c>`;
  exit 1 if d + r != m. Exclude entries re-probed first; a stale one (`reprobe` exits 0) prints `draw: stale exclude
  <alias> <vram> <reason>`, exit 1, nothing written. Format: header of `config/dedup.exclude.yaml`.
- 2026-10-05: 2883 of 7905 drawable, 5022 refused (vendor 477, excluded-module 0, already-c 5, exclude-list 0,
  uncarveable 2628 = rodata 2467 + jump-table 161, dup-member 1912).
Fixture `fixtures/draw/` (rows json, exclude yamls) is synthetic; uncarveable plans against `fixtures/carve/`.

## reconcile.py (the reconcile ladder)
`reconcile.py r1|bank <alias> <vram> --body src/shared/<f>.c [--module M] [--def K=V]...`,
`reconcile.py verify <alias> <vram> [--module M]`, `--selftest`.
- Member text (generated): comment, `#include "types.h"`, `#define DEDUP_NAME <name>` (carve plan's name), one
  `#define K V` per `--def`, r3's externs, `#include "../shared/<f>.c"`.
- r1: member compiled standalone at `.run/reconcile/r1/src/<alias>/` (`src/shared` symlinked to the body's dir), pin
  `L3-gcc2952psx-as286`, masked compare with `probe.target_bytes`; equal -> `.run/reconcile/<alias>_<VRAM>.json`
  `{alias,vram,module,name,body,body_hash}`; with a module the record is `<alias>_<VRAM>_<module, / -> _>.json`
  (same-vram overlay members, T7.c1; a legacy unsuffixed record of the same module is still read). Body hash = sha1 of the text inside the body's outermost braces,
  whitespace runs collapsed.
- bank: refused without the record or on a changed body hash (a redraft: rerun r1). Rungs, each probed first:
  r2 carve.apply with the member text; r3 cc1 `-Wimplicit` (no `-w`), per implicitly declared X an extern before the
  body include: a `src/**` C definition's signature, else `extern int X();` for `type:func` in
  config/symbols.<alias|slus>.txt or a splat `func_<8hex>`, else FAIL; r4 masked compare of the carved TU (no cast
  automation: a differing word is FAIL); r5 `make build/<a>/src/<a>/<name>.o` vs target; r6 `make split build`
  (SHA), log `.run/reconcile/<alias>.build.log`. r4-r6 are checks: green prints `not needed`. Any FAIL ->
  `carve.revert`, exit 1. Already-carved functions are refused (`c-exists`): revert first.
- 2026-10-05: rockx5 func_800EFE70_ovl02 banked at r3 (extern int func_8002D760();), body
  61eab971c61175520b1a1cd2d55026b79e065d70.
- verify (a banked member re-checked; tools-health rung 12 runs `verify rockx5 800EFE70 --module ovl02`): reads the r1
  record (missing -> exit 1 naming it); body hash == record; the yaml `c` cut and `src/<alias>/<name>.c` including the
  body present; r1 re-run standalone on the current member file text (`.run/reconcile/verify/`), masked equal; r5 object
  masked equal. Rung = r3 if the member file carries externs, else r2. Last line
  `reconcile: <name> banked at rung <r>, body unchanged`; any mismatch `reconcile: FAIL <alias> <vram> -- <why>`, exit 1.
Fixture `fixtures/reconcile/` (body, callee, target C) is hand-written; it runs over `fixtures/carve/`, scratch
`.run/reconcile/selftest`; r6 is not run there. The selftest also verifies the banked fixture, and its mutated body
must fail verify.

## propagate.py (propagation and the dedup registry)
`propagate.py run src/shared/<rep>.c [--dry-run]`, `check`, `--selftest`.
- Members, keyed (alias, name) (C0019): fresh census dup group (`census.load` + `census.group` in-process) with the
  body's signature, unioned with sig.py's exact cluster. Signature = sha1 hex of `dup_key` words (LE u32); the body's
  = that of the function named by its stem.
- run: per member, `reconcile.member_text` (DEDUP_NAME; `DEDUP_CALLEE` = the member's single asm `jal` target when the
  body uses it; r3 externs) compiled in `.run/dedup/propagate/cc` and masked-compared with the target; passing members
  carved (`carve.apply`), `make split build BINARY=<a>` per touched binary (log `.run/dedup/propagate/<a>.build.log`).
  A member already carved whose C file includes the body is gated as is. Fail-closed: a failing member is not carved
  (an SHA fail reverts all the binary's new carves), `dedup: FAIL <alias> <name> -- <why>`, exit 1. Gated members go
  to `config/dedup.us.yaml` by line inserts (DK-77). Last line `dedup: <g> of <n> members byte-gated`.
- `--dry-run`: the same in `.run/carve/wt-<pid>` (carve.make_wt; body + registry copied in); main tree untouched.
- check: unregistered = a member of a dup group holding a yaml `c` cut, missing from the registry; ungated = a registry
  member without its `c` cut or a C file including the body. Exit 1 on either; else
  `dedup: registry OK (<g> groups, <n> members, 0 unregistered, 0 ungated)`. Harness p8 cross-checks the registry.
  Before it, per registry group `dedup: <g> of <n> members byte-gated (<body stem>)`: byte-gated here = the yaml `c`
  cut + a C file including the body; the whole-binary SHA itself is tools-health rung 0 (`build/<a>.check.rc`), so
  the line is byte-gated only on a tree whose `make check` is green.
- Registry entry: `- group: <sig>`, `body: src/shared/<f>.c`, `members:` lines `- {alias, module (inventory), vram, name}`.
Fixture `fixtures/propagate/` (yaml + asm, 4 members, hand-written) with reconcile's body/callee/target C; scratch
`.run/dedup/propagate/selftest`; no build there.

## Health (mk/tools-health.mk)
`make tools-selftest` runs every tool's `--selftest` (types, carve, draw, reconcile, propagate's line is `dedup: control
OK`); CI runs it in the compile-only job (reconcile/propagate compile fixture C with the pin). `make check` ends with
`make tools-health`: rungs types check, `carve.py sample --per 5` (background, ~30 s fixed split+build cost),
`draw.py`, `propagate.py check`, `reconcile.py verify ...`; `make tools-health-full` samples carve at the default --per.
