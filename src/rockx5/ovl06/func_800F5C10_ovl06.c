#include "types.h"

extern u8 D_800FE898_ovl06[];
extern u8 D_800FE914_ovl06[];
extern u8 D_800FE918_ovl06[];
extern u8 D_800FE91C_ovl06[];
extern u8 D_800750C0[];

void func_800F5C10_ovl06(u8* obj) {
    u8* p;
    s32 x;
    s32 y;

    obj[4] = 1;
    obj[5] = 2;
    obj[3] = 1;
    obj[0x5C] = 0x18;
    obj[6] = 0;
    obj[7] = 0;
    *(s16*)(obj + 0x7C) = 0;
    obj[0x60] = 5;
    *(u8**)(obj + 0x30) = D_800FE898_ovl06;
    *(u8**)(obj + 0x54) = D_800FE914_ovl06;
    *(u8**)(obj + 0x50) = D_800FE918_ovl06;
    *(u8**)(obj + 0x68) = D_800FE91C_ovl06;
    x = *(s32*)(obj + 8);
    y = *(s32*)(obj + 0xC);
    *(u8**)(obj + 0x58) = D_800750C0;
    obj[0x61] = 0;
    obj[0x67] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x16] = 5;
    *(s32*)(obj + 0x18) = x;
    *(s32*)(obj + 0x1C) = y;
    p = obj + 0x80;
    p[0xA] = 0;
    p[9] = 0;
    p[8] = 0;
    p[7] = 0;
    obj[0x86] = 0;
    obj[0x8D] = 0;
}
