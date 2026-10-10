<!-- Cookbook index. One line per entry, appended by tools/cookbook_add.sh. Grep this file by tag or title; never read it whole; never read an entry you did not find here. -->
<!-- C<nnnn> | <title> | <tags> | <date> | <phase>/<task> | origin: <source section or report id> -->
C0001 | The decomp idiom entry shape: residual, mechanism, lever, byte proof | cookbook-format,idiom,residual,mechanism,lever,byte-proof | 2026-10-03 | - | decomp-architect
C0002 | The triage table: diff tell to mechanism to lever family | triage,symptom,tell,spill,register-pressure,aliasing,callee-saved,branch-polarity,cross-jump | 2026-10-03 | - | decomp-architect
C0003 | Offline tooling first: every computable step becomes a zero-token deterministic tool | strategy,deterministic,recovery,permuter,economics,tooling | 2026-10-03 | - | decomp-architect
C0004 | A slow gate is a bug: parallel worktrees, a per-binary lock, the parallel flag on every build | gate,parallel,worktree,lock,build,throughput | 2026-10-03 | - | decomp-architect
C0005 | Breadth is isolated agents: per-item agents cost about linearly, one serial loop about quadratically | breadth,agents,drafting,fan-out,cost | 2026-10-03 | - | decomp-architect
C0006 | Route drafters by a difficulty cliff measured on your own corpus | routing,model-tier,drafting,cliff,escalation,cost | 2026-10-03 | - | decomp-architect
C0007 | PS1 XA/STR are mixed Form1/Form2; 2336-byte payload; dumpsxiso cmp | psx,cdrom,xa,str,form2,dumpsxiso,extract | 2026-10-03 | 1.1/T1 | mmx5 1.1 T1+T2
C0008 | ghidra_psx_ldr headless: never pass -loader-ramStart | ghidra,psx_ldr,headless | 2026-10-03 | 1.2/T1 | phase-ends/current/tasks/T1.md
C0009 | Parse headless GhidraScript println output | ghidra,headless,parsing | 2026-10-03 | 1.2/T1 | phase-ends/current/tasks/T1.md
C0010 | Ghidra headless rejects '.'-leading project path elements | ghidra,headless,paths | 2026-10-03 | 1.2/T2 | phase-ends/current/tasks/T2.md
C0011 | PCSX-Redux nightlies vs host glibc | pcsx-redux,emulator,pins,glibc | 2026-10-03 | 1.2/T3 | phase-ends/current/tasks/T3.md
C0012 | PS1 overlay hunt: TOC users and loader call sites | ps1,overlay,loadmap,re | 2026-10-03 | 1.2/T4 | phase-ends/current/tasks/T4.md
C0013 | PCSX-Redux Lua exec breakpoints need -interpreter -debugger | pcsx-redux,lua,breakpoints | 2026-10-03 | 1.2/T5 | phase-ends/current/tasks/T5.md
C0014 | Snapshot CD-loaded overlays at the next loader call | ps1,overlay,dma,pcsx-redux | 2026-10-03 | 1.2/T5 | phase-ends/current/tasks/T5.md
C0015 | psx_ldr loses PsyQ object names; recover from signature json | ghidra,psx_ldr,psyq,libobj | 2026-10-03 | 1.2/T6 | phase-ends/current/tasks/T6.md
C0016 | Pinned cross binutils without sudo via dpkg-deb -x | toolchain,binutils,mips,pinning | 2026-10-03 | 1.3/T1 | -
C0017 | splat rodata/text boundary estimate can be off: pin from first function | splat,psx,rodata,segmentation | 2026-10-03 | 1.3/T2 | -
C0018 | All-asm overlays with embedded data need -march=mips4 in gas | gas,mips,overlay,asm | 2026-10-03 | 1.3/T3 | -
C0019 | Same-vram overlays in one yaml: resolve cross-overlay refs from symbol vram | splat,overlay,linker,symbols | 2026-10-03 | 1.3/T3 | -
C0020 | PsyQ lib padding does not segment game text | psyq,segmentation,tu,padding | 2026-10-03 | 1.3/T6 | -
C0021 | gcc 2.x cc1 has no --version; use -version </dev/null | gcc,cc1,toolchain | 2026-10-04 | 1.4/T1 | phase-ends/current/tasks/T1.md
C0022 | Decode PSX tells from spimdisasm raw words, not mnemonics | spimdisasm,psx,fingerprint | 2026-10-04 | 1.4/T3 | phase-ends/current/tasks/T3.md
C0023 | break encoding tells the assembler: GNU 0x0007000D vs aspsx 0x000001CD | aspsx,maspsx,psx,fingerprint | 2026-10-04 | 1.4/T3 | phase-ends/current/tasks/T3.md
C0024 | Legacy docker builder: no --output; build --target then docker cp | docker,toolchain | 2026-10-04 | 1.4/T4.1 | phase-ends/current/tasks/T4.1.md
C0025 | aspsx versions tie unless a maspsx gate fires on the binary's shapes | aspsx,maspsx,compiler-pin,probe | 2026-10-04 | 1.4/T4 | phase-ends/current/tasks/T4.md
C0026 | Absolute low-address loads: use T *p = 0; p->field, not *(int *)addr | gcc,matching,c-idiom | 2026-10-04 | 1.4/T4 | phase-ends/current/tasks/T4.md
C0027 | One-function splat c cut: [start, c, func] then [end, asm, rest] | splat,c,segmentation | 2026-10-04 | 1.4/T5 | phase-ends/current/tasks/T5.md
C0028 | make under dash has no pipefail: stage multi-tool compiles through files | make,dash,build | 2026-10-04 | 1.4/T6 | phase-ends/current/tasks/T6.md
C0029 | Filter .L jump-table labels when counting functions from a GNU ld map | ld,map,splat,census | 2026-10-05 | 1.5/T1 | -
C0030 | psyq _OBJ_<off> symbols are labels unless preceded by a terminator or padding | psyq,symbols,splat,boundaries | 2026-10-05 | 1.5/T2.1 | -
C0031 | splat textbin: leave interior symbols untyped | splat,textbin,symbols,link | 2026-10-05 | 1.5/T2.1 | -
C0032 | A jal target can be a fall-through label; reject starts preceded by plain code | boundaries,oracle,mips | 2026-10-05 | 1.5/T2.1 | -
C0033 | Mask relocated fields by instruction field for duplicate detection | census,duplication,mips,relocation | 2026-10-05 | 1.5/T3 | -
C0034 | Keep differential pairs strict; fix the wrong side | harness,oracle,verification | 2026-10-05 | 1.5/T5 | -
C0035 | Health chain rungs assert work done, not just rc 0 | make,health,verification | 2026-10-05 | 1.5/T6 | -
C0036 | Py3.14 pools: use explicit fork context | python,multiprocessing,perf | 2026-10-05 | 1.6/T1 | T1 gotcha
C0037 | Near-dup joins over exact-cluster reps, count |A|*|B| | sig,dedup,perf | 2026-10-05 | 1.6/T1 | T1 gotcha
C0038 | CRLF PsyQ headers break old-gcc cccp; use host cpp -undef | toolchain,gcc,psyq | 2026-10-05 | 1.6/T2 | T2 gotcha
C0039 | Mask REL .o relocation addends before signing | sig,objects,relocations | 2026-10-05 | 1.6/T2 | T2 gotcha
C0040 | Fixed high-RAM address via null base pointer, not extern | matching,c,addresses | 2026-10-05 | 1.6/T3 | T3 gotcha
C0041 | Non-legacy INCLUDE_ASM needs macro.inc, noat/noreorder, excluded .s | splat,include_asm,build | 2026-10-05 | 1.6/T4 | T4 gotcha
C0042 | Size floor on family key must gate near-link reach too | census,dedup | 2026-10-05 | 1.6/T5 | T5 gotcha
C0043 | Key group membership by (alias, name), not vram | census,overlays | 2026-10-05 | 1.6/T6 | T6 gotcha
C0044 | Shared #included bodies have no object; skip in per-object checks | dedup,harness | 2026-10-05 | 1.6/T6 | T6 gotcha
C0045 | Scratch build sample has a fixed floor; overlap it | health,build,perf | 2026-10-05 | 1.6/T8 | T8 gotcha
C0046 | Equal-density $s tie follows declaration order: swap the declarations | idiom,regalloc,s0-s1-swap,callee-saved,spill,register-order | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml regalloc_decl_tie
C0047 | Callee-saved bank follows use density, not declaration order | idiom,regalloc,s0-s1-swap,callee-saved,phantom-callee-saved,density,register-order | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml regalloc_density_order
C0048 | Phantom callee-saved from cross-call CSE: re-tie the value per call | idiom,cse_expr,phantom-callee-saved,callee-saved,cse,call | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml cse_call_retie
C0049 | Branch arms swapped: dbr eager fill steals the other arm | idiom,sched,branch-polarity,delay-slot,arms-swapped,beq,bne | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml dbr_branch_polarity
C0050 | Cross-jumped tail merged or not: the shared block count law | idiom,cse_expr,cross-jump,tail-merge,jump2,duplicate-tail | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml xjump_tail_merge
C0051 | Latency-1 ties keep source order: reorder the statements | idiom,sched,schedule-reorder,statement-order,ties,store-order | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml sched_stmt_order
C0052 | Def far from its use: single-set temp gets the birthing boost | idiom,sched,schedule-reorder,def-placement,birthing-boost,reused-temp | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml sched_birth_boost
C0053 | Batched vs paired loads: a reused int temp fences them | idiom,sched,schedule-reorder,loads,batched,paired,reused-temp,u16 | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml sched_reused_temp_fence
C0054 | Down-count loop on NE needs the for-loop VTOP note | idiom,loop,loop,reversal,down-count,up-count,dbra,vtop | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml loop_rev_ne_vtop
C0055 | Loop reversal needs a counting-only index | idiom,loop,loop,reversal,down-count,up-count,counting-only | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml loop_rev_counting_only
C0056 | Invariant load stays at loop head unless the operand is const | idiom,loop,loop,invariant,hoist,preheader,const,global-reload | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml loop_const_hoist
C0057 | Signed divide by 2^k biases with bgez; a shift does not | idiom,cse_expr,strength,divide,shift,sra,bias,bgez | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml div_pow2_signed
C0058 | Recompute where CSE reuses: operand-less volatile asm flushes the table | idiom,cse_expr,cse,recompute,reuse,volatile-asm,flush | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml cse_volatile_asm_flush
C0059 | Address operand order: p[i] puts the MULT first | idiom,cse_expr,addressing,operand-order,mult,index,addu | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml expr_mult_first_sum
C0060 | Load stuck below a store: grant /s to the varying store | idiom,cse_expr,aliasing,load-below-store,mem-in-struct,schedule-reorder | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml alias_struct_grant
C0061 | Index shift off by x4: cast the scaffold byte offset through char* | idiom,cse_expr,shift-x4,pointer-arithmetic,scaffold,sll,byte-pointer,imm-offset | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml expr_byte_ptr_scale
C0062 | GCC sources: split on newline only (form feeds) | gcc,python,cites | 2026-10-05 | current/T1 | -
C0063 | Dockerfile RUN globs run under dash (no globstar) | docker,shell | 2026-10-05 | current/T1 | -
C0064 | gcc 2.95.2 callee-saved choice needs global-alloc values | gcc,regalloc,lever | 2026-10-05 | current/T3 | -
C0065 | Tell regex over .cc.s: allow .set lines before branches | levers,regex,maspsx | 2026-10-05 | current/T4 | -
C0066 | Permuter scores on relocating functions: check reloc addends | permuter,relocs | 2026-10-05 | current/T5 | -
C0067 | Plateau classify: width before length drift | permuter,plateau,signedness | 2026-10-05 | current/T6 | -
C0068 | 0-TODO grep gates hit prose; reword, don't exempt | gate,grep | 2026-10-05 | current/T7 | -
C0069 | Post-call temp in $v1 not $v0: declare the ignored callee returning s32 | idiom,regalloc,call-value,v0-v1,return-type,reg-unused,callee-decl | 2026-10-05 | current/T6 | docs/codegen-map/levers.yaml regalloc_call_value_ret
C0070 | Extra move copy into $s: a dead reassignment of the source ends CSE copy-propagation | idiom,cse_expr,dead-store,copy-propagation,move,callee-saved,canon-reg | 2026-10-05 | current/T6 | docs/codegen-map/levers.yaml cse_copy_dead_reset
C0071 | Masked-signature dup group is not a byte-twin set: verify bytes in place before propagating | dedup,propagate,byte-twin,masked-signature,dedup-callee | 2026-10-06 | 1.8/T5 | current/T5 c26
C0072 | Switch body layout follows case order in source: write the cases in target order | idiom,cse_expr,switch,case-order,block-layout,jump,bne,beq | 2026-10-06 | 1.8.2/T5 | docs/codegen-map/levers.yaml switch_case_source_order
C0073 | Commutative addu operand order follows RTL shape: zero_extend mem first, plain reg last | idiom,cse_expr,operand-order,commutative,addu,zero-extend,local-vs-field | 2026-10-06 | 1.8.2/T5 | docs/codegen-map/levers.yaml expr_commutative_rtl_order
C0074 | Compare operand written first is loaded first: write the global first to flip the loads | idiom,cse_expr,operand-order,compare,slt,load-order,branch-sense | 2026-10-06 | 1.8.2/T5 | docs/codegen-map/levers.yaml expr_compare_load_order
C0075 | Constant reassociated onto the other operand: a temp local blocks fold | idiom,cse_expr,fold,associate,constant-folding,temp-local,subtract | 2026-10-06 | 1.8.2/T5 | docs/codegen-map/levers.yaml fold_assoc_temp_block
C0076 | Constant stores alternate v0/v1: interleave a zero store to keep v0 | idiom,regalloc,v0-v1,constant-store,li-sb,local-alloc,store-order | 2026-10-06 | 1.8.2/T5 | docs/codegen-map/levers.yaml regalloc_const_store_interleave
C0077 | Scratchpad pointer load: raw constant-address cast, never an extern symbol | idiom,cse_expr,scratchpad,1F80004C,constant-address,hi-lo-split,raw-cast,extern | 2026-10-06 | current/T7 | docs/codegen-map/levers.yaml addr_const_scratchpad
C0078 | Table entry via pointer-plus-index (T + i)->f flips the addu base/index regs | idiom,cse_expr,addressing,operand-order,index,array-ref,stride-12,addu | 2026-10-06 | current/T7 | docs/codegen-map/levers.yaml expr_ptr_plus_index
C0079 | Two-way compare storing abs(a-b) per arm: ABS() in each arm folds the negation to b-a | idiom,cse_expr,abs,fold,negate,tail-merge,cross-jump,branch | 2026-10-06 | 1.8.2/T11 | current/T10 c16
C0080 | Abs-window test: a condition ternary keeps the negative arm out of line, one store tail | idiom,cse_expr,abs,ternary,cross-jump,branch,bltz,window | 2026-10-06 | 1.8.2/T15.1 | current/T14 c15
C0081 | Per-function rodata without a C match: splat .rodata sub + migrate_rodata_to_functions | splat,rodata,carve,migrate,sha | 2026-10-06 | 1.8.2/T3 | tasks/T3.md:24
C0082 | Text-only try match on a jump-table owner proves nothing about rodata | jtbl,jump-table,rodata,try,bank,sha | 2026-10-06 | 1.8.2/T5 | tasks/T5.md:33
C0083 | Reused build worktree keeps stale splat outputs: delete the .s on a type change | splat,worktree,stale,build | 2026-10-06 | 1.8.2/T5 | tasks/T5.md:34
C0084 | Twin-derived drafts: hoist banked struct shapes to include/types.h at bank time | types,dedup,twin,hoist,struct,draft | 2026-10-06 | 1.8.2/T6 | tasks/T6.md:23
C0085 | Unused callee result: a local void declaration when s32 moves a constant into v1 | regalloc,callee-decl,v0-v1,void,return-type | 2026-10-06 | 1.8.2/T8 | tasks/T8.md:20
C0086 | Sweep statement orders offline before spending capped tries | store-order,regalloc,offline,sweep,tries | 2026-10-06 | 1.8.2/T12 | tasks/T12.md:30
C0087 | Jump-table owner's rodata span ends at the jtbl end, not the next label | jtbl,jump-table,rodata,carve,pad,span | 2026-10-06 | 1.8.2/T13.1 | tasks/T13.1.md:23
C0088 | New idiom cookbook entry needs a lever byte proof and SYMPTOMS.md rebuild in one change | cookbook-format,cookbook,idiom,levers,symptoms,tools-health | 2026-10-06 | 1.8.2/T15.1 | tasks/T15.1.md:21
C0089 | s16 field negate: x *= -1 keeps the lh load, x = -x narrows to lhu | idiom,cse_expr,negate,s16,lh,lhu,narrowing,convert | 2026-10-07 | 1.8.3/T6 | current/T5 c9
C0090 | Glob-then-read scans must tolerate vanished files; scratch worktrees per process | parallel,race,glob,worktree,scratch | 2026-10-11 | 1.8.3/T1 | phase-ends/current/tasks/T1.md:20
C0091 | PCSX-Redux Lua pad override API; one instance at a time; stdout buffered until quit | pcsx-redux,lua,pad,input,emulator | 2026-10-11 | 1.8.3/T2 | phase-ends/current/tasks/T2.md:22-23
C0092 | Return a call result (s32) to stop gcc cross-jumping identical tail increments | idiom,cross-jump,tail-merge,v0,return-type,regalloc | 2026-10-11 | 1.8.3/T3 | phase-ends/current/tasks/T3.md:26
C0093 | s16 negation: x = -x emits lhu, x *= -1 emits lh+negu | idiom,negate,s16,lh,lhu,load-sign | 2026-10-11 | 1.8.3/T5 | phase-ends/current/tasks/T5.md:29
