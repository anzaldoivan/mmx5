/* Adapted from mmx6 @c1c892d src/shared/rock_12/func_800EA2C8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D6FC(); /* extern */

void func_800EF288_ovl16(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x38), s8*, 4) = 2;
    }
    func_8002D6FC();
}
