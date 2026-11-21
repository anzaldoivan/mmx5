#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F1480_ovl12(u8* o) {
    u8* src;

    src = *(u8**)(o + 0x7C);
    *(u16*)(o + 0x40) = *(u16*)(src + 0x40);
    *(u16*)(o + 0x42) = *(u16*)(src + 0x42) & 0x7FFF;
    *(s32*)(o + 0x30) = *(s32*)(src + 0x30);
    *(s32*)(o + 0x3C) = *(s32*)(src + 0x3C);
    o[0x14] = 0;
    o[0x16] = 1;
    o[0x15] = src[0x15];
    o[0x67] = 0;
    o[0x3] = 0;
    *(s32*)(o + 0x68) = 0;
    *(s32*)(o + 0x50) = 0;
    *(s32*)(o + 0x54) = 0;
    *(s32*)(o + 0x58) = 0;
    set_animation(o, 0x11);
    *(s16*)(o + 0xE) = *(u16*)(*(u8**)(o + 0x7C) + 0xE) - 0x36;
    o[0x5C] = 1;
    *(s32*)(o + 0x20) = 0;
    *(s32*)(o + 0x24) = 0;
    *(s32*)(o + 0x28) = 0;
    *(s32*)(o + 0x2C) = 0;
    o[0x60] = 8;
    *(s32*)(o + 0x8C) = 0;
    o[0x4]++;
    o[0x5] = 0;
}

extern u8 D_800F20CC_ovl12[];

void func_800F1554_ovl12(u8* obj) {
    u8* parent;

    func_800317B8(obj);
    if (*(s8*)(obj + 5) == 0) {
        if (*(s32*)(obj + 0x8C) == 0x14) {
            *(u8**)(obj + 0x50) = D_800F20CC_ovl12;
        }
        if (++*(s32*)(obj + 0x8C) == 0x3C) {
            obj[4] = 2;
        }
    }
    parent = *(u8**)(obj + 0x7C);
    if (*(s8*)(parent + 4) == 2 || *(s8*)(parent + 5) == 9) {
        obj[4] = 2;
    }
    func_8002D9EC(obj, 0x20, 0x100);
    animate_object(obj);
    move_object(obj);
}
