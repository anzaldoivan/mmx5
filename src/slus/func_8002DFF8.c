/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002D354.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002DD7C(s32, s32); /* extern */

void func_8002DFF8(void* arg0, s32 arg1, s32 arg2) {
    func_8002DD7C(M2C_FIELD(arg0, s32*, 8) - arg1,
                  M2C_FIELD(arg0, s32*, 0xC) - arg2);
}
