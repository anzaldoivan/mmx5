/* Shared body (DK-5), from the banked draft of func_800F0328_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_8009A0AA;

void DEDUP_NAME(Obj0328* e) {
    if (((D_8009A0AA - e->unkA) >= 0 ? (D_8009A0AA - e->unkA)
                                     : (e->unkA - D_8009A0AA)) > 0x90) {
        e->unk5 = 5;
        e->unk6 = 0;
        return;
    }
    e->unk24 = 0;
    e->unk2C = 0x2000;
    e->unk6++;
}
