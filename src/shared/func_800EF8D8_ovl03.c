#include "types.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"

/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC798.c, AGPL-3.0 (THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800F959C_ovl03[];
extern s32 D_800F95B4_ovl03[];

void func_800EF8D8_ovl03(void* arg0) {
    // !FAKE: pins r to $16; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 r asm("$16");
    s32 t;
    // !FAKE: pins tbl to $5; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 tbl asm("$5");
    // !FAKE: pins v to $4; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 v asm("$4");

    set_animation(arg0, 3);
    r = random_byte();
    t = random_byte();
    tbl = (s32)D_800F95B4_ovl03;
    v = ((s32*)tbl)[(M2C_FIELD(arg0, u8*, 0x15) >> 6) & 1];
    M2C_FIELD(arg0, s32*, 0x20) = v;
    r = ((r << 8) + t) & 0xFFFF;
    if (random_byte() & 1) {
        M2C_FIELD(arg0, s32*, 0x20) += r;
    } else {
        M2C_FIELD(arg0, s32*, 0x20) -= r;
    }
    M2C_FIELD(arg0, s32*, 0x28) = -0x1000;
    M2C_FIELD(arg0, s32*, 0x24) = 0x18000;
    M2C_FIELD(arg0, void**, 0x50) = D_800F959C_ovl03;
    M2C_FIELD(arg0, s32*, 0x88) = 1;
    if (M2C_FIELD(arg0, s8*, 0x2) == 2) {
        M2C_FIELD(arg0, s16*, 0x7C) = random_byte() & 0x3F;
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    } else {
        M2C_FIELD(arg0, u8*, 0x6) += 2;
    }
}

/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC894.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EF9D4_ovl03(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        return;
    }
    M2C_FIELD(arg0, s16*, 0x7C) = (s16)((u16)M2C_FIELD(arg0, s16*, 0x7C) - 1);
}
