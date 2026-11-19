/* Shared body (DK-5), from the banked draft of func_800F7744_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Obj* obj) {
    if (++obj->timer == 300) {
        set_animation(obj, 0);
    }
    if (obj->timer >= 300) {
        apply_object_motion(obj);
        func_8002D9EC(obj, 0x40, 0x40);
    }
    if (obj->timer >= 350) {
        animate_object(obj);
    }
    if (obj->timer == 450) {
        set_animation(obj, 2);
        obj->timer = 0;
        obj->step++;
    }
}
