#include "types.h"
#include "mmx5/graphics.h"

void func_800EFC68_ovl29(ObjEFC68* obj) {
    s32 v;

    if (obj->unk67 == 0 && !(obj->unk70 & 8)) {
        if (obj->unk5 != 5) {
            set_animation(obj, 0);
            obj->unk20 = 0;
        }
        v = 6;
        obj->unk5 = v;
        v = 0x4200;
        obj->unk2C = v;
        v = 1;
        obj->unk6 = 0;
        obj->unk24 = 0;
        obj->unk28 = 0;
        obj->unk67 = v;
    }
}
