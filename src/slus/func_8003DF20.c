#include "types.h"

extern void func_8003C5D8(u8* obj);
extern void* player_spawn_visual(s8 arg0, s8 arg1, s8 arg2, s32 arg3);

void func_8003DF20(u8* obj) {
    s8 state;

    func_8003C5D8(obj);
    state = *(s8*)(obj + 0x93);
    if (state == 1) {
        player_spawn_visual(1, 0x1B, 0, 0);
        if (obj[0xFA] == 1 || obj[0xFA] == 4) {
            player_spawn_visual(1, 0x1B, 0xC, 0);
        }
    } else if (state == 3) {
        player_spawn_visual(1, 0x1B, 1, 0);
        if (obj[0xFA] == 1 || obj[0xFA] == 4) {
            player_spawn_visual(1, 0x1B, 0xB, 0);
        }
    } else if (state == 4) {
        player_spawn_visual(1, 0x1B, 2, 0);
    } else if (state == 5) {
        player_spawn_visual(1, 0x1B, 3, 0);
        if (obj[0xFA] == 1 || obj[0xFA] == 4) {
            player_spawn_visual(1, 0x1B, 0xD, 0);
        }
    } else if (state == 7) {
        player_spawn_visual(1, 0x1B, 4, 0);
    } else if (state == 8) {
        player_spawn_visual(1, 0x1B, 5, 0);
    } else if (state == 6) {
        player_spawn_visual(1, 0x1B, 6, 0);
        if (obj[0xFA] == 1 || obj[0xFA] == 4) {
            player_spawn_visual(1, 0x1B, 0xA, 0);
        }
    }
}
