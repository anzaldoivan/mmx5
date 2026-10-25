/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001651C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

void func_800152B8(void); /* extern */
extern u8 D_80091D50;

void func_80015B78(void) {
    if (D_80091D50 != 0) {
        func_800152B8();
    }
}
