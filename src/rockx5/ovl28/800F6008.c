#include "types.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "addr.h"

extern s32 D_8009A0A8;

void func_800F6008_ovl28(u8* obj) {
    set_animation(obj, 4);
    animate_object(obj);
    obj[0x67] = 1;
    if (D_8009A0A8 > *(s32*)(obj + 8)) {
        *(s32*)(obj + 0x20) = -0x20000;
        obj[0x15] = 0;
    } else {
        *(s32*)(obj + 0x20) = 0x20000;
        obj[0x15] = 0x40;
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0x5D000;
    *(s32*)(obj + 0x2C) = 0x4200;
    switch (random_byte() & 1) {
    case 0:
        play_sound(2, 0x7B, obj);
        break;
    case 1:
        play_sound(2, 0x7C, obj);
        break;
    case 2:
        play_sound(2, 0x7D, obj);
        break;
    }
    play_sound(2, 0x6D, obj);
    obj[6]++;
}

void func_800F6114_ovl28(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x24) <= 0) {
        set_animation(obj, 5);
        *(s8*)(obj + 0x67) = -1;
        obj[6]++;
    }
}

void func_800F616C_ovl28(u8* obj) {
    s32 vx;

    animate_object(obj);
    apply_object_motion(obj);
    vx = *(s32*)(obj + 0x20);
    if ((vx > 0 && (obj[0x70] & 1)) || (vx < 0 && (obj[0x70] & 2))) {
        obj[0x9A] = 1;
        play_sound(2, 0x70, obj);
        obj[5] = 8;
        obj[6] = 0;
    }
    if (obj[0x70] & 8) {
        play_sound(2, 0x6E, obj);
        set_animation(obj, 0x1B);
        obj[0x67] = 0;
        obj[6]++;
    }
}

#include "shared/func_800F6238_ovl28.c"
