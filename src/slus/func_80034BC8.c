#include "types.h"

extern s8 D_8009A424;
void func_800272DC(void);

void func_80034BC8(u8* a0) {
    s8 v;

    if (D_8009A424 == 0) {
        v = ((s8*)a0)[0x14];
        a0[4] = 1;
        a0[5] = 0;
        if (v >= 13) {
            a0[5] = 2;
        } else if (v >= 10) {
            a0[5] = 1;
        }
    }
    func_800272DC();
}
