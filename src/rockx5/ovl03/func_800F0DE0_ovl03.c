#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void func_800F0ED8_ovl03(ObjFE130*, s32);

void func_800F0DE0_ovl03(ObjFE130* arg0) {
    if (arg0->unk45 == 1) {
        switch (D_1F80004C.obj0470->unk86) {
        case 1:
            set_animation(arg0, 0xC);
            break;
        case 0:
        case 2:
            set_animation(arg0, 0xB);
            break;
        case 3:
            set_animation(arg0, 0xD);
            break;
        case 4:
            arg0->unk5 = 2;
            arg0->unk6 = 0;
            break;
        }
        D_1F80004C.obj0470->unk86++;
    }
    if (arg0->unk45 == 2) {
        play_sound(0, 0x23, 0);
        func_800F0ED8_ovl03(arg0, 1);
    }
}
