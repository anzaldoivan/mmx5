#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F64D0_ovl26(u8* obj) {
    animate_object(obj);
    if (*(s16*)(obj + 0x90) != 0) {
        (*(s16*)(obj + 0x90))--;
        return;
    }
    if (*(s8*)(obj + 2) < 8) {
        set_animation(obj, 1);
        play_sound(2, 0x5E, obj);
    }
    obj[6]++;
}
