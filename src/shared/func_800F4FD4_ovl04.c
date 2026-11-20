/* Shared body (DK-5), from the banked draft of func_800F4FD4_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Obj4FD4* obj) {
    obj->unk3 = 1;
    animate_object(obj);
    move_object(obj);
    if (--obj->timer == 0) {
        obj->state++;
        set_animation(obj, 0);
    }
}
