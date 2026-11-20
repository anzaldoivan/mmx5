#include "types.h"
#include "mmx5/system.h"

extern u8* find_free_visual_obj(void);

static inline u16 func_80050650_rnd16(void) {
    s32 hi;
    s32 lo;

    hi = random_byte();
    lo = random_byte();
    hi <<= 8;
    hi += lo;
    hi++;
    return hi;
}

void func_80050650(u8 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s32 mid;
    s16 i;
    s32 d;
    s32 dx;
    s32 dy;
    s32 w;
    s32 hi;
    s32 lo;
    u16 rx;
    u16 ry;
    u8* p;

    d = arg3 - arg1;
    mid = (s16)(arg1 + d / 2);
    for (i = 0; i < arg5; i++) {
        dx = d << 16;
        dy = (arg4 - arg2) << 16;
        p = find_free_visual_obj();
        if (p != 0) {
            p[0] = 0x21;
            p[1] = 9;
            p[2] = 0;
            rx = func_80050650_rnd16();
            hi = random_byte();
            lo = random_byte();
            w = dx >> 16;
            ry = (hi << 8) + lo + 1;
            if (w == 0) {
                *(s16*)(p + 0xA) = arg1;
            } else {
                *(s16*)(p + 0xA) = arg1 + rx % w;
            }
            if ((dy >> 16) == 0) {
                *(s16*)(p + 0xE) = arg2;
            } else {
                *(s16*)(p + 0xE) = arg2 + ry % (dy >> 16);
            }
            *(s16*)(p + 0x8) = 0;
            *(s16*)(p + 0xC) = 0;
            switch (arg0 & 3) {
            case 2:
                if (*(s16*)(p + 0xA) < mid) {
                    *(s32*)(p + 0x20) = 0xFFFE8000;
                    *(s32*)(p + 0x24) = 0;
                } else {
                    *(s32*)(p + 0x20) = 0x18000;
                    *(s32*)(p + 0x24) = 0;
                }
                break;
            case 1:
                *(s32*)(p + 0x20) = 0;
                *(s32*)(p + 0x24) = 0x10000;
                break;
            case 3:
                *(s32*)(p + 0x20) = 0;
                *(s32*)(p + 0x24) = 0x4000;
                break;
            default:
                *(s32*)(p + 0x20) = 0;
                *(s32*)(p + 0x24) = 0;
                break;
            }
            p[0x15] = 0;
            p[0x5C] = arg0 >> 4;
            p[4] = 0;
            p[5] = 0;
            p[6] = 0;
        }
    }
}
