/* Shared body (DK-5), from the banked draft of func_800F0990_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 D_8009A0A8;

void DEDUP_NAME(Ent800EFCD8* e) {
    s32 d = D_8009A0A8;

    if (e->x >= d) {
        e->unk15 = 0;
    } else {
        e->unk15 = 0x40;
    }
}
