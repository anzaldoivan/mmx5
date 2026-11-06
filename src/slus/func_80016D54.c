#include "types.h"

extern void SsUtSetVVol(s16, s16, s16);
extern s32 SsUtKeyOffV(s16);
extern u8* D_8009A770[];

void func_80016D54(s32 arg0, s32 arg1) {
    u8* p;
    u8 v;
    u8 b;
    s8 i;
    u8 j;

    arg0 &= 0xFF;
    arg1 &= 0xFF;
    if (arg0 == 0xFF) {
        j = 0;
        do {
            SsUtSetVVol(j, 0, 0);
            SsUtKeyOffV(j);
            j++;
        } while (j < 24);
        return;
    }
    p = D_8009A770[arg0];
    p += arg1 * 4;
    b = p[3];
    v = b & 0x1F;
    for (i = (b & 0x60) >> 5; i >= 0; i--) {
        SsUtSetVVol(v, 0, 0);
        SsUtKeyOffV(v);
        v++;
    }
}
