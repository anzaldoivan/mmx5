# sched.md — scheduling + delayed-branch: pass → residual → lever (gcc-2.95.2-psx pin)

Translation of the kit's `gcc-2.7.2-map/sched.md` (S1-S13, D1-D5) to our pin. Kit = consulted, not copied;
every claim re-derived on the staged tree `refs/gcc-2.95.2-psx/` (cites audited by `cites.py check`).
Status: `transfers` (mechanism present, same lever) · `changed` (present, different behaviour/lever) · `absent in 2.95.2`.
Experiments: `.run/t3/c1/*.c` (scratch, `levers.py dump` + pin compile); byte-proven levers in `levers.yaml` (group `sched`).

## 0. Which scheduler the pin runs

- `sched.c`, NOT `haifa-sched.c`. configure picks haifa only on an explicit `--enable-haifa` or for
  alpha/hppa/powerpc/rs6000/sparc/m32r: gcc/configure.in:3552 enable_haifa; prefix set at
  gcc/configure.in:4291 sched_prefix; object is gcc/Makefile.in:682 SCHED_PREFIX. Pin is `--target=mips-sony-psx`
  with no `--enable-haifa` (refs/old-gcc Dockerfile) → `sched.o`. No interblock scheduling: bb-local, like 2.7.2.
- Pass order: sched1 gcc/toplev.c:4133 schedule_insns → local/global alloc + reload → prologue/epilogue RTL
  gcc/toplev.c:4266 thread_prologue_and_epilogue_insns → sched2 gcc/toplev.c:4283 schedule_insns →
  dbr gcc/toplev.c:4342 dbr_schedule. -O2 turns both sched passes on: gcc/toplev.c:4869 flag_schedule_insns.
- Pin cpu = R3000 (gcc/config/mips/psx.h:61 MIPS_CPU_STRING_DEFAULT): load latency 2
  (gcc/config/mips/mips.md:159 define_function_unit), imul 12 (gcc/config/mips/mips.md:188 eq_attr).
- psx default flags include split addresses (gcc/config/mips/psx.h:24 MASK_SPLIT_ADDR): globals are `lui %hi`
  + `%lo(sym)($r)`, two length-1 insns, not `-G0` macro loads/stores. Changes D2 below.
- Dump tells (as kit, verified in `.run/codegen/dumps/<stem>/<stem>.c.sched`): `(7f000001)` = boosted,
  `;; blocking insn N for K cycles`, `;; insn N has a greater potential hazard`.

## 1. Pick algorithm (sched.c, backward list scheduling per bb)

- Priority = longest chain: gcc/sched.c:960 insn_cost (pred priority + cost - 1; all-latency-1 → all 1).
- Anti/output deps cost 0 → clamped 1: gcc/config/mips/mips.h:3785 ADJUST_COST; clamp gcc/sched.c:880 LINK_COST_FREE.
- Rank: priority, then class vs last scheduled (data dep with cost>1 demoted), then LUID:
  gcc/sched.c:1837 rank_for_schedule; LUID tie-break gcc/sched.c:1881 INSN_LUID.
- Unit hazards + potential hazard reorder within an equal-priority group: gcc/sched.c:2070 schedule_select.
- Birthing boost (pre-reload only): gcc/sched.c:1958 adjust_priority → gcc/sched.c:1990 birthing_insn_p.
- Tail pin (jumps/calls/USEs stay at bb end): gcc/sched.c:2780 TAIL_PRIORITY.
- Calls flush pending memory lists → no memory op crosses a call: gcc/sched.c:1703 flush_pending_lists.
- Memory dep oracle moved to alias.c in 2.95: gcc/alias.c:949 memrefs_conflict_p; `/s` vs scalar test
  gcc/alias.c:1182 MEM_SCALAR_P. `-fstrict-aliasing` off by default (gcc/toplev.c:763 flag_strict_aliasing).

## 2. Residual classes

### S1 — equal-priority order = source order · transfers
- Pass: sched1 rank tie-break gcc/sched.c:1881 INSN_LUID (sort gcc/sched.c:1829 qsort).
- Residual: same insns, permuted, latency-1 block. Lever: reorder statements to the target order.
- Experiment: lever `sched_stmt_order` (byte-proven): three store chains follow statement order exactly.

### S2 — birthing boost: single-set def sinks to use, multi-set def does not · transfers
- Pass: sched1 gcc/sched.c:1990 birthing_insn_p; discriminator gcc/sched.c:1941 REG_N_SETS (dest live + 1 set).
  Dest test is `REG` only, hard regs qualify (gcc/sched.c:1931 SET_DEST) — kit's 2026-07-28 correction holds.
  Off after reload: gcc/sched.c:1927 reload_completed.
- Lever: create the boost = fresh single-set local; kill it = second surviving set.
- Experiment: lever `sched_birth_boost` (byte-proven): reused `k` (2 sets) → set #2 shows `(1)` in sched dump,
  first k chain stays at block head; fresh `m` → `(7f000001)`, both defs sink to their stores.

### S3 — load/mul-fed chain sinks below lower-priority stores · transfers
- Pass: gcc/sched.c:892 priority (+1 per load on R3000, +11 per imul); priority dominates LUID
  (gcc/sched.c:1848 INSN_PRIORITY). No C edit lowers a priority. Lever: equalise sibling chains or permuter.

### S4 — one insn wedged between a load and its consumer · transfers
- Pass: cost>1 link queues the pred: gcc/sched.c:2058 queue_insn; tick gcc/sched.c:2043 INSN_TICK.
- Lever: statement order picks the filler among ready equal-priority insns; add/remove an independent stmt.
  Observed: `sched_reused_temp_fence.after.c` puts `sw` between `lhu` and its `subu`.

### S5 — memory ops spaced / memory ops pulled ahead among ties · transfers
- Pass: gcc/sched.c:2094 actual_hazard (queue blocked unit users), gcc/sched.c:2119 potential_hazard
  (largest hazard to the front, over LUID). Seen in `.run/codegen/dumps/s2c/s2c.c.sched`:
  `insn 28 has a greater potential hazard`. Lever: filler availability via statement order.

### S6 — independent insn between address-gen and use · transfers
- Pass: class rule gcc/sched.c:1859 insn_cost (cost-1 links = class 3) + gcc/config/mips/mips.h:3785 ADJUST_COST
  (anti/output always cost-free). Lever: which independents are ready (statement order).

### S7 — prologue/epilogue saves interleave with the body · changed
- Prologue RTL: gcc/config/mips/mips.c:6289 mips_expand_prologue (saves emitted by
  gcc/config/mips/mips.c:5681 save_restore_insns). Transfers: `sw $16` lands in the first `jal` slot (scratch s2b.c).
- Epilogue: 2.7.2 kit said the epilogue expander was dead. In 2.95.2 it is live
  (gcc/config/mips/mips.md:9430 mips_expand_epilogue) and inserted before sched2
  (gcc/toplev.c:4266 thread_prologue_and_epilogue_insns) → restores ARE in sched2's pool.
  Observed (scratch d2.c): `lw $31,16($sp)` woven between body `lui`/`li`, `addu $sp` in the `j $31` slot.
- Lever: body-side order (S1/S2) moves the weave; restore order itself is fixed by save_restore_insns.

### S8 — bb0 head-skip of leading param copies · absent in 2.95.2
- The head-skip loop exists but sits in an `#if 0` block, sched.c lines 2648-2686
  (body at gcc/sched.c:2661 reload_completed). Param copies `pseudo = $aN` ARE scheduled.
- Observed: s2c sched dump, param copies insn 4/6/8 in the ready list, insn 8 (`a2`) reordered ahead of insn 15.
- Consequence: no immovable head; param copies follow S1/S2 like any single-set move (boosted).

### S9 — sched1 order persists through sched2 · transfers
- sched2 runs the same code with LUIDs = sched1 output; no boost after reload (gcc/sched.c:1963 reload_completed).
  New vs kit: epilogue restores also enter sched2 (S7). Diagnose order residuals in `.sched` first.

### S10 — `-fno-schedule-insns[2]` attribution · transfers
- Flags: gcc/toplev.c:907 flag_schedule_insns, gcc/toplev.c:909 flag_schedule_insns_after_reload,
  gcc/toplev.c:897 flag_delayed_branch. Diagnostic only, never a fix (the pin's cflags are fixed).

### S11 — LUID ⊗ allocation coupling · transfers (treat as constraint)
- sched1 runs before allocation (gcc/toplev.c:4161 local_alloc after gcc/toplev.c:4133 schedule_insns) and
  rewrites reg counts the allocator reads (gcc/sched.c:4171 reg_n_sets). Any S1/S2 lever can flip allocation;
  apply one lever at a time, re-score. Allocator side: see regalloc.md.

### S12 — reused-temp fence: batch vs pair loads · transfers (type trap included)
- Pass: dep build gcc/sched.c:1490 sched_analyze_insn; reused pseudo gets output dep
  (gcc/sched.c:1191 REG_DEP_OUTPUT) and anti dep (gcc/sched.c:1188 REG_DEP_ANTI) on the second pair.
- Type trap transfers although mips.h now defines gcc/config/mips/mips.h:1542 PROMOTE_MODE: `unsigned short`
  reused temps still batch (4 lhu then 2 subu); `int` temps pair (`lhu;lhu;subu` twice).
- Experiment: lever `sched_reused_temp_fence` (byte-proven). Unfenced plain form (scratch s12c.c) batches too.
- Pin note: kit's "pin dest kills boost" was refuted; still true here (S2 dest test is REG-only).

### S13 — head-skip escape via body-local param copy · changed
- Its premise (S8 head pinning) is absent: param copies already float. The asm-copy and dead-read sub-levers are
  pass-agnostic and still apply (cse cannot see through asm). The reorder effect now comes from S1/S2 alone;
  re-derive on a real case before using. Dep source for the dead-read fence: gcc/sched.c:1490 sched_analyze_insn.

### D1 — delay slot = nearest eligible insn above the branch/call · transfers
- Pass: gcc/reorg.c:1998 fill_simple_delay_slots backward scan (gcc/reorg.c:2117 stop_search_p); the owner's
  sets/needs computed without delayed effects (gcc/reorg.c:2114 mark_set_resources) → arg setups fill their own
  call's slot. Observed: `j $31` slot gets the last store (sched_stmt_order), `jal` slot gets the `$16` save.
- Lever: make the wanted insn adjacent pre-dbr (S1/S2).

### D2 — slot stays nop: eligibility · changed
- Rule: gcc/config/mips/mips.md:125 define_delay (slot insn `dslot=no` and `length=1`);
  loads/hilo/xfer are `dslot=yes` on MIPS1 (gcc/config/mips/mips.md:91 dslot) → never in a slot. Transfers.
- Changed: global stores are split `%hi/%lo` (S0, MASK_SPLIT_ADDR), so `sw $r,%lo(A)($2)` IS slot-eligible.
  Observed (scratch d2.c): `beq …; sw $5,%lo(A)($2)`. The kit's "-G0 macro store → nop" tell does not apply.
- No annulled slots: gcc/config/mips/mips.md:102 branch_likely is no at MIPS1.

### D3 — target/fallthrough-thread steal (eager fill) · transfers
- Pass: gcc/reorg.c:2892 fill_eager_delay_slots → gcc/reorg.c:2491 fill_slots_from_thread; direction
  gcc/reorg.c:891 mostly_true_jump (EQ not-taken gcc/reorg.c:981 EQ; NE taken gcc/reorg.c:983 NE).
  Dest must be dead on the opposite thread (gcc/reorg.c:2611 opposite_needed). Move vs copy:
  gcc/reorg.c:1811 own_thread_p, gcc/reorg.c:2674 copy_rtx. Afterwards gcc/reorg.c:3020 relax_delay_slots
  (inversion gcc/reorg.c:3077 invert_jump).
- New in 2.95: `mostly_true_jump` reads REG_BR_PROB first, only under `-fbranch-probabilities`
  (gcc/reorg.c:901 flag_branch_probabilities); off at the pin.
- Lever: branch polarity. Experiment: lever `dbr_branch_polarity` (byte-proven): `c == 0` puts `addu $2,$5,2`
  in the `bne` slot, `c != 0` puts `addu $2,$5,1` in the `beq` slot.

### D4 — slot insn reads the pre-copy register · transfers
- Pass: gcc/reorg.c:2745 validate_replace_rtx (thread head `r2=r1; use r2` → use rewritten to r1).

### D5 — shared exit: slot takes the insn at a common jump target · transfers
- Pass: fill_simple stop at unconditional jump gcc/reorg.c:2316 simplejump_p; copies the target insn
  (gcc/reorg.c:2340 add_to_delay_list) and redirects both jumps.

## 3. Triage (tell → item)
- permuted latency-1 insns → S1 · def placement single vs multi set → S2 · load/mul chain late → S3 (permuter)
- one insn between load and use → S4 · memory ops spaced/pulled → S5 · callee-save `sw`/`lw` woven → S7
- param copy order differs at function head → S8/S2 (no head pin here) · batched vs paired loads → S12
- slot content wrong → D1 then S1/S2 · `nop` vs filled → D2 · arm insn in branch slot → D3 polarity
- `label+4` target / duplicated insn → D3 copy-steal · slot reads copy source → D4.
