# rockx5.mk — ROCK_X5.BIN extras over mk/slus.mk (read first: mk/*.mk sorts rockx5 < slus).
# All-asm overlays embed data words that spimdisasm decodes as MIPS II-IV ops (beql, dsll32, movn, tge...);
# r3000 gas rejects them, mips4 assembles the same words. Encoding is fixed, so bytes are unchanged (sha-checked).
# Exe symbols: split names exe addresses from build/rockx5/exe_syms.txt (the exe ELF's globals); splat's auto files
# lose their exe-range lines; link takes the exe ELF as --just-symbols, so exe refs keep exe names (T4).
# Region placement: SPLIT_POST rewrites the splat ld's segment vrams 0x800EE970/0x800FA000 to the exe's ovlA_VRAM/
# ovlB_VRAM (config/symbols.slus.txt, in-section via config/shift/ovl_syms.ld), so regions follow the exe (T4.1).
ifeq ($(BINARY),rockx5)
AS_MARCH := mips4
# Every link goes through tools/shift/pad_ld.py (region-bound ASSERTs); overlay pad 0, SHIFT=1: SHIFT_OVL_PAD (mk/shift.mk).
PAD_LD := 1
LD_PAD = $(if $(SHIFT),$(SHIFT_OVL_PAD),0)
# SHIFT=1: link against the shifted exe (JUST_SYMS + exe_syms.ld from it); the split keeps the unshifted names.
JUST_SYMS := $(if $(SHIFT),$(SH),build)/slus/SLUS_013.34.just.elf
LINK_DEPS := $(if $(SHIFT),$(SH)/rockx5/exe_syms.txt)
SPLIT_DEPS := build/rockx5/exe_syms.txt
SPLIT_POST = for f in undefined_syms_auto undefined_funcs_auto; do \
	awk '!($$3 >= "0x80010000;" && $$3 < "0x800EE970;")' build/rockx5/$$f.txt > build/rockx5/$$f.tmp && \
	mv build/rockx5/$$f.tmp build/rockx5/$$f.txt || exit 1; done; \
	sed -i -E 's/^(    \.ovl[0-9]+) 0x800EE970 :/\1 ovlA_VRAM :/; s/^(    \.ovl[0-9]+) 0x800FA000 :/\1 ovlB_VRAM :/' build/rockx5/ROCK_X5.BIN.ld
# SHIFT two-pass (T8; PASS2=1 is the inner relink): exe->ovl names follow the shifted overlays. gen
# $(SH)/ovl_syms.ld from this link's map, keep the pass-1 exe, relink slus against it, check (tools/shift/ovl_syms.py),
# refresh .just.elf/exe_syms from the pass-2 exe, relink rockx5, check again against the pass-2 map.
ifneq ($(SHIFT),)
ifeq ($(PASS2),)
OVL_CHECK = $(PY) tools/shift/ovl_syms.py check --pass1 $(SH)/slus/SLUS_013.34.pass1.elf \
	--pass2 $(SH)/slus/SLUS_013.34.elf --map $(SH)/rockx5/ROCK_X5.BIN.map --pinned config/shift/ovl_syms.ld
LINK_POST = $(PY) tools/shift/ovl_syms.py gen --pinned config/shift/ovl_syms.ld \
	--map $(SH)/rockx5/ROCK_X5.BIN.map --out $(SH)/ovl_syms.ld && \
	cp $(SH)/slus/SLUS_013.34.elf $(SH)/slus/SLUS_013.34.pass1.elf && \
	$(MAKE) --no-print-directory link BINARY=slus SHIFT=1 OVL_SYMS=$(SH)/ovl_syms.ld && $(OVL_CHECK) && \
	rm -f $(SH)/slus/SLUS_013.34.just.elf $(SH)/rockx5/exe_syms.txt && \
	$(MAKE) --no-print-directory $(SH)/slus/SLUS_013.34.just.elf $(SH)/rockx5/exe_syms.txt BINARY=rockx5 SHIFT=1 && \
	$(MAKE) --no-print-directory link BINARY=rockx5 SHIFT=1 PASS2=1 && $(OVL_CHECK)
endif
endif
endif

# Exe ELF absent (fresh tree, carve/gate worktrees): build slus first; present, it is used as is.
build/slus/SLUS_013.34.elf:
	$(MAKE) --no-print-directory split BINARY=slus SHIFT= PATCHES= && $(MAKE) --no-print-directory build BINARY=slus SHIFT= PATCHES=

$(SH)/slus/SLUS_013.34.elf:
	$(MAKE) --no-print-directory split BINARY=slus SHIFT= PATCHES= && $(MAKE) --no-print-directory build BINARY=slus SHIFT=1

# .just.elf: the exe ELF with the rockx5 names of config/shift/ovl_syms.ld made local, so --just-symbols does not
# redefine what the overlays define (two-pass link, T4.1); ovlA/B_VRAM stay global (rockx5 places regions there).
%.just.elf: %.elf config/shift/ovl_syms.ld
	sed -n 's/^\([A-Za-z_][A-Za-z0-9_]*\) = 0x.*/\1/p' config/shift/ovl_syms.ld > $@.names
	$(OBJCOPY) --localize-symbols=$@.names $< $@

# exe_syms.txt (splat) + exe_syms.ld (link): tools/build/undef_by_name.py exe-syms.
build/rockx5/exe_syms.txt: build/slus/SLUS_013.34.elf
	@mkdir -p $(dir $@)
	$(PY) tools/build/undef_by_name.py exe-syms $< $@

$(SH)/rockx5/exe_syms.txt: $(SH)/slus/SLUS_013.34.elf
	@mkdir -p $(dir $@)
	$(PY) tools/build/undef_by_name.py exe-syms $< $@
