/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800F26C4.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F2CCC_ovl06(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x7E) == 0) {
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}
