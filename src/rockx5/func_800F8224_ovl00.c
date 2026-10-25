#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern u8 D_800D1C00[];

void func_800F8224_ovl00(u8* a0) {
    u8* p = D_800D1C00;

    if (((s8*)p)[0x28] != 0) {
        func_8002385C(0, 0xFF, p[0x2E]);
        p[0x16] = 1;
        p[0x13] = 1;
        p[0x19] = 1;
        p[0x18] = 1;
        p[0x17] = 1;
        p[0x14] = 1;
        p[0x15] = 1;
        a0[6]++;
    }
}
