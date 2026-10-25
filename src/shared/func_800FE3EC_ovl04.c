/* Shared body (DK-5), from the banked draft of func_800FE3EC_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800D1C00[];

void DEDUP_NAME(u8* arg0) {
    D_800D1C00[0x28] &= ~arg0[0x93];
    D_800D1C00[0x29] &= ~arg0[0x93];
    arg0[3] = 0;
}
