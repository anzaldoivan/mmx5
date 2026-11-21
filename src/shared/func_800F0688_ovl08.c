#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F0688_ovl08(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x20) == 0) {
        *(s32*)(obj + 0x28) = 0;
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 2);
        obj[6] = 1;
    }
}

void func_800F06F4_ovl08(Obj06F4* obj) {
    animate_object(obj);
    if (obj->unk45 != 0) {
        obj->unk15 ^= 0x40;
        set_animation(obj, 1);
        obj->unk7C = 20;
        if (obj->unk8A == 0) {
            obj->unk6 = 2;
        } else {
            if (obj->unk15 != 0) {
                obj->unk20 = 0x40000;
            } else {
                obj->unk20 = -0x40000;
            }
            set_animation(obj, 7);
            obj->unk5 = 7;
            obj->unk6 = 1;
        }
    }
}

void func_800F078C_ovl08(Obj078C* obj) {
    animate_object(obj);
    if (--obj->unk7C == 0) {
        set_animation(obj, 1);
        if (obj->unk80 == 0) {
            if (obj->unk15) {
                obj->unk20 = 0x18000;
            } else {
                obj->unk20 = -0x18000;
            }
            obj->unk5 = 2;
        } else {
            obj->unk88 = 0;
            obj->unk89 = 0x14;
            obj->unk5 = 6;
        }
        obj->unk6 = 0;
    }
}
