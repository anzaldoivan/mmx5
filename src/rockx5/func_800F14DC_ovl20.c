#include "types.h"

extern u8* func_8002D27C(void);
extern u8 D_800D1C30;

void func_800F14DC_ovl20(u8* arg0) {
    u8* p;
    s32 i;

    D_800D1C30 = 0;
    arg0[2]++;
    for (i = 0; i < 4; i++) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x2E;
            p[2] = i + 8;
        }
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x2E;
            p[2] = i + 12;
        }
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x2E;
        p[2] = 0x10;
    }
}
