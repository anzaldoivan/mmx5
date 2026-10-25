/* Shared body (DK-5), from the banked draft of func_800F2B5C_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 arg);

void DEDUP_NAME(u8* obj) {
    if (*(s8*)(obj + 0x45) == 2) {
        DEDUP_CALLEE(obj, 1);
        obj[6]++;
    }
}
