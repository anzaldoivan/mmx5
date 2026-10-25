/* Shared body (DK-5), from the banked draft of func_800F085C_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (*(signed char*)(obj + 0x45) == 2) {
        obj[0x8B] = 1;
    }
    if (*(signed char*)(obj + 0x45) == 1) {
        *(s16*)(obj + 0x7C) = 4;
        *(s16*)(obj + 0x7E) = 0x1E;
        obj[0x6] = 1;
    }
}
