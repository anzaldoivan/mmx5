/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001DBD8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_8009A424;

void func_8001EF5C(void* arg0) {
    if (D_8009A424 == 0) {
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}
