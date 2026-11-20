/* Shared body (DK-5), from the banked draft of func_800F4F54_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"

void DEDUP_NAME(u8* obj) {
    apply_object_motion(obj);
    if (is_off_screen(obj, 0x40, 0x40) == 0) {
        if (obj[7] ^= 1) {
            func_8002D9EC(obj, 0x20, 0x20);
        } else {
            obj[3] = 0;
        }
    } else {
        clear_object_slot(obj);
    }
}
