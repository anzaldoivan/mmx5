#include "types.h"

void func_80031C38(u8* arg0, u8* arg1, u16* arg2, u16* arg3) {
    u8 r;
    s16 x;
    s16 y;
    u8* p;
    u8 h;

    *arg2 = *(u16*)(arg1 + 0xA);
    *arg3 = *(u16*)(arg1 + 0xE);
    if (*(s8*)(arg1 + 1) == 0x3A) {
        if (arg1[0x15] != 0) {
            *arg2 -= *(s8*)*(u8**)(arg1 + 0x68);
            return;
        }
        *arg2 += *(s8*)*(u8**)(arg1 + 0x68);
        return;
    }
    if (arg0[0x15] != 0) {
        x = *(u16*)(arg0 + 0xA) - **(s8**)(arg0 + 0x68);
    } else {
        x = *(u16*)(arg0 + 0xA) + **(s8**)(arg0 + 0x68);
    }
    p = *(u8**)(arg0 + 0x68);
    y = *(u16*)(arg0 + 0xE) + ((s8*)p)[1];
    if (arg1[0x15] != 0) {
        r = p[3];
        if (y < y - r) {
            *arg3 = y - p[3];
            return;
        }
    } else {
        r = p[3];
        if (y < y - r) {
            *arg3 = y - p[3];
            return;
        }
    }
    if (y + r < y) {
        *arg3 = p[3] + y;
        return;
    }
    h = p[2];
    if (x < x - h) {
        *arg2 = x - p[2];
        return;
    }
    if (x + h < x) {
        *arg2 = p[2] + x;
    }
}
