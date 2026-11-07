#include "types.h"

extern void func_80017348(u8* a0, s32 a1, s32 a2);
extern void func_8003B33C(u8*, s32);
extern u8 D_80077260[];
extern u8 D_80077264[];
extern u8 D_8009A0A0[];

void func_8004C898(u8* obj) {
    u8* g = D_8009A0A0;
    s32 t;

    obj[2] = 1;
    obj[0x14] = g[0x14];
    obj[0x15] = g[0x15];
    *(s32*)(obj + 0x30) = *(s32*)(g + 0x30);
    t = 0x540;
    *(s16*)(obj + 0x40) = t;
    t = 0x780D;
    *(s16*)(obj + 0x42) = t;
    obj[0x16] = 1;
    obj[3] = 1;
    *(u8**)(obj + 0x68) = D_80077260;
    *(u8**)(obj + 0x50) = D_80077264;
    *(u16*)(obj + 0xA) = *(u16*)(g + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(g + 0xE);
    func_8003B33C(obj, 0x61);
    obj[0x48] = 0xFF;
    obj[0x49] = 0;
    if (g[0x15] != 0) {
        *(s32*)(obj + 0x20) = *(s32*)(g + 0x118) * 2;
    } else {
        *(s32*)(obj + 0x20) = -*(s32*)(g + 0x118) * 2;
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[4]++;
    func_80017348(obj, 0x140, 0x40);
}
