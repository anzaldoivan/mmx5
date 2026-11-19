/* Shared body (DK-5), from the banked draft of func_800FA8D8_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        play_sound(2, 0x20, obj);
        obj[6]++;
    }
}
