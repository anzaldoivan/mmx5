/* Shared body (DK-5), from the banked draft of func_800F0280_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    animate_object();
    *(s32*)(obj + 0x24) = 0x60000;
    move_object(obj);
}
