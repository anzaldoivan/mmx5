#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_80074DA0[];
extern u8 D_800FAB2C_ovl09[];
extern u8 D_800FAB30_ovl09[];

void func_800F14A0_ovl09(u8* obj) {
    obj[0x5C] = 4;
    obj[0x60] = 4;
    obj[0x3] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x16] = 0;
    *(u8**)(obj + 0x68) = D_800FAB30_ovl09;
    *(u8**)(obj + 0x54) = D_800FAB2C_ovl09;
    *(s32*)(obj + 0x50) = 0;
    *(u8**)(obj + 0x58) = D_80074DA0;
    func_800171E8(obj, 2);
    obj[0x67] = 1;
    obj[0x8F] = 0;
    *(s16*)(obj + 0x8C) = 0x258;
    if (obj[0x15] == 0) {
        *(s32*)(obj + 0x20) = 0x10000;
        obj[0x15] = 0x40;
        *(s16*)(obj + 0xA) += 0x38;
    } else {
        *(s32*)(obj + 0x20) = 0xFFFF0000;
        obj[0x15] = 0;
        *(s16*)(obj + 0xA) -= 0x38;
    }
    obj[0x5] = 6;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0x4200;
    obj[0x4] = 1;
    obj[0x6] = 0;
}
