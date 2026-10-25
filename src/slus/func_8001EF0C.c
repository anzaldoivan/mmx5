/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001DBAC.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_8009A424;

void func_8001EF0C(void* arg0) {
    if (D_8009A424 == 0) {
        M2C_FIELD(arg0, s8*, 0) = 3;
        M2C_FIELD(arg0, s8*, 1) = 0;
        M2C_FIELD(arg0, s8*, 2) = 0;
        M2C_FIELD(arg0, s8*, 3) = 0;
    }
}
