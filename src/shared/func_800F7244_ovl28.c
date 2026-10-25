/* Shared body (DK-5), from the banked draft of func_800F7244_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (*(signed char*)(obj + 0x45) == 1) {
        obj[4]++;
    }
}
