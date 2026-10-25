/* Adapted from mmx6 @c1c892d src/shared/rock_03/func_800ED984.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

M2C_UNK func_800171E8(void*, M2C_UNK); /* extern */

void func_800F2850_ovl02(void* arg0) {
    ((void (*)(void*, s32))func_800171E8)(arg0, 1);
    ((u8*)arg0)[6]++;
}
