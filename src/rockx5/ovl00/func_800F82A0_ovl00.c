#include "types.h"

extern u8 D_80091C44;
extern u8 D_800D1C00[];

void func_800F82A0_ovl00(u8* a0) {
    if (D_80091C44 == 0) {
        u8* p = D_800D1C00;

        a0[6]++;
        p[0x16] = 0;
        p[0x13] = 0;
        p[0x19] = 0;
        p[0x18] = 0;
        p[0x17] = 0;
        p[0x14] = 0;
        p[0x15] = 0;
    }
}
