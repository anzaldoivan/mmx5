/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80013024.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK func_8001296C(); /* extern */
extern s32 D_8006FB14;
extern s8 D_8009A426;

void func_80012BF4(void) {
    if ((D_8009A426 == 0) && (D_8006FB14 == 0)) {
        func_8001296C();
    }
}
