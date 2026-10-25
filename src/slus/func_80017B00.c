/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800184C8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK func_80017B5C(u8); /* extern */
extern s8 D_800D1599;
extern u8 D_800E805C;

void func_80017B00(void) {
    D_800D1599 = 0;
    func_80017B5C(D_800E805C);
}
