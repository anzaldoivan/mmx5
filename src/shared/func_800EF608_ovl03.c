/* Shared body (DK-5), from the banked draft of func_800EF608_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 DEDUP_CALLEE(ObjEF608*, s32);
extern u8 D_800F959C_ovl03[];

void DEDUP_NAME(ObjEF608* arg0) {
    DEDUP_CALLEE(arg0, 1);
    arg0->unk80 = 5;
    arg0->unk20 = 0;
    arg0->unk54 = D_800F959C_ovl03;
    arg0->unk50 = D_800F959C_ovl03;
    arg0->unk6++;
}
