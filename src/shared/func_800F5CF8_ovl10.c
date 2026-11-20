/* Shared body (DK-5), from the banked draft of func_800F5CF8_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(signed char*)(obj + 0x45) == 0x10) {
        play_sound(2, 0x5B, obj);
    }
    if (*(signed char*)(obj + 0x45) == 1) {
        obj[0x86] = 1;
        obj[0x3] = 0;
    }
}
