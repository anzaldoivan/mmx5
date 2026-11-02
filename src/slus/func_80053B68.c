#include "types.h"

extern void func_80016490(s32, s32, void*);
extern u8 D_8009A0A0[];
extern u8 D_800D1C00[];

void func_80053B68(s32 arg0, u8 arg1) {
    u8* base;
    u8* r;
    s16* p;
    u32 i;
    u16 n;
    s32 lvl;

    if (arg1 == 5) {
        u8* q;

        n = 4;
        lvl = 1;
        q = D_8009A0A0;
        if (*(s32*)(q + 0xFC) & 0x40) {
            n = 6;
            lvl = 2;
        }
    } else if (arg1 == 6) {
        u8* q;

        n = 0x10;
        lvl = 2;
        q = D_8009A0A0;
        if (*(s32*)(q + 0xFC) & 0x40) {
            n = 0x16;
            lvl = 3;
        }
    } else {
        lvl = 0;
        if (arg1 == 7) {
            u8* q;

            q = D_8009A0A0;
            n = *(u16*)(q + 0x148);
            lvl = 4;
        } else {
            n = 0;
        }
    }
    n = n * 6;
    base = D_8009A0A0;
    if (*(s8*)(base + 2) == 0) {
        p = (s16*)(base + 0xA8);
        for (i = 1; i < 9; i++) {
            if (*(s8*)(base + 0x93) == i) {
                if (p[i] < *(s16*)(base + 0x148)) {
                    p[i] = p[i] + n;
                    if (p[i] >= *(s16*)(base + 0x148)) {
                        func_80016490(0, 0x16, 0);
                    }
                }
            } else {
                p[i] = p[i] + (n >> 1);
            }
            if (p[i] > *(s16*)(base + 0x148)) {
                p[i] = *(s16*)(base + 0x148);
            }
        }
    } else {
        if (*(s8*)(base + 0x93) == 1) {
            *(u16*)(base + 0xAA) = n + *(u16*)(base + 0xAA);
        } else {
            *(u16*)(base + 0xAA) = *(u16*)(base + 0xAA) + (n >> 1);
        }
        if (*(s16*)(base + 0xAA) >= *(s16*)(base + 0x148)) {
            if (*(s8*)(base + 0x93) == 1) {
                func_80016490(0, 0x16, 0);
            }
            *(u16*)(base + 0xAA) = *(u16*)(base + 0x148);
        }
        if (*(s8*)(base + 0x93) == 3) {
            *(u16*)(base + 0xAE) = n + *(u16*)(base + 0xAE);
        } else {
            *(u16*)(base + 0xAE) = *(u16*)(base + 0xAE) + (n >> 1);
        }
        if (*(s16*)(base + 0xAE) >= *(s16*)(base + 0x148)) {
            if (*(s8*)(base + 0x93) == 3) {
                func_80016490(0, 0x16, 0);
            }
            *(u16*)(base + 0xAE) = *(u16*)(base + 0x148);
        }
    }
    r = D_800D1C00;
    if (*(u16*)(r + 0x7E) & 0x4000) {
        r[0x78] = r[0x78] + lvl * 2;
        if (*(s8*)(r + 0x78) > 0x20) {
            r[0x78] = 0x20;
        }
    }
}
