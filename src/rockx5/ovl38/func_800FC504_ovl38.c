#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

extern void func_800FCB74_ovl38(ObjFC3F8* arg0, u8 arg1);

void func_800FC504_ovl38(ObjFC3F8* arg0) {
    s8 state = arg0->unk45;

    if (state == 1) {
        func_800FCB74_ovl38(arg0, 0);
        func_800FCB74_ovl38(arg0, 2);
        play_sound(2, 0x9F, arg0);
    } else if (state == 2) {
        set_animation((u8*)arg0, 3);
        arg0->unk6++;
    }
}
