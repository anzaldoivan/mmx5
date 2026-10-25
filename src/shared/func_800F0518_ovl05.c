/* Shared body (DK-5), from the banked draft of func_800F0518_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj, 5);
    D_1F80004C.bytes[0x86] = 3;
    obj[6]++;
}
