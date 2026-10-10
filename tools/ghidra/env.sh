# env.sh -- pinned Ghidra toolchain paths (source me). See docs/ops/oracles.md.
_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
export GHIDRA_HOME="$_root/tools/bin/ghidra_12.1.3_PUBLIC"
export JAVA_HOME=/home/linuxbrew/.linuxbrew/opt/openjdk@21
export GHIDRA_PROJ="$_root/ghidra"
export PROJ_NAME=mmx5
unset _root
