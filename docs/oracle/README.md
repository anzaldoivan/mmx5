# Static oracle: Ghidra import of SLUS_013.34

PsyQ Version: 4.7.0

- Detected by: ghidra_psx_ldr `DetectPsyQ` at import (Program Information → `PsyQ Version`), printed by
  `tools/ghidra/scripts/RecordPsyq.java`. There was no "psyq/xx cannot be found" (the README `.0` fix was not needed).
- Loader: `PSX Executables Loader` (`-loader PsxLoader`, defaults). The RAM base is 0x80000000.
- Language: `PSX:LE:32:default`. Compiler spec: `default` (`mips32le.cspec`).
- The versions are Ghidra 12.1.3 (PUBLIC_20260817), ghidra_psx_ldr 2026.09.03 and JDK openjdk@21.
- Date: 2026-10-03
- To rerun the import, run `bash tools/run.sh ghidra-import -- bash tools/ghidra/import.sh`. The project `ghidra/mmx5`
  is ignored. The logs are in `.run/`.
- Pins and install: `docs/ops/oracles.md`
- Overlays + boundaries: the import adds the 53 code overlays of `loadmap.json` as blocks `ovlNN` (annotation addrs
  `ovl22::800ee970`). The import writes `docs/oracle/boundaries.txt` (jump tables, PsyQ objs). The counts are in
  `docs/memory-map.md`.
- Overlay functions: `tools/ghidra/scripts/CreateOverlayFunctions.java` runs after overlay analysis. It creates
  default-named `FUN_` functions in each `ovlNN` at in-block call targets and at the `jr ra`/data-bounded start of every
  orphan computed `jr` (+109). `nofn@` goes 452 → 9, all in the exe.

## Annotations export: `docs/oracle/annotations.jsonl`

- The file is a text record of the user-sourced annotations in `ghidra/mmx5` (no bytes, no instruction text). The
  annotations are functions and labels with USER_DEFINED/IMPORTED names, comments (all five types), datatypes in
  category `/mmx5` and Note bookmarks. Schema: plan Interfaces `ExportAnnotations.java`.
- Writers: `tools/ghidra/scripts/ExportAnnotations.java <out>` (project opened `-readOnly`).
  `ImportAnnotations.java <in>` writes only differences.
- Proof: `bash tools/run.sh ghidra-rt -- bash tools/ghidra/roundtrip.sh` → `roundtrip: byte-equal`. The proof exports
  twice: determinism. It does a fresh import into `.run/ghidra-rt/proj` via alias `ghidra/rt-proj`, import, re-export,
  `cmp`. The export also `cmp`s this file. The proof takes ~3 min.
- After you annotate in Ghidra, re-export here and commit:
  `analyzeHeadless ghidra mmx5 -process SLUS_013.34 -noanalysis -readOnly -scriptPath tools/ghidra/scripts -postScript ExportAnnotations.java $PWD/docs/oracle/annotations.jsonl`.
- The seed (T2.c1) is `__start` at pc0 0x8005894C (renamed from loader `start`), one eol comment there and struct
  `/mmx5/Vec3s`.

## nofn survivors

None (T8). The 9 former exe-space (`CODE`) survivors were fn-pointer-only code after the `jr ra` of a short function
(DATA/PARAM refs, never a call). The exe pass of `CreateOverlayFunctions` now creates `FUN_` functions there (walk-back,
entry must be DATA/PARAM-referenced, fixpoint). The owners are now `FUN_80014dec`, `FUN_80019d24`, `FUN_80034508`,
`FUN_80034c28`, `FUN_8003c0ec`, `FUN_8004e360`, `FUN_8004e660`, `FUN_800535c8`, `FUN_80054758`.
