/* Shared body (DK-5), from the banked draft of func_800FA3F0_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[5] = 3;
        obj[6] = 0;
    }
}
