#include "types.h"

extern u8 D_800D1C00[];
extern u8 D_8009A169;
extern u16 D_800F4E90_ovl24[][8];
extern s32 func_8002DC14(void);
extern void func_8002385C(s32, s32, s32);

void func_800F0528_ovl24(u8* a0) {
    u8* p = D_800D1C00;
    u8 v = p[0x26];

    if ((u32)(v - 1) < 8 && ((s8*)p)[0x27] == 0 &&
        !((D_8009A169 >> ((s8)v - 1)) & 1)) {
        func_8002385C(D_800F4E90_ovl24[func_8002DC14()][((s8*)p)[0x26] - 1],
                      0xFF, 0);
        a0[2]++;
        return;
    }
    a0[1] = 5;
    a0[2] = 0;
}
