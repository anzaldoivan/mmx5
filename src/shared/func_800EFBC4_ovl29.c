#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800EFBC4_ovl29(Obj800EFBC4* arg0) {
    arg0->unk6 = 1;
    if (arg0->unk15 == 0) {
        arg0->unk20 = -0x8000;
    } else {
        arg0->unk20 = 0x8000;
    }
    arg0->unk28 = 0;
    arg0->unk24 = 0;
    arg0->unk2C = 0;
    arg0->unk7C = 0x30;
}

void func_800EFBF8_ovl29(EntFBF8* obj) {
    s32 v;

    animate_object(obj);
    move_object(obj);
    if (--obj->unk7C == 0) {
        v = -0x20000;
        if (obj->unk15 & 0x40) {
            v = 0x20000;
        }
        obj->unk20 = v;
        obj->unk5 = 5;
        obj->unk6 = 0;
    }
}
