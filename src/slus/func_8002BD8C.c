#include "types.h"
#include "addr.h"

extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;
extern u8 D_800C9310;
extern u16 D_8009A74C;
extern u8 D_8009A197;
extern u16 D_800CD588;
extern u16 D_800A51A6;
extern u16 D_8009A790[];
extern u16 D_800A11A0[];
extern signed char D_800D1C0C;
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s32 D_80093DD0[];

void func_8002BD8C(void) {
    u16 r0 = D_800D50DE;
    u16 g0 = D_8009A42E;
    u16 b0 = D_80093E68;
    u16* src;
    u16* dst;
    u32 n;
    u32 i;
    u32 j;
    s32 mask;
    u16 c;
    u32 r;
    u32 g;
    u32 b;
    u32 t;

    if ((r0 | g0 | b0) == 0 && !(D_800C9310 & 4)) {
        return;
    }
    if (D_8009A74C == r0 && D_800CD588 == g0 && D_800A51A6 == b0 &&
        D_800C9310 == 0) {
        return;
    }
    if (D_8009A197) {
        src = D_8009A790;
    } else {
        src = (u16*)D_1F800028;
    }
    dst = D_800A11A0;
    n = 0x140;
    if (D_800D1C0C == 11) {
        n = 0x200;
    }
    for (i = 0; i < n; i++) {
        if ((i & 0x1F) == 0) {
            mask = D_80093DD0[i >> 5];
        }
        if (mask < 0) {
            for (j = 0; j < 16; j++) {
                c = *src++;
                if (c != 0) {
                    if (D_800D50DC) {
                        t = c & 0x1F;
                        r = (t < D_800D50DE) ? 0 : t - D_800D50DE;
                    } else {
                        r = (c & 0x1F) + D_800D50DE;
                        if (r >= 0x20) {
                            r = 0x1F;
                        }
                    }
                    if (D_8009A42C) {
                        t = c & 0x3E0;
                        g = (t < D_8009A42E) ? 0 : t - D_8009A42E;
                    } else {
                        g = (c & 0x3E0) + D_8009A42E;
                        if (g >= 0x3E1) {
                            g = 0x3E0;
                        }
                    }
                    if (D_80093E66) {
                        t = c & 0x7C00;
                        b = (t < D_80093E68) ? 0 : t - D_80093E68;
                    } else {
                        b = (c & 0x7C00) + D_80093E68;
                        if (b >= 0x7C01) {
                            b = 0x7C00;
                        }
                    }
                    *dst++ = r | g | b | (c & 0x8000);
                } else {
                    dst++;
                }
            }
        } else {
            for (j = 0; j < 16; j++) {
                *dst++ = *src++;
            }
        }
        mask <<= 1;
    }
    D_800C9310 = 8;
    D_8009A74C = D_800D50DE;
    D_800CD588 = D_8009A42E;
    D_800A51A6 = D_80093E68;
}
