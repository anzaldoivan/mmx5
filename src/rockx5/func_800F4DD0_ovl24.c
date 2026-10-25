#include "types.h"

extern u8* func_8002D27C(void);

void func_800F4DD0_ovl24(u8* obj, s16 x, s16 y, u8 kind, u8 arg4) {
    u8* p = func_8002D27C();

    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x2D;
        p[2] = kind;
        p[0x54] = obj[0x54];
        p[0x55] = 0;
        p[0x56] = arg4;
        *(s16*)(p + 0xA) = x;
        *(s16*)(p + 0xE) = y;
    }
}
