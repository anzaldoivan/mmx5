#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800F2EA8_ovl07(u8* obj) {
    if (*(u16*)(*(u8**)(obj + 0x7C) + 0x88) == 0) {
        if (*(s8*)(obj + 0x66) > 0) {
            set_animation(obj, 0xD);
        } else {
            set_animation(obj, 0xE);
        }
        play_sound(0, 0x11, obj);
        obj[6]++;
    }
}
