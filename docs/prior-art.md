# Prior art — leads, their status, and their credit

*Drafted by psxdecomp S3 on 2026-10-03; confirmed at the S4 gate on 2026-10-03. The shape is mmx6's `docs/prior-art.md` (2026-10-01).*

Every fact this project takes from outside its own bytes is a row here, with its source, licence and status.
Status ladder: `lead` → `consistent-with-bytes` (checked against our dump or an oracle; cite the check) →
`proven-at-gate` (a green byte gate, or a runtime proof). Nothing below `proven-at-gate` is banked on, recorded as
fact, or used as a name. `rejected` keeps a lead the developer turned down, with the reason.

## Sources

| Source | Licence | Class | Use allowed |
|---|---|---|---|
| [sozud/mmx4](https://github.com/sozud/mmx4) — WIP matching decomp of Mega Man X4 (PS1), same Capcom engine line | AGPL-3.0 | copyleft | adaptable into this AGPL-3.0 repo, with attribution in THIRD_PARTY.md |
| [mstan/MegaManX5Recomp](https://github.com/mstan/MegaManX5Recomp) — psxrecomp static recomp of this exact disc | PolyForm Noncommercial 1.0.0 | facts | facts only (hashes, layout), never copied |
| [mstan/psxrecomp](https://github.com/mstan/psxrecomp), [MegaManX4Recomp](https://github.com/mstan/MegaManX4Recomp), [MegaManX6Recomp](https://github.com/mstan/MegaManX6Recomp) — recomp framework and sibling recomps | PolyForm NC (framework, per ports scout); X4/X6 unstated | facts | facts only |
| [ChrisNonyminus/mml1](https://github.com/ChrisNonyminus/mml1) — WIP Mega Man Legends decomp | unstated | facts | facts only |
| [Almar's Guides X5 codes](https://almarsguides.com/retro/walkthroughs/ps1/games/megamanx5/codebreaker/) — NTSC-U CodeBreaker/AR sets | unstated | link | RAM-map leads, re-measured before use |
| [MMX5 Improvement Project addendum](https://archive.org/details/mmx5_improvement_project_addendum) (acediez, v2.1.4; workbook 2022.07.19) — 114-sheet RAM/asm/disc workbook for the clean retail disc; hack at [romhacking.net 6131](https://www.romhacking.net/hacks/6131/) | unstated | facts | facts only, never copied |
| mmx6 (psxdecomp profile row, `docs/ops/compiler-pin.md`) — Mega Man X6 decomp | per profile | facts | toolchain lead only |

Classes: `adapt` · `copyleft` (adapt only into a licence-compatible repo) · `facts` · `public` · `byo` · `link`
(`docs/ops/refs.md` after S9).

## Leads

| # | Lead | Source | Status | Evidence / how to verify | Phase |
|---|---|---|---|---|---|
| L1 | Dump = Redump #7437, the only USA revision Redump lists; 1 track MODE2/2352, track SHA-1 `10709231f857…` | MegaManX5Recomp@c8fde08 `DISC.md`, `aot/overlays.json` | consistent-with-bytes | Our S2 track SHA-1 equals the hash that repo records for Redump #7437. redump.org itself was unreachable on 2026-10-03, so re-check it against the Redump PS1 DAT (`identify --dat`) | 1.1 |
| L2 | SDK: PsyQ 4.7 — 11 `Ps` stamps (libs 0,1,3,4,6,7,9,12,14,16,17), 0x80067F98–0x80091B80 | own bytes (S2) | consistent-with-bytes | `medium.json psyq`; ghidra_psx_ldr's detection at import is the final word | 1.2 |
| L3 | Compiler rung 1: gcc 2.95.2-psx `-O2 -G0` + aspsx 2.86 via maspsx (mmx6's pin, same 4.7 libs, nearest in era) | profile `psyq.toml` seen_in mmx6 | lead | Verify: run it first in the 1.4 ladder on small leaf functions of SLUS_013.34; a probe matches or refutes it. The 4.7 stamps date the libraries, not the game's cc1 (profile trap) | 1.4 |
| L4 | Compiler rung 2: gcc 2.7.2-psx (old-gcc 0.9) `-O2 -G0 -g0 -msoft-float -funsigned-char` + maspsx `--aspsx-version=2.56 --expand-div` (mmx4 US/JP) | sozud/mmx4@7569876 `build.py`, `compiler.sh` | lead | The repo scout read the commands the build runs. Web summaries said gcc 2.8.1, which is wrong for US (see trap). Verify: run it in the ladder, comparing functions shared with X4 | 1.4 |
| L5 | Compiler rung 3: gcc 2.8.1-psx (old-gcc 0.15), same flags (mmx4 EU); also dw3's 2.8.1 row | sozud/mmx4@7569876; profile | lead | Verify: run it in the ladder | 1.4 |
| L6 | Compiler rung 4: gcc 2.7.x `-O2 -G8`, maspsx `--no-macro-inc --expand-div` (Mega Man Legends) | ChrisNonyminus/mml1 (build not cloned) | lead | Lowest priority. `-G8` versus `-G0`: check SLUS_013.34 for `$gp`-relative loads (gp0 in the header = 0) | 1.4 |
| L7 | ROCK_X5.BIN holds 59 overlay descriptors, 53 of them code; load destinations 0x800EE970 (indices 0–29) and 0x800FA000 (30–37, 40–58); 13/15/17/19 are data; 38–39 have no known destination; ROCK_X5.DAT holds no code | MegaManX5Recomp@c8fde08 `docs/AOT_OVERLAYS.md`, `aot/overlays.json` | lead | Verify: find the descriptor table in SLUS_013.34 or ROCK_X5.BIN and re-derive count and destinations from our bytes before writing the splat overlay configs; cross-check against L13's `TOC_ROCK_X5.BIN` | 1.3 |
| L8 | The X5 engine is shared with X4 (Capcom 2D engine); X6 not judged (no mmx6 checkout on this host, D1; reopen when the developer points to one) | MegaManX5Recomp README; sozud/mmx4@7569876 `src/main` (AGPL-3.0, LICENSE read 2026-10-05) | consistent-with-bytes (X4) | 2026-10-05, phase-1.6 T2: 591 of 591 mmx4 matched leaves (≤ 32 insns, no jal) compiled and signed, 0 not compiled. Exact signature hits in the X5 fleet: 246 under X5's pin (gcc 2.95.2-psx), 164 under mmx4's triple (gcc 2.7.2-psx, aspsx 2.56 --expand-div); 94 of each are 2-insn bodies, so non-trivial (≥ 8 insns) hits are 76 and 18; near-only 40 / 25. Hand-checked: mmx4 `player_leap_check_wall` (31 insns) = slus func_8003A008. Tool `tools/sig/sig.py foreign`; hits in `.run/sig/mmx4/<triple>/hits.jsonl` | 1.6 |
| L9 | RAM map: player struct near 0x8009A0FC (HP), buster 0x8009A13C, ammo 0x8009A14C–58; lives 0x800D1C45; weapon flags 0x800D4F56–67 | Almar's Guides (NTSC-U codes) | lead | Verify: in an emulator, watch HP at 0x8009A0FC while taking damage; then grep the disassembly for references before naming any global | 2.x |
| L10 | Target release: USA SLUS-01334, the only USA revision; others are JP SLPM-86666, JP Best SLPM-87021, EU SLES-03557; no prototype found | psxdatacenter; Redump via L1 | lead | TCRF served an AI-agent placeholder; a person should read https://tcrf.net/Mega_Man_X5 | 0 |
| L11 | old-gcc's releases page lists no gcc 2.95.x build (latest v0.17, 2026-05-13) | scout-web sdk.md | lead | Conflicts with the profile, which treats old-gcc as the 2.95.2-psx source. Verify: read old-gcc's `*.Dockerfile` list at its pin when S9 fetches it; if absent, build 2.95.2-psx from source with old-gcc's patches, as mmx6 did | 1.4 |
| L13 | MMX5 Improvement Project addendum documents the retail disc: its patch expects Redump #7437 (MD5 98C0D278…); sheets `TOC_ROCK_X5.BIN` / `TOC_ROCK_X5.DAT` / `TOC_DISC` (layout), `BIN-to-RAM` / `DAT-to-RAM` (annotated disassembly), `TBL_Entity` / `TBL_Attack` / `DmgTables` (data); the BIN TOC is written into RAM by the routine at 0x80015DDC | archive.org mmx5_improvement_project_addendum, workbook sha1 179ebbbc… (read 2026-10-03) | lead | Its exe offsets fit our header (exe 0x65DC → RAM 0x80015DDC under text 0x80010000 / header 0x800), arithmetic only. Verify: re-derive about 10 of its EXE/BIN addresses against our clean SLUS_013.34 bytes; start phase 1.3 at 0x80015DDC; skip the hack-only sheets (`TOC_PS-EXE` custom-code, `*_Mod`, `OtherHacks_*`) | 1.3 |
| L12 | No existing decomp of Mega Man X5: decomp.dev shows 0 projects (2026-10-03); GitHub and Discord searches found none | decomp.dev lookup; scout-web existing.md | consistent-with-bytes | Dated negative; re-check decomp.dev before going public | 0 |

## Upstream revisions read

`sozud/mmx4` `7569876` (2026-10-03) · `mstan/MegaManX5Recomp` `c8fde08` (2026-10-03) · archive.org `mmx5_improvement_project_addendum` workbook 2022.07.19, sha1 `179ebbbc` (2026-10-03)
