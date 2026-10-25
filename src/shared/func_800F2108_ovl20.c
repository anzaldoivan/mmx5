/* Shared body (DK-5), from the banked draft of func_800F2108_ovl20 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_8009A256;
extern s8 D_800D1C28[];

void DEDUP_NAME(u8* arg0) {
    s16 t = D_8009A256;

    if ((s16)(t % 320) == 0 && t != 320) {
        arg0[4] = 3;
        return;
    }
    if (D_800D1C28[1] != 0) {
        arg0[5]++;
    }
}
