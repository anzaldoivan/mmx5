#include "types.h"

extern u8* func_8002D0E4(void);
extern s32 func_8002DF78(void);
extern u8 D_800FDC70_ovl01;

void func_800F7024_ovl01(s16 x, s16 y, s16 x2, s16 y2, s16 n) {
    s16 i;
    s16 dx;
    s16 dy;
    u16 rx;
    u16 ry;
    u8* p;
    u8 c;
    s32 hi;
    s32 lo;

    for (i = 0; i < n; i++) {
        p = func_8002D0E4();
        if (p != 0) {
            p[0] = 0x21;
            p[1] = 4;
            p[2] = 0;
            rx = (func_8002DF78() << 8) + func_8002DF78() + 1;
            hi = func_8002DF78();
            lo = func_8002DF78();
            dx = x2 - x;
            ry = (hi << 8) + lo + 1;
            if (dx == 0) {
                *(s16*)(p + 0xA) = x;
            } else {
                *(s16*)(p + 0xA) = x + rx % dx;
            }
            dy = y2 - y;
            if (dy == 0) {
                *(s16*)(p + 0xE) = y;
            } else {
                *(s16*)(p + 0xE) = y + ry % dy;
            }
            *(s16*)(p + 0x8) = 0;
            *(s16*)(p + 0xC) = 0;
            p[4] = 0;
            p[5] = 0;
            p[6] = 0;
            p[0x15] = 0;
            p[0x14] = 0;
            p[0x16] = 1;
            c = ++D_800FDC70_ovl01;
            if (c & 1) {
                p[0x5C] = 0;
            } else {
                p[0x5C] = 1;
            }
        }
    }
}
