# Modding the build

This file describes the build toggles that make modified variants of the game. Each section names what the toggle
builds, where the output goes, the command and the string that the command prints on success. Write `PY=...` as the
path to your Python interpreter, the same way the top-level `README.md` does.

## BINARY=

`BINARY=<a>` builds one binary. `BINARY=slus` builds the main executable into `build/slus/SLUS_013.34`. The build
checks its hash with `sha1sum -c config/check.slus.sha`.

```sh
make split build BINARY=slus PY=...
```

On success, the build prints `build/slus/SLUS_013.34: OK`. After `slus`, `BINARY=rockx5` builds
`build/rockx5/ROCK_X5.BIN` and prints `build/rockx5/ROCK_X5.BIN: OK`. `make check` builds both binaries and prints
`check: 2 of 2 green, 0 failed`. `BINARY=` combines with `SHIFT=1` and `PATCHES=`. Then the build skips the hash check.

## SHIFT=1

`SHIFT=1` builds a shifted variant. Every code and data address moves. The disc goes into
`build/shift/disc/mmx5.cue`. The build has no hash gate.

```sh
make disc SHIFT=1 PY=...
make replay-shift PY=...
```

The replay plays the intro script on the shifted disc. On success, it prints `replay: shifted 0 divergences`.

## PATCHES=

`PATCHES=<name>` builds a patched variant from `patches/<name>/`. It works with `SHIFT=1` only. Without `SHIFT=1`, the
build stops with an error. The rules are in `mk/patches.mk`. The disc goes into `build/shift-<name>/disc/mmx5.cue`.

```sh
make disc SHIFT=1 PATCHES=halfdmg PY=...
make replay-patch PATCHES=halfdmg PY=...
```

On success, the replay prints
`replay-patch: halfdmg OK (first divergence clear >= declared mid_stage, 3 of 3 deterministic, control caught)`.

## ASSET_EDIT=

`ASSET_EDIT=<name>` builds a disc with an edited data asset from `asset-edits/<name>/`. The disc goes into
`build/asset-<name>/disc/mmx5.cue`. The build has no hash gate.

```sh
make disc ASSET_EDIT=m092fill PY=...
make replay-asset ASSET_EDIT=m092fill PY=...
```

On success, the replay prints
`replay-asset: m092fill OK (first divergence mid_stage >= declared mid_stage, 3 of 3 deterministic, control caught)`.

## disc-assets

`make disc-assets` exports and imports `ROCK_X5.DAT` again, then rebuilds the image into `build/assets/disc/mmx5.cue`.

```sh
make disc-assets PY=...
make disc-assets SHIFT=1 PY=...
make disc-assets SHIFT=1 PATCHES=halfdmg PY=...
```

On success, the unshifted build prints `disc-assets: re-imported image sha1 matches config/medium.sha1`. With
`SHIFT=1`, the image goes into `build/shift/disc`. With `PATCHES=<name>` too, it goes into `build/shift-<name>/disc`.
The shifted build prints `disc-assets: re-imported DAT packed into build/shift/disc (shifted, no gate)`. A patched
build names its own `build/shift-<name>/disc` path in that string.

## replay-check

`make replay-check` plays the intro script on the original image, on the rebuilt image and on a planted change. First,
build the disc. On success, `make disc` prints `disc: track sha1 10709231f857636b5ccd3cd9acebc91458dcb5fd OK`.

```sh
make disc PY=...
make replay-check PY=...
```

On success, the replay prints `replay: original 3 of 3 identical, 8 checkpoints`, `replay: rebuilt 0 divergences` and
`replay: plant caught at stage_start`. It takes about an hour.

## contract.sh

`tools/contract.sh` runs the whole contract. It runs the oracles, the shifted build, each `patches/[!_]*/` set and each
`asset-edits/*/` edit. It needs clean `src/` and `config/` trees. It takes about 95 minutes.

```sh
bash tools/contract.sh
bash tools/contract.sh --check-record
```

On success, the first command prints `contract: 1 of 1, oracles 5 of 5 green, modding 3 of 3 declared`. The second
command prints `contract: record OK`.

## How the toggles combine

`SHIFT=1` and `PATCHES=<name>` combine. A patch set always needs the shifted build. If you set `PATCHES=` without
`SHIFT=1`, the build stops with an error. `make replay-patch` is the exception, because it only reads the disc cue.

`make disc-assets` combines with `SHIFT=1` and also with `SHIFT=1 PATCHES=<name>`. `ASSET_EDIT=` needs an unshifted
build. If you set `ASSET_EDIT=` with `SHIFT=1`, the build stops before it starts and prints
`ASSET_EDIT needs an unshifted build (SHIFT unset)`.

## How to add a patch set

1. Make the directory `patches/<name>/`.
2. Copy each source file that you change to `patches/<name>/<alias>/<file>.c`.
3. Make sure that each patch file has a twin `src/<alias>/<file>.c`.
4. Write the declared checkpoint as the first line of `patches/<name>/checkpoint` that does not start with `#`.
5. Run `make replay-patch PATCHES=<name> PY=...` after the shifted disc build.

A patch file without a twin is an error. The declared checkpoint must be one of the replay checkpoints. The replay
passes when it finds at least one divergence and no divergence before the declared checkpoint. The 3 runs must be
identical, and the replay must catch its control.

A name that starts with `_` is a test fixture, and the contract skips
it (`patches/_plant`). `patches/halfdmg` is an example.

## How to add an asset edit

1. Make the directory `asset-edits/<name>/`.
2. Write `edit.json` with the entry as `"<idx>/<sub>"` and the operation.
3. Write the declared checkpoint into `checkpoint`.
4. Write a `README.md` that describes the edit.
5. Run `make replay-asset ASSET_EDIT=<name> PY=...` after the disc build.

An asset edit changes only container entries of `ROCK_X5.DAT`. `asset-edits/m092fill` is an example. The operations
are in `tools/assets/README.md`.
