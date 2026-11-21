#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F0658_ovl01(Obj0658* obj) {
    obj->unk24 = 0;
    obj->unk28 = 0;
    obj->unk2C = 0;
    if (obj->unk15 != 0) {
        obj->unk20 = 0x20000;
        obj->unk6 = 2;
    } else {
        obj->unk20 = -0x20000;
        obj->unk6 = 1;
    }
    set_animation(obj, 0);
}

void func_800F06A8_ovl01(u8* obj) {
    animate_object(obj);
    move_object(obj);
    if (obj[0x70] & 2) {
        obj[0x15] = 0x40;
        *(s32*)(obj + 0x20) = 0x20000;
        obj[0x6] = 2;
    }
}

void func_800F06FC_ovl01(u8* obj) {
    animate_object(obj);
    move_object(obj);
    if (obj[0x70] & 1) {
        obj[0x15] = 0;
        *(s32*)(obj + 0x20) = 0xFFFE0000;
        obj[6] = 1;
    }
}

void func_800F074C_ovl01(Obj074C* obj) {
    if (obj->unk88 != 0) {
        obj->unk8C = 1;
        obj->unk80 = 2;
        set_animation(obj, 1);
        obj->unk60 = 4;
        obj->unk84 = 1;
        obj->state5 = 5;
        obj->state6 = 0;
    }
}
