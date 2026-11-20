/* Shared body (DK-5), from the banked draft of func_800EF6A4_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    set_animation(obj, 3);
    animate_object(obj);
    obj[6] = 1;
}
