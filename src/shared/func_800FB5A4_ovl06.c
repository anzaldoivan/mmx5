/* Shared body (DK-5), from the banked draft of func_800FB5A4_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

void DEDUP_NAME(ObjFB5A4* obj) {
    s32 s;

    if (obj->parent->state == 2) {
        obj->b4 = 2;
        return;
    }
    animate_object(obj);
    s = obj->b7;
    if (s == 0) {
        obj->timer = 60;
        obj->b7++;
    } else if (s == 1) {
        func_800317B8(obj);
        if (obj->timer & 1) {
            obj->b3 = 0;
        } else {
            obj->b3 = s;
        }
        if (--obj->timer == 0) {
            obj->b3 = 0;
            obj->b4 = 2;
        }
    }
}
