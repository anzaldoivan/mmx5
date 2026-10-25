/* Shared body (DK-5), from the banked draft of func_800F61C8_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (--*(s16*)(obj + 0x7E) == 0) {
        obj[6] = 2;
    }
}
