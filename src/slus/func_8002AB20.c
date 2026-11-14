/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/80026028.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern X4_BackgroundObj D_8009A1F8[3];

void func_8002AB20(X4_BackgroundObj* arg0) {
    s32 t;
    u16 y;

    arg0->x_pos.u.hi = D_8009A1F8[0].x_pos.u.hi;
    y = D_8009A1F8[0].y_pos.u.hi;
    t = (s16)y / 2 + y;
    arg0->y_pos.u.hi = arg0->unk42 + t;
}
