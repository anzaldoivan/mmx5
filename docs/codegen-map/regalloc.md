# gcc-2.95.2-psx register allocation + reload → residual → C-lever map

Pass group: `regmove` → `sched1` → `local-alloc` → `global-alloc` → `reload` (+ `reload_cse_regs`).

Source: `refs/gcc-2.95.2-psx/gcc/{regmove.c,local-alloc.c,global.c,reload.c,reload1.c,flow.c}` + `config/mips/mips.h` (as staged, `tools/codegen/stage.sh`).

Translated from the kit map `gcc-2.7.2-map/regalloc.md` (2.7.2/2.8.1 lines). Those lines are never reused here — every line below is re-derived and audited by `cites.py check`.

Shape per item: pass → residual pattern → lever → experiment → citation. Status `transfers | changed | absent in 2.95.2`.

Experiment tags: `byte-proven` = a `levers.yaml` record green under `levers.py check`. `source-read` = mechanism read in the staged tree, not byte-tested in this task.

Dumps: `PY tools/codegen/levers.py dump <file.c>` → `.run/codegen/dumps/<stem>/`. `.lreg` holds `Register N used R times across L insns` (gcc/flow.c:4243 fprintf). `.greg` `;; N regs to allocate: …` lists the global allocnos IN PRIORITY ORDER (gcc/global.c:1781 fprintf), then `;; Register dispositions:` (gcc/global.c:1831 fprintf).

## Pass order (2.95.2, -O2 as pinned: `-O2 -G0`)
- regmove runs at -O2 (`flag_regmove = 1`: gcc/toplev.c:4872 flag_regmove, call gcc/toplev.c:4111 regmove_optimize) — **new vs kit** (2.7.2 has no regmove).
- sched1 (gcc/toplev.c:4133 schedule_insns) rewrites REG_LIVE_LENGTH (gcc/sched.c:4431 sched_reg_live_length) → every schedule lever is also an allocation lever (see sched.md).
- refs recounted after sched1 (gcc/toplev.c:4159 recompute_reg_usage), then gcc/toplev.c:4161 local_alloc, gcc/toplev.c:4190 global_alloc (reload called from inside global_alloc), then gcc/toplev.c:4201 reload_cse_regs (post-reload cse/combine/move2add — **new vs kit**).

## Allocation order (DK-47: read this before any register lever)
- **Scan order.** `REG_ALLOC_ORDER` IS defined for MIPS in 2.95.2 (gcc/config/mips/mips.h:1916 REG_ALLOC_ORDER) but is the identity 0..75. It is kept only so mips16 can permute it (gcc/config/mips/mips.h:1929 ORDER_REGS_FOR_LOCAL_ALLOC → gcc/config/mips/mips.c:4507 mips_order_regs_for_local_alloc resets identity unless mips16). Global first-fit walks it (gcc/global.c:986 reg_alloc_order), local first-fit too (gcc/local-alloc.c:2040 reg_alloc_order). Net: plain regno order.
- **Callee-saved bank.** Not call-used GPRs = 16..23 and 30 (gcc/config/mips/mips.h:1598 CALL_USED_REGISTERS). 30 is allocatable (not in gcc/config/mips/mips.h:1581 FIXED_REGISTERS) when no frame pointer is needed. A call-crossing allocno is barred from every call-used reg on the first try (gcc/global.c:948 call_used_reg_set). So its grant order is **$s0 ($16), $s1 … $s7 ($23), then $fp ($30)**: the first-allocated call-crossing value takes $s0.
- **Who is first = global priority.** Allocnos are sorted once (gcc/global.c:545 qsort) by gcc/global.c:593 allocno_compare: `pri = floor_log2(refs)·refs / live_length · 10000 · size` (gcc/global.c:603 floor_log2), int-truncated, higher first. The refs per allocno are summed from REG_N_REFS (gcc/global.c:429 allocno_n_refs). The length = max REG_LIVE_LENGTH (gcc/global.c:430 allocno_live_length). **live_length is the denominator** (shorter range → higher priority). The refs are loop-depth weighted (gcc/flow.c:3373 loop_depth) — read `.lreg`, never hand-count inside loops.
- **Tie-break.** Equal int priority → lower allocno first (gcc/global.c:615 v1). Allocnos are numbered in pseudo-regno order (gcc/global.c:405 max_allocno), and a user local's pseudo is created at its **declaration** → equal-density contenders take $s0.. in declaration order.
- **Pass-0 frugality.** `regs_used_so_far` is pre-seeded with every call-used and already-live reg (gcc/global.c:362 call_used_regs). Pass 0 never opens a fresh callee-saved reg (gcc/global.c:973 regs_used_so_far) and skips regs that lower-priority conflicting allocnos prefer (gcc/global.c:974 regs_someone_prefers). Copy/plain preferences then override first-fit within the class (gcc/global.c:1025 hard_reg_copy_preferences).
- **Local-alloc first.** Single-block, single-death pseudos (gcc/local-alloc.c:366 REG_N_DEATHS) are allocated by local-alloc BEFORE global, with the same density formula per qty (gcc/local-alloc.c:1511 QTY_CMP_PRI) and qty-number tie-break (gcc/local-alloc.c:1535 q1). A call-crossing local qty can take $s0 there too. Check `.greg` `regs to allocate`: `0 regs` = local-alloc decided.
- **Reproducer 1 — density decides $s0 (byte-proven, `regalloc_density_order`).** Two call-crossing multi-block locals `a`, `b`. Only the use count changes.
  - Before: `.lreg` a=83 6 refs/11 insns, b=84 3/11 → pri 10909 vs 2727 → `.greg` `2 regs to allocate: 83 84`, dispositions `83 in 16 84 in 17` (`addu $16,$4,1`).
  - After (`return a + b*b*b`): a 4/12, b 5/10 → 6666 vs 10000 → `84 83`, `84 in 16` (`addu $17,$4,1`).
  - Lever: the target's $s0 is the higher-density value. To move a value into $s0, raise its refs or shrink its range (move the def later / last use earlier). Never use a pin first.
- **Reproducer 2 — equal density falls to declaration order (byte-proven, `regalloc_decl_tie`).** a, b both have 2 refs/7 insns (pri 2857 each). Swapping only `int a, b;` → `int b, a;` swaps which value is in $16 (`addu $16,$4,3` vs `addu $17,$4,3`). Control (scratch `.run/t3/c2/`, first tie attempt): with unequal lengths (7 vs 9), the same decl swap gave identical bytes. Decl order is a lever only on an exact tie.

## §A knobs (kit K1–K8 and the reload knobs)
- **K1 pseudo creation order** — transfers. Pass: expand/local-alloc/global/reload. Residual: equal-density swap, qty order, slot order. Lever: decl order (regno), birth order (qty: gcc/local-alloc.c:279 next_qty, handed out in gcc/local-alloc.c:274 alloc_qty during the forward scan of gcc/local-alloc.c:1032 block_alloc). Experiment: byte-proven `regalloc_decl_tie` (decl-time pseudo creation holds in 2.95.2). Cite: gcc/global.c:405 max_allocno.
- **K2 density priority** — transfers. Same formula both allocators (gcc/global.c:603 floor_log2, gcc/local-alloc.c:1511 QTY_CMP_PRI), denominator = live length, loop-weighted refs (gcc/flow.c:3610 loop_depth). Experiment: byte-proven `regalloc_density_order`. New in 2.95.2: refs are recounted after sched1 (gcc/flow.c:4935 recompute_reg_usage).
- **K3 hard-reg scan order** — changed (text), transfers (effect). Kit: "MIPS defines no REG_ALLOC_ORDER". 2.95.2 defines it as identity (gcc/config/mips/mips.h:1916 REG_ALLOC_ORDER) → global/local scan unchanged (regno order). Side effect: `#ifdef REG_ALLOC_ORDER` disables the skip-ahead in find_reg (gcc/global.c:986 reg_alloc_order) and switches reload's reg pool (see reload knobs). Experiment: byte-proven via both levers ($16 before $17).
- **K4 call-crossing ⇒ callee-saved, caller-saves ON** — transfers. `flag_caller_saves = 1` at -O2 (gcc/toplev.c:4866 flag_caller_saves). A retry with call-clobbered regs occurs when gcc/regs.h:201 CALLER_SAVE_PROFITABLE (`4*calls < refs`), in gcc/global.c:1109 CALLER_SAVE_PROFITABLE. Tell: caller-save slots natural-aligned (packed 4-byte, gcc/caller-save.c:313 assign_stack_local with align 0) vs spill slots 8-rounded (K7). source-read.
- **K5 two-pass frugality + preferences** — transfers. gcc/global.c:973 regs_used_so_far (pass 0 never opens a fresh reg), gcc/global.c:1513 set_preference, local analog gcc/local-alloc.c:2027 qty_phys_copy_sugg. Suggested qtys allocate first (gcc/local-alloc.c:1363 find_free_reg). source-read.
- **K6 eviction** — global part transfers. An allocno with no reg may kick out a local-alloc reg scanning from the highest regno (gcc/global.c:1141 reg_alloc_order) iff local refs/length < its refs/length (gcc/global.c:1162 local_reg_n_refs). Reload part changed: see reload knobs. source-read.
- **K7 spill slots** — transfers. Unallocated pseudos get slots in regno order (gcc/reload1.c:797 alter_reg), one fresh slot each (gcc/reload1.c:2422 assign_stack_local), size `MAX(inherent, reg_max_ref_width)` (gcc/reload1.c:2408 reg_max_ref_width). Align -1 → BIGGEST_ALIGNMENT 64 bits (gcc/config/mips/mips.h:1444 BIGGEST_ALIGNMENT, gcc/function.c:783 BIGGEST_ALIGNMENT) → 8-rounded slots. No slot when reg_equiv_constant/memory_loc is set (gcc/reload1.c:724 function_invariant_p). source-read.
- **K8 local vs global split & tying** — changed. Local gate unchanged (gcc/local-alloc.c:366 REG_N_DEATHS). Local tie at dest's first set when the source dies (gcc/local-alloc.c:1609 combine_regs, condition gcc/local-alloc.c:1747 already_dead). global still has no coalescing (preferences only, gcc/global.c:1513 set_preference). **Changed:** regmove now runs before both and rewrites copies (gcc/regmove.c:376 optimize_reg_copy_1, gcc/regmove.c:580 optimize_reg_copy_2). "two C variables ⇒ a surviving move" is no longer guaranteed. Read `.regmove` before assuming the copy reaches local-alloc. source-read.
- **Reload: spill-reg identity** — changed. 2.95.2 picks reload regs per insn chain: a reg live before/after the insn is bad for that insn only (gcc/reload1.c:4118 live_before). Unused regs are taken in REG_ALLOC_ORDER (gcc/reload1.c:4150 reg_alloc_order) — one regno-order pool, no "call-used first" split, so an unused $s reg precedes $t8/$t9. Used regs are then taken by ascending refs (gcc/reload1.c:4042 hard_reg_use_compare). `regs_explicitly_used` does not exist in 2.95.2 (grep: 0 hits in gcc/*.c) → the kit's "a pin poisons the pool function-wide" mechanism is absent. A pinned hard reg is excluded only where live. source-read.
- **Reload: round-robin** — transfers (gcc/reload1.c:5448 last_spill_reg in gcc/reload1.c:5398 allocate_reload_reg). source-read.
- **Reload: inheritance** — transfers (gcc/reload1.c:5894 reg_last_reload_reg in gcc/reload1.c:5606 choose_reload_regs). source-read.
- **Reload: delete_output_reload** — transfers (gcc/reload1.c:7924 delete_output_reload). source-read.
- **Reload: reload insn order by operand** — transfers (reloads recorded per operand in gcc/reload.c:2420 find_reloads, emitted by gcc/reload1.c:6504 emit_reload_insns). source-read.

## §B residual classes
- **RC-1 spill-slot offsets swapped** — transfers. Pass: reload. Lever: reorder the spilled locals' declarations (slot order = regno order, gcc/reload1.c:797 alter_reg). Assignment order is a no-op (decl-time pseudo creation re-confirmed by `regalloc_decl_tie`). Slot shape (8-rounded `$t`-reg access = genuinely spilled scalar) per K7. source-read.
- **RC-2 wrong value spilled / evicted param** — transfers. Pass: global. Residual: `sw $aN,slot / lw` of a param.
  - Lever: shrink/lengthen the contender's live range or change its refs (gcc/global.c:593 allocno_compare). Call-crossing flips K4.
  - Experiment: the density mechanism is byte-proven (`regalloc_density_order`). The spill outcome itself is source-read.
- **RC-3 callee-saved order permutation** — transfers. Pass: global (or local, see Allocation order). Lever: unequal density → refs/range shaping. Exact tie → swap declarations (gcc/global.c:615 v1). Pin last. Experiment: byte-proven both poles (`regalloc_density_order`, `regalloc_decl_tie`).
- **RC-4 copy coalescing** — changed. The local tie transfers (gcc/local-alloc.c:1747 already_dead). Un-tie by a later source use or earlier dest set. New: regmove may already have substituted src/dest before local-alloc (gcc/regmove.c:1650 fixup_match_1, gcc/regmove.c:376 optimize_reg_copy_1) — check `.regmove` for the copy first. source-read.
- **RC-5 pin side-effects** — changed.
  - ch.1 init copy: transfers (local tie as RC-4).
  - ch.2 reload-pool poisoning: changed — no `regs_explicitly_used`. The per-insn bad set comes from live regs (gcc/reload1.c:4118 live_before). The global `bad_spill_regs_global` comes only from frame-pointer cant_eliminate (gcc/reload1.c:3806 bad_spill_regs_global) and is fed to the retry (gcc/reload1.c:3921 retry_global_alloc).
  - ch.3 pass-0 shift: transfers (`regs_ever_live` seeds gcc/global.c:362 call_used_regs).
  - ch.4 range blocking: transfers.
  - source-read. The ch.2 claims need a byte test before use.
- **RC-6 pressure-locked flat allocation** — transfers (mechanism: births/deaths indexed per insn in gcc/local-alloc.c:1032 block_alloc). Kit downgrades (§F/§G/§H) stand: most "RC-6" verdicts were steerable. source-read.
- **RC-7 rematerialization vs spill** — changed.
  - (a) 2.95.2 accepts frame/arg-pointer + constant as an equivalence (gcc/local-alloc.c:643 function_invariant_p) and reload rematerializes it with no slot (gcc/reload1.c:730 reg_equiv_constant). So the kit's [A23] "a frame address never remats" is 2.7.2-only. `&local` may remat per use here.
  - (b) A multi-set reg keeps its equivalence if every set carries the same invariant REG_EQUAL (gcc/local-alloc.c:810 function_invariant_p). So "give it a second set" no longer reliably defeats the equiv.
  - (c) The doubling transfers (gcc/local-alloc.c:874 REG_LIVE_LENGTH).
  - (d) The "init moved to just before its use" pass, absent in 2.7.2, IS present (gcc/local-alloc.c:972 emit_insn_before, length forced to 2 at gcc/local-alloc.c:985 REG_LIVE_LENGTH).
  - (e) Call killer transfers (gcc/local-alloc.c:480 RTX_UNCHANGING_P in gcc/local-alloc.c:456 validate_equiv_mem).
  - (f) lui+ori second-set escape: unverified under (b).
  - source-read.
- **RC-8 reload artifacts** — transfers except reg identity (changed, see reload knobs). Cite: gcc/reload1.c:7924 delete_output_reload. source-read.
- **RC-9 cross-block copy the target folded** — transfers (global has no coalescing, gcc/global.c:1513 set_preference only). Lever: one variable updated in place. source-read.
- **RC-10 preference cascade** — transfers. set_preference unwraps one operand level (gcc/global.c:1523 GET_RTX_FORMAT). Preferences merge through deaths (gcc/global.c:801 expand_preferences), pruned (gcc/global.c:854 prune_preferences). Pass 0 skips others' preferences (gcc/global.c:974 regs_someone_prefers). source-read.
- **RC-11 ≤3-qty sort bug** — transfers. The 3/2-qty switch still compares fixed qty numbers while swapping order slots (gcc/local-alloc.c:1383 qty_compare, gcc/local-alloc.c:1385 qty_compare). ≥4 qtys use qsort. Lever: zero-byte decoy qty. source-read.
- **RC-11 caveat `#APP`** — transfers (asm emits gcc/config/mips/mips.h:3884 ASM_APP_ON markers). The delay-slot hop is the assembler's, see the toolchain notes. source-read.
- **RC-12 `$0`-add opaque copy** — transfers. `$0` is fixed (gcc/config/mips/mips.h:1581 FIXED_REGISTERS) → no allocation side channel. The cse copy-collapse it defeats is gcc/cse.c:957 make_regs_eqv. source-read.
- **RC-13 condition operand order sets reload birth** — transfers (scheduler side, live length rewrite gcc/sched.c:4431 sched_reg_live_length). source-read.
- **RC-14 reused load temps serialize** — transfers (no global coalescing, gcc/global.c:1513 set_preference). regmove caveat as K8. source-read.
- **RC-15 density dial across a floor_log2 boundary** — transfers (gcc/global.c:603 floor_log2, refs += loop_depth gcc/flow.c:3373 loop_depth). source-read.
- **local-alloc suggestion (dying hard reg suggests itself)** — transfers (gcc/local-alloc.c:2027 qty_phys_copy_sugg, suggested first gcc/local-alloc.c:1363 find_free_reg). source-read.
- **local-vs-global tie** — transfers (local runs first: gcc/toplev.c:4161 local_alloc before gcc/toplev.c:4190 global_alloc). source-read.
- **reg_renumber-swap oracle** — changed: pseudos start at 76, not 68 (gcc/config/mips/mips.h:1574 FIRST_PSEUDO_REGISTER). `(reg N)` with N < 76 is hard. The oracle harness itself is not in this repo: absent. source-read.

## §C/§D tells and triage
Kit tells/triage transfer with these edits:

- A `.greg` `regs to allocate` list gives the global priority order directly (gcc/global.c:1781 fprintf).
- A per-use `addiu $rX,$sp,K` can now be a rematerialized frame address (RC-7 changed).
- "all reload regs shifted $t0→$t1 ⇒ a pin" is unsupported in 2.95.2 (RC-5 ch.2 changed).
- A missing `move` may be regmove's, not local-alloc's (K8).

## regmove (new in 2.95.2, no kit counterpart)
- pass: gcc/regmove.c:1075 regmove_optimize, before sched1 and local-alloc, -O2 default (gcc/toplev.c:4106 flag_regmove). Three passes (gcc/regmove.c:1103 pass): pass 0 forward, then backward passes only with `-fregmove` — on at -O2 (gcc/regmove.c:1105 flag_regmove).
- Copy cleanup (pass 0, needs `flag_expensive_optimizations`):
  - Copy where src does not die → rewrite later src uses to dest so src dies at the copy (gcc/regmove.c:376 optimize_reg_copy_1, same basic block only).
  - Pseudo→pseudo copy with dead src → replace dest by src back to src's set (gcc/regmove.c:580 optimize_reg_copy_2).
  - Extend-of-load folded so src/dest can tie (gcc/regmove.c:659 optimize_reg_copy_3).
- Two-address matching (needs `flag_regmove`): for insns whose constraints tie an input to the output (gcc/regmove.c:1569 find_matches), make them the same reg (gcc/regmove.c:1650 fixup_match_1, gcc/regmove.c:937 fixup_match_2). A copy is inserted when needed (gcc/regmove.c:747 copy_src_to_dest). Which MIPS patterns carry matching constraints at this pin is unmeasured (gate gcc/regmove.c:2142 regmove_profitable_p).
- residual pattern: a copy present in the C that never reaches local-alloc, or a value whose register identity changed before allocation. The `.regmove` dump shows it.
- lever: none byte-proven in this task. Experiment owed (pair differing only in a copy's source death). Status: absent in 2.7.2, new in 2.95.2.
- Related post-reload (also new): gcc/reload1.c:8914 reload_cse_regs runs gcc/reload1.c:8918 reload_combine and gcc/reload1.c:8919 reload_cse_move2add — may delete/merge reload moves after allocation.
