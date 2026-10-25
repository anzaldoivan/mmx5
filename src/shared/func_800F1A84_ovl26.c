/* Shared body (DK-5), from the banked draft of func_800F1A84_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern s16 D_8009A0AA;
extern void DEDUP_CALLEE(Obj1A84*, s32);

void DEDUP_NAME(Obj1A84* o) {
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
    DEDUP_CALLEE(o, 0);
    o->x54 = 0;
    o->x50 = 0;
    o->x6++;
}
