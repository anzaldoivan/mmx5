#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800F8CF8_ovl00(u8* obj) {
    set_animation(obj, 4);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s32*)(obj + 0x50) = 0;
    *(s32*)(obj + 0x54) = 0;
    *(s16*)(obj + 0x7C) = 15;
    obj[6]++;
    play_sound(2, 4, obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}
