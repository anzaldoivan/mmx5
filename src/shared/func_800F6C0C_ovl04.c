#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_80101CDC_ovl04[];
extern u8 D_80101CEC_ovl04[];

void func_800F6C0C_ovl04(Obj6C0C* obj) {
    if (obj->unk93 & 8) {
        obj->unk50 = D_80101CDC_ovl04;
        obj->unk68 = D_80101CEC_ovl04;
        obj->unk5 = 3;
        obj->unk6 = 0;
        set_animation(obj, 0xC);
        if (obj->unk91 != 0) {
            obj->unk20 = -0x20000;
            obj->unk15 = 0;
            obj->unkA -= 6;
        } else {
            obj->unk20 = 0x20000;
            obj->unk15 = 0x40;
            obj->unkA += 6;
        }
        obj->unk24 = 0;
        obj->unk67 = 0;
    }
    animate_object(obj);
    move_object(obj);
}

void func_800F6CC0_ovl04(u8* obj) {
    animate_object(obj);
    *(s32*)(obj + 0x24) = 0x20000;
    *(s32*)(obj + 0x68) = 0;
    obj[6] = 1;
}

void func_800F6CF8_ovl04(u8* a0) {
    move_object(a0);
    animate_object(a0);
    if (*(s16*)(a0 + 0xE) < 0x11) {
        a0[0x8F] = 0x1E;
        a0[0x6] = 2;
    }
}
