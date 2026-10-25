/* Shared body (DK-5), from the banked draft of func_800FD504_ovl39 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* a0);

void DEDUP_NAME(u8* a0) {
    if (*(s8*)(a0 + 2) == 0) {
        *(s32*)(a0 + 0x20) = 0x18000;
    } else {
        *(s32*)(a0 + 0x20) = -0x18000;
    }
    *(s32*)(a0 + 0x24) = 0;
    DEDUP_CALLEE(a0);
    a0[6]++;
}
