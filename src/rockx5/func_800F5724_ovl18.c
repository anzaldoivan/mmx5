#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern u8 D_800767E0[];
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_800F7F68_ovl18;

void func_800F5724_ovl18(u8* p) {
    s32 r0;
    s32 r1;

    p[4] = 1;
    p[5] = 2;
    p[6] = 0;
    p[0] = 0x41;
    p[0x15] = 0;
    p[3] = 0;
    p[0x14] = D_8009A0B4;
    *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(0x9B)] >> 7;
    *(s32*)(p + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x9B)];
    r0 = func_8002B5B4(0x9B);
    r1 = func_8002B5B4(0x9B);
    *(u16*)(p + 0x42) = ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
    p[0x16] = 7;
    *(u8**)(p + 0x30) = &D_800F7F68_ovl18;
    p[0x75] = 1;
    p[0xA2] = 1;
    *(u8**)(p + 0x58) = D_800767E0;

    p[0x65] = 0;
    *(s32*)(p + 0x54) = 0;
    p[0x61] = 0;
    p[0x60] = 0;
    p[0x66] = 4;
}
