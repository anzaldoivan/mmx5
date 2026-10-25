/* Shared body (DK-5), from the banked draft of func_800EF8D8_ovl03 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC798.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800171E8(void*, M2C_UNK);
s32 func_8002DF78();
extern u8 D_800F959C_ovl03[];
extern s32 D_800F95B4_ovl03[];

void DEDUP_NAME(void* arg0) {
    // !FAKE: pins r to $16; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 r asm("$16");
    s32 t;
    // !FAKE: pins tbl to $5; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 tbl asm("$5");
    // !FAKE: pins v to $4; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 v asm("$4");

    func_800171E8(arg0, 3);
    r = func_8002DF78();
    t = func_8002DF78();
    tbl = (s32)D_800F95B4_ovl03;
    v = ((s32*)tbl)[(M2C_FIELD(arg0, u8*, 0x15) >> 6) & 1];
    M2C_FIELD(arg0, s32*, 0x20) = v;
    r = ((r << 8) + t) & 0xFFFF;
    if (func_8002DF78() & 1) {
        M2C_FIELD(arg0, s32*, 0x20) += r;
    } else {
        M2C_FIELD(arg0, s32*, 0x20) -= r;
    }
    M2C_FIELD(arg0, s32*, 0x28) = -0x1000;
    M2C_FIELD(arg0, s32*, 0x24) = 0x18000;
    M2C_FIELD(arg0, void**, 0x50) = D_800F959C_ovl03;
    M2C_FIELD(arg0, s32*, 0x88) = 1;
    if (M2C_FIELD(arg0, s8*, 0x2) == 2) {
        M2C_FIELD(arg0, s16*, 0x7C) = func_8002DF78() & 0x3F;
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    } else {
        M2C_FIELD(arg0, u8*, 0x6) += 2;
    }
}
