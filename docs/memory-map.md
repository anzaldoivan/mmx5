# Memory map

This file is the static load map. Every claim below is
`static` (decoded from SLUS_013.34 code/tables and the ROCK_X5.BIN TOC). T5 proves the claims live and appends
`- datapoint` lines.

## Main executable (PS-X EXE header) `static`

- The entry pc0 is 8005894C. The gp0 is 00000000. The stack s_addr is 801FFFF0. `static`
- The text is 80010000..80092000. Its size is 0x82000. Its file offset is 0x800. `static`
- In the header, data/bss is d_size 0, b_size 0 (none declared). `static`

## Exe shift range (2.3 T1) and overlay regions (2.4 T1)

- The range is 80010000..800EE970 = image 80010000..80092000 + bss 80092000..800EE970 (`tools/shift/scan.py`, run
  time). `static`
- The header b_size is 0. So the bss end = the highest SHN_ABS symbol of the exe ELF below ovl00 vram 800EE970
  (D_800EE96C), rounded up to 4, + 1 word. Thus bss runs up to the overlay vram (no slack for a shift pad). `static`
- In 2.3 T2, the splat bss subsegment `[0x82800, bss]` at vram 80092000 with `bss_size: 0x5C970`
  (config/us/splat.main.yaml) gives the NOLOAD `.main_bss` 80092000..800EE970. The end = the __start clear-loop bound
  D_800EE970. The bss D_ symbols are section-relative, not ABS. The script scan.py takes bss_end from the end of that
  section. `static`
- The baseline of 2.3 T1 is 37816 unsymbolized (exe 6283, rockx5 31533) (data 9140, hilo 54, gprel 0, jal 45,
  abs 28577). `static`
- 2.3 T5 pinned tail: 80091C30..80092000 (0x3D0, splat `[0x82430, .data, func_800203F0]`, defined in src/main/func_800203F0.c) never moves under SHIFT=1. `static`
  - Why: the image has 0 bytes of free trailing fill. D_80091C10 is a null-terminated table that ends at 80091C2F.
    From D_80091C30 (= _gp) the labels are zero, bss-like: D_80091D60 is a 2x6x0x44 = 0x330 buffer that runs to
    80092090, inside `.main_bss` (asm/slus/game_80027514.s:583-640). So that range stays with bss.
  - The shifted build moves every other address by reordering `.main` to text, data, rodata
    (tools/shift/pad_ld.py). At SHIFT_PAD 0, the moves are text/data -0x1DC8 and rodata +0x7FE68.
- 2.4 T1 overlay regions: `scan.py` reads rockx5 `ovlNN_VRAM`/`ovlNN_VRAM_END` and groups the overlays by vram.
  Region A is 800EE970..8010309E (ovl00-29). Region B is 800FA000..80100172 (ovl30-58). A overlaps B. `static`
  - `scan.py` also reports the targets in these regions, per direction: exe->exe, exe->ovl, ovl->exe, ovl->ovl.
- The baseline of 2.4 T1 is 6605 unsymbolized (exe->exe 0, exe->ovl 362, ovl->exe 0, ovl->ovl 6243). `static`
- 2.4 T2 region bounds (config/shift/regions.txt): `static`
  - A starts at 800EE970. Its max end is 8010309E (ovl04). Its bound is 80105000. Its slack is 0x1F62.
  - A.lo is the A members with a retail end <= 800FA000. They may be resident while B loads. Its max end is 800F80F8
    (ovl18). Its bound is 800FA000. Its slack is 0x1F08.
  - B starts at 800FA000. Its max end is 80100172 (ovl34). Its bound is 80105000. Its slack is 0x4E8E.
- 3.8 T2 region B base hazards: five C code sites hold 800FA000 as a constant (lui/ori). A symbol gives lui/addiu
  and loses the byte match. Thus the region B base does not move with a shift. config/us/shift/not_pointers.txt
  accepts each site under R96.
  - main 8001369C (`load_stage`): lui/ori pair, found by `scan.py`.
  - main 80014310 (`poll_rock_bin_read`): lui/ori pair, found by `scan.py`.
  - main 80013528 (`load_stage_ovl_b`): lui at 80013528, ori at 8001356C. The pair is outside the 8-word hilo window,
    so `scan.py` does not find it.
  - rockx5 ovl18 800F6B24 (`func_800F6A94_ovl18`): lui/ori pair, found by `scan.py`.
  - rockx5 ovl18 800F6C1C (`func_800F6BF8_ovl18`): lui/ori pair, found by `scan.py`.

## Overlay table `static`

- The loader is read_rock_bin_toc 80015DDC: BIN sector 0 TOC -> RAM table 800E6188, 59 rows of 8 bytes. Row 59 is
  all-zero. `static`
- read_rock_bin_member is 80015EB4(a0=index, a1=dest). The dest comes from the call sites 800136EC (base `*80010000`, initial
  800EE970), 800136B4 and 80013568 (800FA000). `static`
- poll_rock_bin_read is 80014290. It reads a row of the TOC table 800E6188 (`src/main/file/poll_rock_bin_read.c:59-60`), as read_rock_bin_member does
  (`src/main/file/read_rock_bin_member.c:42-43`). It also calls CdReset, CdControlB and VSync. `static`
- The region bounds are 80105000 for A and B (the base of the exe CD/image buffer) and 800FA000 for A.lo. See
  config/shift/regions.txt. `static`
- If the blob contains `jr ra` (03E00008), the kind is `code`. If not, the kind is `data`. A `-` dest means that the
  index is in no loader table. `static`

| index | bin_offset | size | dest | kind | status |
|---|---|---|---|---|---|
| 0 | 0x800 | 0xCD2C | 800EE970 | code | static |
| 1 | 0xD800 | 0xF301 | 800EE970 | code | static |
| 2 | 0x1D000 | 0x5FC8 | 800EE970 | code | static |
| 3 | 0x23000 | 0xB8E4 | 800EE970 | code | static |
| 4 | 0x2F000 | 0x1472E | 800EE970 | code | static |
| 5 | 0x43800 | 0x6FF6 | 800EE970 | code | static |
| 6 | 0x4A800 | 0x10FE0 | 800EE970 | code | static |
| 7 | 0x5B800 | 0x136B6 | 800EE970 | code | static |
| 8 | 0x6F000 | 0x56A0 | 800EE970 | code | static |
| 9 | 0x74800 | 0xCD12 | 800EE970 | code | static |
| 10 | 0x81800 | 0xD85A | 800EE970 | code | static |
| 11 | 0x8F800 | 0xB6F7 | 800EE970 | code | static |
| 12 | 0x9B000 | 0x3792 | 800EE970 | code | static |
| 13 | 0x9E800 | 0x540 | 800EE970 | data | static |
| 14 | 0x9F000 | 0x3736 | 800EE970 | code | static |
| 15 | 0xA2800 | 0x540 | 800EE970 | data | static |
| 16 | 0xA3000 | 0x3C80 | 800EE970 | code | static |
| 17 | 0xA7000 | 0x540 | 800EE970 | data | static |
| 18 | 0xA7800 | 0x9788 | 800EE970 | code | static |
| 19 | 0xB1000 | 0x540 | 800EE970 | data | static |
| 20 | 0xB1800 | 0x848C | 800EE970 | code | static |
| 21 | 0xBA000 | 0x1910 | 800EE970 | code | static |
| 22 | 0xBC000 | 0x848 | 800EE970 | code | static |
| 23 | 0xBD000 | 0xF2C | 800EE970 | code | static |
| 24 | 0xBE000 | 0x7618 | 800EE970 | code | static |
| 25 | 0xC5800 | 0x3B85 | 800EE970 | code | static |
| 26 | 0xC9800 | 0xBD14 | 800EE970 | code | static |
| 27 | 0xD5800 | 0xF828 | 800EE970 | code | static |
| 28 | 0xE5800 | 0x100ED | 800EE970 | code | static |
| 29 | 0xF6000 | 0xBCE2 | 800EE970 | code | static |
| 30 | 0x102000 | 0x3E58 | 800FA000 | code | static |
| 31 | 0x106000 | 0x5C44 | 800FA000 | code | static |
| 32 | 0x10C000 | 0x5038 | 800FA000 | code | static |
| 33 | 0x111800 | 0x5058 | 800FA000 | code | static |
| 34 | 0x117000 | 0x6172 | 800FA000 | code | static |
| 35 | 0x11D800 | 0x5CBA | 800FA000 | code | static |
| 36 | 0x123800 | 0x4EA2 | 800FA000 | code | static |
| 37 | 0x128800 | 0x3C9B | 800FA000 | code | static |
| 38 | 0x12C800 | 0x39D0 | - | code | static |
| 39 | 0x130800 | 0x4D70 | - | code | static |
| 40 | 0x135800 | 0x68C | 800FA000 | code | static |
| 41 | 0x136000 | 0x18A4 | 800FA000 | code | static |
| 42 | 0x138000 | 0x440 | 800FA000 | code | static |
| 43 | 0x138800 | 0x3A8 | 800FA000 | code | static |
| 44 | 0x139000 | 0x814 | 800FA000 | code | static |
| 45 | 0x13A000 | 0x740 | 800FA000 | code | static |
| 46 | 0x13A800 | 0xC34 | 800FA000 | code | static |
| 47 | 0x13B800 | 0x5B0 | 800FA000 | code | static |
| 48 | 0x13C000 | 0x530 | 800FA000 | code | static |
| 49 | 0x13C800 | 0x21C8 | 800FA000 | code | static |
| 50 | 0x13F000 | 0x1C8C | 800FA000 | code | static |
| 51 | 0x141000 | 0x40C | 800FA000 | code | static |
| 52 | 0x141800 | 0x1968 | 800FA000 | code | static |
| 53 | 0x143800 | 0x15A0 | 800FA000 | code | static |
| 54 | 0x145000 | 0x1558 | 800FA000 | code | static |
| 55 | 0x146800 | 0x32C0 | 800FA000 | code | static |
| 56 | 0x14A000 | 0x3F00 | 800FA000 | code | static |
| 57 | 0x14E000 | 0x17E8 | 800FA000 | code | static |
| 58 | 0x14F800 | 0x2240 | 800FA000 | code | static |

Hazard: 5 exe sites hold raw retail-valued pointers into overlay region A (`config/us/shift/not_pointers.txt`, T4.1.1).

- `800710A4->800EEBB8` (mode 6)
- `80071254->800F2E38` (type 59)
- `80071258->800F33A8` (type 60)
- `8007466C->800EEA88` (action 31)
- `80074710->800EECC0` (action 72)

SHIFT does not move them. make replay-shift (T6) arbitrates. A divergence at any of them reopens the word.

## Boundaries `static`

- The private Ghidra import and its export script write a private boundaries table. Each
  line is `<start>-<end> | jumptable|libobj|libobj? | <owner> | <evidence>`. The end is exclusive, overlay starts
  `ovlNN:`. `static`
- The jumptable lines are 583 (exe 42, overlays 541). 452 owners are `nofn@<jr>` (Ghidra made no function around the
  jr). `static`
- The libobj lines are 181 (psx_ldr PsyQ 4.7.0 obj sigs, owner `<lib>/<obj>`). The libobj? lines are 0. `static`
- The unresolved computed jumps (jr non-ra, no recovered table) are 8. `static`
- The overlays loaded as Ghidra blocks are 53 (code, dest known). The skipped overlays are 38, 39 (dest=null). `static`
- 80014064 is renamed Ovl_Load2 -> wait_rock_bin_read. It calls CdReset/CdControlB/VSync. T5 saw a1=1F801110. `static`

## Overlays 38/39 (T2, 1.8.3)

- static: no 8006FD50/8006FD80/8006FC5C entry is 38 or 39. The exe read_rock_bin_member call sites are only
  80013568/800136B4/800136EC. The loader is ovl18 (stage 12 sub 0, 8006FD50[24]). It calls read_rock_bin_member(0x26, 800FA000) at
  800F6B30 and read_rock_bin_member(0x27, 800FA000) at 800F6C30. These calls are states 3/6 of an object state machine (dispatcher
  800F5EA0, handler table 800F80D4). `static`
- ovl38: dest 800FA000 proven live (phase 2.2 T4): read_rock_bin_member(0x26) a1=800FA000 ra=800F6B38 (ovl18), spawn-poke route of the private load-map prover (`ovl3839`). Log 2026-10-12 prove_ovl3839.spawn.log
- ovl39: dest 800FA000 proven live (phase 2.2 T4): read_rock_bin_member(0x27) a1=800FA000 ra=800F6C38 (ovl18), spawn-poke route of the private load-map prover (`ovl3839`). Log 2026-10-12 prove_ovl3839.spawn.log
- binding (1.8.3 T2): the private load-map table's dest for 38/39 is filled only from a live datapoint, never from
  the static 800FA000. Filling it flips harness p6 and makes 38/39 code segments in the rockx5 yaml/census. The test
  is the check of the private load-map tool.

## X6 twin leads at boot (3.7 T1) `lead`

R3.5-003 pairs three X5 boot functions with X6 functions. Each X6 body has the same masked hash and word count as its
X5 twin (the private twin table `x6-twins.tsv`). A pair is a lead for a name, not a name. The gate and the name rules decide.

- 80012F58 (13 words) pairs with X6 `func_8001344C`, the task starter (`x6-twins.tsv:3440-3441`). X6 has no name. `lead`
- 80014464 (68 words) pairs with X6 `func_80014D50`, which calls CdGetSector and CdPosToInt (`x6-twins.tsv:3460-3461`).
  X6 has no name. `lead`
- 80015EB4 (62 words, read_rock_bin_member) pairs with X6 `read_rock_bin_member` (`x6-twins.tsv:3480-3481`). The name rests on
  this twin. Phase 3.7 T4 gives it through the `x6-twin` class. `lead`
- `mmx6:docs/systems/boot.md:234` says that X5 has no counterpart for the boot chain, the `D_800710E8` table, the
  title or the menu. That line is about the chain as a whole. Lines 230-233 of the same file list these single
  pairs. Thus the line does not deny the 80015EB4 pair. `lead`

## Object pools and dispatch tables (4.8 T5)

At each stage load, load_stage copies 7 directory entries to the scratchpad words 1F800080..1F800098. Each
directory has the form `void* D_dir[stage][sub]`, with 23 stages and 2 subs. A null entry marks an absent sub. The
member at 800EE970 is `g_ovl_idx_stage_sub[stage*2 + sub]` (8006FD50). Stage 0xB also loads
`g_ovl_idx_stage_c[p[0x1D]]` at 800FA000. `static`

The stage 0xB capture records p[0x1D] = 0. No stage 0xB table word points at 800FA000 or above. Its sub 0 targets
are in ovl16, and its sub 1 targets are in ovl17. `proven` for p[0x1D], `static` for the targets

A table ends at the next table of the same stage, or at its first word that is not a 4-aligned code pointer. The
lengths in words are D_8006FD94 77, D_8006FE4C 58, D_8006FF04 40, D_8006FFBC 45, D_8007012C 64, D_80070074 32,
D_800701E4 19 to 22, and D_80071168 99. `static`

The object map tool of the project decodes the tables and writes the object leads table (1306 rows, 44 proven, 0
mismatches). A PCSX-Redux capture script writes one capture file per stage (2026-11-22). It samples every 30
frames from the first gameplay stage load. `nopoke.jsonl` is stage 0. `st1`, `st2`, `st3`, `st5` and `st11` poke
stages 1, 2, 3, 5 and 0xB.

D_80071168 is one table for all stages. Its words outside the exe point into the stage member at 800EE970. The tool
objmap places such a target in the member of the stage that was live when it was captured.

A datapoint is a sampled frame that has a live slot (+0 != 0). On that frame, the table word must equal the static
directory entry. Also, the RAM word `table[type]` must equal the static word.

- 80092090 (48 x 0x9C), loop func_80021F64, word 1F800080, directory D_8006FD94. `proven`
  - datapoint 463 frames: st1.jsonl 192 (8082-13902), st2.jsonl 118 (9582-13992), st3.jsonl 153 (8352-13992)
- 80098120 (32 x 0x9C), loop func_80022084, fixed exe table D_80071168, no scratchpad word. `proven`
  - datapoint 72 frames: st5.jsonl 72 (8082-13872)
  - D_80071168 type 0x39 is func_800F1448 in ovl07, the stage 5 member. It is live in 72 frames.
  - Stages 0 to 3 and 0xB have no live slot. The setters of types 0x38 to 0x3E are in ovl03, ovl06, ovl07, ovl24
    to ovl27, ovl31 and the exe.
- 80096D98 (32 x 0x9C), loop func_800221B0, word 1F800084, directory D_8006FE4C. `proven`
  - datapoint 102 frames: st2.jsonl 63 (9792-13932), st3.jsonl 39 (10632-13392)
- 80094398 (96 x 0x70), loop func_800222D0, word 1F800088, directory D_8006FF04. `proven`
  - datapoint 280 frames: st1.jsonl 87 (8862-13812), st2.jsonl 6 (10452-13842), st3.jsonl 14 (10722-13242),
    st5.jsonl 173 (8082-13992)
- 8009E7A0 (96 x 0x30), loop func_800223E4, word 1F80008C, directory D_8006FFBC. `proven`
  - datapoint 1063 frames: nopoke.jsonl 98 (8082-10992), st1.jsonl 192 (8082-13902), st11.jsonl 200 (8022-13992),
    st2.jsonl 201 (7992-13992), st3.jsonl 194 (8082-13992), st5.jsonl 178 (8082-13992)
- 800D1F40 (128 x 0x60), loop func_80022618, word 1F800090, directory D_8007012C. `proven`
  - datapoint 837 frames: nopoke.jsonl 98 (8082-10992), st1.jsonl 198 (8082-13992), st11.jsonl 5 (8082-8202),
    st2.jsonl 201 (7992-13992), st3.jsonl 177 (8142-13992), st5.jsonl 158 (8142-13992)
- 800C6A10 (64 x 0xA4), loop func_800224F8, word 1F800094, directory D_80070074. `proven`
  - datapoint 312 frames: st3.jsonl 134 (8982-13992), st5.jsonl 178 (8082-13992)
- 8009F9A0 (64 x 0x60), loop func_8002272C, word 1F800098, directory D_800701E4. `proven`
  - datapoint 551 frames: nopoke.jsonl 61 (8112-10062), st1.jsonl 32 (8112-13242), st11.jsonl 3 (8082-8142),
    st2.jsonl 199 (7992-13992), st3.jsonl 194 (8082-13992), st5.jsonl 62 (8142-13902)

## Data blocks in C (4.8 T12)

- Pointer tables: D_800FA7DC_ovl44, D_800FA580_ovl47, D_800FA510_ovl48 and D_800FA3E8_ovl51 are defined in their reader units. `static`
- Exe bss: D_8009A3B8, D_8009E798, D_8009E79C, g_decompression_buffer, D_800CE598, D_800D5120 and D_800D5138 are defined in their sole readers. `static`

## Datapoints

<!-- T5: `- datapoint <exe|ovl<n>> <addr> <how> <file range> sha1=… ram=… <date> <log>` -->
- datapoint exe 80015DDC window SLUS_013.34:0x65DC+0x100 sha1=2d52315f4d90e4f2630584d80a926ef3e1eee83c ram=2d52315f4d90e4f2630584d80a926ef3e1eee83c 2026-10-03 prove_exe.boot1.log
- datapoint exe 8005894C window SLUS_013.34:0x4914C+0x100 sha1=d2b95d70aeff18e846c1ab9ae2f76f298a31accb ram=d2b95d70aeff18e846c1ab9ae2f76f298a31accb 2026-10-03 prove_exe.boot1.log
- datapoint exe 80067F98 window SLUS_013.34:0x58798+0x100 sha1=2e11373bf3392b80517572233d7a94da38d7a0a2 ram=2e11373bf3392b80517572233d7a94da38d7a0a2 2026-10-03 prove_exe.boot1.log
- datapoint exe 80015DDC window SLUS_013.34:0x65DC+0x100 sha1=2d52315f4d90e4f2630584d80a926ef3e1eee83c ram=2d52315f4d90e4f2630584d80a926ef3e1eee83c 2026-10-03 prove_exe.boot2.log
- datapoint exe 8005894C window SLUS_013.34:0x4914C+0x100 sha1=d2b95d70aeff18e846c1ab9ae2f76f298a31accb ram=d2b95d70aeff18e846c1ab9ae2f76f298a31accb 2026-10-03 prove_exe.boot2.log
- datapoint exe 80067F98 window SLUS_013.34:0x58798+0x100 sha1=2e11373bf3392b80517572233d7a94da38d7a0a2 ram=2e11373bf3392b80517572233d7a94da38d7a0a2 2026-10-03 prove_exe.boot2.log
- datapoint ovl22 800EE970 before-after ROCK_X5.BIN:0xBC000+0x848 sha1=c1fa832119d33bcba108078f553e0de4d14eb6df ram=c1fa832119d33bcba108078f553e0de4d14eb6df 2026-10-03 prove_overlay.boot1.log
