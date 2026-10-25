/* Adapted from mmx6 @c1c892d src/shared/rock_11/func_800FB178.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F7194_ovl09(u8* arg0); /* extern */
extern s8 D_8009A250;

void func_800F732C_ovl09(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x15) = 0;
    M2C_FIELD(arg0, s8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    D_8009A250 = 5;
    ((void (*)())func_800F7194_ovl09)();
}
