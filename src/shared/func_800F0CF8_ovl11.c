/* Shared body (DK-5), from the banked draft of func_800F0CF8_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 5);
        *(s16*)(obj + 0x7C) = 0x29;
        obj[6]++;
    }
}
