#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

extern void func_800F1C64_ovl10(u8* arg0);

void func_800F1A50_ovl10(u8* obj) {
    if (*(s8*)(obj + 0x45) == 1) {
        play_sound(2, 0x29, 0);
        set_animation(obj, 4);
        func_800F1C64_ovl10(obj);
        obj[6]++;
    }
}
