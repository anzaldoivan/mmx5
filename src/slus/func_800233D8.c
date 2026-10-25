/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002130C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800233D8(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x50);
    M2C_FIELD(arg0, s32*, 8) = (s32)M2C_FIELD(temp_a1, s32*, 0x18);
    M2C_FIELD(arg0, s32*, 0xC) = (s32)M2C_FIELD(temp_a1, s32*, 0x1C);
}
