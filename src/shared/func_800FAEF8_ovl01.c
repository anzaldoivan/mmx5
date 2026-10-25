/* Shared body (DK-5), from the banked draft of func_800FAEF8_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(s32 a0);
extern u8 D_80091C44;

void DEDUP_NAME(u8* arg0) {
    if (D_80091C44 == 0) {
        *(s16*)(arg0 + 0x7C) = 4;
        *(s16*)(arg0 + 0x7E) = 3;
        arg0[6] = 7;
        DEDUP_CALLEE(7);
    }
}
