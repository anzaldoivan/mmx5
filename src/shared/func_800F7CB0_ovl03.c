/* Shared body (DK-5), from the banked draft of func_800F7CB0_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl03.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void DEDUP_NAME(Ent7CB0* e) {
    if (++e->unk7C == 6) {
        u8 t;
        t = D_800FA0BC_ovl03[e->unk92][e->unk93++];
        e->unk6 = 0;
        e->unk5 = t;
    }
    animate_object(e);
    apply_object_motion(e);
}
