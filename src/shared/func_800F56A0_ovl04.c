/* Shared body (DK-5), from the banked draft of func_800F56A0_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (*(s16*)(obj + 0x7C) != 0) {
        *(s16*)(obj + 0x7C) -= 1;
    } else {
        *(s32*)(obj + 0x98) = 0;
        obj[5] = 5;
        obj[6] = 0;
    }
}
