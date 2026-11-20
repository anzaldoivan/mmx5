/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/cling/enter_wall_cling_8003B3B8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/sound.h"

extern void player_set_animation_shooting(u8* arg0, s32 arg1);

void player_enter_wall_cling(u8* arg0) {
    // !FAKE: flag byte lives in the second return register
    register s32 t asm("$3");

    player_set_animation_shooting(arg0, 0xD);
    play_sound(1, 4, arg0);
    t = arg0[0x89];
    {
        // !FAKE: the -1 constant lives in the first return register
        register s32 m asm("$2") = -1;
        arg0[0x8C] = m;
    }
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x24) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    arg0[0x84] = 0;
    arg0[0x86] = 0;
    arg0[0x8A] = 8;
    if (t & 1) {
        arg0[0x15] = 0x40;
    } else {
        arg0[0x15] = 0;
    }
    arg0[0x5] = 9;
    arg0[0x6] = 0;
}
