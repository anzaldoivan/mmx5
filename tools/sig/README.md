# tools/sig

`sig.py` — function signatures, the exact tier and the near (twin) band over the census inventory.

    PY tools/census/inventory.py && PY tools/census/census.py dup     # inputs
    PY tools/sig/sig.py band [--sample N] [--pairs P] [--seed S]
    PY tools/sig/sig.py --selftest

- Words: `census.load()` (imported in place); norm words = `census.dup_key(words)` (reloc fields masked).
  Signature = sha1 hex of the norm words; exact cluster = equal signature; rep = first member by key.
  Functions keyed (alias, vram, name) (G41).
- Near tier, reps only: dist = unit-cost Levenshtein over norm words; near iff `dist / max(len) < T`, `T = 0.3`
  (DK-10 lookalike ratio), and `max(len) >= 8` (short-function floor: below 8 words one differing word is a large
  share of the body; recorded, not tuned).
- Prefilter (both sound lower bounds on dist): length difference; opcode histogram `(|la-lb| + L1) / 2`.
  Survivors: banded Levenshtein with cutoff `D = largest d with d/max < T`.
- Work weights: `work = indels + 3 * substitutions` (alignment: min dist, then fewest substitutions); rows rank by
  work ascending, ties by keys. Near pairs expand to `|A| * |B|` function pairs, never materialised.
- Output `.run/sig/twins.jsonl`: `{a, b, tier: exact|near, dist, ratio, sig_a, sig_b, na, nb (insns), work}`;
  exact = one row per member vs its rep, near = one row per rep pair.
- Prints `sig: <n> of <m> functions signed`, `sig: band reproduces <r> of <e> exact pairs, +<k> near`
  (e = sum C(|g|,2) over census dup groups, each checked to sit in one signature cluster by key),
  `sig: base rate <x>% over <p> random pairs` (exact or near, fixed seed, p = `--pairs` 100000),
  `sig: control OK -- prefilter sound on <p> random pairs` (same pairs, true dist by unbanded bit-parallel
  Levenshtein; a prefilter rejection whose true ratio passes T, or a banded/true disagreement, fails).
- `--sample N`: deterministic N-function subset; dup groups cut to their members inside it.
- `--selftest`: `fixtures/functions.json` (our own words, G12): reloc-only pair exact, one-substitution pair near
  only, a permuted lookalike (passes the prefilter, ratio 0.8) not paired; banded vs bit-parallel on random sequences.
- Exit: 0 green; 1 exact pair missing, n != m, or control fail; 2 refused input. Stdlib only (multiprocessing fork).
- Wall time, full band (7905 functions, 4503 reps, 16 cores): ~11 s.
- Health: `make tools-selftest` runs `--selftest` (`sig: control OK -- ...`); `make tools-health` (end of `make check`)
  runs the full `band` (never `--sample`: draw reads `twins.jsonl` and a sample would overwrite it), asserting
  `sig: band reproduces k of k exact pairs` and a fresh `.run/sig/twins.jsonl`.

## L8: foreign (mmx4) leaves

    PY tools/sig/sig.py build-foreign --triple mmx4     # first: writes the leaf population
    PY tools/sig/sig.py build-foreign --triple x5
    PY tools/sig/sig.py foreign --objs .run/sig/mmx4/<triple>

- Source: `refs/mmx4/` (MMX4 decomp, AGPL-3.0, pinned 756987672dea). Only compiled into `.run/sig/mmx4/`;
  nothing is copied into `src/` or `include/`, no object or word leaves `.run/` (G12).
- `build-foreign`: every `refs/mmx4/src/main/**/*.c` → `.run/sig/mmx4/<triple>/<relpath>.o` (+ `.i .cc.s .s`, `.err`
  on failure; a failing file is logged on stderr, not fatal); prints `sig: build-foreign <ok> of <n> mmx4 files
  compiled [<triple>]`. Preprocessing: the host `cpp -undef -DSKIP_ASM=1 -DVERSION_US=1 -I refs/mmx4/src/snd
  -I refs/mmx4/include` + the triple's defines, as mmx4 itself does (build.py:149); `SKIP_ASM` empties `INCLUDE_ASM`
  (include/common.h:9). The psx cpps (2.7.2, 2.95.2) reject PsyQ 4.0's CRLF line continuations.
  Also compiles the control `src/slus/func_800132F8.c` under X5's pin (pin cpp, `-I include`) → `control.o`.
- Triples: `mmx4` = `gcc-2.7.2-psx` cc1 `-w -quiet -msoft-float -O2 -g0 -G0 -funsigned-char` (build.py:159),
  defines per build.py:71, maspsx `--aspsx-version=2.56 --expand-div`; `x5` = the pin (docs/ops/compiler-pin.md):
  `gcc-2.95.2-psx` cc1 `-O2 -G0 -quiet -w`, mk/slus.mk defines, maspsx `--aspsx-version=2.86`.
  Both: as `-EL -march=r3000 -no-pad-sections -G0`. mmx4's own cc1 is old-gcc 0.9 `gcc-2.7.2` (compiler.sh); the
  `-psx` build is used here (same version, Sony target banner).
- Leaf population (from `--triple mmx4` objects): STT_FUNC symbols in `.text`, ≤ 32 insns, no `jal`/`jalr` →
  `.run/sig/mmx4/leaves.json` `[{file, name}]`.
- `foreign`: each leaf's `.text` words by symbol, relocated fields zeroed, signed with the band's signature
  (sha1 of `dup_key` words); exact = equal signature with any fleet function; otherwise near against every fleet
  cluster rep with the band's T = 0.3 and floor 8. A leaf whose `.o` or symbol is absent counts `not compiled` (G35).
  Prints `sig: foreign <n> of <m> mmx4 leaves signed [<triple>]` (`, <k> not compiled`),
  `sig: L8 exact <a> hits, near <b> [<triple>]` (a = leaves with an exact hit, b = leaves with no exact hit and ≥ 1
  near rep), `sig: control OK -- ...` when control.o's `func_800132F8` hits slus 800132F8 exactly, else exit 1.
  Writes `<objs>/hits.jsonl` `{mmx4: {file, name, insns}, fleet: {alias, name, vram}, tier, dist[, members]}`
  (exact: one row per fleet member; near: one row per rep, `members` = its cluster size).
- Exact hits include trivial bodies (2 insns: 94 per triple); read by size, not by count alone.
