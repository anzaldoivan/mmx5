#include "types.h"

s32 func_8002E274(u8* a, u8* b) {
    u8* h1;
    u8* h2;
    s32 sum;
    s32 w1;
    s32 w2;
    s32 x1;
    s32 x2;
    s32 d;

    if (*(s8*)(b + 0x61) != 0) {
        return 0;
    }
    h1 = *(u8**)(a + 0x50);
    if (h1 == 0) {
        return 0;
    }
    h2 = *(u8**)(b + 0x54);
    if (h2 == 0) {
        return 0;
    }
    sum = (u16)(h1[2] + h2[2]);
    w1 = h1[2];
    w2 = h2[2];
    if (a[0x15] & 0x40) {
        x1 = *(s16*)(a + 0xA) - *(s8*)(h1 + 0);
    } else {
        x1 = *(s16*)(a + 0xA) + *(s8*)(h1 + 0);
    }
    if (b[0x15] & 0x40) {
        x2 = *(s16*)(b + 0xA) - *(s8*)(h2 + 0);
    } else {
        x2 = *(s16*)(b + 0xA) + *(s8*)(h2 + 0);
    }
    d = x2 - x1;
    if (d < 0) {
        d = x1 - x2;
    }
    if (x2 < x1) {
        if (a[0x15] & 0x40) {
            if (b[0x15] & 0x40) {
                if (d >= w1) {
                    return 0;
                }
            } else {
                if (d >= sum) {
                    return 0;
                }
            }
        } else {
            if (b[0x15] & 0x40) {
                return 0;
            }
            if (d >= w2) {
                return 0;
            }
        }
    } else {
        if (a[0x15] & 0x40) {
            if (!(b[0x15] & 0x40)) {
                return 0;
            }
            if (d >= w2) {
                return 0;
            }
        } else {
            if (b[0x15] & 0x40) {
                if (d >= sum) {
                    return 0;
                }
            } else {
                if (d >= w1) {
                    return 0;
                }
            }
        }
    }
    x1 = *(s16*)(a + 0xE) + *(s8*)(h1 + 1);
    x2 = *(s16*)(b + 0xE) + *(s8*)(h2 + 1);
    d = x2 - x1;
    if (d < 0) {
        d = x1 - x2;
    }
    if (x2 < x1) {
        if (d >= h2[3]) {
            return 0;
        }
    } else {
        if (d >= h1[3]) {
            return 0;
        }
    }
    return 1;
}
