/* Shared body (DK-5), from the banked draft of func_800F864C_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        set_animation(obj, 0xB);
        obj[5] = 2;
    }
}
