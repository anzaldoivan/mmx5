/* Shared body (DK-5), from the banked draft of func_800F078C_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Obj078C* obj) {
    animate_object(obj);
    if (--obj->unk7C == 0) {
        set_animation(obj, 1);
        if (obj->unk80 == 0) {
            if (obj->unk15) {
                obj->unk20 = 0x18000;
            } else {
                obj->unk20 = -0x18000;
            }
            obj->unk5 = 2;
        } else {
            obj->unk88 = 0;
            obj->unk89 = 0x14;
            obj->unk5 = 6;
        }
        obj->unk6 = 0;
    }
}
