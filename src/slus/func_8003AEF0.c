#include "types.h"

extern void player_set_animation_shooting(u8* arg0, s32 arg1);

void func_8003AEF0(u8* arg0) {
    player_set_animation_shooting(arg0, 0xB);
    if (arg0[0x89] & 1) {
        *(s32*)(arg0 + 0x20) = -*(s32*)(arg0 + 0x104);
    } else {
        *(s32*)(arg0 + 0x20) = *(s32*)(arg0 + 0x104);
    }
    *(s32*)(arg0 + 0x2C) = *(s32*)(arg0 + 0x110);
    arg0[0x8A] = 4;
    *(s8*)(arg0 + 0x67) = -1;
    arg0[5] = 0xB;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x24) = 0;
    arg0[6] = 1;
}
