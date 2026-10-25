# fleet.mk — fleet-wide targets over every alias (read first: mk/*.mk sorts fleet < rockx5 < slus).
# clean:    rm build/ asm/ assets/ for every alias; never extracted/ (game data), never git clean.
# check:    clean -> extract (once) -> per alias `split` then `build` in parallel (rockx5 after slus); never stops early.
#           One line per alias `check: <a> ok|FAIL` (output in build/<a>.check.log), last line
#           `check: <k> of <n> green, <f> failed`; exit 0 iff f=0. After a green line it runs
#           `make tools-health` (mk/tools-health.mk); its failure fails check.
# expected: copy build/<a>/<name> (config/splat.<a>.yaml name:) to expected/build/<a>/ (ignored).
# compile-only: every COMPILE_SRC .c -> cpp, cc1, maspsx, as with mk/slus.mk's C vars -> .run/compile-only/<path>.o
#           (one path printed per object). ROM-free: no split, no extracted/, expected/ or asm/ read (CI no-rom.yml).
#           Stages go through files (dash has no pipefail), so any failing stage fails the target.
#           A unit whose maspsx output .includes asm/ (INCLUDE_ASM) is not assembled where asm/ is absent (CI): its
#           path is printed as `<path>.maspsx.s (not assembled ...)`; with asm/ present it is assembled as before.
#           Negative control: a planted unit with a syntax error must fail cc1, else the target fails.
# types-check: tools/dedup/shapes.py check -- refuses a duplicate struct shape, a second definition, a raw address
#           cast in include/*.h and src/**/*.c; `types: <n> shapes, 0 duplicates, 0 raw casts` (tools/dedup/README.md).
# readability-check: tools/readability/scan.py -- six readability classes, one line per offender, then
#           `readability: <p> unmarked pins, ... <u> unbased names`; exit 1 if any count > 0 (tools/readability/README.md).
# no-rom:   firewall-check, format-check, compile-only, types-check, readability-check, tools-selftest
#           (PY passed through), stop at the first failure (`no-rom: <t> FAIL`); last line `no-rom: OK`. Binding before every bank/propagate commit.

ALIASES := slus rockx5
COMPILE_SRC ?= $(shell find src -name '*.c')
CO_DIR := .run/compile-only
# the list goes through a file: inlined, ~4100 paths pass MAX_ARG_STRLEN (128 KiB per sh -c arg)

.PHONY: check expected clean compile-only types-check readability-check no-rom $(addprefix check-,$(ALIASES))

clean:
	rm -rf build asm assets

check:
	@$(MAKE) --no-print-directory clean
	@$(MAKE) --no-print-directory extract
	@mkdir -p build
	@$(MAKE) --no-print-directory -j$(shell nproc) $(addprefix check-,$(ALIASES))
	@n=0; f=0; for a in $(ALIASES); do n=$$((n+1)); \
	  if [ "$$(cat build/$$a.check.rc 2>/dev/null)" = 0 ]; then echo "check: $$a ok"; \
	  else f=$$((f+1)); echo "check: $$a FAIL (build/$$a.check.log)"; fi; done; \
	echo "check: $$((n-f)) of $$n green, $$f failed"; [ $$f -eq 0 ]
	@$(MAKE) --no-print-directory tools-health

# check-<a>: always succeeds so siblings run to the end; the result is build/<a>.check.rc.
# split and build are separate sub-makes: one `split build` invocation could run them in parallel under -j.
$(addprefix check-,$(ALIASES)): check-%:
	@{ $(MAKE) --no-print-directory split BINARY=$* && $(MAKE) --no-print-directory build BINARY=$*; } \
	  > build/$*.check.log 2>&1; echo $$? > build/$*.check.rc

check-rockx5: check-slus  # rockx5 splits against the built exe ELF (mk/rockx5.mk)

expected:
	@for a in $(ALIASES); do n=$$(sed -n 's/^name: *//p' config/splat.$$a.yaml); \
	  mkdir -p expected/build/$$a && cp build/$$a/$$n expected/build/$$a/ || exit 1; done

compile-only:
	$(shell mkdir -p .run)$(file >$(CO_DIR).list,$(COMPILE_SRC))
	@set -e; for c in $$(cat $(CO_DIR).list); do o=$(CO_DIR)/$${c%.c}.o; t=$${o%.o}; mkdir -p $$(dirname $$o); \
	  $(CPP) $(CPPFLAGS) $$c > $$t.i; $(CC1) $(CFLAGS) < $$t.i > $$t.cc1.s; $(MASPSX) < $$t.cc1.s > $$t.maspsx.s; \
	  if [ ! -d asm ] && grep -q '^\.include "asm/' $$t.maspsx.s; then \
	    echo "$$t.maspsx.s (not assembled: it includes asm/, absent here)"; continue; fi; \
	  $(AS) $(CC_ASFLAGS) -o $$o $$t.maspsx.s; echo $$o; done
	@mkdir -p $(CO_DIR) && printf 'int f( { return 0; }\n' > $(CO_DIR)/control.c; \
	  if $(CPP) $(CPPFLAGS) $(CO_DIR)/control.c 2> /dev/null | $(CC1) $(CFLAGS) > /dev/null 2>&1; then \
	    echo "compile-only: planted control compiled, want a cc1 error"; exit 1; fi; \
	  echo "compile-only: OK (control caught)"

types-check:
	$(PY) tools/dedup/shapes.py check

readability-check:
	$(PY) tools/readability/scan.py

# no-rom: the game-free gate, run before every commit that banks or propagates code; stops at the first failure.
no-rom:
	@for t in firewall-check format-check compile-only types-check readability-check tools-selftest; do \
	  $(MAKE) --no-print-directory $$t PY="$(PY)" || { echo "no-rom: $$t FAIL"; exit 1; }; done; echo "no-rom: OK"
