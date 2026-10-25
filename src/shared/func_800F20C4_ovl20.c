/* Shared body (DK-5), from the banked draft of func_800F20C4_ovl20 by tools/wave/gate.py rescan. */
#include "types.h"

extern s8 D_800D1C28[];

void DEDUP_NAME(u8* arg0) {
    *(s16*)(arg0 + 0xA) += 8;
    if (*(s16*)(arg0 + 0xA) >= 0x190) {
        *(s16*)(arg0 + 0xA) = 0x190;
        arg0[5]++;
        D_800D1C28[1] = 0;
    }
}
