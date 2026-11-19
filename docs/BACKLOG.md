# Backlog

This file lists the known defects and the planned work of the decompilation. The
[roadmap](ROADMAP.md) gives the phases that hold the planned work. The counts come from
[docs/progress.md](progress.md).

Order is priority. Each item ends when its check passes.

Each item has these fields:

- Kind: `defect` or `work`.
- Status: `open`, `planned` or `blocked on the developer`.
- Planned in: the phase that holds the item, or `not planned`.
- Problem: what is wrong or missing.
- Cause: why the problem exists.
- Approaches: the options, and the option that we chose or prefer.
- Done when: the check. It is a command and its output, or a fact that a person can see.

## P1: Defects in the public repository

### B1: The README progress block cites a file that the repository does not ship

- Kind: defect
- Status: planned
- Planned in: phase 4.9, Validation: the clean repository, or earlier
- Problem: The progress block of `README.md` cites a file in the rules folder. The public repository does not ship
  that folder. Thus the link check finds one unresolved link at `README.md:107`.
- Cause: The psxdecomp tool writes the text of the progress block. Its progress note names the file. The same tool keeps
  the rules folder out of the public tree.
- Approaches: The preferred approach is a psxdecomp release whose progress note names no file in the rules folder. The other
  approach is to edit the generated block by hand. We do not use it, because the next render replaces the block.
- Done when: The README cites no file in the rules folder. The link check prints no unresolved link, and the fresh-clone check
  no longer accepts the `README.md:107` link.

### B2: The CONTRIBUTING statement on AI use is a placeholder

- Kind: defect
- Status: blocked on the developer
- Planned in: not planned
- Problem: Line 48 of [CONTRIBUTING.md](../CONTRIBUTING.md) holds a placeholder for the statement on AI use.
- Cause: The statement is a decision of the developer.
- Approaches: The developer writes the statement. No other approach applies.
- Done when: `CONTRIBUTING.md` holds the statement, and the placeholder line is gone.

### B3: The no-rom CI workflow has a stale step name and an extra public tool

- Kind: defect
- Status: blocked on the developer
- Planned in: not planned
- Problem: In `.github/workflows/no-rom.yml`, the name of step 7 of the compile-only job lists 4 tools. The step runs
  5 selftests. Also, `tools/codegen/stage.sh` is in the public tree only because `tools/docker/no_rom.sh:32` runs it.
- Cause: The project governs the workflow and the tools. Only the developer changes these paths.
- Approaches: The developer renames the step to list the 5 tools. Then the developer removes the `stage.sh` line from
  `tools/docker/no_rom.sh`. After that change, `tools/codegen/stage.sh` can leave the public tree.
- Done when: The name of the selftest step lists 5 tools. `tools/docker/no_rom.sh` does not run
  `tools/codegen/stage.sh`, and `config/public-paths.txt` does not list it.

## P2: The compile units

### B4: Each function is in its own file

- Kind: work
- Status: planned
- Planned in: phase 4.3, The unit map and the merge dry run, then phases 4.4, 4.5 and 4.6
- Problem: Today each function is one compile unit in its own file. The original game had compile units with many
  functions.
- Cause: The decompilation matched each function in its own file.
- Approaches: The chosen approach has four steps. Phase 4.3 maps each C function to one proposed unit, and a dry run
  compiles each unit. Phase 4.4 gives each symbol one declaration in a header. Phases 4.5 and 4.6 merge the files.
  The other approach keeps one function in each file. We do not prefer it, because the original units are the goal.
- Done when: Every C function is in exactly one compile unit of the 4.3 map, merged or held with its cause. No file
  declares a symbol that a header declares. A clean rebuild of both binaries is byte-identical.

### B5: 164 functions are not matched as C

- Kind: work
- Status: planned
- Planned in: phase 4.7, The ledger after the merge
- Problem: 164 of 7647 functions are still in assembly. 119 are in `ROCK_X5.BIN` and 45 are in `SLUS_013.34`.
- Cause: Each of these functions has a row in the ledger of open functions, with its blocker. The cause of some
  blockers may be the scope of the unit, for example shared data or a static in the file.
- Approaches: The chosen approach attacks each row with a unit-scope cause once, inside its merged unit. A row that
  stays open becomes an assembly line inside its unit, or one assembly subsegment.
- Done when: `python3 tools/wave/ledger.py check` prints `0 unledgered, 0 without draft, 0 without blocker`. The open
  count in [docs/progress.md](progress.md) is at or below the figure of the 4.7 plan.

## P3: Readability

### B6: The C files carry narration, task ids and banners

- Kind: work
- Status: planned
- Planned in: phase 4.8, Names, types and data. Phase 4.5 removes the banners with the merge.
- Problem: The matched C carries comments that tell how the work went, task ids and pipeline banners. 5,545 files
  start with a banner.
- Cause: The matching pipeline wrote the banners. The comments record the work, not the code.
- Approaches: The chosen approach is one pass over `src/`, `include/`, `tools/` and `mk/`. It keeps only the comments
  that tell why. The readability scan gets two new classes, `taskid` and `banner`, with planted fixtures.
- Done when: Both binaries stay byte-identical. `make readability-check PY=...` prints `readability: 0 unmarked pins, 0 macro bodies, 0 raw casts,
  0 duplicate shapes, 0 stray structs, 0 unbased names, 0 task ids, 0 banners`.

### B7: Few functions have names

- Kind: work
- Status: planned
- Planned in: phase 4.8, Names, types and data
- Problem: 37 of 7647 functions have a name. The other functions have an address name.
- Cause: A name needs recorded evidence. We do not guess names.
- Approaches: The chosen approach is a names queue, an object map and global types, adapted from the Mega Man X6
  decompilation. Each name climbs the evidence ladder. A pilot sets the figures for the phase.
- Done when: The named count in [docs/progress.md](progress.md) reaches the figure of the 4.8 plan. Each new name has
  recorded evidence.

## P4: Tools and modding

### B8: The contract script uses the host python3 when PY is not set

- Kind: defect
- Status: planned
- Planned in: phase 4.3, The unit map and the merge dry run
- Problem: If `PY` is not set, the contract script uses `python3`. If that `python3` does not have `toml`, the
  permuter selftest fails.
- Cause: The script sets `PY` to `python3` by default. The permuter selftest needs `pycparser` and `toml`.
- Approaches: The chosen approach is one line in the operations docs: set `PY` before you run the script. The other
  approach changes the default of the script.
- Done when: The operations docs tell the reader to set `PY` before the contract script runs.

### B9: The shift scan does not count five accepted pointers

- Kind: defect
- Status: open
- Planned in: not planned
- Problem: `config/shift/not_pointers.txt` lists five raw exe pointers into overlay region A. The shift scan does not
  count them. Thus, the scan does not prove that they are correct in a shifted build.
- Cause: The developer accepted these five words. [docs/modding.md](modding.md) lists them in its shift-scan section.
- Approaches: The current approach keeps the five words on the list. The other approach gives each word a symbol, so
  that the scan counts it.
- Done when: `config/shift/not_pointers.txt` holds no raw exe pointer into overlay region A, and `make shift-scan`
  prints `shift-scan: 0 unsymbolized`.
