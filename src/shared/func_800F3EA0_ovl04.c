/* Shared body (DK-5), from the banked draft of func_800F3EA0_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8001296C(s32);
extern void func_80024548(s32);
extern s32 func_8002A5C4(s32, s32, s32);
extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern s32 func_8002DFB0(void);
extern void func_8003D29C(s32, s32);
extern u8 D_8009A0A0[];
extern Bg800F3EA0 D_8009A1F8;
extern Glb800F3EA0 D_800D1C00;

void DEDUP_NAME(u8* arg0) {
    s32 i;
    u8* p;
    u8* b;

    if (D_800D1C00.unkF == 0) {
        if (*(s16*)(arg0 + 0x7C) == 0x15E) {
            if (D_800D1C00.unkC != 0xC) {
                D_8009A1F8.unk26 = 0x1590;
                D_8009A1F8.unk24 = 0x1590;
            } else {
                D_8009A1F8.unk26 = 0x480;
                D_8009A1F8.unk24 = 0x480;
            }
        }
        if (D_800D1C00.unkC != 0xC && *(s16*)(arg0 + 0x7C) < 0x104) {
            func_8003D29C(0x14, 0x40);
        }
        if (--*(s16*)(arg0 + 0x7C) == 0 && **(s8**)(arg0 + 0x80) == 0) {
            if (D_800D1C00.unkC != 0xC) {
                D_8009A1F8.unk57 = 0;
                D_8009A1F8.unkAB = 0;
            }
            func_8002A5C4(0x20, 6, 2);
            func_8001296C(2);
            b = D_8009A0A0;
            i = 0x1F;
            do {
                p = func_8002D27C();
                if (p != 0) {
                    p[0] = 0x41;
                    p[1] = 0x1A;
                    p[0x15] = func_8002DF78() & 0x40;
                    p[2] = (func_8002DFB0() & 1) + 1;
                    *(s32*)(p + 0x20) = 0;
                    *(s32*)(p + 0x30) = *(s32*)(arg0 + 0x30);
                    *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
                    *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
                    *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
                    p[0x14] = b[0x14];
                }
                i--;
            } while (i >= 0);
            D_800D1C00.unk24 = 1;
            D_800D1C00.unk25 = 0;
            D_800D1C00.unkA2 = 0x3A;
            D_800D1C00.unk20 = arg0;
            if (D_800D1C00.unkC == 0xC) {
                func_80024548(-1);
            } else {
                func_80024548(1);
            }
            *(s32*)(arg0 + 0x20) = 0xFFFF0000;
            *(s32*)(arg0 + 0x24) = 0;
            *(s16*)(arg0 + 0x7C) = 0x70;
            arg0[5]++;
        }
    }
}
