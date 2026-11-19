#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern u8 D_8009A0B4;
extern u32* D_80098118;
extern u8 D_800FEABC_ovl06[];
extern u8 D_800FEAB8_ovl06[];
extern u8 D_800750C0[];
extern s16 D_8009A21C;
extern u8 D_800FEA78_ovl06[];
extern u8 D_800FEA38_ovl06[];
extern u8 D_800767E0[];

void func_800F6378_ovl06(u8* a0) {
    s32 r;
    s32 r2;
    u8 k;
    u32* t;

    a0[0] = 0x41;
    a0[4]++;
    a0[0x14] = D_8009A0B4;
    *(u16*)(a0 + 0x40) = D_80098118[func_8002B5B4(0x8B)] >> 7;
    r = func_8002B5B4(0x8B);
    t = D_1F800020.u32s;
    *(s32*)(a0 + 0x3C) = (s32)t + t[r];
    r = func_8002B5B4(0x8B);
    r2 = func_8002B5B4(0x8B);
    *(s16*)(a0 + 0x42) = ((r * 4 + 0x18) % 16) | (((r2 + 6) / 4 + 0x1E0) << 6);
    a0[0x16] = 7;
    k = a0[2];
    a0[0x61] = 0;
    a0[0xA2] = 1;
    a0[0x75] = 1;
    a0[0x76] = 0;
    a0[0x47] = k;
    if ((s8)k >= 8) {
        a0[0x5C] = 0x20;
        a0[0x47] = 8;
        *(u8**)(a0 + 0x68) = D_800FEABC_ovl06;
        *(u8**)(a0 + 0x54) = D_800FEAB8_ovl06;
        *(u8**)(a0 + 0x58) = D_800750C0;
        a0[4]++;
        *(s16*)(a0 + 0x82) = D_8009A21C;
    } else {
        a0[0x5C] = 4;
        *(u8**)(a0 + 0x68) = D_800FEA78_ovl06 + (s8)k * 16;
        *(u8**)(a0 + 0x54) = D_800FEA38_ovl06 + (s8)k * 16;
        a0[0x65] = 0;
        *(u8**)(a0 + 0x58) = D_800767E0;
        a0[0] |= 8;
    }
}
