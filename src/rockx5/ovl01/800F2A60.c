#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"

void func_800F2A60_ovl01(u8* obj) {
    s32 v;

    set_animation(obj, 2);
    v = -0x20000;
    if (obj[0x15] != 0) {
        v = 0x20000;
    }
    *(s32*)(obj + 0x20) = v;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[6]++;
}

extern s32 func_800F2F8C_ovl01(u8* obj);
extern s32 func_800F3040_ovl01(u8* obj);
extern s32 func_800F2FEC_ovl01(u8* obj);

void func_800F2AB8_ovl01(u8* obj) {
    animate_object(obj);
    move_object(obj);
    if (func_800F2F8C_ovl01(obj) == 0 && func_800F3040_ovl01(obj) == 0) {
        func_800F2FEC_ovl01(obj);
    }
}

void func_800F2B0C_ovl01(u8* obj) {
    animate_object(obj);
    move_object(obj);
    if (--D_1F80004C.bytes[0x80] == 0xFF) {
        obj[5] = 4;
        obj[6] = 0;
    }
}

void func_800F2B6C_ovl01(u8* obj) {
    animate_object(obj);
    move_object(obj);
    set_animation(obj, 3);
    obj[5] = 5;
    obj[6] = 0;
    *(s32*)(obj + 0x2C) = 0x1800;
    *(s32*)(obj + 0x24) = 0x2E000;
    *(s32*)(obj + 0x28) = 0;
    obj[0x67] = 1;
}

void func_800F2BD0_ovl01(u8* obj) {
    s32 vx;

    animate_object(obj);
    move_object(obj);
    if (--D_1F80004C.bytes[0x80] == 0xFF) {
        set_animation(obj, 3);
        obj[5] = 6;
        obj[6] = 0;
        vx = -0x20000;
        if (obj[0x15] != 0) {
            vx = 0x20000;
        }
        *(s32*)(obj + 0x20) = vx;
        *(s32*)(obj + 0x24) = 0x25000;
        *(s32*)(obj + 0x2C) = 0x1800;
        *(s32*)(obj + 0x28) = 0;
        obj[0x67] = 1;
    }
}
