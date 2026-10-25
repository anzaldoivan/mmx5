# `docs/` — what goes where

*Installed by decomp-architect (install.py S3) on 2026-10-03 for mmx5-decomp. This folder holds the project's records and references.
The top-level `README.md` is the usage entry point. Knowledge has a home by KIND, not by the session that produced it. A note written for
one session is scratch (`.run/`). The durable result it produced goes into one of the files below, and the note is archived.*

| Kind of knowledge | Where it goes | The rule behind it |
|---|---|---|
| A compiler idiom proven on the bytes (the residual, the mechanism, the lever, the byte proof) | one `cookbook/C<nnnn>.md` entry written by `tools/cookbook_add.sh`, tagged by symptom in `cookbook/INDEX.md` (grepped, never read whole) | the flywheel: consult before a match, feed back after |
| A norm of conduct the project adopts (a "never X" / "always Y when Z") | one `rules/<id>.md` written by `tools/rules_add.py`, proposed as a `Rule candidate:` and adjudicated by the phase planner | Rules accumulate. They are never added unilaterally. |
| A strategic pivot: what was believed, what failed, the measurement, the hindsight | `GENERATION_PLAN.md` `## Changes`, written while fresh. A standing decision goes to the standing decisions of `HOW_WE_WORK.md`. | capture the why while it hurts |
| A late discovery that would have sped up an earlier phase. The entry says what it is, when it was found, when it *could* have been found and what it would have saved. | a `cookbook/` entry (`tools/cookbook_add.sh`) | the ledger a future project starts from |
| A procedure people run (the wave, the publication) | a runbook under `docs/`. A superseded runbook carries a banner at the top and is then archived. | one runbook is the procedure |
| An environment or tool fact (a version, a flag, a hook, a row per tool) | a topic under `docs/ops/` (the decomp facts: `docs/ops/decomp-environment.md`), in the same change as the tool. A standing decision goes to `HOW_WE_WORK.md` only through PA3's routing. | keep the ops reference current |
| An address, with its source and its verification status | `docs/memory-map.md` | address provenance and region tags |
| A file or container format | `docs/formats.md` (the medium's layout). The medium has the main exe SLUS_013.34 (534528 bytes, text at 0x80010000, entry 0x8005894C). It also has a code-overlay archive ROCK_X5.BIN (lead: 59 descriptors, 53 code, loaded at 0x800EE970 / 0x800FA000). It has the ROCK_X5.DAT data archive, STR/ FMV and XA/BGM.XA audio. It has one MODE2/2352 data track. | — |
| The state of the open phase. Then the phase's synthesis. | `phase-ends/current/` → `phase-ends/PhaseEnd_Phase<N>.md`, assembled by PA3's scripts. `phase-ends/current/` holds the plan, written only by `tools/plan_edit.py`. It also holds the task summaries and logs. At a hand-off, it holds a `TASK_PROGRESS.md`. | the hand-off is written to be replayed (G59) |
| How the project is used: building, verifying, contributing, its layout and conventions | the top-level `README.md` and the topic files under `docs/` | — |
| How to mod the build: toggles, patch sets, asset edits | `docs/modding.md` ([modding.md](modding.md)) | — |
| A design note, a frontier analysis, a triage ladder, a worklist for one session | `.run/<session>/` while live. Once its result is in the record above, the note moves to the archive. It is never a reference. | see the archive |

**Authored versus generated.** Numbers are generated, never typed. A tool produces every progress figure, badge, timeline
row and census in a published document from the tree. The tool asserts the published copy is fresh. A generated file
says so on its first line. Edits go to the generator.

A number that has to appear in prose is a dated snapshot with the command that produced it. Snapshots of a state that
no longer exists are frozen, not regenerated.

**Placeholders.** A tracked document never pastes a literal double-brace placeholder token. It names the placeholder in prose.
The install-time placeholder audit cannot tell a quotation from an unfilled placeholder, and it must stay a true signal.

**Links.** Nothing links into the archive (`docs/retired/`), and its index names files as backticked
paths with the version they were archived at. A backticked path is a citation, not a link. A link checker classifies
cited paths as TRACKED or UNTRACKED by asking git, never the disk.

**The archive.** A document leaves `docs/` when its purpose is fulfilled and its information lives elsewhere. The document
moves by `git mv` into `docs/retired/` under the same relative path. It gets one archive index row (what it was, what
came of it, where it lives now) and a review row for the owner. Deletion is the owner's decision, never part of the
move. Every referrer is re-pointed first (a `git grep` over the tree must return only the two index files).
