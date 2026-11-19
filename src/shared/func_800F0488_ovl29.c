/* Shared body (DK-5), from the banked draft of func_800F0488_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        obj[6] = 2;
        *(s16*)(obj + 0x7C) = 2;
        *(s16*)(obj + 0x7E) = 0xC;
    }
}
