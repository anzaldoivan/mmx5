#include "types.h"
#include "mmx5/ovl07.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void func_800FCB98_ovl07(u8* obj, s32 x, s32 y, s32 mode);
extern s8 D_800D1C44;

void func_800FBFE8_ovl07(u8* obj) {
    set_animation(obj, 2);
    D_1F80004C.bytes[0x92] = 1;
    func_800FCB98_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 2);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    if (D_800D1C44 == 0) {
        func_800FC9E0_ovl07(obj);
        if (D_1F80004C.bytes[0x8F] == 0) {
            *(s32*)(obj + 0x24) = -0x2000;
            *(s32*)(obj + 0x2C) = 0x1000;
        } else {
            *(s32*)(obj + 0x24) = 0x2000;
            *(s32*)(obj + 0x2C) = -0x1000;
        }
        obj[6] = 1;
    } else {
        if (D_1F80004C.bytes[0x8F] == 0) {
            obj[0x15] = 0x40;
            *(s32*)(obj + 0x20) = 0x2000;
            *(s32*)(obj + 0x28) = 0x1000;
        } else {
            obj[0x15] = 0;
            *(s32*)(obj + 0x20) = -0x2000;
            *(s32*)(obj + 0x28) = 0x1000;
        }
        obj[6] = 2;
    }
}

#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800FC0EC_ovl07(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (ABS(*(s16*)(D_1F80004C.bytes + 0x84) - *(s16*)(obj + 0xE)) < 8) {
        obj[6] = 3;
    }
}

#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800FC15C_ovl07(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (ABS(*(s16*)(D_1F80004C.bytes + 0x84) - *(s16*)(obj + 0xA)) < 8) {
        obj[6] = 3;
    }
}

void func_800FC1CC_ovl07(u8* obj) {
    D_1F80004C.bytes[0x92] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    func_800FB030_ovl07(obj);
}
