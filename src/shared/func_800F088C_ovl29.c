/* Shared body (DK-5), from the banked draft of func_800F088C_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_8009A0AA;

void DEDUP_NAME(u8* arg0) {
    s16 x;
    s16 y;

    y = D_8009A0AA;
    x = *(s16*)(arg0 + 0xA);
    if (((y - x) < 0 ? (x - y) : (y - x)) < 0x80) {
        arg0[5] = 2;
        arg0[6] = 0;
    }
}
