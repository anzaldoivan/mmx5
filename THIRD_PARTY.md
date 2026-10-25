# Third-party sources

This file lists every third-party source that this repository uses, by how it is used. Pins come from
`config/refs.toml`. Classes come from `docs/ops/refs.md` and `docs/prior-art.md`. The tracked tree (`git ls-files`)
was checked on 2026-10-11. No `refs/` file is tracked. Only drafts from mmx6's C (below, from 2026-10-14) may carry
code adapted from a third-party source.

## Adapted or vendored in this tree

An entry gives the name, the URL, the pinned ref, the licence and the tracked path that holds the adapted code. Its
class is `adapt`, or `copyleft` when licence-compatible with AGPL-3.0.

- mmx6 — https://github.com/anzaldoivan/mmx6 — `c1c892dc301cfb2f1752b06854cbc02778e1404a` — AGPL-3.0
  (copyleft), the developer's own Mega Man X6 decompilation under this repository's licence, path `src/`. A function
  drafted from a card's `## Twin in X6` adapts its X6 twin's C from `refs/mmx6/src/`, with X5's symbols and types.
  The leads are `docs/oracle/x6-leads.tsv` (`docs/prior-art.md` L8d). Some of those X6 files are adapted from
  sozud/mmx4 (AGPL-3.0), as their first line says, and a draft keeps that line.
  `waves.py port` writes the attribution line (`/* Adapted from mmx6 @<pin> <path>, AGPL-3.0 (THIRD_PARTY.md). */`)
  as each ported draft's first line.

## Used at build or analysis time, not included

`tools/bootstrap.sh`, `tools/refs_fetch.sh`, `tools/toolchain/fetch.sh` or `pip` fetches these sources into ignored
paths (`refs/`, `.venv/`, `.run/`). They are never committed. Our tools invoke them. They keep their own licences.

- maspsx — https://github.com/mkst/maspsx — `423ffc6bca05e53f9b7ab06159d0cbe71111bc90` — MIT. It is the assembler
  shim in the build (`mk/`), run from `refs/maspsx/`.
- splat (splat64) — https://github.com/ethteck/splat — `1d09139b886f0bece632bd8f367ccc1d3318ca2a` — MIT. It is the
  splitter, installed as `splat64[mips]==0.50.0` (`requirements-python.txt`). Our `config/splat.*.yaml` are our own
  configs.
- spimdisasm — https://github.com/Decompollaborate/spimdisasm — `4b5d4c68eeb9f9eae14b3bb713971433ae2c3c43` — MIT.
  It is splat's disassembler backend, installed as `spimdisasm==1.42.4`.
- decomp-permuter — https://github.com/simonlindholm/decomp-permuter — `059609d4aec73eb0650726772954e1ad575825f8` —
  MIT. `tools/codegen/stage.sh --permuter` stages it into `refs/decomp-permuter/`. `tools/permuter/permute.py`
  drives it. That file is our wrapper, with no permuter code in it.
- mmx4 — https://github.com/sozud/mmx4 — `34f37a46f34a1180a7eac7d545fdfb6e0c7f533d` — AGPL-3.0 (copyleft).
  `tools/sig/sig.py` (L8, `build-foreign`) compiles `refs/mmx4/src/main/**/*.c` into `.run/sig/mmx4/` only. It does
  so to compare leaf-function signatures. It cites mmx4's build flags (`build.py` line references) and copies no
  mmx4 code (sig.py:276). Nothing from mmx4 is in a tracked file, so nothing is attributed as adapted.
- psy-q-decomp — https://github.com/sozud/psy-q-decomp — `6edf9b24721ba02a53eb423b8a7497b82ba0768c` — MIT. It is an
  optional reference, read only. Nothing is adapted.
- sotn-decomp — https://github.com/Xeeynamo/sotn-decomp — `9faca7c81c736a037949022237051cdd170e84e5` — AGPL-3.0
  (copyleft). It is an optional reference for layout and style, read only. Nothing is adapted.
- GCC 2.7.2 / 2.95.2 sources — https://ftp.gnu.org/gnu/gcc/ — tarball sha256 in `config/refs.toml` — GPL-2.0-or-later
  (copyleft). It is an optional compiler-source reference, read only. The cc1 binaries are decompals/old-gcc 0.17
  release tarballs (GCC, GPL). `tools/toolchain/fetch.sh` (`tools/toolchain/compilers.txt`) fetches them with pinned
  sha256 into an ignored path.
- pcsx-redux PsyQ obj parser — https://github.com/grumpycoders/pcsx-redux — `config/refs.toml` — GPL-2.0 (copyleft).
  It is optional. It is read only.

## Facts only, not included

Class `facts`: this repository cites facts (hashes, layouts, flags), never text or code. The sources of this class
are in this list:

- old-gcc (https://github.com/decompals/old-gcc)
- ghidra_psx_ldr (https://github.com/lab313ru/ghidra_psx_ldr)
- decompme/compilers
- mstan/MegaManX5Recomp (PolyForm Noncommercial 1.0.0)
- mstan/psxrecomp and the X4/X6 recomps
- ChrisNonyminus/mml1
- psx-spx
- the MMX5 Improvement Project addendum (acediez)

The pins and the licences are in `config/refs.toml`, `docs/ops/refs.md` and `docs/prior-art.md`.

## Bring your own, not included

Class `byo`: the PsyQ SDK (proprietary, Sony Computer Entertainment) is never fetched and never committed. The user
supplies a local path, and `tools/psyq/` is a firewall purge path (`config/firewall.txt:55`). The game itself
(*Mega Man X5*, Capcom) is the user's own legally obtained copy. Nothing derived from it is committed
(`config/firewall.txt`, `tools/audit_public.py`).
