/* Shared body (DK-5), from the banked draft of func_800F0E24_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj3DD4*, s32);

void DEDUP_NAME(Obj3DD4* arg0) {
    DEDUP_CALLEE(arg0, 0xC);
    arg0->unk20 = -0x30000;
    arg0->unk24 = 0;
    arg0->unk7C = 0x28;
    arg0->unk6++;
}
