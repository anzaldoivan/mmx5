#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F9CF8_ovl28(Ent* e) {
    set_animation(e, 6);
    if (D_8009A0AA > e->y) {
        e->flag15 = 0x40;
    } else {
        e->flag15 = 0;
    }
    e->state++;
}
