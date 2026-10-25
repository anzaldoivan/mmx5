/* Shared body (DK-5), from the banked draft of func_800F0BFC_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    if (++*(s16*)(obj + 0x7C) == 60) {
        DEDUP_CALLEE(obj, 1);
        obj[5] = 4;
        obj[6] = 0;
    }
}
