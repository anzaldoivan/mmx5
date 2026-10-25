/* Adapted from mmx6 @c1c892d src/shared/rock_02/func_800F9F3C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_80091C44;

void func_800F1164_ovl07(void* arg0) {
    if (D_80091C44 == 0) {
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}
