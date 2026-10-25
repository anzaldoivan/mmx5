/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80052CC0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017E54(M2C_UNK); /* extern */

void func_80056A30(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x16) = -1;
    M2C_FIELD(arg0, s16*, 0x14) = 0x64;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    func_80017E54(3);
}
