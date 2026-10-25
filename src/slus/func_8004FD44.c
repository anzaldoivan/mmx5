/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80049E70.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002DF78();                      /* extern */
M2C_UNK func_8004FF94(s8, s16, s16, s32); /* extern */

void func_8004FD44(void* arg0, s8 arg1) {
    func_8004FF94(arg1, M2C_FIELD(arg0, s16*, 0xA), M2C_FIELD(arg0, s16*, 0xE),
                  (func_8002DF78() & 1) ^ 1);
}
