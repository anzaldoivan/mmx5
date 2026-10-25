/* Shared body (DK-5), from the banked draft of func_800EEABC_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800F4828_ovl05[][14];

void DEDUP_NAME(u8* arg0) {
    arg0[0x14] = 0;
    *(u8**)(arg0 + 0x18) = D_800F4828_ovl05[((s8*)arg0)[2]];
    arg0[4]++;
}
