/* Shared body (DK-5), from the banked draft of func_800F5DE0_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    if (obj[0x8A] == 2 && *(signed char*)(obj + 0x87) != 0) {
        obj[0x87]--;
        return;
    }
    DEDUP_CALLEE(obj);
    if (*(signed char*)(obj + 0x45) == 1 && *(signed char*)(obj + 0x87) == 0) {
        obj[0x6] = 3;
    }
}
