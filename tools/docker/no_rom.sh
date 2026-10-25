#!/usr/bin/env bash
# no_rom.sh -- `make no-rom` in the build container, for a host that cannot run it (a Mac): the floor's game check,
# `[own] gate` of config/psxdecomp.toml, which the pre-push hook runs. ROM-free like no-rom itself: no disc is read.
#   bash tools/docker/no_rom.sh
# The working tree (tracked + untracked-unignored files) replaces the source on volume ${MMX5_NO_ROM_VOLUME:-mmx5-push},
# committed there in a fresh repository (the audit lists files with git; src/ and config/ keep their tree hashes).
# The volume keeps the toolchain between runs: .venv, refs/, tools/bin/ and .run/ (CPython 3.14 for the pinned wheels
# in .run/uv). Image mmx5-build (tools/docker/Dockerfile), built when absent. The setup's output goes to
# .run/no_rom.setup.log on the volume; the last line is make's. Exit status: make no-rom's.
set -euo pipefail
cd "$(git rev-parse --show-toplevel)"
VOL="${MMX5_NO_ROM_VOLUME:-mmx5-push}"
IMG=mmx5-build
PLAT=linux/amd64
docker image inspect "$IMG" >/dev/null 2>&1 || docker build -q --platform "$PLAT" -t "$IMG" tools/docker >/dev/null
git ls-files -co --exclude-standard -z \
  | while IFS= read -r -d '' f; do [ -e "$f" ] && printf '%s\0' "$f"; done \
  | COPYFILE_DISABLE=1 tar --no-xattrs --no-mac-metadata --null -T - -cf - \
  | docker run -i --rm --platform "$PLAT" -v "$VOL":/work -w /work -e UV_PYTHON_INSTALL_DIR=/work/.run/uv "$IMG" sh -c '
      set -e
      find /work -mindepth 1 -maxdepth 1 ! -name .run ! -name .venv ! -name refs ! -name tools -exec rm -rf {} +
      if [ -d tools ]; then find tools -mindepth 1 -maxdepth 1 ! -name bin -exec rm -rf {} +; fi
      tar -xf - -C /work
      git init -q && git add -A && git -c user.name=no-rom -c user.email=no-rom@localhost commit -q -m "the synced tree"
      mkdir -p .run
      {
        python3 -m pip install -q --break-system-packages uv
        uv python install 3.14
        .venv/bin/python -c "" 2>/dev/null || { rm -rf .venv; "$(uv python find 3.14)" -m venv .venv; }
        bash tools/bootstrap.sh
        PY=.venv/bin/python bash tools/refs_fetch.sh maspsx decomp-permuter old-gcc
        bash tools/codegen/stage.sh
      } > .run/no_rom.setup.log 2>&1 || { tail -5 .run/no_rom.setup.log; echo "no_rom.sh: setup FAILED"; exit 1; }
      PATH=/work/.venv/bin:$PATH make --no-print-directory no-rom'
