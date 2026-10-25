/* Adapted from mmx6 @c1c892d src/shared/rock_17/func_800E9B68.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#ifndef M2C_UNK
#define M2C_UNK s32
#endif

M2C_UNK func_80013288(M2C_UNK); /* extern */

void func_800EEC94_ovl21(u8* arg0) {
    // !FAKE: pins temp to $2; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 temp asm("$2");

    func_80013288(8);
    temp = arg0[1] + 1;
    arg0[1] = temp;
}
