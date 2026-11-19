/* Shared body (DK-5), from the banked draft of func_800F5C0C_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Obj5C0C* e) {
    set_animation(e, 3);
    if (D_8009A0AA > e->unkA) {
        e->unk15 = 0x40;
    } else {
        e->unk15 = 0;
    }
    e->unk20 = 0;
    e->unk24 = 0;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk7C = 0;
    e->unk6++;
    func_8002D9EC(e, 0x40, 0x40);
    animate_object(e);
    apply_object_motion(e);
}
