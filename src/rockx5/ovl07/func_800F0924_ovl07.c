#include "types.h"
#include "mmx5/sound.h"

void func_800F0924_ovl07(u8* a0) {
    if (a0[0x7D] == 0) {
        if (a0[0x7E] != 0 || (*(u16*)(a0 + 0x8C) & 0x100)) {
            a0[0x7D] = 1;
            a0[5] = 5;
            a0[6] = 0;
            a0[0x99] = 0;
            a0[0x80] |= 3;
            play_sound(5, 0x12, 0);
        }
    }
}
