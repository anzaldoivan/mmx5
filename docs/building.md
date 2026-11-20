# Building

This file gives the detail of the build. The top-level [README](../README.md) gives only the three commands. Each
section names a command and the line that the command prints on success.

## Requirements

You need these items:

- Linux on x86-64. WSL 2 counts.
- Git, Bash and Make.
- Python 3.14 with `venv`.
- `clang-format`.
- Your own dump of *Mega Man X5* (USA), SLUS-01334, as `.cue` + `.bin`.

The `python3` command must be Python 3.14, because the pinned Python packages are CPython 3.14 builds. The dump
never enters the repository. The `disks/` folder and everything extracted from the dump are git-ignored.

If `python3` is not Python 3.14, set `PY=<python>`. The Makefile and `bootstrap.sh` both read `PY` and default to
`python3`. The text writes `PY=...` for the path to your Python interpreter.

## Bootstrap

Run this command once after the clone.

```sh
bash bootstrap.sh /path/to/your/dump.cue
```

The script makes the venv and installs binutils, the pinned compiler and maspsx. Then it extracts the dump. It
fetches every tool by pinned checksum or commit. It checks that the extraction manifest equals the tracked
`extracted/retail/manifest.jsonl`. On success, it prints `bootstrap: OK`.

The script remembers the path of your dump in an ignored file. Then `make extract` and `make check` use that path as
their default `CUE=`. To use another dump, give `CUE=/path/to/dump.cue` to make.

If you give no argument, the script prepares the toolchain alone. Then it prints a usage line and exits with code 2.

## Build and check

Run this command to build and check every binary.

```sh
make check
```

The command splits, assembles, compiles and links each binary, then checks the hash of each binary. On success, it
prints these lines:

```text
check: slus ok
check: rockx5 ok
check: 2 of 2 green, 0 failed
```

After a green line, `make check` runs the [shift-scan](modding.md#shift-scan). A finding or a missed plant makes
`make check` fail. To build one binary, use [`BINARY=`](modding.md#binary).

## Rebuild the disc

Run this command to rebuild the whole disc.

```sh
make disc PY=...
```

The command uses your extraction plus the built `SLUS_013.34` and `ROCK_X5.BIN`. It regenerates the overlay table of
`ROCK_X5.BIN` from the overlay sizes. It writes the disc into `build/disc/mmx5.cue` + `.bin`. The image format is in
[formats.md](formats.md). When the image is identical to the retail track, the command prints
`disc: track sha1 10709231f857636b5ccd3cd9acebc91458dcb5fd OK`.

Disc images are git-ignored. The firewall refuses them.

## Boot the rebuilt disc

`make replay-check` boots the original and the rebuilt image in the pinned PCSX-Redux and compares them. The
[modding guide](modding.md#replay-check) gives its command and its success lines.

To run a Lua script of your own on the rebuilt image, run this command.

```sh
REDUX_CUE=build/disc/mmx5.cue bash tools/redux/run.sh <script.lua>
```

The exit code is the code that the script gives to `PCSX.quit`. The code 124 means a timeout.

## Checks that need no game file

These checks read no game file. You can run them before you have a dump.

```sh
make firewall-check PY=...
make no-rom PY=...
```

`make firewall-check` plants controls and requires the audit to catch each one. It prints
`firewall-check: assets control caught` and, on success, `firewall-check: OK (control caught, tree clean)` as its
last line.

`make no-rom` runs the same steps as CI: `firewall-check`, `format-check`, `compile-only`, `readability-check` and
`selftest`. It stops at the first failure. On success, it prints `no-rom: OK`.
