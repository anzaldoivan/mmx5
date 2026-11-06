#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern void func_8002D89C(u8*, s32, s32, s32);
extern u32* D_80098118;

void func_800F7DE0_ovl00(u8* a0) {
    s32 r;
    s32 r2;
    u32* t;
    u8 b;
    s32 sum;
    s32 one;

    *(u16*)(a0 + 0x40) = D_80098118[func_8002B5B4(0x8A)] >> 7;
    r = func_8002B5B4(0x8A) *
        2; // !FAKE: *4 split as *2 *2 keeps the sll in s0 after the call
    r2 = func_8002B5B4(0x8A);
    *(s16*)(a0 + 0x42) = ((r * 2 + 0x18) % 16) | (((r2 + 6) / 4 + 0x1E0) << 6);
    r = func_8002B5B4(0x8A);
    t = D_1F800020.u32s;
    one = 1;
    b = a0[2];
    sum = (s32)t + t[r];
    a0[0x14] = one;
    a0[0x16] = 0x31;
    a0[3] = one;
    a0[0x15] = 0;
    a0[0x47] = b;
    *(s32*)(a0 + 0x20) = 0;
    *(s32*)(a0 + 0x24) = 0;
    *(s32*)(a0 + 0x28) = 0;
    *(s32*)(a0 + 0x2C) = 0;
    a0[4]++;
    a0[5] = 0;
    *(s32*)(a0 + 0x3C) = sum;
    func_8002D89C(a0, one, sum, b);
}
