#!/usr/bin/env bash
# import.sh [--proj DIR] -- headless import of SLUS_013.34 into $GHIDRA_PROJ/$PROJ_NAME
# (PSX Executables Loader, auto-analysis, RecordPsyq.java, ImportOverlays.java: code overlays of
# docs/oracle/loadmap.json as ovlNN blocks; CreateOverlayFunctions.java: FUN_ functions there and at fn-pointer-only exe code). Default project only: ImportAnnotations.java applies
# docs/oracle/annotations.jsonl, ExportBoundaries.java writes docs/oracle/boundaries.txt.
# Idempotent (-overwrite). Prints `PsyQ Version: <v>`; exits non-zero if the version is empty.
set -euo pipefail
case "${1:-}" in -h|--help) echo "usage: import.sh [--proj DIR]  (default \$GHIDRA_PROJ=ghidra/; prints PsyQ Version; default project also gets annotations + boundaries.txt)"; exit 0;; esac
here="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "$here/env.sh"
root="$(cd "$here/../.." && pwd)"
post=(-postScript ImportAnnotations.java "$root/docs/oracle/annotations.jsonl"
  -postScript ExportBoundaries.java "$root/docs/oracle/boundaries.txt")
ovl=(-postScript ImportOverlays.java -postScript CreateOverlayFunctions.java)
# --proj (roundtrip rebuild): overlay blocks without analysis or functions (time cap); no annotations, no boundaries.
[ "${1:-}" = "--proj" ] && { GHIDRA_PROJ="$2"; post=(); ovl=(-postScript ImportOverlays.java noanalysis); }
mkdir -p "$GHIDRA_PROJ" "$root/.run"
out="$root/.run/ghidra-import.out"
# No -loader-ramStart: its custom option type rejects CLI strings; the default (0x80000000)
# leaves ramBase == DEF_RAM_BASE, so the base-mismatch OptionDialog cannot fire.
"$GHIDRA_HOME/support/analyzeHeadless" "$GHIDRA_PROJ" "$PROJ_NAME" \
  -import "$root/extracted/retail/SLUS_013.34" -overwrite \
  -loader PsxLoader \
  -scriptPath "$here/scripts" -postScript RecordPsyq.java "${ovl[@]}" "${post[@]}" \
  -log "$root/.run/ghidra-import.analyze.log" -scriptlog "$root/.run/ghidra-import.script.log" \
  > "$out" 2>&1 || { tail -20 "$out"; exit 1; }
line="$(grep -o 'PsyQ Version: .*' "$out" | tail -1 | sed 's/ *(GhidraScript) *$//')"
echo "${line:-PsyQ Version: }"
grep -o 'overlay skipped: .*\|overlays loaded: .*\|overlay functions: .*\|exe functions: .*\|boundaries: .*' "$out" | sed 's/ *(GhidraScript) *$//' || true
[ -n "${line#PsyQ Version: }" ] || { echo "empty PsyQ version; see $out" >&2; exit 1; }
grep -q 'overlays loaded: ' "$out" || { echo "ImportOverlays failed; see $out" >&2; exit 1; }
[ ${#post[@]} -eq 0 ] || grep -q 'boundaries: ' "$out" || { echo "ExportBoundaries failed; see $out" >&2; exit 1; }
