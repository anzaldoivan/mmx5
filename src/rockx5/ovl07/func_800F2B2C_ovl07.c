#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800F2B2C_ovl07(u8* obj) {
    if (((s8*)obj)[2] != 0) {
        set_animation(obj, 0xB);
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0xFFFC0000;
        *(u16*)(obj + 0x8A) = *(u16*)(obj + 0xE);
    } else {
        set_animation(obj, 0xC);
        if (obj[0x86] != 0) {
            *(s32*)(obj + 0x20) = 0xFFFC0000;
        } else {
            obj[0x15] = 0;
            *(s32*)(obj + 0x20) = 0x40000;
        }
        *(s32*)(obj + 0x24) = 0;
        *(u16*)(obj + 0x8A) = *(u16*)(obj + 0xA);
    }
    play_sound(0, 0x11, obj);
    obj[0x83] = 0;
    obj[0x84] = 0;
    obj[6]++;
}
