/* Shared body (DK-5), from the banked draft of func_800F1660_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (*(s16*)(obj + 0x7C) != 0) {
        *(s16*)(obj + 0x7C) -= 1;
    } else {
        ((s32(*)())apply_object_motion)(obj);
        if (*(s32*)(obj + 0x24) > 0x1FFFF) {
            *(s32*)(obj + 0x2C) = 0x1000;
        }
        if (*(s32*)(obj + 0x24) == 0) {
            obj[6] = 0;
        }
    }
}
