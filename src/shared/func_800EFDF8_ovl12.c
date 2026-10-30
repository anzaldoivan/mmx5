/* Shared body (DK-5), from the banked draft of func_800EFDF8_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj, 1);
    obj[0x85] = 0x3C;
    obj[6]++;
}
