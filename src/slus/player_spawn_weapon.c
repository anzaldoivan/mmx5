/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003D3F8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/weapon.h"

void* func_8002D078();
extern u8 D_8009A0B4;

void* player_spawn_weapon(s32 a0, s32 a1, s32 a2, s32 arg3) {
    s8 arg0 = a0;
    s8 arg1 = a1;
    s8 arg2 = a2;
    u8* p;

    p = func_8002D078();
    if (p != 0) {
        p[0] = arg0;
        p[1] = arg1;
        p[2] = arg2;
        p[0x14] = D_8009A0B4;
        if (arg3 != 0) {
            *(s32*)(p + 0x7C) = arg3;
        }
        return p;
    }
    return 0;
}
