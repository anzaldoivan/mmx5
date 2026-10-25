/* Shared body (DK-5), from the banked draft of func_800F09F4_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

void DEDUP_NAME(Ent09F4* e) {
    if (D_1F80004C.scr09f4->unk90 == 0) {
        e->unk54 = 0;
        e->unk68 = 0;
        e->unk15 = D_1F80004C.scr09f4->unk80->unk15;
        e->unkA = D_1F80004C.scr09f4->unk80->unkA;
        e->unkE = D_1F80004C.scr09f4->unk80->unkE;
        e->unk6++;
    }
}
