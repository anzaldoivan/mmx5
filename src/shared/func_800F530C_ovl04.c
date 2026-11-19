/* Shared body (DK-5), from the banked draft of func_800F530C_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    move_object(obj);
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[6]++;
    }
}
