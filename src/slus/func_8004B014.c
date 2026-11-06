#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 D_800771C8[];
extern s32 D_800771EC[];
extern u8 D_8009A0A0[];

void func_8004B014(u8* obj) {
    u8* g = D_8009A0A0;
    s32 v;

    if (*(s8*)(g + 5) != 0x29) {
        obj[4] = 3;
        return;
    }
    if (++*(s16*)(obj + 0x8C) >= 4) {
        func_800171E8(obj, 0);
        *(s32**)(obj + 0x50) = D_800771C8;
        *(s32**)(obj + 0x68) = D_800771EC;
        *(u16*)(obj + 0xA) = *(u16*)(g + 0xA);
        *(u16*)(obj + 0xE) = *(u16*)(g + 0xE);
        obj[0x64] = 1;
        v = *(s32*)(g + 0x20);
        *(s32*)(obj + 0x20) = v;
        if (v < 0) {
            *(s32*)(obj + 0x28) = -0x1000;
        } else if (v > 0) {
            *(s32*)(obj + 0x28) = 0x1000;
        } else {
            *(s32*)(obj + 0x28) = 0;
        }
        *(s32*)(obj + 0x24) = 0x2C000;
        *(s32*)(obj + 0x2C) = 0x1000;
        obj[0x67] = 1;
        obj[3] = 1;
        *(s16*)(obj + 0x8C) = 0;
        obj[5]++;
    }
}
