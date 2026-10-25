#include "types.h"

extern u8* func_8002D078();

void func_800443E4(u8* a0, s8 a1) {
    u8* p = func_8002D078();
    if (p != 0) {
        p[0] = 1;
        p[1] = a1;
        p[2] = a0[0xCB];
        p[0x14] = a0[0x14];
        *(s32*)(p + 0x84) = a0[0x17];
        p[0x15] = a0[0x15];
    }
}
