#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800FDC4C_ovl01[];
extern u8 D_80074E40[];
extern u8 D_800FDC40_ovl01[];
extern u8 D_800FDC2C_ovl01[];

void func_800FB624_ovl01(u8* obj) {
    obj[4] = 1;
    obj[3] = 1;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    *(u16*)(obj + 0xE) += (s8)D_800FDC4C_ovl01[((s8*)obj)[2] * 2 + 1];
    obj[0x60] = 4;
    *(s32*)(obj + 0x24) = 0;
    if (obj[0x15] == 0) {
        *(s32*)(obj + 0x20) = -0x30000;
        *(u16*)(obj + 0xA) -= 0x30;
    } else {
        *(s32*)(obj + 0x20) = 0x30000;
        *(u16*)(obj + 0xA) += 0x30;
    }
    switch (((s8*)obj)[2]) {
    case 0:
        *(u8**)(obj + 0x58) = D_80074E40;
        func_80016490(2, 10, obj);
        func_800171E8(obj, 5);
        break;
    case 1:
        *(u8**)(obj + 0x58) = D_80074E40;
        func_80016490(2, 10, obj);
        func_800171E8(obj, 5);
        *(s32*)(obj + 0x24) = 0xC000;
        break;
    case 2:
        *(u8**)(obj + 0x58) = D_80074E40;
        func_80016490(2, 10, obj);
        func_800171E8(obj, 5);
        *(s32*)(obj + 0x24) = 0x18000;
        break;
    case 3:
    case 4:
        func_80016490(2, 11, obj);
        func_800171E8(obj, 4);
        obj[0x60] = 6;
        break;
    }
    obj[0x16] = 0;
    if (((s8*)obj)[2] < 3) {
        *(u8**)(obj + 0x68) = D_800FDC40_ovl01;
    }
    obj[0x5C] = 1;
    *(u8**)(obj + 0x50) = *(u8**)(obj + 0x54) =
        D_800FDC2C_ovl01 + ((s8*)obj)[2] * 4;
}
