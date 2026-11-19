/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003FA60.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/weapon.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void player_fire_weapon(void* arg0) {
    player_spawn_weapon(1, M2C_FIELD(arg0, s8*, 0x96), 0, arg0);
}
