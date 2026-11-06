#include "types.h"

extern u8* func_8002C938();
extern void func_8003D29C(s32, s32);
extern s8 D_8009A0A5;
extern u8 D_800D1C00[];

void func_800EF908_ovl04(u8* arg0) {
    u8* base = D_800D1C00;
    u8* p;
    s32 one;

    if ((s8)base[0x1D] == 2) {
        one = 1;
        p = func_8002C938();
        if (p != 0) {
            p[0] = one;
            p[1] = 0x1E;
            p[2] = one;
        }
        base[0x26] = 0;
        arg0[6] = 6;
    } else if (D_8009A0A5 == 20) {
        one = 1;
        p = func_8002C938();
        if (p != 0) {
            p[0] = one;
            p[1] = 0x1E;
            p[2] = one;
        }
        base[0x26] = 0;
        arg0[6]++;
    } else if (D_8009A0A5 == 2) {
        func_8003D29C(0x14, 0);
    }
}
