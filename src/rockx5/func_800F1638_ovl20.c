#include "types.h"

extern u8* func_8002D27C(void);
extern u8 D_800D1C00[];

void func_800F1638_ovl20(u8* a0) {
    s32 i;
    u8* p;

    D_800D1C00[0x30] = 0;
    D_800D1C00[0x31] = 0;
    a0[2]++;
    for (i = 0; i < 3; i++) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x2C;
            p[2] = i + 4;
        }
    }
}
