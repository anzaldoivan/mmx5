#include "types.h"

extern s8 D_8009A0A5;
extern u8 D_8009A1F8[];
extern s8 D_800D1C1D;

void func_800F0090_ovl04(u8* a0) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        p = D_8009A1F8;
        if (*(s16*)(p + 0xA) == 0x12C0) {
            *(s16*)(p + 0x5E) = 0x370;
            *(s16*)(p + 0x62) = 0;
            p[0xA0] = 1;
            D_800D1C1D = 5;
            a0[6] = 0;
            a0[5]++;
        }
    }
}
