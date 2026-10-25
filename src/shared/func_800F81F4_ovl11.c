/* Shared body (DK-5), from the banked draft of func_800F81F4_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_8009A0AA;

void DEDUP_NAME(Obj800F81F4* arg0) {
    if (arg0->unkA > D_8009A0AA) {
        arg0->unk15 = 0;
        arg0->unk20 = -1;
    } else {
        arg0->unk15 = 0x40;
        arg0->unk20 = 1;
    }
}
