/* Shared body (DK-5), from the banked draft of func_800EEFE0_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    s16 d;

    set_animation(obj, 6);
    if (D_8009A0AA < 0xB8) {
        d = 0x130 - *(u16*)(obj + 0xA);
        obj[0x15] = 0;
        if ((d < 0 ? -d : d) < 0x20) {
            set_animation(obj, 7);
            play_sound(2, 0x3D, obj);
            obj[6] += 2;
        } else {
            *(s32*)(obj + 0x20) = (d << 16) / 42;
            goto far; // !FAKE: goto kept for the matching branch layout
        }
    } else {
        obj[0x15] = 0x40;
        d = 0x40 - *(u16*)(obj + 0xA);
        if ((d < 0 ? -d : d) < 0x20) {
            set_animation(obj, 7);
            play_sound(2, 0x3D, obj);
            obj[6] += 2;
        } else {
            *(s32*)(obj + 0x20) = (d << 16) / 42;
        far:
            *(s32*)(obj + 0x24) = 0x30000;
            *(s32*)(obj + 0x2C) = 0x2666;
            play_sound(2, 0x35, obj);
            obj[6] += 1;
        }
    }
}
