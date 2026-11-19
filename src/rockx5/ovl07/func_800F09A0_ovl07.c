#include "types.h"

u8 func_800F09A0_ovl07(u8* p) {
    u8 v = p[0x81];

    if ((u32)(v - 1) < 8) {
        if (v < 5) {
            return 0;
        }
        if (v < 9) {
            return 1;
        }
    }
    if (v == 0x10) {
        return p[0x83];
    }
    return 2;
}
