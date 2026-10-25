# tools/shift — exe shiftability

`scan.py` finds values in the exe ELF (`slus`) and the overlay ELF (`rockx5`). It finds every value that points into
SLUS_013.34's range or an overlay region and that no relocation symbolizes. Phase 2.3 drove the exe-target findings to 0 so that the
exe can be padded and relinked. Phase 2.4 adds the overlay targets (directions exe->exe, exe->ovl, ovl->exe, ovl->ovl).

## Usage

- Run `make shift-scan PY=…`. With `SCAN_FLAGS=--baseline`, the command exits 0 whatever the count is.
- `PY tools/shift/scan.py [--exe ELF] [--ovl ELF] [--allow config/shift/not_pointers.txt] [--report .run/shift/scan.txt] [--no-plant] [--baseline]`
- `PY tools/shift/scan.py --selftest` prints `shift-scan: control OK`. The selftest uses a synthetic ELF and is
  game-free. It is in `make tools-selftest`.

The inputs are ELFs linked with `ld -q` (`--emit-relocs`, mk/slus.mk `link`), so `.rel.*` survive. The ld map beside
each ELF (`<name>.map`) tells text from data.

## Range

The range is `[0x80010000, bss_end)`: the image `[0x80010000, 0x80092000)` + bss. Header b_size is 0, so bss_end is
the end of the exe ELF's alloc NOBITS sections (splat bss subsegment, `.main_bss` → 0x800EE970). Without one, bss_end
is the highest SHN_ABS symbol below overlay vram 0x800EE970, rounded up to 4, + 4. `scan.py` prints the range as
`shift-scan: range <lo>..<hi>`. Scratchpad/IO (0x1F80xxxx) is never in range.

Overlay regions (2.4 T1): `scan.py` groups the rockx5 `ovlNN` by `ovlNN_VRAM`. A region is
`[vram, max ovlNN_VRAM_END)`. These names are ld map symbols, and `scan.py` reads them from the rockx5 ELF symtab.
Region A is 0x800EE970 (ovl00-29). Region B is 0x800FA000 (ovl30-58). A runs past B's start.

`scan.py` prints the regions as `shift-scan: ovl regions <lo>..<hi>, …`. Each `.ovlNN` section must start at
`ovlNN_VRAM` and span `ovlNN_ROM_END - ovlNN_ROM_START`. If a section does not, `scan.py` exits with an error.

A target in the exe range is `exe`. A target in any region is `ovl`. A site is a section + a vaddr, because the
overlays share vram. A rockx5 site belongs to the output section `.ovlNN`. The direction is
`<exe|ovl site>-><exe|ovl target>`.

## Text vs data

splat links text and data into one WAX section per binary/overlay, so SHF_EXECINSTR alone cannot tell text from data.
Instruction words are the `.text` input sections in the ld map of an exec section, minus the objects under
`asm/<a>/data/` (splat textbin `.incbin` blobs). With no map (selftest), a whole exec section is text. `scan.py` scans
only SHF_ALLOC sections with bytes.

## Kinds

- A `data` finding is an aligned word in range without R_MIPS_32 at its address. The word can be anywhere, including
  a raw `.word` in text.
- A `hilo` finding is a `lui rX` without HI16 + the first lo user without LO16, with the combined value in range. A lo
  user is one of addiu ori lw lh lb lbu lhu sw sh sb lwc2 swc2, with base rX. The window is 8 words. The window stops
  early when an instruction writes rX or when text ends.
- A `gprel` finding is a load/store/addiu with base $gp and no GPREL16, with `0x80091C30 + simm16` in range.
  `addiu gp,gp,x` is the gp setup, and `scan.py` skips it.
- A `jal` finding is a j/jal without R_MIPS_26, with the target in range.
- An `abs` finding is any relocation whose symbol is SHN_ABS (0xfff1) with a value in range. The absolutes that splat
  defines do not move. A (name, value) that is an in-section global of the exe or rockx5 ELF is not a finding. The
  reason is that rockx5 links the exe names as ABS.

## Plant

Unless the command has `--no-plant`, `scan.py` makes three plants in memory. It rescans after each plant, and the
rescan must report the plant as `data` with its direction. `scan.py` prints
`shift-scan: plant caught at <addr> (<dir>)` or `plant NOT caught (<dir>)`. The counts exclude the plants.

- exe->exe: `scan.py` drops the first R_MIPS_32 at an exe data word (in-section symbol, value in the exe range).
- exe->ovl: `scan.py` patches the same word to the start of the first overlay region and drops the reloc.
- ovl->ovl: `scan.py` drops the first rockx5 R_MIPS_32 at a data word (in-section symbol, value in an overlay region).

## Output

- `scan.py` prints `shift-scan: <n> unsymbolized (exe <a>, rockx5 <b>; data <d>, hilo <h>, gprel <g>, jal <j>, abs <s>); exe data <x>, abs-in-data <y>`.
  The field x counts the exe `data` findings. The field y counts the exe `abs` findings at non-instruction words: map
  data/rodata, textbin blobs.
- `scan.py` prints `shift-scan: <dir> <n> (data <d>, hilo <h>, gprel <g>, jal <j>, abs <s>)` per direction.
- The report (`--report`) holds `<alias> <site section> <dir> <kind> <site vaddr> -> <target> <sym>[+0xoff]` per
  finding. The rockx5 overlays share vram, so a site vaddr can repeat across overlays.
  - For an exe target, sym is the nearest exe symbol.
  - For an ovl target, sym is the nearest rockx5 symbol. For a rockx5 site, it is a symbol of the site's overlay. For
    an exe site, it is a symbol of any overlay.
- `scan.py` exits 0 if and only if n == 0 and it caught every plant. With `--no-plant`, the condition is n == 0. With
  `--baseline`, `scan.py` always exits 0.

## Allowlist

Each line of `config/shift/not_pointers.txt` is `<alias> <site vaddr> <value> -- <reason>` (hex). `#` marks a comment.
`scan.py` does not count a listed site with that value, in any rockx5 overlay with that site. Every line needs a
reason. The shifted replay arbitrates.

The sites are retail vaddrs. With `--retail-exe ELF`, `scan.py` moves each slus site to the scanned exe by retail
symbol+offset. `make shift-scan SHIFT=1` passes the ELF of build/slus. If a name is missing in either ELF, `scan.py`
exits 1.

## Regions and bounds (2.4 T2)

`config/shift/regions.txt` has one line per region:
`<name> vram=<hex> members=<ovl list> max_end=<hex>(<ovl>) bound=<hex> slack=<hex> verified=<static|live|no> source=<evidence>`.
The `#` comments carry the evidence.

- The max_end is the retail vram + the file size of the largest member. The bound is the first address that a member
  image must not reach. The slack is bound - max_end: the room that a shifted overlay may grow.
- The bound 80105000 is the base of the exe CD sector / image buffer (A, B). A.lo (bound 800FA000) is the
  co-residency bound: the A members that may be resident while a B overlay loads at 800FA000.
- The link enforces the bounds (2.4 T5). Every rockx5 link (default and SHIFT) goes through `pad_ld.py`. After each
  of the 59 overlays, the script emits `ASSERT(ovlNN_VRAM_END <= bound, "region bound: ovlNN overruns <bound>")`.
  The A.lo members take 800FA000. The other A members and the B members take 80105000.
- `make shift-oversize` first builds the SHIFT=1 slus and rockx5 pair when it is absent. Then it relinks the
  shifted rockx5 with pad 0x2000 into .run/shift-oversize/. The pad is larger than the smallest slack (0x1F08,
  ovl18).
  - If ld fails on that ASSERT, the target prints `shift-oversize: link failed as planted (ovlNN)` and exits 0.
  - If ld succeeds or fails in another way, the target exits 1.

## Shifted build (`SHIFT=1`, 2.3 T5)

- The outputs of `make split build SHIFT=1 BINARY=<a>`, `make build SHIFT=1` and `make disc SHIFT=1` are
  build/shift/<a>/ and build/shift/disc/mmx5.cue.
- The objects, the ELF and the map are in build/shift/<a>/ and are never shared with build/<a>/. The shifted build
  reads the split outputs (splat ld, undefined_*_auto.txt) from build/<a>/. There is no sha1 gate (the bytes differ by
  design). `make clean` removes build/ (including build/shift).
- rockx5 uses `--just-symbols` + exe_syms.ld from the build/shift/slus ELF (build/shift/rockx5/exe_syms.{txt,ld}). Its
  split still names exe addresses from build/rockx5/exe_syms.txt (unshifted ELF). Recursive exe builds pass `SHIFT=` /
  `SHIFT=1` explicitly (mk/rockx5.mk).
- exe->ovl (T4.1): the exe relocs (config/reloc_addrs.slus.txt) name the symbol of the owner overlay.
  config/shift/ovl_syms.ld defines that symbol in the exe at the retail vram. The symbol is pinned: the exe does not
  follow a shifted overlay. The rockx5 regions are placed at the exe's ovlA_VRAM/ovlB_VRAM (in-section exe globals).
  28 HELD words stay raw (logs/T4.1.owners.txt).
- The SHIFT rockx5 link has two passes (T8, mk/rockx5.mk LINK_POST).
  - `ovl_syms.py gen` rewrites the pinned names to the shifted rockx5 map (build/shift/ovl_syms.ld).
  - slus relinks with `OVL_SYMS=` set to that file. The pass-1 exe stays as `*.pass1.elf`. Then rockx5 relinks
    (`PASS2=1`).
  - `ovl_syms.py check` runs after each relink. The non-pinned exe symbols and ovlA/B_VRAM must be unchanged from
    pass 1 to pass 2. Every pinned name in the exe must equal its rockx5 map address. If not, the check exits 1 and
    names the differences.
- For the disc, the shifted build uses `rockx5.py pack --ref ''` (no cmp) and
  `disc.py build --out build/shift/disc --slus … --rockx5 … --no-gate`.

The link recipe runs `pad_ld.py <alias> <in.ld> <out.ld> [--pad N] [--objdir DIR]`.

- For slus, N = `SHIFT_PAD ?= 0`, and the recipe runs the script under SHIFT only.
- For rockx5, every link runs the script. Under SHIFT (both T8 passes), N = `SHIFT_OVL_PAD ?= 0x10`. If not, N is 0
  and the script writes the default build/rockx5/ROCK_X5.BIN.pad.ld.
- The script changes the object paths from build/<a>/ to DIR/. make passes B_DIR. The default is build/shift/<a>/.
- For rockx5 only, the script puts `. += N` before the RODATA, TEXT and DATA of each code overlay. It does not pad
  the data overlays 13/15/17/19 or pad/toc. It also emits the region-bound ASSERTs above.
- For slus only, `.main` becomes `. += N`, TEXT, `. += N`, DATA minus the tail object, `. += N`, RODATA,
  `ASSERT(. <= 0x80091C30)`, advance to 0x80091C30, tail (82430.data.o, 0x3D0), `ASSERT(. <= 0x80092000)`. The script
  also puts `. = 0x80092000` before `.main_bss`.

The free trailing fill is 0, so the script reorders `.main` and does not pad it. Every address below the tail moves
(text/data -0x1DC8, rodata +0x7FE68). Size and t_size stay unchanged. Any N > 0 fails the ASSERT. The section "Exe
shift range" of docs/memory-map.md explains why the tail is pinned. Inside `.main`, `.` is a section offset, so the
script writes vram - 0x80010000.
