#include "types.h"
#include "mmx5/globals.h"

extern s8 D_800D1C1D;
extern u8 D_8009A1F8[];
extern u16 D_800F9618_ovl26[];

void func_800F1F10_ovl26(u8* arg0) {
    u8* d;

    if (D_800D1C1D != 0) {
        arg0[4] = 3;
        return;
    }
    d = D_8009A1F8;
    d[0x98] = 1;
    d[0xEC] = 1;
    *(u16*)(d + 0x2E) = D_800F9618_ovl26[*(signed char*)(arg0 + 2)];
    arg0[4]++;
}

extern u8 D_8009A1F8[];
extern s16 D_800F961C_ovl26[];

void func_800F1F78_ovl26(u8* arg0) {
    u8* a = g_Player;
    u8* b = D_8009A1F8;

    *(s16*)(b + 0xE) = *(u16*)(a + 0xE) - 0x1E;
    if (*(s16*)(b + 0xE) >= D_800F961C_ovl26[(s8)arg0[2]]) {
        *(s16*)(b + 0xE) = D_800F961C_ovl26[(s8)arg0[2]];
    }
    if (*(s16*)(b + 0xE) <= 0) {
        *(s16*)(b + 0xE) = 0;
    }
    if (*(s8*)(a + 5) != 0) {
        if ((s8)arg0[2] == 1) {
            arg0[4] = 3;
            return;
        }
        arg0[4]++;
    }
}

extern s16 D_8009A226;
extern s8 D_800D1C1D;

void func_800F2020_ovl26(u8* arg0) {
    if (D_800D1C1D != 0) {
        arg0[4]++;
        D_8009A226 = 0xC0;
    }
}
