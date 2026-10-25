/* Shared body (DK-5), from the banked draft of func_800F0930_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

void DEDUP_NAME(Self780* self) {
    Scr780* scr = D_1F80004C.scr780;

    if (scr->unk90 == 0) {
        self->unkA = scr->unk80->unkA + scr->unk80->unk8A;
        self->unkE = D_1F80004C.scr780->unk80->unkE;
        /* 0x91 lies past Pl780's proven fields */
        if (((u8*)D_1F80004C.scr780->unk80)[0x91] != 0) {
            self->unk6 = 5;
        }
    }
}
