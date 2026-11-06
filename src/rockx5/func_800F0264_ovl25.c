#include "types.h"

extern u8* func_8002D27C(void);
extern s32 D_800D1DB4;

void func_800F0264_ovl25(u8* arg0) {
    u8* p;

    arg0[1]++;
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x38;
        p[2] = 1;
        *(s32*)(p + 0x54) = D_800D1DB4;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x38;
        p[2] = 0;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x38;
        p[2] = 9;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x38;
        p[2] = 7;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x38;
        p[2] = 8;
    }
}
