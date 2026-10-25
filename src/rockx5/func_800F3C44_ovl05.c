#include "types.h"

extern s16 D_8009A0AA;
extern s16 D_8009A202;
extern s32 D_8009A420;
extern u8* func_8002D27C(void);

void func_800F3C44_ovl05(u8* o) {
    u8* p;

    if (D_8009A0AA < 0x471) {
        return;
    }
    if (++*(s16*)(o + 0x7C) >= 0xF0) {
        *(s16*)(o + 0x7C) = 0;
        o[6] = 0;
        o[5]++;
    }
    *(s16*)(o + 0xA) = D_8009A202 - 0x10;
    if (*(s16*)(o + 0x7C) < 0x3C) {
        return;
    }
    if (D_8009A420 & 0xF) {
        return;
    }
    p = func_8002D27C();
    if (p != 0) {
        *(u8**)(p + 0x50) = o;
        p[0] = 0x41;
        p[1] = 0x14;
        p[2] = 3;
    }
}
