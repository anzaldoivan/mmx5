# docs/codegen-map — the pin's codegen map (gcc-2.95.2-psx cc1)

Per pass group: residual pattern in a near-miss diff → the compiler mechanism (cited into the staged source
`refs/gcc-2.95.2-psx/`) → the C lever that moves it → the experiment that proves it. Translated item by item
from the kit's gcc-2.7.2 map (`decomp-architect/corpus/cookbook/gcc-2.7.2-map/`); kit text is consulted, never copied.

## Files
- `sched.md` — scheduling + delayed branch: `sched.c` (not haifa; see its §0), `reorg.c`, MIPS hooks. Kit S1-S13, D1-D5.
- `regalloc.md` — local/global alloc + reload, regmove. Kit K1-K8, RC-1..RC-15.
- `loop.md` — loop optimiser: `loop.c`, unroll, jump VTOP. Kit L0-L8 + appendices.
- `cse_expr.md` — cse, gcse, combine, jump2 cross-jump, expression expansion, `/s` aliasing, frame layout. Kit K§1-K§8, H1-H3, E1-E5. Holds `div_pow2_signed`: `expand_divmod` is expmed.c, called
  from expr.c expression expansion, which is the kit's cse_expr scope.
- `levers.yaml` + `levers/<id>.{before,after}.c` — byte-proven levers (JSON list; record shape in tools/codegen/README.md).

## Entry shape
`### <kit id> — <residual> · <status>` then bullets: pass + `gcc/<path>:<line> <symbol>` cite(s) · residual tell ·
lever · experiment (lever id in levers.yaml, or scratch file under `.run/`, which is not kept).

Status vocabulary: `transfers` (mechanism present in 2.95.2, kit lever applies) · `changed` (present, behaviour or
lever differs; the entry says how) · `absent in 2.95.2` (mechanism not compiled in / not reachable at the pin).

## Tools
- `PY tools/codegen/cites.py check` — every `gcc/<path>:<line> <symbol>` in this dir must be grep-true in the
  staged tree (lines split on `\n`); prints `cites: <ok> of <n> citations resolve, <s> stale`.
- `PY tools/codegen/levers.py check` — compiles each lever's before/after at the pin; tell regex must match
  before and not after, masked words of `fn` must differ. `levers.py dump <file.c>` → `-da` RTL dumps in
  `.run/codegen/dumps/<stem>/` (`.sched`, `.sched2`, `.dbr`, …). Details: tools/codegen/README.md.
- Reproducers are synthetic C, function named `lever_*`; no game bytes.

## Levers by group
- sched: `sched_stmt_order` (S1), `sched_birth_boost` (S2), `sched_reused_temp_fence` (S12),
  `dbr_branch_polarity` (D3).
- regalloc: `regalloc_density_order` (K2/RC-3), `regalloc_decl_tie` (K1/RC-3).
- loop: `loop_rev_ne_vtop` (L3), `loop_rev_counting_only` (L3), `loop_const_hoist` (L4).
- cse_expr: `div_pow2_signed` (E5), `xjump_tail_merge` (E3), `cse_call_retie` (K§3), `cse_volatile_asm_flush`
  (K§1-g), `expr_mult_first_sum` (E4).

## Triage table
Symptom-keyed. Find the tell, open the map §, try the lever family, rerun the lever id as the worked example.
`(C0002)` = row of cookbook/C0002.md. `—` = no byte-proven lever yet; the § is the pointer.

| Tell in the diff | Pass (map §) | Lever family | Lever ids |
|---|---|---|---|
| a temporary in a spill slot (C0002) | reload / global (regalloc.md §B RC-1, RC-2, RC-8) | reshape the live range; declaration order | `regalloc_decl_tie` |
| every small edit moves 20+ insns (C0002) | local-alloc pressure lock (regalloc.md §B RC-6; sched.md S11) | hand to the permuter | — |
| a load stuck below a store while other loads float (C0002) | `/s` aliasing (cse_expr.md K§4) + sched dep (sched.md S3) | the source's aliasing facts | `alias_struct_grant` |
| a phantom callee-saved register (C0002) | cross-call value cse (cse_expr.md K§3) / alloc order (regalloc.md RC-3) | count the uses; re-shape; re-tie per call | `cse_call_retie`, `regalloc_density_order` |
| a shift off by ×4 against the target (C0002) | front-end pointer scaling, not a map pass (nearest cse_expr.md E4/E5) | cast through a byte pointer | `expr_byte_ptr_scale` |
| a branch's arms swapped (C0002) | dbr eager fill (sched.md D3) | put the fall-through block in the `if` | `dbr_branch_polarity` |
| a cross-jumped tail merged or not merged (C0002) | jump2 cross-jump (cse_expr.md E3) | shape the shared block count | `xjump_tail_merge` |
| latency-1 insns permuted among ties | sched1 (sched.md S1) | statement order | `sched_stmt_order` |
| def placed far from / sunk to its use | sched birthing boost (sched.md S2) | single-set vs reused temp | `sched_birth_boost` |
| batched vs paired loads | sched (sched.md S12, S4) | reused-temp fence | `sched_reused_temp_fence` |
| delay slot `nop` vs filled, slot content wrong | reorg (sched.md D1, D2, D4) | eligibility; statement order | — |
| `$s0`/`$s1` swapped, unequal use counts | global density priority (regalloc.md K2, RC-3) | refs / live-range shaping | `regalloc_density_order` |
| `$s0`/`$s1` swapped, equal density | pseudo creation order (regalloc.md K1, RC-3) | swap declarations | `regalloc_decl_tie` |
| down-count `addiu -1` + `bne`/`bgez` vs up-count `slt` | loop reversal (loop.md L3) | index use in body; loop shape | `loop_rev_ne_vtop`, `loop_rev_counting_only` |
| invariant load at loop head vs hoisted to preheader | loop invariant motion (loop.md L4) | `const`/volatility of the operand | `loop_const_hoist` |
| IV count / giv shape / endtest differs | loop strength reduction (loop.md L1, L2, L5-L8) | IV form of the source | — |
| `bgez`+`addiu` bias vs plain `sra` | expmed signed divide (cse_expr.md E5) | `/ 2^k` vs `>> k` | `div_pow2_signed` |
| recompute where target reuses, no label/call between | cse table flush (cse_expr.md K§1-g, K§1-f) | operand-less volatile asm / statement split | `cse_volatile_asm_flush` |
| address register/operand order in a sum | expression expansion (cse_expr.md E4) | operand order, MULT first | `expr_mult_first_sum` |
| per-call `addiu $aN,$sp,K` vs cached `$sN` | cse address caching (cse_expr.md K§2) | hoist vs remat | — |
| frame offsets ±8 / out of decl order | frame layout (cse_expr.md K§5) | temp population; decl order | — |

## Residual classes
Vocabulary T6's `plateau.py classify` emits as `class <c>`. Names from the kit's residual classifier (decision order,
first match wins), routed to our pin's groups. Bytes decide the class; the byte gate decides the match.

| Class | Definition | Routes to |
|---|---|---|
| MATCH | masked streams identical | none: integration / reconcile, not codegen |
| EMPTY | one stream empty | none: harness fault |
| LENGTH-DRIFT | lengths differ; one shift point explains the tail | small delta: permuter; else structural (frame, loop L4, cross-jump E3 rows) |
| SIZE-MISMATCH | lengths differ wildly, no shift explains | redraft; not a near-miss |
| SHIFT-DRIFT | equal length; a small shift realigns most of the tail | structural: one insn moved (sched S2/S3, loop L4 rows) |
| REGALLOC-PERM | register-only diffs, one consistent injective reg map | regalloc: `$s` swap rows (K1/K2, RC-3); permuter |
| SCHEDULE-REORDER | same masked insns, different order | sched: S1-S5, S12 rows; permuter |
| DELAY-SLOT | `nop` vs insn at the diff positions | sched D1-D4 rows (branch-arms row for polarity) |
| REGALLOC-LOCAL | register-only diffs, no consistent map | regalloc RC-2/RC-4/RC-8 rows (spill, phantom callee-saved) |
| WIDTH | load/store width flip | structural C idiom (types); no map pass |
| STRENGTH | mult/div vs shift/add | cse_expr E5 (`div_pow2_signed` row) |
| ADDRESSING | `addu`/`addiu`/`lui` base-address shape | cse_expr K§2, E4 rows; structural |
| BRANCH-POLARITY | `beq`/`bne`, `bgez`/`bltz` flips | branch-arms row (sched D3); loop L3 guard rows |
| OPCODE-MIXED | different operations, no single family | structural; read the map by pass dump |
| IMM-OFFSET | same ops/regs, immediates off by a constant | frame layout (cse_expr K§5) or struct layout; ×4 row |
| IMM-VALUE | same ops/regs, unrelated immediates | cse constant (cse_expr K§1); wrong constant in source |
| MIXED | several kinds, none dominant | unknown: LLM tier |
| UNKNOWN | opcode the decoder does not cover | unknown; counted, never bucketed |

Plateau labels (`plateau.py classify … label <l>`), one per stalled permuter run, keyed off the class's route:
- `missing-transform` — class routes to the permuter (REGALLOC-*, SCHEDULE-REORDER, DELAY-SLOT, small LENGTH-DRIFT,
  IMM-VALUE) yet it plateaued: a lever the permuter lacks; add a transform or a levers.yaml entry.
- `mis-classified` — the stored class/route disagrees with what the bytes say; re-route, do not grind.
- `seed-structural` — class is structural (WIDTH, BRANCH-POLARITY, ADDRESSING, STRENGTH, IMM-OFFSET, SHIFT-DRIFT, big
  LENGTH-DRIFT, SIZE-MISMATCH): fix the seed's C shape via the triage row first; permuter CPU is waste.
- `wall` — none of the above, triage rows and lever ladder walked; evidence required (G61), never a closeness number.
