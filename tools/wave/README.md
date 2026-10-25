# tools/wave

The command is `PY tools/wave/waves.py <cmd>`. The tool uses the stdlib. The doc header of waves.py is the spec.
LAWS.md holds the drafter rules. The health checks are tools-selftest and the tools-health rungs
wave/ledger/harvest/routing (mk/tools-health.mk).

- `draw W<k> [--per 6] [--buckets 20,50,100,200]` -> `waves/W<k>/wave.json`. The command prints `wave: W<k> drew <n> targets,
  <i> invalid` and `lane: <lane> <count>` (sums to draw.jsonl rows). The command does not refresh the inputs.
  Run census/sig/draw first. The command refuses stale inputs (older than the last commit to src or
  config/splat.*). The command never overwrites a wave.

  `--order leverage --size N` (R2, default `strata`) uses one pool by reach desc, insns desc, (alias, vram).
  It skips rows whose bucket routes `defer` in docs/routing.md. It takes `draft-twin` rows only with a banked twin
  or a matched lever. The draw holds >= 3 slus and >= 2 rockx5 among N. The wave.json and the output are the same
  as with the default order. The selftest plants a defer-bucket row, and the command does not draw that row.

  A row with an X6 lead (below) also qualifies for `draft-twin`.

  `--order port-x6 --size N` is the same pool with the rows that have an X6 lead first. A lead row is drawn whatever
  its bucket's route. One target per cluster: the gate's `rescan` banks its exact twins (the other members of the
  X6 class) from the representative. The selftest plants a lead in a `defer` bucket, and the draw takes it first.

  Every order skips the `ledger.py` targets (tried, not banked, not c) as invalid `ledgered`.
  The `--only A,B` option (leverage/port-x6 only) keeps pool rows in the named buckets. When that pool cannot fill N,
  the draw drops the NEED floor and takes the whole valid pool. It prints
  `wave: pool exhausted, drew <n> of --size <N>` (n == 0: nothing written, exit 1). Without `--only` a short pool is still refused.
- `open [--check] [--buckets 20,50,100,200] <L,L,...>` prints per bucket `open: <L> <o> open, <d> drawable,
  <l> ledgered[, <u> unranked]` (d = draw.jsonl `draw` rows, l = ledgered, o = d - l, u = open rows without a rank,
  printed when > 0). Stale inputs are refused as in `draw`. `--check` exits 1 when any named bucket has o > 0.
- `card W<k>` -> `.run/wave/W<k>/packs/<alias>_<name>/{card.md, target.s}`. The command refuses unresolved
  lever/C ids (G44).
  `## Twin in X6` comes from `docs/oracle/x6-leads.tsv` (`tools/sig/imgtab.py x6 --leads`, tools/sig/README.md),
  joined on alias, unit and vram. It names the X6 function, its C file under `refs/mmx6/` (the `mmx6` row of
  `config/refs.toml`) and the map X6 name -> X5 name. It says to keep X5's types and to
  spell X6's plain `char` (`-funsigned-char`) as `u8`/`s8`. The section is `none` without a lead.
- `try <draft.c> --target <alias>_<name>` -> `try: <name> match | diff <d> of <w> words | error <stage>`, exit 0/1/2.
  The log is `.run/wave/try/<alias>_<name>.jsonl`. The scratch is `.run/probe/wave/<alias>_<name>/`. An error adds
  the stage's first stderr lines (cc1 errors). A diff adds `try:   differing word offsets: +0x..` (offsets only, no
  bytes).
- `port W<k> [--target <alias>_<name>] [--waves DIR]` ports each wave.json target's X6 lead (`docs/oracle/x6-leads.tsv`)
  from `refs/mmx6/<path>` and compiles/compares it through try's path. Per target, the line is
  `port: <alias>_<name> match | diff <d> of <w> words | error <stage> | no-lead`. The result `error map` means a map
  name or the lead function is absent from the X6 file. The result `error symbol <name>` means an X6 data symbol
  (`D_<addr>`, maybe `+ N`) has no X5 name. Nothing is written then. The last line is
  `port: W<k> <m> of <n> leads matched`, exit 0.

  A missing wave.json is refused (exit 1). A `refs/mmx6` HEAD that is
  not config/refs.toml's mmx6 `ref` is refused (exit 1). A match goes to `DIR/W<k>/drafts/<alias>_<name>.c` (DIR
  default `waves/`). A non-match seeds the drafter at `.run/wave/W<k>/port/<alias>_<name>.c`.

  The transform is `port_text`:
  - line 1 is the attribution (`Adapted from mmx6 @<pin7> <path>`). The X6 file's sozud/mmx4 line stays.
  - `common.h` becomes `types.h`. The `mmx6/x4.h` and `mmx6/psyq_api.h` includes go.
  - The draft declares what the body references from those headers and `mmx6/types.h`. Names that X5's
    `include/types.h` defines are skipped.
  - No struct, union or aggregate typedef is emitted. Each X6 aggregate maps to an `include/types.h` shape. The shape
    has the same name, else it resolves most of the member accesses. Unmapped ones become `void`.
  - A member chain keeps its spelling when X5 resolves it the same. Else it takes the X5 path at the same offset and
    type. Else it becomes `M2C_FIELD(base, T*, off)` (its `#define` is added).
  - A scratchpad cast `(*(T*)0x1F80....)` becomes its `include/addr.h` name (`#include "addr.h"` added). Another
    pointee type T casts through the name: `(*(T*)&D_<A>)`.
  - A `\` continued `#define` is joined onto one line (the readability scan refuses `\`).
  - A register pin gets a `// !FAKE:` line above it.
  - A `goto L;` gets `// !FAKE: control flow kept from the mmx6 twin` on its line (the debt gate's goto marker).
  - A function-pointer typedef (`X4_CdlCB` and kin) goes, as shapes.py refuses it. Each use spells the pointer type
    inline: `R (*name)(A)`, a function `R (*f(x))(A)`, a cast `(R (*)(A))`.
  - A scalar typedef (`typedef s32 T;`, `u8*`, `void*` and kin) goes, as shapes.py refuses its second definition across
    drafts. Each use spells the base type inline.
  - A `D_<addr>` data symbol must have an X5 name in asm/, src/ or include/. Else it takes the X5 name at the
    address that the target's HI16/LO16 pair loads (`D_<A>_<ovl>` or `D_<A>`). No such name gives `error symbol`.
  - An undeclared callee gets the card's X5 consensus prototype. Plain `char` becomes `u8`.
  - The map renames by whole word.
- `seed W<k> [--target <alias>_<name>] [--waves DIR]` is opt-in, after `port`, for no-lead targets. It writes an m2c
  first draft per wave.json target (docs/ops/decompiler.md). The asm comes from the segment file (`asm_index`), else
  from `asm/<alias>/nonmatchings/**/<name>.s`. The prepped asm goes to `.run/wave/W<k>/seed/<key>.s`, the raw m2c C to
  `<key>.c`. It never writes `waves/`.

  Per target: `seed: <key> emitted (<n> lines)` | `seed: <key> failed <why>`, exit 0. With m2c absent: `seed: m2c missing (bash tools/refs_fetch.sh m2c)`, exit 2. The seed is a draft. The coder
  keeps or discards any part. Raw m2c needs a typing pass before `try` compiles.
- `--selftest` -> `wave: control OK -- invalid target refused`, then `wave: control OK -- mmx6 lead ported (includes
  rewritten), wrong map refused`, plus `mmx6 closure rewritten to the types.h shape` and `unmapped mmx6 data symbol
  refused`, `mmx6 goto emitted marked !FAKE` `mmx6 function-pointer typedef inlined`, `raw scratchpad cast spelled through its
  addr.h name` and `mmx6 continued #define joined onto one line`, `seed asm prepped for m2c[, m2c emits it]`. The fixtures are synthetic (fixtures/, with a fake `fixtures/refs/mmx6/` tree). The
  scratch is .run/wave/selftest.
- `status W<k> [--drafts-only] [--waves DIR]` -> `wave: W<k> <d> drafts = <b> banked + <f> failed + <n> no-verdict`.
  The exit is 1 when the counts are unequal or a draft has no verdicts.jsonl row.
  `--drafts-only` -> `wave: W<k> <n> of <m> targets drafted`.
  `status [--waves DIR]` (W<k> omitted) covers every `waves/W<k>/` (k ascending). It prints one `wave: W<k> ...` line
  for each wave. The exit is 1 if any wave fails or there is no wave.
- `rate W<k> [--check]` -> `waves/W<k>/rate.txt` (also printed). Per bucket, the line is `rate: <bucket> <bi> of <ai> insns banked,
  <bh> of <ah> heads, <c> k ctx per banked insn`. The value c = ctx_k of all bucket targets / bi. The order is A..D,
  then `>200`. A `>200` with 0 heads drawn is `rate: >200 unmeasured, 0 of 0 heads` instead.

  `--check` -> `routing: <r> of <m> buckets routed`. The check is against the docs/routing.md lines
  `route: <bucket> <draft|draft-twin|defer> cap <N> tries`. Each route must equal R3: >= 50% draft, 20-50%
  draft-twin, < 20% defer. A measured `>200` is checked the same, but an unmeasured one needs a
  `route: >200 ... unmeasured` line. The exit is 1 on r < m or a mismatch. The selftest plants wrong routes (A and
  measured `>200`) and asserts refusal.
- `rate [--check]` (W<k> omitted, R5) gives the same lines with every wave's bucket counts summed. In these lines,
  bi of ai and bh of ah are the aggregate numerators/denominators. The command writes no rate.txt. `--check`
  routes against the aggregate. tools-health routing runs this command. There is no range argument. The sum takes
  hand-listed waves (W14, W22), and a target carried from wave to wave counts once per wave.

## gate.py

The command is `PY tools/wave/gate.py run|recover W<k> [--alias a] [--waves DIR]`. The doc header is the spec.
The gate banks a wave's drafts (`waves/W<k>/drafts/<alias>_<name>.c`) through reconcile plain mode. The steps are:

1. r1 in the main tree.
2. The r2-r5 slate in the worktree `.run/wave/wt/<alias>`.
3. The worktree SHA. On red, the gate bisects.
4. `shapes.py check` on the worktree (R4). On red, the gate bisects. The culprits get no-verdict `refused types`.
5. Adoption into the main tree.
6. One build.
7. `reconcile verify`.

`--help` lists the subcommands. The gate writes `waves/W<k>/verdicts.jsonl` (one row per draft) and ends with the
status assertion. The gate refuses a dirty src/ or config/. The gate never commits. It prints
`gate: commit <paths>`. Before that commit, run `make no-rom PY=PY` -> `no-rom: OK`.

The per-alias lock is `.run/wave/lock.<alias>`. The build logs are `.run/wave/<alias>.{wt,main}.build.log`.
`recover` retries `failed` r1 rows with extern_for decls: `recover: <p>
plumbing banked, <b> body`. `--selftest` -> `gate: control OK -- missing verdict refused`, then `gate: control OK --
raw cast refused`. A planted raw-cast slate draft gets no-verdict `refused types` (fixtures/gate).

`rescan W<k> [--waves DIR]` (R6, G46) refuses a dirty src/config. Commit the gate's banks first. The command
refreshes inventory -> census dup -> sig band (full). Then, for each `banked` row, the command lists the row's open
exact twins + dup-group members (status asm). It keeps them only when they are byte twins in place
(`propagate.twin`: raw words equal, jal targets free when the rep takes DEDUP_CALLEE). The command prints the
others as `gate: <a>_<name> <k> masked-only skipped`.

A banked function with any kept byte twin becomes a dedup rep (`src/shared/<name>.c`). Its sole callee ->
DEDUP_CALLEE when its words have one jal target and its body calls one function. Its own C file -> member text. Its
r1 record -> shared body. `propagate.py run` instantiates the rep.

The command prints `rescan: <b> banked, <t> open twins, <p> propagated`, then `gate: commit <paths>`. Here
p = propagated members, counted apart from drafted banks. Before that commit, run `make no-rom PY=PY` -> `no-rom: OK`.
On a failure, the command restores the rep's snapshot (C files, yamls, registry, r1 record), rebuilds, and exits 1.
The logs are `.run/wave/rescan.*.log`.

## ledger.py, harvest.py

The command is `PY tools/wave/ledger.py build|check [--waves DIR] [--out F]` (R7). The doc header is the spec.
`build` renders `docs/ledger.md` (generated, never hand-edited). The file has one row per non-banked verdict whose
target is still asm in `.run/census/inventory.jsonl`. The row is `{alias, name, vram, insns, wave, class, closeness, best_draft, blocker, tries, ctx_k,
date}`, and the rows are sorted (alias, vram). A target failed in several waves keeps its closest row (lowest diff,
tie → later wave).

`check` rebuilds in memory. It checks that every attempted target is `c` or has exactly one row. It checks that no
row lacks a real draft or closeness, and that the file is byte-current. It prints
`ledger: <n> rows, <u> unledgered, <d> without draft, <e> without blocker` (a row with an empty blocker is refused),
and the exit is 1 on any nonzero or stale. Targets are keyed (alias, ovl, vram), so a renamed function stays matched.
`--selftest` -> `ledger: control OK -- rumour refused` (fixtures/ledger).

`PY tools/wave/harvest.py check [W<k>] [--waves DIR]` (R8) -> `harvest: W<k> <h> of <b> banked harvested, <o> open`.
The file is `waves/W<k>/harvest.jsonl`, with one row per banked draft:
`{name, [alias], [vram], [module], idiom, rider}`. The exit is 1 unless h == b and o == 0. A
rider `inert` is open. With W<k> omitted, the command covers every `waves/W<k>/` and prints one `harvest:` line for
each. The exit is 1 if any wave fails or there is no wave (tools-health harvest).

A row with vram matches its verdict by `ledger.key` (alias, ovl, vram). So a renamed function stays harvested.
A row without vram (W2-W14) matches by alias+name.

`rider <banked.c> <stripped.c> --target <alias>_<name>` compiles both through try's path (`wave.compile_func`).
The result is `rider: <name> load-bearing` (exit 0) | `inert` (exit 1).
`--selftest` -> `harvest: control OK -- inert rider refused`.

Scratchpad/absolute addresses are named in `include/addr.h` as `D_<ADDR>` (union of views when several pointee
types). Raw constant-address casts (C0077 form) live only there.
