/* Shared body (DK-5), from the banked draft of func_800F8A78_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 3);
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
