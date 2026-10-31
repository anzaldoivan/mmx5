/* Shared body (DK-5), from the banked draft of func_800F3670_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80024548(s32);
extern u8* func_8002D27C();
extern u8 D_800D1C00[];

void DEDUP_NAME(u8* arg0) {
    s16 t;
    s32 m;
    u8* p;
    u8* q;
    u8* g;

    if (**(s8**)(arg0 + 0x80) == 0) {
        t = *(s16*)(arg0 + 0x7C);
        m = 7;
        if (t >= 0xD3) {
            m = 0x3F;
        }
        if (!(t & m)) {
            p = func_8002D27C();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x23;
                p[2] = 0;
                *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
                *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
                *(s32*)(p + 0x30) = *(s32*)(arg0 + 0x30);
                *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42);
                p[0x15] = arg0[0x15];
            }
        }
        if (--*(s16*)(arg0 + 0x7C) < 0x8D) {
            q = func_8002D27C();
            if (q != 0) {
                q[0] = 0x41;
                q[1] = 0x23;
                q[2] = 3;
                *(s32*)(q + 0x3C) = *(s32*)(arg0 + 0x3C);
                *(u16*)(q + 0x40) = *(u16*)(arg0 + 0x40);
                *(s32*)(q + 0x30) = *(s32*)(arg0 + 0x30);
                *(u16*)(q + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
                q[0x15] = arg0[0x15];
                *(s32*)(q + 0x8) = *(s32*)(arg0 + 0x8);
                *(s32*)(q + 0xC) = *(s32*)(arg0 + 0xC);
                *(u8**)(q + 0x50) = arg0;
            }
            g = D_800D1C00;
            g[0x24] = 1;
            g[0x25] = 0;
            g[0xA2] = 0x30;
            *(u8**)(g + 0x20) = arg0;
            if (*(s8*)(g + 0xC) == 0xC) {
                func_80024548(-1);
            } else {
                func_80024548(1);
            }
            arg0[0x8C] = 1;
            *(s32*)(arg0 + 0x2C) = 0xC00;
            *(s32*)(arg0 + 0x24) = 0x30000;
            arg0[6] = 3;
        }
    }
}
