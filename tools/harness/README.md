# tools/harness

`harness.py` — question pairs: each question answered by two independent paths; a differing answer fails.

    PY tools/harness/harness.py [--sample|--full] [--selftest]

Run on a post-`make check` tree, after `make compile-only` and `tools/census/{inventory,boundaries,census report}`.

- p1 fleet green: `build/<a>.check.rc` vs hashlib sha1 of the built binary against `config/check.<a>.sha`.
- p2 function set: `.run/census/inventory.jsonl` (alias, name, vram) vs linker-map `.text` symbols
  (`fingerprint.read_map`); dropped on the map side: `= .` linker symbols, objects under `asm/<a>/data/`
  (non-code subsegments), names an asm file declares `dlabel`/`alabel` (the map cannot type a symbol).
- p3 extents: inventory (vram, insns) vs `boundaries.py` partition of the linked bytes (its `run`/`analyze`, `compare`
  spied for the parts); both ends trimmed of trailing zero words; strict equality (stricter than boundaries'
  `confirmed`, which tolerates an inventory extent running past the bytes end with no start inside).
- p4 matched set: yaml `c` subsegments vs `src/<a>/*.c` and `build/<a>/src/**/*.o`.
- p5 compiles: `.run/compile-only/src/**/*.o` vs `build/<a>/src/**/*.o` per `src/**/*.c`, `.text` of the function
  named by the stem (`probe.read_func` + `masked`).
- p6 load addresses: `docs/oracle/loadmap.json` code overlays (bin_offset -> dest) vs `config/splat.rockx5.yaml`
  `type: code` segments (start -> vram); null-dest code overlays excluded.
- p7 census denominator: `.run/census/report.txt` `[fleet]` lane sums (all/game/vendor) vs inventory rows counted here.
- p8 dedup registry: `config/dedup.us.yaml` members (alias, name) vs yaml `c` cuts whose `src/<a>/<name>.c` includes `../shared/`.

Modes: `--sample` (default) = p1 p2 p4 p5 p6 p7 p8 on on-disk inputs; `--full` re-runs `inventory.py` and
`census.py report`, then all eight (p3 re-derives boundaries in-process, ~10 s).

Output: `pair <id>: agree|DISAGREE <a> <n> vs <b> <n>[: first 3 diffs (+k)]` or `pair <id>: not judged <why>`
(missing input; counts as a disagreement); last line `harness: <k> pairs, <d> disagreements`; copied to
`.run/harness/last.txt`. Exit 0 green, 1 any DISAGREE/not judged, 2 refused input (bad arguments).

`--selftest`: per pair a synthetic clean tree (must agree), a planted disagreement (must DISAGREE), a missing input
(must be not judged); trees built from our own words under `.run/harness/selftest/`; p3 uses boundaries' own
synthetic module (`boundaries.build`). No game bytes (G12); no spimdisasm import.
