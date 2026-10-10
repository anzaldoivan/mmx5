#!/usr/bin/env bash
# roundtrip.sh -- prove the annotations export is a faithful, deterministic record of ghidra/mmx5:
# export A, A2 from $GHIDRA_PROJ (cmp: determinism); fresh import into .run/ghidra-rt/;
# ImportAnnotations A; export B; cmp A B; cmp A docs/oracle/annotations.jsonl (record is current).
# Prints `roundtrip: byte-equal`; exits non-zero on any difference.
# ANN_IN=<jsonl> imports that file into the rebuild instead of A (negative check: cmp A B must fail).
set -euo pipefail
here="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "$here/env.sh"
root="$(cd "$here/../.." && pwd)"
rt="$root/.run/ghidra-rt"
prog=SLUS_013.34

# headless <proj dir> <log tag> <args...>
headless() {
  local proj="$1" tag="$2"; shift 2
  "$GHIDRA_HOME/support/analyzeHeadless" "$proj" "$PROJ_NAME" -process "$prog" -noanalysis \
    -scriptPath "$here/scripts" -log "$rt/$tag.analyze.log" -scriptlog "$rt/$tag.script.log" \
    "$@" > "$rt/$tag.out" 2>&1 || { tail -20 "$rt/$tag.out"; exit 1; }
}
export_to() { headless "$1" "export-$(basename "$2" .jsonl)" -readOnly -postScript ExportAnnotations.java "$2"; }

rm -rf "$rt"; mkdir -p "$rt/proj"
# Ghidra rejects project paths with a '.'-leading element (GhidraURL.checkValidProjectPath), so the
# rebuild in .run/ghidra-rt/proj is reached through an ignored alias inside ghidra/.
proj="$root/ghidra/rt-proj"
ln -sfn "$rt/proj" "$proj"
export_to "$GHIDRA_PROJ" "$rt/A.jsonl"
export_to "$GHIDRA_PROJ" "$rt/A2.jsonl"
cmp "$rt/A.jsonl" "$rt/A2.jsonl"
bash "$here/import.sh" --proj "$proj" > "$rt/import.out"
headless "$proj" import-ann -postScript ImportAnnotations.java "${ANN_IN:-$rt/A.jsonl}"
export_to "$proj" "$rt/B.jsonl"
cmp "$rt/A.jsonl" "$rt/B.jsonl"
[ -n "${ANN_IN:-}" ] || cmp "$rt/A.jsonl" "$root/docs/oracle/annotations.jsonl"
echo "roundtrip: byte-equal"
