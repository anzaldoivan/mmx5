#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern u8 D_800FB744_ovl10[];
extern u8 D_800FB748_ovl10[];
extern u8 D_800FB754_ovl10[];
extern u8 D_80074DA0[];
extern u8 D_80074EE0[];

void func_800F1FA0_ovl10(u8* obj) {
    u8* p;

    obj[0x5C] = 2;
    obj[0x60] = 3;
    *(u8**)(obj + 0x50) = D_800FB744_ovl10;
    *(u8**)(obj + 0x54) = D_800FB748_ovl10;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x16] = 0;
    *(u8**)(obj + 0x68) = D_800FB754_ovl10;
    p = *(u8**)(obj + 0x7C);
    *(u8**)(obj + 0x58) = D_80074DA0;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    *(s32*)(obj + 0x8) = *(s32*)(p + 0x8);
    *(s32*)(obj + 0xC) = *(s32*)(p + 0xC);
    obj[0x67] = 1;
    obj[0x3] = 0;
    switch (*(s8*)(obj + 2)) {
    case 0:
        set_animation(obj, 0xC);
        *(s32*)(obj + 0x8C) = 0x258;
        obj[0x90] = 0;
        obj[0x15] = 0;
        *(s32*)(obj + 0x20) = 0xFFFE0000;
        *(s32*)(obj + 0x24) = 0x20000;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0x1000;
        obj[0x4] = 1;
        obj[0x5] = 6;
        break;
    case 1:
        set_animation(obj, 0xC);
        *(s32*)(obj + 0x8C) = 0x258;
        obj[0x90] = 0;
        obj[0x15] = 0;
        *(s32*)(obj + 0x20) = 0xFFFF0000;
        *(s32*)(obj + 0x24) = 0x20000;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0x1000;
        obj[0x4] = 1;
        obj[0x5] = 6;
        break;
    case 2:
        set_animation(obj, 0xC);
        *(s32*)(obj + 0x8C) = 0x258;
        obj[0x15] = 0x40;
        obj[0x90] = 0;
        *(s32*)(obj + 0x20) = 0x10000;
        *(s32*)(obj + 0x24) = 0x20000;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0x1000;
        obj[0x4] = 1;
        obj[0x5] = 6;
        break;
    case 3:
        set_animation(obj, 0xC);
        *(s32*)(obj + 0x8C) = 0x258;
        obj[0x15] = 0x40;
        obj[0x90] = 0;
        *(s32*)(obj + 0x20) = 0x20000;
        *(s32*)(obj + 0x24) = 0x20000;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0x1000;
        obj[0x4] = 1;
        obj[0x5] = 6;
        break;
    case 4:
        *(u8**)(obj + 0x58) = D_80074EE0;
        *(s16*)(obj + 0x90) = 0;
        *(s16*)(obj + 0x92) = 0x3C;
        obj[0x60] = 0;
        obj[0x47] = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[0x4] = 2;
        obj[0x5] = 2;
        break;
    }
    obj[0x6] = 0;
}

extern void* D_800FB7CC_ovl10[];

void func_800F21D4_ovl10(u8* o) {
    u8* p;

    if (is_off_screen(o, 0x20, 0x20) == 0) {
        func_8002D9EC(o, 0x10, 0x10);
        if (*(s8*)(o + 5) != 3) {
            o[3] = 0;
        }
    } else {
        o[4] = 3;
    }
    if (func_80031DD0(o) < 0) {
        if (*(s8*)(o + 5) == 3) {
            g_Player[0xCA] = 0;
        }
        o[4] = 4;
        *(u16*)(o + 0x42) &= 0x7FFF;
    }
    if (g_Player[0xF7] == 0) {
        o[0x62] = 3;
        *(s32*)(o + 0x18) = *(s32*)(o + 8);
        *(s32*)(o + 0x1C) = *(s32*)(o + 0xC);
        ((void (*)(u8*))D_800FB7CC_ovl10[*(s8*)(o + 5)])(o);
    } else {
        o[0x62] = 0;
        func_800317B8(o);
    }
    p = *(u8**)(o + 0x7C);
    if (*(s8*)(p + 4) != 1) {
        if (*(s8*)(o + 5) == 3) {
            g_Player[0xCA] = 0;
        }
        o[4] = 3;
        return;
    }
    if ((u32)(o[4] - 3) < 2) {
        p[0x80] = 0;
    }
}
