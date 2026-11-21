#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"

extern void func_800F0978_ovl29(u8* obj);
extern void func_800F017C_ovl29(u8* obj);

void func_800F0424_ovl29(u8* obj) {
    func_800F0978_ovl29(obj);
    func_800F017C_ovl29(obj);
    if (obj[0x80] == 0) {
        set_animation(obj, obj[0x88] + 0x12);
    } else {
        set_animation(obj, obj[0x88] + 0x17);
    }
    obj[6] = 1;
}

void func_800F0488_ovl29(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        obj[6] = 2;
        *(s16*)(obj + 0x7C) = 2;
        *(s16*)(obj + 0x7E) = 0xC;
    }
}

void func_800F04D0_ovl29(Ent04D0* obj) {
    animate_object(obj);
    if (--obj->unk7C == 0) {
        obj->unk8C = 0;
        obj->unk7C = 90;
        if (obj->unk80 == 0) {
            obj->unk5 = 3;
            obj->unk6 = 0;
        } else {
            obj->unk20 = 0;
            obj->unk2C = 0x4000;
            obj->unk5 = 4;
            obj->unk6 = 1;
        }
        if (obj->unk2 == 1) {
            obj->unk5 = 5;
            obj->unk6 = 0;
            obj->unk7C = 60;
        }
    }
}
