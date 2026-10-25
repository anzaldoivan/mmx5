# cse_expr.md — cse + gcse + expression expansion + /s aliasing + frame layout + cross-jump (gcc-2.95.2-psx pin)

This file translates the kit's `gcc-2.7.2-map/cse_expr.md` (§0-§8, §H) to our pin. The writers consulted the kit
and did not copy it. They re-derived every claim on the staged tree `refs/gcc-2.95.2-psx/` (cites audited by
`cites.py check`).

Status:
- `transfers`: the mechanism is present, with the same lever.
- `changed`: the mechanism is present, with a different behaviour/lever.
- `absent in 2.95.2`.

The experiments are in `.run/t4/c2/*.c` (scratch, `levers.py dump` + pin compile). The byte-proven levers are in
`levers.yaml` (group `cse_expr`).

The kit cites were gcc-2.8.1 / 2.7.2 lines. None carried over. Every line below is the pin's.

## 0. Pass order and -O2 flags at the pin

- cse1 gcc/toplev.c:3871 cse_main → gcse gcc/toplev.c:3907 gcse_main → loop → cse2 gcc/toplev.c:3983 cse_main →
  flow → combine gcc/toplev.c:4092 combine_instructions → regmove → sched1 → alloc/reload → sched2 →
  jump2 with cross-jump gcc/toplev.c:4307 JUMP_CROSS_JUMP → dbr.
- -O2 sets gcc/toplev.c:4859 flag_cse_follow_jumps, gcc/toplev.c:4860 flag_cse_skip_blocks and
  gcc/toplev.c:4861 flag_gcse (new pass vs 2.7.2, on at -O2).
- The dumps (`levers.py dump`, `.run/codegen/dumps/<stem>/`) are `.rtl .jump .cse .addressof .gcse .loop .cse2 .flow
  .combine .regmove .sched .lreg .greg .flow2 .sched2 .jump2 .mach .dbr`. Cross-jump effects show first in `.jump2`.
- The register numbering changed: gcc/config/mips/mips.h:1574 FIRST_PSEUDO_REGISTER is 76. So the virtuals are
  76-79 and the first pseudo is 80 (kit: 68/72).
- Triage: if the residual is first in `.cse/.gcse/.cse2`, go to §1-§3 of this file. For `.combine`, go to §E2.
  For `.lreg/.greg`, go to regalloc.md. For `.sched/.sched2/.dbr`, go to sched.md. For `.jump2`, go to §E3
  cross-jump.

## 1. The CSE machine (cse.c)

The machine uses a hash table of equivalence classes per extended basic block. An extended basic block is a path
through followed/skipped jumps (gcc/cse.c:8482 cse_end_of_basic_block). Each path start has a fresh table
(gcc/cse.c:8897 new_basic_block).

### K§1-a — reg SET kills classes containing it · transfers
- gcc/cse.c:1707 invalidate. The reg_tick bump stales every expr that mentions the reg.
- Lever: a zero-byte re-SET of a variable (input-tied asm) stales expressions built from it. Proven as
  `cse_call_retie` (§3).

### K§1-b — CALL: only call-clobbered HARD regs invalidated, pseudo classes survive · transfers
- gcc/cse.c:1948 invalidate_for_call. The loop is over gcc/cse.c:1962 regs_invalidated_by_call.
- Residual: a pre-call subexpression reused after the call, parked in an $s reg. Lever: §3.
- Experiment: lever `cse_call_retie` before side shows `andi $16,$4,0xffff` once, reused after `jal g`.

### K§1-c — CALL kills all MEM entries (non-const calls) · transfers
- gcc/cse.c:7665 invalidate_memory under `! CONST_CALL_P`. Cached loads never cross a call.

### K§1-d — store kills MEM entries selectively · changed
- 2.7.2 used flag sets from note_mem_written. At the pin, note_mem_written only handles stack push/pop, and the
  per-entry kill is gcc/cse.c:1832 true_dependence (alias.c oracle, same one sched uses). The effect table is in
  §4b.

### K§1-e — CODE_LABEL / path start flushes the table · changed (scope)
- gcc/cse.c:893 new_basic_block at each cse_basic_block run. With follow-jumps + skip-blocks (-O2), the path runs
  through a followed jump's target and around skipped blocks (gcc/cse.c:8313 invalidate_skipped_block). So a
  join is NOT always a flush. A barrier-preceded label (not followable, not skippable) is: §H1.

### K§1-f — 1000-insn flush · changed (kit: absent in 2.7.2. PRESENT at the pin)
- gcc/cse.c:8916 num_insns → flush_hash_table every >1000 non-NOTE insns, counter local to one
  cse_basic_block run (gcc/cse.c:8873 num_insns). Both cse1 and cse2.
- Residual: in a giant (>1000 insns along one cse path), one value recomputed mid-function where the rest is
  reused. Lever: restructure so the boundary falls elsewhere (insn count before the use), or reproduce the
  target's labels so paths are shorter. It is fragile. Diagnose with `.cse` dump insn counts first.
- Experiment: not run. It needs a >1000-insn path. There is no game code in scratch.

### K§1-g — volatile asm: kit "kills nothing" · changed
- A raw volatile ASM_OPERANDS flushes the WHOLE table: gcc/cse.c:7697 flush_hash_table. An asm with no outputs is
  forced volatile (gcc/stmt.c:1154 noutputs). It is emitted as a raw ASM_OPERANDS only with no clobbers
  (gcc/stmt.c:1567 nclobbers). With outputs or clobbers, it is a SET/PARALLEL and does not hit 7697.
- A volatile SET dest is invalidated (gcc/cse.c:7526 do_not_record). This is the kit's §2 output-only kill.
- Byte-checked (`.run/t4/c2/va*.c`): `asm volatile("" : : )` and `asm("" : : )` flush reg classes, but
  `asm volatile("")` (basic asm, ASM_INPUT) and `asm volatile("" : : : "memory")` do not.
- Lever: `cse_volatile_asm_flush` (byte-proven): `x*5+1` twice → reused (`sll $2,$3,3`). Operand-less asm
  between → recomputed. Zero bytes, no register named — the cheapest "recompute here" fence at the pin.

### K§1-h — follow-jumps: EBB follows the taken path · transfers
- gcc/cse.c:8482 cse_end_of_basic_block (flags at gcc/toplev.c:4859 flag_cse_follow_jumps).
  gcc/cse.c:6125 record_jump_equiv records the branch condition on the path (§H3).

## 2. K§2 — cross-call ADDRESS caching (hoist vs remat) · transfers (not re-proven at pin)
- Arg values are precomputed into pseudos: gcc/calls.c:614 precompute_register_parameters.
  cse unifies the second site's `(plus $fp K)` with the first (K§1-b, pseudos survive calls). The global pass
  gives it a callee-saved reg.
- Kit lever (pointer local in nested block, output-only `asm volatile("" : "=r"(q))` after the call): the
  output-only asm is a SET of q. So the gcc/cse.c:7526 do_not_record path invalidates q's class. The mechanism is
  present.
- Kit A23-2 multi-reg class via block move: gcc/config/mips/mips.c:3145 copy_addr_to_reg (both addresses) is
  still present. The remedies are the same (field-by-field copy, or a real join label).
- update_equiv_regs does not rescue (2 refs only, gcc/local-alloc.c:890 REG_N_REFS) — transfers.
- Experiment: not run. It needs a frame + 2 call sites. The kit's proofs were game fns. Re-prove before relying
  on it.

## 3. K§3 — cross-call VALUE CSE (phantom extra $s reg) · transfers
- The mechanism is K§1-b. The lever is an input-tied re-tie `__asm__("" : "=r"(x) : "0"(x));` between the
  occurrences. It re-SETs x (K§1-a), so the tail recomputes from x in place.
- Lever `cse_call_retie` (byte-proven): the before side shows `andi $16,$4,0xffff` + `move $4,$16` per call. The
  after side shows `move $16,$4` + `andi $4,$16,0xffff` at each call. The variant table (input-tied for live
  values, output-only for dead-after-call addresses) transfers as is.
- New at pin: the operand-less volatile asm (K§1-g) also kills it, but flushes everything (MEM too). When only
  one value must recompute, prefer the re-tie.

## 4. K§4 — /s (MEM_IN_STRUCT_P) aliasing

### K§4a — setters · transfers (lines moved, one temp-slot correction)
- Deref: gcc/expr.c:6267 PLUS_EXPR arm list (top PLUS / SAVE_EXPR of PLUS / aggregate type / &aggregate) →
  gcc/expr.c:6274 MEM_SET_IN_STRUCT_P. The four arms are the same as the kit's. A cast on top of the sum still
  denies.
- Member/array refs: gcc/expr.c:6663 MEM_SET_IN_STRUCT_P (unconditional, COMPONENT_REF/ARRAY_REF bundle).
- Store side: component dest → gcc/expr.c:3413 store_field → gcc/expr.c:4770 MEM_SET_IN_STRUCT_P.
- Locals: gcc/stmt.c:3515 MEM_SET_IN_STRUCT_P = aggregate-ness (array/struct home `/s`, scalar spill not).
- Temps: at the pin assign_temp EXISTS (gcc/function.c:1117 assign_temp, `/s` = aggregate at
  gcc/function.c:1141 MEM_SET_IN_STRUCT_P) and a reused slot IS reset (gcc/function.c:1091 MEM_IN_STRUCT_P,
  plus MEM_SCALAR_P). This is the 2.8.1 behaviour, not 2.7.2's inherit-on-recycle (kit A23 correction reverses
  here).
- Params: gcc/function.c:4505 MEM_SET_IN_STRUCT_P (and siblings) = aggregate-ness.
- New: MEM_SCALAR_P marks fixed scalar MEMs. MEM_ALIAS_SET exists but strict aliasing is off (see sched.md §1).

### K§4b — consumers · changed (oracle moved to alias.c, observed effect same)
- sched and cse both use gcc/alias.c:1219 true_dependence / gcc/alias.c:1320 anti_dependence. The escape is
  gcc/alias.c:1174 fixed_scalar_and_varying_struct_p (`/s` varying vs fixed scalar never conflict).
  QImode aliases everything: gcc/alias.c:1261 QImode.
- cse store-kill: per entry gcc/cse.c:1832 true_dependence (no flag table). Byte-checked (`.run/t4/c2/st*.c`,
  global `g` loaded, store, `g` again): `*p = 1` → reload. `p[1] = 1` (int) → reused (`sll $2,$2,1`).
  `p[1] = 1` (char, `sb`) → reload. The lever reading is the same as the kit's: a bare `*p=` / byte store reloads
  globals, an indexed/member non-byte store keeps them.

### K§4c — grant/deny cheat sheet · transfers
- GRANT: member ref (anon-struct cast), `q[k]` typed, aggregate deref. DENY: bare `*p`, `*(T*)(p+k)`, scalar
  spill homes. Same syntax steers loads and stores, true and anti deps.

## 5. K§5 — stack frame layout (function.c) · changed (leaf base, temps)
- gcc/function.c:756 assign_stack_local. The frame grows up (gcc/config/mips/mips.h:2125 FRAME_GROWS_DOWNWARD is
  commented out). The base is gcc/config/mips/mips.h:2131 STARTING_FRAME_OFFSET = outgoing args size (+ a pad only
  under abicalls. psx.h does not set it, not verified further). So a leaf has its first local at sp+0, and a
  non-leaf at sp+outgoing (≥0x10). The kit A23 parenthetical holds.
- The BLKmode align is gcc/config/mips/mips.h:1444 BIGGEST_ALIGNMENT = 64 bits, so arrays/structs are 8-aligned.
- Temp-slot reuse/split: gcc/function.c:924 assign_stack_temp_for_type, freed by gcc/function.c:1409
  free_temp_slots. Reuse resets `/s` at the pin (K§4a). Lever as kit: reproduce the source's temp population
  and declaration order. Separate locals per 8-aligned cluster.
- Experiment: not run (no frame lever proven this task).

## 6. K§6 — diagnostic tells · per row
- per-call `addiu $aN,$sp,K` vs cached `$sN` → K§2 (transfers).
- extra $s reg, tail reuses `$sN` where target recomputes → K§3, lever `cse_call_retie`.
- `/s` true/anti-dep order flips → K§4 (sched.md alias cites).
- global reload after `*p=` vs not after `p->f=` → K§4b.
- frame ±8 / out-of-decl-order offsets → K§5.
- "recompute after a join is normal" → changed: only after a barrier-preceded label or a path start. With
  follow/skip, a reuse across a join is possible (K§1-e).
- once-mid-giant recompute → changed: the 1000-insn flush EXISTS at the pin (K§1-f), check it before other causes.
- recompute where ours reuses, no label/call between → operand-less volatile asm or re-tie (K§1-g, K§3).
- `lui` above a branch + delay-slot duplicate → dbr (sched.md D-items), not cse.

## 7. K§7 — verdicts · per item
- K§2 is steerable (unproven at pin). K§3 is steerable (proven). K§4 is steerable both directions, QImode
  intrinsic. K§5 is steerable via decl order/typing. K§1-f (1000-insn) is REAL at the pin — the kit's deleted
  bullet re-applies. The kit's `func_80132784` notes are about the kit's game: not applicable.

## 8. K§8 — cookbook feed-forward · not done here
- Candidates: pseudo-classes-survive-calls + re-tie variants. Operand-less volatile asm = full cse flush at
  the pin. Cross-jump RETURN minimum 2. Routed via the T4 log, not added by this task.

## H. Kit §H — fresh-table antidote, equiv doubling, jump equiv

### K§H1 — cse address fold killed by a barrier-preceded label · transfers (not re-proven)
- gcc/cse.c:2815 find_best_addr folds addresses on each cse walk. A label after a BARRIER is neither followed nor
  skipped → new path → gcc/cse.c:8897 new_basic_block. Lever: balanced if/else diamond (the ELSE label is the
  barrier-preceded one).

### K§H2 — update_equiv_regs doubles live length of single-set REG_EQUIV pseudos · transfers
- gcc/local-alloc.c:666 update_equiv_regs. Doubling: gcc/local-alloc.c:874 REG_LIVE_LENGTH. A 2nd set forfeits it.
  Shared with regalloc.md.

### K§H3 — record_jump_equiv deletes a provably-dead branch · transfers
- gcc/cse.c:6125 record_jump_equiv. Tell: if the target keeps a branch that cse would prove dead, the source had
  a real second writer. An identity re-tie re-opaques the value.

## E. Pin-only / brief-scoped passes (not in the kit map)

### E1 — gcse (new in 2.95, on at -O2) · new
- gcc/gcse.c:621 gcse_main. It is skipped for 1-block functions (gcc/gcse.c:651 n_basic_blocks) and setjmp
  (gcc/gcse.c:635 current_function_calls_setjmp). Per pass: copy/const prop gcc/gcse.c:714 one_cprop_pass,
  then PRE gcc/gcse.c:719 one_pre_gcse_pass.
- Experiment `.run/t4/c2/gc1.c` (`if (a) p[0]=x*5; return x*5+p[1];`): the `.gcse` dump shows "0 substs, 0 insns
  created", and x*5 is recomputed after the join. In practice, PRE is not applied to small multi-insn
  expressions. No lever is needed yet.

### E2 — combine · transfers
- gcc/combine.c:459 combine_instructions → gcc/combine.c:1329 try_combine (2-3 linked insns into one).
- Tell: target keeps a separate def+use pair that ours fuses (or reverse) → give the def a second use / make it
  multi-set. Not byte-proven this task.

### E3 — jump2 cross-jump · new lever
- Runs after sched2 (gcc/toplev.c:4307 JUMP_CROSS_JUMP). Simple jump to a label: min 1 matching insn
  (gcc/jump.c:1974 find_cross_jump). RETURN-to-RETURN: min 2 (gcc/jump.c:2020 find_cross_jump). A label inside
  the match lowers it (gcc/jump.c:2867 minimum). A jump to the epilogue is first turned into a RETURN
  (gcc/jump.c:407 redirect_jump), so a tail before function end is a RETURN case.
- Lever `xjump_tail_merge` (byte-proven): 1-insn tail `p[2]=b` in both arms → two `j $31` (dup kept).
  Written after the join → one copy. Scratch `.run/t4/c2/xj3.c` vs `xj4.c`: a 2-insn tail in both arms is
  merged (`.sched2` 2 copies → `.jump2` 1). The merge gives the same bytes as writing it after the join.
- Matching rule for the residual "ours has one shared tail, target duplicates it": write the tail per arm with ≤1
  identical insn before the return. For the reverse, hoist after the join (or ≥2 identical insns).

### E4 — expression expansion: MULT-first sums · new lever
- Under EXPAND_SUM a MULT_EXPR by a constant returns a MULT rtx (gcc/expr.c:7130 gen_rtx_MULT). The sum puts it
  first (gcc/expr.c:7036 MULT), so `p[i]`/`(char*)p + i*4` give `sll $i; addu $i,$i,$p`. An explicit shift
  (`(char*)p + (i<<2)`) or a pointer local `int *q = p + i` gives `addu $p,$p,$i` (scratch ps1-ps7).
- Lever `expr_mult_first_sum` (byte-proven): which register receives the address follows operand order.

### E5 — expmed: signed divide by 2^k, constant multiply · transfers
- gcc/expmed.c:2881 expand_divmod biases a negative dividend (gcc/expmed.c:3217 do_cmp_and_jump): lever
  `div_pow2_signed` (byte-proven, existing). Constant multiply → shift/add via gcc/expmed.c:2060 synth_mult
  (x*5 → `sll 2; addu`, seen in va6).
