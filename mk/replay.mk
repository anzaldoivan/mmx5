# replay.mk — `make replay-check`: intro.pad original x3, rebuilt x1, plant x1 (tools/replay/README.md; ~65 min)

.PHONY: replay-check replay-shift replay-patch replay-asset

replay-check:
	$(PY) tools/replay/replay.py check

# replay-shift — shifted disc (make disc SHIFT=1) once vs original/run1; prints `replay: shifted <d> divergences` (~15 min)
RS_PAD := tools/replay/scripts/intro.pad
RS_DIR := .run/replay

replay-shift:
	@test -f $(RS_DIR)/original/run1/checkpoints.jsonl || $(PY) tools/replay/replay.py run --pad $(RS_PAD) --runs 1 --out $(RS_DIR)/original
	rm -rf $(RS_DIR)/shifted && $(PY) tools/replay/replay.py run --cue build/shift/disc/mmx5.cue --pad $(RS_PAD) --runs 1 --out $(RS_DIR)/shifted
	@$(PY) tools/replay/replay.py compare $(RS_DIR)/original/run1 $(RS_DIR)/shifted/run1 > $(RS_DIR)/shifted/compare.txt; rc=$$?; \
	  cat $(RS_DIR)/shifted/compare.txt; \
	  sed -n 's/^replay: [0-9]* checkpoints, \([0-9]*\) divergences.*/replay: shifted \1 divergences/p; s/^replay: first divergence /replay: shifted first divergence /p' $(RS_DIR)/shifted/compare.txt; \
	  exit $$rc

# replay-patch PATCHES=<n> — build/shift-<n>/disc/mmx5.cue (make disc SHIFT=1 PATCHES=<n>) x3 vs original/run1 from the cp
# on the first non-# line of patches/<n>/checkpoint; prints `replay: patch <n> ...: PASS|FAIL` (replay.py compare --from)
RP_DIR = $(RS_DIR)/patch-$(PATCHES)
replay-patch:
	@test -n "$(PATCHES)" || { echo "replay-patch: PATCHES=<name> required"; exit 1; }
	@test -f build/shift-$(PATCHES)/disc/mmx5.cue || { echo "replay-patch: no build/shift-$(PATCHES)/disc/mmx5.cue (make disc SHIFT=1 PATCHES=$(PATCHES))"; exit 1; }
	@test -f $(RS_DIR)/original/run1/checkpoints.jsonl || $(PY) tools/replay/replay.py run --pad $(RS_PAD) --runs 1 --out $(RS_DIR)/original
	rm -rf $(RP_DIR) && $(PY) tools/replay/replay.py run --cue build/shift-$(PATCHES)/disc/mmx5.cue --pad $(RS_PAD) --runs 3 --out $(RP_DIR)
	@cp=$$(grep -m1 -v -e '^#' -e '^[[:space:]]*$$' patches/$(PATCHES)/checkpoint) || { echo "replay-patch: no cp in patches/$(PATCHES)/checkpoint"; exit 1; }; \
	  $(PY) tools/replay/replay.py compare $(RS_DIR)/original/run1 $(RP_DIR) --from $$cp

# replay-asset ASSET_EDIT=<n> — replay-patch twin for build/asset-<n>/disc/mmx5.cue (make disc ASSET_EDIT=<n>) x3,
# cp from asset-edits/<n>/checkpoint; prints `replay-asset: <n> OK (...)`
RA_DIR = $(RS_DIR)/asset-$(ASSET_EDIT)
replay-asset:
	@test -n "$(ASSET_EDIT)" || { echo "replay-asset: ASSET_EDIT=<name> required"; exit 1; }
	@test -f build/asset-$(ASSET_EDIT)/disc/mmx5.cue || { echo "replay-asset: no build/asset-$(ASSET_EDIT)/disc/mmx5.cue (make disc ASSET_EDIT=$(ASSET_EDIT))"; exit 1; }
	@test -f $(RS_DIR)/original/run1/checkpoints.jsonl || $(PY) tools/replay/replay.py run --pad $(RS_PAD) --runs 1 --out $(RS_DIR)/original
	rm -rf $(RA_DIR) && $(PY) tools/replay/replay.py run --cue build/asset-$(ASSET_EDIT)/disc/mmx5.cue --pad $(RS_PAD) --runs 3 --out $(RA_DIR)
	@cp=$$(grep -m1 -v -e '^#' -e '^[[:space:]]*$$' asset-edits/$(ASSET_EDIT)/checkpoint) || { echo "replay-asset: no cp in asset-edits/$(ASSET_EDIT)/checkpoint"; exit 1; }; \
	  $(PY) tools/replay/replay.py compare $(RS_DIR)/original/run1 $(RA_DIR) --from $$cp --label replay-asset
