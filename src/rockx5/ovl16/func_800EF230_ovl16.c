/* Adapted from mmx6 @c1c892d src/shared/rock_12/func_800EA270.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800D1C04;

void func_800EF230_ovl16(void* arg0) {
    clear_object_slot();
    M2C_FIELD(arg0, s8*, 3) = 0;
    D_800D1C04 = 0;
}
