# Segmentation proposal (T6)

Generated list: `docs/oracle/segments.txt` (`tools/build/propose_segments.py --write`; `--check` validates, exit 0/1;
`--segments <path>` checks another file). Inputs: `boundaries.txt`, `loadmap.json`, `annotations.jsonl`, `asm/<alias>`
(`make split BINARY=<alias>`). Addresses/names only (G12).

## Rule
- libobj span (boundaries.txt) = one TU (`libobj`). A span ending mid-function runs to the next function start.
- gap between adjacent libobj spans = one `libgap` TU.
- game text (exe 0x80011DC8.. outside libobj; each code overlay's text) is cut at padding indicators: `jr $ra` + delay
  slot, >= 1 extra `nop`, next glabel 8-aligned. Each overlay >= 1 TU (`overlay`); overlay text starts at the first
  function start at/after its last jumptable (rodata heads the overlay).
- function starts = `glabel` (not `D_`/`jtbl_`) ∪ annotation functions ∪ libobj starts ∪ jumptable owner starts.
- jumptable -> TU whose text holds its owner's start. Rodata order: TUs' jumptables increase in text order; a cut that
  breaks it is dropped (TUs merged).

## Counts per alias
- slus: 211 TUs = game 6, libobj 180, libgap 25. Padding cuts kept 0 (game cuts = yaml cuts, build truth). Dropped
  cuts: 0.
- rockx5: 92 TUs = overlay 92 (>= 1 per asm'd code overlay; the rest yaml cuts). Padding cuts: 0. Dropped cuts: 0.
- Indicator on libobj (validation): 181 libobj starts with a parsed predecessor; 122 predecessors end unaligned, 74 of
  them show padding; 59 end 8-aligned. The ~125 extra-nop sites in `asm/slus/25C8.s` are in the libobj range.

## Judgment calls
- Unresolved computed jumps (`jr <reg>`, reg != ra, not a jumptable's `jr`): 58 (slus 52: 1 game `80014790`, 51 in the
  libobj/libgap range; rockx5 6: `ovl00:800F1760`, `ovl05:800F18C8`, `ovl10:800EED2C`,
  `ovl30:800FB628`, `ovl32:800FD7CC`, `ovl35:800FC8D0`). Full list: `#` lines in segments.txt. Overlay code that
  spimdisasm typed as `.word` is not scanned.
- Unowned rodata between TU jumptable groups: 4 gaps, 2380 bytes; not assigned. Rodata order violations: 0.
- crt0: pc0 8005894C sits inside libobj 2MBYTE.OBJ 80058944-80058A08 = PsyQ startup; kept as that libobj TU.
- libobj span 8006BDA8-8006BDB8 matched by LIBAPI.LIB/C112.OBJ and LIBCARD.LIB/C112.OBJ: one TU (first name).
- libobj spans ending mid-function, TU extended: INTR_DMA.OBJ 80063AD8->80063AEC, C73.OBJ 8006C2C8->8006C2D0.
- libgap TUs (25): unmatched code between libobj spans; one TU each, not cut.
- Padding only shows a boundary where the prior function ends unaligned (libobj: 74/122), so the game TU count is a
  lower bound; slus game TUs here (6) come from yaml cuts only.
- data/bss not segmented yet.
- Excluded overlays: 38/39 (null dest), data overlays 13/15/17/19 (bin in splat).

## Alternatives
- A libobj-only coarse (game text one TU): cheapest; ≈ B today since padding yields 1 cut.
- B this proposal: padding cuts + rodata-order merge; boundaries only where alignment exposes them.
- C one function per TU: max granularity; breaks static/rodata sharing and order, many link-order fixes.
- D rodata-gap indicators (cut where jumptable/const rodata groups have gaps): more game cuts; needs const-rodata
  ownership first (unowned rodata unresolved).
