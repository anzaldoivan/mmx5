/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/80026028.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern s16 D_8009A0AE;

void func_8002A7E0(X4_BackgroundObj* arg0) {
    s16 delta;

    delta = (D_8009A0AE - arg0->y_pos.i.hi) - arg0->unk2C;
    if (delta < 0) {
        arg0->y_pos.i.hi = delta + arg0->y_pos.i.hi;
        return;
    }
    delta = (D_8009A0AE - arg0->y_pos.i.hi) - arg0->unk2E;
    if (delta > 0) {
        arg0->y_pos.i.hi = delta + arg0->y_pos.i.hi;
    }
}
