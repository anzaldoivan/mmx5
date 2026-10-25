#include "types.h"

extern u8* func_8002D27C(void);
extern u8 D_800D1C00[];
extern u8 D_800F6DF0_ovl20[];
extern u8 D_800F6DF8_ovl20;

void func_800F0ED8_ovl20(u8* arg0) {
    u8* p = D_800D1C00;
    u8* obj;
    u8 idx;

    p[0x31] = 0;
    idx = D_800F6DF0_ovl20[0];
    p[0x32] = 1;
    p[0x30] = idx;
    p[0x2A] = D_800F6DF0_ovl20[(s8)idx];
    obj = func_8002D27C();
    if (obj != 0) {
        obj[0] = 0x41;
        obj[1] = 0x2B;
        obj[2] = 0;
    }
    obj = func_8002D27C();
    if (obj != 0) {
        obj[0] = 0x41;
        obj[1] = 0x2B;
        obj[2] = 1;
    }
    *(s16*)(arg0 + 8) = 0;
    arg0[2]++;
    D_800F6DF8_ovl20 = 0x1F;
}
