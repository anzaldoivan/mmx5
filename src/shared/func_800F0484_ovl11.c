/* Shared body (DK-5), from the banked draft of func_800F0484_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8*, s32);

void DEDUP_NAME(u8* a0) {
    u8 t;

    t = (*(u8**)(a0 + 0x50))[0x16];
    a0[3] = 0;
    a0[0x16] = t;
    DEDUP_CALLEE(a0, 1);
    a0[4] = 1;
    t = (*(u8**)(a0 + 0x50))[7];
    a0[0x54] = 0;
    a0[7] = t;
}
