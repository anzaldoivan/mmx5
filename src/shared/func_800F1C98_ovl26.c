/* Shared body (DK-5), from the banked draft of func_800F1C98_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern s16 D_8009A202;
extern s32 D_800F95B0_ovl26;
extern s32 D_800F95B4_ovl26;
extern void DEDUP_CALLEE(Obj1C98*, s32);

void DEDUP_NAME(Obj1C98* o) {
    s8 v;

    if (D_1F80004C.scr84->unk84 == 0) {
        o->xA = D_8009A202 + 0x40;
    } else {
        o->xA = D_8009A202 + 0x100;
    }
    if (o->x45 != 0) {
        DEDUP_CALLEE(o, 1);
        o->x54 = &D_800F95B4_ovl26;
        o->x50 = &D_800F95B0_ovl26;
        v = 3;
        if (D_1F80004C.scr84->unk84 == 0) {
            v = 2;
        }
        o->x6 = v;
    }
}
