/* Shared body (DK-5), from the banked draft of func_800F428C_ovl24 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_CALLEE(u8* arg0, s16 arg1, s16 arg2, u8 arg3);
extern s32 D_800D1CB4;
extern s16 D_800F596C_ovl24[];

void DEDUP_NAME(u8* arg0) {
    s32 ones;
    s32 hundreds;
    s32 tens;
    s16* p;

    if (D_800D1CB4 >= 999) {
        p = D_800F596C_ovl24;
        DEDUP_CALLEE(arg0, p[0], p[1], 0x89);
        DEDUP_CALLEE(arg0, p[2], p[3], 0x89);
        DEDUP_CALLEE(arg0, p[4], p[5], 0x89);
    } else if (D_800D1CB4 == 0) {
        DEDUP_CALLEE(arg0, D_800F596C_ovl24[4], D_800F596C_ovl24[5], 0x80);
    } else {
        ones = D_800D1CB4 % 10;
        hundreds = D_800D1CB4 / 100;
        tens = D_800D1CB4 - hundreds * 100;
        if (tens != 0) {
            tens = tens / 10;
        }
        if (hundreds != 0) {
            DEDUP_CALLEE(arg0, D_800F596C_ovl24[0], D_800F596C_ovl24[1],
                         hundreds - 0x80);
        }
        if (tens != 0 || hundreds != 0) {
            DEDUP_CALLEE(arg0, D_800F596C_ovl24[2], D_800F596C_ovl24[3],
                         tens - 0x80);
        }
        DEDUP_CALLEE(arg0, D_800F596C_ovl24[4], D_800F596C_ovl24[5],
                     ones - 0x80);
    }
    arg0[4] = 2;
}
