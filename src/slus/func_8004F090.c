/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800490DC.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_8009A427;

void func_8004F090(void* arg0) {
    M2C_FIELD(arg0, s16*, 0xA) = 0x3F;
    M2C_FIELD(arg0, s16*, 0xE) = (s16)((D_8009A427 * 0x10) + 0x30);
}
