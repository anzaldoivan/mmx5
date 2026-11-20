#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800F948C_ovl00(u8* obj) {
    set_animation(obj, 2);
    play_sound(2, 0, obj);
    obj[6]++;
}
