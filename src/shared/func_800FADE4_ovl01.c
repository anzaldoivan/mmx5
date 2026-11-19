/* Shared body (DK-5), from the banked draft of func_800FADE4_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        set_animation(obj, 0xC);
        obj[6] = 5;
    }
}
