#include "types.h"

extern s32 func_8002385C(s32, s32, s32);
extern u8 D_800D1C00[];

void func_800F0FE8_ovl07(u8* arg0) {
    u8* p;

    if ((u16)++ * (u16*)(arg0 + 0x9C) >= 0x5A) {
        p = D_800D1C00;
        if ((p[0xA1] & 1) || ((s8*)p)[0x26] == 0) {
            arg0[5] = 9;
        } else {
            func_8002385C(0x37, 0xFF, 0);
            arg0[5]++;
        }
    }
}
