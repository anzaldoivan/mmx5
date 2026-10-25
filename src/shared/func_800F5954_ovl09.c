/* Shared body (DK-5), from the banked draft of func_800F5954_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800FAD58_ovl09[][6];

void DEDUP_NAME(Ent5954* e) {
    if (e->unk95 == 0) {
        e->unk5 = D_800FAD58_ovl09[e->unk96][e->unk97];
        e->unk6 = 0;
        e->unk97++;
    } else {
        e->unk95--;
    }
}
