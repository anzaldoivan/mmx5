/* Shared body (DK-5), from the banked draft of func_800F5C90_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (*(signed char*)(obj + 0x45) == 0x10) {
        play_sound(2, 0x5B, obj);
    }
    if (*(signed char*)(obj + 0x45) == 1) {
        obj[0x6] = 2;
    }
}
