#include "types.h"

extern u8* func_8002D27C(void);

void func_800F0C00_ovl24(s32 a0, u8 a1, s8 a2) {
    u8* p = func_8002D27C();

    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x2D;
        p[0x54] = a2;
        p[0x55] = 0;
        p[2] = a1;
    }
}
