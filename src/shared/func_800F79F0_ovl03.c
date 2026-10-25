/* Shared body (DK-5), from the banked draft of func_800F79F0_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800FA0BC_ovl03[][6];

void DEDUP_NAME(Ent79F0* e) {
    if (e->unk91 == 0) {
        u8 t;
        t = D_800FA0BC_ovl03[e->unk92][e->unk93];
        e->unk6 = 0;
        e->unk93++;
        e->unk5 = t;
    } else {
        e->unk91--;
    }
}
