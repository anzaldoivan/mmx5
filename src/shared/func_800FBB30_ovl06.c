/* Shared body (DK-5), from the banked draft of func_800FBB30_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(Obj0658* arg0) {
    arg0->unk28 = 0;
    if (arg0->unk15 == 0) {
        arg0->unk20 = 0xFFFE0000;
    } else {
        arg0->unk20 = 0x20000;
    }
    arg0->unk24 = 0x20000;
    arg0->unk2C = 0x1000;
    arg0->unk6++;
}
