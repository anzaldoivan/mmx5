/* Shared body (DK-5), from the banked draft of func_800F2504_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* a0);

void DEDUP_NAME(u8* a0) {
    s32 v;

    if (a0[0x15] == 0) {
        v = a0[0x70] & 2;
    } else {
        v = a0[0x70] & 1;
    }
    if (v) {
        *(s16*)(a0 + 0x7C) = 0x3C;
        a0[6]++;
    } else {
        DEDUP_CALLEE(a0);
    }
}
