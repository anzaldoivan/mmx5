#include "types.h"

extern u8 D_8009A0A0[];
extern s16 D_8009A202;
extern u8 D_800D1C00[];

void func_800F0260_ovl04(void) {
    u8* p = D_8009A0A0;
    s16 d = *(s16*)(p + 0xA) - D_8009A202;
    u8 x;
    u8* q;

    if (d >= 0x138) {
        *(s16*)(p + 0xA) = D_8009A202 + 0x138;
    }
    if (d < -0x10) {
        q = D_800D1C00;
        x = p[0x5C];
        *(s8*)(p + 0x5C) = -0x80;
        *(s32*)(q + 0xB8) += x & 0x7F;
    }
}
