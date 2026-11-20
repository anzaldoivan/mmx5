#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F9A18_ovl28(Obj3DD4* e) {
    set_animation(e, 5);
    if (D_8009A0AA > e->unkA) {
        e->unk15 = 0x40;
    } else {
        e->unk15 = 0;
    }
    e->unk20 = 0;
    e->unk7C = 0;
    e->unk6++;
    func_8002D9EC(e, 0x30, 0x30);
    animate_object(e);
    apply_object_motion(e);
}
