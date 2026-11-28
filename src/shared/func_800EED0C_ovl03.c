#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
extern u8 D_800750C0[];
extern u8 D_8009A0B4;
extern u8 D_800F94D0_ovl03[];
extern u8 D_800F94D4_ovl03[];
extern u8 D_800F94D8_ovl03[];
extern u8 D_800F9554_ovl03[];

void func_800EED0C_ovl03(u8* obj) {
    obj[0x5C] = 0x10;
    *(s16*)(obj + 0x7C) = 0;
    obj[0x61] = 0;
    obj[0x14] = D_8009A0B4;
    obj[0x15] = 0;
    *(u8**)(obj + 0x30) = D_800F9554_ovl03;
    obj[0x16] = 4;
    *(u8**)(obj + 0x68) = D_800F94D0_ovl03;
    *(u8**)(obj + 0x54) = D_800F94D8_ovl03;
    *(u8**)(obj + 0x50) = D_800F94D4_ovl03;
    obj[0x67] = 0;
    *(u8**)(obj + 0x58) = D_800750C0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    obj[0x5] = 3;
    obj[0x60] = 8;
    *(s32*)(obj + 0x2C) = 0x2000;
    obj[0x4] = 1;
    obj[0x6] = 0;
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    if (((s8*)obj)[2] == 0) {
        set_animation(obj, 0);
    } else {
        set_animation(obj, 1);
    }
}
