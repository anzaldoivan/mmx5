#include "types.h"
#include "mmx5/sound.h"

extern u8 D_80091C44;

void func_800FAB78_ovl50(u8* arg0) {
    if (D_80091C44 == 0) {
        play_sound(2, 0x6C, 0);
        play_sound(2, 0x4E, 0);
        arg0[1]++;
    }
}
