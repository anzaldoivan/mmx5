/* Adapted from mmx6 @c1c892d src/shared/rock_10/func_800F0684.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/graphics.h"

void func_800F91CC_ovl00(u8* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 2);
    arg0[6]++;
}
