/* Shared body (DK-5), from the banked draft of func_800F0ED0_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(u8* arg0) {
    if (arg0[0x15] != 0) {
        *(s32*)(arg0 + 0x20) = 0x60000;
    } else {
        *(s32*)(arg0 + 0x20) = 0xFFFA0000;
    }
    arg0[6]++;
}
