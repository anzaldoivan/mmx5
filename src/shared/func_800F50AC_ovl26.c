/* Shared body (DK-5), from the banked draft of func_800F50AC_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[7] = 0;
        obj[6]++;
    }
}
