/* Shared body (DK-5), from the banked draft of func_800F0198_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800F2058_ovl12[])(u8*);
extern void DEDUP_CALLEE(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(u8* arg0) {
    D_800F2058_ovl12[(signed char)arg0[6]](arg0);
    DEDUP_CALLEE(arg0, 0x40, 0x40);
}
