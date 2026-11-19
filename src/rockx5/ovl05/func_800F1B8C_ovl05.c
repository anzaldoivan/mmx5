#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

s32 func_800F1B8C_ovl05(Obj1B8C* e) {
    s32 ret;

    if (e->unk45 == 1) {
        if (e->unk90 != 0) {
            e->unk91 = 1;
            e->unk5 = 2;
            e->unk6 = 0;
            e->unk8A = e->unk88;
        } else if (--e->unk92 == 0) {
            e->unk91 = 1;
            e->unk5 = 2;
            e->unk6 = 0;
        } else {
            switch (e->unk2) {
            case 0:
            case 1:
            case 2:
                set_animation(e, 13);
                break;
            case 3:
            case 4:
            case 5:
                set_animation(e, 0);
                break;
            }
            ret = play_sound(2, 0x18, e);
            e->unk6 = 1;
            return ret;
        }
    } else {
        e->unk8D = -e->unk45;
        e->unk8F = e->unk45;
    }
}
