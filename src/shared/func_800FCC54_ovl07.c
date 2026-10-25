/* Shared body (DK-5), from the banked draft of func_800FCC54_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern signed char D_800D1C0C;
extern s32 D_80093DD0[];
extern s32 D_80093DD8;

void DEDUP_NAME(void) {
    if (D_800D1C0C == 12) {
        D_80093DD8 = 0x9000C000;
        return;
    }
    D_80093DD0[0] = 0xF0;
    D_80093DD0[2] = 0x40FF;
    D_80093DD0[1] = 0;
    D_80093DD0[3] = 0xA0004000;
    D_80093DD0[4] = 0x40000000;
}
