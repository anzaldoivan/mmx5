#include "types.h"
#include "mmx5/sound.h"

void func_800F5820_ovl27(Obj5820* arg0) {
    if (--arg0->unk7C == 0) {
        arg0->unk7C = 0x28;
        if (--arg0->unk7E != -1) {
            func_800F5B44_ovl27(arg0, 0);
            play_sound(2, 0x5D, arg0);
        } else {
            arg0->unk5 = 2;
            arg0->unk6 = 0;
        }
    }
}
