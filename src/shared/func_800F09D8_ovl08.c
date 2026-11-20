/* Shared body (DK-5), from the banked draft of func_800F09D8_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if ((s8)obj[0x45] == 2) {
        obj[0x8B] = 0;
    }
    if ((s8)obj[0x45] == 1) {
        if (obj[2] & 0x10) {
            set_animation(obj, 0);
        } else {
            set_animation(obj, 1);
        }
        *(s16*)(obj + 0x7C) = 10;
        obj[6] = 5;
    }
}
