#include "types.h"
#include "mmx5/weapon.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

void func_80044778(u8* arg0) {
    u8* r;

    if (*(s8*)(arg0 + 0x45) & 0x80) {
        func_8003B33C(arg0, 0x83);
        play_sound(1, 5, arg0);
        arg0[0x8C] = 1;
        arg0[6]++;
        r = player_spawn_weapon(1, 0x22, 0, arg0);
        if (r == 0) {
            r[0x14] = arg0[0x14];
            r[0x15] = arg0[0x15];
        }
    }
}

extern void func_8003A9AC(void);
extern s32 func_800439A8(u8* obj);

void func_80044810(u8* arg0) {
    if (arg0[0x89] & 8) {
        func_8003A9AC();
        return;
    }
    apply_object_motion(arg0);
    if (func_800439A8(arg0) != 0) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        *(s8*)(arg0 + 0x67) = -1;
        arg0[0x84] = 0;
        *(s32*)(arg0 + 0x2C) = *(s32*)(arg0 + 0x110);
        return;
    }
    if (*(s8*)(arg0 + 0x46) < 0) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        *(s8*)(arg0 + 0x67) = -1;
        arg0[0x84] = 0;
        *(s8*)(arg0 + 0x8C) = -1;
        *(s32*)(arg0 + 0x2C) = *(s32*)(arg0 + 0x110);
        func_8003B33C(arg0, 0x13);
        arg0[6]++;
    }
}

#define func_80036E60 func_800448D8
#include "shared/func_80036E60.c"
#undef func_80036E60
