#include "types.h"

extern void func_80024548(s32);
extern s32 func_8003D29C(s32, s32);
extern u8 D_80074EE0[];
extern u8 D_800D1C00[];
extern u8 D_800FB3DC_ovl00[];
extern u8 D_800FB3E8_ovl00[];
extern u8 D_800FB434_ovl00[];

void func_800F7FC4_ovl00(u8* o) {
    u8* g;

    *(u8**)(o + 0x30) = D_800FB434_ovl00;
    o[0x16] = 5;
    *(u8**)(o + 0x50) = D_800FB3DC_ovl00;
    *(u8**)(o + 0x54) = D_800FB3E8_ovl00;
    *(u8**)(o + 0x58) = D_80074EE0;
    *(s16*)(o + 0x40) = 0;
    *(s16*)(o + 0xA) = 0x127C;
    *(s16*)(o + 0xE) = 0x109;
    o[0x15] = 0;
    o[0x67] = 0;
    o[0x3] = 0;
    *(s32*)(o + 0x68) = 0;
    o[0x62] = 0;
    o[0x61] = 0;
    *(s32*)(o + 0x20) = 0;
    *(s32*)(o + 0x24) = 0;
    *(s32*)(o + 0x28) = 0;
    *(s32*)(o + 0x2C) = 0;
    o[0x5C] = 0;
    o[0x60] = 6;
    g = D_800D1C00;
    g[0x25] = 1;
    *(u8**)(g + 0x20) = o;
    g[0xA2] = 0x30;
    func_80024548(0);
    o[0x8A] = 0;
    o[0x90] = 0;
    func_8003D29C(0x14, 0x40);
    o[4]++;
    o[5] = 2;
}
