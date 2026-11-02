#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern void func_800171E8(u8* obj, s32 state);
extern u32* D_80098118;
extern u8 D_800F9DC4_ovl03[];
extern u8 D_800F9DF0_ovl03[];
extern u8 D_800FA238_ovl03;

void func_800F2560_ovl03(u8* a0) {
    s32 r0;
    s32 r1;

    a0[0] = 0x41;
    a0[0x16] = 0;
    a0[0x15] = 0;
    *(u16*)(a0 + 0x40) = D_80098118[func_8002B5B4(0x9D)] >> 7;
    *(s32*)(a0 + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x9D)];
    r0 = func_8002B5B4(0x9D);
    r1 = func_8002B5B4(0x9D);
    *(u16*)(a0 + 0x42) = ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
    *(u8**)(a0 + 0x30) = D_800F9DC4_ovl03;
    *(u8**)(a0 + 0x68) = D_800F9DF0_ovl03;
    if (a0[2] & 1) {
        func_800171E8(a0, 1);
    } else {
        func_800171E8(a0, 0);
    }
    if (((s8*)a0)[2] == 0) {
        D_800FA238_ovl03 = 0;
        a0[5] = 1;
    } else {
        a0[5] = 0;
    }
    a0[4]++;
}
