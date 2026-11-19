#include "types.h"

extern void (*D_80102F30_ovl04[])(u8*);

void func_80100068_ovl04(u8* p) {
    if (p[0x1B] != 0) {
        D_80102F30_ovl04[p[0x1A]](p);
    } else {
        p[0x18]--;
        if (p[0x18] == 0) {
            p[0x1B] = 1;
        }
    }
}
