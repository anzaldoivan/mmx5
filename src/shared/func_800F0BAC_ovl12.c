/* Shared body (DK-5), from the banked draft of func_800F0BAC_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(u8* arg0) {
    if (arg0[0x70] & 4) {
        *(s32*)(arg0 + 0x24) = 0xFFFF0000;
    }
    if (arg0[0x70] & 8) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        *(s32*)(arg0 + 0x2C) = 0;
        *(s16*)(arg0 + 0x7C) = 0;
        arg0[6]++;
    }
}
