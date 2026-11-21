#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800EFEF4_ovl12(Ent* e) {
    set_animation(e, 2);
    if (D_8009A0AA > e->y) {
        e->flag15 = 0x40;
    } else {
        e->flag15 = 0;
    }
    e->state++;
}
