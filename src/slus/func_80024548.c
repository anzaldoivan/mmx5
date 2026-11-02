#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_800D1C00[];
extern u16 D_800717EC[];

void func_80024548(s32 arg0) {
    u8* q = D_8009A0A0;
    u8* p = D_800D1C00;
    s32 i;
    s32 t;
    s16 v;
    u8* r;
    s32 bits;

    if (arg0 == 0 || p[0xA0] == 0) {
        p[0xC0] = 1;
        return;
    }
    v = 0;
    if (arg0 < 0) {
        p[0xC0] = 0x60;
        p[0xA2] = 0x7F;
        return;
    }
    i = 0;
    r = p + 0xAA;
    arg0 = 0x10000;
    bits = q[0xC9];
    do {
        if ((bits >> i) & 1) {
            s32 old = arg0;
            arg0 += 0x10000;
            v = old >> 16;
        }
        i++;
    } while (i < 8);
    t = 0x34BC00 - *(s32*)(p + 0xAC);
    if (t < 0) {
        t = 0;
    }
    v = v + t / 432000 * 2;
    v += (s16)D_800717EC[r[(s8)q[2]]];
    if (v < 0x5F) {
        p[0xC0] = v + 1;
    } else {
        p[0xC0] = 0x60;
    }
    v = v + (s8)p[0xA2];
    if (v >= 0x80) {
        p[0xA2] = 0x7F;
        return;
    }
    p[0xA2] = v;
}
