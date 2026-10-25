#include "types.h"

extern s32 func_8003D2C4(void);
extern u8 D_8009A0A0[];
extern u8 D_80091C44;
extern u8 D_800D1C00[];

void func_80056F20(u8* a0) {
    u8* g;

    D_8009A0A0[0x71] |= 8;
    if (D_80091C44 == 0) {
        g = D_800D1C00;
        g[0x12] = 0;
        g[0x13] = 0;
        g[0x16] = 0;
        g[0x19] = 0;
        g[0x18] = 0;
        g[0x17] = 0;
        g[0x14] = 0;
        g[0x15] = 0;
        func_8003D2C4();
        a0[4]++;
    }
}
