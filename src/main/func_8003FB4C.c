#include "types.h"
#include "mmx5/weapon.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

void func_8003FB4C(u8* arg0) {
    func_8003B33C(arg0, 0x61);
    play_sound(1, 0x10, arg0);
    arg0[0x67] = 1;
    arg0[0x5] = 0x28;
    arg0[0x6] = 0;
    player_spawn_weapon(1, 0xE, 0, 0);
    arg0[0x98]++;
    arg0[0x99]++;
    arg0[0xA6]++;
}
