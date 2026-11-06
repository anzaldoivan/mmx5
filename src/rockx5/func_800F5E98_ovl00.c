#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern void func_8002D89C(u8* obj);
extern u32* D_80098118;

void func_800F5E98_ovl00(u8* p) {
    s32 a;
    s32 b;

    p[3] = 1;
    *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(0x83)] >> 7;
    *(s32*)(p + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x83)];
    a = func_8002B5B4(0x83);
    b = func_8002B5B4(0x83);
    *(u16*)(p + 0x42) = ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
    p[0x16] = 1;
    p[4]++;
    func_8002D89C(p);
}
