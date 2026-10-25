/* Shared body (DK-5), from the banked draft of func_800EF6DC_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Ent6DC*);
extern u8 D_80074EE0[];
extern u8 D_800F8FC0_ovl29[];
extern u8 D_800F8FC4_ovl29[];

void DEDUP_NAME(Ent6DC* arg0) {
    switch (arg0->unk45) {
    case 2:
        break;
    case 1:
        arg0->unk60 = 4;
        arg0->unk20 = 0;
        arg0->unk7C = 0xF;
        arg0->unk5 = 5;
        arg0->unk6 = 0;
        break;
    case 3:
        arg0->unk54 = D_800F8FC4_ovl29;
        arg0->unk50 = D_800F8FC0_ovl29;
        break;
    case 4:
        arg0->unk58 = D_80074EE0;
        break;
    }
    DEDUP_CALLEE(arg0);
}
