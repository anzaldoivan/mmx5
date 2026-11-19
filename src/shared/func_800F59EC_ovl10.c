/* Shared body (DK-5), from the banked draft of func_800F59EC_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    apply_object_motion(obj);
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 2 && *(s32*)(obj + 0x24) <= 0) {
        set_animation(obj, 3);
    }
    if ((obj[0x70] & 8) && *(s32*)(obj + 0x24) <= 0) {
        if (*(s16*)(obj + 0x7C) != 0) {
            obj[6] = 1;
            *(u16*)(obj + 0x7C) = *(u16*)(obj + 0x7C) - 1;
            if (obj[0x8A] != 0 && *(s8*)(obj + 2) == 0 &&
                *(s32*)(obj + 0x94) == 0) {
                set_animation(obj, 0);
                obj[0x8F] = 0x14;
                *(s16*)(obj + 0x7E) = 0x14;
            }
        } else {
            obj[6] = 3;
            set_animation(obj, 0);
            *(s16*)(obj + 0x7C) = 0x3C;
        }
    }
}
