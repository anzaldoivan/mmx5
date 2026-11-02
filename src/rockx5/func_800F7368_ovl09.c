#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002B5B4(s32);
extern void func_8002D6FC(u8* obj);
extern u8 D_800767E0[];
extern u32* D_80098118;
extern s8 D_800D1C1D;
extern u8 D_800FB278_ovl09[];
extern u8 D_800FB2AC_ovl09[];
extern u8 D_800FB2B0_ovl09[];

void func_800F7368_ovl09(u8* p) {
    s32 a;
    s32 b;
    s8 mode;

    p[0] = 0x41;
    p[0x16] = 6;
    p[0x15] = 0;
    *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(0x8D)] >> 7;
    *(s32*)(p + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x8D)];
    a = func_8002B5B4(0x8D);
    b = func_8002B5B4(0x8D);
    *(u16*)(p + 0x42) = ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
    *(u8**)(p + 0x30) = D_800FB278_ovl09;
    p[0x67] = 0;
    p[0x75] = 0;
    *(u8**)(p + 0x68) = D_800FB2AC_ovl09;
    *(u8**)(p + 0x54) = D_800FB2B0_ovl09;
    *(u8**)(p + 0x58) = D_800767E0;
    p[0xA2] = 1;
    func_800171E8(p, 0);
    mode = ((s8*)p)[2];
    if (mode & 0x80) {
        if (D_800D1C1D != 0) {
            p[4] = 3;
        } else {
            func_8002D6FC(p);
            return;
        }
    } else if (D_800D1C1D < mode) {
        p[4] = 1;
    } else {
        func_8002D6FC(p);
        return;
    }
    p[5] = 0;
}
