/* Shared body (DK-5), from the banked draft of func_800F5E54_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* DEDUP_CALLEE();
extern s8 D_8009A0A2;

void DEDUP_NAME(u8* arg0) {
    u8* p;
    u8 t;

    p = DEDUP_CALLEE();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x27;
        p[4] = 0;
        *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
        *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32*)(p + 0x30) = *(s32*)(arg0 + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
        p[0x14] = arg0[0x14];
        t = arg0[0x15];
        p[0x15] = t;
        if (t != 0) {
            *(s32*)(p + 0x8) = *(s32*)(arg0 + 0x8) + 0x4EEE90;
        } else {
            *(s32*)(p + 0x8) = *(s32*)(arg0 + 0x8) + 0xFFB11170;
        }
        *(s32*)(p + 0xC) = *(s32*)(arg0 + 0xC) + 0xFFF70000;
        *(u8**)(p + 0x7C) = arg0;
        if (arg0[0x90] != 0) {
            *(u16*)(p + 0xE) += 0xB;
            if (p[0x15] != 0) {
                *(u16*)(p + 0xA) -= 8;
            } else {
                *(u16*)(p + 0xA) += 8;
            }
        }
    }
    arg0[6] = 4;
    arg0[0x87] = 0;
    *(s16*)(arg0 + 0x7E) = 0;
    if (D_8009A0A2 != 0) {
        *(s16*)(arg0 + 0x7E) = 0x3C;
    }
}
