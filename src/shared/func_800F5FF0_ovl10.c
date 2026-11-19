/* Shared body (DK-5), from the banked draft of func_800F5FF0_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        set_animation(obj, 0);
        *(s16*)(obj + 0x7C) = 0x78;
        obj[6] = 4;
    }
}
