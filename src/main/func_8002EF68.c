/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002E47C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

s32 func_8002EF68(X4_Obj* a, X4_Obj* b) {
    s16 ax, ay, bx, by;
    u8 r;
    s16 y;
    s32 w1;
    s32 w2;
    s32 d;
    s32 dx;
    s16 t;

    r = 0;
    if (a->unk15 == 0x40) {
        ax = a->x_pos.i.hi - a->unk68->a;
    } else {
        ax = a->x_pos.i.hi + a->unk68->a;
    }
    ay = a->y_pos.i.hi + a->unk68->b;
    if (b->unk15 == 0x40) {
        bx = b->x_pos.i.hi - b->unk68->a;
    } else {
        bx = b->x_pos.i.hi + b->unk68->a;
    }
    by = b->y_pos.i.hi + b->unk68->b;

    d = ay - by;
    if (d >= 0) {
        t = d;
    } else {
        t = by - ay;
    }
    dx = ax - bx;
    w1 = a->unk68->d;
    if (t == b->unk68->d + w1) {
        if (dx >= 0) {
            t = dx;
        } else {
            t = bx - ax;
        }
        y = a->unk68->c + b->unk68->c;
        if (t < y) {
            r = 8;
            if (ay < by) {
                r = 4;
            }
        }
    }
    if (dx >= 0) {
        t = dx;
    } else {
        t = bx - ax;
    }
    w2 = a->unk68->c;
    if (t == b->unk68->c + w2) {
        d = ay - by;
        if (d >= 0) {
            t = d;
        } else {
            t = by - ay;
        }
        y = a->unk68->d + b->unk68->d;
        if (t < y) {
            if (ax < bx) {
                r |= 2;
            } else {
                r |= 1;
            }
        }
    }
    b->unk71 |= r;
    return r;
}
