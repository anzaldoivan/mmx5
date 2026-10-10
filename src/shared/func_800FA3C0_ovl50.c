/* Shared body (DK-5), from the banked draft of func_800FA3C0_ovl50 by tools/wave/gate.py rescan. */
#include "types.h"

extern signed char D_8009A424;
extern void DEDUP_CALLEE(s32, s32);

void DEDUP_NAME(Actor50* a) {
    if (D_8009A424 == 0) {
        DEDUP_CALLEE(0x1A, 0x7F);
        a->step++;
    }
}
