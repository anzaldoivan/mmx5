# Medium formats (extractor: `tools/extract/extract.py`, `make extract`)

## CUE/BIN
- CUE: one `FILE "<name>.bin" BINARY`, one `TRACK 01 MODE2/2352`, `INDEX 01 00:00:00`. BIN path is relative to the CUE.
- BIN: raw 2352-byte sectors, LBA n at byte `n*2352`. The file has no pregap (LBA 0 = byte 0).
- Raw Mode 2 XA sector, both forms: `0..11` sync, `12..15` header (MSF + mode=2), `16..23` subheader (file, channel,
  submode, coding). The sector repeats these subheader fields twice.
- Form 1 (submode bit `0x20` clear): `24..2071` user data (2048), `2072..2075` EDC, `2076..2351` ECC (P 172 + Q 104).
- Form 2 (submode bit `0x20` set): `24..2347` user data (2324), `2348..2351` EDC (may be 0).
- Form test: raw byte 18 (submode) `& 0x20`. Submode `0x00` (null sector) counts as Form 1.

## ISO9660 records used (offsets into 2048-byte user data)
- Volume descriptors from LBA 16 until type `255` (terminator).
- PVD: `0` type=1, `1..5` `CD001`. `80` volume space size (u32 LE). `132` path table size (u32 LE). `140` L path table
  LBA, `144` optional L. `148` M path table LBA (BE), `152` optional M (BE). `156..189` root directory record.
- Directory record: `0` length (0 = skip to next sector, and records never cross sectors). `2` extent LBA (u32 LE). `10`
  data length (u32 LE). `25` flags (bit `0x02` = directory). `32` name length. `33` name (`\0` self, `\1` parent), with
  `;1` stripped.
- Path tables: located only to account their sectors (not parsed). Sectors = ceil(path table size / 2048).

## Payload convention
- Extent sectors = ceil(size / 2048). Mode over the extent: all Form 1 = `form1`, all Form 2 = `form2`, else `mixed`.
- `form1`: 2048 user bytes/sector, truncated to `size`. `form2`/`mixed`: 2336 bytes/sector (raw `16..2351`: subheader +
  data + EDC/ECC), not truncated. Their file size on disk = sectors*2336.
- Retail: `STR/*.STR` and `XA/BGM.XA` are `mixed` (Form 1 video `0x48` / null `0x00` sectors among Form 2 audio `0x64`).
- Reference cross-check (`tools/extract/refcheck.py`): dumpsxiso 2.30 writes XA/mixed files in the same 2336-byte/sector
  layout (raw `16..2351`). It writes Form 1 files truncated to `size`. The mapping is identity, with no normalisation.

## Manifest (`<out>/manifest.jsonl`)
- One JSON object per line, `json.dumps(sort_keys=True)`, sorted by `(lba, path)`. The keys are
  `kind lba mode path sectors size` plus `sha1`, or `content_sha1` + `"trivial": true` when the payload is empty or all zero bytes.
- `file`: sha1 of the payload above. `dir`: sha1 of the directory extent's Form 1 user data (`size` bytes). The root path is `/`.
- `system` (sha1 over raw 2352-byte sectors, `size` = sectors*2352): `@system/area` LBA 0-15, `@system/descriptors`
  LBA 16..terminator, `@system/pathtable_{l,l2,m,m2}` for each nonzero path table LBA.
- Last line `{"kind": "coverage", "sectors_total": bin_size/2352, "sectors_accounted": |union of extents|}`.

## Coverage (retail, Redump #7437)
- `sectors_total` 247855 = PVD volume space size. `sectors_accounted` 247705.
- Unaccounted: LBA 247705-247854 (150 sectors): trailing pad after the last file, subheader all zero, user data all zero.

## ROCK_X5.BIN TOC (inverse)
- Tool: `tools/repack/rockx5.py pack` rebuilds the archive from `build/rockx5/ROCK_X5.BIN` + its ld map. The TOC is generated, never copied.
- Sector 0: 59 rows `<II` (start sector = offset/2048, size bytes) for ovl00..ovl58, then `(0,0)`. The rest of sector 0 is zero.
  The count comes from exe `addiu a2,zero,0x3a` (+1). Reader: `tools/loadmap/loadmap.py`.
- Layout: ovl00 at 0x800. Each next overlay is at the next 2048-aligned offset after the previous end. The file ends 2048-aligned (0x152000).
- Gap rule: every gap (padNN, padend) is exactly the rounding remainder (retail: 59 gaps, max 0x7ec) and zero. If a gap breaks this rule, pack exits 1 and names it.
- Named non-zero pads: none.
- Shifted (`--ref ''`, `make disc SHIFT=1`): overlays grow but padNN bins keep retail length, so gaps may exceed the remainder. Each gap must be all zero (else exit 1 naming the pad), and is dropped. Every overlay is relaid at the next sector by the layout rule above.
- Shifted checks: TOC rows read back == (relaid sector, map END-START) for all 59, and image len == align(last end). Pack prints `relaid <n> sectors (retail <m>)` and the row counts that differ from the retail TOC (read-only).

## Image rebuild (inverse)
- Tool: `make disc` → `tools/repack/disc.py build` → `build/disc/mmx5.bin/.cue`.
- Layout: `dumpsxiso -s` of the original → `build/disc/ref/layout.xml` (order, dates, license, trailing `<dummy sectors="150">` of zeros).
  The track has `xa_edc="false"`. Every `<file>` gets an absolute `source=`: `extracted/retail/<path>`, except ROCK_X5.BIN (`build/disc/`) and SLUS_013.34 (`build/slus/`).
- `type="mixed"` sources (STR, XA) are 2336-B-per-sector payloads (= extractor's mixed payload). The mkpsxiso tool regenerates headers/EDC.
- Gate: sha1 of the image vs `config/medium.sha1` line 1. If they differ, exit 1 with first differing LBA, manifest extent, form (subheader byte 18 & 0x20).
- Override: `disc.py build --file <discpath>=<src>` (repeatable, applied last). `make disc-assets` re-imports ROCK_X5.DAT (`assets.py export` + `import`) and packs it → `build/assets/disc/mmx5.bin/.cue`, same sha gate.


## Asset survey
- Source: `extracted/retail/manifest.jsonl` (18 lines). Admitted = enters the asset pipeline (`tools/assets/assets.py` export/import). Everything else reaches the image through `make disc` unchanged.
- `@system/area` (LBA 0-15), `@system/descriptors`, `@system/pathtable_{l,l2,m,m2}`: class system. Admitted no: mkpsxiso regenerates them from `build/disc/ref/layout.xml` (license from `dumpsxiso -s`).
- `/`, `STR`, `XA` (dir): class dir. Admitted no: mkpsxiso regenerates the directory extents from the layout.
- `SYSTEM.CNF` (68 B, form1): class config text. Admitted no: boot config, passthrough. Nothing to convert.
- `ROCK_X5.DAT` (form1, LBA 26, 23,406 sectors): class data container. Admitted yes: the one asset archive. Layout below.
- `SLUS_013.34`: class code. Admitted no: built from src/ (`make split build BINARY=slus`).
- `ROCK_X5.BIN`: class code (overlay archive). Admitted no: built from src/ + `rockx5.py pack`. Data overlays ovl13/15/17/19 (loadmap kind `data`, 1344 B each) are linked from our split (`config/splat.rockx5.yaml`), not assets.
- `STR/CAPLOGO.STR`, `STR/X5OP.STR` (mixed, 2336 B/sector): class video stream. Admitted no: passthrough. MDEC/XA re-encoders (psxavenc, jPSXdec) are lossy, never byte-identical (cookbook C0007).
- `XA/BGM.XA` (mixed): class XA audio stream. Admitted no: same reason as STR.
- `ZNULL.DAT` (37,044,000 B): class filler, all zero (manifest `trivial`). Admitted no: nothing to edit.
- `coverage`: accounting line, not a file. Admitted no.

## ROCK_X5.DAT (inverse)
- TOC (sector 0): `struct.pack('<II', start_sector, size_bytes)` x172, then `(0,0)`, rest of sector 0 zero. Same row form as the ROCK_X5.BIN TOC.
- Layout: member 0 at sector 1. Member i at `start_sector*2048`, length `size_bytes`. Next member at the next 2048 boundary. Gap = rounding remainder, zero. Last member ends at the file end (23,406 sectors).
- Reader: `func_80013EE8` (0x80013EE8). `CdSearchFile("\ROCK_X5.DAT;1")` at 0x80013F1C (name `D_80010004`), `CdRead` of 1 sector to 0x80105000, then copies the 172 rows into the file table `D_800E5C08[175][2]` as `{DAT LBA + start_sector, size}`. Rows 172-174 come from `CdSearchFile` on the name table `D_8006F3FC` (22-byte stride): `\STR\CAPLOGO.STR;1`, `\STR\X5OP.STR;1`, `\XA\BGM.XA;1`.
- Indexing (R5): proven for the exe. The only DAT LBA source is the TOC copy above. `D_800E5C08` consumers are all in slus: `func_80014574` (x2), `func_80015A00`, `func_80015BA4`, `func_800157D4`. No `D_800E5C08` reference in asm/rockx5. A member that changes size moves later members, and the game follows that through the TOC. Unproven: whether any overlay keeps its own copy of an LBA.
- Pack form (165 of 172 members): `u32 count, u32 total_size (== member size)`, then `count` rows `<II (type, size)>`. Header padded with zero to 2048. Entry k starts at `2048 + sum(align2048(size_j), j<k)`. Each entry is zero-padded to 2048. `total_size == 2048 + sum(align2048(size))`. Offsets are implicit (no offset table), padding byte 0x00 everywhere (header and entries).
- Entry `type`: low 16 bits = kind, high 16 bits = class (observed 0, 1, 2). Per-class counts, sizes, kinds and readings: `### Entry taxonomy`.
- Non-pack members (7, kind raw): 78 (u32 count 28 + ascending u32 table). 89 and 91 (u32 8, u32 0x474, `pQES` SEQ magic at +8). 96-99 (8192 B each, other form). Not decoded.
- TIM (id 0x10, flags bpp|0x8 CLUT): none found. No member and no pack entry starts with a TIM header, and a 4-aligned scan of the whole DAT for `0x10, flags, block len == 12 + w*h*2` finds 0. Graphics are headerless blocks (class-1 entries). The planning read of first-u32 0x10 as a TIM id was a pack with count 16.
- Census (`assets.py survey`): level 1: 165 pack, 0 tim, 7 raw, 0 zero. Level 2 (pack entries): 891 entries, 0 pack, 0 tim, 862 raw, 29 zero. No pack nests a pack.

### Entry taxonomy (`assets.py survey`, 891 pack entries)
- Class 0: 592 entries in 164 members, sizes 4..262,144 B. Kinds: 0x0000:56 0x0001:56 0x0002:6 0x0003:8 0x0004:40 0x0005:75 0x0006:12 0x0007:78 0x0009:6 0x000a:55 0x000b:55 0x000c:55 0x000d:17 0x0011:6 0x0012:6 0x0014:7 0x0015:28 0x0016:16 0x0017:10.
- Class 1: 169 entries in 89 members, sizes 2,048..262,144 B, every size a multiple of 0x800. Kinds: 0x0000:55 0x0001:1 0x0002:2 0x0007:7 0x0008:1 0x000b:6 0x0102:52 0x0109:11 0x010a:1 0x010d:7 0x010e:1 0x010f:1 0x0110:1 0x0206:6 0x030c:11 0x0411:5 0x0412:1. Members holding class-1 entries: 0, 77, 79-88, 90, 92-95, 100-171.
- Class 2: 130 entries in 85 members, sizes 5,616..297,680 B. Kinds: 0x0000:39 0x0101:6 0x0202:61 0x0303:6 0x0505:18.
- Readings, all unproven: class 1 = VRAM image blocks (size multiples of 0x800), class 2 = sound-bank bodies (high entropy). No format claim for any class or kind without a loader trace.

### Export layout (`assets.py export|import|roundtrip`)
- `export [--src extracted/retail] [--out assets/retail]`: raw member → `<out>/dat/<idx:03d>.bin`. Pack entry → `<out>/dat/<idx:03d>/<sub:03d>.bin` (entry bytes only, no padding).
- `<out>/dat/index.json` = `{"toc":[{"idx","sector","size","kind","sha1","entries":[{"sub","type","kind","class","size","sha1"}]}]}`. `entries` only for packs. `type` is the full u32 type word. `kind` = `type & 0xFFFF`, `class` = `type >> 16` (ints, written by export). Import reads only `type`.
- `<out>/manifest.jsonl`: `{"path","sha1","class":"container"}` per `.bin`, sorted by path. Retail: 898 files (891 pack entries + 7 raw members).
- `import [--src assets/retail] [--out build/assets]`: pack header rebuilt from index.json (count, total, type, size), never from member bytes. All padding is zero. TOC regenerated contiguous from sector 1, then `(0,0)`. A `.bin` whose size differs from index.json → exit 1, `assets: <path> size changed, relayout not proven`.
- `roundtrip`: export + import under `.run/assets-rt/`, per-entry compare, then whole-DAT sha1 vs retail. Retail matches the layout rule exactly (no TOC deviation, gap or tail).
