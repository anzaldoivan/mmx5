#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800F59E8_ovl18(u8* obj) {
    if (--obj[0x7C] == 0) {
        play_sound(5, 0x1F, obj);
        set_animation(obj, 1);
        obj[6]++;
    }
}
