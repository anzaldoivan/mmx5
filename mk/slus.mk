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
B_DIR := build/$(BINARY)
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

split:
	$(SPLAT) split config/splat.$(BINARY).yaml

$(B_DIR)/%.o: %.s
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

# undef_by_name.ld: refs splat left undefined, defined at the vram in their name (tools/build/undef_by_name.py).
link: $(B_OBJ)
	$(PY) tools/build/undef_by_name.py $(B_DIR)/undef_by_name.ld $(B_OBJ)
	$(LD) -nostdlib --no-check-sections -T $(B_DIR)/$(B_NAME).ld -T $(B_DIR)/undefined_syms_auto.txt \
		-T $(B_DIR)/undefined_funcs_auto.txt -T $(B_DIR)/undef_by_name.ld -Map $(B_DIR)/$(B_NAME).map -o $(B_DIR)/$(B_NAME).elf
	$(OBJCOPY) -O binary $(B_DIR)/$(B_NAME).elf $(B_DIR)/$(B_NAME)
	sha1sum -c config/check.$(BINARY).sha

# clean: fleet-wide, mk/fleet.mk
