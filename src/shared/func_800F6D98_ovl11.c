/* Shared body (DK-5), from the banked draft of func_800F6D98_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    move_object(obj);
    animate_object(obj);
    if (obj[0x70] & 8) {
        set_animation(obj, 13);
        obj[6]++;
    }
}
