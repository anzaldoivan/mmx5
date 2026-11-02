/* Shared body (DK-5), from the banked draft of func_800EFFCC_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern s32 DEDUP_CALLEE(void);
extern s8 D_800D1C44;
extern u8 D_800F52C4_ovl05[];

void DEDUP_NAME(u8* arg0) {
    if (!(DEDUP_CALLEE() & 1)) {
        if (D_800D1C44 == 0) {
            if (D_1F80004C.scr84->unk84 != 0) {
                arg0[5] = 6;
            } else {
                arg0[5] = 8;
            }
        } else if (D_1F80004C.scr84->unk84 == 0) {
            arg0[5] = 8;
        } else {
            arg0[5] = 7;
        }
    } else if (D_1F80004C.scr84->unk84 == 0) {
        arg0[5] = 4;
    } else {
        *(void**)(arg0 + 0x54) = D_800F52C4_ovl05;
        arg0[5] = 3;
    }
    arg0[6] = 0;
}
