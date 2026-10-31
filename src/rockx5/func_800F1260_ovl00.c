#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern s32 func_800171E8(u8* obj, s32 state);
extern u32* D_80098118;
extern u8 D_800FA9B0_ovl00;

void func_800F1260_ovl00(u8* p) {
    s32 r0;
    s32 r1;

    p[0] = 0x41;
    *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(0x96)] >> 7;
    *(s32*)(p + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x96)];
    r0 = func_8002B5B4(0x96);
    r1 = func_8002B5B4(0x96);
    *(u16*)(p + 0x42) = ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
    *(u8**)(p + 0x30) = &D_800FA9B0_ovl00;
    p[0x14] = 0;
    p[0x15] = 0;
    *(u16*)(p + 0xA) = 0x11EB;
    *(u16*)(p + 0xE) = 0x145;
    *(u16*)(p + 0x40) -= 0x100;
    func_800171E8(p, 0);
    p[0x16] = 0x10;
    p[4]++;
}
