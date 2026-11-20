#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F9E90_ovl28(Obj3DD4* e) {
    set_animation(e, 7);
    if (D_8009A0AA > e->unkA) {
        e->unk15 = 0x40;
    } else {
        e->unk15 = 0;
    }
    e->unk7C = 0;
    e->unk7E = 0;
    e->unk6++;
}
