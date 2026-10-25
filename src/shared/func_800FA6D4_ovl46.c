/* Shared body (DK-5), from the banked draft of func_800FA6D4_ovl46 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern void DEDUP_CALLEE(s32, s32);

void DEDUP_NAME(Actor50* a) {
    if (D_80091C44 == 0) {
        DEDUP_CALLEE(0x16, 0x7F);
        a->step++;
    }
}
