# halfdmg: half damage for X

Every positive hit on X costs half the retail damage (minimum 1).

How: the player damage scaler `func_80031670` halves a positive hit when
`a0[0xFA]` is 1..4, or 5 with `D_800D1C00[0x4A] & 0x10`, or `*(s32*)(a0+0xFC) & 0x20000`.
Retail X along intro.pad always takes that arm (traced: `a0[0xFA]` = 1 on every hit,
T4.1). This patch makes that arm quarter the damage instead (`dmg >> 2`), i.e. half of
retail's `dmg / 2`. The other arm is unchanged. Callers that route through it:
- `func_800317B8`: contact hits
- `func_8003D010`: scripted damage

Unchanged:
- the non-halving arm (full damage, as in retail)
- the healing / negative-damage branch
- 0x7F instant kill
- the difficulty scale (applied before the halving, as before)
- crush damage (`D_8009A199`, `func_800389E8`): does not go through the scaler, not in v1

Files:
- `slus/func_80031670.c`: replaces `src/slus/func_80031670.c` in a patched build
- `checkpoint`: first replay checkpoint expected to diverge

Build: `make disc SHIFT=1 PATCHES=halfdmg PY=…`
Verify: `make replay-patch PATCHES=halfdmg PY=…`

Opt-in only. A patched build is never a match. The default build ignores `patches/`.
