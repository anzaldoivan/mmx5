/* Shared body (DK-5), from the banked draft of func_800F5F2C_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern s16 D_800FB61E_ovl09;
extern u8 D_800FAD58_ovl09[][6];

void DEDUP_NAME(Ent5F2C* e) {
    if (e->unkE <= D_800FB61E_ovl09) {
        e->unkE = D_800FB61E_ovl09;
        e->unk24 = 0;
        e->unk5 = D_800FAD58_ovl09[e->unk96][e->unk97++];
        e->unk6 = 0;
    }
    animate_object(e);
    apply_object_motion(e);
}
