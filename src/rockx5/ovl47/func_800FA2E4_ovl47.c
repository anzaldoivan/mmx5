#include "types.h"

extern u8 D_8009A1F8[];
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DD0[];
extern u16 D_80093E68;
extern u16 D_8009A42E;
extern u16 D_800D50DE;

void func_800FA2E4_ovl47(u8* arg0) {
    u8* p = D_8009A1F8;

    *(s32*)(p + 0x5C) += 0x14CCCC;
    if (++*(s16*)(arg0 + 4) >= 10) {
        *(s32*)(p + 0x5C) = 0x1D00000;
        D_80093E66 = 1;
        D_8009A42C = 1;
        D_800D50DC = 1;
        D_80093DD0[2] = -1;
        D_80093DD0[3] = 0xFFFF0000;
        D_80093E68 = 0;
        D_8009A42E = 0;
        D_800D50DE = 0;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
