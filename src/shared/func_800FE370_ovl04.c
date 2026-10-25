/* Shared body (DK-5), from the banked draft of func_800FE370_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800D1C00[];

void DEDUP_NAME(u8* arg0) {
    s32 limit;

    limit = 300;
    D_800D1C00[0x28] &= ~arg0[0x93];
    D_800D1C00[0x29] &= ~arg0[0x93];
    if (D_800D1C00[0x26] & 2) {
        limit = 50;
    }
    if (++*(s32*)(arg0 + 0x84) >= limit) {
        *(s32*)(arg0 + 0x84) = 0;
        arg0[5]++;
    }
}
