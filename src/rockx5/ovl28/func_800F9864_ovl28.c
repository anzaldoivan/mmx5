#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800F9864_ovl28(u8* obj) {
    u8* p;

    if (*(s8*)(obj + 0x45) == 1) {
        play_sound(2, 0x91, obj);
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = 3;
            *(u8**)(p + 0x7C) = obj;
        }
    }
    if (*(s8*)(obj + 0x46) == 0) {
        set_animation(obj, 2);
    }
    if (*(s8*)(obj + 7) == 2) {
        set_animation(obj, 4);
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        obj[6]++;
    }
}
