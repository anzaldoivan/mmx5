# disc.mk — `make disc`: rebuild SLUS + ROCK_X5.BIN, pack ROCK_X5.BIN, mkpsxiso the image, sha1-gate it
# (tools/repack/disc.py; docs/formats.md "Image rebuild (inverse)"). `make disc-clean` drops build/disc.
# `make disc-assets`: assets.py export + import -> build/assets/ROCK_X5.DAT, the same slus/rockx5 steps, then the
# image with that DAT packed (disc.py build --file) -> build/assets/disc/mmx5.bin/.cue, same sha gate.
# `make disc ASSET_EDIT=<name>`: export (if absent), assets.py apply <name>, import -> build/asset-<name>/ROCK_X5.DAT,
# then the image with that DAT -> build/asset-<name>/disc/mmx5.cue, no sha gate (asset-edits/<name>/edit.json).
# `make disc-assets SHIFT=1 [PATCHES=<n>]`: same DAT, shifted slus + rockx5 -> $(SH)/disc/mmx5.cue, no sha gate.
# `make disc ASSET_EDIT=<name> SHIFT=1` is refused (ASSET_EDIT needs an unshifted build).

.PHONY: disc disc-assets disc-clean

# SHIFT=1: shifted slus + rockx5 (mk/shift.mk) -> build/shift/disc/mmx5.cue (PATCHES=<n>: build/shift-<n>/disc/), no sha gate.
D_SH = $(if $(SHIFT),$(patsubst build/%,%,$(SH))/)
define DISC_PARTS
	$(MAKE) --no-print-directory split build BINARY=slus
	$(MAKE) --no-print-directory split build BINARY=rockx5
	$(PY) tools/repack/rockx5.py pack --map build/$(D_SH)rockx5/ROCK_X5.BIN.map --elf-bin build/$(D_SH)rockx5/ROCK_X5.BIN \
		--out build/$(D_SH)disc/ROCK_X5.BIN $(if $(SHIFT),--ref '')
endef
AE = build/asset-$(ASSET_EDIT)
disc:
ifdef ASSET_EDIT
	$(if $(SHIFT),$(error ASSET_EDIT needs an unshifted build (SHIFT unset)))
	@test -f assets/retail/dat/index.json || $(PY) tools/assets/assets.py export
	$(PY) tools/assets/assets.py apply $(ASSET_EDIT)
	$(PY) tools/assets/assets.py import --src assets/work/$(ASSET_EDIT) --out $(AE)
	$(DISC_PARTS)
	$(PY) tools/repack/disc.py build --out $(AE)/disc --file ROCK_X5.DAT=$(AE)/ROCK_X5.DAT --no-gate
else
	$(DISC_PARTS)
	$(PY) tools/repack/disc.py build $(if $(SHIFT),--out $(SH)/disc --slus $(SH)/slus/SLUS_013.34 \
		--rockx5 $(SH)/disc/ROCK_X5.BIN --no-gate)
endif

disc-assets:
	$(PY) tools/assets/assets.py export
	$(PY) tools/assets/assets.py import
	$(DISC_PARTS)
ifdef SHIFT
	$(PY) tools/repack/disc.py build --out $(SH)/disc --slus $(SH)/slus/SLUS_013.34 --rockx5 $(SH)/disc/ROCK_X5.BIN \
		--file ROCK_X5.DAT=build/assets/ROCK_X5.DAT --no-gate
	@echo "disc-assets: re-imported DAT packed into $(SH)/disc (shifted, no gate)"
else
	$(PY) tools/repack/disc.py build --out build/assets/disc --file ROCK_X5.DAT=build/assets/ROCK_X5.DAT
	@echo "disc-assets: re-imported image sha1 matches config/medium.sha1"
endif

disc-clean:
	rm -rf build/disc build/shift/disc
