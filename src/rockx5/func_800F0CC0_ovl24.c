#include "types.h"

extern u8* func_8002D27C(void);

void func_800F0CC0_ovl24(u8* arg0, u8 arg1, s8 arg2, s16 arg3, s16 arg4) {
    u8* p = func_8002D27C();

    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x2D;
        p[0x54] = arg2;
        p[0x55] = 0;
        p[2] = arg1;
        *(s16*)(p + 0xA) = arg3;
        *(s16*)(p + 0xE) = arg4;
    }
}
