/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80053FE4.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK func_8002D6FC(); /* extern */
extern s8 D_800D1C1C;

void func_80057C60(void) {
    D_800D1C1C = 1;
    ((M2C_UNK(*)())func_8002D6FC)();
}
