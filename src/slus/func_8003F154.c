#include "types.h"
#include "mmx5/weapon.h"
#include "mmx5/globals.h"

extern void* player_spawn_visual(s32, s32, s32, s32);
extern void player_set_animation_shooting(u8* arg0, s32 arg1);

s32 func_8003F154(u8* obj) {
    s32 s;

    if (!((u32)(obj[0xFA] - 1) < 2 || obj[0xFA] == 4)) {
        return 0;
    }
    if (!(*(u16*)(obj + 0x80) & 0x80)) {
        return 0;
    }
    s = obj[0xFA];
    obj[0x86] = 4;
    *(s32*)(obj + 0x20) = 0;
    obj[0xE8] = 0xB4;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x84] = 0;
    obj[0x8C] = 0;
    obj[0xE9] = 0;
    if (s == 1 || s == 4) {
        player_set_animation_shooting(obj, 0x15);
        obj[5] = 0x21;
    } else {
        func_8003B33C(obj, 0xA9);
        obj[5] = 0x23;
        player_spawn_weapon(1, 0x17, 0, obj);
        player_spawn_visual(1, 0x12, 0, 0);
        obj[0x7A] = 2;
    }
    obj[6] = 0;
    return 1;
}
