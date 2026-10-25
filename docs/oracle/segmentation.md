# Segmentation proposal (T6)

The generated list is `docs/oracle/segments.txt`. The command `tools/build/propose_segments.py --write` writes it.
The option `--check` validates the list and exits with 0 or 1. The option `--segments <path>` checks another file.

The inputs are `boundaries.txt`, `loadmap.json`, `annotations.jsonl` and `asm/<alias>`
(`make split BINARY=<alias>`). This proposal holds addresses and names only (G12).

## Rule
- A libobj span (boundaries.txt) is one TU (`libobj`). A span that ends mid-function runs to the next function start.
- A gap between adjacent libobj spans is one `libgap` TU.
- The tool cuts game text at padding indicators. Game text is the exe from 0x80011DC8 outside libobj, and the text of
  each code overlay. The padding indicators are: `jr $ra` + delay slot, >= 1 extra `nop`, next glabel 8-aligned.
- Each overlay has >= 1 TU (`overlay`). Overlay text starts at the first function start at or after the last
  jumptable of the overlay. Rodata heads the overlay.
- The function starts are `glabel` (not `D_`/`jtbl_`) ∪ annotation functions ∪ libobj starts ∪ jumptable owner starts.
- A jumptable goes to the TU whose text holds the start of its owner. Rodata order means that the jumptables of the
  TUs increase in text order. The tool drops a cut that breaks this order and merges the TUs.

## Counts per alias
2.3 T5 refreshed these counts from `--write`. There are yaml cuts since T6. The counts were stale per 2.3 T4.
- The alias slus has 582 TUs: game 377, libobj 180, libgap 25. The tool kept 0 padding cuts. The game cuts equal the
  yaml cuts (build truth). There are 0 dropped cuts.
- The alias rockx5 has 1358 TUs: overlay 1358. There is >= 1 TU for each disassembled code overlay. The rest are yaml
  cuts. There are 0 padding cuts. There are 0 dropped cuts.
- Indicator on libobj (validation): 180 libobj starts have a parsed predecessor. 121 predecessors end unaligned, and
  74 of them show padding. 59 predecessors end 8-aligned. The ~125 extra-nop sites in `asm/slus/25C8.s` are in the
  libobj range.

## Judgment calls
- There are 61 unresolved computed jumps (`jr <reg>`, reg != ra, not a jumptable's `jr`). The alias slus has 52:
  1 game `80014790`, 51 in the libobj/libgap range. The alias rockx5 has 9: `ovl00:800F1760`, `ovl05:800F18C8`,
  `ovl10:800EED2C`, `ovl30:800FB628`, `ovl32:800FD7CC`, `ovl35:800FC8D0`, `ovl38:800FB104`, `ovl39:800FB4F8`,
  `ovl39:800FBF24`. The full list is the `#` lines in segments.txt. The tool does not scan overlay code that
  spimdisasm typed as `.word`.
- There are 25 gaps of unowned rodata between TU jumptable groups, 3076 bytes. This rodata is not assigned. There are
  0 rodata order violations.
- crt0: pc0 8005894C sits inside libobj 2MBYTE.OBJ 80058944-80058A08, which is the PsyQ startup. The proposal keeps
  it as that libobj TU.
- LIBAPI.LIB/C112.OBJ and LIBCARD.LIB/C112.OBJ match libobj span 8006BDA8-8006BDB8. The span is one TU (first name).
- These libobj spans end mid-function, and the tool extended the TU: INTR_DMA.OBJ 80063AD8->80063AEC, C73.OBJ
  8006C2C8->8006C2D0.
- The libgap TUs (25) are unmatched code between libobj spans. Each gap is one TU and is not cut.
- Padding only shows a boundary where the prior function ends unaligned (libobj: 74/122), so the game TU count is a
  lower bound. The slus game TUs here (377) come from yaml cuts only.
- The data/bss is not segmented yet.
- The excluded overlays are data overlays 13/15/17/19 (bin in splat). Overlays 38/39 (null dest) are now segmented.

## Alternatives
- A is libobj-only coarse (game text is one TU). A is the cheapest. A ≈ B today since padding yields 1 cut.
- B is this proposal: padding cuts + rodata-order merge. B has boundaries only where alignment exposes them.
- C is one function per TU. C gives the maximum granularity. C breaks static/rodata sharing and order, and needs many
  link-order fixes.
- D is rodata-gap indicators (cut where jumptable/const rodata groups have gaps). D gives more game cuts. D needs
  const-rodata ownership first (unowned rodata is unresolved).
