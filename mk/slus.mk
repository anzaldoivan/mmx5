# slus.mk — asm + C build of one binary: `make split build BINARY=<alias>`.
# split: splat config/splat.<alias>.yaml -> asm/<alias>/ + build/<alias>/<name>.ld (both ignored).
# build: as each .s, cpp|cc1|maspsx|as each .c -> ld (splat script) -> objcopy -O binary -> sha1sum -c config/check.<alias>.sha (fails on mismatch).

.PHONY: split build link

BINARY ?= slus
SPLAT ?= .venv/bin/python -m splat
AS := tools/bin/mipsel-linux-gnu-as
LD := tools/bin/mipsel-linux-gnu-ld
OBJCOPY := tools/bin/mipsel-linux-gnu-objcopy
# AS_MARCH: per-alias override in mk/<alias>.mk
AS_MARCH ?= r3000
ASFLAGS := -EL -march=$(AS_MARCH) -mtune=r3000 -no-pad-sections -G0 -I asm/$(BINARY)/include

B_NAME = $(shell sed -n 's/^name: *//p' config/splat.$(BINARY).yaml)
# SHIFT=1 (mk/shift.mk): objects/ELF in build/shift/<alias>/ (PATCHES=<n>: build/shift-<n>/, mk/patches.mk);
# split outputs (ld, auto files) stay in S_DIR.
B_DIR := $(if $(SHIFT),$(SH),build)/$(BINARY)
S_DIR := build/$(BINARY)
# asm/<alias>/nonmatchings/: INCLUDE_ASM bodies of carved c subsegments, assembled through their .c, not alone.
B_ASM = $(shell find asm/$(BINARY) -name '*.s' -not -path '*/nonmatchings/*' 2>/dev/null)
# bin segments (splat asset_path assets/<alias>); *.textbin.bin are .incbin'd by their .s, not linked.
B_BIN = $(filter-out %.textbin.bin,$(shell find assets/$(BINARY) -name '*.bin' 2>/dev/null))
B_OBJ = $(patsubst %.s,$(B_DIR)/%.o,$(B_ASM)) $(patsubst %.bin,$(B_DIR)/%.o,$(B_BIN))

# C: splat `c` subsegments, src/<alias>/<name>.c -> build/<alias>/src/<alias>/<name>.o (the ld script's path).
# Triple pinned in docs/ops/compiler-pin.md ## Pin. CC_ASFLAGS stays r3000 whatever AS_MARCH is (mk/rockx5.mk).
CC_DIR := tools/bin/cc/gcc-2.95.2-psx
CPP := $(CC_DIR)/cpp
CC1 := $(CC_DIR)/cc1
MASPSX := python3 refs/maspsx/maspsx.py --aspsx-version=2.86
CPPFLAGS := -lang-c -D__GNUC__=2 -Dmips -D__mips__ -Dpsx -D__psx__ -D_MIPSEL -D__CHAR_UNSIGNED__ -D__OPTIMIZE__ -I include
CFLAGS := -O2 -G0 -quiet -w
CC_ASFLAGS := -EL -march=r3000 -no-pad-sections -G0 -I asm/$(BINARY)/include
B_C = $(shell find src/$(BINARY) -name '*.c' 2>/dev/null)
B_OBJ += $(patsubst %.c,$(B_DIR)/%.o,$(B_C))

# SPLIT_DEPS / SPLIT_POST / JUST_SYMS: per-alias hooks (mk/rockx5.mk: exe symbols).
# rm asm/<alias> first: splat never deletes a .s whose sub a yaml edit removed or retyped, and B_ASM globs asm/, so a
# stale dlabel object fed undef_by_name a definition the ld script never links (T10.c13: W22 adopt red, worktree green).
split: $(SPLIT_DEPS)
	rm -rf asm/$(BINARY)
	$(SPLAT) split config/splat.$(BINARY).yaml
	$(SPLIT_POST)

$(B_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

# Hand asm src/<alias>/<seg>.s replaces splat's generated asm/<alias>/<seg>.s (shorter stem wins over the rule above).
# slus: header.s (pc0/t_addr/t_size as link symbols), game_80013348.s (lui/ori pair relocated).
$(B_DIR)/asm/$(BINARY)/%.o: src/$(BINARY)/%.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

$(B_DIR)/%.o: %.c $(wildcard include/*.h) $(wildcard src/shared/*.c)
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) $< | $(CC1) $(CFLAGS) | $(MASPSX) | $(AS) $(CC_ASFLAGS) -o $@

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
# LINK_SCRIPTS: extra -T scripts; slus: OVL_SYMS, default config/shift/ovl_syms.ld (rockx5 names its exe relocs use,
# retail; ovlA/B_VRAM; T4.1); the SHIFT rockx5 pass 2 relinks with $(SH)/ovl_syms.ld (mk/rockx5.mk, T8).
# LINK_POST: per-alias hook after the link (mk/rockx5.mk: SHIFT two-pass); empty by default.
OVL_SYMS ?= config/shift/ovl_syms.ld
# PAD_LD (mk/rockx5.mk): pad_ld.py on every link, not only SHIFT; LD_PAD its --pad; LD_SCRIPT the -T script it writes.
LD_PAD ?= $(SHIFT_PAD)
LD_SCRIPT = $(B_DIR)/$(B_NAME)$(if $(SHIFT),,$(if $(PAD_LD),.pad)).ld
LINK_SCRIPTS = $(if $(filter slus,$(BINARY)),$(OVL_SYMS))
link: $(B_OBJ) $(JUST_SYMS) $(LINK_DEPS) $(LINK_SCRIPTS)
	$(PY) tools/build/undef_by_name.py $(if $(JUST_SYMS),--just-symbols $(JUST_SYMS)) $(B_DIR)/undef_by_name.ld $(B_OBJ)
	$(if $(SHIFT)$(PAD_LD),$(PY) tools/shift/pad_ld.py $(BINARY) $(S_DIR)/$(B_NAME).ld $(LD_SCRIPT) --pad $(LD_PAD) --objdir $(B_DIR))
	for f in undefined_syms_auto undefined_funcs_auto; do \
		sed -E 's/^([^ =]+) *= *([^;]+);/PROVIDE(\1 = \2);/' $(S_DIR)/$$f.txt > $(B_DIR)/$$f.provide.ld || exit 1; done
	$(LD) -nostdlib -q --no-check-sections -T $(LD_SCRIPT) -T $(B_DIR)/undefined_syms_auto.provide.ld \
		-T $(B_DIR)/undefined_funcs_auto.provide.ld -T $(B_DIR)/undef_by_name.ld $(foreach f,$(LINK_SCRIPTS),-T $(f)) $(if $(JUST_SYMS),-T $(B_DIR)/exe_syms.ld --just-symbols=$(JUST_SYMS)) -Map $(B_DIR)/$(B_NAME).map -o $(B_DIR)/$(B_NAME).elf
	$(OBJCOPY) -O binary $(B_DIR)/$(B_NAME).elf $(B_DIR)/$(B_NAME)
	$(if $(SHIFT),,sha1sum -c config/check.$(BINARY).sha)
	$(LINK_POST)

# clean: fleet-wide, mk/fleet.mk
