#!/usr/bin/env bash
# tools/refs_fetch.sh <name>… — clone each named [[ref]] of config/refs.toml into refs/<name> at its pinned ref
# (shallow fetch of the exact commit). Idempotent: a refs/<name> whose HEAD is already the pin is left alone.
# PY (default python3) reads the toml (tomllib). Unknown name or failed fetch → exit 1.
set -euo pipefail
cd "$(dirname "${BASH_SOURCE[0]}")/.."
(($#)) || { echo "usage: bash tools/refs_fetch.sh <name>…" >&2; exit 2; }
for name in "$@"; do
    url= ref=
    read -r url ref < <("${PY:-python3}" -c 'import sys, tomllib
r = [r for r in tomllib.load(open("config/refs.toml", "rb"))["ref"] if r["name"] == sys.argv[1] and "ref" in r]
print(r[0]["url"], r[0]["ref"]) if r else print("- -")' "$name") || true
    if [ -z "${ref:-}" ] || [ "$ref" = - ]; then
        echo "refs_fetch: $name FAILED (no [[ref]] with url+ref in config/refs.toml)" >&2; exit 1
    fi
    dir="refs/$name"
    if [ "$(git -C "$dir" rev-parse -q --verify HEAD 2>/dev/null)" = "$ref" ]; then
        echo "refs_fetch: $name ok (present)"; continue
    fi
    if git init -q "$dir" && git -C "$dir" fetch -q --depth 1 "$url" "$ref" && git -C "$dir" checkout -q FETCH_HEAD; then
        echo "refs_fetch: $name ok (fetched)"
    else
        echo "refs_fetch: $name FAILED (fetch $url $ref)" >&2; exit 1
    fi
done
