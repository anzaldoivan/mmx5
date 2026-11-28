/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80054210.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_8009A424;

void func_80057E8C(void* arg0) {
    if (D_8009A424 == 0) {
        M2C_FIELD(arg0, s8*, 0x14) = 0;
        M2C_FIELD(arg0, s8*, 0x15) = 0;
        M2C_FIELD(arg0, s8*, 0x16) = 0;
        M2C_FIELD(arg0, s8*, 4) = 1;
        M2C_FIELD(arg0, s8*, 5) = 0;
    }
}
