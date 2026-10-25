/* Shared body (DK-5), from the banked draft of func_800FC85C_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj, 4);
    D_1F80004C.bytes[0x8E] = 1;
    obj[6]++;
}
