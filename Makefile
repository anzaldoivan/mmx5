# make-format.snippet.mk — appended to the project's Makefile by decomp-architect (install.py S9).
# `make format` rewrites every C source and header under src/ with the tracked .clang-format; `make format-check`
# is the same run in dry mode with warnings as errors (a CI-able check, no game bytes needed). Dotfiles under src/
# are excluded so a tool's live probe file is never formatted into the tree.

.PHONY: format format-check firewall-check extract

PY ?= python3
OUT ?= extracted/retail
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
# Then requires the real tree audit to pass.
FW_PLANT := .run/firewall-control/planted.bin
FW_IMG := .run/firewall-control/planted.cue
FW_PATCH := patches/firewall-planted.bin
FW_ASSET := assets/firewall-planted.bin
firewall-check:
	@set -u; trap 'rm -f $(FW_PLANT) $(FW_IMG) $(FW_PATCH) $(FW_ASSET); rmdir patches 2>/dev/null; true' EXIT; \
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
	mkdir -p assets && printf 'ASSET-CONTROL\n' > $(FW_ASSET) || { echo "firewall-check: cannot plant assets control"; exit 1; }; \
	out=$$($(PY) tools/audit_public.py --paths $(FW_ASSET) 2>&1); rc=$$?; \
	rm -f $(FW_ASSET); \
	[ $$rc -eq 1 ] || { echo "firewall-check: assets control: audit exit $$rc, want 1"; exit 1; }; \
	printf '%s\n' "$$out" | grep -qF 'OFFENDER $(FW_ASSET): purge path (assets/)' || { echo "firewall-check: assets control not reported as a purge path"; exit 1; }; \
	echo "firewall-check: assets control caught"; \
	$(PY) tools/audit_public.py >/dev/null || { echo "firewall-check: tree audit failed"; exit 1; }; \
	echo "firewall-check: OK (control caught, tree clean)"

# extract: CUE/BIN -> $(OUT)/<disc path> + $(OUT)/manifest.jsonl (docs/formats.md). CUE defaults to .run/dump-cue
# (written by bootstrap.sh), else the one disks/*.cue.
CUE ?= $(shell cat .run/dump-cue 2>/dev/null)
extract:
	$(PY) tools/extract/extract.py --out "$(OUT)" $(if $(CUE),--cue "$(CUE)")

-include mk/*.mk
