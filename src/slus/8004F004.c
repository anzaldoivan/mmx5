#include "types.h"

extern u16 D_8007B5AC[][2];
extern u8 D_800D1C03;

void func_8004F004(u8* arg0) {
    s32 i;

    i = ((s8*)arg0)[2] >> 4;
    arg0[0x47] = D_800D1C03;
    *(u16*)(arg0 + 0xA) = D_8007B5AC[i][0];
    *(u16*)(arg0 + 0xE) = D_8007B5AC[i][1];
}

extern u16 D_8007B5AC[][2];
extern s16 D_800D1C0A;

void func_8004F044(u8* arg0) {
    s32 i;

    i = ((s8*)arg0)[2] >> 4;
    if (D_800D1C0A == 0) {
        *(s16*)(arg0 + 0xA) = 0x28;
    } else {
        *(s16*)(arg0 + 0xA) = 0x68;
    }
    *(s16*)(arg0 + 0xE) = D_8007B5AC[i][1] + 0x10;
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800490DC.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_8009A427;

void func_8004F090(void* arg0) {
    M2C_FIELD(arg0, s16*, 0xA) = 0x3F;
    M2C_FIELD(arg0, s16*, 0xE) = (s16)((D_8009A427 * 0x10) + 0x30);
}
