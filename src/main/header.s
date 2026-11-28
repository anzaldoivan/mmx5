# header.s — PS-X EXE header of SLUS_013.34 (0x800 bytes). Hand file: mk/slus.mk builds $(B)/slus/$(ASM)/slus/header.o
# from it in place of splat's generated $(ASM)/slus/header.s ($(CONFIG_V)/splat.slus.yaml segment `header`).
# Link-symbol words, so a shifted link stays self-consistent: pc0 (0x10) = __start, t_addr (0x18) = main_VRAM,
# t_size (0x1C) = main_ROM_END - 0x800 (image after the header). gp0 (0x14) is 0 in retail, kept as is.
# Every other byte (magic, s_addr, Sony string, pad) is .incbin'd from the retail exe: no game bytes in git.
# gas finds SLUS_013.34 through -I $(EXTRACTED) (mk/slus.mk ASFLAGS).
.section .data
.incbin "SLUS_013.34", 0x0, 0x10
.word __start
.incbin "SLUS_013.34", 0x14, 0x4
.word main_VRAM
.word main_ROM_END - 0x800
.incbin "SLUS_013.34", 0x20, 0x7E0
