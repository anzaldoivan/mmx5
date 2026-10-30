/* Shared body (DK-5), from the banked draft of func_800F8330_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80033024(u8* a0);
extern s32 func_80032F70(u8* a0);
extern s32 func_8004FD90(u8*, s32, s32, s32);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D89C(u8*);
extern int func_8002D7A0();
extern void func_8003258C(u8* a0);
extern s32 func_800326BC(u8* a0);
extern s8 D_800D1C00[];
extern void* D_801016E4_ovl07[];

void DEDUP_NAME(u8* arg0) {
    s16 y;
    s16 cmp;
    s16 val;

    if (D_800D1C00[0xC] == 7) {
        y = *(s16*)(arg0 + 0xE);
        if (y >= 0x468) {
            arg0[0x16] = 0x23;
        } else if (y >= 0x458) {
            arg0[0x16] = 0x22;
        } else if (y >= 0x428) {
            arg0[0x16] = 0x21;
        } else {
            arg0[0x16] = 0x20;
        }
    } else {
        y = *(s16*)(arg0 + 0xE);
        if (y >= 0x4F8) {
            arg0[0x16] = 0x37;
        } else if (y >= 0x4C8) {
            arg0[0x16] = 0x36;
        } else if (y >= 0x498) {
            arg0[0x16] = 0x35;
        } else if (y >= 0x468) {
            arg0[0x16] = 0x34;
        } else if (y >= 0x438) {
            arg0[0x16] = 0x33;
        } else if (y >= 0x408) {
            arg0[0x16] = 0x32;
        }
    }
    func_80033024(arg0);
    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    ((void (*)(u8*))D_801016E4_ovl07[(s8)arg0[6]])(arg0);
    if ((s8)func_80032F70(arg0) < 0) {
        func_8004FD90(arg0, 1, 0x1F, 0xF);
        arg0[4] = 2;
        return;
    }
    if (func_8002D938(arg0, 0x80, 0x80) == 0) {
        func_8002D89C(arg0);
    } else {
        val = D_800D1C00[0xC];
        if (val == 7) {
            cmp = 1;
            val = D_800D1C00[0x1D];
        } else {
            cmp = 0x1ED8;
            val = *(s16*)(arg0 + 0xA);
        }
        if (val != cmp) {
            func_8002D7A0(arg0);
        }
    }
    func_8003258C(arg0);
    func_800326BC(arg0);
    if (arg0[0x70] & 8) {
        arg0[0x67] = 0;
        return;
    }
    if (*(s32*)(arg0 + 0x24) < 0) {
        *(s8*)(arg0 + 0x67) = -1;
    } else {
        arg0[0x67] = 1;
    }
}
