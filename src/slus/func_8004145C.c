#include "types.h"
#include "mmx5/weapon.h"
#include "mmx5/globals.h"

void func_8004145C(u8* a0) {
    if (*(s8*)(a0 + 0x45) != 0) {
        a0[0xF4]++;
    }
    if (*(s8*)(a0 + 0x45) & 0x80) {
        a0[0x45] &= 0x7F;
        player_spawn_weapon(1, 0x2F, 0, 0);
    }
    if (a0[0xF4] >= 0x79) {
        a0[6]++;
        func_8003B33C(a0, 0xB6);
    }
}
