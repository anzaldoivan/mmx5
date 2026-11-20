/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80053FE4.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"

#define M2C_UNK s32

extern s8 D_800D1C1C;

void func_80057C60(void) {
    D_800D1C1C = 1;
    ((M2C_UNK(*)())clear_object_slot)();
}
