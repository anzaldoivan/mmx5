#include "types.h"
#include "mmx5/graphics.h"

extern s32 D_800F95AC_ovl03[];

void func_800EF740_ovl03(Obj3DD4* o) {
    set_animation(o, 3);
    o->unk20 = D_800F95AC_ovl03[(o->unk15 >> 6) & 1];
    o->unk24 = 0x5000;
    o->unk6++;
}
