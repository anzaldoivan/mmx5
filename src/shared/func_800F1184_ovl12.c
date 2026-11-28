#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
extern u8 D_800F20C4_ovl12[];

void func_800F1184_ovl12(u8* obj) {
    u8* parent;
    u8* t;
    s32 c;
    s32 cnt;
    u16 e;

    parent = *(u8**)(obj + 0x7C);
    *(u16*)(obj + 0x40) = *(u16*)(parent + 0x40);
    *(u16*)(obj + 0x42) = *(u16*)(parent + 0x42) & 0x7FFF;
    *(s32*)(obj + 0x30) = *(s32*)(parent + 0x30);
    *(s32*)(obj + 0x3C) = *(s32*)(parent + 0x3C);
    obj[0x16] = 1;
    obj[0x14] = 0;
    obj[0x15] = parent[0x15];
    obj[0x67] = 0;
    obj[0x3] = 0;
    *(s32*)(obj + 0x68) = 0;
    *(u8**)(obj + 0x50) = D_800F20C4_ovl12;
    *(s32*)(obj + 0x54) = 0;
    *(s32*)(obj + 0x58) = 0;
    set_animation(obj, 0xE);
    if (obj[0x15] == 0) {
        *(s16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x7C) + 0xA) - 0xA;
    } else {
        *(s16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x7C) + 0xA) + 0xA;
    }
    t = *(u8**)(obj + 0x7C);
    cnt = obj[0x4];
    e = *(u16*)(t + 0xE);
    c = 0xFFFC0000;
    *(s32*)(obj + 0x24) = c;
    c = 1;
    obj[0x5C] = c;
    c = 4;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x60] = c;
    cnt++;
    obj[0x4] = cnt;
    obj[0x5] = 0;
    *(s16*)(obj + 0xE) = e + 0x16;
}
