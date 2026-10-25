#!/usr/bin/env bash
# bootstrap.sh <dump.cue> — fresh clone to a verified extraction in one command:
#   tools/bootstrap.sh (packages check, venv, binutils, cc1 candidates) → tools/refs_fetch.sh (maspsx, decomp-permuter, old-gcc
#   at the config/refs.toml pins) → tools/codegen/stage.sh → make extract CUE=<dump.cue> → extracted/retail/manifest.jsonl must equal the tracked one.
# Idempotent. PY (default python3) runs the Python steps.
set -euo pipefail
cd "$(dirname "${BASH_SOURCE[0]}")"
PY="${PY:-python3}"
bash tools/bootstrap.sh
PY="$PY" bash tools/refs_fetch.sh maspsx decomp-permuter old-gcc
bash tools/codegen/stage.sh   # refs/gcc-2.95.2-psx: the cc1 source tree tools-health's cites rung audits (T10)
if (($# < 1)); then
    echo "usage: bash bootstrap.sh <dump.cue>  — Mega Man X5 (USA), Redump #7437 (docs/ops/medium-identity.md)" >&2
    exit 2
fi
make --no-print-directory extract CUE="$1" PY="$PY"
if ! git diff --exit-code --quiet -- extracted/retail/manifest.jsonl; then
    echo "bootstrap: FAILED — extracted/retail/manifest.jsonl differs from the tracked one (not the Redump #7437 dump?)" >&2
    exit 1
fi
mkdir -p .run && realpath "$1" > .run/dump-cue  # make extract/check default CUE (Makefile)
echo "bootstrap: OK"
