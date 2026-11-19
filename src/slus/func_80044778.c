#include "types.h"
#include "mmx5/weapon.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

void func_80044778(u8* arg0) {
    u8* r;

    if (*(s8*)(arg0 + 0x45) & 0x80) {
        func_8003B33C(arg0, 0x83);
        play_sound(1, 5, arg0);
        arg0[0x8C] = 1;
        arg0[6]++;
        r = player_spawn_weapon(1, 0x22, 0, arg0);
        if (r == 0) {
            r[0x14] = arg0[0x14];
            r[0x15] = arg0[0x15];
        }
    }
}
