# tools/dedup

`shapes.py check | --selftest` (`make types-check`) is the type check over our own C (see the module docstring).
If a concurrent writer deletes a globbed file before the type check reads it, the type check skips the file. That is
not fatal.

## Supported C subset (anything else in a declaration it parses is refused, file:line, G28)
- The type check scans `include/*.h` and `src/**/*.c` (so `src/shared/`). It scans each file once. It ignores `#`
  lines and comments.
- It parses these statements: `typedef <type> <declarator>;`, `typedef struct|union [tag] { ... } Name;`,
  `struct|union tag { ... };`. It skips everything else (only the raw-cast scan reads it).
- The types are `[signed|unsigned] char|short|int|long`, `void`, earlier typedef names and `struct|union tag`. Plain
  `char` counts as `unsigned char` (`-D__CHAR_UNSIGNED__`).
- A declarator has the form `*`... name `[N]`..., and one member line can hold several with `,`. `N` is an integer
  expression of literals.
- The type check refuses these as unsupported: nested or anonymous inline records in a body, bitfields and
  function-pointer declarators. It also refuses typedefs of a record with more than one name, anonymous records
  outside a typedef and unknown type names.
- A raw cast is `(T *)` followed (through any `(`) by a nonzero integer literal. The type check allows `(T *)0` and
  `T *p = 0;`.
- A struct member whose leading `/* 0xNN */` comment differs from its computed offset is refused (2.8 T14).
- The sizes are char 1, short 2 and int/long/pointer 4. The alignment is natural. The type check pads the struct size
  to its alignment.

The fixtures (`fixtures/{clean,dup,cast}`) are synthetic C written for the selftest, not game-derived.

## carve.py (the carve chain, C0027)
`carve.py plan|apply|revert <alias> <vram> [--name N] [--module M] [--body FILE]`, `own [<alias>]`, `sample [--per N]`,
`--selftest`.
- The carve chain decides rodata ownership by gaps (T3, phase 3.x). A region is a rodata|textbin|rodatabin subsegment
  ahead of the code segment's first asm/c subsegment. A label is a region address that text references
  (%hi/%lo/%gp_rel, jtbl_). A range goes from a label to the next label or the region end. A range is owned
  (1 referencing function), shared (2+) or unreferenced. References outside the own regions (resident, other binary,
  .data, tail textbin) are externs.
- `own` prints `carve: rodata <alias> owned <o> shared <s> unreferenced <u>
  ranges; owners <f> fns`.
- plan prints the cut(s) that it would write, or `carve: refused <reason>` (exit 1). The reasons are not-found,
  ambiguous, outside-asm, rodata-shared, jump-table and c-exists. If the reason is ambiguous (rockx5 same-vram
  overlays), pass `--module ovlNN` (C0019). The reason rodata-shared is a region reference into a shared range or a
  non-contiguous span, jtbl included. The reason jump-table is `jtbl_` resolving to no own region, or `jlabel` without
  a jtbl reference. The extent is `nonmatching <name>, <size>` of the split asm (asm/<alias>/*.s + nonmatchings/).
- apply makes line edits to `config/splat.<alias>.yaml` only (G43). The edits are
  `[rom, c, <name>]` + remainder `[end, asm,
  game_<VRAM>|ovlNN_<VRAM>]`, and each ends with `# carve`. A replaced line keeps its text after `# carve was: `. The
  command writes `src/<alias>/<name>.c`: `INCLUDE_ASM("asm/<alias>/nonmatchings/<name>", <name>)` or the `--body` text.
- owner apply also splits the region: `[a, .rodata, <name>]  # carve` and the remainder `[b, rodata, <B>]` /
  `[b, rodatabin]`. The .rodata line pairs with the c subsegment: splat migrate_rodata_to_functions writes the span
  into the INCLUDE_ASM .s, so its .c.o(.rodata) links there. The command retypes a textbin head before `a` to
  `rodatabin` (`# carve was:`), because .rodata links ahead of .text. The script tools/build/rockx5_splits.py keeps
  `# carve` lines inside its header range.
  - A span that ends in a `jtbl_` range ends pad-free (T17). Its end is label + 4*n. Here n = consecutive words that
    are addresses in the function (bytes from the yaml target_path). The alignment pad goes to the remainder.
- revert restores the lines and deletes the C file. The yaml is byte-identical (newest carve first within a
  subsegment).
- sample works in the worktree `.run/carve/wt-<pid>`. It symlinks the ignored inputs (extracted, refs, .venv, expected,
  tools/bin) and removes the links before it removes the worktree. It takes every k-th plannable game-lane asm
  inventory function per alias (k = plannable / N, N = 50). It applies all and runs `make split build`. The build logs
  are `.run/carve/<alias>.build.log`. It needs a post-`make check` tree.
- Each process has its own worktree (`make_wt()` default `.run/carve/wt-<pid>`, or the caller's path). Each caller
  removes only its own worktree (`drop_wt`, try/finally). `git worktree prune` drops only entries whose directory is
  gone.
- The INCLUDE_ASM path (include/include_asm.h) uses `.include "macro.inc"` via CC_ASFLAGS `-I asm/$(BINARY)/include`,
  with noat/noreorder around the body. The file mk/slus.mk assembles `nonmatchings/` only through their .c.
- 2026-10-05: sample 102 of 102 carves build (51 slus, 51 rockx5), refused rodata 2467, jump-table 161. The run took
  ~1 min.

The fixture `fixtures/carve/` (yaml + asm) is hand-written and has no game bytes.

## draw.py (the draw filter)
`draw.py [--selftest]` writes `.run/dedup/draw.jsonl`. Each row is
`{alias,module,name,vram,insns,verdict,reason,rank,reach[,detail]}`.
- The inputs are `.run/census/inventory.jsonl`, `groups.jsonl` (census dup), `.run/sig/twins.jsonl` (sig band), carve
  `plan` in-process (rockx5 passes the yaml segment as module, C0019) and `config/dedup.exclude.yaml`. Refresh them
  first.
- Each refused function has one reason, the first match in this list:
  - vendor (libobj|libgap)
  - excluded-module (inventory.excluded module or census load() miss)
  - already-c (status c / plan c-exists)
  - exclude-list
  - uncarveable (`detail` = plan refusal)
  - dup-member. In a dup group with a C member, this is all others. In any other dup group, this is all but the first
    (alias, vram, name) not refused above.
- reach = |dup u family (insns >= census.FAMILY_MIN_INSNS) u own sig cluster u near-linked sig clusters (near links
  only between functions >= the floor)|. The draw filter ranks the drawable functions by reach x insns desc. It breaks
  a tie by alias, vram, name.
- The draw filter prints `draw: <d> of <m> drawable, <r> refused`, six `draw: refused <reason> <c>` and
  `draw: uncarveable <detail> <c>`. If d + r != m, the exit is 1. It re-probes the exclude entries first. For a stale
  entry (`reprobe` exits 0), it prints `draw: stale exclude
  <alias> <vram> <reason>`, exits 1 and writes nothing. The header of `config/dedup.exclude.yaml` gives the format.
- 2026-10-05: 2883 of 7905 drawable, 5022 refused (vendor 477, excluded-module 0, already-c 5, exclude-list 0,
  uncarveable 2628 = rodata 2467 + jump-table 161, dup-member 1912).

The fixture `fixtures/draw/` (rows json, exclude yamls) is synthetic. For uncarveable, it plans against
`fixtures/carve/`.

## reconcile.py (the reconcile ladder)
`reconcile.py r1|bank <alias> <vram> --body src/shared/<f>.c [--module M] [--def K=V]...`,
`reconcile.py verify <alias> <vram> [--module M]`, `--selftest`.
- The generated member text has a comment, `#include "types.h"`, `#define DEDUP_NAME <name>` (carve plan's name), one
  `#define K V` per `--def`, r3's externs and `#include "../shared/<f>.c"`.
- r1 compiles the member standalone at `.run/reconcile/r1/src/<alias>/` (`src/shared` symlinked to the body's
  directory), with the pin `L3-gcc2952psx-as286`. It does a masked compare with `probe.target_bytes`. If the compare
  is equal, it writes `.run/reconcile/<alias>_<VRAM>.json` `{alias,vram,module,name,body,body_hash}`. With a module,
  the record is `<alias>_<VRAM>_<module, / -> _>.json` (same-vram overlay members, T7.c1). The tool still reads a
  legacy unsuffixed record of the same module. The body hash = sha1 of the text inside the body's outermost braces,
  with whitespace runs collapsed.
- bank refuses without the record or on a changed body hash (a redraft: rerun r1). The rungs follow, and bank probes
  each rung first:
  - r2: carve.apply with the member text.
  - r3: cc1 `-Wimplicit` (no `-w`). For each implicitly declared X, r3 puts an extern before the body include. The
    extern is a `src/**` C definition's signature. Otherwise it is `extern int X();` for `type:func` in
    config/symbols.<alias|slus>.txt or a splat `func_<8hex>`. Otherwise r3 is FAIL.
  - r4: a masked compare of the carved TU (no cast automation: a differing word is FAIL).
  - r5: `make build/<a>/src/<a>/<name>.o` vs target.
  - r6: `make split build` (SHA), with the log `.run/reconcile/<alias>.build.log`.
- r4-r6 are checks: a green check prints `not needed`. After any FAIL, bank runs `carve.revert` and exits 1. If a
  function is already carved, bank refuses it (`c-exists`). Revert it first.
- 2026-10-05: rockx5 func_800EFE70_ovl02 banked at r3 (`extern int func_8002D760();`), body
  61eab971c61175520b1a1cd2d55026b79e065d70.
- verify checks a banked member again (tools-health rung 12 runs `verify rockx5 800EFE70 --module ovl02`). It does
  these checks:
  - It reads the r1 record. If the record is missing, it exits 1 and names the record.
  - The body hash == the record.
  - The yaml `c` cut and `src/<alias>/<name>.c` including the body are present.
  - r1, re-run standalone on the current member file text (`.run/reconcile/verify/`), is masked equal.
  - The r5 object is masked equal.
- In verify, if the member file carries externs, the rung is r3. Otherwise the rung is r2. The last line of verify is
  `reconcile: <name> banked at rung <r>, body unchanged`. On any mismatch, verify prints
  `reconcile: FAIL <alias> <vram> -- <why>` and exits 1.

The fixture `fixtures/reconcile/` (body, callee, target C) is hand-written. It runs over `fixtures/carve/`, with the
scratch `.run/reconcile/selftest`. The selftest does not run r6 there. The selftest also verifies the banked fixture,
and its mutated body must fail verify.

## propagate.py (propagation and the dedup registry)
`propagate.py run src/shared/<rep>.c [--dry-run]`, `check`, `sweep [--dry-run] [--binary <alias>]`, `--selftest`.
- The members, keyed (alias, name) (C0019), are the fresh census dup group (`census.load` + `census.group` in-process)
  with the body's signature, unioned with sig.py's exact cluster. The signature = sha1 hex of `dup_key` words (LE u32).
  The body's signature = that of the function named by its stem.
- Byte twins in place (`twin()`) are members. A masked-only member M can be reloc-gated. `relocs()` (on x4core.Elf)
  reads the relocations of the rep's `build/<a>/src/<a>/<name>.o` and of M's asm `build/<a>/asm/<a>/<file>.o`.
- The reloc gate has five conditions. Slot by slot, the reloc types and in-place addends (C0039) agree.
  The map sym_R -> sym_M is a function. Every sym_M is in M's own object (`_ovlNN` = M's overlay, no suffix = main exe).
  No renamed sym_R is a struct field, param or local in the body. Raw words are equal outside relocated fields.
- A reloc-gated member text gets `#define sym_R sym_M` per differing symbol. Otherwise run refuses the member
  (`dedup: FAIL ...`, exit code unchanged). run prints `dedup: <m> masked-only: <a> reloc-gated, <k> refused`.
- run compiles `reconcile.member_text` per member in `.run/dedup/propagate/cc` and masked-compares it with the target.
  The member text carries DEDUP_NAME, `DEDUP_CALLEE` and the r3 externs. `DEDUP_CALLEE` = the member's single asm `jal`
  target when the body uses it. The command carves the passing members (`carve.apply`). It runs
  `make split build BINARY=<a>` per touched binary (log `.run/dedup/propagate/<a>.build.log`). A member already carved
  whose C file includes the body is gated as is.
- run is fail-closed: it does not carve a failing member (an SHA fail reverts all the binary's new carves). If a
  member fails, it prints `dedup: FAIL <alias> <name> -- <why>` and exits 1. Gated members go to `config/dedup.us.yaml` by line inserts
  (DK-77). The last line is `dedup: <g> of <n> members byte-gated`.
- `--dry-run` does the same in `.run/carve/wt-<pid>` (carve.make_wt, with the body + registry copied in). It leaves
  the main tree untouched.
- check: unregistered = a member of a dup group holding a yaml `c` cut, missing from the registry. Ungated = a registry
  member without its `c` cut or a C file including the body. On either, the exit is 1. Otherwise check prints
  `dedup: registry OK (<g> groups, <n> members, 0 unregistered, 0 ungated)`. Harness p8 cross-checks the registry.
- Before that line, check prints `dedup: <g> of <n> members byte-gated (<body stem>)` per registry group. Here,
  byte-gated = the yaml `c` cut + a C file including the body. The whole-binary SHA itself is tools-health rung 0
  (`build/<a>.check.rc`), so the line is byte-gated only on a tree whose `make check` is green.
- A registry entry has `- group: <sig>`, `body: src/shared/<f>.c` and `members:` lines
  `- {alias, module (inventory), vram, name}`.

### sweep --dry-run (T2)
- First the reloc control (`fixtures/propagate/reloc`, scratch `.run/dedup/propagate/sweep_control`) runs
  in-process. It prints `dedup: sweep control refused fx func_80001120 -- foreign-object target ...`. If the planted
  member is not refused, it prints `dedup: sweep control FAIL` and exits 1.
- The targets are the masked-only members of every dup group with a C-banked member, as check() counts them
  (`banked_groups()`). A group's rep is its registered body, else `src/shared/<name>.c` of a banked member. Otherwise
  the rep is made from the first banked member's C file, as gate.py rescan does (`rep_text`/`rep_callee`, now here).
- All the work happens in one scratch worktree (carve.make_wt), which is dropped at the end. The main tree is not
  touched. Per rep the sweep runs `run(build=False)`: the members() reloc gate, gate() compile + word compare and
  carve.apply. Then each binary is built once (`make split` + `make -j build`), one binary at a time, with all the
  reps' carves. A red build is bisected by rep (gate.bisect). The members of a losing rep are refused `sha`.
- The sweep builds slus first and freezes its green set. Then it bisects rockx5, whose build links slus
  (mk/rockx5.mk:41, C0148).
- Output: one line per member, `dedup: sweep <alias> <name> gated|refused <why>`. Then `dedup: sweep refused <count>
  <reason-class>` per class, `dedup: sweep <c> of <F> gated members already C`, and the last line
  `dedup: sweep <F> of <n> masked-only members byte-gated, <r> refused`. Build logs are
  `.run/dedup/propagate/sweep.<a>.<k>.build.log`.
- gate.py rescan now filters open members through `propagate.members()`, so reloc-gated members are kept.

### sweep (wet, T3)
- `propagate.py sweep [--binary <alias>]`: the same pipeline in the main tree, no worktree. The green set's carves
  stay. A losing rep's carves are reverted and its members print `dedup: sweep <alias> <name> refused sha: ...`.
- Each rep's gated members (and the rep, when its C file includes the body) are registered in
  `config/dedup.us.yaml` with `register()` (line inserts). A body made for a rep none of whose members ends gated is
  removed.
- `--binary <alias>` carves, builds and registers only that alias's members. Reps from any binary still serve (an
  out-of-scope rep keeps its own C file). Run slus first, then rockx5 (the rockx5 build links slus). The final
  tree is not rebuilt by the sweep, so run `make split build BINARY=<a>` after, then commit.

The fixture `fixtures/propagate/` (yaml + asm, 4 members, hand-written) uses reconcile's body/callee/target C.
The fixture `fixtures/propagate/reloc/` (body + one C object: rep, renamed member, foreign-overlay member) drives
reloc gating. The scratch is `.run/dedup/propagate/selftest`. There is no build there.

## Health (mk/tools-health.mk)
`make tools-selftest` runs every tool's `--selftest` (types, carve, draw, reconcile, propagate's line is `dedup: control
OK`). CI runs it in the compile-only job (reconcile/propagate compile fixture C with the pin). `make check` ends with
`make tools-health`. Its rungs are types check, `carve.py sample --per 5` (background, ~30 s fixed split+build cost),
`draw.py`, `propagate.py check` and `reconcile.py verify ...`. `make tools-health-full` samples carve at the default
--per.
