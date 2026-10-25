/* Shared body (DK-5), from the banked draft of func_800F292C_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj, 6);
    D_1F80004C.bytes[0x84] = 3;
    obj[6]++;
}
