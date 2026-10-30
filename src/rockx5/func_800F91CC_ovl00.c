/* Adapted from mmx6 @c1c892d src/shared/rock_10/func_800F0684.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

M2C_UNK func_800171E8(void*, M2C_UNK);

void func_800F91CC_ovl00(u8* arg0) {
    ((void (*)(void*, s32))func_800171E8)(arg0, 2);
    arg0[6]++;
}
