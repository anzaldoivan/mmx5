/* Shared body (DK-5), from the banked draft of func_800F5FC0_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj, 1);
    obj[6] = 1;
}
