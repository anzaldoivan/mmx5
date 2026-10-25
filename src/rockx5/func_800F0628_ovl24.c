#include "types.h"

extern u8 D_800D1C00[];
extern u8 D_8009A169;
extern void func_800EEB30_ovl24(void);

void func_800F0628_ovl24(u8* a0) {
    u8* p = D_800D1C00;
    u8 v = p[0x26];

    if ((u32)(v - 1) < 8 && ((s8*)p)[0x27] == 0 &&
        !((D_8009A169 >> ((s8)v - 1)) & 1)) {
        func_800EEB30_ovl24();
    }
    a0[1] = 5;
    a0[2] = 0;
}
