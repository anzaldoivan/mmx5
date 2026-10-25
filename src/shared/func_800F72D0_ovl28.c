/* Shared body (DK-5), from the banked draft of func_800F72D0_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(Obj800F72D0* arg0, Obj800F72D0* arg1) {
    s8 temp_v0;
    s32 temp;

    temp_v0 = arg1->unk9A;
    if (temp_v0 != 0) {
        if (temp_v0 > 0) {
            arg0->unk3 = 1;
            arg0->unk54 = 3;
            arg0->unk56 = 8;
            arg0->unk58 = (5 - arg0->unk2) * 2;
            arg0->unk8 = arg1->unk8;
            temp = arg1->unkC;
            arg0->unk4 = 1;
            arg0->unk5 = 0;
            arg0->unkC = temp;
            return;
        }
        arg1->unk9A = 0;
    }
}
