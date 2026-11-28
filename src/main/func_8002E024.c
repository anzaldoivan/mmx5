/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002D380.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002DD7C(s32, s32);
void func_8002E024(void* arg0, void* arg1) {
    s32 temp_a2;

    temp_a2 = M2C_FIELD(arg0, s32*, 8);
    ((s32(*)())func_8002DD7C)(
        temp_a2 - M2C_FIELD(arg1, s32*, 8),
        M2C_FIELD(arg0, s32*, 0xC) - M2C_FIELD(arg1, s32*, 0xC), temp_a2);
}
