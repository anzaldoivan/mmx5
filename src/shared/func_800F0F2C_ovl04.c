/* Shared body (DK-5), from the banked draft of func_800F0F2C_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(Obj800F0F2C* arg0) {
    if (--arg0->unk7C == -1) {
        arg0->unk15 = 0x40;
        arg0->unk7C = 3;
        arg0->unk6++;
    }
}
