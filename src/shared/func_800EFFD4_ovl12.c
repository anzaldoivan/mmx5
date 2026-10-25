/* Shared body (DK-5), from the banked draft of func_800EFFD4_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    if (*(s8*)(obj + 7) != 0) {
        DEDUP_CALLEE(obj, 3);
        obj[6]++;
    }
}
