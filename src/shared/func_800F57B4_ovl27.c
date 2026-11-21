#include "types.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"

void func_800F57B4_ovl27(Obj3DD4* o) {
    u32 r;

    set_animation(o, 3);
    o->unk7C = 1;
    r = random_byte();
    o->unk6++;
    o->unk7E = (u8)(r % 3) + 2;
}
