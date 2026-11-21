#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F43F8_ovl29(Ent* e) {
    if (D_8009A0AA > e->y) {
        e->flag15 = 0x40;
    } else {
        e->flag15 = 0;
    }
    set_animation(e, 0);
    ((u8*)e)[0x8F] = 0x14;
    e->state++;
}

#include "shared/func_800F4460_ovl29.c"
