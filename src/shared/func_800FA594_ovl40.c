/* Shared body (DK-5), from the banked draft of func_800FA594_ovl40 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern void DEDUP_CALLEE(s8 arg);

void DEDUP_NAME(Actor50* a) {
    if (D_80091C44 == 0) {
        DEDUP_CALLEE(8);
        a->step++;
    }
}
