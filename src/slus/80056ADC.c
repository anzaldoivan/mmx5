#include "types.h"
#include "mmx5/globals.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80052D6C.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800D1C1D;

void func_80056ADC(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    if ((M2C_FIELD(arg0, u8*, 2) & 0xF) == D_800D1C1D) {
        func_8002D760(arg0, arg0);
    }
}
#undef M2C_FIELD

extern s32 func_8002D800(u8* a0);
extern s16 D_8009A0AE;
extern s8 D_800D1C1D;

void func_80056B28(u8* a0) {
    s32 hit;
    u8 b;

    if (func_8002D800(a0) == 0) {
        b = a0[2];
        if (((s8*)a0)[2] & 0x80) {
            hit = *(s16*)(a0 + 0xE) > D_8009A0AE;
        } else {
            hit = *(s16*)(a0 + 0xA) > D_8009A0AA;
        }
        if (!hit) {
            D_800D1C1D = b & 0x7F;
            func_8002D760(a0);
        }
    } else {
        func_8002D760(a0);
    }
}
