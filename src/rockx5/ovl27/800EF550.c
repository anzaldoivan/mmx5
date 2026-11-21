#include "types.h"
#include "mmx5/globals.h"

#define D_800FD264_ovl28 D_800FC550_ovl27

#define func_800EF064_ovl28 func_800EF550_ovl27
#include "shared/func_800EF064_ovl28.c"
#undef func_800EF064_ovl28
#undef D_800FD264_ovl28

#define D_800EEBA0_ovl00 func_800EF5B0_ovl27
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00

#define func_800EEF2C_ovl18 func_800EF5D0_ovl27
#include "shared/func_800EEF2C_ovl18.c"
#undef func_800EEF2C_ovl18

extern void func_8002C1C8(void);
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s32 D_80093DD0[];

void func_800EF5FC_ovl27(u8* arg) {
    s32 i;

    D_800D50DC = 1;
    D_8009A42C = 1;
    D_80093E66 = 1;
    func_8002C1C8();
    for (i = 7; i < 13; i++) {
        s32 bit = i + 0x40;
        s32 q = bit / 32;
        s32 sh = 31 - (bit - q * 32);
        s32 m = 1 << sh;
        D_80093DD0[q] |= m;
    }
    arg[6]++;
    *(s16*)(arg + 0x16) = 0;
}

#define func_800EF008_ovl26 func_800EF6A4_ovl27
#include "shared/func_800EF008_ovl26.c"
#undef func_800EF008_ovl26
