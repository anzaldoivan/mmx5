/* Shared body (DK-5), from the banked draft of func_800EF604_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(ObjEF604* obj) {
    if (obj->unk45 != 0) {
        obj->unk28 = 0;
        obj->unk15 ^= 0x40;
        set_animation(obj, 1);
        obj->unk5 = 2;
        obj->unk20 = 0;
        obj->unk6 = 0;
        obj->unk7C = 0x14;
    }
    animate_object(obj);
}
