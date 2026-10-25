/* Shared body (DK-5), from the banked draft of func_800EFCD8_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 D_8009A0A8;

void DEDUP_NAME(Ent800EFCD8* e) {
    s32 x = e->x;

    if (D_8009A0A8 < x) {
        e->unk15 = 0;
    } else {
        e->unk15 = 0x40;
    }
}
