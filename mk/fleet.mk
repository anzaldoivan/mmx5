# Fleet-wide targets over every alias (read first: mk/*.mk sorts fleet < rockx5 < main).
# clean:    rm $(B) $(ASM) $(ASSETS) (this version's build, split and assets); never extracted/ (game data), never git clean.
# style-check: the psxdecomp-readme job's verdict, locally: tools/psxd_{floor,publish}.py copied from STYLE_BASE
#           (default origin/main, the last pushed head = the job's BASE), then `gate --ci STYLE_BASE..HEAD` (style,
#           README lint, categories, debt). Commits only, not the work tree. Last line `style-check: OK|FAIL ...`.
# check:    style-check, then clean -> extract (once) -> per alias `split` then `build` in parallel (rockx5 after main); never stops early.
#           One line per alias `check: <a> ok|FAIL` (output in $(B)/<a>.check.log), last line
#           `check: <k> of <n> green, <f> failed`; exit 0 iff f=0. After a green line it runs
#           `make shift-scan` (mk/shift.mk, retail pair; a finding or a missed plant fails check). This public
#           target runs no tools-health. The dev tier is `make dev-check` (mk/tools-dev.mk: check, then mk/tools-health.mk).
# check-all: `make check VERSION=<v>` once per data row of config/versions.tsv (skip # lines and the header), in row
#           order; then `check-all: <k> of <n> versions green (<v> ...)`; exit 0 iff every version is green.
# expected: copy $(B)/<a>/<name> ($(CONFIG_V)/splat.<a>.yaml name:) to $(EXPECTED)/<a>/ (ignored).
# compile-only: every COMPILE_SRC .c -> cpp, cc1, maspsx, as with mk/main.mk's C vars -> .run/compile-only/<path>.o
#           (one path printed per object; every unit gets $(VERSION_CPPFLAGS), an ovlNN one -DOVL_ID=NN, as mk/rockx5.mk).
#           ROM-free: no split, no extracted/, expected/ or asm/ read (CI no-rom.yml).
#           Stages go through files (dash has no pipefail), so any failing stage fails the target.
#           A unit whose maspsx output .includes asm/ (INCLUDE_ASM) is not assembled where asm/ is absent (CI): its
#           path is printed as `<path>.maspsx.s (not assembled ...)`; with asm/ present it is assembled as before.
#           Negative control: a planted unit with a syntax error must fail cc1, else the target fails.
#           Version control: a planted unit including mmx5/version.h must compile with $(VERSION_CPPFLAGS), and
#           without it must fail on version.h's #error; either way out fails the target.
# readability-check: tools/readability/scan.py -- nine readability classes, one line per offender, then
#           `readability: <p> unmarked pins, ... <u> unbased names, <t> task ids, <b> banners, <e> end markers`; exit 1 if any count > 0 (CONTRIBUTING.md).
# selftest: per `<tool>:<name>` of $(SELFTESTS_PUBLIC) $(SELFTESTS_DEV): `tools/<tool>.py --selftest` (log
#           .run/selftest/<name>.log) must exit 0 and print `<name>: control OK`. The target prints its last such
#           line. The first failure fails (`selftest: FAIL <name> (<log>)`). SELFTESTS_DEV comes from mk/tools-health.mk.
# no-rom:   the $(NOROM_STEPS) in order, PY passed through. Public steps: firewall-check, format-check, compile-only,
#           readability-check, selftest. mk/tools-dev.mk appends types-check. It stops at the first failure
#           (`no-rom: <t> FAIL`). The last line is `no-rom: OK`. Binding before every bank/propagate commit.

ALIASES := $(MAIN) rockx5
COMPILE_SRC ?= $(shell find src -name '*.c')
CO_DIR := .run/compile-only
ST_DIR := .run/selftest
SELFTESTS_PUBLIC := readability/scan:readability repack/rockx5:rockx5 shift/scan:shift-scan assets/assets:assets replay/replay:replay# layout: other-tree tools/<tool>.py names, not paths
NOROM_STEPS := firewall-check format-check compile-only readability-check selftest
# the list goes through a file: inlined, ~4100 paths pass MAX_ARG_STRLEN (128 KiB per sh -c arg)

.PHONY: check check-all style-check expected clean compile-only readability-check selftest no-rom $(addprefix check-,$(ALIASES))

clean:
	rm -rf $(B) $(ASM) $(ASSETS)

STYLE_BASE ?= origin/main
SC_DIR := .run/style-check
# The version-ifdef refusal (R229): the version axis is ordered (include/mmx5/version.h, VERSION_CPPFLAGS), so C
# compares `#if VERSION >= VER_US`; an `#ifdef`, `#ifndef` or `defined()` of VERSION_* is refused.
VIFDEF := ^[[:space:]]*\#[[:space:]]*(ifdef|ifndef)[[:space:]]+VERSION_[[:alnum:]_]*|\bdefined[[:space:]]*\(?[[:space:]]*VERSION_[[:alnum:]_]*
# check-all's rows: config/versions.tsv's version column (a comment or the header has fewer than three fields).
VERSIONS := $(shell awk -F'\t' 'NF >= 3 && $$1 != "version" { print $$1 }' config/versions.tsv)
# the judge is BASE's copy of the kit tools, as in .github/workflows/psxdecomp-readme.yml: a change never judges itself
style-check:
	@b=$$(git rev-parse -q --verify '$(STYLE_BASE)^{commit}') || { echo "style-check: FAIL no base $(STYLE_BASE)"; exit 2; }; \
	  rm -rf $(SC_DIR) && mkdir -p $(SC_DIR) && git show $$b:tools/psxd_floor.py > $(SC_DIR)/psxd_floor.py \
	  && git show $$b:tools/psxd_publish.py > $(SC_DIR)/psxd_publish.py || { echo "style-check: FAIL no tools at $$b"; exit 2; }; \
	  printf '%s\n' '/* a comment line */' '#ifdef VERSION_US' '#endif' '#ifndef VERSION_JP' '#endif' '#if VERSION >= VER_US' '#endif' > $(SC_DIR)/version-ifdef.c; \
	  c=$$(grep -cE '$(VIFDEF)' $(SC_DIR)/version-ifdef.c || true); \
	  if [ "$$c" != 2 ]; then echo "style-check: FAIL version-ifdef control ($$c of 2)"; rm -rf $(SC_DIR); exit 2; fi; \
	  h=$$(grep -rEn '$(VIFDEF)' --include='*.c' --include='*.h' --include='*.s' --include='*.inc' src include patches || true); \
	  if [ -n "$$h" ]; then c=$$(printf '%s\n' "$$h" | wc -l); \
	    echo "style-check: REFUSE $$c version ifdefs (write #if VERSION >= VER_<X>, include/mmx5/version.h)"; \
	    printf '%s\n' "$$h" | cut -d: -f1,2; rm -rf $(SC_DIR); exit 1; fi; \
	  $(PY) -I $(SC_DIR)/psxd_floor.py gate --ci $$b..HEAD; rc=$$?; rm -rf $(SC_DIR); \
	  if [ $$rc = 0 ]; then r=OK; else r=FAIL; fi; echo "style-check: $$r (gate --ci, base $$(git rev-parse --short $$b))"; exit $$rc

check:
	@$(MAKE) --no-print-directory style-check PY="$(PY)"
	@$(MAKE) --no-print-directory clean
	@$(MAKE) --no-print-directory extract
	@mkdir -p $(B)
	@$(MAKE) --no-print-directory -j$(shell nproc) $(addprefix check-,$(ALIASES))
	@n=0; f=0; for a in $(ALIASES); do n=$$((n+1)); \
	  if [ "$$(cat $(B)/$$a.check.rc 2>/dev/null)" = 0 ]; then echo "check: $$a ok"; \
	  else f=$$((f+1)); echo "check: $$a FAIL ($(B)/$$a.check.log)"; fi; done; \
	echo "check: $$((n-f)) of $$n green, $$f failed"; [ $$f -eq 0 ]
	@$(MAKE) --no-print-directory shift-scan PY="$(PY)" SHIFT= SCAN_FLAGS=

# One `check` per registry row; the foreach expands the sub-make at make time, so `make -n check-all` names every version.
check-all:
	@n=$(words $(VERSIONS)); k=0; g=; \
	$(foreach v,$(VERSIONS),if $(MAKE) --no-print-directory check VERSION=$(v) PY="$(PY)"; then k=$$((k+1)); g="$$g $(v)"; else echo "check-all: $(v) FAIL"; fi; ) \
	echo "check-all: $$k of $$n versions green ($${g# })"; [ $$k -eq $$n ]

# check-<a>: always succeeds so siblings run to the end; the result is $(B)/<a>.check.rc.
# split and build are separate sub-makes: one `split build` invocation could run them in parallel under -j.
$(addprefix check-,$(ALIASES)): check-%:
	@{ $(MAKE) --no-print-directory split BINARY=$* && $(MAKE) --no-print-directory build BINARY=$*; } \
	  > $(B)/$*.check.log 2>&1; echo $$? > $(B)/$*.check.rc

check-rockx5: check-$(MAIN)  # rockx5 splits against the built exe ELF (mk/rockx5.mk)

expected:
	@for a in $(ALIASES); do n=$$(sed -n 's/^name: *//p' $(CONFIG_V)/splat.$$a.yaml); \
	  mkdir -p $(EXPECTED)/$$a && cp $(B)/$$a/$$n $(EXPECTED)/$$a/ || exit 1; done

compile-only:
	$(shell mkdir -p .run)$(file >$(CO_DIR).list,$(COMPILE_SRC))
	@set -e; for c in $$(cat $(CO_DIR).list); do o=$(CO_DIR)/$${c%.c}.o; t=$${o%.o}; mkdir -p $$(dirname $$o); \
	  d=$${c%/*}; d=$${d##*/}; case $$d in ovl[0-9]*) d=-DOVL_ID=$${d#ovl};; *) d=;; esac; \
	  $(CPP) $(CPPFLAGS) $(VERSION_CPPFLAGS) $$d $$c > $$t.i; $(CC1) $(CFLAGS) < $$t.i > $$t.cc1.s; $(MASPSX) < $$t.cc1.s > $$t.maspsx.s; \
	  if [ ! -d $(ASM) ] && grep -q '^\.include "$(ASM)/' $$t.maspsx.s; then \
	    echo "$$t.maspsx.s (not assembled: it includes $(ASM)/, absent here)"; continue; fi; \
	  $(AS) $(CC_ASFLAGS) -o $$o $$t.maspsx.s; echo $$o; done
	@mkdir -p $(CO_DIR) && printf 'int f( { return 0; }\n' > $(CO_DIR)/control.c; \
	  if $(CPP) $(CPPFLAGS) $(VERSION_CPPFLAGS) $(CO_DIR)/control.c 2> /dev/null | $(CC1) $(CFLAGS) > /dev/null 2>&1; then \
	    echo "compile-only: planted control compiled, want a cc1 error"; exit 1; fi; \
	  printf '#include "mmx5/version.h"\n#if VERSION >= VER_US\nint version_ok;\n#endif\n' > $(CO_DIR)/version.c; \
	  if ! $(CPP) $(CPPFLAGS) $(VERSION_CPPFLAGS) $(CO_DIR)/version.c 2> /dev/null | $(CC1) $(CFLAGS) > /dev/null 2>&1; then \
	    echo "compile-only: version control failed with $(VERSION_CPPFLAGS)"; exit 1; fi; \
	  if $(CPP) $(CPPFLAGS) $(CO_DIR)/version.c > /dev/null 2> $(CO_DIR)/version.err; then \
	    echo "compile-only: version control cpp passed without $(VERSION_CPPFLAGS), want the version.h #error"; exit 1; fi; \
	  grep -q 'VERSION is undefined' $(CO_DIR)/version.err || { \
	    echo "compile-only: version control failed without the version.h #error"; exit 1; }; \
	  echo "compile-only: version control OK (compiles with $(VERSION_CPPFLAGS), refuses without)"; \
	  echo "compile-only: OK (control caught)"

readability-check:
	$(PY) tools/readability/scan.py

selftest:
	@set -e; mkdir -p $(ST_DIR); for t in $(SELFTESTS_PUBLIC) $(SELFTESTS_DEV); do p=$${t%:*}; n=$${t#*:}; \
	  l=$(ST_DIR)/$$n.log; $(PY) tools/$$p.py --selftest > $$l 2>&1 || { echo "selftest: FAIL $$n ($$l)"; exit 1; }; \
	  grep -E "^$$n: control OK( --|$$)" $$l | tail -n 1 | grep . || { echo "selftest: FAIL $$n ($$l)"; exit 1; }; done

# no-rom: the game-free gate, run before every commit that banks or propagates code; stops at the first failure.
no-rom:
	@for t in $(NOROM_STEPS); do \
	  $(MAKE) --no-print-directory $$t PY="$(PY)" || { echo "no-rom: $$t FAIL"; exit 1; }; done; echo "no-rom: OK"
