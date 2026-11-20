/* Shared body (DK-5), from the banked draft of func_800F06A8_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    move_object(obj);
    if (obj[0x70] & 2) {
        obj[0x15] = 0x40;
        *(s32*)(obj + 0x20) = 0x20000;
        obj[0x6] = 2;
    }
}
