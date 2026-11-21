#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern D_8009A1F8_t D_8009A1F8;

void func_800F1A84_ovl26(Obj1A84* o) {
    s32 d;

    o->x3 = 0;
    d = o->xA - (s16)D_8009A1F8.unkA;
    if (d < 0x20) {
        return;
    }
    if (d >= 0x121) {
        return;
    }
    d = o->xE - (s16)D_8009A1F8.unkE;
    if (d < 0x20) {
        return;
    }
    if (d >= 0xD1) {
        return;
    }
    if (D_8009A0AA < o->xA) {
        o->x15 = 0;
    } else {
        o->x15 = 0x40;
    }
    set_animation(o, 0);
    o->x54 = 0;
    o->x50 = 0;
    o->x6++;
}
