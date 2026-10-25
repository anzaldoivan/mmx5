/* Shared body (DK-5), from the banked draft of func_800F6CC0_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    *(s32*)(obj + 0x24) = 0x20000;
    *(s32*)(obj + 0x68) = 0;
    obj[6] = 1;
}
