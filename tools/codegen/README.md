# tools/codegen — the pinned cc1's source and the codegen-map citation audit

`bash tools/codegen/stage.sh` · `PY tools/codegen/cites.py check [--docs DIR] [--tree DIR]` · `PY tools/codegen/cites.py --selftest`

Health: `make tools-health` runs `cites.py check`, `levers.py check`, `symptoms.py check` (rungs 13-15); `make tools-selftest` runs their `--selftest`.

- `stage.sh`: fetch `gcc-2.95.2.tar.gz` → `refs/` (sha256 from config/refs.toml `gcc-2.95.2-src`), unpack to
  `refs/gcc-2.95.2-psx/`, apply the source steps of `refs/old-gcc/gcc-2.95.2-psx.Dockerfile` in the tree root:
  1. `sed -i -- 's/include <varargs.h>/include <stdarg.h>/g' */*.c` (dash expands the Dockerfile's `**/*.c` one level deep)
  2. `patch -u -p1 include/obstack.h -i <old-gcc>/patches/obstack-2.95.2.h.patch`
  3. `patch -u -p1 gcc/config/mips/mips.h -i <old-gcc>/patches/mips.patch`
  4. `patch -su -p1 < <old-gcc>/patches/psx-2.91.patch`
  No configure/build. Idempotent: an unchanged `.staged` prints `stage: up to date`; any change restages.
- `.staged` (key=value lines): `tarball_sha256=`, `old_gcc_ref=` (`git -C refs/old-gcc rev-parse HEAD`),
  `step=` (the sed step), `patch=<name> <sha256>` per patch in order.
- `cites.py check`: scans `docs/codegen-map/` (default; missing = 0 cites) `*.md/*.yaml/*.yml` for
  `gcc/<path>:<line> <symbol>` (symbol optionally in backticks); stale = file missing, line out of range, or
  symbol not on the line (lines numbered on `\n`, as grep does). Prints the tree line, `cites: <ok> of <n>
  citations resolve, <s> stale`, one `cites: STALE …` per stale cite; exit 1 if stale or tree unstaged.
- `--selftest`: `fixtures/` (invented text, no GCC text): one good, one stale cite → `cites: control OK -- stale citation refused`.

## levers

`PY tools/codegen/levers.py check` · `PY tools/codegen/levers.py dump <file.c>` · `PY tools/codegen/levers.py --selftest`

- `docs/codegen-map/levers.yaml`: JSON (valid YAML; PY has no yaml module), a list of
  `{id, group: sched|regalloc|loop|cse_expr, tell: <regex over before .cc.s>, before: <path .c>, after: <path .c>,
  fn: <symbol>, cite: "gcc/<path>:<line> <symbol>", cookbook: C<nnnn>|null, proven_on: <game fn>|null}`;
  reproducers `docs/codegen-map/levers/<id>.{before,after}.c`. `cite` is audited by `cites.py check`.
- `check`: compiles both sides at the pin (`reconcile.triple()` → `probe.compile_obj`); copies cc1 output to
  `.run/codegen/levers/<id>/{before,after}.cc.s`; proven = tell matches before, absent in after, masked words of
  `fn` differ. Prints `levers: <g> of 4 pass groups proven, <n> of <m> levers byte-proven`, one
  `levers: FAIL <id> <reason>` per failure; exit 1 on any FAIL.
- `dump <file.c>`: same pin + `-da -dumpbase`; per-pass RTL dumps `<file>.c.<pass>` in `.run/codegen/dumps/<stem>/`.
- `--selftest`: `fixtures/levers/inert.{before,after}.c` (synthetic, same codegen) → `levers: control OK -- inert lever refused`.

## symptoms

`PY tools/codegen/symptoms.py build` · `PY tools/codegen/symptoms.py check` · `PY tools/codegen/symptoms.py --selftest`

- Inputs: `cookbook/INDEX.md` lines tagged `idiom` (not `cookbook-format`); each entry's column-0 `symptom: <phrase>` and
  `lever: <id>` lines; `docs/codegen-map/levers.yaml` (`id`, `cookbook`); `cookbook/C0002.md` table Entries cells.
- `build`: writes `docs/codegen-map/SYMPTOMS.md` (generated, never hand-edit), sorted rows `symptom | entry ids | lever ids`.
- `check`: unindexed = idiom entry or levers.yaml id absent from SYMPTOMS.md; unresolved = row entry without
  `cookbook/C<nnnn>.md`, row lever not in levers.yaml or whose `cookbook:` is not in the row, C0002 Entries id without a file;
  also fails on a missing symptom/lever line, any `TODO` in C0002, stale SYMPTOMS.md. Prints one `symptoms: FAIL <what>`
  per failure, then `symptoms: <n> of <n> idiom entries indexed, <m> of <m> levers indexed, <u> unindexed, <r> unresolved`;
  exit 1 on any failure.
- `--selftest`: scratch copy in `.run/codegen/symptoms-selftest/` plus a planted idiom entry absent from SYMPTOMS.md →
  `symptoms: control OK -- unindexed entry refused`.
