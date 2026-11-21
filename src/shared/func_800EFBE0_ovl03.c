/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC978.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800F959C_ovl03[];

void func_800EFBE0_ovl03(void* arg0) {
    *(u8**)((u8*)arg0 + 0x50) = D_800F959C_ovl03;
    set_animation(arg0, 3);
    ((void (*)())animate_object)(arg0);
    *(s32*)((u8*)arg0 + 0x88) = 1;
    *(s16*)((u8*)arg0 + 0x7C) = 0x12C;
    *((u8*)arg0 + 6) += 1;
}
