/* Shared body (DK-5), from the banked draft of func_800F2330_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* o) {
    DEDUP_CALLEE(o, 0);
    *(s32*)(o + 0x20) = 0;
    *(s32*)(o + 0x24) = 0;
    *(s32*)(o + 0x28) = 0;
    *(s32*)(o + 0x2C) = 0;
    *(s16*)(o + 0x7C) = 0x3C;
    o[6]++;
}
