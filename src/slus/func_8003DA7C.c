/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003DACC.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003DA7C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD7) != 0) {
        M2C_FIELD(arg0, s8*, 0xD7) = (s8)((u8)M2C_FIELD(arg0, s8*, 0xD7) - 1);
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 3;
    M2C_FIELD(arg0, s8*, 5) = 0;
}
