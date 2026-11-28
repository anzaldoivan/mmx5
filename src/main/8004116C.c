#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/weapon.h"

extern s8 D_800E9548;

void func_8004116C(u8* obj) {
    if ((u8)++obj[0xF4] < 51) {
        return;
    }
    if (obj[0x17] > 0xB0) {
        func_8003B33C(obj, 0xB2);
    } else {
        func_8003B33C(obj, 0xAF);
    }
    obj[0xF4] = random_byte() % 3 + 3;
    obj[7] = 0;
    obj[6]++;
    D_800E9548 = 0;
    play_sound(1, 0x1C, obj);
}

extern s8 D_800E9548;

void func_80041238(u8* obj) {
    if (--obj[0xF4] == 0) {
        obj[0xF4] = random_byte() % 3 + 3;
        player_spawn_weapon(1, 0x31, D_800E9548, 0);
        D_800E9548 ^= 1;
    }
    if (++((s8*)obj)[7] >= 0x79) {
        obj[6]++;
        if (obj[0x17] >= 0xB1) {
            func_8003B33C(obj, 0xB3);
        } else {
            func_8003B33C(obj, 0xB0);
        }
    }
}

extern void func_8003CD08(u8* obj);
extern s8 D_800D1C1C;

void func_80041330(u8* obj) {
    if (*(s8*)(obj + 0x46) == 0) {
        if (*(s8*)(obj + 0xD0) == 0) {
            obj[0x7A] = 0;
            D_800D1C1C = 0;
        }
        obj[0xF3] = 0;
        func_8003CD08(obj);
        obj[6]++;
    }
}

#define animate_object func_8003C5D8
#define move_object func_8003AA4C

s32 func_8003AA4C(s32);
#define func_800EF574_ovl09 func_80041394
#include "shared/func_800EF574_ovl09.c"
#undef func_800EF574_ovl09
#undef animate_object
#undef move_object

void func_800413C0(u8* a0) {
    if (*(s8*)(a0 + 0x45) == 2) {
        play_sound(1, 0xE, a0);
        *(s8*)(a0 + 0x45) = 0;
    }
    if (*(s8*)(a0 + 0x45) != 0) {
        a0[0xF4]++;
    }
    if (a0[0xF4] >= 0x33) {
        play_sound(1, 0xF, a0);
        func_8003B33C(a0, 0xB5);
        a0[0xF4] = 0;
        a0[6]++;
    }
}

void func_8004145C(u8* a0) {
    if (*(s8*)(a0 + 0x45) != 0) {
        a0[0xF4]++;
    }
    if (*(s8*)(a0 + 0x45) & 0x80) {
        a0[0x45] &= 0x7F;
        player_spawn_weapon(1, 0x2F, 0, 0);
    }
    if (a0[0xF4] >= 0x79) {
        a0[6]++;
        func_8003B33C(a0, 0xB6);
    }
}
