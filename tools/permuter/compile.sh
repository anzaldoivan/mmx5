#!/usr/bin/env bash
# compile.sh — decomp-permuter compile command: `compile.sh in.c -o out.o`.
# Mirrors the C rule of mk/slus.mk (CPP, CPPFLAGS, CC1, CFLAGS, MASPSX, AS, CC_ASFLAGS) exactly, so a permuter
# object is byte-identical to the `make` object of the same source (T5.c1: cmp-proven on func_80027474).
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
IN="$1"; OUT="$3"
BINARY="${BINARY:-slus}"
CC_DIR="$ROOT/tools/bin/cc/gcc-2.95.2-psx"

"$CC_DIR/cpp" -lang-c -D__GNUC__=2 -Dmips -D__mips__ -Dpsx -D__psx__ -D_MIPSEL -D__CHAR_UNSIGNED__ -D__OPTIMIZE__ \
    -I "$ROOT/include" "$IN" \
  | "$CC_DIR/cc1" -O2 -G0 -quiet -w \
  | python3 "$ROOT/refs/maspsx/maspsx.py" --aspsx-version=2.86 \
  | "$ROOT/tools/bin/mipsel-linux-gnu-as" -EL -march=r3000 -no-pad-sections -G0 -I "$ROOT/asm/$BINARY/include" -o "$OUT"
