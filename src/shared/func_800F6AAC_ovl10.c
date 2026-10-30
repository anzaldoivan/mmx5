/* Shared body (DK-5), from the banked draft of func_800F6AAC_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DF54(u8* a0);
extern s32 func_800317B8(u8* a0);
extern void func_80017248(u8* obj);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D1A4();
extern s8 D_800D1C0C;
extern u8 D_800FBF34_ovl10[];

void DEDUP_NAME(u8* a0) {
    s32 lim;
    s32 x;
    s32 vx;
    s32 i;
    s32 n;
    u8* c;
    s8 m;

    if (D_800D1C0C != 0xC) {
        lim = 0x3C0;
        x = 0x2000;
        vx = 0x20900000;
    } else {
        lim = 0;
        x = 0xB00;
        vx = 0x0B900000;
    }
    func_8002DF54(a0);
    *(u16*)(a0 + 0x42) &= 0x7FFF;
    func_800317B8(a0);
    func_80017248(a0);
    if (func_80031DD0(a0) < 0) {
        a0[4] = 0xD;
        func_8004FD24(a0);
        return;
    }
    a0[0x15] = 0;
    if (*(s16*)(a0 + 0xE) < lim) {
        if (x < *(s16*)(a0 + 0xA)) {
            *(s32*)(a0 + 0x20) = 0;
            *(s32*)(a0 + 0x28) = 0x17D0;
            *(s32*)(a0 + 0x8) = vx;
        } else {
            *(s32*)(a0 + 0x20) = 0;
            *(s32*)(a0 + 0x28) = -0x17D0;
            *(s32*)(a0 + 0x8) = vx + 0xFEE00000;
        }
        *(s32*)(a0 + 0x24) = 0xFFFE0000;
        *(s32*)(a0 + 0x2C) = -0x770;
        *(u8**)(a0 + 0x68) = D_800FBF34_ovl10;
        a0[4] = 0xC;
        *(s16*)(a0 + 0x92) = 0x3C;
        *(s16*)(a0 + 0x88) = (*(s8*)(a0 + 2) * 0x3C) + 0x3C;
        func_800171E8(a0, 0xD);
        m = a0[2];
        if (m == 0) {
            i = 0;
            do {
                c = func_8002D1A4();
                n = i + 1;
                if (c != 0) {
                    c[0] = 0x41;
                    c[1] = 0x27;
                    c[2] = n;
                    c[4] = 0xA;
                    *(u16*)(c + 0x40) = *(u16*)(a0 + 0x40);
                    *(u16*)(c + 0x42) = *(u16*)(a0 + 0x42) & 0x7FFF;
                    *(s32*)(c + 0x30) = *(s32*)(a0 + 0x30);
                    *(s32*)(c + 0x3C) = *(s32*)(a0 + 0x3C);
                    c[0x14] = a0[0x14];
                    *(s32*)(c + 0x8) = *(s32*)(a0 + 0x8);
                    *(s16*)(c + 0xE) = lim - 1;
                    c[0x15] = a0[0x15];
                    *(s32*)(c + 0x7C) = *(s32*)(a0 + 0x7C);
                }
                i = n;
            } while (i < 4);
        } else if (m == 4) {
            a0[4] = 0xD;
        }
    }
}
