# tools/progress

`progress.py` publishes the progress numbers (G58: every published number is generated and stamped).

- `PY tools/progress/progress.py write` — reads `.run/census/report.txt` (the `census: stubs …` line: fleet numbers) and
  `.run/census/inventory.jsonl` (per-binary game c/total); rewrites the README.md block between
  `<!-- progress:begin -->`/`<!-- progress:end -->` and `docs/progress.json` (shields.io endpoint). The block's stamp
  holds `git rev-parse HEAD:src`, `HEAD:config`, the UTC date and the command.
- `PY tools/progress/progress.py check` — `progress: OK`, or exit 1 with the reason: stamp trees ≠ current trees,
  json ≠ README numbers, or (census outputs present) regeneration differs ignoring the date. Game-free; in `make no-rom`
  (`progress-check`), the `progress` tools-health rung and CI.
- `--selftest` — `progress: control OK` (fresh fixture passes, stale stamp fails).

After `make check` or any src/ or config/ commit: run `write`, commit README.md and docs/progress.json.
