/* Shared body (DK-5), from the banked draft of func_800F5B98_ovl18 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800D1C00[];
extern void DEDUP_CALLEE(u8 arg0);

void DEDUP_NAME(u8* obj) {
    D_800D1C00[0x10D] = 0;
    D_800D1C00[0x10E] = 0;
    if (((s8*)D_800D1C00)[0x10] == 2) {
        DEDUP_CALLEE(1);
        obj[4]++;
    }
}
