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
absolute address in `src/`. A symbol renamed in `config/symbols.*.txt` needs a row in `config/names.tsv`
(`rules/NAME1.md`: kind, decision and evidence). `make readability-check` gates all of this and runs inside `make no-rom`, the public CI.

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
Write a commit message that names what was matched and how it was verified. Add no AI-attribution trailers.
