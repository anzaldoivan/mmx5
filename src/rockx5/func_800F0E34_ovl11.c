/* Adapted from mmx6 @c1c892d src/shared/rock_15/func_800EC334.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

M2C_UNK func_800171E8(void*, M2C_UNK);
M2C_UNK func_80017248();

void func_800F0E34_ovl11(u8* arg0) {
    func_80017248();
    func_800171E8(arg0, 6);
    {
        // !FAKE: depin: dropping it breaks the match (12/17)
        register s32 t asm("$2") = arg0[6];
        *(s16*)(arg0 + 0x7C) = 0x1A;
        arg0[6] = t + 1;
    }
}
