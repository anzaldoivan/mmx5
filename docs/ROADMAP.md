# Roadmap

This file gives the plan of the decompilation in phases. The [backlog](BACKLOG.md) lists the known defects and the
planned work, item by item.

## Where we are

The census counts 7647 game functions. The numbers come from [docs/progress.md](progress.md).

- 7552 functions have the status finished: they are in C, and the build is byte-identical. That is 98.8%.
- 95 functions are open: they are still in assembly, and each one has a ledger row. That is 1.2%.
- 100 functions have a name. That is 1.3%.

The current work is Generation 4, the clean final repository. Its goal is to complete the C and to leave a clean
repository. Each file must be a compile unit, with one declaration for each symbol. The public repository must ship
only what a person needs to build, check, mod and contribute. Both binaries stay byte-identical from a clean rebuild.

## Generation 4

### 4.1: The census content check and the overlay folders

- Status: done
- What and why: The census now reads each C file. It counts a function that a file pulls in as assembly as
  assembly. Before this phase, six files that held only assembly counted as C. Each `ROCK_X5.BIN` file moved to the
  folder of its overlay, `src/rockx5/ovlNN/`.
- Result: The census prints `census: stubs 0 of 7647 game functions`. The layout check prints 0 hard-coded paths and
  0 misplaced files.

### 4.2: The public face

- Status: done
- What and why: The public repository ships only what a person needs. The README has eight sections. The progress
  tool writes [docs/progress.md](progress.md) and three badges.
- Result: Clone the repository and run the three commands of the README. Then `make check` prints
  `check: 2 of 2 green, 0 failed`.

### 4.3: The unit map and the merge dry run

- Status: done
- What and why: Each C function gets one proposed compile unit, with the evidence for its boundary. A dry run
  compiles each proposed unit and counts the results. These counts set the size of phases 4.4, 4.5 and 4.6.
- Result: The dry run prints four counts in functions. Their sum is 7483. No tracked file in `src/` changes.

### 4.4: One declaration per symbol

- Status: done
- What and why: Each system gets one header. A header declaration replaces each local declaration. Conflicts of
  declarations between sibling functions were the main stop when the Mega Man X6 decompilation merged files.
- Goal: Each conflicting symbol has one header declaration, or it is held with its cause. Conflict units fall below
  369, and no unit that compiled identical before regresses. No source file declares a symbol that a header declares.
- Result: The headers in `include/mmx5/` declare 229 symbols. The dry run now stops on 64 units, down from 369.
  All 772 units that compiled identical before are still identical. Two data symbols are held, because their users
  read them as arrays of different element types. Both binaries stay byte-identical.

### 4.5: Merge I: shared bodies and overlays

- Status: done
- What and why: The files of each overlay of `ROCK_X5.BIN` merged into their compile units. Each overlay merged in
  its own commit. Each shared body now has the name of its owner function. Each other file that uses the body renames
  it only around its include. The merge also removed the pipeline banners, the dead aliases and the rename comments.
- Result: The phase merged 923 of the 994 multi-function units of `ROCK_X5.BIN`. It held 71 units with their cause:
  62 have conflicting types, 5 compile differently, and 4 would rename a header by accident. The phase also joined
  196 runs of shared bodies, 589 bodies, into one file each. The `src/shared/` folder went from 1136 files to 743.
  Each overlay was byte-identical from a clean rebuild after its commit. The shifted build and the patch build stay
  green.

### 4.6: Merge II: SLUS and the system folders

- Status: done
- What and why: The files of `SLUS_013.34` merge into their compile units. Merged units with an accepted name go into
  system folders. Units without a name stay under their address names.
- Result: The phase merged 149 of the 152 multi-function units of `SLUS_013.34`, in five batches. It held 3 units
  with their cause: 2 have conflicting types, and 1 compiles its constant data in a different order. 81 of the 86
  units with a game name moved into 19 system folders, such as `player` and `ladder`. The other 5 stay flat, and the
  placement record gives the cause of each. Both binaries stayed byte-identical from a clean rebuild after each commit.
  The shifted build and the patch build stay green.

### 4.7: The ledger after the merge

- Status: done
- What and why: Some open functions may need the other functions of their unit to match. The tools learned to try
  and bank a function inside its merged unit. The tools that copy a body to its twins and rename functions now take
  merged units. Then each open function that had never had a coder got one capped pass.
- Result: The open count fell from 164 to 96. 5 of the 7 functions tagged for their unit matched inside it. 54 of the
  93 functions marked as walls without a coder matched in one pass of at most 20 tries. 13 byte twins of these came
  free. Each of the 40 functions that stay open records its 4.7 wave and its blocker in the ledger. Both binaries
  stayed byte-identical after each commit.

### 4.8: Names, types and data

- Status: done
- What and why: Functions, types and data get names, each with recorded evidence. One pass removes the comments that
  do not tell why. The readability scan gets checks for task ids, banners and end markers.
- Result: The named count rose from 37 to 100 functions, and 24 game variables have names. Each new name has a recorded
  source. Shared globals got one home header each, and the type conflicts fell from 141 to 59. 11 data blocks are now
  defined in C. `make readability-check PY=...` prints `0 task ids, 0 banners, 0 end markers` with its other zero
  counts. Both binaries stayed byte-identical after each commit.

### 4.9: The version axis

- Status: done
- What and why: The build learns to select a game version. US stays the only version in this phase. The
  paths change once, before the release, so that they stay the same after it.
- Result: Both binaries stay byte-identical with `VERSION=us`. `make check` prints `check: 2 of 2 green, 0 failed`.
  Build outputs are under `build/us/`, and address-bound config is under `config/us/`. The file
  `config/versions.tsv` lists each version, and `make check-all` checks each one.
- Code: The executable has the build name `main`. C code tests the version with `#if VERSION >= VER_US`. The style
  check refuses `#ifdef VERSION_US`.

### 4.10: Validation: the clean repository

- Status: next
- What and why: This phase proves the final tree from a clean rebuild. A fresh clone builds and checks with the
  commands of the README alone. The README, the progress page and the badges get the final numbers.
- Result: The build contract record is current. The check of the decomp.dev report prints `REPORT OK (0 errors)`.

## After Generation 4

Generation 5 goes beyond the disc. Its subjects are a native port or a recompilation from the source, and tools for a
randomizer. It also covers the other regions of the game: `SLPM-86666`, `SLPM-87021` and `SLES-03557`. These
subjects depend on the shiftable build.
