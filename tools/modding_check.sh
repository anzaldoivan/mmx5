#!/usr/bin/env bash
# tools/modding_check.sh — checks that docs/modding.md documents every modding toggle with a verifying command.
# For each toggle literal: a `## ` heading containing it, and a fenced block inside that section containing it.
# Usage: bash tools/modding_check.sh [file]   (default docs/modding.md)
set -u
doc="${1:-docs/modding.md}"
[ -f "$doc" ] || { echo "modding-check: no file $doc"; exit 1; }
toggles=("BINARY=" "SHIFT=1" "PATCHES=" "ASSET_EDIT=" "disc-assets" "replay-check" "contract.sh")
k=0
for t in "${toggles[@]}"; do
  # In the first `## ` section whose heading contains $t, find $t on a line inside a ``` fence.
  if awk -v t="$t" '
    /^## / { if (insec) exit; if (index($0, t)) insec = 1; next }
    insec && /^```/ { infence = !infence; next }
    insec && infence && index($0, t) { found = 1; exit }
    END { exit !found }' "$doc"; then
    k=$((k + 1))
  else
    echo "modding-check: MISS $t"
  fi
done
echo "modding-check: $k of ${#toggles[@]} toggles documented with a verifying command"
[ "$k" -eq "${#toggles[@]}" ]
