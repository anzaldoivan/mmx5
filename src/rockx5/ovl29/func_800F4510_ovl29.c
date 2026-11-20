#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F4510_ovl29(u8* obj) {
    if (*(s16*)(obj + 0x88) - *(s16*)(obj + 0xE) >= 0x61) {
        obj[6]++;
        set_animation(obj, 4);
        play_sound(2, 0xAD, obj);
        obj[0x60] = 5;
        *(s32*)(obj + 0x24) = 0xFFFA0000;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
    }
    apply_object_motion(obj);
    animate_object(obj);
}
