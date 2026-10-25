/* Adapted from mmx6 @c1c892d src/shared/rock_21/func_800EB764.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C50C(); /* extern */
M2C_UNK func_8002D004(); /* extern */

void func_800EFFC0_ovl25(void* arg0) {
    func_8002C50C();
    func_8002D004();
    M2C_FIELD(arg0, s8*, 0x1F) = 0;
    M2C_FIELD(arg0, s8*, 0x24) = 0;
    M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
}
