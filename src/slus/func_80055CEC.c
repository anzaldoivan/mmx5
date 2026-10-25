/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80051E9C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_8009A0A8;

void func_80055CEC(void* arg0) {
    s32 temp_v0;

    D_8009A0A8 = M2C_FIELD(arg0, s32*, 8);
    temp_v0 = M2C_FIELD(arg0, s32*, 0x7C);
    if (temp_v0 == 0) {
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
        return;
    }
    M2C_FIELD(arg0, s32*, 0x7C) = (s32)(temp_v0 - 1);
}
