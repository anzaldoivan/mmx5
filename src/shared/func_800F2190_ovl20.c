/* Shared body (DK-5), from the banked draft of func_800F2190_ovl20 by tools/wave/gate.py rescan. */
#include "types.h"

extern s8 D_800D1C28[];

void DEDUP_NAME(u8* arg0) {
    *(s16*)(arg0 + 0xA) -= 8;
    if (*(s16*)(arg0 + 0xA) < 0xC1) {
        *(s16*)(arg0 + 0xA) = 0xC0;
        D_800D1C28[1] = 0;
        arg0[4] = 3;
    }
}
