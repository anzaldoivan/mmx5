#include "types.h"

extern void func_8003D29C(s32, s32);
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
