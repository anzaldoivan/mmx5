#include "types.h"

extern u8 D_80091C44;
extern u8 D_8009A1F8[];

void func_800FB630_ovl49(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8;
        *(s32*)(p + 0x8) = 0x02000000;
        *(s32*)(p + 0xC) = 0x04080000;
        p[0x3] = 1;
        p[0x4C] = 1;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
