#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D1A4();
extern s32 func_8002DF78(void);
extern u8 D_80074EE0[];
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern u8 D_800D1C26;
extern u8 D_800FE4D0_ovl06[];
extern u8 D_800FE4D4_ovl06[];
extern u8 D_800FE5F4_ovl06[];

void func_800F3780_ovl06(u8* o) {
    u8* c;
    u8* p;
    u16 t;
    u8* g;
    u8 x;

    o[0] = 0x41;
    o[3] = 1;
    o[4] = 1;
    o[5] = 2;
    o[6] = 0;
    o[7] = 0x3C;
    g = D_8009A0A0;
    x = g[0x14];
    o[0x15] = 0x40;
    *(u8**)(o + 0x30) = D_800FE5F4_ovl06;
    o[0x16] = 5;
    o[0x60] = 5;
    o[0x5C] = 1;
    *(s32*)(o + 0x68) = 0;
    *(u8**)(o + 0x50) = D_800FE4D0_ovl06;
    *(u8**)(o + 0x54) = D_800FE4D4_ovl06;
    *(u8**)(o + 0x58) = D_80074EE0;
    o[0x14] = x;
    *(s32*)(o + 0xC) = *(s32*)(g + 0xC);
    *(s32*)(o + 0xC) = *(s32*)(g + 0xC);
    *(s32*)(o + 0x20) = 0x30000;
    *(s32*)(o + 0x24) = 0;
    *(s32*)(o + 0x28) = 0;
    *(s32*)(o + 0x2C) = 0;
    o[0x88] = (func_8002DF78() & 3) + 1;
    *(s16*)(o + 0x7C) = 0;
    o[0x89] = 0;
    o[0x8A] = 0;
    o[0x8B] = 0;
    o[0x8C] = 0;
    o[0x8D] = 0;
    D_800D1C26 = 0;
    p = D_8009A1F8;
    t = *(u16*)(p + 0xA);
    *(u16*)(o + 0xA) = t;
    *(u16*)(p + 0x26) = t;
    func_800171E8(o, 0);
    c = func_8002D1A4();
    if (c != 0) {
        c[0] = 0x41;
        c[1] = 0xF;
        *(u16*)(c + 0x40) = *(u16*)(o + 0x40);
        *(u16*)(c + 0x42) = *(u16*)(o + 0x42);
        *(s32*)(c + 0x3C) = *(s32*)(o + 0x3C);
        c[0x14] = o[0x14];
        *(s32*)(c + 0x8) = *(s32*)(o + 0x8);
        *(s32*)(c + 0xC) = *(s32*)(o + 0xC);
        *(u8**)(c + 0x30) = *(u8**)(o + 0x30);
        *(u8**)(c + 0x7C) = o;
        c[2] = 1;
    }
}
