/* Shared body (DK-5), from the banked draft of func_800F320C_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern s32 func_800317B8(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002D6FC(u8* obj);
extern signed char D_800D1CA2;
extern void (*D_800FBE2C_ovl10[])(u8*);
extern u8 D_8009A11A;
extern u8 D_80074EE0[];
extern u8 D_80076060[];

void DEDUP_NAME(u8* a0) {
    s32 r;
    s32 t;
    s8 lim;
    u8 c;

    if (((s8*)a0)[5] != 7) {
        lim = D_800D1CA2 / 3;
        if (((s8*)a0)[0x5C] < lim) {
            if (a0[0x8A] == 1) {
                a0[0x8E] = 1;
            }
            a0[0x8A] = 2;
        } else if (((s8*)a0)[0x5C] < lim * 2) {
            if (a0[0x8A] == 0) {
                a0[0x8E] = 1;
            }
            a0[0x8A] = 1;
        } else {
            if (*(u16*)(a0 + 0x92) != 0) {
                *(u16*)(a0 + 0x92) -= 1;
            }
            a0[0x8A] = 0;
        }
    }
    D_800FBE2C_ovl10[((s8*)a0)[5]](a0);
    if (((s8*)a0)[2] == 0 && a0[0x8C] == 0) {
        return;
    }
    r = func_80031DD0(a0);
    c = a0[0x84];
    if (((s8*)a0)[0x84] == 0) {
        if (r < 0) {
            if (((s8*)a0)[2] != 0) {
                a0[5] = 6;
                a0[6] = 0;
            } else {
                D_8009A11A = 1;
                a0[4] = 2;
                a0[5] = 0;
                return;
            }
        } else if (r != 0 && r != 0x7F) {
            *(u8**)(a0 + 0x58) = D_80074EE0;
            *(u16*)(a0 + 0x42) |= 0x8000;
            if ((u32)(r - 0x19) < 2) {
                a0[0x84] = 2;
            } else {
                a0[0x84] = 0x1E;
            }
            if (r == 5 || r == 0xE || r == 0x24) {
                a0[0x60] = 6;
                a0[5] = 2;
                a0[6] = 0;
            }
        }
    } else {
        t = c - 1;
        a0[0x84] = t;
        if ((t << 24) == 0) {
            *(u8**)(a0 + 0x58) = D_80076060;
            *(u16*)(a0 + 0x42) &= 0x7FFF;
        } else if (((s8*)a0)[5] != 2) {
            if (!(t & 1)) {
                *(u16*)(a0 + 0x42) |= 0x8000;
            } else {
                *(u16*)(a0 + 0x42) &= 0x7FFF;
            }
        }
    }
    if (((s8*)a0)[5] != 1) {
        func_800317B8(a0);
    }
    func_8002D9EC(a0, 0x60, 0x60);
    if (((s8*)a0)[2] != 0) {
        u8* p;
        if (((s8*)*(u8**)(a0 + 0x80))[5] == 2) {
            if (((s8*)a0)[5] != 6 || ((s8*)a0)[6] >= 3) {
                a0[5] = 6;
                a0[6] = 0;
            }
        }
        p = *(u8**)(a0 + 0x80);
        if (((s8*)p)[4] == 2) {
            *(s32*)(p + 0x94) = 0;
            a0[4] = 2;
            a0[5] = 0;
        }
        if (a0[0x86] != 0 && ((s8*)a0)[5] == 6) {
            *(s32*)(*(u8**)(a0 + 0x80) + 0x94) = 0;
            func_8002D6FC(a0);
        }
    } else if (a0[0x8F] != 0) {
        if (!(a0[0x8F] & 1)) {
            *(u16*)(a0 + 0x42) &= 0x7FFF;
        } else {
            *(u16*)(a0 + 0x42) |= 0x8000;
        }
        a0[0x8F]--;
    }
}
