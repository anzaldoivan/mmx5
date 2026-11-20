/* Shared body (DK-5), from the banked draft of func_800F0C30_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    move_object(obj);
    if (*(s32*)(obj + 0x8C) != 1) {
        *(s32*)(obj + 0x8C) -= 1;
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 1);
        *(s32*)(obj + 0x28) = -0x2000;
        obj[6] = 2;
    }
}
