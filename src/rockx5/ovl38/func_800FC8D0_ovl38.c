#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800FC8D0_ovl38(u8* obj) {
    s8 v = *(s8*)(obj + 0x45);

    if (v == 2) {
        play_sound(2, 0xA3, obj);
    } else if (v == 1) {
        set_animation(obj, 3);
        obj[5] = 3;
        obj[6] = 0;
    }
}
