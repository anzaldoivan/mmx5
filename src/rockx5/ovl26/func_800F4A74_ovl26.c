#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F4A74_ovl26(Obj* o) {
    animate_object(o);
    if (--o->timer != 0) {
        return;
    }
    switch (D_1F80004C.scr2074->unk94) {
    case 0:
        set_animation(o, 0xD);
        break;
    case 1:
        set_animation(o, 0x1D);
        break;
    case 2:
        set_animation(o, 0x20);
        break;
    case 3:
        set_animation(o, 0x23);
        break;
    case 4:
        set_animation(o, 0x26);
        break;
    case 5:
        set_animation(o, 0x29);
        break;
    case 6:
        set_animation(o, 0x2C);
        break;
    case 7:
        set_animation(o, 0x2F);
        break;
    }
    o->step++;
}
