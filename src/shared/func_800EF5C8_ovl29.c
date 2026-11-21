#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800EF5C8_ovl29(u8* o) {
    set_animation(o, 2);
    animate_object(o);
    *(s32*)(o + 0x20) = 0;
    o[6] = 1;
}

void func_800EF604_ovl29(ObjEF604* obj) {
    if (obj->unk45 != 0) {
        obj->unk28 = 0;
        obj->unk15 ^= 0x40;
        set_animation(obj, 1);
        obj->unk5 = 2;
        obj->unk20 = 0;
        obj->unk6 = 0;
        obj->unk7C = 0x14;
    }
    animate_object(obj);
}
