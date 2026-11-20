#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800FA5C0_ovl27(u8* obj) {
    s16 t;

    t = --*(s16*)(obj + 0x7C);
    if (t == 0) {
        set_animation(obj, 0x19);
        *(s32*)(obj + 0x24) = 0;
        if (D_8009A0AA < *(s16*)(obj + 0xA)) {
            play_sound(2, 0x66, obj);
            *(s32*)(obj + 0x20) = -0x20000;
            obj[6]++;
        } else {
            play_sound(2, 0x66, obj);
            *(s32*)(obj + 0x20) = 0x20000;
            obj[6]++;
        }
    }
}
