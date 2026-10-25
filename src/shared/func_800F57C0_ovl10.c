/* Shared body (DK-5), from the banked draft of func_800F57C0_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s16*)(obj + 0x7C) = 0x78;
    DEDUP_CALLEE(obj, 0);
    obj[6] = 1;
}
