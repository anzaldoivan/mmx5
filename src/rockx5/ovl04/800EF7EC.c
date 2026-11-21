#include "types.h"
#include "mmx5/globals.h"

extern void func_8002A600(s32, s32, s32);
extern u8* func_8002C938();
extern signed char D_8009A0A5;

void func_800EF7EC_ovl04(u8* arg0) {
    u8* p;

    if (D_8009A0A5 == 2) {
        func_8003D29C(0x1D, 0x40);
        func_8002A600(0x20, 2, 1);
        p = func_8002C938();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x1E;
            p[2] = 0;
        }
        arg0[6]++;
    }
}

extern s16 D_8009A202;
extern s8 D_800D1C1D;

void func_800EF86C_ovl04(u8* a0) {
    if (D_8009A202 >= 0x230) {
        func_8003D2C4();
        func_8003D29C(0x14, 0);
        D_800D1C1D = 1;
        a0[6] = 0;
        a0[5]++;
    }
}
