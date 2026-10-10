# Memory map

Static map from `tools/loadmap/loadmap.py derive` (`docs/oracle/loadmap.json`). Every claim below is `static`
(decoded from SLUS_013.34 code/tables and the ROCK_X5.BIN TOC); T5 proves them live and appends `- datapoint` lines.

## Main executable (PS-X EXE header) `static`

- entry pc0 8005894C; gp0 00000000; stack s_addr 801FFFF0 `static`
- text 80010000..80092000 (size 0x82000; file offset 0x800) `static`
- data/bss in header: d_size 0, b_size 0 (none declared) `static`

## Overlay table `static`

- loader Ovl_ReadToc 80015DDC: BIN sector 0 TOC -> RAM table 800E6188, 59 rows of 8 bytes; row 59 all-zero `static`
- Ovl_Load 80015EB4(a0=index, a1=dest); dest from call sites 800136EC (base `*80010000`, initial 800EE970), 800136B4 and 80013568 (800FA000) `static`
- kind: `code` if the blob contains `jr ra` (03E00008), else `data`; `-` dest = index in no loader table `static`

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

## Boundaries `static`

- `docs/oracle/boundaries.txt` (`tools/ghidra/scripts/ExportBoundaries.java`, written by `tools/ghidra/import.sh`):
  `<start>-<end> | jumptable|libobj|libobj? | <owner> | <evidence>`, end exclusive, overlay starts `ovlNN:` `static`
- jumptable lines: 583 (exe 42, overlays 541); 452 owners `nofn@<jr>` (Ghidra made no function around the jr) `static`
- libobj lines: 181 (psx_ldr PsyQ 4.7.0 obj sigs, owner `<lib>/<obj>`); libobj? lines: 0 `static`
- unresolved computed jumps (jr non-ra, no recovered table): 8 `static`
- overlays loaded as Ghidra blocks: 53 (code, dest known); skipped: 38, 39 (dest=null) `static`
- 80014064 renamed Ovl_Load2 -> Cd_Unk_80014064 (calls CdReset/CdControlB/VSync; T5 saw a1=1F801110) `static`

## Overlays 38/39 (T2, 1.8.3)

- static: no 8006FD50/8006FD80/8006FC5C entry is 38 or 39; exe Ovl_Load call sites only 80013568/800136B4/800136EC. Loader is ovl18 (stage 12 sub 0, 8006FD50[24]): Ovl_Load(0x26, 800FA000) at 800F6B30, Ovl_Load(0x27, 800FA000) at 800F6C30, states 3/6 of an object state machine (dispatcher 800F5EA0, handler table 800F80D4) `static`
- ovl38: blocked: live load needs ovl18's state-machine object spawned (real stage-12 progress or an object spawn/state poke); static dest 800FA000 unproven live -- tools/redux/prove_ovl3839.lua runs t2c1_pad2 (pad taps, 20000 frames: idx 22,23,40,16,0 only), t2c1_stage1/poke4/hold4 (REDUX_STAGE=12: idx18 loads, no further Ovl_Load, bp 800F5EA0 never fires); phase-ends/current/logs/T2.c1.md
- ovl39: blocked: same as ovl38 (Ovl_Load(0x27) is state 6 of the same object, reached after state 3) -- same runs, no idx 39 hit
- binding (1.8.3 T2): `docs/oracle/loadmap.json` dest for 38/39 is filled only from a live datapoint, never from the static 800FA000 (filling it flips harness p6 and makes 38/39 code segments in the rockx5 yaml/census); test: `PY tools/loadmap/loadmap.py check`

## Datapoints

<!-- T5: `- datapoint <exe|ovl<n>> <addr> <how> <file range> sha1=… ram=… <date> <log>` -->
- datapoint exe 80015DDC window SLUS_013.34:0x65DC+0x100 sha1=2d52315f4d90e4f2630584d80a926ef3e1eee83c ram=2d52315f4d90e4f2630584d80a926ef3e1eee83c 2026-10-03 .run/redux/prove_exe.boot1.log
- datapoint exe 8005894C window SLUS_013.34:0x4914C+0x100 sha1=d2b95d70aeff18e846c1ab9ae2f76f298a31accb ram=d2b95d70aeff18e846c1ab9ae2f76f298a31accb 2026-10-03 .run/redux/prove_exe.boot1.log
- datapoint exe 80067F98 window SLUS_013.34:0x58798+0x100 sha1=2e11373bf3392b80517572233d7a94da38d7a0a2 ram=2e11373bf3392b80517572233d7a94da38d7a0a2 2026-10-03 .run/redux/prove_exe.boot1.log
- datapoint exe 80015DDC window SLUS_013.34:0x65DC+0x100 sha1=2d52315f4d90e4f2630584d80a926ef3e1eee83c ram=2d52315f4d90e4f2630584d80a926ef3e1eee83c 2026-10-03 .run/redux/prove_exe.boot2.log
- datapoint exe 8005894C window SLUS_013.34:0x4914C+0x100 sha1=d2b95d70aeff18e846c1ab9ae2f76f298a31accb ram=d2b95d70aeff18e846c1ab9ae2f76f298a31accb 2026-10-03 .run/redux/prove_exe.boot2.log
- datapoint exe 80067F98 window SLUS_013.34:0x58798+0x100 sha1=2e11373bf3392b80517572233d7a94da38d7a0a2 ram=2e11373bf3392b80517572233d7a94da38d7a0a2 2026-10-03 .run/redux/prove_exe.boot2.log
- datapoint ovl22 800EE970 before-after ROCK_X5.BIN:0xBC000+0x848 sha1=c1fa832119d33bcba108078f553e0de4d14eb6df ram=c1fa832119d33bcba108078f553e0de4d14eb6df 2026-10-03 .run/redux/prove_overlay.boot1.log
