#include "types.h"

extern u8* func_8002D27C(void);

void func_800F4D50_ovl24(u8* arg0, s16 arg1, s16 arg2, u8 arg3) {
    u8* p = func_8002D27C();

    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x2D;
        p[2] = arg3;
        p[0x54] = arg0[0x54];
        p[0x55] = 0;
        *(s16*)(p + 0xA) = arg1;
        *(s16*)(p + 0xE) = arg2;
    }
}
