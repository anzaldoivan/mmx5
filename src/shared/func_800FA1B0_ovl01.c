/* Shared body (DK-5), from the banked draft of func_800FA1B0_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0);
        obj[5] = 3;
        obj[6] = 0;
    }
}
