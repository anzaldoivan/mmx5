#include "types.h"
#include "mmx5/ovl28.h"
#include "mmx5/globals.h"

extern s8 D_800D1C1D;

void func_800EF010_ovl28(u8* arg0) {
    if (D_800D1C1D >= 2) {
        arg0[5] = 1;
    } else {
        arg0[5] = 0;
    }
    arg0[6] = 0;
    *(s16*)(arg0 + 0x14) = 0;
    *(s16*)(arg0 + 0x18) = 0;
    arg0[4]++;
    func_800EF064_ovl28(arg0);
}

#include "shared/func_800EF064_ovl28.c"

#define D_800EEBA0_ovl00 func_800EF0C4_ovl28
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00

#define func_800EEF2C_ovl18 func_800EF0E4_ovl28
#include "shared/func_800EEF2C_ovl18.c"
#undef func_800EEF2C_ovl18

extern void func_8002C1C8(void);
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s32 D_80093DD0[];

void func_800EF110_ovl28(u8* arg) {
    s32 i;

    D_800D50DC = 1;
    D_8009A42C = 1;
    D_80093E66 = 1;
    func_8002C1C8();
    for (i = 8; i < 12; i++) {
        s32 bit = i + 0x40;
        s32 q = bit / 32;
        s32 sh = 31 - (bit - q * 32);
        s32 m = 1 << sh;
        D_80093DD0[q] |= m;
    }
    arg[6]++;
    *(s16*)(arg + 0x16) = 0;
}

#define func_800EF008_ovl26 func_800EF1B8_ovl28
#include "shared/func_800EF008_ovl26.c"
#undef func_800EF008_ovl26
