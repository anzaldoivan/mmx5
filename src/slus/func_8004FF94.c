#include "types.h"

extern u8* func_8002D0E4(void);
extern u16 D_800D1C0C;

u8* func_8004FF94(s32 arg0, s16 x, s16 y, u8 arg3) {
    u8* p;

    p = func_8002D0E4();
    if (p != 0) {
        p[0] = 0x21;
        p[1] = 4;
        p[2] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[0x5C] = arg3;
        *(s16*)(p + 0xA) = x;
        *(s16*)(p + 0x8) = 0;
        *(s16*)(p + 0xE) = y;
        *(s16*)(p + 0xC) = 0;
        p[0x15] = 0;
        p[0x14] = 0;
        if (D_800D1C0C == 6) {
            p[0x16] = 0x11;
        } else {
            p[0x16] = 1;
        }
    }
    return p;
}
