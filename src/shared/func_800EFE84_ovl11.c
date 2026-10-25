/* Shared body (DK-5), from the banked draft of func_800EFE84_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_800D1C00[];
void func_80017248(u8* obj);
s32 func_80016490(s32, s32, s32);
void func_800F03E0_ovl11(s32);

void DEDUP_NAME(u8* a0) {
    u8* p;
    u8* q;
    u8* r;
    u8* t;
    u8* tbl;
    s32 v;
    s8 hi;

    func_80017248(a0);
    if (((s8*)a0)[6] == 0) {
        q = a0 + 0x7C;
        q[9] = a0[0x85] - 1;
        p = q;
        if (q[9] == 0) {
            a0[0x85] = 4;
            t = D_8009A0A0;
            v = t[0x5C];
            hi = v & 0x80;
            r = D_800D1C00;
            tbl = r + 0x47;
            q = tbl;
            if ((v & 0x7F) >= ((s8*)tbl)[((s8*)t)[2]]) {
                a0[6] = 1;
                t[0x5C] = hi | tbl[((s8*)t)[2]];
            } else {
                t[0x5C] = hi | (v + 1);
            }
            func_80016490(0, 0xD, 0);
            p[8] = a0[0x84] - 1;
            if (p[8] == 0) {
                a0[6] = 1;
            }
        }
    } else {
        func_800F03E0_ovl11(0);
        a0[4] = 3;
        a0[5] = 0;
        a0[0] &= 0xF7;
    }
}
