# tools/census

`inventory.py` is the function inventory (corpus oracle). It runs on a post-`make check` tree (asm/ + build maps).

    PY tools/census/inventory.py [--alias A] [--selftest]

- Aliases: `config/splat.<a>.yaml`. Functions: `glabel`s in `.text` of `asm/<a>/**/*.s` (status `asm`) + yaml `c`
  subsegments (status `c`, extent from the map `.text` section). Module/kind from `docs/oracle/segments.txt`
  (overlay → `game`). The tool keys the rows by (alias, module, vram), same-vram overlays apart (C0019).
- Text bytes = map `.text` sections ∪ segments.txt text ranges. Byte class precedence: rodata (segments.txt rodata
  ranges, `dlabel` words, non-asm subsegments e.g. `bin`/`textbin`, a function's words after its last `jr`/`j`
  (+ delay slot) or `break` when its tail is splat `invalid instruction` words) > function > padding (unlabelled zero word).
- Output: `.run/census/inventory.jsonl`, one row `{"alias","module","kind","name","vram","insns","status"}`
  (vram 8 hex upper). Prints per alias `inventory: <n> of <m> functions [a]` (m = map symbol starts less data and
  in-function labels), `inventory: <fn> of <y> text bytes [a]`, the byte breakdown, `uncovered:` runs,
  `excluded: <module> -- <reason>` (from docs/oracle/loadmap.json), and `inventory: control OK -- <k> of <k> c`.
- `--selftest`: the synthetic fixture `fixtures/ok/` (4 functions, 1 c) must pass. A copy with one `glabel` removed
  (planted gap, under `.run/census/selftest/`) must fail.
- Exit: 0 green, 1 fail (uncovered bytes, map/asm mismatch, c control), 2 refused input (missing asm/ or map).
- The tool uses the stdlib only. It never imports spimdisasm/splat. Fixtures are our own words (G12).

`boundaries.py` is the second boundary oracle. It takes function starts/extents from the linked bytes alone and
compares them with `.run/census/inventory.jsonl`. Run `inventory.py` first, on a post-`make check` tree.

    PY tools/census/boundaries.py [--alias A] [--selftest]

- Bytes: `expected/build/slus/SLUS_013.34` (exe text = loadmap `exe` t_addr/t_size, file offset 0x800) and
  `expected/build/rockx5/ROCK_X5.BIN` (loadmap overlays kind `code`, non-null dest). The tool skips the inventory
  exclusions. The tool decodes the raw words here. It uses no spimdisasm/splat/rabbitizer.
- Scope (the only splat-derived input): per module the inventory's text bytes less its rodata class (yaml non-asm/non-c
  subsegments, segments.txt rodata, `dlabel` words), via `inventory.run(..., classes)`.
- Strong starts:
  - `jal` targets: overlay → own overlay or exe. The tool ignores exe → overlay (C0019).
  - Code-address words in non-code bytes and `lui`+`addiu`/`ori` pairs. Both are strong starts only where the target
    follows a `jr`+delay slot or zero padding (same-vram overlays' shared tables point mid-function). Both are never
    a strong start at a forward branch target.
  - The tool accepts no start of any source where the two words before are plain non-zero code (fall-through,
    e.g. a jal into a shared tail).
  - Jump tables: `jr rX` traced back to `lw`/`addu`/`addiu`/`lui`, entries capped by the `sltiu` bound. The entries
    are data and extend the owner, never start.
- Extent: a linear walk that tracks the furthest forward target. The walk ends at `jr`, tail/backward `j`, backward `b`
  (+ delay) when nothing is pending, else `no terminator` at the next strong start. Next sweep start = next non-zero
  word.
- Output: `boundaries: <n> of <m> functions confirmed` (m = inventory rows), `boundaries: <p> phantoms, <t> truncations`,
  per row `phantom inventory-only|bytes-only <alias> <module> <addr>` / `truncation <alias> <module> <addr> <why>`
  (`contains start X (jal|ptr|lui|sweep)`, `ends X before bytes flow end Y`, `no terminator`).
  `.run/census/boundaries.txt` holds one line per inventory fn (`confirmed|phantom inventory-only|truncation ...`) +
  bytes-only rows.
- `--selftest`: a synthetic module of words encoded in Python (jal, lui/addiu pair, jump table, tail `j`, backward
  loop, data pointer). The clean twin gives 0/0, exit 0. A planted phantom (fn dropped from inventory) and a planted
  truncation (fn shortened) each exit 1.
- Exit: 0 green (0 phantoms, 0 truncations), 1 fail, 2 refused input (missing binary, loadmap, inventory or map).

`census.py` makes the duplicate and family groups over the inventory, from the expected bytes. Run `inventory.py`
first.

    PY tools/census/census.py dup|report [--selftest]

- Words: each inventory row's `insns` words from `expected/build/slus/SLUS_013.34` (exe, loadmap `exe`) or
  `expected/build/rockx5/ROCK_X5.BIN` (overlay whose loadmap `bin_offset` = the row's yaml code segment start).
  Same-vram overlays stay apart by module (C0019). Coverage assert: a row outside its module's bytes →
  `census: coverage miss ...`, exit 1.
- Dup key = words with relocated fields masked (mirrors `tools/probe/probe.py` rel types 4-7):
  - j/jal (op 2/3): 26-bit target, R_MIPS_26
  - lui (op 15): imm16, HI16
  - addiu/ori/loads/stores, rs set by a lui earlier in fn: imm16, LO16 (a reg set by a lui stays marked all function)
  - addiu/ori/loads/stores, rs = $gp: imm16, GPREL16
- Family key = per-word skeleton: opcode, + funct (SPECIAL), rt (REGIMM), rs/fmt (COP0-3). Registers/immediates are
  masked. Dup group: ≥ 2 fns, one dup key. Family group: skeleton class ≥ 2 fns spanning ≥ 2 dup keys (all members listed).
- Output: `.run/census/groups.jsonl` `{"group","kind":"dup"|"family","members":[{"alias","name","vram"}]}` (stable
  order). The tool prints `census: dup|family <n> of <m> functions in <g> groups` for the fleet and per lane
  (`census: game ...`, `census: vendor ...`), and `census: cross-lane <k> groups`. Vendor = libobj|libgap. Lanes count
  only their own members.
- `--selftest`: `fixtures/census/functions.json` (our own words). Dup pair (jal + lui/LO16 differ) → one dup group.
  Family pair (registers differ) → family only. Near-miss (andi vs ori) → no group.
- Exit: 0 green, 1 fail (coverage miss, zero dup groups, selftest wrong), 2 refused input. No spimdisasm/splat.
- `report`: same load + groups → `.run/census/report.txt` (also printed). Terms: docs/ops/census.md.
  - First: `excluded: <module> -- <reason>` (inventory.excluded).
  - Per scope (fleet, slus, rockx5) and lane (all, game, vendor):
    `census: [<scope>] [<lane>] dup|family-only <n> of <m>`, `unique-tail <n> of <m> functions, <i> insns`,
    `excluded <n> of <m>` (rows not read from bytes). These rows are counted, not fatal.
  - Per scope: `reach x size [lo,hi) <n> of <m> functions` (edges 1,16,64,256,1024,4096,inf), `matched (c) <n> of <m>`,
    `top 1..20` by reach x size (one per dup group). Tie: alias, vram, name.
  - Last: `census: lanes reconcile <sum> = <m>` (m = inventory.jsonl rows). Sum mismatch → `census: FAIL -- ...`,
    exit 1.
  - `--selftest` also checks report lanes by name and catches a planted dropped member.

`tools/build/rockx5_splits.py` makes the rockx5 overlay header and data-tail splits, from bytes +
`docs/oracle/loadmap.json`.

    PY tools/build/rockx5_splits.py --write | --check

- The tool writes marked lines (`# gen:rockx5_splits`) into `config/splat.rockx5.yaml`. Header (id word < 0x100 +
  pointer run) → `[start, textbin]` + `[code, asm]`. Tail after the last `jr ra`+delay (no `addiu sp,-N`, no jal
  target) → `[tail, textbin]`. The tool keeps hand lines. It refuses a hand line inside a generated range. `--check`
  exit 1 on drift.
- After any rockx5 yaml hand edit, run the tool. It feeds the census scope (textbin = rodata class). It uses no
  spimdisasm.
