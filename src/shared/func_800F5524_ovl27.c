#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F5524_ovl27(Obj5524* obj) {
    Scr5308* s = D_1F80004C.scr5308;
    u8 flag = s->unk86;

    if (flag == 2) {
        s->unk86 = 0;
        set_animation(obj, 1);
        obj->state6 = flag;
        return;
    }
    set_animation(obj, 0);
    obj->timer7C = 0x5A;
    obj->timer7E = 0x28;
    obj->state6++;
}
