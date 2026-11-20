#include "types.h"

extern u8 D_8009A1F8[];
extern s8 D_8009A0FC;

void func_800F2500_ovl06(u8* o) {
    s16 t;

    if (o[0x97] & 0x40) {
        u8* p = D_8009A1F8 + *(s8*)(o + 0x14) * 84;
        t = *(u16*)(p + 0x1C) + 0x140;
        if (*(s16*)(o + 0xA) + 0x20 >= t) {
            *(s16*)(o + 0xA) = t - 0x20;
        }
        {
            u8* q = D_8009A1F8 + *(s8*)(o + 0x14) * 84;
            t = *(s16*)(q + 0x1E);
            if (*(s16*)(o + 0xA) - 0x20 < t) {
                *(s16*)(o + 0xA) = t + 0x20;
            }
        }
    }
    {
        u8* r = D_8009A1F8 + *(s8*)(o + 0x14) * 84;
        t = *(u16*)(r + 0x20) + 0xF0;
        if (*(s16*)(o + 0xE) - 0x20 >= t) {
            o[4] = 2;
            if (o[0x97] & 0x40) {
                D_8009A0FC = -0x80;
            }
        }
    }
}
