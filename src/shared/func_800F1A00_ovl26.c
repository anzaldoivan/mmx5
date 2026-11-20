/* Shared body (DK-5), from the banked draft of func_800F1A00_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    *(u16*)(obj + 0x42) &= 0x7FFF;
    DEDUP_CALLEE(obj);
    if (*(signed char*)(obj + 0x45) != 0) {
        obj[4] = 2;
    }
}
