#include "types.h"
#include "addr.h"

extern s32 func_80028FF0(s32 a, s32 x, s32 y);

s32 func_80030BB4(u8* obj, s16 px, s16 py) {
    s32 x = px >> 8;
    s32 y = py >> 8;
    s32 sx = (px & 0xF0) >> 4;
    s32 sy = (py & 0xF0) >> 4;
    s32 ret;
    s32 v;

    ret = func_80028FF0(*(s8*)(obj + 0x14), x, y);
    if (ret == 0 || y < 0) {
        v = 0;
    } else if (x < 0) {
        v = 0;
    } else {
        *(s16*)(obj + 0x6C) = px & 0xF;
        *(s16*)(obj + 0x6E) = py & 0xF;
        v = D_1F80000C[(*(u16*)(D_1F800008 + ret * 512 + sy * 32 + sx * 2) &
                        0x3FFF) *
                       4];
    }
    if (v == 0x3B) {
        v = 0x38;
    }
    return v;
}
