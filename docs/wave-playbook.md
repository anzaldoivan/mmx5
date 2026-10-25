# The wave playbook — the operating procedure for the matching campaign

> ONE document is the procedure. Read it before every run. Keep it current in the same change as any tool that it
> names. A superseded procedure gets a banner.
>
> The table pairs each guard below with the MEASUREMENT that earned it. Fill the measurement column from your own
> waves. The source project's measurements are in the kit's methodology (the calibration fences).
> Created by decomp-architect on 2026-10-03.

| # | Step | The guard | The measurement that earned it |
|---|---|---|---|
| 0 | Preconditions | The tree must be clean. The last clean fleet run must be green. | W1: refresh inventory→dup→sig band→draw 23 s (9+0+9+5). Fleet green before draw (R1.8.1-003). |
| 1 | Draw | Exclude what cannot bank. Audit the exclude list first (it records what the TOOLING could not do). Rank by open templatable instructions. Know face mass vs delivered mass. `waves.py draw W<k>` stratifies (`--order strata`, W1), skips ledgered targets, and `waves.py open A,B` counts the open ones. `--order leverage --size 48 --only A,B` draws by reach then insns, skips `defer` buckets, and takes `draft-twin` only with a banked twin or lever (docs/routing.md). | W1: 1 s, 24 targets (3 slus + 3 rockx5 per bucket A-D), 0 invalid. 2882 of 7905 drawable, 5023 refused. |
| 2 | Cards | The banked twin found over the WHOLE world goes on the card. A card names only levers that the base contains. | W1: <1 s, 24 cards, 0 refused, 17.4k chars of card.md total |
| 3 | Packs | Make one pack per target + the shared laws file, at the paths that the drafting prompt reads. | W1: 24 packs from the same `card` run |
| 4 | Validate | Never hand-type a target. Assert that every target is still open at draw time. Send near-misses to the permuter first. | W1: 0 invalid of 24. 2 near-misses (diff 2 words) to permute/plateau: no gain (regalloc $v0/$v1). |
| 5 | Draft | Before hand drafting, run `waves.py port W<k>`, then `waves.py seed W<k>` (opt-in, no-lead targets: an m2c draft to keep in part and type before `try`). From W26, seed per the T3 verdict (seed if seed k/insn <= 0.9 x fresh, heads lower by at most 2): `seedcheck: W24-W25 A seed 3/3 heads 1.62 k/insn, fresh 3/3 heads 2.13 k/insn; B seed 46/46 heads 1.07 k/insn, fresh 44/44 heads 1.07 k/insn; verdict A seed, B fresh`. A matched port is written to `waves/W<k>/drafts/` and goes straight to the gate. An unmatched port seeds its drafter (`.run/wave/W<k>/port/`). Ports reuse `include/types.h` shapes and `include/addr.h` names, mark pins and gotos `!FAKE`, inline pointer typedefs, refuse an unnamed X6 data symbol (`port: <key> error symbol <name>`: hand-draft it). Use one agent per target, the model by measured size, streaming not batched, with the wave's difficulty set at draw time. | W1: 24 coders streamed (20-concurrent cap), wall 15.4 min, 22 of 24 match, 137 tries, 998 k ctx |
| 5b | Try | Compare a draft before the gate: `waves.py try <draft.c> --target <alias>_<name>`. An error prints the first cc1 lines. A diff prints the differing word offsets. | — |
| 6 | Gate | Run everything in parallel (worktrees, and the executable by a clean rebuild). Gate the DIRECTORY, never the verdict list. Assert banked + failed + no-verdict == drafts. Run `shapes.py check` on the worktree after the SHA bisect, with culprits bisected out as no-verdict `refused types`. | W1: slus 19 s, rockx5 26 s. 24 = 22 banked (r2) + 2 failed + 0 no-verdict. Finding: the gate banked a raw-cast draft that `shapes.py check` rejects (red only at tools-health) — now gated (R4). |
| 6b | Reconcile | Make one deterministic pass over each gate group's slate BEFORE the rebuild. | W1: ~1 s. 0 plumbing, 2 body failures. |
| 7 | After ANY bank | Run the twin rescan. Then run `make no-rom PY=PY` (`no-rom: OK`). Then commit. | W1: rescan 425 s first pass, 436 twins. 754 propagated after the byte-twin-in-place fix (+318). |
| 8 | Harvest — a hard gate | Put every idiom into the cookbook + index. Put every mechanical idiom into a sweep that banks the free functions. Do the widening review. | W1: 22 of 22 banks harvested: 15 none, 4 covered (C0049/50/51/54), 2 new idioms C0069/C0070 (3 rows) with byte-proven levers. 8 riders load-bearing, 4 candidate credits inert. Widening: neither new idiom nameable by sig/draw/harvest. |
| 9 | Verify the fleet | Do a clean rebuild of everything. Read the exit code. | W1: `make check` 207 s (tools-health 191 s), exit 0 |
| 10 | Hand off | The task summary carries the exact state and the next step. At a context handoff, `TASK_PROGRESS.md` does. Stale is worse than absent. | W1: 0 context handoffs over T1-T5 |

Then **recover** before re-drawing. Triage the gate's failures into body and plumbing. Bank the plumbing rejects through
the reconcile ladder without a redraft. The gate number is not the close rate until recovery has run.

## Per-wave numbers (W1-W64)
The numbers come from `waves/W*/{wave.json,attempts.jsonl,verdicts.jsonl}` (T16). The first fields are drafts / banked /
failed / twins propagated / coder ctx k / k per banked insn. The next fields are banked insns of all insns / max min per
target (wall proxy) / sum min (coder-minutes) / tries.
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
- W15-W22 (2.8, T3-T10): same fields, then the `waves.py port` line. Coder ctx is the task summary's sum (T3-T10).
  `*` = the summary is silent, so attempts.jsonl `ctx_k` is summed (a low estimate). `-` = minutes not recorded.
- W15 48 / 48 / 0 / 27 / 276k / 0.11 / 2432 of 2432 / 7.6 / 7.6 / 5 · port 47 of 48
- W16 48 / 47 / 1 / 6 / 270k / 0.08 / 3283 of 3424 / 2.5 / 9.0 / 29 · port 40 of 48
- W17 48 / 47 / 1 / 1 / 117k* / 0.04 / 3154 of 3295 / - / - / 6 · port ~41 of 48 (inferred: T6 counts 7 T5 misses)
- W18 48 / 47 / 1 / 1 / 41k / 0.03 / 1440 of 1581 / 1.0 / 1.5 / 6 · port 45 of 48
- W19 48 / 47 / 1 / 8 / 34k* / 0.05 / 755 of 896 / 0.5 / 1.5 / 4 · port 44 of 48
- W20 48 / 46 / 2 / 7 / 675k / 0.46 / 1480 of 1789 / - / - / 65 · port 22 of 24 (24 fresh drafts, lead lane dry)
- W21 48 / 44 / 4 / 4 / 1134k / 0.40 / 2807 of 3286 / - / - / 150 · port 4 of 5 (43 fresh drafts)
- W15-W21: 336 drafts, 326 banked (97.0%), 10 failed, 54 twins, ~2547k ctx (~7.6k per draft). Six failures are
  2C4C_ovl24, carried W16-W21. Banked 15351 of 16703 insns. Port matched 243 of 269 leads under `try` (90.3%).
- W22 40 / 39 / 1 / 0 / 1290k / 0.29 / 4412 of 4709 / 75 / 410 / 179 · hand-listed: 37 uncarveable + 7 ledger re-entries
- W24-W64 (3.3, T2-T42): same fields. Coder ctx is the sum of the draft coders' attempts.jsonl `ctx_k`.
  It excludes the gate and harvest coders. Twins come from each task summary. W24-W25 split seed and fresh arms
  (arms.json). From W26: A seed, B fresh.
- W24 48 / 48 / 0 / 34 / 1801k / 1.00 / 1807 of 1807 / 3.2 / 62 / 100
- W25 48 / 48 / 0 / 34 / 1690k / 1.23 / 1369 of 1369 / 3.7 / 50 / 83
- W26 48 / 47 / 1 / 40 / 1764k / 1.34 / 1313 of 1363 / 5.3 / 77 / 107
- W27 48 / 44 / 4 / 28 / 1946k / 1.03 / 1883 of 2075 / 7.0 / 98 / 152
- W28 48 / 44 / 4 / 29 / 1902k / 1.04 / 1828 of 1997 / 6.4 / 103 / 143
- W29 48 / 47 / 1 / 32 / 1824k / 1.03 / 1776 of 1813 / 8.1 / 100 / 123
- W30 48 / 46 / 2 / 29 / 1825k / 1.19 / 1537 of 1609 / 4.1 / 79 / 125
- W31 48 / 47 / 1 / 27 / 1751k / 1.21 / 1444 of 1474 / 4.9 / 76 / 114
- W32 48 / 48 / 0 / 23 / 1593k / 1.18 / 1354 of 1354 / 2.6 / 61 / 76
- W33 48 / 48 / 0 / 25 / 1689k / 1.37 / 1233 of 1233 / 4.4 / 69 / 102
- W34 48 / 48 / 0 / 28 / 1627k / 1.49 / 1091 of 1091 / 2.3 / 62 / 79
- W35 48 / 44 / 4 / 31 / 1632k / 1.87 / 872 of 949 / 2.6 / 43 / 83
- W36 48 / 45 / 3 / 30 / 1546k / 2.14 / 722 of 770 / 2.3 / 44 / 80
- W37 48 / 46 / 2 / 23 / 1592k / 1.30 / 1227 of 1285 / 3.8 / 54 / 97
- W38 48 / 45 / 3 / 3 / 1842k / 0.90 / 2038 of 2142 / 5.8 / 72 / 145
- W39 48 / 43 / 5 / 0 / 2011k / 1.05 / 1917 of 2146 / 8.5 / 109 / 177
- W40 48 / 45 / 3 / 1 / 1953k / 1.02 / 1922 of 2052 / 8.8 / 98 / 147
- W41 48 / 42 / 6 / 1 / 1897k / 1.09 / 1734 of 1985 / 4.5 / 86 / 150
- W42 48 / 42 / 6 / 0 / 1904k / 1.15 / 1658 of 1899 / 11.5 / 86 / 135
- W43 48 / 46 / 2 / 0 / 1830k / 1.04 / 1754 of 1832 / 5.8 / 78 / 119
- W44 48 / 44 / 4 / 2 / 1925k / 1.19 / 1616 of 1765 / 5.4 / 90 / 154
- W45 48 / 45 / 3 / 1 / 1826k / 1.16 / 1569 of 1675 / 4.7 / 79 / 120
- W46 48 / 46 / 2 / 1 / 1727k / 1.13 / 1529 of 1597 / 5.5 / 62 / 96
- W47 48 / 45 / 3 / 1 / 1780k / 1.24 / 1440 of 1537 / 4.6 / 63 / 121
- W48 48 / 44 / 4 / 1 / 1835k / 1.36 / 1353 of 1479 / 6.6 / 63 / 112
- W49 48 / 48 / 0 / 1 / 1718k / 1.22 / 1408 of 1408 / 3.6 / 57 / 86
- W50 48 / 43 / 5 / 1 / 1694k / 1.41 / 1204 of 1346 / 4.1 / 57 / 116
- W51 48 / 47 / 1 / 0 / 1748k / 1.40 / 1251 of 1278 / 8.3 / 66 / 88
- W52 48 / 47 / 1 / 1 / 1766k / 1.49 / 1188 of 1214 / 3.9 / 68 / 106
- W53 48 / 46 / 2 / 5 / 1673k / 1.52 / 1102 of 1149 / 5.2 / 62 / 104
- W54 48 / 43 / 5 / 0 / 1741k / 1.81 / 964 of 1075 / 4.3 / 70 / 123
- W55 48 / 47 / 1 / 0 / 1682k / 1.73 / 974 of 994 / 2.1 / 52 / 79
- W56 48 / 48 / 0 / 0 / 1681k / 1.84 / 912 of 912 / 2.9 / 69 / 88
- W57 48 / 43 / 5 / 0 / 1573k / 2.16 / 727 of 814 / 3.7 / 59 / 88
- W58 48 / 46 / 2 / 0 / 1476k / 2.22 / 666 of 694 / 3.9 / 56 / 76
- W59 48 / 46 / 2 / 0 / 1406k / 2.57 / 547 of 569 / 3.7 / 48 / 68
- W60 44 / 40 / 4 / 0 / 1220k / 4.18 / 292 of 314 / 2.4 / 39 / 52
- W61 10 / 10 / 0 / 1 / 257k / 2.96 / 87 of 87 / 1.3 / 8 / 10
- W62 5 / 5 / 0 / 1 / 157k / 3.94 / 40 of 40 / 1.5 / 4 / 6
- W63 3 / 3 / 0 / 2 / 93k / 2.99 / 31 of 31 / 1.0 / 3 / 3
- W64 3 / 3 / 0 / 6 / 86k / 2.32 / 37 of 37 / 1.0 / 2 / 4
- W24-W64: 1793 drafts, 1702 banked (94.9%), 91 failed, 442 twins, 4037 tries. Draft ctx 64679k (~36.1k per
  draft, 1.31 k per banked insn). Banked 49416 of 52260 insns. W60-W64 are the pool-exhausted tail (44, 10, 5, 3, 3 drawn).

## Lanes (W1, counts from the W1 draw, R1.8.1-003. Opening the excluded lanes is 1.8.2's)
- drafter — one coder per target (W1: 24), and gater — `gate.py` + recover (W1: 22 banked, 2 failed)
- maintenance/propagation — twin rescan + `propagate.py` (W1: 754 twins, dup-member lane 1897)
- rodata-uncarveable 2467 · jump-table 161 · vendor 477 · excluded-module 0 (`config/dedup.exclude.yaml` empty)
- current (post-W13, `draw.py` refresh, no wave drawn): `draw: 3482 of 7905 drawable, 4423 refused`. The refused are
  vendor 477 · already-c 1668 · exclude-list 22 · uncarveable 37 (jump-table 35, rodata-shared 2) · dup-member 2219.
  The dup-member buckets are A 1070, B 620, C 358, D 148, >200 23.

## Routing
The route and the cap per bucket are in docs/routing.md. The routes come from waves/W1/rate.txt + W2 for >200.
`waves.py rate --check`, with no wave arg, checks the aggregate of every closed wave (now W1-W64). See docs/routing.md
`## Aggregate rate (W1-W64, 3.3 T43)`.

## Remaining campaign (for the next planner, 2.8 close, T11, 2026-10-17)
- census: `stubs 5519 of 7647 game functions (2109 c, 19 ledgered); vendor 475 asm` (2.8 start 5936, G1 close 5738)
- draw: `draw: 3312 of 8124 drawable, 4812 refused` (vendor 477 · already-c 2109 · exclude-list 17 · uncarveable 0 ·
  dup-member 2209). Drawable 3312 + dup-member 2209 = 5521, 2 above the stub count. Not reconciled: T1's sum was exact.
- drawable by bucket (count, insns): A 554 8136 · B 1412 47322 · C 878 61361 · D 368 50227 · >200 100 29891
- cost per bucket, fresh drafts W1-W13 (drafts, banked, insns banked of drawn, ctx k, k per bank, k per banked insn):
  - bucket A 122/122 1941 of 1941 3494 28.6 1.80
  - bucket B 298/285 9301 of 9859 9517 33.4 1.02
  - bucket C 130/125 8502 of 8900 4953 39.6 0.58
  - bucket D 38/34 4486 of 5096 2131 62.7 0.48
  - bucket >200 12/9 2220 of 3925 1035 115.0 0.47
- W15-W21 by bucket, as drafts/banked and insns banked of drawn.
  A 104/104 1517 of 1517 · B 102/102 3258 of 3258 · C 93/91 6545 of 6715 · D 33/25 3180 of 4362 · >200 4/4 851 of 851.
  No per-bucket ctx exists, because port targets carry no `ctx_k`.
  Fresh drafts alone cost ~26k per bank in W21 (40 of 42 matched) and ~33k in W22 (hard lane).
- X6 leads (docs/oracle/x6-leads.tsv vs inventory): 1032 of 1348 rows still asm, in 98 of 328 classes. Of those
  1032, 21 are drawable and 1011 are dup-members. `--order port-x6` draws no new class (T8, T9): the lead lane is spent.
- porter hit rate: 243 of 269 leads matched under `try` (90.3%, W15-W21, W17 inferred). A port draft cost
  ~5.7k coder ctx (T3, T4), a fresh draft ~26k (W21).
- estimate (the drawable are now fresh drafts, no donor C):
  - drawable x W1-W13 k per bank: A 15.8M · B 47.2M · C 34.8M · D 23.1M · >200 11.5M = ~132M coder tokens (upper)
  - drawable x W21's ~26k per bank = ~86M (lower, as W21 drew from the top of the leverage order)
  - ~69 waves of 48 at ~1.1-1.9M each
  - ledger: 20 rows now (`ledger.py check`, census counts 19). At W1-W13's 95.8% about 140 more, ~160 at the end.
- lanes and levers for the next waves:
  - drafter: 3312 drawable, leverage order (`--order port-x6` falls through to it)
  - reloc-aware propagate: done (phase 3.1). 1315 of 1387 masked-only members banked, 72 refused. Draw dup-member
    2209 -> 901. Rescans are reloc-aware via `propagate.members()`. Command `propagate.py sweep [--dry-run]
    [--binary <alias>]` (slus before rockx5). Lines `dedup: sweep <alias> <name> gated|refused <why>`, last
    `dedup: sweep <g> of <n> masked-only members byte-gated, <r> refused` (tools/dedup/README.md `### sweep`).
  - ledger: F3BF0_ovl28 stays at diff 6/297 (addu operand order +0x280/+0x2C0, tail li 12 hoist).
    2C4C_ovl24 and F0DAC_ovl02 failed at cap. The prologue store-order family (EF094_ovl03, 5308_ovl27) banked in W22
    with C0129, the lever C0051/C0053 named. It applies to any new prologue-order near-miss.
  - gate: run `gate.py run --alias slus` and `--alias rockx5` one after the other, never concurrently (T9).
  - vendor 475 (separate lane, G48)
- scaffold lane (R4 re-raise, measured): R4 deferred mmx6's scaffold first pass to this close, to be weighed with the
  porter's hit rate. Measured: 90.3% at ~5.7k per draft, ~5x cheaper than a fresh draft, with the donor set spent
  (21 drawable lead rows left). The 3291 other drawable have no donor C, and this repo has no decompiler front end.
  A first pass that matched even half as often would cut the ~86-132M estimate materially. Recommended: a 12-target
  pilot (T2's band pick) of a decompiler first pass before any adoption, with the three-line tool case.
  - tool case (Phase 3.2 T1): m2c decompiles one function's asm to a C draft (`-t mipsel-gcc-c`, structs as `unkNN`).
  - existing: `port` maps donor mmx6 C onto a target (lead rows only). `try` compiles a draft and byte-diffs it.
  - delta: a first draft for the 3291 drawable with no donor C. It still needs hand typing before `try` compiles it.
  - pilot (Phase 3.2 T4, waves/W23/pilot.txt): `pilot: W23 seed 12/12 heads 1276/1276 insns 0.62 k/insn; fresh 11/12 heads 1052/1251 insns 0.83 k/insn; m2c 708d2d2cb2698f091a92492b328f73b24209f72d; verdict adopted`. Gain is in D (0.42 vs 0.88). C is worse seeded (0.91 vs 0.67). n=12, re-measure on real waves (3.3).
- caveats:
  - 2C4C_ovl24 (141 insns, D) is counted failed in each of W16-W21: the aggregate D and failure counts carry it 6 times.
  - the aggregate `k ctx per banked insn` is diluted by port waves whose attempts carry no `ctx_k`.
  - the stub fall per wave was ~55 (W15-W21, 5936 -> 5552, twins included).
    The wave count above comes from the 3312 drawable. The dup-members (901 left) need the propagate lever instead.

## Remaining campaign (3.3 close)
The 3.3 close is T43 (2026-10-25). Inputs were refreshed (step 0): `draw: 1587 of 8124 drawable, 6537 refused` (vendor 477 ·
already-c 5604 · exclude-list 10 · dup-member 446).
- census: `stubs 1940 of 7647 game functions (5604 c, 103 ledgered); vendor 475 asm` (3.3 start 4211, 3424 c)
- `open: A 128 open, 151 drawable, 23 ledgered`
- `open: B 37 open, 105 drawable, 68 ledgered`
- `open: C 870 open, 870 drawable, 0 ledgered`
- `open: D 360 open, 361 drawable, 1 ledgered`
- `open: >200 0 open, 0 drawable, 0 ledgered`. This line is a tool gap. `bucket_of` returns None above 200, so
  `open` never counts that bucket. draw.jsonl counted by a scratch script gives 100 drawable, 98 open, 29250 insns.
- open insns: A 2015 · B 894 · C 60660 · D 48690 · >200 29250
- ledger: `ledger: 104 rows, 0 unledgered, 0 without draft, 0 without blocker` (3.3 start 13)
- the A/B pool did not close. The leverage draw takes one target per dup cluster. Almost all of the 165 open A/B
  rows are in one cluster, so W61-W64 drew 10, 5, 3 and 3 targets. A draw that takes several targets per cluster
  is necessary before the A/B pool can reach 0.
  - T45 added `draw … --only A,B --per-cluster N`. The draw then takes up to N targets from one cluster. The
    default is 1. Use it for the A/B tail only, when the draw falls far short of `--size`.
  - 162 of the 165 open A/B rows are in one cluster. A dry draw with N 1 takes 2 targets. With N 48 it takes 48.
  - `open '>200'` now counts that bucket: `open: >200 98 open, 100 drawable, 2 ledgered`.
- per-bucket cost, W24-W64 draft coders only. The fields are drafts/banked, insns banked of drawn, ctx, k per bank,
  k per banked insn and tries:
  - bucket A 426/403 5801 of 6121 13417k 33.3 2.31 666
  - bucket B 1367/1299 43615 of 46139 51262k 39.5 1.18 3371
  - C, D and >200 were not drawn in 3.3 (`--only A,B`).
  - against W1-W13 fresh (A 1.80, B 1.02 k per banked insn), the tail cost more: A +28%, B +16%.
- seeded vs fresh (k ctx per banked insn), W24-W25 arms: A seed 1.62 vs fresh 2.13 (3 heads each). B seed 1.07 vs
  fresh 1.07 (46 and 44 heads). Verdict A seed, B fresh.
  - W26-W64: A seeded 397 of 420 heads, 2.32 k/insn. B fresh 1209 of 1277 heads, 1.18 k/insn.
  - The A seed gain did not hold at scale: 2.32 is above the pilot's fresh 2.13 (n=3). The A tail is mostly
    bodies of 1-20 insns, where the fixed cost of a coder dominates.
- wall per full wave: 2.8-3.7 h for W24-W34 (the twin rescan took ~2 h). ~60-80 min from W40, when the rescan
  found few twins. The drafts of a full wave took 5-12 min. `make check` took ~21 min.
- C/D estimate for the 3.4 planner (fresh drafts, no donor C):
  - C: 870 heads, 60660 insns. At W1-W13 fresh 0.58 k/insn, ~35M. With the 3.3 tail drift (x1.16), ~41M.
    At 39.6k per bank and 95.5% heads, ~33M.
  - D: 360 heads, 48690 insns. At fresh 0.48 k/insn, ~23M. With x1.16, ~27M. At the pilot's seed 0.42 k/insn, ~20M.
  - C+D: ~53-68M coder tokens in ~26 waves of 48. A C wave costs ~1.9M, a D wave ~3.0M (W1-W13 k per bank).
  - >200 (98 open, 29250 insns, cap 30): ~14M at 0.47 k/insn, 2-3 waves. It is outside C/D.
  - expected ledger growth at the W1-W13 head rates (C 96%, D 89%): ~35 C and ~40 D rows.
  - seed: the pilot (W23, n=12) found C worse seeded (0.91 vs 0.67) and D better (0.42 vs 0.88). Recommended: split
    the first C and D waves into seed and fresh arms, as W24-W25 did, and bind the verdict for the later waves.
  - draw: `--only C` or `--only D` (T1). Set the caps per docs/routing.md (C 20, D 30).
