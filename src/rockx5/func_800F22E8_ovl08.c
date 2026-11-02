#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002B5B4(s32);
extern u8 D_800750C0[];
extern u8 D_80076A60;
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_800F3EFC_ovl08;
extern u8 D_800F3F38_ovl08;
extern u8 D_800F3F3C_ovl08;
extern u8 D_800F3F40_ovl08;

void func_800F22E8_ovl08(u8* p) {
    s32 a;
    s32 b;
    s8 mode;

    p[0] = 0x41;
    *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(0x90)] >> 7;
    *(s32*)(p + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x90)];
    a = func_8002B5B4(0x90);
    b = func_8002B5B4(0x90);
    *(u16*)(p + 0x42) = ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
    p[0x75] = 1;
    p[0x76] = 0;
    p[0x67] = 0;
    *(u8**)(p + 0x30) = &D_800F3EFC_ovl08;
    p[0x14] = D_8009A0B4;
    mode = ((s8*)p)[2];
    p[0x16] = 6;
    p[0x15] = 0;
    p[0x65] = 0;
    p[0x61] = 0;
    if (mode == 0) {
        p[0x5C] = 0x20;
        *(u8**)(p + 0x58) = D_800750C0;
        *(s32*)(p + 0x50) = 0;
        *(u8**)(p + 0x54) = &D_800F3F38_ovl08;
        *(u8**)(p + 0x68) = &D_800F3F3C_ovl08;
        func_800171E8(p, 3);
        p[4] = 1;
        p[5] = 0;
        p[6] = 0;
    } else if (mode == 1) {
        p[0x16] = 0x21;
        p[0x5C] = 4;
        *(u8**)(p + 0x58) = &D_80076A60;
        *(s32*)(p + 0x50) = 0;
        *(u8**)(p + 0x54) = &D_800F3F40_ovl08;
        *(s32*)(p + 0x68) = 0;
        func_800171E8(p, 0xB);
        p[3] = 0;
        p[4] = 4;
        p[5] = 0;
        p[6] = 0;
    } else if (mode == 2) {
        p[0x16] = 1;
        func_800171E8(p, 9);
        *(s32*)(p + 0x58) = 0;
        *(s32*)(p + 0x50) = 0;
        *(s32*)(p + 0x54) = 0;
        *(s32*)(p + 0x68) = 0;
        p[4] = 1;
        p[5] = 0;
        p[6] = 0;
    }
}
