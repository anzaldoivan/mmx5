/* Shared body (DK-5), from the banked draft of func_800F6234_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FAD58_ovl09[][6];

void DEDUP_NAME(Ent6234* e) {
    if (++e->unk7C == 0xF0) {
        u8 t;
        set_animation(e, 0);
        t = D_800FAD58_ovl09[e->unk96][e->unk97++];
        e->unk6 = 0;
        e->unk5 = t;
    }
    animate_object(e);
    apply_object_motion(e);
}
