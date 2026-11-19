#include "types.h"

extern const s16 D_80102FD4_ovl04;
extern s8 D_800D1C1D;
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_800F03F4_ovl04(u8* p) {
    u16 t;
    u16 r;
    u16 g;
    u16 b;

    p[3] = 1;
    *(u16*)(p + 0x16) = 0;
    t = D_80102FD4_ovl04;
    *(u16*)(p + 0x1E) = 0x140;
    *(u16*)(p + 0x26) = 0x140;
    *(u16*)(p + 0x2E) = 0;
    *(u16*)(p + 0x1A) = t;
    *(u16*)(p + 0x22) = t;
    *(u16*)(p + 0x2A) = t + 0xF0;
    *(u16*)(p + 0x32) = t + 0xF0;
    if (D_800D1C1D >= 6) {
        r = D_800D50DE + 0x11;
        g = D_8009A42E + 0x2A0;
        b = D_80093E68 + 0x6000;
        if (r > 0x1F) {
            r = 0x1F;
        }
        if (g > 0x3E0) {
            g = 0x3E0;
        }
        if (b > 0x7C00) {
            b = 0x7C00;
        }
        *(u16*)(p + 0x34) = b | (r | g);
    }
}
