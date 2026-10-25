/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004C01C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80051B24(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) == 0x15) {
        M2C_FIELD(arg0, s8*, 0x3D) = 0xF;
        return;
    }
    M2C_FIELD(arg0, s8*, 0x3D) = 2;
}
