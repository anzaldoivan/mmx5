/* Shared body (DK-5), from the banked draft of func_800F0464_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj, 4);
    *(u8*)(obj + 0x67) = 1;
    *(s32*)(obj + 0x20) = 0x10000;
    *(s32*)(obj + 0x24) = -0x2000;
    *(s32*)(obj + 0x2C) = 0x200;
    obj[6]++;
}
