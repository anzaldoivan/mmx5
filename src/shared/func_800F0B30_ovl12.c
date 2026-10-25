/* Shared body (DK-5), from the banked draft of func_800F0B30_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj800EFBC4*, s32);

void DEDUP_NAME(Obj800EFBC4* arg0) {
    if (++arg0->unk7C == 20) {
        DEDUP_CALLEE(arg0, 10);
        if (arg0->unk15 != 0) {
            arg0->unk20 = -0x80000;
        } else {
            arg0->unk20 = 0x80000;
        }
        arg0->unk24 = 0x20000;
        arg0->unk2C = 0x1999;
        arg0->unk6++;
    }
}
