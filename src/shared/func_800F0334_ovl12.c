/* Shared body (DK-5), from the banked draft of func_800F0334_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* o) {
    if (*(s8*)(o + 0x45) == 2) {
        *(s16*)(o + 0x7C) = 0;
        *(s16*)(o + 0x7E) = 0;
        o[6]++;
    }
    animate_object(o);
    apply_object_motion(o);
}
