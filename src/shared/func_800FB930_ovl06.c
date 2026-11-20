/* Shared body (DK-5), from the banked draft of func_800FB930_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"

extern u8 D_800FF684_ovl06[];
extern u8 D_800FF688_ovl06[];

void DEDUP_NAME(ObjFB930* obj) {
    apply_object_motion(obj);
    if (is_off_screen(obj, 0x50, 0x50) == 0) {
        if (obj->kind == 11) {
            obj->p50 = D_800FF684_ovl06;
            obj->p54 = D_800FF688_ovl06;
        }
    } else {
        obj->state = 2;
    }
}
