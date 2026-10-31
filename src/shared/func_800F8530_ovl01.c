/* Shared body (DK-5), from the banked draft of func_800F8530_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern u32* D_80098118;
extern u8 D_8009A0B4;
extern s8 D_800D1C00[];
extern u8 D_800FD57C_ovl01[];
extern u8 D_800FDA14_ovl01[];
extern u16 D_800FDA98_ovl01[];
extern u16 D_800FDAA4_ovl01[];

void DEDUP_NAME(u8* arg0) {
    u8* p;
    s32 off;

    arg0[0x60] = 5;
    arg0[0x93] = 0;
    arg0[0x94] = 0;
    arg0[0x5C] = 0;
    arg0[0x61] = 0;
    *(s32*)(arg0 + 0x58) = 0;
    if (D_800D1C00[0xC] != 0xC) {
        *(u16*)(arg0 + 0x40) = (*D_80098118 >> 7) + 0xB0;
    } else {
        *(u16*)(arg0 + 0x40) = (*D_80098118 >> 7) + 0x210;
        p = D_1F80009C;
        off = *(s32*)p;
        *(u16*)(arg0 + 0x42) = 0x7CC4;
        *(u8**)(arg0 + 0x3C) = p + off;
    }
    arg0[0x14] = D_8009A0B4;
    if (D_800D1C00[0xC] != 0xC) {
        *(s16*)(arg0 + 0xA) = 0x26A0;
        *(s16*)(arg0 + 0xE) = 0xC0;
    } else {
        *(s16*)(arg0 + 0xA) = 0x3A0;
        *(s16*)(arg0 + 0xE) = -0x20;
        D_800FDA98_ovl01[0] = D_800FDAA4_ovl01[0];
        D_800FDA98_ovl01[1] = D_800FDAA4_ovl01[1];
        D_800FDA98_ovl01[2] = D_800FDAA4_ovl01[2];
        D_800FDA98_ovl01[3] = D_800FDAA4_ovl01[3];
        D_800FDA98_ovl01[4] = D_800FDAA4_ovl01[4];
        D_800FDA98_ovl01[5] = D_800FDAA4_ovl01[5];
    }
    *(u8**)(arg0 + 0x30) = D_800FDA14_ovl01;
    arg0[0x16] = 5;
    *(u8**)(arg0 + 0x50) = D_800FD57C_ovl01;
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x24) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    arg0[0x67] = 0;
    *(s32*)(arg0 + 0x54) = 0;
    *(s32*)(arg0 + 0x68) = 0;
    arg0[0x15] = 0;
    arg0[0x80] = 0;
    arg0[0x82] = 0;
    arg0[0x81] = 0;
    arg0[0x89] = 0;
    arg0[0x95] = 0;
    arg0[0x96] = 0;
    arg0[0x98] = 0;
    arg0[0x8A] = 1;
    arg0[0x4] = 1;
    arg0[0x5] = 9;
    arg0[0x6] = 0;
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
}
