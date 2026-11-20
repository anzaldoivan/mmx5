#include "types.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

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
