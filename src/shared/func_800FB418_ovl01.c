/* Shared body (DK-5), from the banked draft of func_800FB418_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern u8 D_8009A0A0[];
extern u8 D_8009A0B4;
extern s32 D_800FDBEC_ovl01[];
extern s32 D_800FDC0C_ovl01[];

void DEDUP_NAME(u8 n, u8* arg1, u8* arg2, s8 arg3) {
    u8* p;

    if (arg3 >= 10) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x10;
            p[2] = 10;
            *(s32*)(p + 0x8) = *(s32*)(arg2 + 0x8);
            *(s32*)(p + 0xC) = *(s32*)(arg2 + 0xC);
            *(s32*)(p + 0x3C) = *(s32*)(arg2 + 0x3C);
            *(u16*)(p + 0x40) = *(u16*)(arg2 + 0x40);
            *(u16*)(p + 0x42) = *(u16*)(arg2 + 0x42) & 0x7FFF;
            p[0x14] = D_8009A0B4;
            *(u8**)(p + 0x50) = arg2;
        }
    } else if (n != 0) {
        do {
            p = func_8002D27C();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x10;
                p[0x15] = func_8002DF78() & 0x40;
                p[2] = arg3;
                *(s32*)(p + 0x8) =
                    *(s32*)(arg2 + 0x8) + D_800FDBEC_ovl01[func_8002DF78() & 7];
                *(s32*)(p + 0xC) =
                    *(s32*)(arg2 + 0xC) + D_800FDC0C_ovl01[func_8002DF78() & 7];
                p[0x54] = arg1[n];
                *(s32*)(p + 0x3C) = *(s32*)(arg2 + 0x3C);
                *(u16*)(p + 0x40) = *(u16*)(arg2 + 0x40);
                *(u16*)(p + 0x42) = *(u16*)(arg2 + 0x42) & 0x7FFF;
                p[0x14] = D_8009A0A0[0x14];
            }
        } while (--n != 0);
    }
}
