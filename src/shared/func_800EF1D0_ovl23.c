#include "types.h"

extern s8 D_800D1C44;

void func_800EF1D0_ovl23(u8* arg0) {
    s8 v = D_800D1C44;

    if (v == 1) {
        arg0[3] = v;
    } else {
        arg0[3] = 0;
    }
}
