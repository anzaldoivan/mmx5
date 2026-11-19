#include "types.h"

extern u8* func_8002C938();

void func_800FDDDC_ovl04(u8* arg0) {
    u8* o;

    if (++arg0[0x8D] == 4) {
        o = func_8002C938();
        if (o != 0) {
            o[1] = 3;
            o[2] = 0x11;
            o[0] = 0x41;
            *(s16*)(o + 0xA) = *(u16*)(arg0 + 0xA) - 0x30;
            *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
        }
    }
    if (arg0[0x8D] == 8) {
        o = func_8002C938();
        if (o != 0) {
            o[1] = 3;
            o[2] = 0x10;
            o[0] = 0x41;
            *(s16*)(o + 0xA) = *(u16*)(arg0 + 0xA) - 0x30;
            *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
        }
    }
    if (arg0[0x8D] >= 0xC) {
        arg0[6]--;
    }
}
