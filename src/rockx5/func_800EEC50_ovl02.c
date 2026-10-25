#include "types.h"

extern void func_8002C1C8(void);
extern u8* func_8002D53C(void);
extern u8 D_800D1C00[];
extern s32 D_80093DD0[];
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;

void func_800EEC50_ovl02(u8* arg) {
    s32 i;
    u8* p;

    *(s16*)(arg + 0x14) = -100;
    arg[4]++;
    D_800D1C00[0x26] = 0;
    D_800D1C00[0x27] = 0;
    *(s8*)(arg + 0x16) = -1;
    func_8002C1C8();
    D_80093E66 = 1;
    D_8009A42C = 1;
    D_800D50DC = 1;
    for (i = 2; i < 10; i++) {
        D_80093DD0[i] = -1;
    }
    D_80093DD0[1] = -0xF01;
    p = func_8002D53C();
    if (p != 0) {
        p[0] = 0x51;
        p[1] = 0xD;
    }
}
