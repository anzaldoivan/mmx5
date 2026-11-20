#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern u8 D_80075020;
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_800F9CEC_ovl03;
extern u8 D_800F9CF0_ovl03;

void func_800F2170_ovl03(u8* p) {
    s32 r0;
    s32 r1;

    p[4] = 1;
    p[5] = 2;
    p[6] = 0;
    p[0] = 0x41;
    p[0x15] = 0;
    p[0x14] = D_8009A0B4;
    *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(0x8E)] >> 7;
    *(s32*)(p + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x8E)];
    r0 = func_8002B5B4(0x8E);
    r1 = func_8002B5B4(0x8E);
    *(u16*)(p + 0x42) = ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
    p[0x47] = 0;
    p[0x16] = 7;
    *(u8**)(p + 0x68) = &D_800F9CEC_ovl03;
    *(u8**)(p + 0x54) = &D_800F9CF0_ovl03;
    p[0x75] = 1;
    p[0xA2] = 1;
    p[0x60] = 0x10;
    p[0x61] = 0;
    p[0x65] = 0;
    *(u8**)(p + 0x58) = &D_80075020;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2C) = 0;
}
