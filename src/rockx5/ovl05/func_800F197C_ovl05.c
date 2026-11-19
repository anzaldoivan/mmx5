#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800F197C_ovl05(Obj197C* o) {
    switch (o->state) {
    case 0:
    case 1:
    case 2:
        set_animation(o, 13);
        o->unk92 = 4;
        break;
    case 3:
    case 4:
    case 5:
        set_animation(o, 0);
        o->unk92 = 1;
        break;
    }
    o->unk91 = 2;
    play_sound(2, 0x18, o);
    o->step++;
}
