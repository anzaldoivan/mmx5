/* Shared body (DK-5), from the banked draft of func_800F0470_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800F1F94_ovl12[][6];

void DEDUP_NAME(Obj0470* obj) {
    if (++obj->unk7C == 100) {
        set_animation(obj, 9);
    }
    if (obj->unk46 == 0) {
        set_animation(obj, 1);
        obj->unk5 = D_800F1F94_ovl12[obj->unk86][obj->unk87++];
        obj->unk6 = 0;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
