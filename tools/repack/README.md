# tools/repack
`rockx5.py` rebuilds `ROCK_X5.BIN` (overlay archive) from the linked image and generates the sector-0 TOC.

    rockx5.py pack --map build/rockx5/ROCK_X5.BIN.map --elf-bin build/rockx5/ROCK_X5.BIN --out build/disc/ROCK_X5.BIN [--ref extracted/retail/ROCK_X5.BIN]
    rockx5.py --selftest

- `pack` cuts the blobs ovl00..ovl58 by `<name>_ROM_START/_ROM_END` in the map. The layout: ovl00 is at 0x800, each
  next blob is at the next 2048 boundary, and the file is 2048-aligned. The TOC rows are `<II` (sector, size) + `(0,0)`.
  The format is in docs/formats.md "ROCK_X5.BIN TOC (inverse)".
- The output is the `--out` file. When the file is equal to `--ref`, `pack` prints
  `disc: ROCK_X5.BIN 59 overlays, toc generated, cmp OK`. Otherwise, `pack` prints the first diff and exits 1.

`disc.py build` (via `make disc`) rebuilds the CD image into `build/disc/mmx5.bin/.cue` and sha1-gates it vs `config/medium.sha1`.
`disc.py build --file <discpath>=<src>` packs `<src>` at `<discpath>` (repeatable). `make disc-assets` uses it to pack the re-imported ROCK_X5.DAT into `build/assets/disc/` under the same gate.

`make disc-assets SHIFT=1 [PATCHES=<n>]` packs the re-imported ROCK_X5.DAT into the shifted image `$(SH)/disc/` (no gate). `make disc ASSET_EDIT=<name>` refuses SHIFT.

`disc.py compare --image <bin>` runs the gate alone (exit 1: first differing LBA, manifest extent, form). The format is in docs/formats.md "Image rebuild (inverse)".
