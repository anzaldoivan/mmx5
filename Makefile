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
# plant unconditionally (trap), then requires the real tree audit to pass.
FW_PLANT := .run/firewall-control/planted.bin
firewall-check:
	@set -u; trap 'rm -f $(FW_PLANT)' EXIT; \
	mkdir -p .run/firewall-control && printf 'DECOMP-FIXTURE!!' > $(FW_PLANT) || { echo "firewall-check: cannot plant control"; exit 1; }; \
	out=$$($(PY) tools/audit_public.py --paths $(FW_PLANT) 2>&1); rc=$$?; \
	rm -f $(FW_PLANT); \
	[ $$rc -eq 1 ] || { echo "firewall-check: planted control: audit exit $$rc, want 1"; exit 1; }; \
	printf '%s\n' "$$out" | grep -qF 'OFFENDER $(FW_PLANT): game-derived content' || { echo "firewall-check: planted control not reported as game-derived content"; exit 1; }; \
	$(PY) tools/audit_public.py >/dev/null || { echo "firewall-check: tree audit failed"; exit 1; }; \
	echo "firewall-check: OK (control caught, tree clean)"

# extract: CUE/BIN -> $(OUT)/<disc path> + $(OUT)/manifest.jsonl (docs/formats.md). CUE defaults to the one disks/*.cue.
extract:
	$(PY) tools/extract/extract.py --out "$(OUT)" $(if $(CUE),--cue "$(CUE)")

-include mk/*.mk
