#include "types.h"

extern s8 D_8009A424;
extern u8 D_8009A1F8[];

void func_800FA200_ovl46(u8* arg0) {
    u8* p;

    if (D_8009A424 == 0) {
        p = D_8009A1F8;
        p[0x3] = 0;
        p[0x57] = 0;
        p[0xAB] = 1;
        *(s32*)(p + 0xB0) = 0;
        *(s32*)(p + 0xB4) = 0;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
