/* Shared body (DK-5), from the banked draft of func_800F1708_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 DEDUP_CALLEE(s32, s32, void*);

void DEDUP_NAME(u8* arg0) {
    if (--arg0[0x8C] == 0 && arg0[0x91] == 0) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        *(s32*)(arg0 + 0x28) = 0x3000;
        arg0[0x91] = 1;
        arg0[0x8D] = 0x28;
        DEDUP_CALLEE(0, 0x23, arg0);
        arg0[5]++;
    }
    if (*(signed char*)(arg0 + 2) != 0 && arg0[0x8C] < 0x15 &&
        *(s32*)(arg0 + 0x24) != 0) {
        *(s32*)(arg0 + 0x24) = 0;
    }
}
