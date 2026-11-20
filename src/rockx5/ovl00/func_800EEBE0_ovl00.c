#include "types.h"

extern u8 D_8009A1F8[];
extern s8 D_800D1C1D;

void func_800EEBE0_ovl00(u8* arg0) {
    if (D_800D1C1D == 1) {
        D_8009A1F8[0x58] = 2;
        *(s16*)(D_8009A1F8 + 0x96) = 0;
        *(s16*)(D_8009A1F8 + 0x94) = 0;
        arg0[6] = 0;
        arg0[5]++;
    }
}
