# shift.mk — `make shift-scan`: unsymbolized pointers into the exe range and the overlay regions (rockx5
# ovlNN_VRAM..max ovlNN_VRAM_END), exe + rockx5 ELFs, per direction exe/ovl -> exe/ovl, three plants
# (exe->exe, exe->ovl, ovl->ovl) (tools/shift/README.md).
# Needs both linked with -q (mk/slus.mk link). SCAN_FLAGS=--baseline exits 0 whatever the count. SHIFT=1: the build/shift/ pair.
# SHIFT=1 (any target, e.g. `make split build SHIFT=1 BINARY=<a>`, `make disc SHIFT=1`): link into build/shift/<a>/
# through tools/shift/pad_ld.py (exe .main reordered, SHIFT_PAD before each block), no sha gate (mk/slus.mk link).
SHIFT_PAD ?= 0
# rockx5 under SHIFT=1: `. += SHIFT_OVL_PAD` before each code overlay's RODATA, TEXT, DATA (both T8 passes); default build 0.
SHIFT_OVL_PAD ?= 0x10
# shift-oversize: relink the shifted rockx5 (builds the SHIFT=1 slus+rockx5 pair first if absent) with pad 0x2000 > smallest
# slack 0x1F08 (ovl18, A.lo) into .run/shift-oversize/; exit 0 only if ld fails on a region-bound ASSERT.
OVERSIZE_DIR := .run/shift-oversize
SB := build/shift/rockx5

.PHONY: shift-scan shift-oversize

shift-oversize:
	@test -f $(SB)/undef_by_name.ld || { $(MAKE) split build SHIFT=1 BINARY=slus PY=$(PY) && \
	  $(MAKE) split build SHIFT=1 BINARY=rockx5 PY=$(PY); }
	@mkdir -p $(OVERSIZE_DIR)
	$(PY) tools/shift/pad_ld.py rockx5 build/rockx5/ROCK_X5.BIN.ld $(OVERSIZE_DIR)/ROCK_X5.BIN.ld --pad 0x2000
	@if $(LD) -nostdlib -q --no-check-sections -T $(OVERSIZE_DIR)/ROCK_X5.BIN.ld -T $(SB)/undefined_syms_auto.provide.ld \
	  -T $(SB)/undefined_funcs_auto.provide.ld -T $(SB)/undef_by_name.ld -T $(SB)/exe_syms.ld \
	  --just-symbols=build/shift/slus/SLUS_013.34.just.elf -o $(OVERSIZE_DIR)/ROCK_X5.BIN.elf 2> $(OVERSIZE_DIR)/ld.err; then \
	  echo "shift-oversize: link succeeded, region-bound ASSERT did not fire"; exit 1; fi; \
	o=$$(grep -o 'region bound: ovl[0-9]*' $(OVERSIZE_DIR)/ld.err | head -1 | sed 's/.* //'); \
	if [ -z "$$o" ]; then echo "shift-oversize: link failed otherwise:"; tail -5 $(OVERSIZE_DIR)/ld.err; exit 1; fi; \
	echo "shift-oversize: link failed as planted ($$o)"

shift-scan:
	$(PY) tools/shift/scan.py --exe build/$(if $(SHIFT),shift/)slus/SLUS_013.34.elf --ovl build/$(if $(SHIFT),shift/)rockx5/ROCK_X5.BIN.elf \
	  $(if $(SHIFT),--retail-exe build/slus/SLUS_013.34.elf) $(SCAN_FLAGS)
