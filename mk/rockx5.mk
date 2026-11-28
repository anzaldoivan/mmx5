# ROCK_X5.BIN extras over mk/main.mk (read first: mk/*.mk sorts rockx5 < main).
# All-asm overlays embed data words that spimdisasm decodes as MIPS II-IV ops (beql, dsll32, movn, tge...);
# r3000 gas rejects them, mips4 assembles the same words. Encoding is fixed, so bytes are unchanged (sha-checked).
# Exe symbols: split names exe addresses from $(B)/rockx5/exe_syms.txt (the exe ELF's globals); splat's auto files
# lose their exe-range lines; link takes the exe ELF as --just-symbols, so exe refs keep exe names.
# Region placement: SPLIT_POST rewrites the splat ld's segment vrams 0x800EE970/0x800FA000 to the exe's g_ovl_a_vram/
# g_ovl_b_vram ($(CONFIG_V)/symbols.main.txt, in-section via $(CONFIG_V)/shift/ovl_syms.ld), so regions follow the exe.
ifeq ($(BINARY),rockx5)
AS_MARCH := mips4
# include/mmx5/ovl.h: a C unit in an ovlNN folder compiles with -DOVL_ID=NN (its $< folder; tools: layout.ovl_cppflags).
OVL_CPPFLAGS = $(patsubst ovl%,-DOVL_ID=%,$(filter ovl%,$(subst /, ,$(dir $<))))
# Every link goes through tools/shift/pad_ld.py (region-bound ASSERTs); overlay pad 0, SHIFT=1: SHIFT_OVL_PAD (mk/shift.mk).
PAD_LD := 1
LD_PAD = $(if $(SHIFT),$(SHIFT_OVL_PAD),0)
# SHIFT=1: link against the shifted exe (JUST_SYMS + exe_syms.ld from it); the split keeps the unshifted names.
JUST_SYMS := $(if $(SHIFT),$(SH),$(B))/$(MAIN)/SLUS_013.34.just.elf
LINK_DEPS := $(if $(SHIFT),$(SH)/rockx5/exe_syms.txt)
SPLIT_DEPS := $(B)/rockx5/exe_syms.txt
SPLIT_POST = for f in undefined_syms_auto undefined_funcs_auto; do \
	awk '!($$3 >= "0x80010000;" && $$3 < "0x800EE970;")' $(B)/rockx5/$$f.txt > $(B)/rockx5/$$f.tmp && \
	mv $(B)/rockx5/$$f.tmp $(B)/rockx5/$$f.txt || exit 1; done; \
	sed -i -E 's/^(    \.ovl[0-9]+) 0x800EE970 :/\1 g_ovl_a_vram :/; s/^(    \.ovl[0-9]+) 0x800FA000 :/\1 g_ovl_b_vram :/' $(B)/rockx5/ROCK_X5.BIN.ld
# SHIFT two-pass (PASS2=1 is the inner relink): exe->ovl names follow the shifted overlays. gen
# $(SH)/ovl_syms.ld from this link's map, keep the pass-1 exe, relink main against it, check (tools/shift/ovl_syms.py),
# refresh .just.elf/exe_syms from the pass-2 exe, relink rockx5, check again against the pass-2 map.
ifneq ($(SHIFT),)
ifeq ($(PASS2),)
OVL_CHECK = $(PY) tools/shift/ovl_syms.py check --pass1 $(SH)/$(MAIN)/SLUS_013.34.pass1.elf \
	--pass2 $(SH)/$(MAIN)/SLUS_013.34.elf --map $(SH)/rockx5/ROCK_X5.BIN.map --pinned $(CONFIG_V)/shift/ovl_syms.ld
LINK_POST = $(PY) tools/shift/ovl_syms.py gen --pinned $(CONFIG_V)/shift/ovl_syms.ld \
	--map $(SH)/rockx5/ROCK_X5.BIN.map --out $(SH)/ovl_syms.ld && \
	cp $(SH)/$(MAIN)/SLUS_013.34.elf $(SH)/$(MAIN)/SLUS_013.34.pass1.elf && \
	$(MAKE) --no-print-directory link BINARY=$(MAIN) SHIFT=1 OVL_SYMS=$(SH)/ovl_syms.ld && $(OVL_CHECK) && \
	rm -f $(SH)/$(MAIN)/SLUS_013.34.just.elf $(SH)/rockx5/exe_syms.txt && \
	$(MAKE) --no-print-directory $(SH)/$(MAIN)/SLUS_013.34.just.elf $(SH)/rockx5/exe_syms.txt BINARY=rockx5 SHIFT=1 && \
	$(MAKE) --no-print-directory link BINARY=rockx5 SHIFT=1 PASS2=1 && $(OVL_CHECK)
endif
endif
endif

# Exe ELF absent (fresh tree, carve/gate worktrees): build main first; present, it is used as is.
$(B)/$(MAIN)/SLUS_013.34.elf:
	$(MAKE) --no-print-directory split BINARY=$(MAIN) SHIFT= PATCHES= && $(MAKE) --no-print-directory build BINARY=$(MAIN) SHIFT= PATCHES=

$(SH)/$(MAIN)/SLUS_013.34.elf:
	$(MAKE) --no-print-directory split BINARY=$(MAIN) SHIFT= PATCHES= && $(MAKE) --no-print-directory build BINARY=$(MAIN) SHIFT=1

# .just.elf: the exe ELF with the rockx5 names of $(CONFIG_V)/shift/ovl_syms.ld made local, so --just-symbols does not
# redefine what the overlays define (two-pass link); ovlA/B_VRAM stay global (rockx5 places regions there).
%.just.elf: %.elf $(CONFIG_V)/shift/ovl_syms.ld
	sed -n 's/^\([A-Za-z_][A-Za-z0-9_]*\) = 0x.*/\1/p' $(CONFIG_V)/shift/ovl_syms.ld > $@.names
	$(OBJCOPY) --localize-symbols=$@.names $< $@

# exe_syms.txt (splat) + exe_syms.ld (link): tools/build/undef_by_name.py exe-syms.
$(B)/rockx5/exe_syms.txt: $(B)/$(MAIN)/SLUS_013.34.elf
	@mkdir -p $(dir $@)
	$(PY) tools/build/undef_by_name.py exe-syms $< $@

$(SH)/rockx5/exe_syms.txt: $(SH)/$(MAIN)/SLUS_013.34.elf
	@mkdir -p $(dir $@)
	$(PY) tools/build/undef_by_name.py exe-syms $< $@
