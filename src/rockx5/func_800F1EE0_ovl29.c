#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800750C0[];
extern u8 D_8009A0B4;
extern u8 D_800F9694_ovl29[];
extern u8 D_800F9540_ovl29[];

void func_800F1EE0_ovl29(u8* obj) {
    s32 one;

    obj[0x5C] = 6;
    obj[0x60] = 3;
    *(u8**)(obj + 0x58) = D_800750C0;
    obj[0x61] = 0;
    obj[0x14] = D_8009A0B4;
    *(u8**)(obj + 0x30) = D_800F9694_ovl29;
    obj[0x16] = 6;
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x67] = 0;
    *(s32*)(obj + 0x68) = 0;
    *(u8**)(obj + 0x54) = D_800F9540_ovl29;
    *(u8**)(obj + 0x50) = D_800F9540_ovl29;
    switch (((s8*)obj)[2]) {
    case 1:
        func_800171E8(obj, 1);
        obj[5] = 3;
        obj[0x15] = 0x40;
        *(s32*)(obj + 0x90) = 1;
        break;
    case 2:
        func_800171E8(obj, 0);
        obj[0x7A] = 1;
        obj[0x61] = 1;
        obj[5] = 2;
        obj[0x15] = 0;
        *(s32*)(obj + 0x80) = 0;
        *(s32*)(obj + 0x84) = 100;
        *(s32*)(obj + 0x90) = 0;
        break;
    case 3:
        func_800171E8(obj, 0);
        one = 1;
        obj[5] = 2;
        obj[0x7A] = one;
        obj[0x15] = 0x40;
        obj[0x61] = one;
        *(s32*)(obj + 0x80) = 0;
        *(s32*)(obj + 0x84) = 100;
        *(s32*)(obj + 0x90) = 0;
        break;
    case 4:
        func_800171E8(obj, 0);
        obj[0x7A] = 1;
        obj[0x61] = 1;
        obj[5] = 2;
        obj[0x15] = 0;
        *(s32*)(obj + 0x80) = 0;
        *(s32*)(obj + 0x84) = 140;
        *(s32*)(obj + 0x90) = 0;
        break;
    case 5:
        func_800171E8(obj, 0);
        one = 1;
        obj[5] = 2;
        obj[0x7A] = one;
        obj[0x15] = 0x40;
        obj[0x61] = one;
        *(s32*)(obj + 0x80) = 0;
        *(s32*)(obj + 0x84) = 140;
        *(s32*)(obj + 0x90) = 0;
        break;
    case 6:
        func_800171E8(obj, 0);
        obj[0x7A] = 1;
        obj[5] = 2;
        obj[0x61] = 1;
        obj[0x15] = 0;
        *(s32*)(obj + 0x80) = 1;
        *(s32*)(obj + 0x84) = 40;
        *(s32*)(obj + 0x90) = 0;
        break;
    case 7:
        func_800171E8(obj, 0);
        obj[0x7A] = 1;
        obj[5] = 2;
        obj[0x61] = 1;
        obj[0x15] = 0x40;
        *(s32*)(obj + 0x80) = 1;
        *(s32*)(obj + 0x84) = 40;
        *(s32*)(obj + 0x90) = 0;
        break;
    default:
        func_800171E8(obj, 1);
        obj[5] = 3;
        obj[0x15] = 0;
        *(s32*)(obj + 0x90) = 1;
        break;
    }
    obj[4] = 1;
    obj[6] = 0;
}
