#include "types.h"
#include "mmx5/sound.h"

extern s8 D_8009A0A5;
extern s16 D_8009A202;

void func_800EFE78_ovl04(u8* a0) {
    if (D_8009A0A5 == 20 && D_8009A202 == 0xC80) {
        play_sound(5, 10, 0);
        a0[6]++;
    }
}
