# m092fill

Asset-edit recipe (tools/assets/README.md `apply`). Build with `make disc ASSET_EDIT=m092fill`, check with
`make replay-asset ASSET_EDIT=m092fill`.

- entry: ROCK_X5.DAT member 092, pack entry 002 (112640 B), class 1 (type >> 16 = 1), kind 0x206.
- change: bytes 0..8191 of the entry set to 0xFF, size unchanged. The recipe holds our op only, no game bytes.
- evidence (T6.c1, one intro.pad run): 1 divergence vs original/run1, first `mid_stage` (stage_start equal), so the
  declared cp is `mid_stage`. Tried first, 0 divergences: 000/000 and 077/000 and 088/002 (same 8192 B fill).
  Bisection by whole-entry fills of all class-1 entries narrowed the visible ones to members 92-93.
