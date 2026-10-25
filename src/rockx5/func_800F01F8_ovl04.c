#include "types.h"

extern u8 D_800D1C00[];
extern u8 D_8009A1F8[];

void func_800F01F8_ovl04(u8* obj) {
    u8* g = D_800D1C00;
    u8* b;

    if (g[0x26] & 4) {
        obj[6]++;
        b = D_8009A1F8;
        ((s8*)b)[0xA6] = -1;
        *(s16*)(b + 0x5E) = 0;
        *(s16*)(b + 0x62) = 0;
        b[0xA0] = 1;
        g[0x26] |= 8;
    }
}
