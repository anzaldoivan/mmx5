#!/usr/bin/env bash
# tools/toolchain/fetch.sh — fetch the old-gcc 0.17 cc1 candidates listed in compilers.txt
# (`<name> <url> <sha256>`, sha256 trust-on-first-use) into tools/bin/cc/<name>/ (gitignored).
# Idempotent: a candidate whose cc1 exists and whose archive hash matches is skipped. Never sudo.
set -euo pipefail
cd "$(dirname "$0")/../.."
dst=tools/bin/cc
mkdir -p "$dst"
while read -r name url sha; do
    [ -z "$name" ] || [ "${name:0:1}" = "#" ] && continue
    tgz="$dst/$name.tar.gz"
    if [ -x "$dst/$name/cc1" ] && [ -f "$tgz" ] && echo "$sha  $tgz" | sha256sum -c --status; then
        continue
    fi
    echo "fetch: $name"
    curl -fsSL -o "$tgz" "$url"
    echo "$sha  $tgz" | sha256sum -c --quiet
    rm -rf "${dst:?}/$name"
    mkdir -p "$dst/$name"
    tar xzf "$tgz" -C "$dst/$name"
done < tools/toolchain/compilers.txt
