#!/usr/bin/env bash
# tools/bootstrap.sh sets up the toolchain of a fresh clone. The root `bash bootstrap.sh <dump.cue>` runs it first.
# It is idempotent and never runs sudo. Its steps, in order:
#   1. system packages      — only CHECKED (dpkg): the missing ones are printed as one install line.
#   2. the Python venv      — .venv, `pip install --require-hashes -r requirements-python.txt`.
#   2b. mipsel binutils     — system ones if on PATH, else the pinned Ubuntu deb (sha256) extracted to tools/bin/binutils/
#                             by dpkg-deb or bsdtar, and wrapped as tools/bin/mipsel-linux-gnu-{as,ld,objcopy} (symlinked into ~/.local/bin).
#   3. submodules           — `git submodule update --init` when .gitmodules exists. None exist today: maspsx and
#                             decomp-permuter are refs/ clones from tools/refs_fetch.sh.
#   4. the vintage compiler — tools/toolchain/fetch.sh: old-gcc cc1 candidates, sha256-checked, into tools/bin/cc/<name>/.
#   5. the preflight        — `make check-env` if the Makefile has it. Its exit status is this script's.

set -euo pipefail
REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$REPO"
say() { printf 'bootstrap: %s\n' "$*"; }

# 1) System packages: this step checks only that they are present. It prints the install line and never runs it.
# The names are Debian and Ubuntu names. Step 2b sets up binutils. Each cc1 tarball of step 4 ships the C preprocessor.

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

# 2) The venv installs pinned requirements. Phase 1 created the file with the extractor's dependencies.

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

# 2b) mipsel binutils (as, ld, objcopy). The preferred route is `sudo apt-get install binutils-mipsel-linux-gnu`.
#     Without sudo, this step extracts the pinned Ubuntu noble deb and wraps it.
#     The sha256 pins are in tools/bin/*.sha256 and docs/ops/toolchain.md.

say "mipsel binutils — preferred system route: sudo apt-get install binutils-mipsel-linux-gnu"
if command -v mipsel-linux-gnu-as >/dev/null 2>&1 && command -v mipsel-linux-gnu-objdump >/dev/null 2>&1; then
    say "mipsel binutils: present ($(command -v mipsel-linux-gnu-as))"
    # mk/slus.mk:9-11 calls tools/bin/mipsel-linux-gnu-*. A fresh clone needs links there to the PATH tools.

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
    rm -rf "$BU" && mkdir -p "$BU"
    if command -v dpkg-deb >/dev/null 2>&1; then
        dpkg-deb -x "$DEB" "$BU"
    else
        # If `dpkg-deb` is absent, `bsdtar` reads the deb.

        bsdtar -xOf "$DEB" 'data.tar*' | bsdtar -xf - -C "$BU"
    fi
    mkdir -p "$HOME/.local/bin"
    for t in as ld objcopy; do
        w="$REPO/tools/bin/mipsel-linux-gnu-$t"
        printf '#!/bin/sh\nLD_LIBRARY_PATH="%s/usr/lib/x86_64-linux-gnu${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}" exec "%s/usr/bin/mipsel-linux-gnu-%s" "$@"\n' \
            "$REPO/$BU" "$REPO/$BU" "$t" > "$w"
        chmod +x "$w"
        [ -e "$HOME/.local/bin/mipsel-linux-gnu-$t" ] || ln -s "$w" "$HOME/.local/bin/mipsel-linux-gnu-$t"  # never repoint the host's links
    done
    "$HOME/.local/bin/mipsel-linux-gnu-as" --version | head -1
fi

# 2c) The deb binutils of step 2b need `libsframe.so.1`. A newer host binutils has only `libsframe.so.3`.
#     This step extracts `libsframe.so.1` from the pinned Ubuntu noble deb.

if [ -d tools/bin/binutils/usr ] && [ ! -e tools/bin/binutils/usr/lib/x86_64-linux-gnu/libsframe.so.1 ]; then
    SDEB=tools/bin/libsframe1.deb
    SURL=http://archive.ubuntu.com/ubuntu/pool/main/b/binutils/libsframe1_2.42-4ubuntu2_amd64.deb
    if ! sha256sum --quiet -c "$SDEB.sha256" >/dev/null 2>&1; then
        say "fetching $SURL"
        curl -fsSL -o "$SDEB" "$SURL"
        sha256sum --quiet -c "$SDEB.sha256"
    fi
    if command -v dpkg-deb >/dev/null 2>&1; then
        dpkg-deb --fsys-tarfile "$SDEB" | tar -x -C tools/bin/binutils --wildcards './usr/lib/x86_64-linux-gnu/libsframe.so.1*'
    else
        # If `dpkg-deb` is absent, `bsdtar` reads the deb.
        bsdtar -xOf "$SDEB" 'data.tar*' | bsdtar -xf - -C tools/bin/binutils --include './usr/lib/x86_64-linux-gnu/libsframe.so.1*'
    fi
    say "libsframe.so.1: installed in tools/bin/binutils/usr/lib/x86_64-linux-gnu"
fi

# 3) Submodules. This step does nothing when they are populated. None exist today.
#    maspsx and decomp-permuter are refs/ clones from tools/refs_fetch.sh.

if [ -f .gitmodules ]; then
    say "submodules: git submodule update --init"
    git submodule update --init
else
    say "no submodules"
fi

# 4) The vintage compiler. This step fetches each old-gcc 0.17 cc1 candidate into its own tools/bin/cc/<name>/.
#    tools/toolchain/compilers.txt lists them with their sha256 (docs/ops/toolchain.md).
#    Never download a file without a checksum. Never vendor a compiler whose license forbids it.
#    Keep a fetch step and a checksum instead.

say "vintage compiler candidates (tools/toolchain/fetch.sh)"
bash tools/toolchain/fetch.sh

# 4b) mkpsxiso and dumpsxiso v2.30 (GPL-2.0, sha256-pinned) go to .run/tools/ for `make disc`.
#     See docs/ops/reference-extractor.md.

MK=.run/tools/mkpsxiso-2.30
if [ ! -x "$MK/mkpsxiso-2.30-Linux/bin/mkpsxiso" ]; then
    say "fetching mkpsxiso v2.30"
    mkdir -p .run/tools
    curl -fsSL -o "$MK-Linux.zip" https://github.com/Lameguy64/mkpsxiso/releases/download/v2.30/mkpsxiso-2.30-Linux.zip
    echo "8e387e6db51dee3eb7cb08f4d59293a24c48f58bd541631acf9301d78015a1fc  $MK-Linux.zip" | sha256sum --quiet -c
    rm -rf "$MK" && python3 -m zipfile -e "$MK-Linux.zip" "$MK" && chmod +x "$MK"/mkpsxiso-2.30-Linux/bin/*
fi

# 5) The preflight runs only if a `check-env` target exists. None exists today. Its exit status is the script's.

if grep -q '^check-env:' Makefile 2>/dev/null; then
    say "make check-env"
    make --no-print-directory check-env
else
    say "no make check-env; bootstrap ends here"
fi
