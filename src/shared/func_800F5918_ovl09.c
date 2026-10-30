/* Shared body (DK-5), from the banked draft of func_800F5918_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj, 0);
    obj[0x95] = 0x3C;
    obj[6]++;
}
