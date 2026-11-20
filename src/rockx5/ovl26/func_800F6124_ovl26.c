#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F6124_ovl26(u8* obj) {
    animate_object(obj);
    if (*(s16*)(obj + 0x90) != 0) {
        *(s16*)(obj + 0x90) -= 1;
        return;
    }
    if (obj[0x94] < 3) {
        obj[5] = 0;
        play_sound(2, 0x5E, obj);
        set_animation(obj, 1);
    } else {
        obj[5] = 5;
        if (*(s8*)(obj + 2) < 8) {
            set_animation(obj, 1);
            play_sound(2, 0x5E, obj);
        }
    }
    obj[6] = 0;
    if ((*(u8**)(obj + 0x7C))[0x96]) {
        *(s32*)(obj + 0x20) = 0x60000;
    } else {
        *(s32*)(obj + 0x20) = 0xFFFA0000;
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    (*(u8**)(obj + 0x7C))[0x97] = 0;
}
