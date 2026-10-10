# tools/wave

`PY tools/wave/waves.py <cmd>` (stdlib; doc header of waves.py is the spec). Drafter rules: LAWS.md.
health: tools-selftest + tools-health rungs wave/ledger/harvest/routing (mk/tools-health.mk).

- `draw W<k> [--per 6] [--buckets 20,50,100,200]` -> `waves/W<k>/wave.json`; prints `wave: W<k> drew <n> targets,
  <i> invalid` and `lane: <lane> <count>` (sums to draw.jsonl rows). Inputs are not refreshed: run census/sig/draw
  first; stale inputs (older than the last commit to src or config/splat.*) are refused. Never overwrites a wave.
  `--order leverage --size N` (R2; default `strata`): one pool by reach desc, insns desc, (alias, vram); skips rows
  whose bucket routes `defer` in docs/routing.md, takes `draft-twin` rows only with a banked twin or a matched lever;
  >= 3 slus and >= 2 rockx5 among N; same wave.json and output. Selftest plants a defer-bucket row (not drawn).
- `card W<k>` -> `.run/wave/W<k>/packs/<alias>_<name>/{card.md, target.s}`; refuses unresolved lever/C ids (G44).
- `try <draft.c> --target <alias>_<name>` -> `try: <name> match | diff <d> of <w> words | error <stage>`, exit 0/1/2;
  log `.run/wave/try/<alias>_<name>.jsonl`; scratch `.run/probe/wave/<alias>_<name>/`. An error adds the stage's
  first stderr lines (cc1 errors), a diff adds `try:   differing word offsets: +0x..` (offsets only, no bytes).
- `--selftest` -> `wave: control OK -- invalid target refused` (fixtures/, synthetic, scratch .run/wave/selftest).
- `status W<k> [--drafts-only] [--waves DIR]` -> `wave: W<k> <d> drafts = <b> banked + <f> failed + <n> no-verdict`
  (exit 1 when unequal or a draft has no verdicts.jsonl row); `--drafts-only` -> `wave: W<k> <n> of <m> targets drafted`.
  `status [--waves DIR]` (W<k> omitted): every `waves/W<k>/` (k ascending), one `wave: W<k> ...` line each; exit 1 if
  any fails or no wave.
- `rate W<k> [--check]` -> `waves/W<k>/rate.txt` (also printed): per bucket `rate: <bucket> <bi> of <ai> insns banked,
  <bh> of <ah> heads, <c> k ctx per banked insn` (c = ctx_k of all bucket targets / bi), A..D then `>200`; a `>200` with
  0 heads drawn is `rate: >200 unmeasured, 0 of 0 heads` instead. `--check` -> `routing: <r> of <m> buckets routed`
  against docs/routing.md `route: <bucket> <draft|draft-twin|defer> cap <N> tries` (must equal R3: >= 50% draft, 20-50%
  draft-twin, < 20% defer; a measured `>200` is checked the same, an unmeasured one needs a `route: >200 ... unmeasured`
  line); exit 1 on r < m or a mismatch. Selftest plants wrong routes (A and measured `>200`) and asserts refusal.
- `rate [--check]` (W<k> omitted, R5): the same lines with every wave's bucket counts summed (bi of ai, bh of ah are
  the aggregate numerators/denominators); writes no rate.txt; `--check` routes against the aggregate. tools-health
  routing runs this.

## gate.py

`PY tools/wave/gate.py run|recover W<k> [--alias a] [--waves DIR]` (doc header is the spec). Banks a wave's drafts
(`waves/W<k>/drafts/<alias>_<name>.c`) through reconcile plain mode: r1 in the main tree, r2-r5 slate in the worktree
`.run/wave/wt/<alias>`, worktree SHA (bisect on red), `shapes.py check` on the worktree (R4; bisect on red, culprits
no-verdict `refused types`), adopt into the main tree, one build, `reconcile verify`. `--help` lists the subcommands.
Writes `waves/W<k>/verdicts.jsonl` (one row per draft), ends with the status assertion. Refuses a dirty src/ or
config/; never commits (prints `gate: commit <paths>`; run `make no-rom PY=PY` -> `no-rom: OK` before that commit). Per-alias lock `.run/wave/lock.<alias>`; build logs
`.run/wave/<alias>.{wt,main}.build.log`. `recover` retries `failed` r1 rows with extern_for decls: `recover: <p>
plumbing banked, <b> body`. `--selftest` -> `gate: control OK -- missing verdict refused`, then `gate: control OK --
raw cast refused` (a planted raw-cast slate draft gets no-verdict `refused types`; fixtures/gate).
`rescan W<k> [--waves DIR]` (R6, G46; refuses a dirty src/config: commit the gate's banks first): refreshes
inventory -> census dup -> sig band (full), then per `banked` row lists its open exact twins + dup-group members
(status asm), kept only when byte twins in place (`propagate.twin`: raw words equal, jal targets free when the rep
takes DEDUP_CALLEE; others printed `gate: <a>_<name> <k> masked-only skipped`); a banked function with any becomes a
dedup rep (`src/shared/<name>.c`; its sole callee -> DEDUP_CALLEE when its words have one jal target and its body
calls one function; own C file -> member text, r1 record -> shared body) and `propagate.py run` instantiates it. `rescan: <b> banked, <t> open twins, <p> propagated`
(p = propagated members, counted apart from drafted banks), then `gate: commit <paths>` (after `make no-rom PY=PY` -> `no-rom: OK`). A failure restores the
rep's snapshot (C files, yamls, registry, r1 record), rebuilds, exit 1. Logs `.run/wave/rescan.*.log`.

## ledger.py, harvest.py

`PY tools/wave/ledger.py build|check [--waves DIR] [--out F]` (R7; doc header is the spec). `build` renders
`docs/ledger.md` (generated; never hand-edited): one row per non-banked verdict whose target is still asm in
`.run/census/inventory.jsonl`, `{alias, name, vram, insns, wave, class, closeness, best_draft, blocker, tries, ctx_k,
date}`, sorted (alias, vram); a target failed in several waves keeps its closest row (lowest diff, tie → later wave). `check` rebuilds in memory: every attempted target is `c` or has exactly one row, no row
lacks a real draft or closeness, the file is byte-current: `ledger: <n> rows, <u> unledgered, <d> without draft`,
exit 1 on any nonzero or stale. `--selftest` -> `ledger: control OK -- rumour refused` (fixtures/ledger).
`PY tools/wave/harvest.py check [W<k>] [--waves DIR]` (R8) -> `harvest: W<k> <h> of <b> banked harvested, <o> open`
(`waves/W<k>/harvest.jsonl`, one row per banked draft; exit 1 unless h == b and o == 0; rider `inert` is open).
W<k> omitted: every `waves/W<k>/`, one `harvest:` line each; exit 1 if any fails or no wave (tools-health harvest).
`rider <banked.c> <stripped.c> --target <alias>_<name>` compiles both through try's path (`wave.compile_func`) ->
`rider: <name> load-bearing` (exit 0) | `inert` (exit 1). `--selftest` -> `harvest: control OK -- inert rider refused`.
