#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern void func_800171E8(u8* obj, s32 state);
extern u32* D_80098118;
extern u8 D_800FAB24_ovl10[];

void func_800EEE7C_ovl10(u8* a0) {
    s32 r0;
    s32 r1;
    s8 v;

    a0[4] = 1;
    a0[6] = 0;
    a0[0x14] = 0;
    *(u8**)(a0 + 0x30) = D_800FAB24_ovl10;
    *(u16*)(a0 + 0x40) = D_80098118[func_8002B5B4(0x9A)] >> 7;
    r0 = func_8002B5B4(0x9A);
    r1 = func_8002B5B4(0x9A);
    *(u16*)(a0 + 0x42) = ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
    *(s32*)(a0 + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x9A)];
    v = ((s8*)a0)[2];
    if (v == 5) {
        a0[0x16] = v;
    } else {
        a0[0x16] = 0x11;
    }
    func_800171E8(a0, ((s8*)a0)[2]);
}
