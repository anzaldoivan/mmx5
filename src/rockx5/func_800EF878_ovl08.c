#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_8009A0B4;
extern u8 D_800F3CE4_ovl08[];
extern s32 D_800F4000_ovl08;
extern s32 D_800F4004_ovl08;
extern s32 D_800F4008_ovl08;
extern s32 D_800F400C_ovl08;
extern u8 D_800F3B68_ovl08[];
extern u8 D_800F3B58_ovl08[];
extern u8 D_800F3B5C_ovl08[];
extern u8 D_800F3B64_ovl08[];
extern u8 D_800F3B60_ovl08[];
extern u8 D_800F3B7C_ovl08[];
extern u8 D_800F3B6C_ovl08[];
extern u8 D_800F3B70_ovl08[];
extern u8 D_800F3B78_ovl08[];
extern u8 D_800F3B74_ovl08[];

void func_800EF878_ovl08(u8* obj) {
    u8 t;

    obj[0x5C] = 6;
    obj[0x61] = 0;
    obj[0x14] = D_8009A0B4;
    obj[0x16] = 6;
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    *(u8**)(obj + 0x30) = D_800F3CE4_ovl08;
    obj[0x67] = 0;
    *(s32*)(obj + 0x54) = 0;
    *(s32*)(obj + 0x50) = 0;
    obj[0x70] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x99] = 1;
    obj[0x8B] = 0;
    switch ((s8)obj[2]) {
    case 0:
    case 4:
        *(s32*)(obj + 0x20) = -0x18000;
        obj[0x90] = 0;
        obj[0x15] = 0;
        obj[0x80] = 0;
        *(s32*)(obj + 0x8C) = 30;
        obj[5] = 2;
        break;
    case 1:
    case 5:
        obj[0x90] = 0;
        obj[0x80] = 0;
        obj[0x15] = 0x40;
        *(s32*)(obj + 0x20) = 0x18000;
        *(s32*)(obj + 0x8C) = 30;
        obj[5] = 3;
        obj[0x7A] = 1;
        break;
    case 2:
    case 6:
        obj[0x90] = 0;
        obj[0x15] = 0;
        obj[0x82] = 30;
        obj[0x80] = 1;
        *(s32*)(obj + 0x8C) = 300;
        obj[0x88] = 0;
        obj[0x89] = 20;
        obj[0x8A] = 0;
        obj[5] = 6;
        break;
    case 3:
    case 7:
        obj[0x90] = 0;
        obj[0x15] = 0x40;
        obj[0x82] = 30;
        obj[0x80] = 1;
        *(s32*)(obj + 0x8C) = 300;
        obj[0x88] = 1;
        obj[0x89] = 20;
        obj[0x8A] = 0;
        obj[0x7A] = 1;
        obj[5] = 3;
        break;
    case 8:
        obj[0x90] = 1;
        obj[0x91] = 0x30;
        obj[0x15] = 0;
        obj[0x80] = 0;
        obj[0x8A] = 0;
        *(s32*)(obj + 0x20) = -0x18000;
        obj[5] = 2;
        break;
    case 9:
        obj[0x90] = 1;
        obj[0x91] = 0x30;
        obj[0x15] = 0x40;
        obj[0x80] = 0;
        obj[0x8A] = 0;
        *(s32*)(obj + 0x20) = 0x18000;
        obj[5] = 2;
        break;
    case 10:
        obj[0x90] = 2;
        obj[0x91] = 0x30;
        obj[0x92] = 2;
        obj[0x15] = 0;
        obj[0x80] = 0;
        obj[0x8A] = 0;
        *(s32*)(obj + 0x20) = -0x18000;
        obj[5] = 2;
        break;
    case 11:
        obj[0x90] = 2;
        obj[0x92] = 2;
        obj[0x91] = 0x30;
        obj[0x15] = 0x40;
        obj[0x80] = 0;
        obj[0x8A] = 0;
        *(s32*)(obj + 0x20) = 0x18000;
        obj[5] = 2;
        break;
    case 17:
        obj[0x90] = 0;
        obj[0x15] = 0;
        *(s32*)(obj + 0x20) = 0;
        obj[0x80] = 0;
        *(s32*)(obj + 0x8C) = 30;
        obj[5] = 2;
        break;
    case 16:
        obj[0x15] = 0x40;
        obj[0x90] = 0;
        *(s32*)(obj + 0x20) = 0;
        obj[0x80] = 0;
        *(s32*)(obj + 0x8C) = 30;
        obj[5] = 2;
        break;
    }
    t = obj[2];
    if (t < 4 || (t >= 8 && t < 12)) {
        obj[0x60] = 6;
        *(u8**)(obj + 0x68) = D_800F3B68_ovl08;
        D_800F4000_ovl08 = (s32)D_800F3B58_ovl08;
        D_800F4004_ovl08 = (s32)D_800F3B5C_ovl08;
        D_800F4008_ovl08 = (s32)D_800F3B64_ovl08;
        D_800F400C_ovl08 = (s32)D_800F3B60_ovl08;
    } else {
        obj[0x60] = 7;
        *(u8**)(obj + 0x68) = D_800F3B7C_ovl08;
        D_800F4000_ovl08 = (s32)D_800F3B6C_ovl08;
        D_800F4004_ovl08 = (s32)D_800F3B70_ovl08;
        D_800F4008_ovl08 = (s32)D_800F3B78_ovl08;
        D_800F400C_ovl08 = (s32)D_800F3B74_ovl08;
    }
    if (obj[2] & 0x10) {
        obj[0x60] = 6;
        *(u8**)(obj + 0x68) = D_800F3B68_ovl08;
        D_800F4000_ovl08 = (s32)D_800F3B58_ovl08;
        D_800F4004_ovl08 = (s32)D_800F3B5C_ovl08;
        D_800F4008_ovl08 = (s32)D_800F3B64_ovl08;
        D_800F400C_ovl08 = (s32)D_800F3B60_ovl08;
        func_800171E8(obj, 0);
    } else {
        func_800171E8(obj, 1);
    }
    obj[4] = 1;
    obj[6] = 0;
}
