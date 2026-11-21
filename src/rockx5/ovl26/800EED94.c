#include "types.h"
#include "mmx5/globals.h"

extern s8 D_800D1C00[];
extern u8 D_800F8BB0_ovl26[];
extern void func_800EEE34_ovl26(u8*);

void func_800EED94_ovl26(u8* a0) {
    if (D_800D1C00[0x1D] >= 3) {
        *(s16*)(a0 + 0x1A) = 1;
        a0[5] = 1;
    } else {
        a0[5] = 0;
    }
    if (D_800D1C00[0x1D] == 2) {
        *(s16*)(a0 + 0x1A) = 1;
        func_80028B18(0, 0x3C0, 0x11A0, D_800F8BB0_ovl26);
    }
    a0[6] = 0;
    *(s16*)(a0 + 0x14) = 0;
    *(s16*)(a0 + 0x18) = 0;
    a0[4]++;
    func_800EEE34_ovl26(a0);
}

extern s16 D_8009A206;
extern u8 D_800F8BB0_ovl26[];
extern void* D_800F8C44_ovl26[];

void func_800EEE34_ovl26(u8* a0) {
    u8* g = g_Player;

    if (g[0xF7] == 0) {
        ((void (*)(u8*))D_800F8C44_ovl26[((s8*)a0)[5]])(a0);
        *(u16*)(a0 + 0x14) += 1;
    }
    if (*(s16*)(a0 + 0x1A) == 0 && (u16)(*(u16*)(g + 0xA) - 0x3C0) < 0x140 &&
        (u16)(*(u16*)(g + 0xE) - 0x11E0) < 0xB0 && D_8009A206 >= 0x11B0) {
        ((s32(*)())func_80028B18)(0, 0x3C0, 0x11A0, D_800F8BB0_ovl26);
        *(s16*)(a0 + 0x1A) = 1;
    }
}

#define D_800EEBA0_ovl00 func_800EEF14_ovl26
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00

#define func_800EEF2C_ovl18 func_800EEF34_ovl26
#include "shared/func_800EEF2C_ovl18.c"
#undef func_800EEF2C_ovl18

extern void func_8002C1C8(void);
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s32 D_80093DD0[];

void func_800EEF60_ovl26(u8* arg) {
    s32 i;

    D_800D50DC = 1;
    D_8009A42C = 1;
    D_80093E66 = 1;
    func_8002C1C8();
    for (i = 5; i < 11; i++) {
        s32 bit = i + 0x40;
        s32 q = bit / 32;
        s32 sh = 31 - (bit - q * 32);
        s32 m = 1 << sh;
        D_80093DD0[q] |= m;
    }
    arg[6]++;
    *(s16*)(arg + 0x16) = 0;
}

#include "shared/func_800EF008_ovl26.c"
