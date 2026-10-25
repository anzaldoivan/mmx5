# tools/replay — deterministic pad-script replay in PCSX-Redux 298 (T1 phase 2.2)

`replay.lua` (Redux side, `-interpreter`, C0104) + `replay.py` (driver, stdlib). Outputs only under `.run/` (G12).

## .pad format
Line-based. `#` starts a comment. Blank lines are ignored. `<frame> <op> [arg]`, frame = n-th `GPU::Vsync` (1-based).
- `<n> press <BUTTON>` / `<n> release <BUTTON>`: pad 1 override set/clear. BUTTON = a key of `PCSX.CONSTS.PAD.BUTTON` (START, CROSS, …).
- `<n> cp <name>`: checkpoint (report line + `<REDUX_OUT>/<name>.png` when the screenshot is 15-bit).
- `<n> end`: `redux: end frame=<n>`, quit 0. Lines of one frame run in file order. A bad line → `redux: bad pad line`, exit 2.
Example: `scripts/boot.pad` (boot 360, title 5000, menu 5120, player_select 5480, end 5500).

## Scripts
`scripts/intro.pad` (T2 phase 2.2): power-on → intro stage → Sigma-head boss → stage select, pad only, end 34420
(~12 min per run under `-interpreter`). Checkpoints (frame, stage/sub, scene):
- `boot` 360, 0/0: power-on screen. `title` 5000, 14/0: title. `menu` 5120, 14/0: title menu. `player_select` 5480, 14/1: X/Zero select.
- `stage_start` 11010, 0/0: X standing at the intro stage start. `mid_stage` 13000, 0/0: X mid intro stage.
- `clear` 29850, 15/0: MISSION REPORT / MISSION COMPLETE. `stage_select` 34400, 13/0: 8-boss stage select grid.

Authoring: probe-and-extend. Each segment was probed from a savestate of the previous one (scratch `.run/replay/`,
never tracked). Inputs were kept when the probe's checkpoint showed the wanted scene. Then the segments were concatenated into
one pad and replayed straight from power-on. cp frames sit on stable 15-bit frames. X dies once at the boss by design.

## Listener leak fix (R2.2-001, T3.1)
Redux 298 leaves 2 tables per dispatch on the listener's own coroutine thread. One listener overflowed the Lua stack at
vsync 32736 (T2 runs). That vsync's body was lost, so T2's frames after it are one vsync late vs now.

replay.lua recreates the listener every 16384 vsyncs (fresh thread). The new one removes the old from its own callback. A listener
created in a callback fires in the same dispatch, so the body is guarded by `PCSX.getCPUCycles()` (one body per vsync).
Proof: boot.pad with recycle every 100 = T1 cps. intro.pad runs past 32736 with no `stack overflow` in `redux.log`.

## Plant and check
`REDUX_PLANT=<hexaddr>:<hexword>@<frame>` (replay.py `run --plant`): at that vsync replay.lua writes the word (LE) at
addr, invalidates the CPU cache, prints `redux: plant addr=.. word=.. frame=..`. `plants.txt`: `<spec> <declared cp>`
(main-exe code only, authored word, why in its comments).

`make replay-check` = `replay.py check` (~65 min, builds
`build/disc/mmx5.cue` if missing). It runs intro.pad original x3 (`.run/replay/original/run{1,2,3}`), rebuilt x1
(`rebuilt/run1`) and plant x1 (`plant/run1`). The plant run's rc is ignored: the plant halts the CPU and the run ends by timeout. It prints
`replay: original 3 of 3 identical, <k> checkpoints`, `replay: rebuilt 0 divergences`, `replay: plant caught at <cp>`
(first divergence vs original/run1 = declared cp). Any red → exit 1.

`make replay-shift` (~15 min, needs `make disc SHIFT=1`): intro.pad once on `build/shift/disc/mmx5.cue` →
`.run/replay/shifted/run1`, compare vs `original/run1` (run once if absent). It prints `replay: shifted <d> divergences`
(+ `replay: shifted first divergence <cp>`). Exit 1 on any divergence.

`make replay-asset ASSET_EDIT=<n>` (~36 min, needs `make disc ASSET_EDIT=<n>`): replay-patch twin, intro.pad x3 on
`build/asset-<n>/disc/mmx5.cue` → `.run/replay/asset-<n>/run{1,2,3}`, `compare --from <cp> --label replay-asset` with cp
from the first non-# line of `asset-edits/<n>/checkpoint`. It prints `replay-asset: <n> OK (first divergence <cp> >= declared
<cp>, 3 of 3 deterministic, control caught)`. `compare --label` (default `replay-patch`) only renames the OK line's prefix.
B's dir name loses `patch-` / `asset-`.

## Env (replay.lua)
`REDUX_PAD`: .pad path (absolute: run.sh cwd is `.run/redux`). `REDUX_OUT`: PNG dir (default cwd). `REDUX_PLANT`: above. replay.py sets both,
plus `REDUX_TIMEOUT` = end_frame/30 + 60 s and `REDUX_CUE` from `--cue` (default: run.sh's retail cue).

## Report lines
- Redux: `redux: cp <name> frame=<n> stage/sub=<s>/<u> vram_sha1=<h>` (h = sha1 of `PCSX.GPU.takeScreenShot()` pixels, as
  title.lua, stage/sub = RAM 800D1C0C/0D), `redux: end frame=<n>`.
- `replay.py run --pad P --runs N --out DIR [--cue C]`: serial runs (never two Redux at once, C0091). `DIR/run<i>/`
  holds `stdout.txt`, `redux.log` (copy of `.run/redux/replay.log`), `checkpoints.jsonl` (regex search for `redux: cp`) and PNGs. It prints `replay: run<i> rc=<rc> <k> checkpoints end=yes|no`.
  Exit 1 if any run failed or missed `end`.
- `replay.py compare A B`: `replay: <k> checkpoints, <d> divergences` (+ `replay: first divergence <name>`, exit 1). A
  checkpoint diverges when missing on one side or any of frame/stage/sub/vram_sha1 differs. `--selftest`: synthetic records.

## Memcards
Pinned by Redux CLI flags `-memcard1 <path> -memcard2 <path>`, both = `.run/replay/cards/card1.mcd`. replay.py deletes
`.run/replay/cards/` before each run, and Redux creates a fresh formatted card. Redux 298 quirk: `-memcard2` sets `Mcd2` from
the `-memcard1` value (probe: `PCSX.settings.emulator.Mcd2` = card1 path), so both slots share the one card. Pass both
flags (other combinations untested). Verified: `~/.config/pcsx-redux/memcard{1,2}.mcd`
mtimes unchanged across 3 boot.pad runs. No `pcsx.json` is written under `-no-ui`, so the flags do not persist.

## Savestates (datapoint, Redux 298)
Yes. Lua: `PCSX.createSaveState()` → Slice (in memory). `PCSX.loadSaveState(slice_or_file)`. To disk:
`Support.File.open(path, 'TRUNCATE'):writeMoveSlice(PCSX.createSaveState())`, load with `PCSX.loadSaveState(Support.File.open(path))`.

Raw protobuf ("PCSX-Redux SaveState v4"), ~21 MB, uncompressed. Redux's UI slots use `.sstate` (ignored + firewall glob:
holds emulated RAM).

Probe (scratch `.run/replay/ss_probe.lua`): save at frame 4900, straight run to 5000 → title
`vram_sha1=f44fc02b…`. Load from slice, 100 more vsyncs → same hash. Load from file → same hash. Loading inside the
`GPU::Vsync` listener works. Caveat: one checkpoint, on the title's 2-state blink loop (frame 4900 hashes differently).
