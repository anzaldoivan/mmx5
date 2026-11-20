/* Shared body (DK-5), from the banked draft of func_800F0964_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        if (obj[2] & 0x10) {
            set_animation(obj, 0xC);
        } else {
            set_animation(obj, 6);
        }
        obj[6] = 4;
    }
}
