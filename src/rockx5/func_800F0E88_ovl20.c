#include "types.h"

extern u8 D_800D1C00[];

void func_800F0E88_ovl20(u8* arg0) {
    u8* p;

    *(s16*)(arg0 + 8) += 1;
    if (*(s16*)(arg0 + 8) >= 10) {
        p = D_800D1C00;
        p[0x26] = 0;
        *(s16*)(arg0 + 8) = 0;
        arg0[2]++;
        p[0x27] = 0x1F;
        p[0x2B] = 0;
    }
}
