/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003056C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"

#define M2C_UNK s32

M2C_UNK func_80030EA4(s32); /* extern */

void func_80030E1C(s32 arg0) {
    if ((func_800311CC() != 0) && (func_8003049C(arg0) != 0)) {
        func_80030EA4(arg0);
    }
}
