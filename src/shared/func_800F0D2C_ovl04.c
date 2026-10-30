/* Shared body (DK-5), from the banked draft of func_800F0D2C_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj, 11);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0x50000;
    obj[6]++;
}
