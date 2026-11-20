/* Shared body (DK-5), from the banked draft of func_800F8038_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        animate_object();
        set_animation(obj, 5);
        obj[6]++;
    }
}
