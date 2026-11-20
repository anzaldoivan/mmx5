#include "types.h"
#include "mmx5/weapon.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

void func_8003F9CC(u8* obj) {
    func_8003B33C(obj, 0x60);
    play_sound(1, 0x19, obj);
    obj[0x67] = 1;
    obj[0x5] = 0x2B;
    obj[0x6] = 0;
    player_spawn_weapon(1, 0xC, 0, 0);
    player_spawn_weapon(1, 0xC, 1, 0);
    player_spawn_weapon(1, 0xC, 2, 0);
    player_spawn_weapon(1, 0xC, 3, 0);
    player_spawn_weapon(1, 0xC, 4, 0);
    player_spawn_weapon(1, 0xC, 5, 0);
    player_spawn_weapon(1, 0xC, 6, 0);
    player_spawn_weapon(1, 0xC, 7, 0);
    obj[0x98] += 8;
    obj[0x99] += 8;
}
