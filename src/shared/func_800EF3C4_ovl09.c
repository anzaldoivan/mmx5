/* Shared body (DK-5), from the banked draft of func_800EF3C4_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Obj3C4* obj) {
    if (--obj->timer == -1) {
        DEDUP_CALLEE(obj, 1);
        obj->state6 = 2;
        if (obj->x < D_8009A0AA) {
            obj->flags15 = 0x40;
            obj->vx = 0x40000;
        } else {
            obj->flags15 = 0;
            obj->vx = -0x40000;
        }
    }
}
