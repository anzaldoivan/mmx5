/* Shared body (DK-5), from the banked draft of func_800F07B0_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if ((u8)(obj[5] - 3) >= 2 && !(obj[0x70] & 8)) {
        obj[5] = 3;
        obj[6] = 0;
        *(s32*)(obj + 0x2C) = 0x3C00;
    }
}
