/* Shared body (DK-5), from the banked draft of func_800F0324_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        *(s16*)(obj + 0x7C) = 10;
        obj[6] = 1;
    }
}
