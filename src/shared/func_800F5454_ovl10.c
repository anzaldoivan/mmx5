/* Shared body (DK-5), from the banked draft of func_800F5454_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FC1C8_ovl10[];

void DEDUP_NAME(u8* obj) {
    apply_object_motion(obj);
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 2 && *(s32*)(obj + 0x24) <= 0) {
        set_animation(obj, 3);
    }
    if ((obj[0x70] & 8) && *(s32*)(obj + 0x24) <= 0) {
        if (obj[0x88] == 0 && *(u16*)(obj + 0x92) == 0) {
            D_800FC1C8_ovl10[1] = 1;
            set_animation(obj, 0x20);
        } else {
            D_800FC1C8_ovl10[1] = 0;
            set_animation(obj, 0x10);
        }
        obj[6] = 2;
    }
}
