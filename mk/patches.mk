# patches.mk — `PATCHES=<name>` (SHIFT=1 only): patches/<name>/<alias>/<f>.c replaces its twin src/<alias>/<f>.c
# in a build of its own, build/shift-<name>/<alias>/ (`make split build SHIFT=1 PATCHES=<n> BINARY=<a>`,
# `make disc SHIFT=1 PATCHES=<n>` -> build/shift-<n>/disc/mmx5.cue). `make replay-patch PATCHES=<n>`: mk/replay.mk.
# Read before rockx5.mk/shift.mk/slus.mk (mk/*.mk sorts patches first): SH is their shifted build root.
SH := build/shift$(if $(PATCHES),-$(PATCHES))

ifneq ($(PATCHES),)
# replay-patch only reads the built cue; every other goal builds and needs SHIFT=1.
ifneq ($(filter-out replay-patch,$(or $(MAKECMDGOALS),all)),)
$(if $(SHIFT),,$(error PATCHES needs SHIFT=1 (patches apply to the shifted build only)))
endif
$(if $(wildcard patches/$(PATCHES)/),,$(error PATCHES=$(PATCHES): no directory patches/$(PATCHES)/))
P_C := $(shell find patches/$(PATCHES) -name '*.c')
P_ORPHAN := $(filter-out $(patsubst src/%,patches/$(PATCHES)/%,$(wildcard $(patsubst patches/$(PATCHES)/%,src/%,$(P_C)))),$(P_C))
$(if $(P_ORPHAN),$(error PATCHES=$(PATCHES): no src/ twin for $(P_ORPHAN)))
BINARY ?= slus

# Shorter stem than mk/slus.mk's `$(B_DIR)/%.o: %.c`, so it wins where a patch exists; falls back to src/ elsewhere.
# -I the twin's src dir: its quoted relative includes (../shared/*.c) resolve as they do from src/; sed names the
# twin in cpp's line markers (the object's .file), so an identical patch gives a cmp-equal object.
$(SH)/$(BINARY)/src/%.o: patches/$(PATCHES)/%.c $(wildcard include/*.h) $(wildcard src/shared/*.c)
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -I $(dir src/$*) $< | sed 's|"$<"|"src/$*.c"|' | $(CC1) $(CFLAGS) | $(MASPSX) | $(AS) $(CC_ASFLAGS) -o $@
endif
