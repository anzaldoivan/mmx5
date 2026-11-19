/* Shared body (DK-5), from the banked draft of func_800EF2F8_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Obj3C4* obj) {
    obj->unk5 = 3;
    obj->timer = 0x30;
    set_animation(obj, 6);
    if (obj->x < D_8009A0AA) {
        obj->flags15 = 0x40;
    } else {
        obj->flags15 = 0;
    }
    if ((u32)(random_byte() & 0xF) < 10) {
        obj->state6 = 0;
    } else {
        obj->state6 = 1;
    }
}
