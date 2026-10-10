# rockx5.mk — ROCK_X5.BIN extras over mk/slus.mk (read first: mk/*.mk sorts rockx5 < slus).
# All-asm overlays embed data words that spimdisasm decodes as MIPS II-IV ops (beql, dsll32, movn, tge...);
# r3000 gas rejects them, mips4 assembles the same words. Encoding is fixed, so bytes are unchanged (sha-checked).
ifeq ($(BINARY),rockx5)
AS_MARCH := mips4
endif
