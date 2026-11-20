/* Shared body (DK-5), from the banked draft of func_800F85BC_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (is_off_screen(obj, 0x40, 0x40) == 1) {
        obj[4] = 2;
    }
}
