#!/usr/bin/env bash
# land_check.sh <tree>: the byte check of an exported tree ([public].land_check; psxd_publish.py land and ship run it on
# a tree that holds tracked files only). The tree is copied to a temporary folder and built there with this checkout's
# ignored inputs linked in (the extraction, the fetched toolchain, the venv, maspsx): this checkout is never written.
# Exit 0 only when every config/check.*.sha line holds.
set -euo pipefail
tree=${1:?usage: land_check.sh <tree>}
dev=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
work=$(mktemp -d)
trap 'rm -rf "$work"' EXIT
cp -a "$tree/." "$work/"
rm -rf "$work/.git" "$work/tools/bin"
for p in extracted tools/bin .venv refs; do
    [ -e "$dev/$p" ] || { echo "LAND-CHECK FAIL $dev/$p is missing (bash bootstrap.sh <dump.cue>)"; exit 1; }
    rm -rf "${work:?}/$p" && ln -s "$dev/$p" "$work/$p"
done
cd "$work"
n=0; t=0
for cfg in config/splat.*.yaml; do
    a=${cfg#config/splat.}; a=${a%.yaml}; t=$((t + 1))
    if make --no-print-directory split build BINARY="$a" > "$work/$a.log" 2>&1 && sha1sum --quiet -c "config/check.$a.sha"; then
        n=$((n + 1))
    else
        echo "LAND-CHECK $a FAIL"; grep -v 'asm/\|\.s:' "$work/$a.log" | tail -5
    fi
done
echo "LAND-CHECK $n of $t"
[ "$n" = "$t" ]
