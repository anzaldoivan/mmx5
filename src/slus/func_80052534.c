/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004CA08.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern u16 D_8007BACC[];
extern u16 D_8007BAE0[][8];
extern u16 D_8007BB80[][8];
extern u16 D_8007BC50;
void func_80052BDC(u8*, u8, u8, u16*);

#define B(o) (*(s8*)(p + (o)))
#define UB(o) (*(u8*)(p + (o)))
#define H(o) (*(u16*)(p + (o)))

void func_80052534(u8* p) {
    u8* q;
    u32 i;
    s32 c;
    u16 d;
    u16 x;
    u16* t;

    switch (B(5)) {
    case 0:
        B(5) = 1;
        H(0xA) = 0;
        H(0x16) = D_8007BACC[B(7)];
        H(0x2E) = D_8007BACC[B(7)];
        H(0x1E) = D_8007BACC[B(7)] + 0x3F;
        H(0x26) = D_8007BACC[B(7)] + 0x3F;
        H(0xE) = 0;
        if (B(7) < 5) {
            H(0x1A) = 0;
            H(0x22) = 0;
            H(0x2A) = 0;
            H(0x32) = 0;
        } else {
            H(0x1A) = 0xF0;
            H(0x22) = 0xF0;
            H(0x2A) = 0xF0;
            H(0x32) = 0xF0;
        }
        B(0x55) = 1;
        B(0x54) = 1;
        B(0x4C) = 0;
        B(0x4D) = 0;
        B(0x4E) = 0;
        B(0x4F) = 0;
        H(0x50) = 8;
        break;
    case 1:
        i = 0;
        q = p + 0x38;
        for (; i < 4; i++) {
            func_80052BDC(p, UB(7), i, &D_8007BAE0[B(7)][i * 2]);
        }
        c = H(0x50) - 1;
        *(u16*)(q + 0x18) = c;
        if (!(c & 0xFFFF)) {
            t = D_8007BAE0[B(7)];
            H(0x16) = *t++;
            H(0x1A) = *t++;
            H(0x1E) = *t++;
            H(0x22) = *t++;
            H(0x26) = *t++;
            H(0x2A) = *t++;
            H(0x2E) = *t++;
            H(0x32) = *t++;
            B(5) = 2;
            B(0x55) = 1;
            B(0x54) = 1;
            B(0x4C) = 0;
            B(0x4D) = 0;
            B(0x4E) = 0;
            B(0x4F) = 0;
            H(0x50) = 8;
        }
        break;
    case 2:
        i = 0;
        q = p + 0x38;
        for (; i < 4; i++) {
            func_80052BDC(p, UB(7), i, &D_8007BB80[B(7)][i * 2]);
        }
        c = H(0x50) - 1;
        *(u16*)(q + 0x18) = c;
        if (!(c & 0xFFFF)) {
            t = D_8007BB80[B(7)];
            H(0x16) = *t++;
            H(0x1A) = *t++;
            H(0x1E) = *t++;
            H(0x22) = *t++;
            H(0x26) = *t++;
            H(0x2A) = *t++;
            H(0x2E) = *t++;
            x = *t;
            B(5) = 3;
            B(0x55) = 1;
            B(0x54) = 1;
            B(0x4C) = 0;
            B(0x4D) = 0;
            B(0x4E) = 0;
            B(0x4F) = 0;
            d = D_8007BC50;
            H(0x50) = 0x10;
            H(0x32) = x;
            if (d != 0) {
                D_8007BC50 = d - 1;
            }
        }
        break;
    case 3:
        *(u8*)(*(u8**)(p + 0x58) + 0x14) = 0;
        B(4) = 2;
        B(5) = 0;
        break;
    }
}

#undef B
#undef UB
#undef H
