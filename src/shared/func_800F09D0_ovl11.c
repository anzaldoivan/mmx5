/* Shared body (DK-5), from the banked draft of func_800F09D0_ovl11 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_15/func_800EBED0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
M2C_UNK func_80017248();
void DEDUP_NAME(void* arg0) {
    // !FAKE: pins t to $2; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 t asm("$2");
    func_80017248(arg0);
    t = M2C_FIELD(arg0, u16*, 0x7C) - 1;
    M2C_FIELD(arg0, u16*, 0x7C) = t;
    if ((t << 16) == 0) {
        if (M2C_FIELD(arg0, s8*, 2) == 2) {
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
            return;
        }
        M2C_FIELD(arg0, u8*, 5) = 3;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
