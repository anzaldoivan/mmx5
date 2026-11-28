# Asm + C build of one binary: `make split build BINARY=<alias>`.
# split: splat $(CONFIG_V)/splat.<alias>.yaml -> $(ASM)/<alias>/ + $(B)/<alias>/<name>.ld (both ignored). The yaml holds
#        literal paths (build/us/...); tools/build/splat_root.py moves them under BUILD_ROOT before splat reads them.
# build: as each .s, cpp|cc1|maspsx|as each .c -> ld (splat script) -> objcopy -O binary -> sha1sum -c config/check.$(VERSION).<alias>.sha (fails on mismatch).

.PHONY: split build link

BINARY ?= $(MAIN)
SPLAT ?= .venv/bin/python tools/build/splat_root.py
AS := tools/bin/mipsel-linux-gnu-as
LD := tools/bin/mipsel-linux-gnu-ld
OBJCOPY := tools/bin/mipsel-linux-gnu-objcopy
# AS_MARCH: per-alias override in mk/<alias>.mk
AS_MARCH ?= r3000
ASFLAGS := -EL -march=$(AS_MARCH) -mtune=r3000 -no-pad-sections -G0 -I $(ASM)/$(BINARY)/include -I $(EXTRACTED)

B_NAME = $(shell sed -n 's/^name: *//p' $(CONFIG_V)/splat.$(BINARY).yaml)
# SHIFT=1 (mk/shift.mk): objects/ELF in $(B)/shift/<alias>/ (PATCHES=<n>: $(B)/shift-<n>/, mk/patches.mk);
# split outputs (ld, auto files) stay in S_DIR.
B_DIR := $(if $(SHIFT),$(SH),$(B))/$(BINARY)
S_DIR := $(B)/$(BINARY)
# $(ASM)/<alias>/nonmatchings/: INCLUDE_ASM bodies of carved c subsegments, assembled through their .c, not alone.
B_ASM = $(shell find $(ASM)/$(BINARY) -name '*.s' -not -path '*/nonmatchings/*' 2>/dev/null)
# bin segments (splat asset_path $(ASSETS)/<alias>); *.textbin.bin are .incbin'd by their .s, not linked.
B_BIN = $(filter-out %.textbin.bin,$(shell find $(ASSETS)/$(BINARY) -name '*.bin' 2>/dev/null))
B_OBJ = $(patsubst %.s,$(B_DIR)/%.o,$(B_ASM)) $(patsubst %.bin,$(B_DIR)/%.o,$(B_BIN))

# C: splat `c` subsegments, src/<alias>/<name>.c -> $(B)/<alias>/src/<alias>/<name>.o (the ld script's path).
# Triple pinned in docs/ops/compiler-pin.md ## Pin. CC_ASFLAGS stays r3000 whatever AS_MARCH is (mk/rockx5.mk).
CC_DIR := tools/bin/cc/gcc-2.95.2-psx
CPP := $(CC_DIR)/cpp
CC1 := $(CC_DIR)/cc1
MASPSX := python3 refs/maspsx/maspsx.py --aspsx-version=2.86
CPPFLAGS := -lang-c -D__GNUC__=2 -Dmips -D__mips__ -Dpsx -D__psx__ -D_MIPSEL -D__CHAR_UNSIGNED__ -D__OPTIMIZE__ -I include -I src
CFLAGS := -O2 -G0 -quiet -w
CC_ASFLAGS := -EL -march=r3000 -no-pad-sections -G0 -I $(ASM)/$(BINARY)/include
B_C = $(shell find src/$(BINARY) -name '*.c' 2>/dev/null)
B_OBJ += $(patsubst %.c,$(B_DIR)/%.o,$(B_C))
# DEPFILE: a recipe line, run after cpp wrote $@.dt (also used by mk/patches.mk).
DEPFILE = sed '1s|^[^:]*:|$@:|' $@.dt > $(@:.o=.d) && sed 's/^[^:]*://; s/\\$$//' $@.dt | tr -s ' ' '\n' | grep . | tail -n +2 | sed 's/$$/:/' >> $(@:.o=.d); rm -f $@.dt

# SPLIT_DEPS / SPLIT_POST / JUST_SYMS: per-alias hooks (mk/rockx5.mk: exe symbols).
# rm $(ASM)/<alias> first: splat never deletes a .s whose sub a yaml edit removed or retyped, and B_ASM globs $(ASM)/, so a
# stale dlabel object fed undef_by_name a definition the ld script never links.
split: $(SPLIT_DEPS)
	rm -rf $(ASM)/$(BINARY)
	$(SPLAT) split $(CONFIG_V)/splat.$(BINARY).yaml
	$(SPLIT_POST)

$(B_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

# Hand asm src/<alias>/<seg>.s replaces splat's generated $(ASM)/<alias>/<seg>.s (shorter stem wins over the rule above).
# main: header.s (pc0/t_addr/t_size as link symbols), game_80013348.s (lui/ori pair relocated).
$(B_DIR)/$(ASM)/$(BINARY)/%.o: src/$(BINARY)/%.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

# Depfile: the pinned cpp takes only `-MMD <file>` (-MT/-MF exit 33; stdout stays cmp-equal) and names the target
# `<basename>.o`; sed retargets it to $@ into $(@:.o=.d), plus one empty rule per header/shared body (what -MP gives).
# OVL_CPPFLAGS: mk/rockx5.mk (-DOVL_ID=NN of an ovlNN unit); undefined, so empty, for main.
$(B_DIR)/%.o: %.c $(wildcard include/*.h)
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) $(VERSION_CPPFLAGS) $(OVL_CPPFLAGS) -MMD $@.dt $< | $(CC1) $(CFLAGS) | $(MASPSX) | $(AS) $(CC_ASFLAGS) -o $@
	@$(DEPFILE)

$(B_DIR)/%.o: %.bin
	@mkdir -p $(dir $@)
	$(OBJCOPY) -I binary -O elf32-tradlittlemips -B mips $< $@

# build re-enters make so the object list is read after a split in the same invocation.
build:
	$(MAKE) --no-print-directory link BINARY=$(BINARY)

# -q (--emit-relocs): keeps .rel.* in the ELF for tools/shift/scan.py; the objcopy'd bin is unchanged.
# undef_by_name.ld: refs splat left undefined, defined at the vram in their name (tools/build/undef_by_name.py).
# splat auto files are linked as PROVIDE(): a name an object already defines (dlabel) keeps its in-section label.
# JUST_SYMS (rockx5): the exe ELF, --just-symbols; undef_by_name fails on an exe-range name it does not define.
# exe_syms.ld (same names, assignments) overrides the sign-extended just-symbols values R_MIPS_26 rejects.
# SHIFT=1: -T the tools/shift/pad_ld.py rewrite of the splat script, no sha gate (bytes differ by design).
# LINK_SCRIPTS: extra -T scripts; main: OVL_SYMS, default $(CONFIG_V)/shift/ovl_syms.ld (rockx5 names its exe relocs use,
# retail; ovlA/B_VRAM); the SHIFT rockx5 pass 2 relinks with $(SH)/ovl_syms.ld (mk/rockx5.mk).
# LINK_POST: per-alias hook after the link (mk/rockx5.mk: SHIFT two-pass); empty by default.
OVL_SYMS ?= $(CONFIG_V)/shift/ovl_syms.ld
# PAD_LD (mk/rockx5.mk): pad_ld.py on every link, not only SHIFT; LD_PAD its --pad; LD_SCRIPT the -T script it writes.
LD_PAD ?= $(SHIFT_PAD)
LD_SCRIPT = $(B_DIR)/$(B_NAME)$(if $(SHIFT),,$(if $(PAD_LD),.pad)).ld
LINK_SCRIPTS = $(if $(filter $(MAIN),$(BINARY)),$(OVL_SYMS))
link: $(B_OBJ) $(JUST_SYMS) $(LINK_DEPS) $(LINK_SCRIPTS)
	$(PY) tools/build/undef_by_name.py $(if $(JUST_SYMS),--just-symbols $(JUST_SYMS)) $(B_DIR)/undef_by_name.ld $(B_OBJ)
	$(if $(SHIFT)$(PAD_LD),$(PY) tools/shift/pad_ld.py $(BINARY) $(S_DIR)/$(B_NAME).ld $(LD_SCRIPT) --pad $(LD_PAD) --objdir $(B_DIR))
	for f in undefined_syms_auto undefined_funcs_auto; do \
		sed -E 's/^([^ =]+) *= *([^;]+);/PROVIDE(\1 = \2);/' $(S_DIR)/$$f.txt > $(B_DIR)/$$f.provide.ld || exit 1; done
	$(LD) -nostdlib -q --no-check-sections -T $(LD_SCRIPT) -T $(B_DIR)/undefined_syms_auto.provide.ld \
		-T $(B_DIR)/undefined_funcs_auto.provide.ld -T $(B_DIR)/undef_by_name.ld $(foreach f,$(LINK_SCRIPTS),-T $(f)) $(if $(JUST_SYMS),-T $(B_DIR)/exe_syms.ld --just-symbols=$(JUST_SYMS)) -Map $(B_DIR)/$(B_NAME).map -o $(B_DIR)/$(B_NAME).elf
	$(OBJCOPY) -O binary $(B_DIR)/$(B_NAME).elf $(B_DIR)/$(B_NAME)
	$(if $(SHIFT),,$(if $(filter build,$(BUILD_ROOT)),sha1sum -c $(call CHECK_SHA,$(BINARY)),sed 's|  build/|  $(BUILD_ROOT)/|' $(call CHECK_SHA,$(BINARY)) | sha1sum -c -)) # layout: other-tree the check file spells the default build/ tree
	$(LINK_POST)

# clean: fleet-wide, mk/fleet.mk

# Compiler depfiles of every C object (patch objects share these paths under SHIFT, mk/patches.mk).
-include $(patsubst %.c,$(B_DIR)/%.d,$(B_C))
