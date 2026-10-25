/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001D2A0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_8009A424;

void func_8001E6F0(void* arg0) {
    if (D_8009A424 == 0) {
        M2C_FIELD(arg0, s8*, 0xD) = 0;
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}
