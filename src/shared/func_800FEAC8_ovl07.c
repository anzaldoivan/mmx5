/* Shared body (DK-5), from the banked draft of func_800FEAC8_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 DEDUP_CALLEE(EntFEAC8*);

void DEDUP_NAME(EntFEAC8* a0) {
    a0->unk3 = 0;
    if ((s8)a0->unk7 == 0) {
        a0->unk15 = a0->unk7C->unk15;
        a0->unk7++;
    }
    if ((s8)a0->unk7C->unk6 == 6 || (s8)a0->unk7C->unk5 != 9) {
        a0->unk4 = 2;
    } else {
        DEDUP_CALLEE(a0);
    }
}
