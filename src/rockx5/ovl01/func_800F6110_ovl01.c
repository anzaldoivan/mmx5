#include "types.h"
#include "addr.h"

extern u8* func_8002C938();
extern s32 func_8002B5B4(s32);
extern u32* D_80098118;

void func_800F6110_ovl01(u8* a0) {
    u8* p;
    s32 r0;
    s32 r1;

    p = func_8002C938();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x10;
        p[2] = a0[2] + 0x20;
        *(u16*)(p + 0xA) = *(u16*)(a0 + 0xA);
        *(u16*)(p + 0xE) = *(u16*)(a0 + 0xE);
        *(s32*)(p + 0x10) = 0;
        *(u8**)(p + 0x80) = a0;
        *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(((s8*)a0)[1])] >> 7;
        r0 = func_8002B5B4(((s8*)a0)[1]);
        r1 = func_8002B5B4(((s8*)a0)[1]);
        *(u16*)(p + 0x42) =
            ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
        *(s32*)(p + 0x3C) =
            (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(((s8*)a0)[1])];
    }
}
