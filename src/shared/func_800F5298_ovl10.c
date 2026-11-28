#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern signed char D_8009A0B4;

void func_800F5298_ovl10(Obj5298* obj) {
    Ent9A1F8* base;

    if (--obj->unk7C == 0) {
        base = D_8009A1F8.ent;
        if (obj->unkA < (base + D_8009A0B4)->unkA + 0xA0) {
            obj->unk15 = 0x40;
        } else {
            obj->unk15 = 0;
        }
        obj->unk85 = 1;
        set_animation(obj, 2);
        obj->unk5 = 4;
        obj->unk6 = 0;
    }
}
