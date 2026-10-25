/* Shared body (DK-5), from the banked draft of func_800F0FFC_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 DEDUP_CALLEE(u8* a0);

s32 DEDUP_NAME(u8* a0) {
    if (a0[0x70] == 0) {
        DEDUP_CALLEE(a0);
    }
    return a0[0x70] != 0;
}
