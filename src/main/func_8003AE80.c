#include "types.h"

extern void player_set_animation_shooting(u8* arg0, s32 arg1);
extern void spawn_dust(u8* arg0);
extern void player_clear_dash(u8*);

void func_8003AE80(u8* arg0) {
    player_set_animation_shooting(arg0, 0xF);
    if (arg0[0xFA] != 3) {
        spawn_dust(arg0);
    }
    *(s8*)(arg0 + 0x67) = -1;
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    *(s32*)(arg0 + 0x24) = *(s32*)(arg0 + 0x120);
    player_clear_dash(arg0);
    arg0[5] = 0xB;
    arg0[6] = 0;
}
