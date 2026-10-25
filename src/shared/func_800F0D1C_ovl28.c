/* Shared body (DK-5), from the banked draft of func_800F0D1C_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_8009A0AA;

void DEDUP_NAME(Ent800F0D1C* e) {
    if (D_8009A0AA - e->y >= 0xB0) {
        e->unk15 = 0x40;
        e->unk4 = 1;
        e->unk5 = 3;
    }
}
