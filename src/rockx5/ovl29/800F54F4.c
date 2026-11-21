#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"

extern u8 D_800F9894_ovl29[];
extern u8 D_800F988C_ovl29[];

void func_800F54F4_ovl29(u8* obj) {
    u8* child;

    set_animation(obj, 13);
    *(u8**)(obj + 0x50) = D_800F9894_ovl29;
    *(u8**)(obj + 0x54) = D_800F988C_ovl29;
    obj[0x60] = 4;
    *(s32*)(obj + 0x24) = 0x40000;
    *(s32*)(obj + 0x2C) = 0x1C00;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    child = func_8002D27C();
    if (child != 0) {
        child[0] = 0x41;
        child[1] = 0x26;
        child[2] = 4;
        *(u8**)(child + 0x50) = obj;
        *(u8**)(obj + 0x80) = child;
    }
    obj[6]++;
}

void func_800F5590_ovl29(Ent08D8* e) {
    animate_object(e);
    apply_object_motion(e);
    if (e->unk24 < 0) {
        e->unk6++;
    }
}

void func_800F55DC_ovl29(u8* obj) {
    u8* child;

    animate_object(obj);
    child = *(u8**)(obj + 0x80);
    if (*(s8*)(child + 0x46) < 0) {
        child[4] = 2;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0x4200;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[6]++;
    }
}

void func_800F563C_ovl29(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        obj[6]++;
        set_animation(obj, 0);
        if (obj[0x8A] & 1) {
            obj[0x8A] = 0x3D;
        } else {
            obj[0x8A] = 0x3E;
        }
        *(s16*)(obj + 0x7C) = 1;
    }
}

void func_800F56B4_ovl29(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[5] = 10;
        obj[6] = 0;
    }
}
