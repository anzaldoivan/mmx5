/* Shared body (DK-5), from the banked draft of func_800EFA9C_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    set_animation(obj, 4);
    animate_object(obj);
    *(s32*)(obj + 0x80) = 0;
    *(s32*)(obj + 0x84) = 0;
    *(s32*)(obj + 0x88) = 1;
    *(s32*)(obj + 0x8C) = 0;
    obj[6] = 1;
}
