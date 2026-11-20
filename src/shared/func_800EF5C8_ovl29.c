/* Shared body (DK-5), from the banked draft of func_800EF5C8_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* o) {
    set_animation(o, 2);
    animate_object(o);
    *(s32*)(o + 0x20) = 0;
    o[6] = 1;
}
