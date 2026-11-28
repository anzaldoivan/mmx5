#include "types.h"

s32 func_8003A134(u8* p, u8 c) {
    s32 r;

    switch (c) {
    case 0x2D:
        r = 0;
        break;
    case 0x25 ... 0x28:
        if (p[0x15] == 0) {
            r = 2;
        } else {
            r = 1;
        }
        break;
    default:
        if (p[0x15] == 0) {
            r = 1;
        } else {
            r = 2;
        }
        break;
    }
    return r;
}
