#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F19F4_ovl10(Obj3DD4* e) {
    set_animation(e, 3);
    if (D_8009A0AA <= e->unkA) {
        e->unk15 = 0;
    } else {
        e->unk15 = 0x40;
    }
    e->unk6++;
}
