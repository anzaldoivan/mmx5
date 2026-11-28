# `make format` rewrites every C source and header under src/ with the tracked .clang-format; `make format-check`
# is the same run in dry mode with warnings as errors (a CI-able check, no game bytes needed). Dotfiles under src/
# are excluded so a tool's live probe file is never formatted into the tree.

.PHONY: format format-check firewall-check extract

PY ?= python3

# Adapted from mmx6 (Makefile, the version axis). VERSION selects the build target. BUILD_ROOT moves every build output.
# Both are exported, so tools (tools/build/layout.py, same defaults) and sub-makes agree.
VERSION ?= us
BUILD_ROOT ?= build
export VERSION BUILD_ROOT
B := $(BUILD_ROOT)/$(VERSION)
# Address-bound config (splat yamls, symbols, reloc_addrs, dedup, shift/) is per version. Shared config stays in config/.
CONFIG_V := config/$(VERSION)
# BUILD_ROOT other than `build` nests the split, asset and expected trees under it (build/health/asm/us/...), so a run
# there never reads or writes asm/ or expected/; extracted/ (game data) stays where extract wrote it.
OUT_ROOT := $(if $(filter build,$(BUILD_ROOT)),,$(BUILD_ROOT)/)
ASM := $(OUT_ROOT)asm/$(VERSION)# layout: other-tree the version axis itself
ASSETS := $(OUT_ROOT)assets/$(VERSION)# layout: other-tree the version axis itself
EXTRACTED := extracted/$(VERSION)# layout: other-tree the version axis itself
EXPECTED := $(OUT_ROOT)expected/$(VERSION)# layout: other-tree the version axis itself
# The hash list of one binary: $(call CHECK_SHA,<alias>). The kit reads config/check.*.sha.
CHECK_SHA = config/check.$(VERSION).$(1).sha# layout: other-tree the version axis itself
# The version registry config/versions.tsv (`version serial triple`): its serial joins config/discs.tsv.
# A VERSION without a row stops make before any rule runs.
VERSION_ROW := $(shell awk -F'\t' -v v='$(VERSION)' '$$1 == v { print $$2, $$3 }' config/versions.tsv)
ifeq ($(VERSION_ROW),)
$(error VERSION '$(VERSION)' has no row in config/versions.tsv (the version registry))
endif
ifeq ($(shell awk -F'\t' -v s='$(word 1,$(VERSION_ROW))' '$$2 == s { print $$2 }' config/discs.tsv),)
$(error VERSION '$(VERSION)': its serial $(word 1,$(VERSION_ROW)) has no row in config/discs.tsv)
endif
VERSION_TRIPLE := $(word 2,$(VERSION_ROW))
# The compiler pin (docs/ops/compiler-pin.md). A default that differs from the registry row stops make.
TRIPLE ?= L3-gcc2952psx-as286
ifeq ($(origin TRIPLE),file)
ifneq ($(TRIPLE),$(VERSION_TRIPLE))
$(error TRIPLE ?= $(TRIPLE) differs from the $(VERSION) row of config/versions.tsv ($(VERSION_TRIPLE)))
endif
endif
OUT ?= $(EXTRACTED)
# include/mmx5/version.h: every C compile gets -DVERSION=VER_<VERSION in capitals> (cpp-running tools: layout.ovl_cppflags).
VERSION_UC := $(shell echo '$(VERSION)' | tr a-z A-Z)
VERSION_CPPFLAGS := -DVERSION=VER_$(VERSION_UC)
CLANG_FORMAT ?= .venv/bin/clang-format

format:
	find src -type f \( -name '*.c' -o -name '*.h' \) -not -name '.*' -print0 | xargs -0 -r $(CLANG_FORMAT) -i --style=file

format-check:
	find src -type f \( -name '*.c' -o -name '*.h' \) -not -name '.*' -print0 | xargs -0 -r $(CLANG_FORMAT) --dry-run --Werror --style=file

# firewall-check: negative control for tools/audit_public.py. Plants the 16-byte fixture (sha1 in
# config/firewall-fixture.sha1) under .run/, requires the audit to FAIL naming it as game-derived content, removes the
# plant unconditionally (trap). Second control: plants game-free text as a .cue (FW_IMG), requires the audit to FAIL
# naming it by the disc-image path rule. Third: the fixture under patches/ (a published path), must FAIL naming it.
# Fourth: game-free text under assets/ (FW_ASSET), must FAIL naming it by the assets/ purge rule.
# Fifth: game-free text in a version folder that is not US (FW_VER) under each of build/, asm/, assets/, expected/ and
# extracted/, must FAIL naming its purge rule (extracted/: the version-folder glob). Empty plant folders are removed.
# Then requires the real tree audit to pass.
FW_PLANT := .run/firewall-control/planted.bin
FW_IMG := .run/firewall-control/planted.cue
FW_PATCH := patches/firewall-planted.bin
FW_ASSET := $(ASSETS)/firewall-planted.bin
FW_ASSET_RULE := purge path (assets/)# layout: other-tree the firewall rule name, not a build path
FW_VER := jp# a version folder that is not US
FW_VER_ROOTS := build asm assets expected extracted# layout: other-tree the firewall's roots, not build paths
FW_VER_DIRS := $(addsuffix /$(FW_VER),$(FW_VER_ROOTS))
FW_VER_PLANTS := $(addsuffix /firewall-planted.bin,$(FW_VER_DIRS))
FW_VER_EXT_RULE := glob:extracted/??/[!m]*# layout: other-tree the firewall rule name, not a build path
firewall-check:
	@set -u; trap 'rm -f $(FW_PLANT) $(FW_IMG) $(FW_PATCH) $(FW_ASSET) $(FW_VER_PLANTS); rmdir patches $(FW_VER_DIRS) 2>/dev/null; true' EXIT; \
	mkdir -p .run/firewall-control && printf 'DECOMP-FIXTURE!!' > $(FW_PLANT) || { echo "firewall-check: cannot plant control"; exit 1; }; \
	out=$$($(PY) tools/audit_public.py --paths $(FW_PLANT) 2>&1); rc=$$?; \
	rm -f $(FW_PLANT); \
	[ $$rc -eq 1 ] || { echo "firewall-check: planted control: audit exit $$rc, want 1"; exit 1; }; \
	printf '%s\n' "$$out" | grep -qF 'OFFENDER $(FW_PLANT): game-derived content' || { echo "firewall-check: planted control not reported as game-derived content"; exit 1; }; \
	printf 'FILE "fake.bin" BINARY\n' > $(FW_IMG) || { echo "firewall-check: cannot plant image control"; exit 1; }; \
	out=$$($(PY) tools/audit_public.py --paths $(FW_IMG) 2>&1); rc=$$?; \
	rm -f $(FW_IMG); \
	[ $$rc -eq 1 ] || { echo "firewall-check: image control: audit exit $$rc, want 1"; exit 1; }; \
	printf '%s\n' "$$out" | grep -qF 'OFFENDER $(FW_IMG): purge path (glob:*.cue)' || { echo "firewall-check: image control not reported as a disc-image path"; exit 1; }; \
	echo "firewall-check: image control caught"; \
	mkdir -p patches && printf 'DECOMP-FIXTURE!!' > $(FW_PATCH) || { echo "firewall-check: cannot plant patches control"; exit 1; }; \
	out=$$($(PY) tools/audit_public.py --paths $(FW_PATCH) 2>&1); rc=$$?; \
	rm -f $(FW_PATCH); \
	[ $$rc -eq 1 ] || { echo "firewall-check: patches control: audit exit $$rc, want 1"; exit 1; }; \
	printf '%s\n' "$$out" | grep -qF 'OFFENDER $(FW_PATCH): game-derived content' || { echo "firewall-check: patches control not reported as game-derived content"; exit 1; }; \
	echo "firewall-check: patches control caught"; \
	mkdir -p $(ASSETS) && printf 'ASSET-CONTROL\n' > $(FW_ASSET) || { echo "firewall-check: cannot plant assets control"; exit 1; }; \
	out=$$($(PY) tools/audit_public.py --paths $(FW_ASSET) 2>&1); rc=$$?; \
	rm -f $(FW_ASSET); \
	[ $$rc -eq 1 ] || { echo "firewall-check: assets control: audit exit $$rc, want 1"; exit 1; }; \
	printf '%s\n' "$$out" | grep -qF 'OFFENDER $(FW_ASSET): $(FW_ASSET_RULE)' || { echo "firewall-check: assets control not reported as a purge path"; exit 1; }; \
	echo "firewall-check: assets control caught"; \
	mkdir -p $(FW_VER_DIRS) || { echo "firewall-check: cannot make the version folders"; exit 1; }; \
	for f in $(FW_VER_PLANTS); do r=$${f%%/*}; printf 'VERSION-CONTROL\n' > $$f || { echo "firewall-check: cannot plant $$f"; exit 1; }; \
	  case $$r in extracted) w='$(FW_VER_EXT_RULE)';; *) w=$$r/;; esac; \
	  out=$$($(PY) tools/audit_public.py --paths $$f 2>&1); rc=$$?; \
	  [ $$rc -eq 1 ] || { echo "firewall-check: version control $$f: audit exit $$rc, want 1"; exit 1; }; \
	  printf '%s\n' "$$out" | grep -qF "OFFENDER $$f: purge path ($$w)" || { echo "firewall-check: version control $$f not caught by $$w"; exit 1; }; \
	done; rm -f $(FW_VER_PLANTS); rmdir $(FW_VER_DIRS) 2>/dev/null; \
	echo "firewall-check: version controls caught ($(FW_VER) under $(FW_VER_ROOTS))"; \
	$(PY) tools/audit_public.py >/dev/null || { echo "firewall-check: tree audit failed"; exit 1; }; \
	echo "firewall-check: OK (control caught, tree clean)"

# extract: CUE/BIN -> $(OUT)/<disc path> + $(OUT)/manifest.jsonl (docs/formats.md). CUE defaults to .run/dump-cue
# (written by bootstrap.sh), else the one disks/*.cue.
CUE ?= $(shell cat .run/dump-cue 2>/dev/null)
extract:
	$(PY) tools/extract/extract.py --out "$(OUT)" $(if $(CUE),--cue "$(CUE)")

# The executable binary's alias (layout.MAIN): the mk files name its build dirs and BINARY by it.
MAIN := main

# mk/main.mk must be read last: mk/patches.mk defines SH, and main.mk's `B_DIR :=` reads it (C0126). `-include mk/*.mk`
# sorts main.mk first, so the list is explicit; a new mk file goes in the first line (`-include` skips a missing one).
-include mk/disc.mk mk/fleet.mk mk/patches.mk mk/replay.mk mk/rockx5.mk mk/shift.mk mk/tools-dev.mk mk/tools-health.mk
-include mk/main.mk
