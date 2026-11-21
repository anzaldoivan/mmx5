#include "types.h"
#include "mmx5/globals.h"

extern s32 func_8002A600(s32, s32, s32);
extern u8 D_8009A1F8[];

void func_800EEDEC_ovl01(u8* arg0) {
    u8* g;
    u8* s;
    u8* g0;
    u8* s0;
    u8* p;

    s0 = D_8009A1F8;
    if (*(s16*)(s0 + 0x5E) == 0x100) {
        g0 = g_Player;
        if (g0[0xF7] == 0) {
            arg0[0x18]++;
            if (arg0[0x18] & 1) {
                p = func_8002D27C();
                if (p != 0) {
                    p[0] = 0x41;
                    p[1] = 8;
                    p[2] = arg0[0x18] & 2;
                }
            }
        }
    }
    g = g_Player;
    if (*(s16*)(g + 0xA) >= 0x1CF0) {
        ((s32(*)())func_8003D29C)(0x14, 0x40);
        arg0[5]++;
    }
    if (g[0xF7] == 0) {
        s = D_8009A1F8;
        if (*(s16*)(s + 0x2A) == *(s16*)(s + 0x28)) {
            if (--arg0[0x1C] == 0) {
                func_8002A600(0x30, 2, 1);
                arg0[0x1C] = 0xA0;
            }
        } else {
            *(s16*)(s + 0x34) = 0;
        }
    }
}

extern u16 D_80093E68;
extern u8 D_8009A1F8[];
extern u16 D_8009A42E;
extern u8 D_800C9310;
extern u16 D_800D50DE;

void func_800EEF28_ovl01(u8* arg0) {
    u8* s;
    u8* g;
    u8* q;
    s32 t;

    s = D_8009A1F8;
    if (*(s16*)(s + 0xA) < 0x1D31) {
        *(s32*)(s + 8) += *(s32*)(arg0 + 0x14);
        *(u16*)(s + 0x26) = *(u16*)(s + 0xA);
        *(u16*)(s + 0x1E) = *(u16*)(s + 0xA);
        g = g_Player;
        *(s32*)(g + 8) += *(s32*)(arg0 + 0x14);
    }
    q = arg0 + 0x14;
    t = arg0[0x1A] - 1;
    q[6] = t;
    if ((t & 0xFF) == 0) {
        t = arg0[0x19] - 1;
        q[5] = t;
        if ((t & 3) == 0) {
            D_800C9310 |= 1;
            arg0[0x19] = 4;
            D_800D50DE = 0;
            D_8009A42E = 0;
            D_80093E68 = 0;
            arg0[0x1A] = 2;
            arg0[0x1B]++;
        } else {
            D_800D50DE = 0x1F;
            D_8009A42E = 0x3E0;
            D_80093E68 = 0x7C00;
            arg0[0x1A] = 1;
        }
        if (arg0[0x1B] >= 3) {
            arg0[0x19] = 0;
            arg0[5]++;
        }
    }
}

extern u16 D_80093E68;
extern u8 D_8009A1F8[];
extern u16 D_8009A42E;
extern u16 D_800D50DE;
extern s32 D_800E92F8;

void func_800EF054_ovl01(u8* arg0) {
    u8* s;
    u8* g;
    s32 t;

    s = D_8009A1F8;
    if (*(s16*)(s + 0xA) < 0x1D31) {
        *(s32*)(s + 8) += *(s32*)(arg0 + 0x14);
        *(u16*)(s + 0x26) = *(u16*)(s + 0xA);
        *(u16*)(s + 0x1E) = *(u16*)(s + 0xA);
        g = g_Player;
        *(s32*)(g + 8) += *(s32*)(arg0 + 0x14);
    }
    arg0[0x19]++;
    if ((u8)(arg0[0x19] % 5) == 0) {
        t = D_800D50DE + 2;
        D_800D50DE = t;
        D_8009A42E += 0x40;
        D_80093E68 += 0x800;
        if ((u16)t >= 0x1F) {
            D_800E92F8 = 1;
            arg0[0x19] = 0x14;
            arg0[5]++;
            *(u16*)(s + 0x26) = 0x2000;
            *(u16*)(s + 0x1E) = 0x2000;
            s[0x4C] = 1;
        }
    }
}
