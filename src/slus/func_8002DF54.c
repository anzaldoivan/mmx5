/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002D2B0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8002DF54(void* arg0) {
    M2C_FIELD(arg0, s32*, 8) =
        (s32)(M2C_FIELD(arg0, s32*, 8) + M2C_FIELD(arg0, s32*, 0x20));
    M2C_FIELD(arg0, s32*, 0xC) =
        (s32)(M2C_FIELD(arg0, s32*, 0xC) - M2C_FIELD(arg0, s32*, 0x24));
}
