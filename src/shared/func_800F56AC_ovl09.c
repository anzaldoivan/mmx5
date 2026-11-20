/* Shared body (DK-5), from the banked draft of func_800F56AC_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Obj56AC* obj) {
    if (++obj->timer == 100) {
        obj->timer = 0;
        obj->state++;
        func_8002D9EC(obj, 0x40, 0x40);
    }
    if (obj->flag46 == 0) {
        set_animation(obj, 0);
    }
    animate_object(obj);
    apply_object_motion(obj);
    if (obj->timer >= 31 || (obj->timer & 1)) {
        func_8002D9EC(obj, 0x40, 0x40);
    }
}
