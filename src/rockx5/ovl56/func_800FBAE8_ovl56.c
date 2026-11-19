#include "types.h"
#include "mmx5/sound.h"

extern u8 D_80091C44;

void func_800FBAE8_ovl56(UnkObj* arg0) {
    if (((s8*)arg0)[2] != 0) {
        if (arg0->unk6 == 0) {
            ((u8*)arg0)[2]--;
            play_sound(0, 0x13, 0);
            arg0->unk6 = 0x3C;
        } else {
            arg0->unk6--;
        }
    }
    if (D_80091C44 == 0) {
        arg0->unk1++;
    }
}
