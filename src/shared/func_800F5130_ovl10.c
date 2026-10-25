/* Shared body (DK-5), from the banked draft of func_800F5130_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj, 0x13);
    *(s16*)(obj + 0x7C) = 0x3C;
    obj[6] = 1;
}
