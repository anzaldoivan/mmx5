#include "types.h"

extern s8 D_8009A424;
extern u8 D_8009A0A0[];
extern u8 D_800D1C00[];
extern u8 D_8007337C[];
extern u8 D_80073364[];
extern u8 D_80073384[];
extern u8 D_80073370[];
extern s8 D_800E9528;

extern void func_800272B4(void);
extern void func_800183B4(void);
extern void func_80013288(s32);

void func_8003322C(u8* a0) {
    u8* g = D_8009A0A0;
    u8 *d1, *d2, *d3, *d4, *d5, *d6;
    u8 *e1, *e2, *e3;
    u8* q;
    u8 *f2, *f3, *f4;
    s32 y;
    u8* flags;
    s32 i;
    s32 n;
    u32 k;
    s32 x;
    u8 c;

    if (D_8009A424 != 0) {
        func_800272B4();
        return;
    }
    func_800183B4();
    func_80013288(8);
    a0[5] = 2;
    a0[0x14] = 0;
    if (((s8*)g)[2] == 0) {
        a0[0x16] = 1;
        flags = a0 + 0x16;
        for (i = 1; i < 9; i++) {
            if (g[0xC9] & D_8007337C[D_80073364[i]]) {
                flags[i] = 1;
            } else {
                flags[i] = 0;
            }
        }
        if ((u8)(g[0xFA] - 2) < 3) {
            a0[0x1F] = 1;
        } else {
            a0[0x1F] = 0;
        }
    } else {
        d1 = D_800D1C00;
        if (d1[0x1BA] != 0) {
            a0[0x16] = 1;
        } else {
            a0[0x16] = 2;
        }
        flags = a0 + 0x16;
        for (i = 1; i < 9; i++) {
            y = D_80073364[i];
            y = D_80073384[y];
            if (g[0xC9] & D_8007337C[y]) {
                flags[i] = 1;
            } else {
                flags[i] = 0;
            }
        }
        a0[0x1F] = 0;
    }
    d2 = D_800D1C00;
    a0[0x20] = 0;
    a0[0x21] = 0;
    if (*(u16*)(d2 + 0x7E) & 0x3000) {
        if (*(u16*)(d2 + 0x7E) & 0x1000) {
            a0[0x20] = 1;
            d2[0x76] |= 0x80;
        }
        if (*(u16*)(d2 + 0x7E) & 0x2000) {
            a0[0x21] = 1;
            d2[0x77] |= 0x80;
        }
    }
    d3 = D_800D1C00;
    if (*(u16*)(d3 + 0x7E) & 0x4000) {
        a0[0x22] = 1;
    } else {
        a0[0x22] = 0;
    }
    d4 = D_800D1C00;
    c = d4[0xC];
    if ((u8)(c - 1) < 8) {
        if ((d4[0x4C] >> ((s8)c - 1)) & 1) {
            a0[0x23] = 1;
        } else {
            a0[0x23] = 0;
        }
    }
    a0[0x24] = 1;
    a0[0x25] = 1;
    a0[0x26] = 1;
    d5 = D_800D1C00;
    a0[2] = 0;
    if ((((s8*)d5)[0xC] == 5 && ((s8*)d5)[0x1D] == 0) ||
        (e1 = D_8009A0A0, ((s8*)e1)[0xD5] < 0)) {
        a0[2] = 1;
    }
    if (((s8*)a0)[2] != 0) {
        f2 = a0 + 0x16;
        for (k = 10; k < 17; k++) {
            if (f2[k]) {
                a0[0x14] = k;
                break;
            }
        }
    } else if (e2 = D_8009A0A0, ((s8*)e2)[2] == 0) {
        for (i = 0; i < 8; i++) {
            if (((s8*)g)[0x93] == D_80073370[i]) {
                break;
            }
        }
        a0[0x14] = i;
    } else {
        x = (s8)g[0x93];
        if (x != 0) {
            if (x == 1) {
                a0[0x14] = 5;
            } else if (x == 2) {
                a0[0x14] = 6;
            } else {
                a0[0x14] = 3;
            }
        } else {
            f3 = a0 + 0x16;
            for (k = 0; k < 17; k++) {
                if (f3[k]) {
                    a0[0x14] = k;
                    break;
                }
            }
        }
    }
    f4 = a0 + 0x16;
    d6 = D_800D1C00;
    if (*(u16*)(d6 + 0x7E) & 0x8000) {
        a0[0x27] = 1;
    } else {
        a0[0x27] = 0;
    }
    a0[0x28] = 0;
    a0[0x29] = 0;
    a0[0x2A] = 0;
    a0[0x2B] = 0;
    n = 0;
    i = 0;
    q = f4 + 0x12;
    for (; i < 16; i++) {
        if (*(u32*)(g + 0xFC) & (4 << i)) {
            *q = i + 1;
            q++;
            n++;
        }
        if (n >= 4) {
            break;
        }
    }
    a0[0x2C] = ((D1C00_8003322C*)D_800D1C00)->unkAA[((s8*)g)[2]];
    e3 = D_8009A0A0;
    D_800E9528 = e3[0x93];
    *(s32*)(a0 + 0x30) = 0;
    *(s32*)(a0 + 0x34) = 0;
    *(s32*)(a0 + 0x38) = 0;
}
