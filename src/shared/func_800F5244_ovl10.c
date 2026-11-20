/* Shared body (DK-5), from the banked draft of func_800F5244_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        obj[0x61] = 0;
        set_animation(obj, 0);
        *(s16*)(obj + 0x7C) = 0x14;
        obj[6] = 6;
    }
}
