# decomp-architect install record

*Written by the kit's installer on 2026-10-03 against ProjectArchitect 3.14.2 (tested 3.14.2). The kit's pieces and their PA3 homes: the kit's `templates/pa3-contract.md`.*

## The game interview

- **GAME_TITLE:** Mega Man X5
- **PLATFORM:** Sony PlayStation (PS1)
- **GAME_SERIAL:** USA SLUS-01334
- **TARGET_BINARY:** SLUS_013.34
- **DUMP_PATH:** given (machine-local; not recorded)
- **CONTAINER_LAYOUT:** Main exe SLUS_013.34 (534528 bytes, text at 0x80010000, entry 0x8005894C) plus a code-overlay archive ROCK_X5.BIN (lead: 59 descriptors, 53 code, loaded at 0x800EE970 / 0x800FA000), the ROCK_X5.DAT data archive, STR/ FMV and XA/BGM.XA audio; one MODE2/2352 data track
- **SDK_EVIDENCE:** PsyQ 4.7: 11 Ps library stamps (libs 0,1,3,4,6,7,9,12,14,16,17) at 0x80067F98-0x80091B80; string "Library Programs (c) 1993-1997 Sony Computer Entertainment Inc."; ghidra_psx_ldr detection pending
- **COMPILER_FAMILY:** Candidate (S4 2026-10-03; superseded by the pinned toolchain triple once phase 1.4 pins it): PsyQ-era gcc via maspsx, candidate set in ladder order: gcc 2.95.2-psx + aspsx 2.86 (mmx6); gcc 2.7.2-psx -funsigned-char + aspsx 2.56 --expand-div (mmx4 US); gcc 2.8.1-psx (mmx4 EU, dw3); gcc 2.7.x -G8 (mml1). Not a pin
- **COMMUNITY_WORK:** No X5 decomp (decomp.dev 0 projects, 2026-10-03). sozud/mmx4 X4 decomp (AGPL-3.0, copyleft); mstan/MegaManX5Recomp static recomp of this disc (PolyForm Noncommercial 1.0.0, facts only); MMX5 Improvement Project addendum workbook (acediez, licence unstated, facts only); mstan/psxrecomp and X4/X6 recomps (facts only); ChrisNonyminus/mml1 (licence unstated, facts only); Almar's Guides NTSC-U codes (link)
- **PROJECT_GOALS:** Every code binary on the disc rebuilt byte-identical from readable, evidenced C, with the hash check inside the build, reproducible by anyone with their own dump from the README alone.
- **LICENSE_CHOICE:** AGPL-3.0 for the project's tools and docs; the decompiled source is offered under AGPL-3.0 as far as its authors' contribution goes, with no claim over Capcom's game or its assets
- **AI_DISCLOSURE:** AI-use statement to be added before this repository is made public.
- **PUBLIC_OR_PRIVATE:** private

## Deviations

- none

## Warnings

- none

## What was written

- created `.clang-format`
- changed `.claude/skills/project-architect/SKILL.md`
- changed `.gitignore`
- created `.run/README.md`
- changed `CLAUDE.md`
- created `CONTRIBUTING.md`
- changed `HOW_WE_WORK.md`
- created `Makefile`
- created `README.md`
- created `config/decomp-hooks.snippet.json`
- created `config/mcp.json.template`
- created `cookbook/C0001.md`
- created `cookbook/C0002.md`
- created `cookbook/C0003.md`
- created `cookbook/C0004.md`
- created `cookbook/C0005.md`
- created `cookbook/C0006.md`
- changed `cookbook/INDEX.md`
- created `docs/README.md`
- created `docs/decomp-architect-install.md`
- created `docs/decomp-architect.md`
- created `docs/decomp-kernels.md`
- created `docs/inherited-record.md`
- created `docs/knowledge-corpus.md`
- created `docs/ops/INDEX.md`
- created `docs/ops/decomp-environment.md`
- created `docs/ops/disassembler-mcp.md`
- created `docs/tools-manifest.md`
- created `docs/wave-playbook.md`
- created `rules/G1.md`
- created `rules/G10.md`
- created `rules/G11.md`
- created `rules/G12.md`
- created `rules/G13.md`
- created `rules/G14.md`
- created `rules/G15.md`
- created `rules/G16.md`
- created `rules/G17.md`
- created `rules/G18.md`
- created `rules/G19.md`
- created `rules/G2.md`
- created `rules/G20.md`
- created `rules/G21.md`
- created `rules/G22.md`
- created `rules/G23.md`
- created `rules/G24.md`
- created `rules/G25.md`
- created `rules/G26.md`
- created `rules/G27.md`
- created `rules/G28.md`
- created `rules/G29.md`
- created `rules/G3.md`
- created `rules/G30.md`
- created `rules/G31.md`
- created `rules/G32.md`
- created `rules/G33.md`
- created `rules/G34.md`
- created `rules/G35.md`
- created `rules/G36.md`
- created `rules/G37.md`
- created `rules/G38.md`
- created `rules/G39.md`
- created `rules/G4.md`
- created `rules/G40.md`
- created `rules/G41.md`
- created `rules/G42.md`
- created `rules/G43.md`
- created `rules/G44.md`
- created `rules/G45.md`
- created `rules/G46.md`
- created `rules/G47.md`
- created `rules/G48.md`
- created `rules/G49.md`
- created `rules/G5.md`
- created `rules/G50.md`
- created `rules/G51.md`
- created `rules/G52.md`
- created `rules/G53.md`
- created `rules/G54.md`
- created `rules/G55.md`
- created `rules/G56.md`
- created `rules/G57.md`
- created `rules/G58.md`
- created `rules/G59.md`
- created `rules/G6.md`
- created `rules/G60.md`
- created `rules/G61.md`
- created `rules/G62.md`
- created `rules/G63.md`
- created `rules/G64.md`
- created `rules/G65.md`
- created `rules/G66.md`
- created `rules/G67.md`
- created `rules/G7.md`
- created `rules/G8.md`
- created `rules/G9.md`
- changed `rules/INDEX.md`
- created `src/NOTICE.md`
- created `tools/bootstrap.sh`
- created `tools/docker/Dockerfile`
- routed `memory-seed/offline-tooling-first.md` → cookbook
- routed `memory-seed/a-slow-gate-is-a-bug.md` → cookbook
- routed `memory-seed/breadth-is-isolated-agents.md` → cookbook
- routed `memory-seed/route-by-measured-difficulty.md` → cookbook
- routed `memory-seed/mcp-reconnect-after-restart.md` → ops:docs/ops/disassembler-mcp.md
- routed `memory-seed/answer-before-grinding-in-live-coop.md` → rule:G2
- routed `memory-seed/tool-change-ships-with-its-consumers-and-docs.md` → rule:G33
- routed `memory-seed/checkpoint-means-everything-is-already-in-a-file.md` → rule:G59
- routed `memory-seed/keep-an-accelerator-ledger.md` → rule:G59
- routed `memory-seed/phaseend-carries-the-narrative-axis.md` → rule:G59
- routed `memory-seed/the-byte-gate-is-the-only-claim.md` → drop
- routed `memory-seed/the-matching-flywheel.md` → drop
- routed `memory-seed/one-runbook-is-the-procedure.md` → drop
- routed `memory-seed/consult-the-tool-dictionary-first.md` → drop
- routed `memory-seed/translate-the-source-idiom-through-the-pass.md` → drop
- routed `memory-seed/no-sleep-polling-background-tasks.md` → drop
- routed `memory-seed/long-checks-run-in-the-foreground.md` → drop
- routed `memory-seed/resume-means-resume-the-run.md` → drop

## Next

A bare `claude` in this repository: PA3's generation planner drafts `GENERATION_PLAN.md` from the ladder; the ladder's Phase-0 milestone (the CI workflow green on the first push) is verified by PA3's own gates.
