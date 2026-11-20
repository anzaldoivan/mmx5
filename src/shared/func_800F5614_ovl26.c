/* Shared body (DK-5), from the banked draft of func_800F5614_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x24) < 0) {
        set_animation(obj, 0x15);
        obj[6]++;
    }
}
