/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80017E6C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK LoadImage(M2C_UNK*, M2C_UNK*); /* extern */
extern M2C_UNK D_800703D4;
extern M2C_UNK D_800705D4;

void func_800176B0(void) {
    LoadImage(&D_800705D4, &D_800703D4);
}
