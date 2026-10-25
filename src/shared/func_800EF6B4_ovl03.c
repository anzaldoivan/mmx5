/* Shared body (DK-5), from the banked draft of func_800EF6B4_ovl03 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC574.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800171E8(void*, M2C_UNK);
M2C_UNK func_80017248();

void DEDUP_NAME(void* arg0) {
    s32 temp_v0;

    ((void (*)())func_80017248)();
    temp_v0 = M2C_FIELD(arg0, s32*, 0x80) - 1;
    M2C_FIELD(arg0, s32*, 0x80) = temp_v0;
    if (temp_v0 == 0) {
        ((void (*)(void*, s32))func_800171E8)(arg0, 3);
        M2C_FIELD(arg0, s8*, 0x5) = 4;
        M2C_FIELD(arg0, s8*, 0x6) = 0;
    }
}
