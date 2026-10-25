/* Shared body (DK-5), from the banked draft of func_800EFF4C_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(ObjEFF4C*, s32);
extern u8 D_800F52C4_ovl05[];
extern u8 D_800F52C8_ovl05[];

void DEDUP_NAME(ObjEFF4C* arg0) {
    if (D_1F80004C.scr84->unk84 == 0) {
        arg0->unk54 = D_800F52C4_ovl05;
        DEDUP_CALLEE(arg0, 1);
        arg0->unk7C = 0x3C;
    } else {
        arg0->unk54 = D_800F52C8_ovl05;
        DEDUP_CALLEE(arg0, 0);
        arg0->unk7C = 0x28;
    }
    arg0->unk6++;
}
