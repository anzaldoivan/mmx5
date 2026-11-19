/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800184C8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"

extern s8 D_800D1599;
extern u8 D_800E805C;

void func_80017B00(void) {
    D_800D1599 = 0;
    func_80017B5C(D_800E805C);
}
