#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_8009A0B4;
extern u8 D_80075840[];

void func_800F1418_ovl05(u8* obj) {
    obj[0x5C] = 0xC;
    obj[0x60] = 0x10;
    obj[0x61] = 0;
    obj[0x14] = D_8009A0B4;
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x67] = 0;
    obj[0x16] = 1;
    *(s32*)(obj + 0x68) = 0;
    *(u8**)(obj + 0x58) = D_80075840;
    *(u8**)(obj + 0x54) = obj + 0x8C;
    *(u8**)(obj + 0x50) = obj + 0x8C;
    obj[0x91] = 1;
    switch (((s8*)obj)[2]) {
    case 0:
    case 3:
        ((s8*)obj)[0x8C] = -0x10;
        ((s8*)obj)[0x8D] = -4;
        obj[0x8E] = 0x20;
        obj[0x8F] = 4;
        func_800171E8(obj, 0);
        break;
    case 1:
    case 4:
        ((s8*)obj)[0x8C] = -4;
        ((s8*)obj)[0x8D] = -0x10;
        obj[0x8E] = 4;
        obj[0x8F] = 0x20;
        func_800171E8(obj, 3);
        break;
    case 2:
    case 5:
        obj[0x8C] = 0;
        ((s8*)obj)[0x8D] = -0x10;
        obj[0x8E] = 4;
        obj[0x8F] = 0x20;
        func_800171E8(obj, 6);
        break;
    }
    obj[0x90] = 0;
    *(s16*)(obj + 0x8A) = 0;
    obj[0x15] = 0;
    obj[4] = 1;
    obj[5] = 2;
    obj[6] = 0;
    obj[3] = 0;
}
