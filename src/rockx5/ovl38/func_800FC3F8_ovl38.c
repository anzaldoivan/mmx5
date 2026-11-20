#include "types.h"
#include "mmx5/ovl38.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void func_800FCB74_ovl38(ObjFC3F8* arg0, u8 arg1);

void func_800FC3F8_ovl38(ObjFC3F8* arg0) {
    s32 state = arg0->unk45;

    if (state == 1) {
        D_1F80004C.bytes[0x92] = state;
        func_800FCB74_ovl38(arg0, 0);
        play_sound(2, 0x9F, arg0);
        state = 0x32;
        arg0->unk7C = state;
    } else if (state == 2) {
        set_animation(arg0, 9);
        func_800FCAA0_ovl38(arg0);
        arg0->unk6++;
    }
}
