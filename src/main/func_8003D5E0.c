#include "types.h"
#include "mmx5/globals.h"

extern void* player_spawn_visual(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
extern void load_buffered_palette(s32 arg0, s32 arg1, s32 arg2);

void func_8003D5E0(u8* arg0) {
    u8* d = g_playthrough_state.u;
    s32 v = d[0x49];

    arg0[0xFA] = v;
    *(s32*)(arg0 + 0xFC) =
        *(s32*)(g_playthrough_state.u + arg0[0xFA] * 4 + 0x88);
    if (v == 3) {
        arg0[0xC9] = 0;
        arg0[0x14A] = 0;
        player_spawn_visual(1, 0x1B, 8, 0);
        player_spawn_visual(1, 0x1B, 9, 0);
        load_buffered_palette(0x49, 0x14, 1);
    } else {
        arg0[0xC9] = d[0x4C];
        arg0[0x14A] = d[0x4B];
    }
}
