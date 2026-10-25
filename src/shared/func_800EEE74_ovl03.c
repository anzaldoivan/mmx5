/* Shared body (DK-5), from the banked draft of func_800EEE74_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (((s8*)obj)[2] != 0) {
        *(s32*)(obj + 0x28) = -0x400;
    } else {
        *(s32*)(obj + 0x28) = 0x400;
    }
    obj[6] = 1;
}
