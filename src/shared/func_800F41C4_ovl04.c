/* Shared body (DK-5), from the banked draft of func_800F41C4_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* func_8002D27C(void);
extern u8* func_8002D210();
extern s32 func_8002DF78(void);
extern s32 func_8002DFB0(void);
extern u8 D_8009A0A0[];

void DEDUP_NAME(u8* arg0) {
    u8* base;
    s32 i;
    u8* p;
    u8* q;

    base = D_8009A0A0;
    i = 5;
    do {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x1A;
            p[0x15] = func_8002DF78() & 0x40;
            p[2] = 8;
            *(s32*)(p + 0x20) = 0x40000;
            *(s32*)(p + 0x30) = *(s32*)(arg0 + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
            *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
            *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
            *(u16*)(p + 0xA) =
                *(u16*)(arg0 + 0xA) + ((func_8002DFB0() & 0xF) + 0x18);
            *(u16*)(p + 0xE) = *(u16*)(arg0 + 0xE) + (func_8002DFB0() & 7) + 8;
            p[0x14] = base[0x14];
        }
        i--;
    } while (i >= 0);
    q = func_8002D210();
    if (q != 0) {
        q[0] = 0x41;
        q[1] = 7;
        *(s32*)(q + 8) = *(s32*)(arg0 + 8) + 0x280000;
        *(s32*)(q + 0xC) = *(s32*)(arg0 + 0xC) + 0x100000;
        q[2] = 0x66;
        *(s32*)(q + 0x20) = 0x40000;
        *(s32*)(q + 0x24) = 0;
        q[0x15] = arg0[0x15];
        *(u16*)(q + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(u16*)(q + 0x40) = *(u16*)(arg0 + 0x40);
        *(s32*)(q + 0x30) = *(s32*)(arg0 + 0x30);
        *(s32*)(q + 0x3C) = *(s32*)(arg0 + 0x3C);
        *(u8**)(q + 0x7C) = arg0;
        *(u16*)(q + 0x80) = *(u16*)(arg0 + 0xA) + 0x28;
    }
    *(u16*)(arg0 + 0x7C) = (func_8002DF78() & 3) * 10 + 1;
    arg0[6]++;
}
