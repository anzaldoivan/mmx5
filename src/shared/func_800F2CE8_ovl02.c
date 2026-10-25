/* Shared body (DK-5), from the banked draft of func_800F2CE8_ovl02 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(Ent2CE8* arg0) {
    Ent2CE8* parent = arg0->unk7C;

    arg0->unk60 = 4;
    arg0->unk50 = parent->unk50;
    arg0->unk15 = parent->unk15;
    arg0->unkA = parent->unkA;
    arg0->unkE = parent->unkE;
    arg0->unk3 = 0;
    arg0->unk4++;
}
