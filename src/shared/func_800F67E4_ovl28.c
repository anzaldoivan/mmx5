/* Shared body (DK-5), from the banked draft of func_800F67E4_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    animate_object();
    set_animation(obj, 1);
    obj[6]++;
}
