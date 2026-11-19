#include "types.h"
#include "mmx5/weapon.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"

extern s8 D_800E9548;

void func_80041238(u8* obj) {
    if (--obj[0xF4] == 0) {
        obj[0xF4] = random_byte() % 3 + 3;
        player_spawn_weapon(1, 0x31, D_800E9548, 0);
        D_800E9548 ^= 1;
    }
    if (++((s8*)obj)[7] >= 0x79) {
        obj[6]++;
        if (obj[0x17] >= 0xB1) {
            func_8003B33C(obj, 0xB3);
        } else {
            func_8003B33C(obj, 0xB0);
        }
    }
}
