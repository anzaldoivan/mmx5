/* Adapted from mmx6 @c1c892d src/shared/rock_10/func_800F0778.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800171E8(void*, M2C_UNK); /* extern */

void func_800F2974_ovl02(void* arg0) {
    ((void (*)(void*, s32))func_800171E8)(arg0, 3);
    M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
}
