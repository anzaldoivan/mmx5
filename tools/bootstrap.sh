#!/usr/bin/env bash
# tools/bootstrap.sh — fresh-clone toolchain setup; the root `bash bootstrap.sh <dump.cue>` runs it first.
# Idempotent; never sudo. Steps, in order:
#   1. system packages      — only CHECKED (dpkg): the missing ones are printed as one install line.
#   2. the Python venv      — .venv, `pip install --require-hashes -r requirements-python.txt`.
#   2b. mipsel binutils     — system ones if on PATH, else the pinned Ubuntu deb (sha256) extracted to tools/bin/binutils/
#                             and wrapped as tools/bin/mipsel-linux-gnu-{as,ld,objcopy} (symlinked into ~/.local/bin).
#   3. submodules           — `git submodule update --init` when .gitmodules exists (none today; maspsx and
#                             decomp-permuter are refs/ clones from tools/refs_fetch.sh).
#   4. the vintage compiler — tools/toolchain/fetch.sh: old-gcc cc1 candidates, sha256-checked, into tools/bin/cc/<name>/.
#   5. the preflight        — `make check-env` if the Makefile has it; its exit status is this script's.
set -euo pipefail
REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$REPO"
say() { printf 'bootstrap: %s\n' "$*"; }

# 1) system packages — presence only; print the install line, never run it.
# Debian/Ubuntu names; binutils is step 2b, the C preprocessor ships with each cc1 tarball (step 4).
PKGS="git make python3-venv clang-format"
if command -v dpkg >/dev/null 2>&1; then
    missing=()
    for p in $PKGS; do dpkg -s "$p" >/dev/null 2>&1 || missing+=("$p"); done
    if ((${#missing[@]})); then
        say "MISSING packages (${#missing[@]}) — run this, then re-run bootstrap:"
        printf '  sudo apt-get install -y %s\n' "${missing[*]}"
    else
        say "packages: all present"
    fi
else
    say "no dpkg on this system — install the equivalents of: $PKGS"
fi

# 2) the venv (pinned requirements; the file is created in Phase 1 with the extractor's dependencies)
if [ ! -x .venv/bin/python ]; then
    say "creating .venv"
    python3 -m venv .venv
fi
if [ -f requirements-python.txt ]; then
    say "installing pinned Python requirements (no-op when satisfied)"
    .venv/bin/pip install -q --disable-pip-version-check --require-hashes -r requirements-python.txt
else
    say "requirements-python.txt missing — skipping pip"
fi

# 2b) mipsel binutils (as/ld/objcopy). Preferred: `sudo apt-get install binutils-mipsel-linux-gnu`. Without sudo:
#     extract the pinned Ubuntu noble deb (sha256 in tools/bin/*.sha256, docs/ops/toolchain.md) and wrap it.
say "mipsel binutils — preferred system route: sudo apt-get install binutils-mipsel-linux-gnu"
if command -v mipsel-linux-gnu-as >/dev/null 2>&1; then
    say "mipsel binutils: present ($(command -v mipsel-linux-gnu-as))"
    # mk/slus.mk:9-11 calls tools/bin/mipsel-linux-gnu-*: link the PATH ones there (fresh clone, T10.c1)
    for t in as ld objcopy; do
        [ -e "tools/bin/mipsel-linux-gnu-$t" ] || ln -s "$(command -v mipsel-linux-gnu-$t)" "tools/bin/mipsel-linux-gnu-$t"
    done
else
    DEB=tools/bin/binutils-mipsel-linux-gnu.deb
    BU=tools/bin/binutils
    URL=http://archive.ubuntu.com/ubuntu/pool/universe/b/binutils-mipsen/binutils-mipsel-linux-gnu_2.42-2ubuntu1cross5_amd64.deb
    if ! sha256sum --quiet -c "$DEB.sha256" >/dev/null 2>&1; then
        say "fetching $URL"
        curl -fsSL -o "$DEB" "$URL" || (cd tools/bin && apt-get download binutils-mipsel-linux-gnu=2.42-2ubuntu1cross5 && mv binutils-mipsel-linux-gnu_*.deb binutils-mipsel-linux-gnu.deb)
        sha256sum --quiet -c "$DEB.sha256"
    fi
    rm -rf "$BU" && dpkg-deb -x "$DEB" "$BU"
    mkdir -p "$HOME/.local/bin"
    for t in as ld objcopy; do
        w="$REPO/tools/bin/mipsel-linux-gnu-$t"
        printf '#!/bin/sh\nLD_LIBRARY_PATH="%s/usr/lib/x86_64-linux-gnu${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}" exec "%s/usr/bin/mipsel-linux-gnu-%s" "$@"\n' \
            "$REPO/$BU" "$REPO/$BU" "$t" > "$w"
        chmod +x "$w"
        ln -sf "$w" "$HOME/.local/bin/mipsel-linux-gnu-$t"
    done
    "$HOME/.local/bin/mipsel-linux-gnu-as" --version | head -1
fi

# 3) submodules (no-op when populated; none: maspsx and decomp-permuter are refs/ clones, tools/refs_fetch.sh)
if [ -f .gitmodules ]; then
    say "submodules: git submodule update --init"
    git submodule update --init
else
    say "no submodules"
fi

# 4) the vintage compiler — fetch each old-gcc 0.17 cc1 candidate (tools/toolchain/compilers.txt, sha256-checked) into
#    its OWN directory tools/bin/cc/<name>/ (docs/ops/toolchain.md). Never download without a checksum to verify against;
#    never vendor a compiler whose license forbids it (keep a fetch step + checksum instead).
say "vintage compiler candidates (tools/toolchain/fetch.sh)"
bash tools/toolchain/fetch.sh

# 5) the preflight (its exit status is ours) — runs only if a `check-env` target exists (none today).
if grep -q '^check-env:' Makefile 2>/dev/null; then
    say "make check-env"
    make --no-print-directory check-env
else
    say "no make check-env; bootstrap ends here"
fi
