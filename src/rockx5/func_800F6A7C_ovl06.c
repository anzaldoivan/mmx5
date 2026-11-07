#include "types.h"

extern u8 D_8009A0A0[];
extern s16 D_800FEAD4_ovl06[];

s32 func_800F6A7C_ovl06(void) {
    u8* p = D_8009A0A0;
    s32 i;
    s16 x;
    s16 y;
    s16* q;
    s16* r;

    if (*(s8*)(p + 0xD5) < 0) {
        return 0;
    }
    y = *(s16*)(p + 0xE);
    x = *(s16*)(p + 0xA);
    if (y < 0x170) {
        return 0;
    }
    i = 0;
    q = D_800FEAD4_ovl06;
    r = D_800FEAD4_ovl06 + 2;
    for (; i < 6; q += 4, i++, r += 4) {
        s16 x0 = q[0];
        s16 y0 = q[1];
        s16 x1 = *r;
        s16 y1 = q[3];
        if (x >= x0 && x1 >= x) {
            if (i < 4) {
                if (y >= y0 && y1 >= y) {
                    return 1;
                }
            } else if (y >= (s16)(y0 + (x - x0) * (y1 - y0) / (x1 - x0))) {
                return 1;
            }
        }
    }
    return 0;
}
