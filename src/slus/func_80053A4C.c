#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_800D1C00[];
s32 func_80016490(s32, s32, s32);
void func_800545DC(s32);

void func_80053A4C(u8* a0) {
    u8* p;
    u8* q;
    u8* r;
    u8* t;
    u8* tbl;
    s32 v;
    s8 hi;

    if (((s8*)a0)[6] == 0) {
        q = a0 + 0x80;
        q[4] = a0[0x84] - 1;
        p = q;
        if (q[4] == 0) {
            a0[0x84] = 2;
            t = D_8009A0A0;
            v = t[0x5C];
            hi = v & 0x80;
            r = D_800D1C00;
            tbl = r + 0x47;
            q = tbl; /* load-bearing: dropping it gives diff 59 of 71 words (T5) */
            if ((v & 0x7F) >= ((s8*)tbl)[((s8*)t)[2]]) {
                a0[6] = 1;
                t[0x5C] = hi | tbl[((s8*)t)[2]];
            } else {
                t[0x5C] = hi | (v + 1);
            }
            func_80016490(0, 0xD, 0);
            p[3] = a0[0x83] - 1;
            if (p[3] == 0) {
                a0[6] = 1;
                a0[3] = 0;
            }
        }
    } else {
        func_800545DC(0);
        a0[4] = 3;
        a0[5] = 0;
        a0[0] &= 0xF7;
    }
}
