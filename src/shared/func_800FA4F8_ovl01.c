/* Shared body (DK-5), from the banked draft of func_800FA4F8_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern signed char D_800D1C0C;

void DEDUP_NAME(u8* obj) {
    s32 below;

    animate_object(obj);
    apply_object_motion(obj);
    if (D_800D1C0C != 12) {
        below = *(s16*)(obj + 0xE) < 177;
    } else {
        below = *(s16*)(obj + 0xE) < -47;
    }
    if (below) {
        *(s16*)(obj + 0x7C) = 60;
        obj[6] = 2;
    }
}
