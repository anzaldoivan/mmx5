/* Shared body (DK-5), from the banked draft of func_800EFE9C_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void silence_sound(s32, s32);

void DEDUP_NAME(u8* obj) {
    u8 mode;

    if (!(obj[2] & 0x10)) {
        move_object(obj);
    }
    animate_object(obj);
    if (--*(s32*)(obj + 0x8C) == 0) {
        set_animation(obj, 3);
        *(s32*)(obj + 0x20) = 0;
        silence_sound(2, 0x51);
        obj[5] = 5;
        obj[6] = 0;
        return;
    }
    mode = obj[0x90];
    if (mode != 0) {
        if (--obj[0x91] == 0) {
            if (mode == 2) {
                obj[0x91] = 0x30;
                if (--obj[0x92] == 0) {
                    obj[0x92] = mode;
                    set_animation(obj, 3);
                    *(s32*)(obj + 0x20) = 0;
                    silence_sound(2, 0x51);
                    obj[5] = 5;
                    obj[6] = 0;
                    return;
                }
            } else {
                obj[0x91] = 0x60;
            }
            *(s16*)(obj + 0x7C) = 0x14;
            *(s32*)(obj + 0x24) = 0;
            obj[5] = 4;
            obj[6] = 0;
        }
    }
    if (obj[0x15] == 0) {
        if (obj[0x70] & 2) {
            goto tail; // !FAKE: goto kept for the matching branch layout
        }
    } else if (obj[0x70] & 1) {
    tail:
        *(s16*)(obj + 0x7C) = 0x14;
        *(s32*)(obj + 0x24) = 0;
        obj[5] = 4;
        obj[6] = 0;
    }
}
