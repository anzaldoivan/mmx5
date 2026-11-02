#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern s32 func_8001D7E8(u8);
extern s32 func_8002C50C(void);
extern u8* func_8002D27C(void);
extern void func_800F19F0_ovl24();
extern u8 D_8009A420[];
extern u8 D_8009A427;
extern u16 D_800C931C[];
extern u8 D_800E81D8[];
extern u8* D_800F5F84_ovl24;

static inline s32 func_800F1414_ovl24_poll(u8* arg0) {
    s32 t;

    t = func_8001D7E8(D_800E81D8[6]);
    if (t != 0) {
        s32 one = 1;
        s32 two = 2;
        if (t == one) {
            arg0[1] = 0xA;
            D_800E81D8[8] = one;
        } else {
            arg0[1] = 0xA;
            D_800E81D8[8] = two;
        }
        arg0[3] = one;
        do {
            D_8009A427 = 0;
        } while (0); // !FAKE: do-while(0) for the register choice
        return 1;
    }
    return 0;
}

void func_800F1414_ovl24(u8* arg0) {
    u8 old;
    u8 i;
    u8* p;
    s32 w;
    u8* q;
    u8* q2;
    u8* r;
    u8* b;
    s32 n;

    if (func_800F1414_ovl24_poll(arg0) != 0) {
        return;
    }
    b = D_8009A420;
    old = b[7];
    if (D_800C931C[2] & 0x1000) {
        if (old == 0) {
            for (i = 0; i < 7; i++) {
                r = D_800E81D8;
                *(s32*)(r + 0xC) += 0x158;
            }
            D_8009A420[7] = 7;
            n = i;
        } else {
            q = D_800E81D8;
            w = *(s32*)(q + 0xC);
            n = old - 1;
            b[7] = n;
            w -= 0x158;
            *(s32*)(q + 0xC) = w;
        }
        func_800F19F0_ovl24(n);
    }
    if (D_800C931C[2] & 0x4000) {
        n = D_8009A420[7];
        if (n == 7) {
            for (i = 0; i < 7; i++) {
                r = D_800E81D8;
                *(s32*)(r + 0xC) -= 0x158;
            }
            D_8009A420[7] = 0;
            n = i;
        } else {
            q2 = D_800E81D8;
            w = *(s32*)(q2 + 0xC);
            n++;
            D_8009A420[7] = n;
            w += 0x158;
            *(s32*)(q2 + 0xC) = w;
        }
        func_800F19F0_ovl24(n);
    }
    if (D_8009A420[7] != old) {
        func_80016490(0, 0xC, 0);
    }
    if (D_800C931C[2] & 0x10) {
        func_80016490(0, 0x22, 0);
        func_8002C50C();
        arg0[0] = 0xE;
        arg0[1] = 3;
        arg0[2] = 0;
        arg0[3] = 0;
        return;
    }
    if (D_800C931C[2] & 0x40) {
        func_80016490(0, 0x22, 0);
        D_800E81D8[7] = D_8009A420[7];
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x3E;
            p[2] = 0x11;
        }
        D_800F5F84_ovl24 = p;
        D_800E81D8[0xA] = 3;
        *(s16*)(arg0 + 0xA) = 1;
        arg0[3] = 9;
        arg0[1]++;
        func_800F19F0_ovl24();
    }
}
