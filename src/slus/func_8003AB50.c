#include "types.h"

extern void player_set_animation_shooting(u8* arg0, s32 arg1);
extern void silence_sound(s32, s32);

void func_8003AB50(u8* arg0) {
    player_set_animation_shooting(arg0, 0x11);
    silence_sound(1, 5);
    if (arg0[0x15] != 0) {
        *(s32*)(arg0 + 0x20) = *(s32*)(arg0 + 0x118);
    } else {
        *(s32*)(arg0 + 0x20) = -*(s32*)(arg0 + 0x118);
    }
    *(s8*)(arg0 + 0x8C) = -1;
    arg0[0x84] = 0;
    arg0[0x86] = 0;
    arg0[6] = 2;
    *(s32*)(arg0 + 0x28) = *(s32*)(arg0 + 0x11C);
}
