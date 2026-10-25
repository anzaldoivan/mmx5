/* Shared body (DK-5), from the banked draft of func_800EFBC4_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(Obj800EFBC4* arg0) {
    arg0->unk6 = 1;
    if (arg0->unk15 == 0) {
        arg0->unk20 = -0x8000;
    } else {
        arg0->unk20 = 0x8000;
    }
    arg0->unk28 = 0;
    arg0->unk24 = 0;
    arg0->unk2C = 0;
    arg0->unk7C = 0x30;
}
