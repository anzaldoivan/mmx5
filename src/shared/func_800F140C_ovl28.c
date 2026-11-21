#include "types.h"
#include "mmx5/graphics.h"

void func_800F140C_ovl28(Obj4FE0* s) {
    s->unk6++;
    s->unk20 = 0;
    s->unk28 = 0;
    s->unk24 = 0x20000;
    s->unk2C = 0;
    set_animation(s, 1);
}
