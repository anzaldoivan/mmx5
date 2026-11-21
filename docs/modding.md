# Modding the build

This file describes the build toggles that make modified variants of the game. Each section names what the toggle
builds, where the output goes, the command and the string that the command prints on success. Write `PY=...` as the
path to your Python interpreter, the same way [building.md](building.md) does.

If you change this file, run this command. It checks that each toggle has a verifying command.

```sh
bash tools/modding_check.sh
```

## BINARY=

`BINARY=<a>` builds one binary. `BINARY=slus` builds the main executable into `build/slus/SLUS_013.34`. The build
checks its hash with `sha1sum -c config/check.slus.sha`.

```sh
make split build BINARY=slus PY=...
```

On success, the build prints `build/slus/SLUS_013.34: OK`. After `slus`, `BINARY=rockx5` builds
`build/rockx5/ROCK_X5.BIN` and prints `build/rockx5/ROCK_X5.BIN: OK`. `make check` builds both binaries and prints
`check: 2 of 2 green, 0 failed`. `BINARY=` combines with `SHIFT=1` and `PATCHES=`. Then the build skips the hash check.

## SHIFT=1 and replay-shift

`SHIFT=1` builds a shifted variant. Every code and data address moves. The disc goes into
`build/shift/disc/mmx5.cue`. The build has no hash gate.

```sh
make disc SHIFT=1 PY=...
make replay-shift PY=...
```

The build regenerates `ROCK_X5.BIN` and its table of contents from the shifted link. The replay plays the intro script
on the shifted disc. On success, it prints `replay: shifted 0 divergences`. The detail is in
[tools/shift/README.md](../tools/shift/README.md). The replay is in [tools/replay/README.md](../tools/replay/README.md).

The region B base 0x800FA000 is pinned. Five code sites hold it as a constant: slus 8001369C, 80014310 and
80013528, and rockx5 ovl18 800F6B24 and 800F6C1C. If a mod moves the end of the exe bss, do not move region B.
The list of sites is in [memory-map.md](memory-map.md).

## SHIFT_PAD= and SHIFT_OVL_PAD=

These two values set the pads of the shifted build. They apply only with `SHIFT=1`.

- `SHIFT_PAD` is the pad of the main executable. Its default is 0. The build reorders the executable, so every code and
  data address of the executable moves at pad 0. Any value larger than 0 fails a link ASSERT, because the executable
  has no free trailing fill.
- `SHIFT_OVL_PAD` is the pad before the RODATA, TEXT and DATA of each code overlay in `ROCK_X5.BIN`. Its default is
  0x10. Every code overlay moves. If a pad makes an overlay larger than the slack of its RAM region, the link fails.

```sh
make disc SHIFT=1 SHIFT_PAD=0 SHIFT_OVL_PAD=0x10 PY=...
make replay-shift PY=...
```

On success, the replay prints `replay: shifted 0 divergences`. The regions and their slack are in
[tools/shift/README.md](../tools/shift/README.md).

## shift-scan

`make shift-scan` scans the built `SLUS_013.34` and `ROCK_X5.BIN` for references that are still bare addresses
rather than symbols. It reads the references into the main executable and into both overlay regions (exe->exe,
exe->ovl, ovl->ovl).

```sh
make shift-scan PY=...
```

On a clean build, the scan prints `shift-scan: 0 unsymbolized (exe 0, rockx5 0; ...)`. The scan also plants three
controls. For each direction, it prints `shift-scan: plant caught at <addr> (<direction>)`. `make check` runs the
scan and fails on any finding.

The file `config/shift/not_pointers.txt` lists the words that the scan does not count. Each line gives a reason. The
list holds five raw exe pointers into overlay region A that the developer accepted:

- `800710A4->800EEBB8` (mode 6)
- `80071254->800F2E38` (type 59)
- `80071258->800F33A8` (type 60)
- `8007466C->800EEA88` (action 31)
- `80074710->800EECC0` (action 72)

The list also holds the five region B base sites of the section above.

## shift-oversize

The `ROCK_X5.BIN` link, default and `SHIFT=1`, asserts that each overlay fits its RAM region. `make shift-oversize`
plants an oversize overlay and requires the link to fail.

```sh
make shift-oversize PY=...
```

On success, it prints `shift-oversize: link failed as planted (<ovl>)`.

## PATCHES= and replay-patch

`PATCHES=<name>` builds a patched variant from `patches/<name>/`. It works with `SHIFT=1` only. Without `SHIFT=1`, the
build stops with an error. The rules are in `mk/patches.mk`. The disc goes into `build/shift-<name>/disc/mmx5.cue`.

```sh
make disc SHIFT=1 PATCHES=halfdmg PY=...
make replay-patch PATCHES=halfdmg PY=...
```

The example patch set is [patches/halfdmg](../patches/halfdmg/README.md). On success, the replay prints
`replay-patch: halfdmg OK (first divergence clear >= declared mid_stage, 3 of 3 deterministic, control caught)`.

## ASSET_EDIT= and replay-asset

`ASSET_EDIT=<name>` builds a disc with an edited data asset from `asset-edits/<name>/`. The disc goes into
`build/asset-<name>/disc/mmx5.cue`. The build has no hash gate.

```sh
make disc ASSET_EDIT=m092fill PY=...
make replay-asset ASSET_EDIT=m092fill PY=...
```

The example asset edit is [asset-edits/m092fill](../asset-edits/m092fill/README.md). On success, the replay prints
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

## assets.py

`assets.py` exports `ROCK_X5.DAT` into the git-ignored `assets/` and imports it back.

```sh
python3 tools/assets/assets.py export
python3 tools/assets/assets.py import
python3 tools/assets/assets.py roundtrip
```

On success, `export` prints `assets: exported <n> files (container)`. On success, `import` prints
`assets: imported ROCK_X5.DAT <m> members`. On success, `roundtrip` prints
`assets: container 898 of 898 identical, 0 differences` and `assets: roundtrip OK (1 class)`.

`make firewall-check` plants an exported asset under `assets/` and prints `firewall-check: assets control caught`.
The detail is in [tools/assets/README.md](../tools/assets/README.md). The repacker is in
[tools/repack/README.md](../tools/repack/README.md).

## replay-check

`make replay-check` plays the intro script on the original image, on the rebuilt image and on a planted change. The
tracked script `tools/replay/scripts/intro.pad` holds pad events per frame and no game bytes. The replay runs on your
original image 3 times and on the rebuilt `build/disc/mmx5.cue` once. It runs once more with a planted
one-instruction change (`tools/replay/plants.txt`).

First, build the disc. On success, `make disc` prints `disc: track sha1 10709231f857636b5ccd3cd9acebc91458dcb5fd OK`.
The disc rebuild is in [building.md](building.md#rebuild-the-disc), and the image format is in [formats.md](formats.md).

```sh
make disc PY=...
make replay-check PY=...
```

On success, the replay prints `replay: original 3 of 3 identical, 8 checkpoints`, `replay: rebuilt 0 divergences` and
`replay: plant caught at stage_start`. It takes about an hour.

## How the toggles combine

`SHIFT=1` and `PATCHES=<name>` combine. A patch set always needs the shifted build. If you set `PATCHES=` without
`SHIFT=1`, the build stops with an error. `make replay-patch` is the exception, because it only reads the disc cue.

`make disc-assets` combines with `SHIFT=1` and also with `SHIFT=1 PATCHES=<name>`. `ASSET_EDIT=` needs an unshifted
build. If you set `ASSET_EDIT=` with `SHIFT=1`, the build stops before it starts and prints
`ASSET_EDIT needs an unshifted build (SHIFT unset)`.

## How to add a patch set

1. Make the directory `patches/<name>/`.
2. Copy each source file that you change to `patches/<name>/<alias>/<file>.c`.
3. Make sure that each patch file has a twin `src/<alias>/<file>.c`. For `rockx5`, the twin is `src/rockx5/ovlNN/<file>.c`
   and the patch file is `patches/<name>/rockx5/ovlNN/<file>.c`. For a `slus` unit in a system folder, the patch
   file is `patches/<name>/slus/<system>/<file>.c`.
4. Write the declared checkpoint as the first line of `patches/<name>/checkpoint` that does not start with `#`.
5. Run `make replay-patch PATCHES=<name> PY=...` after the shifted disc build.

A patch file without a twin is an error. The declared checkpoint must be one of the replay checkpoints. The replay
passes when it finds at least one divergence and no divergence before the declared checkpoint. The 3 runs must be
identical, and the replay must catch its control.

A name that starts with `_` is a test fixture
(`patches/_plant`). `patches/halfdmg` is an example.

## How to add an asset edit

1. Make the directory `asset-edits/<name>/`.
2. Write `edit.json` with the entry as `"<idx>/<sub>"` and the operation.
3. Write the declared checkpoint into `checkpoint`.
4. Write a `README.md` that describes the edit.
5. Run `make replay-asset ASSET_EDIT=<name> PY=...` after the disc build.

An asset edit changes only container entries of `ROCK_X5.DAT`. `asset-edits/m092fill` is an example. The operations
are in `tools/assets/README.md`.
