/* Shared body (DK-5), from the banked draft of func_800F5BEC_ovl18 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800D1C00[];
void DEDUP_CALLEE(u8 arg0);

void DEDUP_NAME(u8* arg0) {
    D_800D1C00[0x10D] = 1;
    D_800D1C00[0x10E] = 1;
    if (((signed char*)D_800D1C00)[0x10] == 0) {
        DEDUP_CALLEE(0);
        arg0[4]--;
    }
}
