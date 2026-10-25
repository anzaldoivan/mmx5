#include "types.h"

extern u8 D_80091C44;
extern u8* D_800FBEF0_ovl56;
extern u8 D_8009A1F8[];

void func_800FB9D8_ovl56(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8;
        D_800FBEF0_ovl56[4] = 2;
        *(s16*)(p + 0xE) = 0x100;
        p[3] = 1;
        *(s16*)(p + 0xA) = 0x200;
        p[0x4C] = 1;
        p[0x57] = 1;
        *(s16*)(p + 0x5E) = 0x200;
        *(s16*)(p + 0x62) = 0xF8;
        p[0xA0] = 1;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
