/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80021208.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800232D4(void* arg0, void* arg1) {
    if ((M2C_FIELD(arg1, s8*, 0x9B) == 0) &&
        (M2C_FIELD(arg1, s8*, 0x9C) == 0)) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 0;
        return;
    }
    animate_object();
}
