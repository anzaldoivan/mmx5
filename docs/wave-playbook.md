# The wave playbook — the operating procedure for the matching campaign

> ONE document is the procedure: read it before every run, keep it current in the same change as any tool it names;
> a superseded procedure gets a banner. Each guard below is paired with the MEASUREMENT that earned it — fill the
> measurement column from your own waves; the source project's are in the kit's methodology (the calibration fences).
> Created by decomp-architect on 2026-10-03.

| # | Step | The guard | The measurement that earned it |
|---|---|---|---|
| 0 | Preconditions | tree clean; the last clean fleet run green | W1: refresh inventory→dup→sig band→draw 23 s (9+0+9+5); fleet green before draw (R1.8.1-003) |
| 1 | Draw | exclude what cannot bank; audit the exclude list first (it records what the TOOLING could not do); rank by open templatable instructions; know face mass vs delivered mass. `waves.py draw W<k>` stratifies (`--order strata`, W1); `--order leverage --size N` draws by reach then insns, skips `defer` buckets, takes `draft-twin` only with a banked twin or lever (docs/routing.md) | W1: 1 s, 24 targets (3 slus + 3 rockx5 per bucket A-D), 0 invalid; 2882 of 7905 drawable, 5023 refused |
| 2 | Cards | the banked twin found over the WHOLE world goes on the card; a card names only levers the base contains | W1: <1 s, 24 cards, 0 refused, 17.4k chars of card.md total |
| 3 | Packs | one per target + the shared laws file, at the paths the drafting prompt reads | W1: 24 packs from the same `card` run |
| 4 | Validate | never hand-type a target; assert every target is still open at draw time; near-misses to the permuter first | W1: 0 invalid of 24; 2 near-misses (diff 2 words) to permute/plateau: no gain (regalloc $v0/$v1) |
| 5 | Draft | one agent per target, model by measured size, streaming not batched; the wave's difficulty is a draw-time knob | W1: 24 coders streamed (20-concurrent cap), wall 15.4 min, 22 of 24 match, 137 tries, 998 k ctx |
| 5b | Try | a draft is compared before the gate: `waves.py try <draft.c> --target <alias>_<name>`; an error prints the first cc1 lines, a diff the differing word offsets | — |
| 6 | Gate | everything in parallel (worktrees; the executable by a clean rebuild); gate the DIRECTORY, never the verdict list; assert banked + failed + no-verdict == drafts; `shapes.py check` on the worktree after the SHA bisect, culprits bisected out as no-verdict `refused types` | W1: slus 19 s, rockx5 26 s; 24 = 22 banked (r2) + 2 failed + 0 no-verdict. Finding: gate banked a raw-cast draft that `shapes.py check` rejects (red only at tools-health) — now gated (R4) |
| 6b | Reconcile | one deterministic pass over each gate group's slate BEFORE the rebuild | W1: ~1 s; 0 plumbing, 2 body failures |
| 7 | After ANY bank | the twin rescan, then `make no-rom PY=PY` (`no-rom: OK`), then commit | W1: rescan 425 s first pass, 436 twins; 754 propagated after the byte-twin-in-place fix (+318) |
| 8 | Harvest — a hard gate | every idiom into the cookbook + index; every mechanical idiom into a sweep that banks the free functions; the widening review | W1: 22 of 22 banks harvested: 15 none, 4 covered (C0049/50/51/54), 2 new idioms C0069/C0070 (3 rows) with byte-proven levers; 8 riders load-bearing, 4 candidate credits inert; widening: neither new idiom nameable by sig/draw/harvest |
| 9 | Verify the fleet | a clean rebuild of everything; read the exit code | W1: `make check` 207 s (tools-health 191 s), exit 0 |
| 10 | Hand off | the task summary carries the exact state and the next step; at a context handoff, `TASK_PROGRESS.md` does — stale is worse than absent | W1: 0 context handoffs over T1-T5 |

Then **recover** before re-drawing: triage the gate's failures into body and plumbing; bank the plumbing rejects through
the reconcile ladder without a redraft; the gate number is not the close rate until recovery has run.

## Per-wave numbers (W1-W13)
From `waves/W*/{wave.json,attempts.jsonl,verdicts.jsonl}` (T16). Fields: drafts / banked / failed / twins propagated /
coder ctx k / k per banked insn / banked insns of all insns / max min per target (wall proxy) / sum min (coder-minutes) / tries.
- W1 24 / 22 / 2 / 754 / 998k / 0.74 / 1341 of 1603 / 15.4 / 79 / 137
- W2 48 / 45 / 3 / 57 / 1941k / 0.77 / 2523 of 4228 / 18.3 / 110 / 179
- W3 48 / 45 / 3 / 19 / 1568k / 0.70 / 2233 of 2505 / 10.8 / 67 / 129
- W4 48 / 45 / 3 / 40 / 1531k / 0.76 / 2008 of 2280 / 6.5 / 58 / 106
- W5 48 / 46 / 2 / 17 / 1648k / 0.71 / 2320 of 2412 / 9.7 / 58 / 115
- W6 48 / 47 / 1 / 15 / 1751k / 0.88 / 1980 of 2007 / 20.5 / 79 / 103
- W7 48 / 46 / 2 / 23 / 1595k / 0.79 / 2029 of 2104 / 3.8 / 54 / 77
- W2-W7: 288 drafts, 274 banked (95.1%), 14 failed, 171 twins, 10034k ctx (~34.8k per draft)
- W8 48 / 46 / 2 / 29 / 1601k / 1.00 / 1601 of 1676 / 3.1 / 52 / 94
- W9 48 / 47 / 1 / 35 / 1766k / 0.68 / 2580 of 2626 / 6.2 / 78 / 125
- W10 48 / 47 / 1 / 4 / 1857k / 0.64 / 2900 of 2996 / 17.6 / 120 / 130
- W11 48 / 45 / 3 / 8 / 1758k / 0.78 / 2241 of 2439 / 10.3 / 86 / 152
- W12 48 / 46 / 2 / 22 / 1592k / 1.07 / 1491 of 1642 / 7.6 / 67 / 105
- W13 48 / 48 / 0 / 45 / 1525k / 1.27 / 1203 of 1203 / 3.0 / 44 / 86
- W8-W13: 288 drafts, 279 banked (96.9%), 9 failed, 143 twins, 10099k ctx (~35.1k per draft)

## Lanes (W1, counts from the W1 draw, R1.8.1-003; opening the excluded lanes is 1.8.2's)
- drafter — one coder per target (W1: 24); gater — `gate.py` + recover (W1: 22 banked, 2 failed)
- maintenance/propagation — twin rescan + `propagate.py` (W1: 754 twins; dup-member lane 1897)
- rodata-uncarveable 2467 · jump-table 161 · vendor 477 · excluded-module 0 (`config/dedup.exclude.yaml` empty)
- current (post-W13, `draw.py` refresh, no wave drawn): `draw: 3482 of 7905 drawable, 4423 refused` = vendor 477 ·
  already-c 1668 · exclude-list 22 · uncarveable 37 (jump-table 35, rodata-shared 2) · dup-member 2219 (A 1070, B 620,
  C 358, D 148, >200 23)

## Routing
Route and cap per bucket: docs/routing.md (routes from waves/W1/rate.txt + W2 for >200; aggregate W1-W13 checked by
`waves.py rate --check`, no wave arg; see docs/routing.md `## Aggregate rate (W1-W13, T15 1.8.3)`).

## Remaining campaign (for the 1.8.4 planner)
- census: `stubs 5738 of 7428 game functions (1668 c, 22 ledgered); vendor 475 asm` (1.8.3 start 6169)
- stubs 5738 = drawable 3482 + dup-member 2219 + uncarveable 37
- drawable by bucket (count, insns): A 641 9398 · B 1426 47774 · C 932 65310 · D 383 51929 · >200 100 29781
- cost per bucket W1-W13 (drafts, banked, insns banked of drawn, ctx k, k per bank, k per banked insn):
  A 122/122 1941 of 1941 3494 28.6 1.80 · B 298/285 9301 of 9859 9517 33.4 1.02 · C 130/125 8502 of 8900 4953 39.6 0.58 ·
  D 38/34 4486 of 5096 2131 62.7 0.48 · >200 12/9 2220 of 3925 1035 115.0 0.47
- estimate, drawable x k per bank: A 18.4M · B 47.6M · C 36.9M · D 24.0M · >200 11.5M = ~138M coder tokens
  (cross-check drawable insns x k per banked insn ~142M); ~73 waves of 48 at ~1.9M each; ~145 ledger rows at 95.8%
  (W1-W13 575 of 600)
- lanes left: drafter (3482 drawable); propagation (2219 dup-members, 0 cost only via a banked rep's twin rescan);
  tool/ledger (37 uncarveable + 22 ledgered); vendor 475 (separate lane, G48)
- I1 outcome: ovl38/39 `blocked:` (docs/memory-map.md:93-94; static dest 800FA000 from ovl18, unproven live); they stay
  excluded `bin` segments, NOT in the inventory; entering needs a live datapoint (stage-12 savestate or object spawn),
  then loadmap/yaml/census regen
- caveat: tail cost rising: k per banked insn W8-W13 0.84 vs W2-W7 0.77 (W12 1.07, W13 1.27); k per bank flat (36.2 vs
  36.6) while banked insns per bank fall (43.1 vs 47.8): leverage order now draws smaller bodies
- caveat: propagation ~24 twins per wave W8-W13 (4-45, uneven) vs ~28 W2-W7
- caveat: >200 routed `draft` since W10 (docs/routing.md); aggregate W1-W13 56.6%, 6.6 points above the line
