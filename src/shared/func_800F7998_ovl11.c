/* Shared body (DK-5), from the banked draft of func_800F7998_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Ob7998*);

void DEDUP_NAME(Ob7998* obj) {
    DEDUP_CALLEE(obj);
    if (--obj->count != 0) {
        obj->state = 2;
        obj->timer = 90;
    } else {
        obj->vy = -0x20000;
        obj->vx = 0;
        obj->unk2C = 0;
        obj->timer = 90;
        obj->state++;
    }
}
