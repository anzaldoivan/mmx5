/* Shared body (DK-5), from the banked draft of func_800F5C1C_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    *(s32*)(obj + 0x2C) = 0x3800;
    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        if (*(s8*)(obj + 2) == 2) {
            (*(u8**)(obj + 0x80))[0x98] = 0;
        }
        set_animation(obj, 0x15);
        obj[6] = 1;
    }
}
