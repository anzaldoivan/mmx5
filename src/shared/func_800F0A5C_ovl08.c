/* Shared body (DK-5), from the banked draft of func_800F0A5C_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        if (obj[2] & 0x10) {
            set_animation(obj, 0);
        } else {
            set_animation(obj, 1);
        }
        if (obj[0x80] == 0) {
            *(s32*)(obj + 0x8C) = 0xB4;
            if (obj[0x15] == 0) {
                *(s32*)(obj + 0x20) = -0x18000;
            } else {
                *(s32*)(obj + 0x20) = 0x18000;
            }
            obj[5] = 2;
        } else {
            obj[0x88] = 0;
            obj[0x89] = 0x14;
            *(s32*)(obj + 0x8C) = 0x12C;
            obj[5] = 6;
        }
        obj[6] = 0;
    }
}
