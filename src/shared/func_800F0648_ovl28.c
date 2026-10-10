/* Shared body (DK-5), from the banked draft of func_800F0648_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* func_8002D1A4();
extern void func_8002E058();
extern u8* func_8002D27C();

#define G (*(u8**)0x1F80004C)

void DEDUP_NAME(u8* arg0) {
    u8* p;

    p = func_8002D1A4();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x1A;
        *(s32*)(p + 8) = *(s32*)(arg0 + 8);
        *(s32*)(p + 0xC) = *(s32*)(arg0 + 0xC);
        p[2] = G[0x85];
        *(u8**)(p + 0x7C) = arg0;
        *(s32*)(p + 0x84) = 0;
        func_8002E058(p, *(s8*)(G + 0x85) & 0xFE);
        G[0x80] = 8;
        arg0[6]++;
        G[0x82]++;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x19;
        *(s32*)(p + 8) = *(s32*)(arg0 + 8);
        *(s32*)(p + 0xC) = *(s32*)(arg0 + 0xC);
        p[2] = G[0x85];
        *(u8**)(p + 0x50) = arg0;
    }
    if (*(s8*)(arg0 + 2) == 3) {
        G[0x89] = 0x5A;
        arg0[5] = 7;
        arg0[6] = G[0x8A];
        *(s16*)(arg0 + 0x7C) = (s8)G[0x8B];
        *(u16*)(arg0 + 0xE) = *(u16*)(G + 0x8E);
        *(s32*)(arg0 + 0x24) = *(s32*)(G + 0x90);
        *(s32*)(arg0 + 0x2C) = *(s32*)(G + 0x94);
    }
}
