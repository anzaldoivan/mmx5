#include "types.h"
#include "mmx5/sound.h"

extern s32 D_80093DD8;

void func_800FA22C_ovl45(u8* arg0) {
    if (++*(s16*)(arg0 + 4) == 30) {
        play_sound(2, 0x4C, 0);
    }
    if (*(s16*)(arg0 + 4) >= 50) {
        D_80093DD8 = 0xFFFF0000;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
