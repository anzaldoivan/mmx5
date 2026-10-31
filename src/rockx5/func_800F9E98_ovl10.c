#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern s32 func_800171E8(u8* obj, s32 state);
extern u32* D_80098118;
extern u8 D_800FC1B8_ovl10;

void func_800F9E98_ovl10(u8* p) {
    s32 r0;
    s32 r1;

    p[0] = 0x41;
    *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(0x9A)] >> 7;
    *(s32*)(p + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x9A)];
    r0 = func_8002B5B4(0x9A);
    r1 = func_8002B5B4(0x9A);
    *(u16*)(p + 0x42) = ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
    *(u8**)(p + 0x30) = &D_800FC1B8_ovl10;
    p[0x14] = 0;
    p[0x15] = 0;
    func_800171E8(p, ((s8*)p)[2]);
    p[0x16] = 7;
    p[4]++;
}
