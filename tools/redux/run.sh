#!/usr/bin/env bash
# run.sh -- run a Lua script in the pinned PCSX-Redux against the retail disc (T3).
#
#   tools/redux/run.sh <script.lua> [extra emulator args]
#
# Env: REDUX_ADDR (default 0x80010000), REDUX_EXPECT_ADDR (file slice compared; default REDUX_ADDR),
#      REDUX_FRAMES, REDUX_TIMEOUT (s, default 120). Exit = the script's PCSX.quit(code); 124 = timed out.
# Output (stdout of the emulator) goes to .run/redux/<script>.log. Pin: tools/bin/pcsx-redux.sha256.
set -u
ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
APP="$ROOT/tools/bin/PCSX-Redux-ff4033ac-x86_64.AppImage"
CUE="$ROOT/disks/Megaman X5 (U) [SLUS-01334].cue"
EXE="$ROOT/extracted/retail/SLUS_013.34"
SCRIPT="$(realpath "${1:?usage: run.sh <script.lua> [args]}")"; shift
OUT="$ROOT/.run/redux"; mkdir -p "$OUT"
[ -x "$APP" ] || { echo "redux: missing $APP (fetch: docs/ops/oracles.md)"; exit 2; }

export REDUX_ADDR="${REDUX_ADDR:-0x80010000}"
# expected sha1 of the exe file slice at offset 0x800 + (addr - t_addr); hash only, never bytes
export REDUX_EXPECT_SHA1="$("${PY:-python3}" - "$EXE" "${REDUX_EXPECT_ADDR:-$REDUX_ADDR}" <<'EOF'
import hashlib, struct, sys
data = open(sys.argv[1], 'rb').read()
t_addr = struct.unpack_from('<I', data, 0x18)[0]
off = 0x800 + int(sys.argv[2], 0) - t_addr
print(hashlib.sha1(data[off:off + 256]).hexdigest())
EOF
)"

LOG="$OUT/$(basename "$SCRIPT" .lua).log"
cd "$OUT"
# timeout signals its whole process group, so the AppImage runtime's child dies with it
timeout -k 10 "${REDUX_TIMEOUT:-120}" "$APP" -no-ui -stdout -fastboot -iso "$CUE" -run -dofile "$SCRIPT" "$@" >"$LOG" 2>&1
rc=$?
grep '^redux:' "$LOG"
[ $rc -eq 124 ] && echo "redux: timed out after ${REDUX_TIMEOUT:-120}s (log $LOG)"
exit $rc
