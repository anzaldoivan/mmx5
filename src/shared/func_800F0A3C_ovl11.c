/* Shared body (DK-5), from the banked draft of func_800F0A3C_ovl11 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_15/func_800EBF3C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK func_80017248();
extern s16 D_8009A0AA;

void DEDUP_NAME(void* arg0) {
    s16 a;
    s16 b;
    s32 d;

    ((void (*)())func_80017248)();
    a = D_8009A0AA;
    b = M2C_FIELD(arg0, s16*, 0xA);
    d = a - b;
    if (d >= 0) {
        if (d < 0x90) {
            goto set; // !FAKE: control flow kept from the mmx6 twin
        }
        return;
    }
    if (b - a < 0x90) {
    set:
        M2C_FIELD(arg0, u8*, 5) = 3;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
