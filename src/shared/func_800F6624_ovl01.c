/* Shared body (DK-5), from the banked draft of func_800F6624_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (--*(s16*)(obj + 0x7C) == -1) {
        obj[6]++;
    }
}
