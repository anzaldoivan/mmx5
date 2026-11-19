/* Shared body (DK-5), from the banked draft of func_800FAD30_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    apply_object_motion(obj);
    func_8002FB58(obj);
    animate_object(obj);
    if (obj[0x70] & 4) {
        set_animation(obj, 5);
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0x1000;
        obj[6]++;
    }
}
