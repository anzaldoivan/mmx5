#include "types.h"

extern u8 D_8009A420[];
extern u8 D_8006FADB;
extern u8 D_800D1D10;
extern Slot8002D27C D_800994A0[32];
extern u8 D_800E9300;
extern void func_8002002C(s32);

void func_8002BC50(u8* arg0) {
    u8* b;
    u16 i;
    u16 j;
    u8 z;
    u8* p;

    p = D_8009A420;
    if (((s8*)p)[4] != 0) {
        return;
    }
    if (p[8] != 0) {
        arg0[0] = 8;
        arg0[1] = 0;
        arg0[2] = 0;
        arg0[3] = 0;
    } else {
        arg0[6]++;
        D_800D1D10 = D_8006FADB;
    }

    z = 0;

    for (i = 0; i < 32; i++) {
        b = (u8*)&D_800994A0[i];
        for (j = sizeof(Slot8002D27C) - 1; j != 0xFFFF; j--) {
            *b++ = z;
        }
    }

    if (D_8009A420[8] != 0) {
        func_8002002C(1);
    }
    D_800E9300 = 0;
}
