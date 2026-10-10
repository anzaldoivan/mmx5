# Third-party sources

Every third-party source this repository uses, by how it is used. Pins come from `config/refs.toml`; classes from
`docs/ops/refs.md` and `docs/prior-art.md`. Checked 2026-10-11 against the tracked tree (`git ls-files`): no
`refs/` file is tracked, and no tracked file carries code adapted or copied from a third-party source.

## Adapted or vendored in this tree

None. No third-party code is copied, adapted or vendored into any tracked file. A future adaptation (class `adapt`,
or `copyleft` when licence-compatible with AGPL-3.0) adds an entry here: name, URL, pinned ref, licence, and the
tracked path that holds the adapted code.

## Used at build or analysis time, not included

Fetched by `tools/bootstrap.sh`, `tools/refs_fetch.sh`, `tools/toolchain/fetch.sh` or `pip` into ignored paths
(`refs/`, `.venv/`, `.run/`); never committed. Our tools invoke them; they keep their own licences.

- maspsx — https://github.com/mkst/maspsx — `423ffc6bca05e53f9b7ab06159d0cbe71111bc90` — MIT. Assembler shim in the
  build (`mk/`), run from `refs/maspsx/`.
- splat (splat64) — https://github.com/ethteck/splat — `1d09139b886f0bece632bd8f367ccc1d3318ca2a` — MIT. Splitter,
  installed as `splat64[mips]==0.50.0` (`requirements-python.txt`); our `config/splat.*.yaml` are our own configs.
- spimdisasm — https://github.com/Decompollaborate/spimdisasm — `4b5d4c68eeb9f9eae14b3bb713971433ae2c3c43` — MIT.
  splat's disassembler backend, installed as `spimdisasm==1.42.4`.
- decomp-permuter — https://github.com/simonlindholm/decomp-permuter — `059609d4aec73eb0650726772954e1ad575825f8` —
  MIT. Staged into `refs/decomp-permuter/` by `tools/codegen/stage.sh --permuter`; driven by `tools/permuter/permute.py`
  (our wrapper, no permuter code in it).
- mmx4 — https://github.com/sozud/mmx4 — `756987672dead40a15e3d633d8a1b3b005fbd6c6` — AGPL-3.0 (copyleft).
  `tools/sig/sig.py` (L8, `build-foreign`) compiles `refs/mmx4/src/main/**/*.c` into `.run/sig/mmx4/` only, to
  compare leaf-function signatures; it cites mmx4's build flags (`build.py` line references) and copies no mmx4 code
  (sig.py:276). Nothing from mmx4 is in a tracked file, so nothing is attributed as adapted.
- psy-q-decomp — https://github.com/sozud/psy-q-decomp — `6edf9b24721ba02a53eb423b8a7497b82ba0768c` — MIT. Optional
  reference, read only; nothing adapted.
- sotn-decomp — https://github.com/Xeeynamo/sotn-decomp — `9faca7c81c736a037949022237051cdd170e84e5` — AGPL-3.0
  (copyleft). Optional reference for layout and style, read only; nothing adapted.
- GCC 2.7.2 / 2.95.2 sources — https://ftp.gnu.org/gnu/gcc/ — tarball sha256 in `config/refs.toml` — GPL-2.0-or-later
  (copyleft). Optional compiler-source reference, read only. The cc1 binaries are decompals/old-gcc 0.17 release
  tarballs (GCC, GPL), fetched with pinned sha256 by `tools/toolchain/fetch.sh` (`tools/toolchain/compilers.txt`)
  into an ignored path.
- pcsx-redux PsyQ obj parser — https://github.com/grumpycoders/pcsx-redux — `config/refs.toml` — GPL-2.0 (copyleft).
  Optional; read only.

## Facts only, not included

Class `facts`: facts are cited (hashes, layouts, flags), never text or code. old-gcc
(https://github.com/decompals/old-gcc), ghidra_psx_ldr (https://github.com/lab313ru/ghidra_psx_ldr),
decompme/compilers, mstan/MegaManX5Recomp (PolyForm Noncommercial 1.0.0), mstan/psxrecomp and the X4/X6 recomps,
ChrisNonyminus/mml1, psx-spx, the MMX5 Improvement Project addendum (acediez), mmx6. Pins and licences:
`config/refs.toml`, `docs/ops/refs.md`, `docs/prior-art.md`.

## Bring your own, not included

Class `byo`: the PsyQ SDK (proprietary, Sony Computer Entertainment) is never fetched and never committed; the user
supplies a local path, and `tools/psyq/` is a firewall purge path (`config/firewall.txt:55`). The game itself
(*Mega Man X5*, Capcom) is the user's own legally obtained copy; nothing derived from it is committed
(`config/firewall.txt`, `tools/audit_public.py`).
