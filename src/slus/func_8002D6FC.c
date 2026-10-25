/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002C9B0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8002D6FC(void* arg0) {
    M2C_FIELD(arg0, s8*, 0) = 0;
    M2C_FIELD(arg0, s8*, 1) = 0;
    M2C_FIELD(arg0, s8*, 2) = 0;
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s8*, 4) = 0;
    M2C_FIELD(arg0, s8*, 5) = 0;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 7) = 0;
}
