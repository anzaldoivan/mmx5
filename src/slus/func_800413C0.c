#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

void func_800413C0(u8* a0) {
    if (*(s8*)(a0 + 0x45) == 2) {
        play_sound(1, 0xE, a0);
        *(s8*)(a0 + 0x45) = 0;
    }
    if (*(s8*)(a0 + 0x45) != 0) {
        a0[0xF4]++;
    }
    if (a0[0xF4] >= 0x33) {
        play_sound(1, 0xF, a0);
        func_8003B33C(a0, 0xB5);
        a0[0xF4] = 0;
        a0[6]++;
    }
}
