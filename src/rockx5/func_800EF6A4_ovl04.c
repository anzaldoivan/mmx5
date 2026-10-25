#include "types.h"

extern u8 D_800D1C00[];
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern void func_8002C1C8(void);
extern void func_800EF76C_ovl04(u8* arg0);
extern s32 func_8002DF78(void);

void func_800EF6A4_ovl04(u8* arg0) {
    u8* gm = D_800D1C00;
    u8 t;

    if (((s8*)gm)[0x1D] >= 6) {
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C1C8();
        t = 2;
        arg0[4] = t;
    } else {
        arg0[4]++;
        t = gm[0x1D];
        arg0[5] = t;
        arg0[6] = 0;
        arg0[7] = 0;
        func_800EF76C_ovl04(arg0);
    }
    arg0[0x1D] = func_8002DF78() % 121 + 120;
}
