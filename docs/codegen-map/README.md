# docs/codegen-map — the pin's codegen map (gcc-2.95.2-psx cc1)

For each pass group, the map goes from a residual pattern in a near-miss diff to the compiler mechanism. The map
cites the mechanism into the staged source `refs/gcc-2.95.2-psx/`. The map then gives the C lever that moves the
pattern, and the experiment that proves the lever.

The writers translated the map item by item from the kit's gcc-2.7.2 map
(`decomp-architect/corpus/cookbook/gcc-2.7.2-map/`). They consult the kit text and never copy it.

## Files
- `sched.md` covers scheduling and delayed branch: `sched.c` (not haifa: see its §0), `reorg.c` and MIPS hooks.
  It holds kit S1-S13 and D1-D5.
- `regalloc.md` covers local/global alloc and reload, and regmove. It holds kit K1-K8 and RC-1..RC-15.
- `loop.md` covers the loop optimiser: `loop.c`, unroll and jump VTOP. It holds kit L0-L8 and appendices.
- `cse_expr.md` covers cse, gcse, combine, jump2 cross-jump, expression expansion, `/s` aliasing and frame layout.
  It holds kit K§1-K§8, H1-H3 and E1-E5. It also holds `div_pow2_signed`: `expand_divmod` is in expmed.c, and
  expr.c expression expansion calls it. That expression expansion is the kit's cse_expr scope.
- `levers.yaml` and `levers/<id>.{before,after}.c` hold the byte-proven levers. The levers are a JSON list, and
  tools/codegen/README.md gives the record shape.

## Entry shape
An entry starts with `### <kit id> — <residual> · <status>`. Bullets follow. They give the pass with its
`gcc/<path>:<line> <symbol>` cite(s), the residual tell, the lever and the experiment. The experiment is a lever
id in levers.yaml, or a scratch file under `.run/`, which the repository does not keep.

The status is one value of this vocabulary:
- `transfers`: the mechanism is present in 2.95.2, and the kit lever applies.
- `changed`: the mechanism is present, but the behaviour or the lever differs. The entry says how.
- `absent in 2.95.2`: at the pin, the mechanism is not compiled into cc1, or it is not reachable.

## Tools
- `PY tools/codegen/cites.py check` — every `gcc/<path>:<line> <symbol>` in this dir must be grep-true in the
  staged tree (lines split on `\n`). The tool prints `cites: <ok> of <n> citations resolve, <s> stale`.
- `PY tools/codegen/levers.py check` — the tool compiles the before/after of each lever at the pin. The tell regex
  must match before and not after. The masked words of `fn` must differ. `levers.py dump <file.c>` gives `-da` RTL
  dumps in `.run/codegen/dumps/<stem>/` (`.sched`, `.sched2`, `.dbr`, …). For details, read
  tools/codegen/README.md.
- Reproducers are synthetic C with no game bytes. The function of a reproducer has a `lever_*` name.

## Levers by group
- sched: `sched_stmt_order` (S1), `sched_birth_boost` (S2), `sched_reused_temp_fence` (S12),
  `dbr_branch_polarity` (D3).
- regalloc: `regalloc_density_order` (K2/RC-3), `regalloc_decl_tie` (K1/RC-3), `sched_zero_store_spacer` (C0129),
  `regalloc_abs_const_lw` (C0130).
- loop: `loop_rev_ne_vtop` (L3), `loop_rev_counting_only` (L3), `loop_const_hoist` (L4).
- cse_expr: `div_pow2_signed` (E5), `xjump_tail_merge` (E3), `cse_call_retie` (K§3), `cse_volatile_asm_flush`
  (K§1-g), `expr_mult_first_sum` (E4).

## Triage table
The key of the table is the symptom. Find the tell. Open the map §. Try the lever family. Rerun the lever id as
the worked example.

`(C0002)` marks a row of cookbook/C0002.md. `—` means that the row has no byte-proven lever yet. The § is then the
pointer.

| Tell in the diff | Pass (map §) | Lever family | Lever ids |
|---|---|---|---|
| a temporary in a spill slot (C0002) | reload / global (regalloc.md §B RC-1, RC-2, RC-8) | reshape the live range, or declaration order | `regalloc_decl_tie` |
| every small edit moves 20+ insns (C0002) | local-alloc pressure lock (regalloc.md §B RC-6, sched.md S11) | hand to the permuter | — |
| a load stuck below a store while other loads float (C0002) | `/s` aliasing (cse_expr.md K§4) + sched dep (sched.md S3) | the source's aliasing facts | `alias_struct_grant` |
| a phantom callee-saved register (C0002) | cross-call value cse (cse_expr.md K§3) / alloc order (regalloc.md RC-3) | Count the uses. Re-shape. Re-tie per call. | `cse_call_retie`, `regalloc_density_order` |
| a shift off by ×4 against the target (C0002) | front-end pointer scaling, not a map pass (nearest cse_expr.md E4/E5) | cast through a byte pointer | `expr_byte_ptr_scale` |
| a branch's arms swapped (C0002) | dbr eager fill (sched.md D3) | put the fall-through block in the `if` | `dbr_branch_polarity` |
| a cross-jumped tail merged or not merged (C0002) | jump2 cross-jump (cse_expr.md E3) | shape the shared block count | `xjump_tail_merge` |
| latency-1 insns permuted among ties | sched1 (sched.md S1) | statement order | `sched_stmt_order` |
| def placed far from / sunk to its use | sched birthing boost (sched.md S2) | single-set vs reused temp | `sched_birth_boost` |
| batched vs paired loads | sched (sched.md S12, S4) | reused-temp fence | `sched_reused_temp_fence` |
| delay slot `nop` vs filled, slot content wrong | reorg (sched.md D1, D2, D4) | eligibility, or statement order | — |
| `$s0`/`$s1` swapped, unequal use counts | global density priority (regalloc.md K2, RC-3) | refs / live-range shaping | `regalloc_density_order` |
| `$s0`/`$s1` swapped, equal density | pseudo creation order (regalloc.md K1, RC-3) | swap declarations | `regalloc_decl_tie` |
| down-count `addiu -1` + `bne`/`bgez` vs up-count `slt` | loop reversal (loop.md L3) | index use in body, or loop shape | `loop_rev_ne_vtop`, `loop_rev_counting_only` |
| invariant load at loop head vs hoisted to preheader | loop invariant motion (loop.md L4) | `const`/volatility of the operand | `loop_const_hoist` |
| IV count / giv shape / endtest differs | loop strength reduction (loop.md L1, L2, L5-L8) | IV form of the source | — |
| `bgez`+`addiu` bias vs plain `sra` | expmed signed divide (cse_expr.md E5) | `/ 2^k` vs `>> k` | `div_pow2_signed` |
| recompute where target reuses, no label/call between | cse table flush (cse_expr.md K§1-g, K§1-f) | operand-less volatile asm / statement split | `cse_volatile_asm_flush` |
| address register/operand order in a sum | expression expansion (cse_expr.md E4) | operand order, MULT first | `expr_mult_first_sum` |
| per-call `addiu $aN,$sp,K` vs cached `$sN` | cse address caching (cse_expr.md K§2) | hoist vs remat | — |
| frame offsets ±8 / out of decl order | frame layout (cse_expr.md K§5) | temp population, or decl order | — |

## Residual classes
This table is the vocabulary that T6's `plateau.py classify` emits as `class <c>`. The names come from the kit's
residual classifier (decision order, first match wins). The table routes the names to our pin's groups. Bytes
decide the class. The byte gate decides the match.

| Class | Definition | Routes to |
|---|---|---|
| MATCH | masked streams identical | none: integration / reconcile, not codegen |
| EMPTY | one stream empty | none: harness fault |
| LENGTH-DRIFT | lengths differ, and one shift point explains the tail | small delta: permuter. Else: structural (frame, loop L4, cross-jump E3 rows) |
| SIZE-MISMATCH | lengths differ wildly, no shift explains | redraft: not a near-miss |
| SHIFT-DRIFT | equal length, and a small shift realigns most of the tail | structural: one insn moved (sched S2/S3, loop L4 rows) |
| REGALLOC-PERM | register-only diffs, one consistent injective reg map | regalloc: `$s` swap rows (K1/K2, RC-3), and the permuter |
| SCHEDULE-REORDER | same masked insns, different order | sched: S1-S5, S12 rows, and the permuter |
| DELAY-SLOT | `nop` vs insn at the diff positions | sched D1-D4 rows (branch-arms row for polarity) |
| REGALLOC-LOCAL | register-only diffs, no consistent map | regalloc RC-2/RC-4/RC-8 rows (spill, phantom callee-saved) |
| WIDTH | load/store width flip | structural C idiom (types): no map pass |
| STRENGTH | mult/div vs shift/add | cse_expr E5 (`div_pow2_signed` row) |
| ADDRESSING | `addu`/`addiu`/`lui` base-address shape | cse_expr K§2, E4 rows, and structural |
| BRANCH-POLARITY | `beq`/`bne`, `bgez`/`bltz` flips | branch-arms row (sched D3), and loop L3 guard rows |
| OPCODE-MIXED | different operations, no single family | structural: read the map by pass dump |
| IMM-OFFSET | same ops/regs, immediates off by a constant | frame layout (cse_expr K§5) or struct layout, and the ×4 row |
| IMM-VALUE | same ops/regs, unrelated immediates | cse constant (cse_expr K§1), or wrong constant in source |
| MIXED | several kinds, none dominant | unknown: LLM tier |
| UNKNOWN | opcode the decoder does not cover | unknown: counted, never bucketed |

The plateau labels (`plateau.py classify … label <l>`) follow. Each stalled permuter run has one label, and the
route of the class is its key:
- `missing-transform` — the class routes to the permuter (REGALLOC-*, SCHEDULE-REORDER, DELAY-SLOT, small
  LENGTH-DRIFT, IMM-VALUE), but the run plateaued. The cause is a lever that the permuter lacks. Add a transform or
  a levers.yaml entry.
- `mis-classified` — the stored class/route disagrees with what the bytes say. Re-route. Do not grind.
- `seed-structural` — the class is structural (WIDTH, BRANCH-POLARITY, ADDRESSING, STRENGTH, IMM-OFFSET,
  SHIFT-DRIFT, big LENGTH-DRIFT, SIZE-MISMATCH). Fix the seed's C shape via the triage row first. Permuter CPU is
  waste.
- `wall` — none of the above applies after a walk of the triage rows and the lever ladder. The label requires
  evidence (G61), never a closeness number.
