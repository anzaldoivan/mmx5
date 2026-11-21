#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"

void func_800F3258_ovl02(u8* obj) {
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x24) > 0x20000) {
        *(s32*)(obj + 0x2C) = 0;
    }
    if (obj[0x70] & 8) {
        play_sound(5, 8, obj);
        set_animation(obj, 2);
        obj[0x67] = 0;
        obj[6]++;
    }
}

void func_800F32D0_ovl02(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        set_animation(obj, 3);
        obj[5] = 4;
        obj[6] = 0;
        obj[0x60] = 0x7F;
    }
}
