#include "types.h"

extern s32 func_8002DF78(void);
extern s16 D_8009A0AA;

void func_800F244C_ovl03(u8* p) {
    s32 n;
    s32 x;
    s32 y;
    s32 d;

    n = (func_8002DF78() & 7) << 4;
    y = D_8009A0AA;
    x = *(s16*)(p + 0xA);
    d = y - x;
    if ((d >= 0) ? (d <= n) : (x - y <= n)) {
        *(s32*)(p + 0x2C) = 0x1000;
        p[6]++;
    }
}
