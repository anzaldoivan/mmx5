/* Shared body (DK-5), from the banked draft of func_800FB6A0_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_8009A0AA;

void DEDUP_NAME(Obj800FB6A0* o) {
    s32 d;
    s32 sq;

    if (o->x15 != 0) {
        o->x20 = 0x40000;
    } else {
        o->x20 = -0x40000;
    }
    d = D_8009A0AA - o->xA;
    if (d < 0) {
        d = o->xA - D_8009A0AA;
    }
    if (d < 5) {
        d = 1;
    } else {
        d = d / 4;
    }
    sq = d * d;
    o->x28 = 0;
    o->x24 = 0;
    o->x2C = 0x500000 / sq;
    o->x6++;
}
