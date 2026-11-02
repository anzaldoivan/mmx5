#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_80074DA0[];
extern u8 D_800FD2B8_ovl01[];
extern u8 D_800FD2C0_ovl01[];
extern u8 D_800FD2C4_ovl01[];
extern u8 D_800FD2C8_ovl01[];
extern u8 D_800FD2CC_ovl01[];

void func_800F7238_ovl01(u8* obj) {
    s8 state;

    state = ((s8*)obj)[2];
    obj[3] = 0;
    obj[0x5C] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    switch (state) {
    case 0:
        obj[0x60] = 3;
        func_800171E8(obj, 2);
        *(u8**)(obj + 0x50) = D_800FD2B8_ovl01;
        *(s32*)(obj + 0x58) = 0;
        *(u8**)(obj + 0x68) = D_800FD2C8_ovl01;
        *(s32*)(obj + 0x54) = 0;
        obj[4] = 1;
        obj[5] = 0;
        obj[0x15] = 0;
        obj[0x16] = 6;
        *(u16*)(obj + 0xA) -= 0x20;
        func_8002D9EC(obj, 0x10, 0x10);
        break;
    case 1:
        obj[0x60] = 6;
        func_800171E8(obj, 9);
        *(s32*)(obj + 0x58) = 0;
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x54) = 0;
        *(s32*)(obj + 0x68) = 0;
        obj[4] = state;
        obj[5] = state;
        obj[0x15] = 0;
        obj[0x16] = 0x30;
        break;
    case 2:
        obj[3] = 1;
        func_800171E8(obj, 6);
        obj[0x60] = 4;
        obj[0x5C] = 3;
        *(u8**)(obj + 0x58) = D_80074DA0;
        *(u8**)(obj + 0x50) = D_800FD2C0_ovl01;
        *(u8**)(obj + 0x54) = D_800FD2C4_ovl01;
        *(u8**)(obj + 0x68) = D_800FD2CC_ovl01;
        obj[4] = state;
        obj[5] = 0;
        obj[0x15] = 0;
        obj[0x16] = 6;
        *(u16*)(obj + 0xE) -= 0x20;
        break;
    }
    obj[6] = 0;
    obj[7] = 0;
}
