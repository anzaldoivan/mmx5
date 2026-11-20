#include "types.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8* find_free_visual_obj(void);

void func_800F3430_ovl28(u8* obj) {
    u8* child;

    child = find_free_visual_obj();
    if (child != 0) {
        child[0] = 0x21;
        child[1] = 0xB;
        child[2] = 6;
        child[0x15] = obj[0x15];
        *(s16*)(child + 0xA) = *(s16*)(obj + 0xA);
        *(s16*)(child + 0xE) = *(s16*)(obj + 0xE);
        *(u8**)(child + 0x50) = obj;
    }
    animate_object(obj);
    if (obj[0x70] & 1) {
        obj[0x15] = 0;
        *(s32*)(obj + 0x20) = -0x42000;
    } else {
        obj[0x15] = 0x40;
        *(s32*)(obj + 0x20) = 0x42000;
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0x5A000;
    *(s32*)(obj + 0x2C) = 0x4200;
    set_animation(obj, 6);
    obj[0x67] = 1;
    obj[6]++;
    play_sound(2, 0x6F, obj);
    switch ((u8)(((u32(*)())random_byte)() % 3)) {
    case 0:
        play_sound(2, 0x7B, obj);
        break;
    case 1:
        play_sound(2, 0x7C, obj);
        break;
    case 2:
        play_sound(2, 0x7E, obj);
        break;
    }
}
