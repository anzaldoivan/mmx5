# tools/sig

`sig.py` computes function signatures, the exact tier and the near (twin) band over the census inventory.

    PY tools/census/inventory.py && PY tools/census/census.py dup     # inputs
    PY tools/sig/sig.py band [--sample N] [--pairs P] [--seed S]
    PY tools/sig/sig.py --selftest

- The words come from `census.load()` (imported in place). The norm words are `census.dup_key(words)` (reloc fields
  masked). The signature is the sha1 hex of the norm words. An exact cluster is the functions with an equal signature.
  The rep of a cluster is its first member by key. The key of a function is (alias, vram, name) (G41).
- The near tier takes reps only. The value dist is the unit-cost Levenshtein over norm words. Two reps are near if and
  only if `dist / max(len) < T`, `T = 0.3` (DK-10 lookalike ratio), and `max(len) >= 8`. The last condition is the
  short-function floor: below 8 words, one differing word is a large share of the body. The floor is recorded, not
  tuned.
- The prefilter uses the length difference and the opcode histogram `(|la-lb| + L1) / 2`. Both are sound lower bounds
  on dist. The survivors go to a banded Levenshtein with cutoff `D = largest d with d/max < T`.
- The work weights are `work = indels + 3 * substitutions`. The alignment takes the min dist, then the fewest
  substitutions. Rows rank by work ascending, and ties rank by keys. Near pairs expand to `|A| * |B|` function pairs,
  which are never materialised.
- The output is `.run/sig/twins.jsonl`: `{a, b, tier: exact|near, dist, ratio, sig_a, sig_b, na, nb (insns), work}`.
  The exact tier has one row per member vs its rep. The near tier has one row per rep pair.
- `sig.py` prints these lines:
  - `sig: <n> of <m> functions signed`
  - `sig: band reproduces <r> of <e> exact pairs, +<k> near`. Here e is the sum of C(|g|,2) over the census dup
    groups. `sig.py` checks by key that each group sits in one signature cluster.
  - `sig: base rate <x>% over <p> random pairs`. The rate counts exact or near pairs. The seed is fixed, and p =
    `--pairs` 100000.
  - `sig: control OK -- prefilter sound on <p> random pairs`. The control uses the same pairs and the true dist by
    unbanded bit-parallel Levenshtein. The control fails on a prefilter rejection whose true ratio passes T, or on a
    banded/true disagreement.
- `--sample N` takes a deterministic N-function subset. It cuts the dup groups to their members inside the subset.
- `--selftest` uses `fixtures/functions.json` (our own words, G12). A reloc-only pair must be exact, and a
  one-substitution pair must be near only. A permuted lookalike (passes the prefilter, ratio 0.8) must not be paired.
  The selftest also compares banded vs bit-parallel on random sequences.
- Exit 0 means green. Exit 1 means an exact pair missing, n != m, or a control fail. Exit 2 means a refused input.
  `sig.py` uses the stdlib only (multiprocessing fork).
- The wall time of the full band (7905 functions, 4503 reps, 16 cores) is ~11 s.
- Health: `make tools-selftest` runs `--selftest` (`sig: control OK -- ...`). `make tools-health` (end of
  `make check`) runs the full `band`. It never runs `--sample`, because draw reads `twins.jsonl` and a sample would
  overwrite it. It asserts `sig: band reproduces k of k exact pairs` and a fresh `.run/sig/twins.jsonl`.

## L8: foreign (mmx4) leaves

    PY tools/sig/sig.py build-foreign --triple mmx4     # first: writes the leaf population
    PY tools/sig/sig.py build-foreign --triple x5
    PY tools/sig/sig.py foreign --objs .run/sig/mmx4/<triple>

- The source is `refs/mmx4/` (MMX4 decomp, AGPL-3.0, pinned 34f37a46f34a). The L8 counts in `docs/prior-art.md` were
  measured at 756987672dea. `sig.py` only compiles the source into `.run/sig/mmx4/`. It copies nothing into `src/`
  or `include/`, and no object or word leaves `.run/` (G12).
- `build-foreign` compiles every `refs/mmx4/src/main/**/*.c` to `.run/sig/mmx4/<triple>/<relpath>.o` (+ `.i .cc.s .s`,
  `.err` on failure). It logs a failing file on stderr, and that failure is not fatal. It prints
  `sig: build-foreign <ok> of <n> mmx4 files compiled [<triple>]`.
  - Preprocessing uses the host `cpp -undef -DSKIP_ASM=1 -DVERSION_US=1 -I refs/mmx4/src/snd -I refs/mmx4/include` +
    the triple's defines, as mmx4 itself does (build.py:149). `SKIP_ASM` empties `INCLUDE_ASM` (include/common.h:9).
    The psx cpps (2.7.2, 2.95.2) reject PsyQ 4.0's CRLF line continuations.
  - `build-foreign` also compiles the control `src/slus/func_800132F8.c` under X5's pin (pin cpp, `-I include`) to
    `control.o`.
- The triples are `mmx4` and `x5`. `mmx4` is `gcc-2.7.2-psx` cc1 `-w -quiet -msoft-float -O2 -g0 -G0 -funsigned-char`
  (build.py:159), the defines per build.py:71 and maspsx `--aspsx-version=2.56 --expand-div`. `x5` is the pin
  (docs/ops/compiler-pin.md): `gcc-2.95.2-psx` cc1 `-O2 -G0 -quiet -w`, the mk/slus.mk defines and maspsx
  `--aspsx-version=2.86`. Both triples use as `-EL -march=r3000 -no-pad-sections -G0`. The own cc1 of mmx4 is old-gcc
  0.9 `gcc-2.7.2` (compiler.sh). `sig.py` uses the `-psx` build here (same version, Sony target banner).
- The leaf population is the STT_FUNC symbols in `.text` with ≤ 32 insns and no `jal`/`jalr`, from the
  `--triple mmx4` objects. It goes to `.run/sig/mmx4/leaves.json` as `[{file, name}]`.
- `foreign` takes each leaf's `.text` words by symbol, with the relocated fields zeroed. It signs the words with the
  band's signature (sha1 of `dup_key` words). A leaf is exact when it has an equal signature with any fleet function.
  Otherwise, `foreign` tests it for near against every fleet cluster rep with the band's T = 0.3 and floor 8. A leaf
  whose `.o` or symbol is absent counts `not compiled` (G35).
  - `foreign` prints `sig: foreign <n> of <m> mmx4 leaves signed [<triple>]` (`, <k> not compiled`).
  - `foreign` prints `sig: L8 exact <a> hits, near <b> [<triple>]`. Here a counts the leaves with an exact hit. Here b
    counts the leaves with no exact hit and ≥ 1 near rep.
  - `foreign` prints `sig: control OK -- ...` when control.o's `func_800132F8` hits slus 800132F8 exactly. Otherwise
    `foreign` exits 1.
  - `foreign` writes `<objs>/hits.jsonl`
    `{mmx4: {file, name, insns}, fleet: {alias, name, vram}, tier, dist[, members]}`. An exact hit has one row per
    fleet member. A near hit has one row per rep, and `members` is its cluster size.
- Exact hits include trivial bodies (2 insns: 94 per triple). Read the hits by size, not by count alone.

## X4 core and adapter: partners and names from sozud/mmx4

```sh
PY tools/sig/x4adapter.py --partners [--jobs N]     # clone at the pin, compile, docs/oracle/x4-partners.tsv
PY tools/sig/x4adapter.py --build                   # docs/oracle/x4-names.tsv
PY tools/sig/x4adapter.py --widen                   # + same-name rows
PY tools/sig/x4adapter.py --doc                     # docs/oracle/x4-names.md
PY tools/sig/x4adapter.py --who <alias text | func_8XXXXXXX | UNIT:0xVRAM>
PY tools/sig/x4adapter.py --ghidra --out <scratch jsonl> [--in <annotations jsonl>]
PY tools/sig/x4core.py --selftest | parity --other <mmx6's x4core.py> | xref --a <X6 partners> --b <X5 partners>
```

- `x4core.py` is the core shared with the X6 decompilation. It has the same bytes as that project's
  `tools/mmx6/x4core.py`. `parity` compares the core sha256, the pin and the table schema. A change here is made in
  both repositories or not at all.
  - The core knows mmx4 and the tables, never a game. It holds the pin (`config/refs.toml` `[[ref]] name = "mmx4"`),
    the exact-commit clone, mmx4's US C file set and its one-file compile recipe.
  - It also holds the ELF reader, the key (sha1 of the words under the mmx4 object's relocation mask) and the partner
    table.
  - It also holds names admission and tiers, widening, the doc, `xref` and the plate-comment lines.
  - `--selftest` runs on synthetic objects (no compiler, no clone, no game data) and ends `x4core: control OK`. It is
    in `make tools-selftest`.
- `x4adapter.py` is mmx5's side and the CLI.
  - It uses the triple `x5` of `sig.TRIPLES` (`-O2 -G0`, maspsx `--aspsx-version=2.86`, no `--expand-div`).
  - It clones `refs/mmx4`. Its objects and logs are under `.run/x4/`. The game's functions come from `census.load()`.
  - With `X4_TREE=<another checkout>`, the adapter reads every input there (inventory, expected bytes, toolchain,
    annotations). The read is read only, and the adapter repeats a read when a file changed under it. The outputs
    always land in this checkout.
- Match: `--partners` reads no game objects. So `census.dup_key` picks the mmx4 candidates, and `x4core.confirmed` keys
  the game words under each candidate's own relocation mask. The result is an undercount, never a false row: a LO16
  site that the heuristic does not mask.
- The tables are tab-separated and have no header. They hold names, addresses, keys and mmx4 paths only (G12).
  - `x4-partners.tsv` is `unit, 0xVRAM, name, words, key, mmx4 path, mmx4 function, partners, state`. It has one row
    per X5 function with a partner: the first partner and the count.
  - `x4-names.tsv` is `unit, 0xVRAM, kind, name, alias, tier, scope, votes, basis`.
  - The unit is `slus` or `ovlNN`. Tier `gate` means state `c`. Tier `bytes` means that the function is still
    assembly.
  - Admission needs a real mmx4 name, one partner or partners that all carry one name, and >= 8 words. An alias is a
    search key, never a rename.
- Tier `slot` gives names for globals and callees from relocation-slot votes. `--widen` reads the built game object
  (`build/<alias>/src/…` or `asm/…` `.o`) of each anchor with `propagate.relocs`. It pairs each relocation with the
  mmx4 twin's at the same word (`x4core.pair`). A game symbol's address comes from its `func_`/`D_`/`jtbl_`
  spelling, else `config/symbols.<alias>.txt`. Its program is `slus` inside the executable's range, else the
  anchor's overlay. Without `build/slus/SLUS_013.34.elf` it prints `X4NAMES slot lane unavailable`.
  - A slot name is a lead, never a rename.
  - `x4adapter.py --selftest` runs the lane on a hand-written asm fixture (`fixtures/x4slot/`, the pinned assembler)
    and a synthetic mmx4 object. An agreeing slot is admitted, a two-name slot refused. It ends
    `x4adapter: control OK -- …` and is in `make tools-selftest`.
- `--ghidra` merges the aliases as plate-comment lines into a copy of `docs/oracle/annotations.jsonl`
  (`{"addr","ctype":"plate","kind":"comment","text"}`).
  - The adapter appends an alias to an existing plate comment. It keeps the exporter line order and every other
    record byte-for-byte.
  - The output is scratch only. Test it with `ANN_IN=<file> bash tools/ghidra/roundtrip.sh`.
- `sig.py foreign` (above) stays the historical L8 leaf measure. The two tools do not share objects.
- The AGPL-3.0 source is compiled into `.run/x4/` only. No mmx4 code, object or word reaches a tracked file.

## X5/X6 tables and the map of a prototype: `--xref`, `imgtab.py` and `tools/psxd_img.py`

```
PY tools/sig/x4adapter.py --xref --other <mmx6>/campaign/x4/partners.tsv      # docs/oracle/x4-xref.tsv
PY tools/sig/imgtab.py x6 --functions <X6 functions.jsonl> --x6-root <mmx6> [--retail <dir>] [--leads]
PY tools/sig/imgtab.py units [--retail <dir>]                                  # config/oracle.units.tsv
PY tools/sig/imgtab.py --selftest
PY tools/psxd_img.py proto --id proto-2000-07-28 --build <dir> --exe ROCKX5.EXE [--retail <dir>]
PY tools/psxd_img.py strnames [--proto proto-2000-07-28:<dir>:ROCKX5.EXE] [--check] [--retail <dir>]
PY tools/psxd_img.py show <key> | promote <unit> <vram> <name> | --self-test
```

- Inputs. `--retail <dir>` is a folder with `SLUS_013.34` and `ROCK_X5.BIN`. Write it with
  `tools/extract/extract.py --out .run/imgtab/retail --cue <cue>`. `config/oracle.retail` names that folder.
- `<mmx6>` is a checkout of the X6 decompilation with its `extracted/retail/` files and `config/loadmap.txt`. Its
  function list is `build/corpus/functions.jsonl`. A prototype's files come from the extractor too, under the same
  file names (`.run/imgtab/<id>/`). Every such file stays in an ignored path.
- `--xref` (through X4) runs `x4core.parity` first (core sha256, pin, schema). A difference refuses. Then it runs
  `x4core.xref` on both partner tables. It writes only the `single` rows (`x4core.SCHEMA["xref"]`). A `multi` row is
  counted, not written. A row is a lead "same source function".
- `imgtab.py x6` searches each X6 function of lane `game` with >= 8 words in every X5 unit (`slus`, `ovlNN`). A hit
  has the same `census.dup_key` over the full length. `x6-twins.tsv` has one row per class member:
  `key, words, game, unit, 0xVRAM, name, state`. X5's state is `c` at a `c` subsegment of the splat configurations,
  else `asm`. X6's state is its list's.
- A twin is a lead for the C, and the byte gate proves it. The two games have different flags, so a donor's C can
  compile to other bytes. An X5 hit has the name `-` when no `c` subsegment and no partner row names the address.
- `--leads` also writes `docs/oracle/x6-leads.tsv` (X5 asm member, X6 donor in C) and `docs/oracle/x5-leads.tsv` (the
  reverse, for mmx6's `campaign/x4/`). Columns: taker unit, `0xVRAM`, name, words, donor unit, `0xVRAM`, name, the
  donor's C path in its checkout, `donor=taker;...`. The donor needs a C definition: a `c` subsegment that still holds
  `INCLUDE_ASM` is no donor. The map renames the function, then each relocated field that the donor's C file names
  (spelled as that file spells it under its `#define` renames).
- A lead target with no symbol gets its default splat name. X6's splat can spell one as `<base> + <off>`, so the row is
  a lead and the gate proves it. `waves.py card` puts the X6 row on the card (`## Twin in X6`). The C is fetched with
  `bash tools/refs_fetch.sh mmx6` (`config/refs.toml`).
- `tools/psxd_img.py` is psxdecomp's map core. `/psxdecomp:upgrade` delivers it, and this repository does not edit
  it. Its header states the mask, the map, the string rows and `strnames`. `imgtab.py` imports it and refuses to load
  when its `LO_OPS` is not `census.LO_OPS`.
- `imgtab.py units` writes `config/oracle.units.tsv`, the contract of `psxd_img.py`. It holds `slus` after the
  executable's header. It also holds each code overlay `ovlNN` of `loadmap.json`, at its offset in `ROCK_X5.BIN`. mmx5 writes no function
  list (`.run/oracle/functions.tsv`). So `strnames` finds each start by a scan, and `proto` writes no functions table.
- The tables: `config/oracle.proto-2000-07-28.{map,strings}.tsv`, `config/oracle.strnames.tsv` and
  `config/oracle.strnames.aliases.tsv` (written by hand). Each has two `#` lines. They hold keys, addresses and
  counts only (G12). The text goes to `.run/oracle/<id>/strings.txt` and `.run/strnames/strings.txt`. `show <key>`
  prints it.
- An alias is a search key, never a rename. No alias for SDK code, for a byte table, or for a text that says nothing
  of the work. `psxd_img.py promote` writes one `provisional` row of `config/names.tsv` with the evidence
  `string:config/oracle.strnames.tsv:<line>` (NAME1).
- On 2026-10-14 the tables moved from `docs/oracle/` to `config/`. `psxd_img.py` regenerated them with data rows
  byte-equal to those of the earlier `imgcore.py` and `imgtab.py`. `psxd_img: strnames: 107 functions, 232 references
  (direct 148, table 84), retail 107, builds 2, 107 start by scan` (`--proto proto-2000-07-28`). 8 aliases.
