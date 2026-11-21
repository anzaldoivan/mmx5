#include "types.h"
#include "mmx5/sound.h"

extern u8 D_80091C44;

void func_800FA9B8_ovl58(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        arg0->unk4 = 0;
        arg0->unk6 = 0;
        arg0->unk1++;
        play_sound(2, 0x58, 0);
    }
}
