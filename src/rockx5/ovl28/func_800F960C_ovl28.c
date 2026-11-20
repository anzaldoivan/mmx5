#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800F960C_ovl28(u8* obj) {
    s8 kind;
    u8* p;

    kind = *(s8*)(obj + 0x45);
    if (kind == 1) {
        play_sound(2, 0x8B, obj);
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = kind;
            *(u8**)(p + 0x7C) = obj;
        }
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = 2;
            *(u8**)(p + 0x7C) = obj;
        }
    }
    if (++*(s16*)(obj + 0x7C) == 40) {
        set_animation(obj, 4);
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        obj[6]++;
    }
}
