# Backlog

This file lists the known defects and the planned work of the decompilation. The
[roadmap](ROADMAP.md) gives the phases that hold the planned work. The counts come from
[docs/progress.md](progress.md).

Order is priority. Each item ends when its check passes. Then the item leaves this file.

Phase 4.8 removed two items, because their checks pass. Phase 4.8 met B6: the readability scan finds no task ids,
banners or end markers in the C files. Phase 4.8 met B7: 100 of 7647 functions have a name with recorded evidence.

Phase 4.10 removed three items, because their checks pass. Phase 4.10 met B1: the link check finds no unresolved link,
and the fresh-clone check accepts no finding. Phase 4.10 met B3: the selftest step names 5 tools, and
the codegen stage script left the public tree. Phase 4.10 met B8: the operations docs tell the reader to set `PY`
before the contract script runs.

Each item has these fields:

- Kind: `defect` or `work`.
- Status: `open`, `planned` or `blocked on the developer`.
- Planned in: the phase that holds the item, or `not planned`.
- Problem: what is wrong or missing.
- Cause: why the problem exists.
- Approaches: the options, and the option that we chose or prefer.
- Done when: the check. It is a command and its output, or a fact that a person can see.

## P1: Defects in the public repository

### B2: The CONTRIBUTING statement on AI use is a placeholder

- Kind: defect
- Status: blocked on the developer
- Planned in: not planned
- Problem: Line 48 of [CONTRIBUTING.md](../CONTRIBUTING.md) holds a placeholder for the statement on AI use.
- Cause: The statement is a decision of the developer.
- Approaches: The developer writes the statement. No other approach applies.
- Done when: `CONTRIBUTING.md` holds the statement, and the placeholder line is gone.

## P4: Tools and modding

### B9: The shift scan does not count five accepted pointers

- Kind: defect
- Status: open
- Planned in: not planned
- Problem: `config/us/shift/not_pointers.txt` lists five raw exe pointers into overlay region A. The shift scan does not
  count them. Thus, the scan does not prove that they are correct in a shifted build.
- Cause: The developer accepted these five words. [docs/modding.md](modding.md) lists them in its shift-scan section.
- Approaches: The current approach keeps the five words on the list. The other approach gives each word a symbol, so
  that the scan counts it.
- Done when: `config/us/shift/not_pointers.txt` holds no raw exe pointer into overlay region A, and `make shift-scan`
  prints `shift-scan: 0 unsymbolized`.
