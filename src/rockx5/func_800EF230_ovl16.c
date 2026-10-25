/* Adapted from mmx6 @c1c892d src/shared/rock_12/func_800EA270.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D6FC(); /* extern */
extern s16 D_800D1C04;

void func_800EF230_ovl16(void* arg0) {
    func_8002D6FC();
    M2C_FIELD(arg0, s8*, 3) = 0;
    D_800D1C04 = 0;
}
