#!/usr/bin/env bash
# stage.sh — stage the pinned cc1's source: vanilla gcc-2.95.2 + old-gcc's -psx patch steps
# (refs/old-gcc/gcc-2.95.2-psx.Dockerfile, source-edit steps only; no configure/build).
# Output: refs/gcc-2.95.2-psx/ (gitignored) + refs/gcc-2.95.2-psx/.staged. Idempotent.
# --permuter: instead, clone decomp-permuter at its config/refs.toml pin into refs/decomp-permuter/. Idempotent.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
REFS="$ROOT/refs"

if [ "${1:-}" = "--permuter" ]; then
  PIN="$(awk '/^name *= *"decomp-permuter"/{f=1} f && /^ref/{gsub(/[" ]/,"",$0); sub(/ref=/,"",$0); print; exit}' "$ROOT/config/refs.toml")"
  [ -n "$PIN" ] || { echo "stage: no decomp-permuter ref in config/refs.toml"; exit 1; }
  P="$REFS/decomp-permuter"
  if [ "$(git -C "$P" rev-parse HEAD 2>/dev/null)" = "$PIN" ]; then echo "stage: decomp-permuter up to date"; exit 0; fi
  [ -d "$P/.git" ] || git clone -q https://github.com/simonlindholm/decomp-permuter "$P"
  git -C "$P" fetch -q origin "$PIN" 2>/dev/null || true
  git -C "$P" checkout -q "$PIN"
  echo "stage: decomp-permuter at ${PIN:0:12}"
  exit 0
fi
URL="https://ftp.gnu.org/gnu/gcc/gcc-2.95.2.tar.gz"
TARBALL="$REFS/gcc-2.95.2.tar.gz"
TREE="$REFS/gcc-2.95.2-psx"
OLDGCC="$REFS/old-gcc"
PATCHES=(obstack-2.95.2.h.patch mips.patch psx-2.91.patch)
SED_STEP="sed -i -- 's/include <varargs.h>/include <stdarg.h>/g' */*.c"

# sha256 of the gcc-2.95.2-src entry in config/refs.toml
WANT_SHA="$(awk '/^name *= *"gcc-2.95.2-src"/{f=1} f && /^sha256/{gsub(/[" ]/,"",$0); sub(/sha256=/,"",$0); print; exit}' "$ROOT/config/refs.toml")"
[ -n "$WANT_SHA" ] || { echo "stage: no gcc-2.95.2-src sha256 in config/refs.toml"; exit 1; }

if [ ! -f "$TARBALL" ]; then
  curl -fsSL -o "$TARBALL.part" "$URL"
  mv "$TARBALL.part" "$TARBALL"
fi
GOT_SHA="$(sha256sum "$TARBALL" | cut -d' ' -f1)"
[ "$GOT_SHA" = "$WANT_SHA" ] || { echo "stage: tarball sha256 $GOT_SHA != $WANT_SHA"; exit 1; }

# expected .staged content
STAMP="tarball_sha256=$GOT_SHA
old_gcc_ref=$(git -C "$OLDGCC" rev-parse HEAD)
step=$SED_STEP"
for p in "${PATCHES[@]}"; do
  STAMP+=$'\n'"patch=$p $(sha256sum "$OLDGCC/patches/$p" | cut -d' ' -f1)"
done

if [ -f "$TREE/.staged" ] && [ "$(cat "$TREE/.staged")" = "$STAMP" ]; then
  echo "stage: up to date"
  exit 0
fi

rm -rf "$TREE" "$REFS/gcc-2.95.2"
tar xzf "$TARBALL" -C "$REFS"
mv "$REFS/gcc-2.95.2" "$TREE"
(
  cd "$TREE"
  # ponytail: Docker's /bin/sh is dash (no globstar): `**/*.c` expands as `*/*.c`, one level deep
  sed -i -- 's/include <varargs.h>/include <stdarg.h>/g' */*.c
  patch -u -p1 include/obstack.h -i "$OLDGCC/patches/obstack-2.95.2.h.patch"
  patch -u -p1 gcc/config/mips/mips.h -i "$OLDGCC/patches/mips.patch"
  patch -su -p1 < "$OLDGCC/patches/psx-2.91.patch"
)
printf '%s\n' "$STAMP" > "$TREE/.staged"
echo "stage: staged $TREE (${GOT_SHA:0:12} +${#PATCHES[@]} patches)"
