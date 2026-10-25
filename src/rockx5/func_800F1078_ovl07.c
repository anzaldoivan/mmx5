#include "types.h"

extern u8 D_80091C44;
extern u8* func_8002D33C(u8* p, s32 backward);
extern s32 func_8003D29C(s32, s32);

void func_800F1078_ovl07(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        p = func_8002D33C(0, 1);
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x3B;
            p[2] = 0;
        }
        func_8003D29C(0x1F, 0x40);
        arg0[5]++;
    }
}
