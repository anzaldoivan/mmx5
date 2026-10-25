/* Shared body (DK-5), from the banked draft of func_800FBC24_ovl38 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_04/func_800F4BA8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80044DD0(M2C_UNK);
extern u8 D_80091C44;

void DEDUP_NAME(void* arg0) {
    if (D_80091C44 == 0) {
        func_80044DD0(0);
        {
            // !FAKE: pins v to $2; gcc 2.7.2 allocates another register without it (byte mismatch)
            register s32 v asm("$2") = ((u8*)arg0)[6] + 1;
            ((u8*)arg0)[6] = v;
        }
    }
}
