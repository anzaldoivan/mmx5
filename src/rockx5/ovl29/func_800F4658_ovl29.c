#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F4658_ovl29(Ent* e) {
    if (D_8009A0AA > e->y) {
        e->flag15 = 0x40;
    } else {
        e->flag15 = 0;
    }
    set_animation(e, 0xB);
    e->state++;
}
