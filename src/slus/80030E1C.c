#include "types.h"
#include "mmx5/globals.h"

s32 func_800311CC();

#include "shared/func_80030E1C.c"

s32 func_800311CC(X4_Obj* arg0);

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003056C.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32

M2C_UNK func_80030EA4(s32); /* extern */

void func_80030E60(s32 arg0) {
    if ((func_8003049C() != 0) && (func_800311CC(arg0) != 0)) {
        func_80030EA4(arg0);
    }
}
