/* Shared body (DK-5), from the banked draft of func_800F5994_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    if (*(s16*)(obj + 0x7E) != 0 && *(signed char*)(obj + 2) == 1) {
        *(s16*)(obj + 0x7E) -= 1;
        DEDUP_CALLEE(obj);
        return;
    }
    *(s16*)(obj + 0x7C) = 1;
    obj[6] = 1;
}
