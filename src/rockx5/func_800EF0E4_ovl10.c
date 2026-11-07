#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern u32* D_8007B2E8[];
extern u32* D_80098118;

void func_800EF0E4_ovl10(u8* a0, u8* a1) {
    s32 r0;
    s32 r1;
    u8 t;

    t = a1[0x14];
    a0[0x16] = 0x11;
    *(u32***)(a0 + 0x30) = D_8007B2E8;
    a0[0x14] = t;
    *(s32*)(a0 + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x9A)];
    *(u16*)(a0 + 0x40) = D_80098118[func_8002B5B4(0x9A)] >> 7;
    r0 = func_8002B5B4(0x9A);
    r1 = func_8002B5B4(0x9A);
    *(u16*)(a0 + 0x42) = ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
    a0[4]++;
}
