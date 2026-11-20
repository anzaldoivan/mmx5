#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F4900_ovl26(Obj* o) {
    if (--o->timer != 0) {
        return;
    }
    switch (D_1F80004C.scr2074->unk94) {
    case 0:
        set_animation(o, 0xC);
        break;
    case 1:
        set_animation(o, 0x1C);
        break;
    case 2:
        set_animation(o, 0x1F);
        break;
    case 3:
        set_animation(o, 0x22);
        break;
    case 4:
        set_animation(o, 0x25);
        break;
    case 5:
        set_animation(o, 0x28);
        break;
    case 6:
        set_animation(o, 0x2B);
        break;
    case 7:
        set_animation(o, 0x2E);
        break;
    }
    o->timer = 20;
    o->step++;
}
