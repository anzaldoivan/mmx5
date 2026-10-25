# tools/assets

ROCK_X5.DAT asset tool (stdlib only). Format: docs/formats.md `## ROCK_X5.DAT (inverse)`.

`PY tools/assets/assets.py survey [--dat extracted/retail/ROCK_X5.DAT]`

Output:
- one line per TOC member: `idx sector size kind`, kind ∈ pack|tim|raw|zero (classify order zero, pack, tim, raw).
- `survey: <N> members, <p> pack, <t> tim, <r> raw` (`, <z> zero` only if z>0).
- `survey: level 2: <n> entries, <p> pack, <t> tim, <r> raw, <z> zero` over all pack entries.
- `survey: classes 0:<a> 1:<b> 2:<c>` (entry class = `type >> 16`, any other class also listed, sum = level-2 count), then per class `survey: class <c> kinds 0x<kind:04x>:<n> ...` sorted by kind (kind = `type & 0xFFFF`).

Prints offsets, sizes and counts only. No game bytes.

`PY tools/assets/assets.py export [--src extracted/retail] [--out assets/retail]` → `assets: exported <n> files (container)`

`PY tools/assets/assets.py import [--src assets/retail] [--out build/assets]` → `assets: imported ROCK_X5.DAT <m> members`

`PY tools/assets/assets.py roundtrip` → `assets: container <n> of <n> identical, 0 differences`, `assets: roundtrip OK (1 class)`. Exit 1 names the first differing entry.

`PY tools/assets/assets.py apply <name> [--src assets/retail] [--out assets/work/<name>]` → copies the export tree, applies `asset-edits/<name>/edit.json` (`{"entry": "iii/sss"|"iii", "op": "fill", "offset", "length", "byte"}`) to that one `.bin`. Size is asserted unchanged → `assets: applied <name> to <entry> (<len> of <size> B, size unchanged)`. sha1s in index.json/manifest are left as exported (import checks sizes only). `make disc ASSET_EDIT=<name>` = export (if absent) + apply + import → `build/asset-<name>/disc/mmx5.cue` (no sha gate). `make replay-asset ASSET_EDIT=<name>` verdicts it (tools/replay/README.md). `make disc-assets SHIFT=1 [PATCHES=<n>]` packs the re-imported DAT into `$(SH)/disc/` (shifted, no gate). `make disc ASSET_EDIT=<name>` refuses SHIFT (needs an unshifted build).

`PY tools/assets/assets.py --selftest` → synthetic DAT from `fixtures/synth.json` (raw member, pack with class 0/1/2 types and a zero entry, no game bytes), round trip + planted byte caught → `assets: control OK`.

index.json entries carry `type` plus derived `kind` and `class` ints. Export layout and size-change refusal: docs/formats.md `### Export layout`. Exports live only under assets/ or .run/ (ignored).
