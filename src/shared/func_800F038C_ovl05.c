/* Shared body (DK-5), from the banked draft of func_800F038C_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_800F52C8_ovl05[];

void DEDUP_NAME(Obj038C* obj) {
    apply_object_motion(obj);
    if (obj->flags70 & 8) {
        obj->unk54 = D_800F52C8_ovl05;
        set_animation(obj, 14);
        D_1F80004C.bytes[0x84] = 1;
        obj->unk24 = 0;
        obj->unk2C = 0;
        obj->unk20 = 0;
        obj->unk28 = 0;
        obj->state++;
    }
}
