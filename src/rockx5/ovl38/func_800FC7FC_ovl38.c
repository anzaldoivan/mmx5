#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800FC7FC_ovl38(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0x16);
        play_sound(2, 0xA3, obj);
        obj[6]++;
    }
}
