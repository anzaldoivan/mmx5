/* Shared body (DK-5), from the banked draft of func_800F01DC_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Obj01DC*);
extern u8 D_800F52CC_ovl05[];

void DEDUP_NAME(Obj01DC* arg0) {
    if (arg0->unk45 == 2) {
        arg0->unk24 = 0xE0000;
        arg0->unk68 = D_800F52CC_ovl05;
    }
    DEDUP_CALLEE(arg0);
    if (arg0->unk45 == 1) {
        arg0->unk68 = D_800F52CC_ovl05;
        arg0->unk24 = 0;
        arg0->unk2C = 0;
        arg0->unk20 = 0;
        arg0->unk28 = 0;
        arg0->unk67 = 0;
        arg0->unk5 = 2;
        arg0->unk6 = 0;
    }
}
