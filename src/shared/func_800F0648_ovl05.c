/* Shared body (DK-5), from the banked draft of func_800F0648_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    D_1F80004C.bytes[0x86] = 0;
    DEDUP_CALLEE(obj, 6);
    obj[6]++;
}
