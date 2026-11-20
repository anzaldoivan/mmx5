/* Shared body (DK-5), from the banked draft of func_800F6A00_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    *(s32*)(obj + 0x20) = 0xFFFF0000;
    obj[6] = 1;
}
