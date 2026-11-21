#include "types.h"
#include "mmx5/weapon.h"
#include "mmx5/system.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003FA60.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void player_fire_weapon(void* arg0) {
    player_spawn_weapon(1, M2C_FIELD(arg0, s8*, 0x96), 0, arg0);
}
#undef M2C_FIELD

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
