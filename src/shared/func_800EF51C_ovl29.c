/* Shared body (DK-5), from the banked draft of func_800EF51C_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Obj800EF51C* obj) {
    if (obj->unk88 == 0) {
        if (--obj->unk8C == 0) {
            set_animation(obj, 2);
            obj->unk5 = 3;
            obj->unk6 = 0;
            obj->unk8C = 0x78;
        }
    }
    move_object(obj);
    animate_object(obj);
}
