/* Shared body (DK-5), from the banked draft of func_800EF7C0_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(ObjEF7C0* obj) {
    if (obj->unk7C == 0) {
        set_animation(obj, 5);
        obj->unk20 = (obj->unk15 & 0x40) ? 0x40000 : -0x40000;
        obj->unk6 = 1;
    } else {
        obj->unk7C--;
    }
    animate_object(obj);
}
