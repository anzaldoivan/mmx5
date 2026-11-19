/* Shared body (DK-5), from the banked draft of func_800F77E8_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Obj77E8* obj) {
    animate_object(obj);
    if (--obj->timer == 0) {
        if (obj->x > D_8009A0AA) {
            obj->flip = 0;
        } else {
            obj->flip = 0x40;
        }
        set_animation(obj, 9);
        obj->state++;
    }
}
