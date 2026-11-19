# Contributing to mmx5-decomp

## Bring your own copy of the game

Every contributor extracts from their own legally obtained copy. Commit nothing derived from it. That means no
executable, payloads, disassembly, assets, build output, memory images, database, vendor SDK, or notes that paste the
target's instructions. The `.gitignore` firewall stops the ordinary case. `tools/audit_public.py` refuses the rest and runs in CI
on every push. Review `git status` before every commit.

## What "done" means

A function is matched when it meets both of these conditions. Its compiled output is instruction-identical to the
original, register allocation included, **and** the whole binary's hash check still passes with it linked.
"Functionally equivalent" is never done. Unmatched C lives under the non-matching guard with the assembly stub in the
default build. Verify a match from a clean rebuild, never from an incremental one. A pull request states which
compilation each claim survived (standalone / the real translation unit / the whole binary).

## Names, types and formatting

Rename a symbol only on recorded evidence. Examples of recorded evidence are a string the symbol prints, a
cross-reference chain, a debug menu, a live-memory datapoint, a community label with provenance. **If you are not sure
what something does, leave it unnamed rather than name it wrongly.** The address-named placeholder is honest and
greppable.

Write one definition for each structure. A duplicate type is a defect.

Run `make format` before committing (`.clang-format` is the community's style). Mark anything that exists only to force
a match with `// !FAKE:` and its reason. Mark an original bug with `//! @bug`.

Define a struct or union once, in `include/types.h`, never in `src/`. Name an absolute address (e.g. scratchpad
`0x1F80xxxx`) once in `include/addr.h` as `D_<ADDR>`. Several pointee views of one address are one union. Never cast an
absolute address in `src/`.

Declare a function or data symbol that several files use once, in `include/mmx5/<system>.h`. Use the system where
mmx6 declares the symbol. Otherwise use its system in `config/layout.tsv`. A `slus` symbol without a system goes in
`include/mmx5/globals.h`.

A header holds only prototypes, externs and enum constants. Its guard is `MMX5_<NAME>_H`.
Include only the headers of the symbols the file uses. Never declare a header symbol again in `src/`.
The declaration check of the unit map tool reports each local declaration of a header symbol.

Write a header prototype with empty parameters, for example `void set_animation();`. Empty parameters accept every
argument count. If a caller needs a different return type for its bytes, cast the function at the call:
`((s32 (*)())set_animation)(obj, 2)`. The call stays a direct `jal`.

If files index the bytes of a data symbol, declare it in the header as an unsized array, for example
`extern u8 g_Player[];`. If a file reads it as a struct or scalar, define a view after the includes:
`#define g_Player_as_X4_Obj (*(X4_Obj*)&g_Player)`. Then use the view in that file.

A symbol renamed in `config/symbols.*.txt` needs one accepted row in `config/names.tsv`.
The row has the columns kind, image, scope, old_name, new_name, decision, evidence and reason.
`make readability-check` gates these rules and the type rules above, inside `make no-rom` and in the public CI
(no-rom.yml).

## Source layout

Each function is one compile unit in its own file. A `slus` unit goes in `src/slus/<name>.c`. A `rockx5` unit goes in
the folder of its overlay, `src/rockx5/ovlNN/<name>.c`. A shared body goes in `src/shared/<name>.c`. If you need the
path of a unit, ask `tools/build/layout.py` `locate()` and do not write the path by hand.
`python3 tools/build/layout.py check` reports each file that is not at its path.

## AI use — conduct

AI-use statement to be added before this repository is made public.

The rules that keep that honest, for every contributor and every agent:

1. **The byte gate is the only claim of success.** Never report a match the gate has not proven. The statements
   "it compiled" and "looks equivalent" are not results. "Banked" is written from a tool's printed success line.
2. **Names and types are evidence-based, never guessed.** A model may propose a name. A person with recorded evidence
   asserts one. Hallucinated meaning is the specific way a model damages a decompilation without any test catching it.
3. **Outward text is written by a person.** Issues, pull requests, forum posts and outreach to other projects are written
   by their author. Write them the way a developer writes: short, plain, from the facts. They are never a model draft
   with the tells removed. Before contributing to another project, read and follow its own AI-contribution policy.
4. **No automated traffic against community infrastructure.** Shared services are used by a person in a browser.
   Anything repetitive is replicated locally.
5. **Agents assist. A person owns.** Every change is justifiable by a person from the record (the phase logs, the
   decision log, the cookbook's byte proofs).

## Submitting

Submit small, per-function or per-family pull requests. The hash check must be green on every binary the change
touches. Anything that touches a shared body, a shared header or the executable needs the clean fleet verification.

Before you submit a change to a public file, build both binaries and run `python3 tools/gen_objdiff.py`.
It writes `objdiff.json`, the unit list that the match report in CI reads.
Before you submit a change to a public file, run `python3 tools/psxd_publish.py style <file>`.

Write a commit message that names what was matched and how it was verified. Add no AI-attribution trailers.
