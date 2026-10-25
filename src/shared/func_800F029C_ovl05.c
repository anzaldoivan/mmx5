/* Shared body (DK-5), from the banked draft of func_800F029C_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    obj[0x67] = 1;
    DEDUP_CALLEE(obj, 3);
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0x400;
    obj[6]++;
}
