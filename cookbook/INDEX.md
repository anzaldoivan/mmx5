<!-- Cookbook index. One line per entry, appended by tools/cookbook_add.sh. Grep this file by tag or title; never read it whole; never read an entry you did not find here. -->
<!-- C<nnnn> | <title> | <tags> | <date> | <phase>/<task> | origin: <source section or report id> -->
C0001 | The decomp idiom entry shape: residual, mechanism, lever, byte proof | cookbook-format,idiom,residual,mechanism,lever,byte-proof | 2026-10-03 | - | decomp-architect
C0002 | The triage table: diff tell to mechanism to lever family | triage,symptom,tell,spill,register-pressure,aliasing,callee-saved,branch-polarity,cross-jump | 2026-10-03 | - | decomp-architect
C0003 | Offline tooling first: every computable step becomes a zero-token deterministic tool | strategy,deterministic,recovery,permuter,economics,tooling | 2026-10-03 | - | decomp-architect
C0004 | A slow gate is a bug: parallel worktrees, a per-binary lock, the parallel flag on every build | gate,parallel,worktree,lock,build,throughput | 2026-10-03 | - | decomp-architect
C0005 | Breadth is isolated agents: per-item agents cost about linearly, one serial loop about quadratically | breadth,agents,drafting,fan-out,cost | 2026-10-03 | - | decomp-architect
C0006 | Route drafters by a difficulty cliff measured on your own corpus | routing,model-tier,drafting,cliff,escalation,cost | 2026-10-03 | - | decomp-architect
C0007 | PS1 XA/STR are mixed Form1/Form2, 2336-byte payload, dumpsxiso cmp | psx,cdrom,xa,str,form2,dumpsxiso,extract | 2026-10-03 | 1.1/T1 | mmx5 1.1 T1+T2
C0008 | ghidra_psx_ldr headless: never pass -loader-ramStart | ghidra,psx_ldr,headless | 2026-10-03 | 1.2/T1 | phase-ends/current/tasks/T1.md
C0009 | Parse headless GhidraScript println output | ghidra,headless,parsing | 2026-10-03 | 1.2/T1 | phase-ends/current/tasks/T1.md
C0010 | Ghidra headless rejects '.'-leading project path elements | ghidra,headless,paths | 2026-10-03 | 1.2/T2 | phase-ends/current/tasks/T2.md
C0011 | PCSX-Redux nightlies vs host glibc | pcsx-redux,emulator,pins,glibc | 2026-10-03 | 1.2/T3 | phase-ends/current/tasks/T3.md
C0012 | PS1 overlay hunt: TOC users and loader call sites | ps1,overlay,loadmap,re | 2026-10-03 | 1.2/T4 | phase-ends/current/tasks/T4.md
C0013 | PCSX-Redux Lua exec breakpoints need -interpreter -debugger | pcsx-redux,lua,breakpoints | 2026-10-03 | 1.2/T5 | phase-ends/current/tasks/T5.md
C0014 | Snapshot CD-loaded overlays at the next loader call | ps1,overlay,dma,pcsx-redux | 2026-10-03 | 1.2/T5 | phase-ends/current/tasks/T5.md
C0015 | psx_ldr loses PsyQ object names: recover them from the signature json | ghidra,psx_ldr,psyq,libobj | 2026-10-03 | 1.2/T6 | phase-ends/current/tasks/T6.md
C0016 | Pinned cross binutils without sudo via dpkg-deb -x | toolchain,binutils,mips,pinning | 2026-10-03 | 1.3/T1 | -
C0017 | splat rodata/text boundary estimate can be off: pin from first function | splat,psx,rodata,segmentation | 2026-10-03 | 1.3/T2 | -
C0018 | All-asm overlays with embedded data need -march=mips4 in gas | gas,mips,overlay,asm | 2026-10-03 | 1.3/T3 | -
C0019 | Same-vram overlays in one yaml: resolve cross-overlay refs from symbol vram | splat,overlay,linker,symbols | 2026-10-03 | 1.3/T3 | -
C0020 | PsyQ lib padding does not segment game text | psyq,segmentation,tu,padding | 2026-10-03 | 1.3/T6 | -
C0021 | gcc 2.x cc1 has no --version: use -version </dev/null | gcc,cc1,toolchain | 2026-10-04 | 1.4/T1 | phase-ends/current/tasks/T1.md
C0022 | Decode PSX tells from spimdisasm raw words, not mnemonics | spimdisasm,psx,fingerprint | 2026-10-04 | 1.4/T3 | phase-ends/current/tasks/T3.md
C0023 | break encoding tells the assembler: GNU 0x0007000D vs aspsx 0x000001CD | aspsx,maspsx,psx,fingerprint | 2026-10-04 | 1.4/T3 | phase-ends/current/tasks/T3.md
C0024 | Legacy docker builder: no --output, so build --target then docker cp | docker,toolchain | 2026-10-04 | 1.4/T4.1 | phase-ends/current/tasks/T4.1.md
C0025 | aspsx versions tie unless a maspsx gate fires on the binary's shapes | aspsx,maspsx,compiler-pin,probe | 2026-10-04 | 1.4/T4 | phase-ends/current/tasks/T4.md
C0026 | Absolute low-address loads: use `T *p = 0; p->field`, not `*(int *)addr` | gcc,matching,c-idiom | 2026-10-04 | 1.4/T4 | phase-ends/current/tasks/T4.md
C0027 | One-function splat c cut: [start, c, func] then [end, asm, rest] | splat,c,segmentation | 2026-10-04 | 1.4/T5 | phase-ends/current/tasks/T5.md
C0028 | make under dash has no pipefail: stage multi-tool compiles through files | make,dash,build | 2026-10-04 | 1.4/T6 | phase-ends/current/tasks/T6.md
C0029 | Filter .L jump-table labels when counting functions from a GNU ld map | ld,map,splat,census | 2026-10-05 | 1.5/T1 | -
C0030 | psyq _OBJ_<off> symbols are labels unless preceded by a terminator or padding | psyq,symbols,splat,boundaries | 2026-10-05 | 1.5/T2.1 | -
C0031 | splat textbin: leave interior symbols untyped | splat,textbin,symbols,link | 2026-10-05 | 1.5/T2.1 | -
C0032 | A jal target can be a fall-through label: reject starts preceded by plain code | boundaries,oracle,mips | 2026-10-05 | 1.5/T2.1 | -
C0033 | Mask relocated fields by instruction field for duplicate detection | census,duplication,mips,relocation | 2026-10-05 | 1.5/T3 | -
C0034 | Keep differential pairs strict and fix the wrong side | harness,oracle,verification | 2026-10-05 | 1.5/T5 | -
C0035 | Health chain rungs assert work done, not just rc 0 | make,health,verification | 2026-10-05 | 1.5/T6 | -
C0036 | Py3.14 pools: use explicit fork context | python,multiprocessing,perf | 2026-10-05 | 1.6/T1 | T1 gotcha
C0037 | Near-dup joins over exact-cluster reps, count |A|*|B| | sig,dedup,perf | 2026-10-05 | 1.6/T1 | T1 gotcha
C0038 | CRLF PsyQ headers break old-gcc cccp: use host cpp -undef | toolchain,gcc,psyq | 2026-10-05 | 1.6/T2 | T2 gotcha
C0039 | Mask REL .o relocation addends before signing | sig,objects,relocations | 2026-10-05 | 1.6/T2 | T2 gotcha
C0040 | Fixed high-RAM address via null base pointer, not extern | matching,c,addresses | 2026-10-05 | 1.6/T3 | T3 gotcha
C0041 | Non-legacy INCLUDE_ASM needs macro.inc, noat/noreorder, excluded .s | splat,include_asm,build | 2026-10-05 | 1.6/T4 | T4 gotcha
C0042 | Size floor on family key must gate near-link reach too | census,dedup | 2026-10-05 | 1.6/T5 | T5 gotcha
C0043 | Key group membership by (alias, name), not vram | census,overlays | 2026-10-05 | 1.6/T6 | T6 gotcha
C0044 | Shared #included bodies have no object: skip in per-object checks | dedup,harness | 2026-10-05 | 1.6/T6 | T6 gotcha
C0045 | Scratch build sample has a fixed floor: overlap it | health,build,perf | 2026-10-05 | 1.6/T8 | T8 gotcha
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
C0057 | Signed divide by 2^k biases with bgez, but a shift does not | idiom,cse_expr,strength,divide,shift,sra,bias,bgez | 2026-10-05 | 1.7/T7 | docs/codegen-map/levers.yaml div_pow2_signed
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
C0068 | 0-TODO grep gates hit prose: reword, do not exempt | gate,grep | 2026-10-05 | current/T7 | -
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
C0090 | Glob-then-read scans must tolerate vanished files, and scratch worktrees take a per-process path | parallel,race,glob,worktree,scratch | 2026-10-11 | 1.8.3/T1 | phase-ends/current/tasks/T1.md:20
C0091 | PCSX-Redux Lua pad override API, one instance at a time, stdout buffered until quit | pcsx-redux,lua,pad,input,emulator | 2026-10-11 | 1.8.3/T2 | phase-ends/current/tasks/T2.md:22-23
C0092 | Return a call result (s32) to stop gcc cross-jumping identical tail increments | idiom,cross-jump,tail-merge,v0,return-type,regalloc | 2026-10-11 | 1.8.3/T3 | phase-ends/current/tasks/T3.md:26
C0093 | s16 negation: x = -x emits lhu, x *= -1 emits lh+negu | idiom,negate,s16,lh,lhu,load-sign | 2026-10-11 | 1.8.3/T5 | phase-ends/current/tasks/T5.md:29
C0094 | Detect stdlib shadows with -S plus venv site-packages | python,tools,stdlib,shadow | 2026-10-11 | 1.9/T1 | generalizable
C0095 | Prove a fresh clone in one pass | publish,fresh-clone,gates | 2026-10-11 | 1.9/T10 | generalizable
C0096 | HEAD-tree stamps need a follow-up commit | progress,stamp,commits | 2026-10-11 | 1.9/T13 | generalizable
C0097 | New idiom entries must match the SYMPTOMS row | cookbook,symptoms,codegen | 2026-10-11 | 1.9/T2 | generalizable
C0098 | Identify a PsyQ SDK release by PSLibId | psyq,sdk,toolchain | 2026-10-11 | 1.9/T6 | generalizable
C0099 | Constant-address casts live only in include/addr.h as union views | scratchpad,constant-address,raw-cast,addr-h,union,readability | 2026-10-11 | 1.10/T3 | supersedes C0077 where; T6.c1
C0100 | Scratchpad pointer as a union of pointee views in include/addr.h | scratchpad,union,addr,cast | 2026-10-11 | 1.10/T3 | generalizable
C0101 | Re-export tracked Ghidra exports after a rename | ghidra,roundtrip,mirror,rename | 2026-10-11 | 1.10/T5 | generalizable
C0102 | PS1 disc rebuild: dumpsxiso -s + mkpsxiso 2.30 round trip is byte-exact | disc,mkpsxiso,repack | 2026-10-11 | 2.1/T2 | -
C0103 | git check-ignore -q takes one path, so count lines for several | git,firewall | 2026-10-11 | 2.1/T3 | -
C0104 | PCSX-Redux 298: MMX5 needs -interpreter (dynarec freezes before FMV) | redux,emulator | 2026-10-11 | 2.1/T4 | -
C0105 | PCSX-Redux 298: both memcard slots share one file | pcsx-redux,memcard,replay | 2026-10-12 | 2.2/T1 | phase-ends/current/tasks/T1.md:25
C0106 | PCSX-Redux 298: Lua savestates work, deterministic | pcsx-redux,lua,savestate | 2026-10-12 | 2.2/T1 | phase-ends/current/tasks/T1.md:26
C0107 | PCSX-Redux 298: Lua listener stack leak, recycle fix | pcsx-redux,lua,listener,replay | 2026-10-12 | 2.2/T3.1 | phase-ends/current/tasks/T2.md:26 phase-ends/current/tasks/T3.1.md:26-27
C0108 | PCSX-Redux 298: debugger hang on guest exception | pcsx-redux,lua,debugger | 2026-10-12 | 2.2/T4 | phase-ends/current/tasks/T4.md:22
C0109 | MMX5 stage poke must hit first gameplay load | mmx5,redux,stage,poke | 2026-10-12 | 2.2/T4 | phase-ends/current/tasks/T4.md:23
C0110 | splat emits one WAX section per segment: classify text vs data from the ld map | splat,elf,sections,ld-map,scanner | 2026-10-12 | 2.3/T1 | generalizable
C0111 | splat bss subsegment emits an empty .s unless ld_bss_is_noload is set | splat,bss,noload,yaml | 2026-10-12 | 2.3/T2 | generalizable
C0112 | spimdisasm keeps jump-table words raw when targets are typed label symbols | spimdisasm,jtbl,jump-table,symbols | 2026-10-12 | 2.3/T2 | generalizable
C0113 | Wrap splat undefined_syms_auto in PROVIDE so object labels win | splat,ld,provide,undefined_syms,reloc | 2026-10-12 | 2.3/T3 | generalizable
C0114 | binutils 2.42 --just-symbols sign-extends MIPS ELF32 0x80 addresses | binutils,ld,just-symbols,mips,r_mips_26 | 2026-10-12 | 2.3/T4 | generalizable
C0115 | spimdisasm emits a function as .word data when no start is known | spimdisasm,func,symbol_addrs,segments,tools-health | 2026-10-12 | 2.3/T4 | generalizable
C0116 | GNU ld: dot inside an output section is a section offset | ld,linker-script,dot,assert,shift | 2026-10-12 | 2.3/T5 | generalizable
C0117 | A PSX exe's sector-rounded image tail can be the start of bss | psx,exe,bss,t_size,padding,shift | 2026-10-12 | 2.3/T5 | generalizable
C0118 | Auto-symbolized data near a section start is often packed byte tuples, not pointers | symbols,pointers,data,false-positive,shift,scanner | 2026-10-12 | 2.3/T6 | generalizable
C0119 | Owner of a pointer into same-vram overlays: spawn search, not residency | overlay,same-vram,owner,redux,shift | 2026-10-13 | 2.4/T3.1.1.1.1 | generalizable
C0120 | Overlay region RAM bound from the lowest exe constant above it | overlay,region,bound,shift | 2026-10-13 | 2.4/T2 | generalizable
C0121 | splat/spimdisasm gotchas when symbolizing overlay data words | splat,spimdisasm,reloc_addrs,data | 2026-10-13 | 2.4/T3 | generalizable
C0122 | GNU ld gotchas relinking exe and overlays (ABS syms, just-symbols, ASSERT) | ld,linker-script,just-symbols,assert,shift | 2026-10-13 | 2.4/T4.1 | generalizable
C0123 | Key allowlists by symbol+offset and let make targets build their own variant inputs | shift,allowlist,make | 2026-10-13 | 2.4/T8 | generalizable
C0124 | Redux Read bps do not leak, and a vsync recycle needs a monotonic counter | redux,lua,breakpoint,savestate | 2026-10-13 | 2.4/T3.1 | generalizable
C0125 | Find a damage routine: Redux Write bp on HP byte, log ra | redux,re,damage | 2026-10-14 | 2.5/T1 | -
C0126 | mk/*.mk sorted includes: := sees later-file vars unset, so use = | make,build | 2026-10-14 | 2.5/T2 | -
C0127 | Trace the forced branch (Exec bp) before declaring a behaviour patch | patch,replay,redux | 2026-10-14 | 2.5/T4.1 | -
C0128 | x>>2 replaces x/4 for non-negative x: no sign fixup, and the patch does not grow | gcc,patch,codegen | 2026-10-14 | 2.5/T4.1 | -
C0129 | Zero-store spacer steers prologue hi() register (local-alloc fake lifetime) | idiom,sched,regalloc,prologue,store-order,fake-lifetime | 2026-10-17 | 2.8/T10 | docs/codegen-map/levers.yaml sched_zero_store_spacer
C0130 | addr.h absolute constant lets the lw macro reuse the lui register | idiom,regalloc,addr,lui,lw-macro | 2026-10-17 | 2.8/T10 | docs/codegen-map/levers.yaml regalloc_abs_const_lw
C0131 | rodata-shared carve: plan with draft text, extern rodata stays in region | carve,rodata,rodata-shared,extern,gate | 2026-10-17 | 2.8/T10 | generalizable
C0132 | Fleet-wide function key is (alias, ovl, vram) because rockx5 overlays share vram | wave,ledger,key,overlay | 2026-10-17 | 2.8/T1 | generalizable
C0133 | s8 switch with nonzero lowest case: copy to local s32 in the arm for lb then addiu -k | source-pattern,switch,jumptable,codegen | 2026-10-17 | 2.8/T10 | generalizable
C0134 | Shared division after if/else: write it in each arm to keep stores out of mult/mfhi | source-pattern,sched,division,codegen | 2026-10-17 | 2.8/T10 | generalizable
C0135 | Prove a source rewriter on a full wave, not only selftest fixtures | porter,rewriter,selftest,shapes | 2026-10-17 | 2.8/T13 | generalizable
C0136 | Before trusting a 100% match rate, mutate two matched drafts and expect a diff | verify,try,match-rate | 2026-10-17 | 2.8/T2 | generalizable
C0137 | try masks relocations: check every draft symbol exists in X5 before the gate | try,port,x6,symbols,sha | 2026-10-17 | 2.8/T3 | generalizable
C0138 | Pre-gate check: all wave drafts in one scratch worktree, shapes + readability | wave,gate,shapes,readability | 2026-10-17 | 2.8/T3 | generalizable
C0139 | A bitfield may become an explicit mask with member stores and still match | source-pattern,bitfield,readability | 2026-10-17 | 2.8/T3 | generalizable
C0140 | Long one-line #define bodies get wrapped by clang-format and refused by readability | readability,macro,clang-format | 2026-10-17 | 2.8/T4 | generalizable
C0141 | try ignores rodata: a span owning .rodata strings must emit them in the draft | try,rodata,carve,sha | 2026-10-17 | 2.8/T4 | generalizable
C0142 | Validate pack header arithmetic before naming a format | formats,survey,containers | 2026-10-18 | 2.6/T1 | -
C0143 | Bisect displayed container entry by whole-entry fills | replay,assets,bisect | 2026-10-18 | 2.6/T6 | -
C0144 | Unproven-lever techniques are source-pattern, not idiom | cookbook,symptoms,tools-health | 2026-10-18 | 2.6/T8 | -
C0145 | Fresh-clone proofs start from the public projection, not a dev clone | publish,fresh-clone,projection | 2026-10-18 | 2.7/T5 | generalizable
C0146 | Reloc rename idiom: masked-only dup member from the rep body via #define | dedup,propagate,reloc,rename,sha | 2026-10-19 | 3.1/T5 | generalizable
C0147 | Commit before any carve dry run (make_wt copies dirty paths) | dedup,carve,dry-run,git | 2026-10-19 | 3.1/T1 | -
C0148 | Batched carve bisect: slus before rockx5 (rockx5 links slus) | dedup,propagate,bisect,sha,rockx5 | 2026-10-19 | 3.1/T2 | -
C0149 | Unboostable hard-reg arg set: a zero-store after an aliasing load opens its sched slot | codegen,sched,delay-slot,arg-reg,store-order,boost,zero-store | 2026-10-19 | 3.2/T3 | .run/p32t3/c28 (W23 harvest)
C0150 | Per-site field stores cross-jump into one tail, and a re-read u8 field gives per-use andi | codegen,cross-jump,tail-merge,jump2,v0,gcse,andi,u8,re-read | 2026-10-19 | 3.2/T3 | .run/p32t3/c28 (W23 harvest)
C0151 | Two-sided range test folds to addu/sltu: split it into separate early returns | codegen,fold,range,sltu,slti,early-return,compare | 2026-10-19 | 3.2/T3 | .run/p32t3/c28 (W23 harvest)
C0152 | Per-branch stores, no join variable: keep each arm's tail from cross-jumping | codegen,cross-jump,tail-merge,jump2,join-variable,per-branch,store-order | 2026-10-19 | 3.2/T3 | .run/p32t3/c28 (W23 harvest)
C0153 | m2c seed first draft: cheaper per banked insn, gain in D | m2c,seed,wave,pilot | 2026-10-19 | 3.2/T4 | W23 pilot
C0154 | m2c seed preparation limits: typing pass, context preprocess, jump tables | m2c,seed,wave,types,jumptable | 2026-10-19 | 3.2/T1 | 3.2 T1/T2 gotchas
C0155 | Inlined helper: block-scoped temps reproduce the inline schedule | codegen,inline,sched,scope,regalloc | 2026-10-19 | 3.2/T3 | W23 FA2FC
C0156 | Else-if with the body written twice reproduces a second field load (cross-jump merges it) | codegen,cross-jump,jump2,cse,reload,else-if,duplicate-body | 2026-10-19 | 3.3/T2 | W24 FD048
C0157 | Signed zero test of a u8 byte: read through (s8*) to keep lb, (s8) cast folds to lbu | codegen,lb,lbu,s8,cast,load-sign,zero-test | 2026-10-19 | 3.3/T2 | W24 51F4
C0158 | Decrement-and-test of a u16 field: s32 temp, test (s16)t keeps the sll-16 test | codegen,u16,s16,temp,sign-extend,sll,decrement | 2026-10-20 | 3.3/T3 | W25 EFB20
C0159 | Global array address held across a branch: a local base pointer keeps it in one register | codegen,cse,address,global,base-pointer,local,branch | 2026-10-20 | 3.3/T3 | W25 FA588
C0160 | Inlined helper needs static inline: a plain static helper stays a call at -O2 | codegen,inline,helper,call | 2026-10-20 | 3.3/T4 | W26 F3588
C0161 | Shared switch cases fold to a range test: write each case's body separately | codegen,switch,case,range,cross-jump,duplicate-body | 2026-10-20 | 3.3/T5 | W27 FC718
C0162 | Byte store of 0xFF: write (s8*) = -1 to get addiu -1, not 0xff | codegen,s8,store,constant,sb,0xff | 2026-10-20 | 3.3/T5 | W27 80036E60
C0163 | NULL is undefined under include/types.h: write 0 in drafts | harness,draft,types,null,cc1 | 2026-10-20 | 3.3/T5 | W27 F4C48 FAC04
C0164 | waves.py try leaves our asm at .run/probe/wave/<key>/<triple>/probe.s | harness,wave,try,probe,asm,diagnostic | 2026-10-20 | 3.3/T5 | W27 FD404 F01BC
C0165 | Two-constant field select: if/else with a store per arm, not a ternary | codegen,ternary,if-else,lui,delay-slot,select,store | 2026-10-20 | 3.3/T6 | W28 F03EC
C0166 | Element address recomputed per use: index the global each time, no cached element pointer | codegen,cse,address,global,index,row,cached-pointer | 2026-10-20 | 3.3/T6 | W28 8002D938 FEC84
C0167 | shapes.py refuses a struct pointing to its own tag: type the field void* | harness,shapes,struct,self-reference,void-pointer,draft | 2026-10-20 | 3.3/T6 | W28 F0D34 F13BC
C0168 | An incremented u16 tested through a u16 local: double mask kept, no alias reload | codegen,u16,local,andi,mask,alias,reload,increment | 2026-10-20 | 3.3/T7 | W29 FA9D8 FA2A4
C0169 | Two-case switch with the wrong block order: write an if/else-if chain | codegen,switch,if-else,block-layout,bnez,case | 2026-10-20 | 3.3/T7 | W29 FD9C0
C0170 | Swapped arg registers: a new variable for a derived value splits the live range | codegen,regalloc,global-alloc,live-range,move,a0-a1,temp | 2026-10-20 | 3.3/T7 | W29 FB6A0
C0171 | Post-call global hi() registers rotate by one: declare the callee s32 (C0069) | codegen,regalloc,hi,lui,global,call,residual,open | 2026-10-20 | 3.3/T7 | W29 EEF20
C0172 | Signed range guard in the wrong order: nest the ifs, upper bound outside | codegen,range,slti,bltz,nested-if,compare,order | 2026-10-20 | 3.3/T8 | W30 F87D4
C0173 | Masked value compare gives slti, target sltiu: cast the masked value to u32 | codegen,sltiu,slti,unsigned,cast,mask,compare | 2026-10-20 | 3.3/T8 | W30 EF2F8
C0174 | Constant store in the wrong register: assign it to the compared local, store the local | codegen,regalloc,v0-v1,constant-store,local,reuse | 2026-10-20 | 3.3/T8 | W30 FC3F8
C0175 | Several fail exits in the wrong block layout: early return-0 guards, one shared return 1 | codegen,early-return,guard,block-layout,return,delay-slot | 2026-10-20 | 3.3/T9 | W31 395E8
C0176 | u8 parameter shifted once and stored: write the shift per store, not a reassignment | codegen,u8,param,shift,truncation,cse,store | 2026-10-20 | 3.3/T9 | W31 17E98
C0177 | Equal-constant store pair in reversed order: a chained assignment stores the right target first | codegen,store-order,chained-assignment,sh,constant,pair | 2026-10-20 | 3.3/T9 | W31 FAC00
C0178 | Load placed too late: read the value into a local where the target loads it | codegen,sched,load,local,alias,branch,hoist,store-order | 2026-10-21 | 3.3/T10 | W32 FCBB0 EF140
C0179 | A jal with no a0 setup: declare the callee taking the object and pass it | codegen,callee-decl,a0,arg-live,delay-slot,prototype | 2026-10-21 | 3.3/T10 | W32 F69E4
C0180 | Conditional threshold compare: set an s32 flag per arm, then test the flag | codegen,compare,slti,flag,local,if-else,ternary,branch-polarity | 2026-10-21 | 3.3/T10 | W32 FA4F8
C0181 | Scratchpad pointer added into an integer sum: cast the addr.h view to s32, cast the total once | codegen,addu,operand-order,scratchpad,addr-h,pointer-arith,cast | 2026-10-24 | 3.3/T13 | W35 F9A88
C0182 | s16 field decrement-and-test stores late: update the field in place and test the field, no temp | codegen,s16,decrement,sign-extend,sll,sra,store-order,temp,in-place | 2026-10-24 | 3.3/T14 | W36 F2190 F9F8C
C0183 | s8 global compared then stored: one s8 local serves the compare and the store, no lbu reload | codegen,s8,global,local,reload,lb,lbu,store | 2026-10-24 | 3.3/T15 | W37 EF1D0
C0184 | Byte join variable decremented then stored: declare it s32, a u8 local adds andi 0xff | codegen,u8,s32,andi,join-variable,decrement,sb,type | 2026-10-24 | 3.3/T15 | W37 FD484
C0185 | One global addressed in two blocks: a block-local base pointer in each, not one reused | codegen,cse,address,global,base-pointer,local,branch,split | 2026-10-24 | 3.3/T16 | W38 FAA4C EF604 FA4D0
C0186 | Byte global copied among byte stores: write the copy first, char stores alias it | codegen,sched,alias,load,store-order,u8,global,char | 2026-10-24 | 3.3/T16 | W38 slus 8004FC64
C0187 | Global s16 load hoisted above stores: declare it s16[] and read [0], not a scalar | codegen,alias,scalar,array,extern,lh,hoist,load-order | 2026-10-24 | 3.3/T16 | W38 FB148
C0188 | Gate debt floor: unmarked goto refuses the bank commit, so mark it !FAKE in src and draft | workflow,gate,debt-floor,goto,FAKE,bank,commit | 2026-10-24 | 3.3/T16 | T16.c49 W38 gate
C0189 | Duplicated store in a j delay slot: write the join store once, after the if/else | codegen,reorg,delay-slot,join,store,duplicate,if-else | 2026-10-24 | 3.3/T17 | W39 slus 800378C8
C0190 | Table of 6-byte rows read at +2/+4: declare s16 D[][3], read D[i][k] inline | codegen,array,2d,row,struct-array,address,lh,lo-fold | 2026-10-24 | 3.3/T17 | W39 F7BEC
C0191 | Global compared with a field loads late: put the global on the left of the compare | codegen,compare,operand-order,global,load-order,regalloc | 2026-10-24 | 3.3/T17 | W39 F6820
C0192 | Same call on two paths merged into one: nest if/else so each arm keeps its call | codegen,cross-jump,tail-merge,jump2,call,nested-if,early-return | 2026-10-24 | 3.3/T17 | W39 slus 80046984
C0193 | Negative mask held in a register for a loop: assign an s32 mask local before it | codegen,regalloc,mask,and,andi,local,constant,loop | 2026-10-24 | 3.3/T17 | W39 F2AE0
C0194 | Byte reload cse removes: one marked volatile access, not the empty asm (gate refuses it) | codegen,cse,reload,volatile,alias,FAKE,gate,lbu | 2026-10-24 | 3.3/T17 | W39 F4C20 F9520 T17.c49
C0195 | Undoing an uncommitted gate run: make split build before re-gating, else not-found | workflow,gate,undo,split,asm,not-found,config | 2026-10-24 | 3.3/T17 | T17.c49 W39 gate
C0196 | Lui per arm, one sw at the join: write the join store in each arm, jump2 cross-jumps it | codegen,cross-jump,jump2,join,store,duplicate,if-else,lui | 2026-10-24 | 3.3/T18 | W40 slus 800180DC F289C
C0197 | Two bytes of a table row with separate address adds: D[r*2] then (&D[r*2])[1], no table local | codegen,array,address,addu,cse,table,lbu,cross-jump | 2026-10-24 | 3.3/T18 | W40 FE5BC
C0198 | Stored byte sum tested for zero with a lone sll 24: test the field through an s8 view | codegen,s8,u8,zero-test,sll,andi,store,view | 2026-10-24 | 3.3/T18 | W40 F9C08
C0199 | Table call with the pointer in $5 and $4 untouched: pass the incoming a0 | codegen,jalr,call,argument,regalloc,fn-table,a0,passthrough | 2026-10-24 | 3.3/T18 | W40 F63E4
C0200 | Harvest row idiom: a new idiom is the bare id, not new:C<id> (harvest.py check) | workflow,harvest,check,cookbook-id | 2026-10-24 | 3.3/T18 | T18.c50 W40 harvest
C0201 | Every call arg narrowed lhu+sll/sra: declare the callee's params s32, not the s16/u8 consensus | codegen,callee-decl,prototype,param,s16,s32,narrowing,lh,lhu | 2026-10-24 | 3.3/T19 | W41 EED00
C0202 | Table index from a just-stored byte keeps andi 0xFF: index by the stored field, not the local | codegen,cse,store-forward,u8,andi,table,index,field | 2026-10-24 | 3.3/T19 | W41 slus 8003D5E0
C0203 | 2nd s16 counter loaded through the base local: read it via the object pointer, store via the local | codegen,s16,counter,decrement,base-pointer,load,store,local | 2026-10-24 | 3.3/T20 | W42 FF3BC
C0204 | Target has an empty 0x10 stack frame: an unused u8 pad[16] local (!FAKE) keeps it | codegen,stack,frame,addiu-sp,unused-local,aggregate,FAKE | 2026-10-24 | 3.3/T20 | W42 slus 800202EC
C0205 | State machine reset block placed before the shared increment: make the increment a goto label in the state-1 body | codegen,block-layout,goto,label,state-machine,source-order,FAKE | 2026-10-24 | 3.3/T20 | W42 EECC0
C0206 | Loop bound copy into a saved reg missing: write the invariant bound inline, not as an end local | codegen,loop,bound,invariant,regalloc,end-pointer,local | 2026-10-24 | 3.3/T20 | W42 slus 80033024
C0207 | Compare temp copied in the then-arm: the copy fills the beqz delay slot | codegen,regalloc,delay-slot,temp,copy,compare,then-arm,move | 2026-10-24 | 3.3/T21 | W43 F3048
C0208 | One-pass loop index tested with beqz: declare it u32, unsigned i < 1 folds to i == 0 | codegen,loop,index,unsigned,u32,beqz,blez,compare | 2026-10-24 | 3.3/T21 | W43 slus 8001F1B0
C0209 | Flag set by either of two tests: hit = 0, then one if per test sets hit = 1 | codegen,flag,local,compare,sltu,delay-slot,regalloc,if | 2026-10-24 | 3.3/T21 | W43 slus 8004F4E0
C0210 | Abs feeding a magic divide: a value ternary keeps one block, the magic lui hoists | codegen,abs,ternary,abssi2,divide,magic,lui,delay-slot,block | 2026-10-24 | 3.3/T21 | W43 F071C
C0211 | Pointer loaded from memory for two RMW blocks: re-read it inline per block, no local | codegen,regalloc,pointer,reload,local,inline,rmw,or | 2026-10-24 | 3.3/T21 | W43 F85D4
C0212 | Constant address held in $s across calls: the body is a sibling helper, inline it (static inline) | codegen,inline,helper,cse,constant-address,scratchpad,callee-saved,call | 2026-10-24 | 3.3/T22 | W44 slus 8003CEDC
C0213 | s8 arg indexing a table: three statements (idx, base, p) put the lui between the shifts | codegen,s8,sign-extend,combine,sra,sll,lui,index,base-pointer | 2026-10-24 | 3.3/T22 | W44 slus 8003DAF4
C0214 | Halfword field read into a local: u16 local gives lhu, s16 gives lh, whatever the table type | codegen,u16,s16,lh,lhu,local,load-sign,table | 2026-10-24 | 3.3/T22 | W44 slus 80052D30 8004CED0 80030D88
C0215 | Insert into the high s16 half of a reg local: Fix0418 union, write d.h.hi | codegen,union,s16,store-bit-field,sll,or,sra,uninit,local,Fix0418 | 2026-10-24 | 3.3/T22 | W44 F1A88
C0216 | Byte-clear loop with all regs shifted by one: store a zero local (z = 0), not literal 0 | codegen,regalloc,loop,zero,local,sb,byte-clear | 2026-10-24 | 3.3/T22 | W44 slus 8002CF70 8002DC44
C0217 | Global set from a byte, read in both arms: read the global, not a local copy (lbu+sll+sra kept) | codegen,global,local,reload,lbu,sll,sra,if-else,s16 | 2026-10-24 | 3.3/T22 | W44 slus 80030D88
C0218 | Switch over a default store loses its case-0 test: case 0 re-stores the default | codegen,switch,case,default,store,beqz,block-layout | 2026-10-24 | 3.3/T22 | W44 slus 8004CED0
C0219 | Callee result and global base share a register: give each role its own local | codegen,regalloc,local,pointer,call-value,base-pointer,split | 2026-10-24 | 3.3/T23 | W45 FA4F8
C0220 | Byte state tested ==1, then slt <2, then ==0: nest the ifs, write the tail in both arms | codegen,nested-if,switch,compare,order,cross-jump,tail,block-layout | 2026-10-24 | 3.3/T23 | W45 slus 80021434
C0221 | Countdown clear loop with li and addu swapped: init counter then pointer in the for header | codegen,loop,for,init,comma,sched,li,addu,byte-clear | 2026-10-24 | 3.3/T23 | W45 EF1E0
C0222 | Byte loop walking down from base+N with bgez: write the plain up-count, gcc reverses it | codegen,loop,reversal,up-count,down-count,strength-reduction,bgez,byte-clear | 2026-10-24 | 3.3/T23 | W45 F0DC0
C0223 | u16 field incremented and tested modulo: increment on its own line, then test the field | codegen,u16,increment,sh,andi,multu,modulo,store-order | 2026-10-24 | 3.3/T23 | W45 slus 80057BD4
C0224 | Global halfwords at fixed offsets with hi anchored at D+off: declare s16 D[] and index it | codegen,extern,s16,array,index,hi,lui,global,offset-cast | 2026-10-24 | 3.3/T23 | W45 EFAC8
C0225 | Dead lb of an s8 global before a call: branch on it with two identical arms | codegen,lb,dead-load,s8,global,tail-merge,cross-jump,identical-arms | 2026-10-24 | 3.3/T24 | W46 slus 80055920
C0226 | Two arms each n = byte + 1, one in the wrong reg: write both arms as `n = x`, then `n++` | codegen,regalloc,if-else,arm-shape,mirror,increment,lb,v0-v1 | 2026-10-24 | 3.3/T24 | W46 F609C
C0227 | Return-0 block placed last behind blez: goto a trailing none: label (marked !FAKE) | codegen,block-layout,goto,label,return,blez,bgtz,FAKE | 2026-10-24 | 3.3/T24 | W46 F30A0
C0228 | One call on two paths, a0 move in a beq slot: write one call per arm, gcc merges them | codegen,cross-jump,tail-merge,cse,call,a0,delay-slot,if-else | 2026-10-24 | 3.3/T25 | W47 slus 8003F2D8
C0229 | Difference sign-extended by sll/sra before an s16 store: compute it into an s16 local | codegen,s16,sign-extend,sll,sra,temp,local,cast,fold | 2026-10-24 | 3.3/T25 | W47 slus 800310E4
C0230 | Two-value state picked by a test with a call: if/else after the call, arms in fall-through order | codegen,branch-polarity,if-else,call,callee-saved,state,sltiu,u32 | 2026-10-24 | 3.3/T25 | W47 F4658
C0231 | Global base plus a separate addiu, not hi(D+off): write p = D then p += n | codegen,global,address,hi,lui,addiu,pointer,base,fold | 2026-10-24 | 3.3/T25 | W47 FB404
C0232 | Param stored to a u8 global before its andi: declare it s32, test (u8)param | codegen,param,u8,s32,narrowing,andi,sb,store-order | 2026-10-24 | 3.3/T25 | W47 slus 8001B2E0
C0233 | Byte field tested by an outer and an inner if: read it once into a u8 local | codegen,u8,local,lbu,reload,cse,nested-if,mask | 2026-10-25 | 3.3/T26 | W48 slus 800477E4
C0234 | Independent store pair in the wrong order: write it in the reverse of the asm's order | codegen,sched,store-order,reverse,global,rmw,v0-v1,statement-order | 2026-10-25 | 3.3/T27 | W49 FA390 FADFC F8920 slus 80019BD4
C0235 | Unknown-trip loop form (li n, blez, bnez down-counter): write the bound as end - p with a named end | codegen,loop,bound,blez,bnez,trip-count,cse,end-pointer | 2026-10-25 | 3.3/T28 | W50 slus 8001DB78
C0236 | Switch whose cases all return -1: return in each case, not break plus one shared return | codegen,switch,case,return,tail,cross-jump,block-layout | 2026-10-25 | 3.3/T28 | W50 slus 80031508
C0237 | Pointer table indexed by two bytes with one shift: flat D[c*2+d], not 2-D D[][2] | codegen,array,table,index,sll,flat,2d,address | 2026-10-25 | 3.3/T28 | W50 slus 80047184
C0238 | Fail store placed before the call arm: one || chain with the assignment inside, not nested ifs | codegen,block-layout,or-chain,assignment,early-return,if-else,guard | 2026-10-25 | 3.3/T28 | W50 F2E48_ovl02
C0239 | Callee result modulo a constant gives multu/srl: declare the callee returning u32 | codegen,unsigned,u32,modulo,multu,callee-decl,return-type | 2026-10-25 | 3.3/T28 | W50 F4818_ovl06
C0240 | s16 field tested then decremented in the arm: read it into a u16 local before the test | codegen,s16,u16,lh,lhu,decrement,local,load-order,zero-test | 2026-10-25 | 3.3/T29 | W51 EEF0C_ovl23
C0241 | Post-decrement with the old value tested via a move copy: a second local, then v-- in place | codegen,s32,decrement,post-decrement,move,copy,local,old-value | 2026-10-25 | 3.3/T29 | W51 slus 80053444
C0242 | Two global base locals with lui/addiu pairs swapped: declare them in the target's order | codegen,base-pointer,local,declaration-order,lui,addiu,global,address | 2026-10-25 | 3.3/T29 | W51 slus 800560D8
C0243 | Constant regs off at a struct store run: typed view, then try source orders | codegen,sched,store-order,struct,view,li,v0-v1,constant-store | 2026-10-25 | 3.3/T30 | W52 FAA20_ovl57
C0244 | Byte table at an offset in a global, addu base-first: s8 array member in a struct view | codegen,addu,operand-order,struct,array-member,index,lb,address | 2026-10-25 | 3.3/T30 | W52 slus 80019DF0
C0245 | Table base picked by a branch, addu operands swapped: hold the base in an s32 local | codegen,addu,operand-order,base-pointer,s32,local,index,rtl-shape | 2026-10-25 | 3.3/T30 | W52 slus 8003FE04
C0246 | Two-way byte dispatch whose first test inverts: a two-case switch, not if/else-if | codegen,switch,if-else,block-layout,beqz,case | 2026-10-25 | 3.3/T30 | W52 F12B0_ovl05
C0247 | Two-constant select into one field: store the ternary directly, not a preset local | codegen,ternary,select,store,local,v0-v1,sched | 2026-10-25 | 3.3/T30 | W52 FB5BC_ovl27
C0248 | try-match but gate r6 red on lui/lo bytes: global store order, check objdump -dr relocs | gate,try,reloc,store-order,global,lui,sha,objdump | 2026-10-25 | 3.3/T30 | W52 FAF28_ovl49
C0249 | Second arm placed after the body with a jump back to the test: goto out and goto back (marked !FAKE) | codegen,block-layout,goto,label,if-else,j,FAKE,source-order | 2026-10-25 | 3.3/T31 | W53 F3040_ovl01
C0250 | One p+i addu shared across blocks where the target recomputes it: s8 array members in a struct view | codegen,cse,addu,struct,array-member,index,lb,address | 2026-10-25 | 3.3/T31 | W53 slus 8003FCC0
C0251 | Byte classed by slt tests, ours folds a range to sltu: a switch with a GNU case range | codegen,switch,case-range,slt,sltu,range,decision-tree,if-else | 2026-10-25 | 3.3/T32 | W54 slus 8003A134
C0252 | Table index by the sign of an s8 local gives slt/subu: write i >> 31, not i >> 7 | codegen,s8,sign,shift,sra,index,table,lb | 2026-10-25 | 3.3/T33 | W55 F016C_ovl24
C0253 | u8 global compared, picks a ternary, then stored: a local for the compare, reload the global for the store | codegen,u8,global,local,reload,ternary,move,delay-slot | 2026-10-25 | 3.3/T33 | W55 slus 8004E8C0
C0254 | If-chain result built in a1 then moved to v0: return in place in every arm, no result local | codegen,return,local,v0,regalloc,if-else,early-return | 2026-10-25 | 3.3/T33 | W55 F09A0_ovl07
C0255 | Same byte compared in both arms against a per-arm constant: write compare and store per arm, ==0 arm first | codegen,cross-jump,tail-merge,jump2,compare,if-else,arm-order,lb | 2026-10-25 | 3.3/T34 | W56 slus 800470EC
C0256 | m2c seed passes a1 that only feeds a store: not an argument, drop it from the callee decl | m2c,seed,callee-decl,prototype,argument,a1,delay-slot,regalloc | 2026-10-25 | 3.3/T34 | W56 slus 8001E810 F85AC_ovl29
C0257 | Two loop invariants hoisted in the wrong order: read the first one into a local, in target order | codegen,loop,invariant,hoist,prologue,saved-reg,local,table-call | 2026-10-25 | 3.3/T34 | W56 slus 80020904
C0258 | Table call sets up the table address before the argument addresses: read each argument into a local first | codegen,table-call,jalr,argument,lui,local,sched,order | 2026-10-25 | 3.3/T35 | W57 slus 80054BB8
C0259 | Table index ending in +1 folds into the lbu offset: compute the index in its own s32 local | codegen,index,table,local,s32,lbu,offset,fold,addiu | 2026-10-25 | 3.3/T36 | W58 slus 8002AA7C
C0260 | u16 field incremented then compared ==N: pre-increment inside the compare, not a temp local | codegen,u16,increment,pre-increment,sh,andi,compare,delay-slot,store-order | 2026-10-25 | 3.3/T37 | W59 F796C_ovl09
C0261 | Hand-asm signs in the target ($sp write, lone break, old-pointer loop compare): ledger at once, no C form | codegen,hand-asm,include_asm,ledger,sp,break,loop,m2c | 2026-10-25 | 3.3/T38 | W60 slus 80013348 8001336C 80013438 8001344C
C0262 | Long list in a make recipe hits MAX_ARG_STRLEN (128 KiB per sh -c arg): pass it through a file | make,shell,argv,e2big,max_arg_strlen,recipe,build | 2026-10-26 | 3.3/T4 | T4 generalizable (c49 no-rom compile-only)
