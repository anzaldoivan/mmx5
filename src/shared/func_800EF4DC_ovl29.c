#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"

void func_800EF4DC_ovl29(u8* obj) {
    s32 v;

    v = 0xFFFF3334;
    obj[6] = 1;
    if (obj[0x15] & 0x40) {
        v = 0xCCCC;
    }
    *(s32*)(obj + 0x20) = v;
    animate_object(obj);
}

void func_800EF51C_ovl29(Obj800EF51C* obj) {
    if (obj->unk88 == 0) {
        if (--obj->unk8C == 0) {
            set_animation(obj, 2);
            obj->unk5 = 3;
            obj->unk6 = 0;
            obj->unk8C = 0x78;
        }
    }
    move_object(obj);
    animate_object(obj);
}
