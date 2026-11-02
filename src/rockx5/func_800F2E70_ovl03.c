#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002B5B4(s32);
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_800F9E2C_ovl03;
extern u8 D_800F9E4C_ovl03;
extern u8 D_800F9E50_ovl03;

void func_800F2E70_ovl03(u8* p) {
    s32 a;
    s32 b;

    p[0] = 0x41;
    p[0x15] = 0;
    *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(0x9D)] >> 7;
    *(s32*)(p + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x9D)];
    a = func_8002B5B4(0x9D);
    b = func_8002B5B4(0x9D);
    *(u16*)(p + 0x42) = ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
    p[0x75] = 1;
    p[0x76] = 0;
    p[0x67] = 0;
    *(u8**)(p + 0x30) = &D_800F9E2C_ovl03;
    p[0x14] = D_8009A0B4;
    p[0x16] = 6;
    p[0x60] = 0;
    p[0x5C] = 1;
    p[0x61] = 0;
    p[0x15] = 0;
    p[0x65] = 0;
    *(s32*)(p + 0x58) = 0;
    *(s32*)(p + 0x50) = 0;
    *(u8**)(p + 0x54) = &D_800F9E4C_ovl03;
    *(u8**)(p + 0x68) = &D_800F9E50_ovl03;
    func_800171E8(p, 0);
    p[0xA2] = 1;
    p[4] = 1;
    p[5] = 1;
    p[6] = 0;
}
