#include "types.h"

extern s32 D_8009A19C;

s32 func_80045E2C(void) {
    s32 r;

    r = 0x7802;
    if (D_8009A19C & 0x300) {
        r = 0x7844;
    }
    return r;
}
