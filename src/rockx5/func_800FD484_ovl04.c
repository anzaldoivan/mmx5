#include "types.h"

extern u8* func_8002C938();
extern u8* D_80103094_ovl04[];
extern u8 D_8010309C_ovl04[];

void func_800FD484_ovl04(void) {
    s32 i;
    u8* p;
    s32 v;

    for (i = 0; i < 2; i++) {
        if (D_80103094_ovl04[i]) {
            if (((s8*)D_80103094_ovl04[i])[4] < 2) {
                continue;
            }
            D_80103094_ovl04[i] = 0;
            v = 0x3C;
        } else {
            v = D_8010309C_ovl04[i];
            if (v == 0) {
                p = func_8002C938();
                if (p) {
                    p[1] = 0x13;
                    p[2] = (i & 1) + 2;
                    p[0] = 0x41;
                    D_80103094_ovl04[i] = p;
                }
                continue;
            }
            v--;
        }
        D_8010309C_ovl04[i] = v;
    }
}
