#include "types.h"
#include "mmx5/globals.h"

void func_80029418(s16* p) {
    s16 t;
    s16 a;
    s16 d;

    t = D_8009A1F8.h[5] >> 1;
    a = t + p[0x20];
    p[5] = a;
    d = a - p[0xB];
    p[7] = D_8009A1F8.h[7] + p[0x21];
    if (d >= 0) {
        if (d >= 0x10) {
            if (d < 0x148) {
                p[5] = p[0xB] + 0x10;
            } else {
                p[5] = a - 0x140;
            }
        }
    } else {
        d = -d;
        if (d >= 0x10) {
            if (d < 0x148) {
                p[5] = p[0xB] - 0x10;
            } else {
                p[5] = a + 0x140;
            }
        }
    }
    d = p[7] - p[0xD];
    if (d >= 0) {
        if (d >= 0x10) {
            if (d >= 0x148) {
                p[7] = p[7] - 0x140;
            } else {
                p[7] = p[0xD] + 0x10;
            }
        }
    } else {
        d = -d;
        if (d >= 0x10) {
            if (d >= 0x148) {
                p[7] = p[7] + 0x140;
            } else {
                p[7] = p[0xD] - 0x10;
            }
        }
    }
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002855C.c, AGPL-3.0 (THIRD_PARTY.md). */

void func_80029528(X4_BackgroundObj* arg0) {
    s16 q;
    s16 q2;
    s16 x;
    s16 d;
    u16 t;
    u16 y;
    u16 t2;

    q2 = (D_8009A1F8.bg[0].x_pos.i.hi * 3) / 4;
    x = q2 + (s16)arg0->unk40;
    arg0->x_pos.i.hi = x;
    q = (D_8009A1F8.bg[0].y_pos.i.hi * 3) / 4;
    arg0->y_pos.i.hi = q + (s16)arg0->unk42;
    t = arg0->unk14.u.hi;
    d = x - t;
    if (d >= 0) {
        if (d >= 0x10) {
            if (d >= 0x148) {
                arg0->x_pos.i.hi = x - 0x140;
            } else {
                arg0->x_pos.i.hi = t + 0x10;
            }
        }
    } else {
        d = -d;
        if (d >= 0x10) {
            if (d >= 0x148) {
                arg0->x_pos.i.hi = x + 0x140;
            } else {
                arg0->x_pos.i.hi = t - 0x10;
            }
        }
    }
    y = arg0->y_pos.u.hi;
    t2 = arg0->unk18.u.hi;
    d = y - t2;
    if (d >= 0) {
        if (d >= 0x10) {
            if (d >= 0x148) {
                arg0->y_pos.u.hi = y - 0x140;
                return;
            }
            arg0->y_pos.u.hi = t2 + 0x10;
        }
    } else {
        d = -d;
        if (d >= 0x10) {
            if (d >= 0x148) {
                arg0->y_pos.u.hi = y + 0x140;
                return;
            }
            arg0->y_pos.u.hi = t2 - 0x10;
        }
    }
}
