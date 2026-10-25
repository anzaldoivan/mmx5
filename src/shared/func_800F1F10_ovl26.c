/* Shared body (DK-5), from the banked draft of func_800F1F10_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"

extern s8 D_800D1C1D;
extern u8 D_8009A1F8[];
extern u16 D_800F9618_ovl26[];

void DEDUP_NAME(u8* arg0) {
    u8* d;

    if (D_800D1C1D != 0) {
        arg0[4] = 3;
        return;
    }
    d = D_8009A1F8;
    d[0x98] = 1;
    d[0xEC] = 1;
    *(u16*)(d + 0x2E) = D_800F9618_ovl26[*(signed char*)(arg0 + 2)];
    arg0[4]++;
}
