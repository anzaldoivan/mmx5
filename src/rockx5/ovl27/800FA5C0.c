#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"

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

void func_800FA65C_ovl27(u8* a0) {
    s32 hit;

    if (*(s32*)(a0 + 0x20) > 0) {
        hit = a0[0x70] & 1;
    } else {
        hit = a0[0x70] & 2;
    }
    if (hit) {
        *(s32*)(a0 + 0x20) = 0;
        *(s32*)(a0 + 0x24) = 0;
        *(s16*)(a0 + 0x7C) = 0x50;
        a0[6] = 1;
    } else {
        move_object(a0);
    }
}
