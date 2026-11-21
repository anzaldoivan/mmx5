#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F5728_ovl04(u8* arg0) {
    arg0[6] = 2;
}

void func_800F5734_ovl04(Obj5734* obj) {
    animate_object(obj);
    if (--obj->timer == 0) {
        if (obj->unk8F == 0) {
            set_animation(obj, 5);
            if (obj->unk91 == 0) {
                obj->unk92 = 2;
            } else {
                obj->unk92 = 0;
            }
            obj->timer = 60;
            obj->unk6 = 3;
        } else {
            obj->timer = 10;
            obj->unk5 = 3;
            obj->unk6 = 0;
        }
    }
}
