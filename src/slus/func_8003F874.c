#include "types.h"
#include "mmx5/system.h"

extern void* player_spawn_visual(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
extern void func_8003CF74(u8*, s32);

void func_8003F874(u8* arg0) {
    s8 t;

    player_spawn_visual(0x21, 2, *(s8*)(arg0 + 0x96), 0);
    t = *(s8*)(arg0 + 0x96);
    if (t == 0x12 || t == 0x14 || t == 0x2E || t == 0x13) {
        if (random_byte() & 1) {
            func_8003CF74(arg0, 6);
        }
    }
}
