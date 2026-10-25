#include "types.h"

extern u8 D_800D1C00[];

void func_800F0FB8_ovl20(u8* arg0) {
    u8* p = D_800D1C00;

    p[0x2B] = 1;
    p[0x31] = 1;
    *(s16*)(arg0 + 8) = 0;
    p[0x27] = 0;
    arg0[2]++;
}
