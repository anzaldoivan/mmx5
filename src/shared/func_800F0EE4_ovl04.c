#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "addr.h"

void func_800F0EE4_ovl04(Obj3DD4* arg0) {
    set_animation(arg0, 0xC);
    arg0->unk20 = 0x30000;
    arg0->unk24 = 0;
    arg0->unk7C = 0x28;
    arg0->unk6++;
}

void func_800F0F2C_ovl04(Obj800F0F2C* arg0) {
    if (--arg0->unk7C == -1) {
        arg0->unk15 = 0x40;
        arg0->unk7C = 3;
        arg0->unk6++;
    }
}

void func_800F0F6C_ovl04(u8* obj) {
    apply_object_motion(obj);
    ((s32(*)())func_8002FB58)(obj);
    if (obj[0x70] & 8) {
        D_1F80004C.bytes[0x82] = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[0x67] = 0;
        if (D_1F80004C.bytes[0x80] == 0) {
            obj[5] = 4;
        } else {
            obj[5] = 5;
        }
        obj[6] = 0;
    }
}
