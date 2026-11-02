#include "types.h"

extern s32 func_8002DF78(void);
extern signed char D_800D1CA2;
extern u8 D_800FEB3C_ovl39[][4];

void func_800FAF08_ovl39(u8* arg0) {
    u8* o;
    u8* p;
    u8 v;
    u32 r;

    r = func_8002DF78() & 0xF;
    if (D_800D1CA2 / 2 < ((s8*)*(u8**)(arg0 + 0x7C))[0x5C]) {
        if (r < 2) {
            arg0[0x87] = 0;
        } else if (r < 7) {
            arg0[0x87] = 1;
        } else if (r < 9) {
            arg0[0x87] = 2;
        } else {
            arg0[0x87] = 3;
        }
    } else if (r < 7) {
        arg0[0x87] = 4;
    } else if (r < 8) {
        arg0[0x87] = 5;
    } else if (r < 10) {
        arg0[0x87] = 6;
    } else {
        arg0[0x87] = 7;
    }
    p = *(u8**)(arg0 + 0x7C) + 0x8D;
    if (p[((s8*)arg0)[2]] == 0 ||
        (p[((s8*)arg0)[2]]--, o = *(u8**)(arg0 + 0x7C),
         (o + ((s8*)arg0)[2])[0x8D] == 0)) {
        arg0[5] = 7;
        arg0[6] = 0;
        return;
    }
    v = o[0x89];
    if (v == 1) {
        arg0[0x87] = 6;
        arg0[0x88] = v;
    }
    arg0[0x88] = 0;
    if (((s8*)*(u8**)(arg0 + 0x7C))[7] != 0x11) {
        arg0[5] = 7;
    } else {
        arg0[5] = D_800FEB3C_ovl39[arg0[0x87]][0];
    }
    arg0[6] = 0;
    if (((s8*)arg0)[5] == 2) {
        *(s16*)(arg0 + 0x82) = 0xB4;
    }
}
