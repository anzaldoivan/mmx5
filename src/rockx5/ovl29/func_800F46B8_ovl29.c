#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FA2E0_ovl29[][6];

void func_800F46B8_ovl29(u8* obj) {
    u8* spawn;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        spawn = func_8002D1A4();
        if (spawn != 0) {
            spawn[0] = 0x41;
            spawn[1] = 0x29;
            spawn[2] = 0;
            *(u8**)(spawn + 0x7C) = obj;
        }
        if (obj[0x45] & 1) {
            play_sound(2, 0xAE, spawn);
        } else {
            play_sound(2, 0xAE);
        }
        obj[0x45] = 0;
    }
    if (*(s8*)(obj + 0x46) == 0) {
        obj[5] = D_800FA2E0_ovl29[obj[0x8D]][obj[0x8E]];
        obj[0x8E]++;
        obj[6] = 0;
        set_animation(obj, 0);
    }
}
