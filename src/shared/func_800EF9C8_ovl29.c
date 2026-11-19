/* Shared body (DK-5), from the banked draft of func_800EF9C8_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800750C0[];

void DEDUP_NAME(ObjEF9C8* obj) {
    animate_object(obj);
    if (obj->unk70 & 8) {
        if (obj->unk80 != 0) {
            obj->unk58 = D_800750C0;
            obj->unk60 = 3;
            obj->unk5 = 7;
        } else {
            set_animation(obj, 1);
            obj->unk5 = 2;
        }
        obj->unk6 = 0;
        obj->unk24 = 0;
        obj->unk2C = 0;
        obj->unk20 = 0;
        obj->unk28 = 0;
        obj->unk67 = 0;
        return;
    }
    apply_object_motion(obj);
}
