# loop.md — loop optimiser: pass → residual → lever (gcc-2.95.2-psx pin)

Translation of the kit's `gcc-2.7.2-map/loop.md` (L0-L8, routing, movables order, giv-init fence) to our pin.
Kit = consulted, not copied; every claim re-derived on the staged tree `refs/gcc-2.95.2-psx/` (cites audited by
`cites.py check`). Status: `transfers` · `changed` · `absent in 2.95.2`.
Experiments: `.run/t4/c1/*.c` (scratch, pin compile + `levers.py dump`); byte-proven levers in `levers.yaml` (group `loop`).
The kit's 2.7.2-vs-2.8.1 caveat table mostly lands on the 2.8.1 side here: 2.95.2 descends from 2.8/egcs.

## 0. L0 — flags, pass order, thresholds, dump tells · changed

- -O2 sets gcc/toplev.c:4863 flag_strength_reduce and gcc/toplev.c:4865 flag_rerun_loop_opt.
  Unroll off: gcc/toplev.c:505 flag_unroll_loops (no -O2 default; `-funroll-loops` forces strength reduce,
  gcc/toplev.c:5400 flag_unroll_loops).
- NEW vs 2.7.2: loop runs TWICE. First gcc/toplev.c:3939 loop_optimize (unroll 0, bct 0), dead insns deleted,
  then gcc/toplev.c:3952 loop_optimize (flag_unroll_loops, bct 1). The `.loop` dump holds both runs; decision
  lines appear per run (grep counts are doubled).
- Pass order: cse gcc/toplev.c:3871 cse_main → gcse gcc/toplev.c:3907 gcse_main (NEW, -O2) → loop ×2 → cse2
  gcc/toplev.c:3983 cse_main → flow/combine/regmove/sched/alloc. Loop decisions surface post-regalloc.
- Hoist threshold gcc/loop.c:701 threshold `(call?1:2)*(1+n_non_fixed_regs)`; strength-reduce threshold
  gcc/loop.c:3723 threshold `(call?1:2)*(3+n_non_fixed_regs)` (count from gcc/regclass.c:376 n_non_fixed_regs).
  Same shape as kit. Benefit units: gcc/loop.c:407 add_cost (rtx_cost PLUS), gcc/loop.c:419 copy_cost.
- Giv worth-while test (`lifetime*threshold*benefit < insn_count` → ignored) at gcc/loop.c:4714
  flag_reduce_all_givs; benefit already net of `add_cost*biv_count` (gcc/loop.c:4677 add_cost).
- Dump phrases (verified in `.run/codegen/dumps/<stem>/<stem>.c.loop`): `Can reverse loop`, `Reversed loop and
  added reg_nonneg`, `biv N can be eliminated.`, `Cannot eliminate biv N: biv used in insn M.`,
  `giv of insn N not worth while, P vs I.`, `Insn N: regno R (life L), ... moved to M`, NEW `Sorted combine
  statistics:` + `giv at X combined with giv at Y`.

## 1. Residual classes

### L1 — IV count & shape (bivs, givs, combine_givs anchor) · changed
- Pass: gcc/loop.c:5928 basic_induction_var; gcc/loop.c:5220 find_mem_givs; gcc/loop.c:6867 combine_givs_p
  (gcc/loop.c:6808 express_from); gcc/loop.c:6931 combine_givs called at gcc/loop.c:4643 combine_givs.
- Transfers: each separately incremented pointer/index is its own biv; bivs never merge.
- Changed (1): bare `*q` (mult 1, add 0) IS a mem giv now — exclusion removed (gcc/loop.c:5257 GIVs comment).
  Experiment `.run/t4/c1/f1.c` vs `f2.c` (walked `q += 32` read as `*q,q[8],q[20]` vs `q[4],q[8],q[20]`):
  identical IV set (q biv + reversed counter), no extra IV — kit's "bare deref → 3 IVs" does not reproduce.
- Changed (2): anchor choice. 2.95.2 sorts givs by total benefit, descending, ties by giv number:
  gcc/loop.c:7002 qsort with gcc/loop.c:6918 total_benefit. Kit's "last-emitted giv anchors" list-head rule
  does not hold; the highest-benefit giv anchors. Giv recombination is compiled out
  (gcc/loop.c:4796 recombine_givs under `#if 0`).
- Tell: preheader `addiu rIV,rBASE,A` + offset cluster `k(rIV)` = combined givs; parallel `addiu` per biv.
- Lever: as kit — one walked pointer with all fields as offsets for one IV; two walked pointers for two IVs.
  Anchor = benefit order (use counts per giv), not emission order. Experiment for the anchor: index-derived
  `base + i*S` with fields of differing use counts; read `Sorted combine statistics` in the `.loop` dump.

### L2 — index-biv elimination / endtest rewrite · changed
- Pass: gcc/loop.c:8188 maybe_eliminate_biv → gcc/loop.c:8333 maybe_eliminate_biv_1; executed only when
  gcc/loop.c:5089 all_reduced. Bound placement gcc/loop.c:8204 where (preheader iff threshold ≥ insn_count).
- Changed (as kit's 2.8.1 column): compare-vs-constant needs the giv's add to be symbol/label/const or a
  pointer REG (gcc/loop.c:8479 SYMBOL_REF, gcc/loop.c:8483 REGNO_POINTER_FLAG); the const-int-add and
  compare-vs-invariant-REG/MEM arms are disabled with `&& 0` (gcc/loop.c:8552 invariant_p guards the latter).
  So variable-bound `i < n` loops do NOT eliminate i through a giv — but see L3: they usually get reversed onto n.
- Tell: `slt rI,rN` up-count + separate pointer IV = biv kept; `sltu rP,rEnd` = pointer walk written in C.
- Lever: pointer form `for (p = a; p < a + n; p++)` gives the `sll/addu` end + `sltu` endtest
  (experiment `.run/t4/c1/a2.c`); index form gives the L3 NE count-down (lever `loop_rev_ne_vtop` before).

### L3 — loop reversal → count-down (check_dbra_loop) · changed
- Pass: gcc/loop.c:7654 check_dbra_loop; counting-only detection gcc/loop.c:7792 no_use_except_counting.
- Changed (1): general reversal disjunct still needs no call (gcc/loop.c:7873 loop_has_call), BUT a
  counting-only biv reverses regardless (`|| no_use_except_counting`), call or not.
- Changed (2): nonzero constant start is normalized when counting-only (gcc/loop.c:7938 no_use_except_counting)
  — kit's "start must be literal 0" is 2.7.2-only. Vanilla GE reversal gcc/loop.c:7959 initial_value,
  gcc/loop.c:7979 cmp_code → `li N-1 … addiu -1; bgez`, REG_NONNEG note gcc/loop.c:8148 REG_NONNEG.
- NEW: NE reversal gcc/loop.c:7986 cmp_code — increment 1, loop has a VTOP note (rotated while/for), biv
  counting-only: the counter is loaded with the trip count and counted to 0
  (`addu rN,rN,-1; bne rN,$0`), even with a VARIABLE bound. Do-while loops have no VTOP → no NE reversal.
- Experiments: lever `loop_rev_counting_only` (byte-proven): `for (i = 1; i < 10; i++) ext(0)` → `li 8 … bgez`
  despite the call and the 1-start; passing i → up-count `slt …,10`. Lever `loop_rev_ne_vtop` (byte-proven):
  `for` index sum → n counted down with `bne $5,$0`; same loop as guarded do-while → `slt i,n` up-count
  (dump: `Can reverse loop` then no `Reversed`).
- Lever: target count-down → natural `for` with the counter otherwise unused; target up-count where yours
  reverses → use the counter, or write do-while (kills NE), or non-unit step.
- decrement_and_branch_on_count/BCT: absent in 2.95.2 for MIPS (gcc/loop.c:5162
  HAVE_decrement_and_branch_on_count; mips.md defines no such pattern).

### L4 — invariant hoisting / preheader copies · changed
- Pass: gcc/loop.c:634 scan_loop (trap guard gcc/loop.c:894 may_trap_p), gcc/loop.c:1444 combine_movables,
  gcc/loop.c:1739 move_movables (`not desirable` gcc/loop.c:2211 loop_dump_stream), gcc/loop.c:3187 invariant_p.
- Transfers: a non-const call sets unknown_address_altered (gcc/loop.c:2451 CONST_CALL_P → plain loads not
  invariant, gcc/loop.c:3259 unknown_address_altered). NEW: `const`-attribute calls do not.
- Transfers: single-use invariant in a call loop is substituted into its use and the set deleted
  (gcc/loop.c:913 loop_has_call) → in-loop `la`/`lui` at the call-arg site is this, not a missed hoist.
- Changed: the RTX_UNCHANGING exception (gcc/loop.c:3254 RTX_UNCHANGING_P) holds for `const` OBJECTS, not for
  `const T *` pointees: `extern const int K` hoists out of a call loop; `const int *p; … *p` does NOT
  (experiment `.run/t4/c1/d1.c` vs `d2.c`: identical in-loop `lw 0($19)`). Kit's `const int *p` proof is 2.7.2-only.
- Experiment: lever `loop_const_hoist` (byte-proven): plain `extern int K` → `lw $2,%lo(K)` at loop head every
  iteration; `extern const int K` → load in preheader, and `s += K` then becomes a biv with pre-add/post-sub
  compensation (L5 shape).
- NEW (2.95.2): memory promotion gcc/loop.c:9475 load_mems (via gcc/loop.c:1170
  load_mems_and_recount_loop_regs_set). Gate: no unknown_address_altered, no call, no alloca, single exit
  (gcc/loop.c:2519 loop_has_call). Effect: a global read-modify-written in the loop lives in a register, one
  load in the preheader, one store after the loop. Experiment `.run/t4/c1/c1.c` (`g += a[i]`, no call: `lw` before,
  `sw` after loop) vs `c3.c` (call in loop: `lw/addu/sw` every iteration).
- Tell: preheader `lw` of a global + post-loop `sw` = load_mems; in-loop reload + `jal` = unknown_address_altered.
- Lever: add/remove a call or second exit, or make the object `const`; caching in a local in C is usually
  redundant with load_mems in call-free loops.

### L5 — giv replaceability / final-value compensation · transfers
- Pass: gcc/loop.c:5413 record_giv, gcc/loop.c:5659 check_final_value, final values from
  gcc/unroll.c:3270 final_biv_value, gcc/unroll.c:3347 final_giv_value (iterations: gcc/unroll.c:3584 loop_iterations).
- Tell: `addiu rX,rX,±K` straddling the loop boundary; `move rOld,rIV` after a non-replaceable giv.
- Observed: lever `loop_const_hoist` after shows the pair (`addu $17,$17,$18` before `$L8`, `subu` after).
- Lever (soft, as kit): keep a derived value's uses on one side of the increment; create the crossing if the
  target shows the compensation.

### L6 — reduced-giv increment placement · transfers
- Pass: gcc/loop.c:4928 insert_before (`tv->insn`: each reduced giv's add goes right before its biv increment;
  auto-inc variants unreachable on MIPS). Order after that = sched (see sched.md). Intrinsic; route to sched/permuter.

### L7 — whole loop skipped (invalid) · transfers
- Pass: gcc/loop.c:2592 find_and_verify_loops; invalid on setjmp gcc/loop.c:2632 loop_invalid, forced/computed
  labels gcc/loop.c:2706 forced_labels, jump into the loop from outside. Invalid → no hoist/reduce/reverse.
- Tell/lever: as kit — an -O0-looking loop in an -O2 function: look for an into-loop jump, reproduce it.

### L8 — not_every_iteration / increment position · changed
- Pass: biv scan gcc/loop.c:3862 not_every_iteration, giv scan gcc/loop.c:4516 not_every_iteration;
  reset at gcc/loop.c:3873 NOTE_INSN_LOOP_VTOP / LOOP_CONT.
- Changed: a jump whose target is a loop exit label does NOT set the flag (gcc/loop.c:3855
  loop_number_exit_labels) — the 2.8.1 behaviour; 2.7.2 set it on any jump.
- Lever: as kit — position of `p += K`/`i++` relative to non-exit branches, `continue` placement.

## 2. Kit appendices

### Movables emission order (bitfield mask decoupler) · transfers
- Pass: gcc/loop.c:1739 move_movables emits in scan order; bitfield masking in gcc/expmed.c:622
  store_fixed_bit_field. Not re-proven at the pin; experiment: kit's setaddr-style bitfield store vs mask expr,
  compare preheader `lui/ori` order.

### Giv-init fence (force emit_iv_add_mult's init move) · transfers
- Pass: gcc/loop.c:7516 emit_iv_add_mult; the move is emitted only when the computed reg differs
  (gcc/loop.c:7537 reg). Lever as kit (`asm("":"=r"(b):"0"(b))` before `dst = b`); not re-proven at the pin.

## 3. Not loop.c (routing)
- `while` vs `do-while` exit-test duplication: gcc/jump.c:2551 duplicate_loop_exit_test (jump.c). It now MATTERS
  to loop.c: the VTOP note it leaves enables the L3 NE reversal (lever `loop_rev_ne_vtop`).
- Store/load order, `/s` aliasing → alias.c/expr.c (cse_expr.md, sched.md). Cross-jump → cse_expr.md.
- Unrolling: gcc/unroll.c:223 unroll_loop reached only with unroll_p (gcc/loop.c:3950 unroll_loop), i.e.
  `-funroll-loops`; dead at -O2. unroll.c supplies loop_iterations and final values to L3/L5.

## 4. Rejected lever candidates (scratch, `.run/t4/c1/`)
- `const int *p` hoist (d1/d2): no codegen change at the pin (L4 changed).
- bare vs offset deref of a walked pointer (f1/f2): same IV set (L1 changed).
- load_mems call/no-call (c1/c3): proven difference, but the C change (adding a call) is not a lever.
