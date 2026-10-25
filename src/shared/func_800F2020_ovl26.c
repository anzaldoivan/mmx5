/* Shared body (DK-5), from the banked draft of func_800F2020_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_8009A226;
extern s8 D_800D1C1D;

void DEDUP_NAME(u8* arg0) {
    if (D_800D1C1D != 0) {
        arg0[4]++;
        D_8009A226 = 0xC0;
    }
}
