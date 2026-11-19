#include "types.h"
#include "mmx5/weapon.h"
#include "mmx5/globals.h"

void func_8003FAD0(u8* arg0) {
    func_8003B33C(arg0, 0x60);
    arg0[0x67] = 1;
    arg0[0x5] = 0x27;
    arg0[0x6] = 0;
    player_spawn_weapon(1, 0xD, 0, 0);
    player_spawn_weapon(1, 0xD, 0x40, 0);
    arg0[0x98] += 2;
    arg0[0x99] += 2;
}
