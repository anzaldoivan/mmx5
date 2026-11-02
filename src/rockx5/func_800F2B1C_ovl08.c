#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002B5B4(s32);
extern u8 D_800750C0[];
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_800F3FBC_ovl08;
extern u8 D_800F3FC4_ovl08;
extern u8 D_800F3FC8_ovl08;

void func_800F2B1C_ovl08(u8* p) {
    s32 a;
    s32 b;

    p[0] = 0x41;
    p[0x15] = 0;
    p[0x75] = 0;
    p[0x76] = 0;
    p[0x67] = 0;
    *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(0x91)] >> 7;
    *(s32*)(p + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x91)];
    a = func_8002B5B4(0x91);
    b = func_8002B5B4(0x91);
    *(u16*)(p + 0x42) = ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
    *(u8**)(p + 0x30) = &D_800F3FBC_ovl08;
    p[0x14] = D_8009A0B4;
    func_800171E8(p, 0);
    p[0x16] = 6;
    p[0x60] = 0;
    p[0x5C] = 8;
    p[0x61] = 0;
    p[0x15] = 0;
    *(s32*)(p + 0x58) = (s32)D_800750C0;
    p[0x65] = 0;
    *(s32*)(p + 0x50) = 0;
    *(s32*)(p + 0x54) = (s32)&D_800F3FC4_ovl08;
    *(s32*)(p + 0x68) = (s32)&D_800F3FC8_ovl08;
    p[5] = 0;
    p[4] = 1;
    p[6] = 0;
}
