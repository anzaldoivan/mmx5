/* Shared body (DK-5), from the banked draft of func_800F5200_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800FBE00_ovl10[][5];

void DEDUP_NAME(u8* arg0) {
    arg0[0x84] = 0x3C;
    arg0[5] = D_800FBE00_ovl10[arg0[0x8A] * 2 + arg0[0x89]][1];
    arg0[6] = 0;
}
