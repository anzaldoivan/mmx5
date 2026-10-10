# Medium formats (extractor: `tools/extract/extract.py`, `make extract`)

## CUE/BIN
- CUE: one `FILE "<name>.bin" BINARY`, one `TRACK 01 MODE2/2352`, `INDEX 01 00:00:00`. BIN path is relative to the CUE.
- BIN: raw 2352-byte sectors, LBA n at byte `n*2352`; no pregap in the file (LBA 0 = byte 0).
- Raw Mode 2 XA sector, both forms: `0..11` sync, `12..15` header (MSF + mode=2), `16..23` subheader (file, channel,
  submode, coding; repeated twice).
- Form 1 (submode bit `0x20` clear): `24..2071` user data (2048), `2072..2075` EDC, `2076..2351` ECC (P 172 + Q 104).
- Form 2 (submode bit `0x20` set): `24..2347` user data (2324), `2348..2351` EDC (may be 0).
- Form test: raw byte 18 (submode) `& 0x20`. Submode `0x00` (null sector) counts as Form 1.

## ISO9660 records used (offsets into 2048-byte user data)
- Volume descriptors from LBA 16 until type `255` (terminator). PVD: `0` type=1, `1..5` `CD001`; `80` volume space size
  (u32 LE); `132` path table size (u32 LE); `140` L path table LBA, `144` optional L; `148` M path table LBA (BE), `152`
  optional M (BE); `156..189` root directory record.
- Directory record: `0` length (0 = skip to next sector; records never cross sectors); `2` extent LBA (u32 LE); `10` data
  length (u32 LE); `25` flags (bit `0x02` = directory); `32` name length; `33` name (`\0` self, `\1` parent; `;1` stripped).
- Path tables: located only to account their sectors (not parsed); sectors = ceil(path table size / 2048).

## Payload convention
- Extent sectors = ceil(size / 2048). Mode over the extent: all Form 1 = `form1`, all Form 2 = `form2`, else `mixed`.
- `form1`: 2048 user bytes/sector, truncated to `size`. `form2`/`mixed`: 2336 bytes/sector (raw `16..2351`: subheader +
  data + EDC/ECC), not truncated; file size on disk = sectors*2336.
- Retail: `STR/*.STR` and `XA/BGM.XA` are `mixed` (Form 1 video `0x48` / null `0x00` sectors among Form 2 audio `0x64`).
- Reference cross-check (`tools/extract/refcheck.py`): dumpsxiso 2.30 writes XA/mixed files in the same 2336-byte/sector
  layout (raw `16..2351`) and Form 1 files truncated to `size`; mapping is identity, no normalisation.

## Manifest (`<out>/manifest.jsonl`)
- One JSON object per line, `json.dumps(sort_keys=True)`, sorted by `(lba, path)`; keys `kind lba mode path sectors size`
  plus `sha1`, or `content_sha1` + `"trivial": true` when the payload is empty or all zero bytes.
- `file`: sha1 of the payload above. `dir`: sha1 of the directory extent's Form 1 user data (`size` bytes); root path `/`.
- `system` (sha1 over raw 2352-byte sectors, `size` = sectors*2352): `@system/area` LBA 0-15, `@system/descriptors`
  LBA 16..terminator, `@system/pathtable_{l,l2,m,m2}` for each nonzero path table LBA.
- Last line `{"kind": "coverage", "sectors_total": bin_size/2352, "sectors_accounted": |union of extents|}`.

## Coverage (retail, Redump #7437)
- `sectors_total` 247855 = PVD volume space size; `sectors_accounted` 247705.
- Unaccounted: LBA 247705-247854 (150 sectors): trailing pad after the last file, subheader all zero, user data all zero.
