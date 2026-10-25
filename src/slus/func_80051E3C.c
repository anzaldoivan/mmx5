#include "types.h"

extern s32 func_8002DFB0(void);

void func_80051E3C(u8* p) {
    p[0x36] = 0;
    if (((s8*)p)[1] != 4) {
        *(s16*)(p + 0x34) = 0x7FFF;
        p[0] |= 0x81;
    } else {
        *(s16*)(p + 0x34) = 2;
        p[0] |= 0x82;
    }
    p[0x37] = 0;
    *(s16*)(p + 0x38) = *(s16*)(p + 0x8);
    p[0x3A] = func_8002DFB0() % 3;
    *(s32*)(p + 0x14) = 0;
    *(s32*)(p + 0x18) = 0;
    p[4]++;
}
