/* Shared body (DK-5), from the banked draft of func_800F0688_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x20) == 0) {
        *(s32*)(obj + 0x28) = 0;
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 2);
        obj[6] = 1;
    }
}
