#include "types.h"
#include "mmx5/globals.h"

extern s8 D_800D1C1D;
extern s32 D_800E92F8;

void func_800F15E0_ovl07(u8* arg0) {
    arg0[4]++;
    if (D_800D1C1D == 0) {
        arg0[5] = 0;
        return;
    }
    D_800E92F8 = 1;
    if (D_800D1C1D != 4) {
        D_8009A1F8.u[0xAC] = 1;
        *(s16*)(D_8009A1F8.u + 0xE8) = 0xC80;
        *(s16*)(D_8009A1F8.u + 0xEA) = 0xF0;
        D_8009A1F8.u[0xF4] = 1;
    } else {
        D_8009A1F8.u[0xAC] = 0xB;
        *(s16*)(D_8009A1F8.u + 0xE8) = 0;
        *(s16*)(D_8009A1F8.u + 0xEA) = -0x238;
        D_8009A1F8.u[0xF4] = 1;
    }
    arg0[4]++;
}

void func_800F1670_ovl07(u8* arg0) {
    u8* p = D_8009A1F8.u;

    if (*(s16*)(p + 0xA) == 0x1E00) {
        *(s16*)(p + 0xB2) = 0x1E00;
        *(s16*)(p + 0xB6) = 0;
        p[0xAC] = 1;
        *(s16*)(p + 0xE8) = 0xC80;
        *(s16*)(p + 0xEA) = 0xF0;
        p[0xF4] = 1;
        arg0[4]++;
    }
}

void func_800F16C4_ovl07(u8* arg0) {
    u8* p = g_Player;
    s16 y;

    if (*(u16*)(p + 0xA) >= 0x20C0 && *(u16*)(p + 0xA) <= 0x21C0) {
        y = *(s16*)(p + 0xE);
        if (y >= 0x4D0) {
            if (y < 0x511) {
                D_8009A1F8.u[0xAC] = 0xB;
                *(s16*)(D_8009A1F8.u + 0xE8) = 0;
                *(s16*)(D_8009A1F8.u + 0xEA) = -0x238;
                D_8009A1F8.u[0xF4] = 1;
                arg0[4]++;
            }
        }
    }
}

#define D_800EEBA0_ovl00 func_800F1738_ovl07
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
