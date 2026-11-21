#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800FB2DC_ovl09[];
extern u8 D_800767E0[];

void func_800F9120_ovl09(u8* a0) {
    a0[0xA2] = 1;
    a0[0x3] = 0;
    a0[0x47] = 0;
    a0[0x5C] = 0;
    a0[0x61] = 0;
    a0[0x15] = 0;
    a0[0x65] = 0;
    *(s32*)(a0 + 0x50) = 0;
    *(s32*)(a0 + 0x54) = 0;
    *(u8**)(a0 + 0x68) = D_800FB2DC_ovl09;
    *(u8**)(a0 + 0x58) = D_800767E0;
    *(s32*)(a0 + 0x20) = 0;
    *(s32*)(a0 + 0x24) = 0;
    *(s32*)(a0 + 0x28) = 0;
    *(s32*)(a0 + 0x2C) = 0;
    a0[0x4] = 1;
    a0[0x5] = 0;
    a0[0x6] = 0;
}

extern s32 func_800326BC(u8* a0);

void func_800F9180_ovl09(u8* a0) {
    if (*(u16*)(*(u8**)(a0 + 0x7C) + 4) != 0x303) {
        a0[4] = 2;
    } else {
        *(s32*)(a0 + 0x18) = *(s32*)(a0 + 0x8);
        *(s32*)(a0 + 0x1C) = *(s32*)(a0 + 0xC);
        func_800326BC(a0);
    }
}

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800F91D4_ovl09
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
