/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC574.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EF6B4_ovl03(void* arg0) {
    s32 temp_v0;

    ((void (*)())animate_object)();
    temp_v0 = M2C_FIELD(arg0, s32*, 0x80) - 1;
    M2C_FIELD(arg0, s32*, 0x80) = temp_v0;
    if (temp_v0 == 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 3);
        M2C_FIELD(arg0, s8*, 0x5) = 4;
        M2C_FIELD(arg0, s8*, 0x6) = 0;
    }
}
