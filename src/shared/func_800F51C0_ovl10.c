/* Shared body (DK-5), from the banked draft of func_800F51C0_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (obj[0x70] & 8) {
        obj[0x61] = 0;
        obj[0x6] = 3;
    }
}
