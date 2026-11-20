#include "types.h"
#include "mmx5/graphics.h"

extern s16 D_800FA64A_ovl29;

void func_800F49FC_ovl29(Ent* e) {
    if (e->y > D_800FA64A_ovl29) {
        e->flag15 = 0;
    } else {
        e->flag15 = 0x40;
    }
    set_animation(e, 0xA);
    e->state++;
}
