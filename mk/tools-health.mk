# tools-health.mk — the health chain over the phase-1.5 scanners (docs/ops/census.md "health chain").
# tools-selftest:    ROM-free (CI no-rom.yml compile-only job: reconcile/propagate compile with the pinned cc1 + maspsx):
#                    the 19 `--selftest` runs (census x3, harness, sig, shapes, carve, draw, reconcile, propagate,
#                    cites, levers, symptoms, permute, plateau, wave, gate, ledger, harvest); each must exit 0 and print `<name>: control OK`
#                    (propagate's name is `dedup`, permute's `permuter`). CI also needs pycparser+toml and
#                    refs/decomp-permuter at their pins (requirements-python.txt, config/refs.toml).
# tools-health:      after a green `make check` (mk/fleet.mk runs it): rungs below, in order, each logged to
#                    .run/tools-health/<rung>.log; prints control OK / `<n> of <m>` lines, then `tools-health: OK`
#                    and `tools-health: <s> s`. Any failure: `tools-health: FAIL <rung> (<log>)`, exit non-zero.
# tools-health-full: the same with `harness.py --full` (re-derives inventory + census report first) and
#                    `carve.py sample` at its default --per.
# Rungs (each real rung: rc 0, a denominator line, its output file -newer .run/tools-health/stamp):
#   0 check:        build/<a>.check.rc = 0 for every alias; then `make expected` + `make compile-only` (harness p5 input).
#   1 selftest:     G32/G25 — every scanner proves it can fail on a planted case before it is trusted.
#   2 inventory:    G19/G27 — the function denominator, every byte classed; `inventory: control OK -- k of k c`.
#   3 boundaries:   G21 — every inventory function confirmed against the bytes; must be 0 phantoms, 0 truncations.
#   4 census-dup:   G27 — dup/family groups over the inventory denominator (groups.jsonl).
#   5 census-report: G27 — lanes reconcile to the inventory row count (report.txt); the R3 `census: stubs` line.
#   6 harness:      G35 + the T5 inventory-overcount incident — independent question pairs must agree (k >= 5, 0 DISAGREE).
#   7 sig:          full `sig.py band` (draw reads twins.jsonl; --sample would overwrite it): `band reproduces k of k`.
#   8 types:        `shapes.py check`: `<n> shapes, 0 duplicates, 0 raw casts`.
#   9 carve:        `carve.py sample $(TH_CARVE)` in its scratch worktree: `k of k carves build` (whole-binary SHA).
#                   Started in the background after rung 1 (fixed ~30 s split+build cost; --per does not shrink it),
#                   joined here; it only reads the main tree.
#  10 draw:         `draw.py` over inventory/groups/twins: `d of m drawable, r refused` + per-reason lines.
#  11 propagate:    `propagate.py check`: per group `g of n members byte-gated (<body>)` (yaml c cut + C file including
#                   the body; the SHA itself is rung 0) and `dedup: registry OK`.
#  12 reconcile:    `reconcile.py verify $(TH_VERIFY)`: the banked member re-checked, `banked at rung r, body unchanged`.
#  13 cites:        `cites.py check`: staged cc1 tree + `k of k citations resolve, 0 stale`.
#  14 levers:       `levers.py check`: `4 of 4 pass groups proven, k of k levers byte-proven`.
#  15 symptoms:     `symptoms.py check`: every idiom entry and lever indexed, 0 unindexed, 0 unresolved.
#  16 permuter:     `permute.py run` on the near draft, $(TH_PERM_ITERS) iterations: >= 100 iterations,
#                   >= 2 distinct candidates (counted from its own compiles.log, -newer the stamp); ~15 s.
#  17 plateau:      `plateau.py classify` on the width draft: `class <c> label seed-structural`.
#  18 wave:         `waves.py status` (every wave): per W<k> `W<k> <n> drafts = <b> banked + <f> failed + <v> no-verdict`.
#  19 ledger:       `ledger.py check`: `<n> rows, 0 unledgered, 0 without draft`.
#  20 harvest:      `harvest.py check` (every wave): per W<k> `W<k> <k> of <k> banked harvested, 0 open`.
#  21 routing:      `waves.py rate --check` (aggregate of every wave, writes no rate.txt): `<k> of <k> buckets routed`.
# Recipes stage every tool through a log file under `set -e` (cookbook C0028: dash, no pipefail).

TH_DIR := .run/tools-health
TH_HARNESS ?= --sample
TH_CARVE ?= --per 5
TH_VERIFY ?= rockx5 800EFE70 --module ovl02
TH_PERM_ITERS ?= 150
TH_PERM_FN := func_80027474
TH_PERM_DRAFT := tools/permuter/drafts/$(TH_PERM_FN)
TH_PERM_RE := ([1-9][0-9]{2,}) iterations, ([2-9]|[1-9][0-9]+) distinct candidates, base [0-9]+ best [0-9]+

# Shell helpers, one shell per recipe: rung <r> <cmd..> runs cmd > <r>.log; need <r> <ERE> asserts a log line;
# new <r> <file> asserts file -newer the stamp; show <r> <ERE> prints matching log lines;
# every <r> <prefix> <ERE>: one `^<prefix>` line per waves/W*/ dir, each matching ERE (R5).
TH_FNS = set -e; mkdir -p $(TH_DIR); \
  fail() { echo "$$who: FAIL $$1 ($${2:-$(TH_DIR)/$$1.log})"; exit 1; }; \
  rung() { r=$$1; shift; "$$@" > $(TH_DIR)/$$r.log 2>&1 || fail $$r; }; \
  need() { grep -Eq "$$2" $(TH_DIR)/$$1.log || fail $$1; }; \
  new() { [ -n "$$(find $$2 -newer $(TH_DIR)/stamp 2>/dev/null)" ] || fail $$1 "$$2 not newer than stamp"; }; \
  show() { grep -E "$$2" $(TH_DIR)/$$1.log || true; }; \
  every() { n=$$(ls -d waves/W*/ 2>/dev/null | wc -l); [ $$n -gt 0 ] || fail $$1 "no waves/W*/"; \
    [ "$$(grep -c "^$$2" $(TH_DIR)/$$1.log)" = $$n ] || fail $$1; \
    ! grep "^$$2" $(TH_DIR)/$$1.log | grep -Evq "$$3" || fail $$1; }

.PHONY: tools-selftest tools-health tools-health-full

tools-selftest:
	@$(TH_FNS); who=tools-selftest; \
	for t in census/inventory:inventory census/boundaries:boundaries census/census:census harness/harness:harness \
	  sig/sig:sig dedup/shapes:shapes dedup/carve:carve dedup/draw:draw dedup/reconcile:reconcile \
	  dedup/propagate:dedup codegen/cites:cites codegen/levers:levers codegen/symptoms:symptoms \
	  permuter/permute:permuter permuter/plateau:plateau \
	  wave/waves:wave wave/gate:gate wave/ledger:ledger wave/harvest:harvest progress/progress:progress; do p=$${t%:*}; n=$${t#*:}; r=selftest-$${p#*/}; \
	  rung $$r $(PY) tools/$$p.py --selftest; need $$r "^$$n: control OK( --|$$)"; \
	  show $$r "^$$n: control OK( --|$$)" | tail -n 1; done

tools-health:
	@$(TH_FNS); who=tools-health; t0=$$(date +%s); touch $(TH_DIR)/stamp; \
	for a in $(ALIASES); do [ "$$(cat build/$$a.check.rc 2>/dev/null)" = 0 ] || fail check build/$$a.check.log; done; \
	rung expected $(MAKE) --no-print-directory expected; \
	rung compile-only $(MAKE) --no-print-directory compile-only; \
	rung selftest $(MAKE) --no-print-directory tools-selftest; show selftest 'control OK'; \
	$(PY) tools/dedup/carve.py sample $(TH_CARVE) > $(TH_DIR)/carve.log 2>&1 & cpid=$$!; \
	rung inventory $(PY) tools/census/inventory.py; need inventory ' of [1-9]'; \
	  need inventory '^inventory: control OK'; new inventory .run/census/inventory.jsonl; \
	  show inventory '^inventory: (control OK|.* of [0-9])'; \
	rung boundaries $(PY) tools/census/boundaries.py; need boundaries ' of [1-9]'; \
	  need boundaries '^boundaries: 0 phantoms, 0 truncations$$'; new boundaries .run/census/boundaries.txt; \
	  show boundaries '^boundaries: '; \
	rung census-dup $(PY) tools/census/census.py dup; need census-dup ' of [1-9]'; \
	  new census-dup .run/census/groups.jsonl; show census-dup '^census: .* of [0-9]'; \
	rung census-report $(PY) tools/census/census.py report; need census-report ' of [1-9]'; \
	  new census-report .run/census/report.txt; \
	  need census-report '^census: stubs [0-9]+ of [1-9][0-9]* game functions \([0-9]+ c, [0-9]+ ledgered\); vendor [0-9]+ asm$$'; \
	  show census-report '^census: \[fleet\] \[(game|vendor)\] |^census: lanes reconcile|^census: stubs '; \
	rung progress $(PY) tools/progress/progress.py check; need progress '^progress: OK$$'; show progress '^progress: '; \
	rung harness $(PY) tools/harness/harness.py $(TH_HARNESS); \
	  need harness '^harness: ([5-9]|[1-9][0-9]+) pairs, 0 disagreements$$'; new harness .run/harness/last.txt; \
	  tail -n 1 $(TH_DIR)/harness.log; \
	rung sig $(PY) tools/sig/sig.py band; need sig ' of [1-9]'; \
	  need sig '^sig: band reproduces ([0-9]+) of \1 exact pairs'; new sig .run/sig/twins.jsonl; \
	  show sig '^sig: band reproduces '; \
	rung types $(PY) tools/dedup/shapes.py check; need types '^types: [1-9][0-9]* shapes, 0 duplicates, 0 raw casts$$'; \
	  show types '^types: '; \
	wait $$cpid || fail carve; need carve '^carve: ([1-9][0-9]*) of \1 carves build$$'; \
	  new carve .run/carve/slus.build.log; show carve '^carve: [0-9]+ of '; \
	rung draw $(PY) tools/dedup/draw.py; need draw '^draw: [0-9]+ of [1-9][0-9]* drawable, [0-9]+ refused$$'; \
	  new draw .run/dedup/draw.jsonl; show draw '^draw: '; \
	rung propagate $(PY) tools/dedup/propagate.py check; need propagate '^dedup: [0-9]+ of [1-9]'; \
	  need propagate '^dedup: registry OK '; show propagate '^dedup: '; \
	rung reconcile $(PY) tools/dedup/reconcile.py verify $(TH_VERIFY); \
	  need reconcile '^reconcile: .* banked at rung r[0-9], body unchanged$$'; show reconcile '^reconcile: '; \
	rung cites $(PY) tools/codegen/cites.py check; need cites '^cites: tree gcc-2.95.2-psx [0-9a-f]{12} \+[0-9]+ patches$$'; \
	  need cites '^cites: ([0-9]+) of \1 citations resolve, 0 stale$$'; show cites '^cites: '; \
	rung levers $(PY) tools/codegen/levers.py check; \
	  need levers '^levers: 4 of 4 pass groups proven, ([0-9]+) of \1 levers byte-proven$$'; show levers '^levers: '; \
	rung symptoms $(PY) tools/codegen/symptoms.py check; need symptoms \
	  '^symptoms: ([0-9]+) of \1 idiom entries indexed, ([0-9]+) of \2 levers indexed, 0 unindexed, 0 unresolved$$'; \
	  show symptoms '^symptoms: '; \
	p0=$$(date +%s); rung permuter $(PY) tools/permuter/permute.py run $(TH_PERM_DRAFT).near.c --fn $(TH_PERM_FN) \
	  --iters $(TH_PERM_ITERS); need permuter '^permuter: $(TH_PERM_FN) $(TH_PERM_RE)$$'; \
	  new permuter .run/permuter/$(TH_PERM_FN)/compiles.log; show permuter '^permuter: '; \
	  pw=$$(($$(date +%s) - p0)); echo "permuter: rung $$pw s"; [ $$pw -le 60 ] || fail permuter "rung wall $$pw s > 60 s"; \
	rung plateau $(PY) tools/permuter/plateau.py classify $(TH_PERM_DRAFT).width.c --fn $(TH_PERM_FN); \
	  need plateau '^plateau: $(TH_PERM_FN) class [a-z-]+ label seed-structural$$'; show plateau '^plateau: '; \
	rung wave $(PY) tools/wave/waves.py status; \
	  every wave 'wave: W' '^wave: W[0-9]+ [1-9][0-9]* drafts = [0-9]+ banked \+ [0-9]+ failed \+ [0-9]+ no-verdict$$'; \
	  show wave '^wave: '; \
	rung ledger $(PY) tools/wave/ledger.py check; need ledger '^ledger: [0-9]+ rows, 0 unledgered, 0 without draft$$'; \
	  show ledger '^ledger: '; \
	rung harvest $(PY) tools/wave/harvest.py check; \
	  every harvest 'harvest: W' '^harvest: W[0-9]+ ([1-9][0-9]*) of \1 banked harvested, 0 open$$'; show harvest '^harvest: '; \
	rung routing $(PY) tools/wave/waves.py rate --check; \
	  need routing '^routing: ([1-9][0-9]*) of \1 buckets routed$$'; show routing '^routing: '; \
	echo "tools-health: OK"; echo "tools-health: $$(($$(date +%s) - t0)) s"

tools-health-full:
	@$(MAKE) --no-print-directory tools-health TH_HARNESS=--full TH_CARVE=
